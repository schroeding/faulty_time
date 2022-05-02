#!/bin/sh

. "${test_dir=.}/init.sh"

value=$(cat "test.txt")
rm -f "test.txt"

if [ -z "$value" ]; then
	exit 1
fi

exit 0
