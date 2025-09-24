#!/bin/bash

# ------------------------------------
# Setup colors
# ------------------------------------
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

FAILED_LOG="failed_cases.log"
> "$FAILED_LOG" # clear file

echo -e "${YELLOW}🚀 Starting push_swap tests...${RESET}"

# ------------------------------------
# Fixed Test Cases
# ------------------------------------
FIXED_TESTS=(
    "2 1"
    "3 2 1"
    "1 5 3 2 4"
    "42 5 99 1 7"
)

echo -e "\n${YELLOW}🧪 Running Fixed Test Cases:${RESET}"

for i in "${!FIXED_TESTS[@]}"; do
    ARG="${FIXED_TESTS[$i]}"
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    COUNT=$(./push_swap $ARG | wc -l)

    if [ "$RESULT" = "OK" ]; then
        echo -e "${GREEN}✅ Fixed Test $((i + 1)) passed"
        echo -e "   Input: $ARG"
        echo -e "   Instruction count: $COUNT${RESET}"
    else
        echo -e "${RED}❌ Fixed Test $((i + 1)) failed"
        echo -e "   Input: $ARG"
        echo -e "   Checker output: $RESULT${RESET}"
        echo "$ARG" >> "$FAILED_LOG"
    fi
    echo "---------------------------"
done

# ------------------------------------
# Random Test Function
# ------------------------------------
run_random_test() {
    COUNT=$1
    MIN=$2
    MAX=$3
    LABEL=$4

    ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range($MIN, $MAX+1), $COUNT))))" 2>/dev/null)

    if [ -z "$ARG" ]; then
        echo -e "${RED}❌ Failed to generate random input for $LABEL${RESET}"
        echo "RANGE: $MIN to $MAX, COUNT: $COUNT" >> "$FAILED_LOG"
        echo "---------------------------"
        return
    fi

    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    COUNT_MOVES=$(./push_swap $ARG | wc -l)

    if [ "$RESULT" = "OK" ]; then
        echo -e "${GREEN}✅ Random Test: $LABEL"
        echo -e "   Range: [$MIN..$MAX], Count: $COUNT"
        echo -e "   Instruction count: $COUNT_MOVES${RESET}"
    else
        echo -e "${RED}❌ Random Test: $LABEL"
        echo -e "   Checker output: $RESULT${RESET}"
        echo "$ARG" >> "$FAILED_LOG"
    fi
    echo "---------------------------"
}

# ------------------------------------
# Run Random Tests
# ------------------------------------
echo -e "\n${YELLOW}🎲 Running Random Test Cases:${RESET}"

run_random_test 10 1 10 "Small (10 values from 1–10)"
run_random_test 50 1 100 "Medium (50 values from 1–100)"
run_random_test 100 -1000 1000 "Large (100 values from -1000 to 1000)"

# ------------------------------------
# Final Summary
# ------------------------------------
if [ -s "$FAILED_LOG" ]; then
    echo -e "\n${RED}❌ Some tests failed. See ${FAILED_LOG} for details.${RESET}"
else
    echo -e "\n${GREEN}✅ All tests passed successfully!${RESET}"
fi
