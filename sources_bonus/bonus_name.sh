#! /bin/bash

find . -name "*.c" | awk -v mvCmd='mv "%s" "%s"\n' \
    '{ old=$0;
       sub(/[.]c$/,"_bonus.c");
       printf mvCmd,old,$0;
     }' | sh
