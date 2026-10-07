# mystery_net.c (ov121)

Translation unit 021DD980..021DEFAC, 50 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`mystery_net.c` is blocked by:

- ov121_func_021DD980.c..ov121_func_021DEF6C.c: settings differ: src/matched/ov/ov121_func_021DDC30.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov121_func_021DD980.c..ov121_func_021DE570.c: settings differ: src/matched/ov/ov121_func_021DDC30.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov121_func_021DD980.c..ov121_func_021DE0AC.c: settings differ: src/matched/ov/ov121_func_021DDC30.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov121_func_021DD980.c..ov121_func_021DDCF8.c: settings differ: src/matched/ov/ov121_func_021DDC30.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov121_func_021DD980.c..ov121_func_021DDC30.c: settings differ: src/matched/ov/ov121_func_021DDC30.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov121_func_021DD9CC.c..ov121_func_021DDC30.c: settings differ: src/matched/ov/ov121_func_021DDC30.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov121_func_021DDC44.c..ov121_func_021DDCF8.c: settings differ: src/matched/ov/ov121_func_021DDC58.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov121_func_021DE0DC.c..ov121_func_021DE570.c: prototype of func_02082BCC differs between members (src/matched/ov/ov121_func_021DE2A0.c); prototype of func_021DE8D0 differs between members (src/matched/ov/ov121_func_021DE3E0.c)
- ov121_func_021DE308.c..ov121_func_021DE570.c: prototype of func_021DE8D0 differs between members (src/matched/ov/ov121_func_021DE3E0.c)
- ov121_func_021DE308.c..ov121_func_021DE4DC.c: prototype of func_021DE8D0 differs between members (src/matched/ov/ov121_func_021DE3E0.c)

Members, in address order:

- `ov121_func_021DD980.c`
- `ov121_func_021DD9CC.c`
- `ov121_func_021DDC30.c`
- `ov121_func_021DDC44.c`
- `ov121_func_021DE308.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names mystery_net.c` again.
