#!/bin/bash
NBR_COUNT=5
##
NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
#NBR="27 1 59 100 68 9 65 22 64 87 19 66 61 51 48 6 89 71 45 69 12 57 56 88 24 84 16 81 92 99 43 25 35 4 94 70 58 40 39 17 32 74 98 67 72 82 26 60 79 20 14 34 2 7 37 30 52 29 38 11 41 85 36 95 63 78 15 49 73 28 18 91 44 62 76 42 31 50 21 55 8 13 97 93 5 3 47 53 46 77 86 80 96 33 83 10 23 54 75 90"
#NBR=$(seq 1 $NBR_COUNT | tr '\n' ' ' | rev | cut -c 2- | rev)
CMD=$( ./push_swap $NBR)
NBR_LINK=$( echo "$NBR" | tr ' ' ',' )
CMD_LINK=$( echo "$CMD" | sed -e"s/rra/g/g" -e"s/rrb/h/g" \
-e"s/rrr/i/g" -e"s/sa/a/g" -e"s/sb/b/g" -e"s/ss/c/g" \
-e"s/ra/d/g" -e"s/rb/e/g" -e"s/rr/f/g"  -e"s/pa/j/g" -e"s/pb/k/g" | tr -d '\n')
CMD_COUNT=${#CMD_LINK}
RESULT=$( echo $CMD | ./checker_Linux $NBR )
echo "Operations: $CMD_COUNT"
echo "Result $RESULT"
echo "https://bluegales.github.io/push-swap-pain/?&nbr=$NBR_LINK&cmd=$CMD_LINK"
