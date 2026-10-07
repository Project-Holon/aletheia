# unit_021BE9B8.c (ov203)

Translation unit 021BE9B8..021BEE1C, 15 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BE9B8.c` is blocked by:

- ov203_func_021BE9B8.c..ov203_func_021BEDCC.c: c99=CCERR: line 137: illegal implicit conversion from 'struct Config_021BE9B8 *' to | line 137: 'const struct Config_021BE9F8 *' | line 193: identifier 'GX_SetCapture(@enum$1_try_unit_021BE9B8_c, @enu
- ov203_func_021BE9B8.c..ov203_func_021BEB48.c: c99=CCERR: line 84: illegal implicit conversion from 'struct Config_021BE9B8 *' to | line 84: 'const struct Config_021BE9F8 *' | line 140: identifier 'GX_SetCapture(@enum$1_try_unit_021BE9B8_c, @enum$
- ov203_func_021BE9B8.c..ov203_func_021BE9F8.c: c99=CCERR: line 55: illegal implicit conversion from 'struct Config_021BE9B8 *' to | line 55: 'const struct Config_021BE9F8 *' nolang=CCERR: line 55: illegal implicit conversion from 'struct Config_02
- ov203_func_021BEA48.c..ov203_func_021BEB48.c: c99=CCERR: line 89: identifier 'GX_SetCapture(@enum$1_try_unit_021BE9B8_c, @enum$2_try_unit_021BE9B8_c, @enum$3_try_unit_021BE9B8_c, @enum$4_try_unit_021BE9B8_c, @enum$5_try_unit_021BE9B8_c, int, int)

Members, in address order:

- `ov203_func_021BE9B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BE9B8.c` again.
