#!/usr/bin/env bash

RESET="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m"

function pheader () {
printf "\e[0;1;94m\
# ****************************************************************************** #
#                       _____ _      _              ___  __ __                   #
#                      / ____(_)    (_)            / _ \/_ /_ |                  #
#                     | (___  _ _ __ _ _   _ ___  | (_) || || |                  #
#                      \___ \| | '__| | | | / __|  \__, || || |                  #
#                      ____) | | |  | | |_| \__ \    / / | || |                  #
#                     |_____/|_|_|  |_|\__,_|___/   /_/  |_||_|                  #
#                                                              container's test  #
# ****************************************************************************** #
\e[0m"
}

compile () {
	# 1=file 2=define used {ft/std} 3=output_file 4=compile_log
	clang++ -Wall -Wextra -Werror -std=c++98 -o "$3" -I./$incl_path -DNAMESPACE=$2 -DWORD="$3" $1 &>$4
	return $?
}

getEmoji () {
	# 1=integer
	emoji='';
	case $1 in
		0) emoji="${GREEN}OK";;
		1) emoji="${RED}KO";;
	esac
	printf "${BOLD}${emoji}${RESET}"
}

compare_output () {
	# 1=diff_file
	if ! [ -s $1 ]; then
		return 0
	fi
	return 1
}

printRes () {
	# 1=file 2=compile 3=bin 4=output
	printf "%-35s: COMPILE: %s | RET: %s | OUT: %s \n" \
		"$1" "$(getEmoji $2)" "$(getEmoji $3)" "$(getEmoji $4)"
}

isEq () {
	[ $1 -eq $2 ] && echo 0 || echo 1
}

test () {
    logdir="logs" logdiff="diffdir"
    mkdir -p $logdir $logdiff
    container=$(echo $1 | cut -d "/" -f 2)
	file=$(echo $1 | cut -d "/" -f 3)
	testname=$(echo $file | cut -d "." -f 1)
	ft_bin="ft.$container.out"; ft_log="$logdir/ft.$testname.$container.log"
	std_bin="std.$container.out"; std_log="$logdir/std.$testname.$container.log"
	std_compile_log="std.$testname.$container.compile.log"
    ft_compile_log="ft."$testname.$container.compile.log    

    compile "$1" "ft"  "$ft_bin" $ft_compile_log "ft_";  ft_ret=$?
    compile "$1" "std" "$std_bin" $std_compile_log "std_"; std_ret=$?
	
	same_compilation=$(isEq $ft_ret $std_ret)
	std_compile=$std_ret

	if [ $std_compile -ne 0 ] && \
		cat $std_compile_log | grep "$container/common.hpp:1" &>/dev/null; then
		rm -f $std_compile_log
		printf "${BOLD}${PURPLE}[$container/$testname] Cannot compile${RESET}\n"
		return;
	fi
	rm -f $std_compile_log
	rm -f $ft_compile_log

    > $ft_log; > $std_log;
    if [ $ft_ret -eq 0 ]; then
		./$ft_bin $ft_log; ft_ret=$?
	fi
	if [ $std_ret -eq 0 ]; then
		./$std_bin $std_log; std_ret=$?
	fi
	same_bin=$(isEq $ft_ret $std_ret)
    diff_file="$logdiff/$testname.$container.diff"
	diff $std_log $ft_log 2>/dev/null 1>"$diff_file";
    compare_output $diff_file
    same_output=$?

    rm -f $ft_bin $std_bin
    printRes "$container/$file" $same_compilation $same_bin $same_output

    [ -s "$diff_file" ] || rm -f $diff_file $ft_log $std_log &>/dev/null
    rmdir  $deepdir $logdir &>/dev/null
}

do_test () {
	# 1=container_name
	test_dir="srcs/$1"
	test_files=`ls $test_dir | grep "cpp"`

	for file in ${test_files[@]}; do
		test "$test_dir/$file"
	done
}

pheader
# containers=(vector map stack set)
containers=(map stack)
for container in ${containers[@]}; do
		printf "%40s\n" $container
		do_test $container 2>/dev/null
done	
