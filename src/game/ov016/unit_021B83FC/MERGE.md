# unit_021B83FC.c (ov016)

Translation unit 021B83FC..021B89C0, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B83FC.c` is blocked by:

- ov016_func_021B83FC.c..ov016_func_021B87F0.c: settings differ: src/matched/ov_sdk/func_021B84AC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B83FC.c..ov016_func_021B84D0.c: settings differ: src/matched/ov_sdk/func_021B84AC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- func_021B84AC.c..ov016_func_021B84D0.c: c99=CCERR: line 47: object 'alarmCallback()' redefined nolang=CCERR: line 47: object 'alarmCallback()' redefined
- ov016_func_021B84BC.c..ov016_func_021B84D0.c: c99=CCERR: line 37: object 'alarmCallback()' redefined nolang=CCERR: line 37: object 'alarmCallback()' redefined
- ov016_func_021B84E4.c..ov016_func_021B87F0.c: global aoss_mq declared two ways (src/matched/ov_sdk/ov016_func_021B85A8.c); prototype of OS_ReceiveMessage differs between members (src/matched/ov_sdk/ov016_func_021B85A8.c); global aoss_mq declared 
- ov016_func_021B8640.c..ov016_func_021B87F0.c: global aoss_mq declared two ways (src/matched/ov_sdk/ov016_func_021B8678.c); prototype of OS_ReceiveMessage differs between members (src/matched/ov_sdk/ov016_func_021B8678.c); prototype of OS_CreateAl
- ov016_func_021B8678.c..ov016_func_021B87F0.c: prototype of OS_CreateAlarm differs between members (src/matched/ov_sdk/ov016_func_021B87F0.c); prototype of OS_SetAlarm differs between members (src/matched/ov_sdk/ov016_func_021B87F0.c); prototype o

Members, in address order:

- `func_021B84AC.c`
- `ov016_func_021B84BC.c`
- `ov016_func_021B84D0.c`
- `ov016_func_021B8640.c`
- `ov016_func_021B8678.c`
- `ov016_func_021B87F0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B83FC.c` again.
