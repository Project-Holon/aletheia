# unit_021DDB38.c (ov175)

Translation unit 021DDB38..021DE14C, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DDB38.c` is blocked by:

- ov175_func_021DDB38.c..ov175_func_021DE100.c: settings differ: src/matched/ov_sdk/ov175_func_021DDBE4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is
- ov175_func_021DDB38.c..ov175_func_021DDFF8.c: settings differ: src/matched/ov_sdk/ov175_func_021DDBE4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is
- ov175_func_021DDB38.c..ov175_func_021DDBE4.c: settings differ: src/matched/ov_sdk/ov175_func_021DDBE4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is
- ov175_func_021DE024.c..ov175_func_021DE100.c: prototype of func_02182AC0 differs between members (src/matched/ov_sdk/ov175_func_021DE100.c); prototype of func_02182CF0 differs between members (src/matched/ov_sdk/ov175_func_021DE100.c)

Members, in address order:

- `ov175_func_021DDB38.c`
- `ov175_func_021DDBE4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DDB38.c` again.
