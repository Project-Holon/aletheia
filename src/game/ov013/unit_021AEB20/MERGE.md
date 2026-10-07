# unit_021AEB20.c (ov013)

Translation unit 021AEB20..021B0D08, 36 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021AEB20.c` is blocked by:

- ov013_func_021AEB20.c..ov013_func_021B0CD8.c: settings differ: src/matched/ov/ov013_func_021AF340.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov013_func_021AEB20.c..ov013_func_021AF2AC.c: global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AED30.c); global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AEF6C.c); global d_021B3C80 declared two ways (src/matched
- ov013_func_021AEB20.c..ov013_func_021AEE14.c: global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AED30.c)
- ov013_func_021AECC4.c..ov013_func_021AEE14.c: global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AED30.c)
- ov013_func_021AED30.c..ov013_func_021AEE14.c: global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AEDEC.c); global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AEE14.c)
- ov013_func_021AEF44.c..ov013_func_021AF2AC.c: global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AEF6C.c); global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AF13C.c); global d_021B3C80 declared two ways (src/matched
- ov013_func_021AEF44.c..ov013_func_021AF13C.c: global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AEF6C.c); global d_021B3C80 declared two ways (src/matched/ov/ov013_func_021AF13C.c)
- ov013_func_021AEF44.c..ov013_func_021AEF6C.c: c99=CCERR: line 65: struct/union/enum/class tag 'Work' redefined | line 120: illegal implicit conversion from 'struct  *' to | line 120: 'struct Work *' nolang=CCERR: line 65: struct/union/enum/class 
- ov013_func_021AF124.c..ov013_func_021AF13C.c: c99=CCERR: line 26: struct/union/enum/class tag 'Work' redefined | line 50: illegal implicit conversion from 'struct Node *' to | line 50: 'int' nolang=CCERR: line 26: struct/union/enum/class tag 'Wor
- ov013_func_021AF30C.c..ov013_func_021B0CD8.c: settings differ: src/matched/ov/ov013_func_021AF340.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov013_func_021AF30C.c..ov013_func_021B04A8.c: settings differ: src/matched/ov/ov013_func_021AF340.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov013_func_021AF30C.c..ov013_func_021AF628.c: settings differ: src/matched/ov/ov013_func_021AF340.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov013_func_021AF30C.c..ov013_func_021AF340.c: settings differ: src/matched/ov/ov013_func_021AF340.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov013_func_021B0508.c..ov013_func_021B0CD8.c: global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0600.c); global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0614.c); global d_021B3CB0 declared two ways (src/matched
- ov013_func_021B0508.c..ov013_func_021B074C.c: global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0600.c); global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0614.c); global d_021B3CB0 declared two ways (src/matched
- ov013_func_021B0614.c..ov013_func_021B074C.c: global d_021B3CB0 declared two ways (src/matched/ov/ov013_func_021B074C.c); global d_021B3CBC declared two ways (src/matched/ov/ov013_func_021B074C.c); global d_021B3C84 declared two ways (src/matched
- ov013_func_021B07F8.c..ov013_func_021B0CD8.c: global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0B48.c); global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0CD8.c)

Members, in address order:

- `ov013_func_021AED30.c`
- `ov013_func_021AEF44.c`
- `ov013_func_021AEF6C.c`
- `ov013_func_021AF124.c`
- `ov013_func_021AF13C.c`
- `ov013_func_021AF30C.c`
- `ov013_func_021AF340.c`
- `ov013_func_021B0614.c`
- `ov013_func_021B074C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021AEB20.c` again.
