# unit_0217B828.c (ov009)

Translation unit 0217B828..0217C070, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217B828.c` is blocked by:

- ov009_func_0217B828.c..ov009_func_0217C060.c: type typedef DWCProfWorkarea differs between members (src/matched/ov_sdk/ov009_func_0217BC90.c); type typedef DWCProfWorkarea differs between members (src/matched/ov_sdk/ov009_func_0217BDA8.c)
- ov009_func_0217B828.c..ov009_func_0217BC90.c: type typedef DWCProfWorkarea differs between members (src/matched/ov_sdk/ov009_func_0217BC90.c)
- ov009_func_0217BDA8.c..ov009_func_0217C060.c: c99=CCERR: line 157: object 'CameraStandbyCallback()' redefined nolang=CCERR: line 157: object 'CameraStandbyCallback()' redefined
- ov009_func_0217C050.c..ov009_func_0217C060.c: c99=CCERR: line 31: object 'CameraStandbyCallback()' redefined nolang=CCERR: line 31: object 'CameraStandbyCallback()' redefined

Members, in address order:

- `ov009_func_0217B828.c`
- `ov009_func_0217BDA8.c`
- `ov009_func_0217C050.c`
- `ov009_func_0217C060.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217B828.c` again.
