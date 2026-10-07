# unit_021DE14C.c (ov175)

Translation unit 021DE14C..021DEE3C, 25 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DE14C.c` is blocked by:

- ov175_func_021DE14C.c..ov175_func_021DEE18.c: settings differ: src/matched/ov_sdk/ov175_func_021DE8AC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', '
- ov175_func_021DE14C.c..ov175_func_021DEB1C.c: settings differ: src/matched/ov_sdk/ov175_func_021DE8AC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', '
- ov175_func_021DE14C.c..ov175_func_021DE840.c: c99=CCERR: line 89: struct/union/enum/class tag 'SAKEField' redefined | line 355: illegal operands 'union ' != 'int' | line 356: illegal implicit conversion from 'union ' to nolang=CCERR: line 89: str
- ov175_func_021DE26C.c..ov175_func_021DE840.c: c99=CCERR: line 85: struct/union/enum/class tag 'SAKEField' redefined | line 307: illegal operands 'union ' != 'int' | line 308: illegal implicit conversion from 'union ' to nolang=CCERR: line 85: str
- ov175_func_021DE2E0.c..ov175_func_021DE840.c: c99=CCERR: line 79: struct/union/enum/class tag 'SAKEField' redefined | line 282: illegal operands 'union ' != 'int' | line 283: illegal implicit conversion from 'union ' to nolang=CCERR: line 79: str
- ov175_func_021DE8AC.c..ov175_func_021DEB1C.c: settings differ: src/matched/ov_sdk/ov175_func_021DE95C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is
- ov175_func_021DE8AC.c..ov175_func_021DE9BC.c: settings differ: src/matched/ov_sdk/ov175_func_021DE95C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is
- ov175_func_021DEB5C.c..ov175_func_021DEE18.c: prototype of func_02182AC0 differs between members (src/matched/ov_sdk/ov175_func_021DEC54.c); prototype of func_021DE184 differs between members (src/matched/ov_sdk/ov175_func_021DEC54.c); prototype 
- ov175_func_021DECA0.c..ov175_func_021DEE18.c: prototype of func_021DE2E0 differs between members (src/matched/ov_sdk/ov175_func_021DEDB4.c)

Members, in address order:

- `ov175_func_021DE26C.c`
- `ov175_func_021DE2E0.c`
- `ov175_func_021DE840.c`
- `ov175_func_021DE8AC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DE14C.c` again.
