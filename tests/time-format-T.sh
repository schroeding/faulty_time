#!/bin/sh

# Test "%T" output format specifier

# Copyright (C) 2017-2019 Free Software Foundation, Inc.
#
# This file is part of GNU Time.
#
# GNU Time is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# GNU Time is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU time.  If not, see <http://www.gnu.org/licenses/>.

# Written by Assaf Gordon
. "${test_dir=.}/init.sh"

fail=

# The auxiliary program should be built and runnable
time-aux || framework_failure_ "time-aux is missing/not runnable"

FMT="exit type:%Tt\nexit code:%Tx\nsig-spec:%Ts\nsig-num:%Tn\nexit ok:%To"


##
## Test 1: terminate with a signal
##

cat<<'EOF'>exp1 || framework_failure_ "failed to write exp1"
exit type:signalled
exit code:
sig-spec:KILL
sig-num:9
exit ok:
EOF

# The exit code of 'time' should be the value of KILL signal
# (e.g. 137 on linux = 126 + 9, but that is not portable, so don't check it).
time -o out1 -q -f "$FMT" time-aux -S KILL -e 4
compare_ exp1 out1 || fail=1



##
## Test 2: terminate with non-zero exit code
##
cat<<'EOF'>exp2 || framework_failure_ "failed to write exp2"
exit type:normal
exit code:4
sig-spec:
sig-num:
exit ok:
EOF

returns_ 4 time -o out2 -q -f "$FMT" time-aux -e 4 || fail=1
compare_ exp2 out2 || fail=1


##
## Test 3: terminate with exit code 0
##
cat<<'EOF'>exp3 || framework_failure_ "failed to write exp3"
exit type:normal
exit code:0
sig-spec:
sig-num:
exit ok:ok
EOF

time -o out3 -q -f "$FMT" time-aux -e 0 || fail=1
compare_ exp3 out3 || fail=1

exit $fail
