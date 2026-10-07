# unit_02164D64.c (ov009)

Translation unit 02164D64..02165B80, 25 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02164D64.c` is blocked by:

- ov009_func_02164D64.c..ov009_func_02165B68.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02164F98.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165088.c); global g_021AA7D4 declared two ways (src
- ov009_func_02164D64.c..ov009_func_02165560.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02164F98.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165088.c); global g_021AA7D4 declared two ways (src
- ov009_func_02164D64.c..ov009_func_02165088.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02164F98.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165088.c)
- ov009_func_02165144.c..ov009_func_02165560.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165560.c)
- ov009_func_021652A4.c..ov009_func_02165560.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165560.c)
- ov009_func_02165478.c..ov009_func_02165560.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165560.c)
- ov009_func_021656A0.c..ov009_func_02165B68.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021656D0.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021657D8.c); global g_021AA7D4 declared two ways (src
- ov009_func_021656A0.c..ov009_func_021658F8.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021656D0.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021657D8.c)
- ov009_func_021656A0.c..ov009_func_0216576C.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021656D0.c)
- ov009_func_021657C8.c..ov009_func_021658F8.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021657D8.c)
- ov009_func_021657D8.c..ov009_func_021658F8.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021658F8.c)
- ov009_func_02165918.c..ov009_func_02165B68.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021659B4.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021659F8.c); prototype of OS_SetAlarm differs between
- ov009_func_02165918.c..ov009_func_021659F8.c: global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021659B4.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_021659F8.c)
- ov009_func_02165A4C.c..ov009_func_02165B68.c: prototype of OS_SetAlarm differs between members (src/matched/ov_sdk/ov009_func_02165AF4.c); global g_021AA7D4 declared two ways (src/matched/ov_sdk/ov009_func_02165AF4.c)
- ov009_func_02165AF4.c..ov009_func_02165B68.c: c99=DIFF nolang=DIFF
- no verified entry for 02165B5C

Members, in address order:

- `ov009_func_021652A4.c`
- `ov009_func_02165478.c`
- `ov009_func_02165560.c`
- `ov009_func_021656A0.c`
- `ov009_func_021657C8.c`
- `ov009_func_021657D8.c`
- `ov009_func_021658F8.c`
- `ov009_func_02165918.c`
- `ov009_func_02165A4C.c`
- `ov009_func_02165AF4.c`
- `ov009_func_02165B68.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02164D64.c` again.
