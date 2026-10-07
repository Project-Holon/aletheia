# unit_021B97A8.c (ov016)

Translation unit 021B97A8..021B9EE0, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B97A8.c` is blocked by:

- ov016_func_021B97A8.c..ov016_func_021B9EA4.c: settings differ: src/matched/ov_sdk/ov016_func_021B9BF8.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p -ipa file', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags'
- ov016_func_021B97A8.c..ov016_func_021B99C8.c: c99=CCERR: line 117: identifier 'ATERMSET_BSS' redeclared | line 117: was declared as: 'struct ' | line 117: now declared as: 'struct ' nolang=CCERR: line 117: identifier 'ATERMSET_BSS' redeclared | l
- ov016_func_021B98A4.c..ov016_func_021B99C8.c: c99=CCERR: line 138: identifier 'ATERMSET_BSS' redeclared | line 138: was declared as: 'struct ' | line 138: now declared as: 'struct ' nolang=CCERR: line 138: identifier 'ATERMSET_BSS' redeclared | l
- ov016_func_021B9A2C.c..ov016_func_021B9EA4.c: settings differ: src/matched/ov_sdk/ov016_func_021B9BF8.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p -ipa file', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags'
- ov016_func_021B9A2C.c..ov016_func_021B9BF8.c: settings differ: src/matched/ov_sdk/ov016_func_021B9BF8.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p -ipa file', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags'

Members, in address order:

- `ov016_func_021B98A4.c`
- `ov016_func_021B99C8.c`
- `ov016_func_021B9A2C.c`
- `ov016_func_021B9BF8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B97A8.c` again.
