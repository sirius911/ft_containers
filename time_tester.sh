# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    time_tester.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 09:20:38 by clorin            #+#    #+#              #
#    Updated: 2021/11/30 10:38:40 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RESET="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m"

if [ -z "$1" ]
then
    seed_=42
else
    seed_=$1
fi
#compilation of given main with stl and ft containers
clang++ -Wall -Wextra -Werror -o ft.out srcs/main.cpp -D NAMESPACE=ft
clang++ -Wall -Wextra -Werror -o stl.out srcs/main.cpp

#time for stl containers
printf "${CYAN}"
echo "   _____________ "
echo "  / ___/_  __/ / "
echo "  \__ \ / / / /  "
echo " ___/ // / / /___"
echo "/____//_/ /_____/ container's"
echo "                 "

start=$(date +%s.%N)
./stl.out $seed_
time_stl=$(echo "$(date +%s.%N) - $start" | bc)

printf "Test time = $time_stl s${RESET}\n"
#echo "-> $time_stl s"

#time for ft containers
printf "${YELLOW}"
echo "    ____________"
echo "   / ____/_  __/"
echo "  / /_    / /   "
echo " / __/   / /    "
echo "/_/     /_/     container's"
echo "                "
start=$(date +%s.%N)
./ft.out $seed_
time_ft=$(echo "$(date +%s.%N) - $start" | bc)

printf "Test time = $time_ft s${RESET}\n"

x=$(echo "scale=3; $time_ft / $time_stl" | bc)
x_int=$(echo "scale=0; $time_ft / $time_stl" | bc)
printf "${BOLD}"
if [ $x_int -le "20" ]
then
    printf ${GREEN}
else
    printf ${RED}
fi
printf "\nFactor x = Time_FT / Time_std = $x${RESET}\n"

rm -rf ft.out stl.out