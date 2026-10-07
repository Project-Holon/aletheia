# unit_02731718.c (twl)

Translation unit 02731718..02732CEC, 26 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02731718.c` is blocked by:

- func_02731718.c..func_02732CAC.c: settings differ: src/matched/twl/func_02731754.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_02731718.c..func_02731BF8.c: settings differ: src/matched/twl/func_02731754.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_02731718.c..func_02731774.c: settings differ: src/matched/twl/func_02731754.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_02731718.c..func_02731760.c: settings differ: src/matched/twl/func_02731754.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_02731764.c..func_02731774.c: settings differ: src/matched/twl/func_02731774.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 't
- func_02731770.c..func_02731774.c: settings differ: src/matched/twl/func_02731774.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 't
- func_0273184C.c..func_02731BF8.c: prototype of func_02731760 differs between members (src/matched/twl/func_02731868.c)
- func_0273199C.c..func_02731BF8.c: c99=DIFF nolang=DIFF
- func_02731AF0.c..func_02731BF8.c: c99=DIFF nolang=DIFF
- func_02731CFC.c..func_02732CAC.c: c99=DIFF nolang=DIFF
- func_027323A8.c..func_02732CAC.c: c99=DIFF nolang=DIFF
- func_027323A8.c..func_02732874.c: c99=DIFF nolang=DIFF
- func_02732944.c..func_02732CAC.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_02731718.c`
- `func_02731764.c`
- `func_02731770.c`
- `func_02731774.c`
- `func_02731AF0.c`
- `func_02731BF8.c`
- `func_027323A8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02731718.c` again.

- `func_02732A70.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
