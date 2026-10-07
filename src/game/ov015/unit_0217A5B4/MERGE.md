# unit_0217A5B4.c (ov015)

Translation unit 0217A5B4..0217A8EC, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217A5B4.c` is blocked by:

- ov015_func_0217A5B4.c..ov015_func_0217A7AC.c: c99=CCERR: line 143: illegal implicit conversion from 'struct irc_param *' to | line 143: 'struct  *' | line 145: illegal implicit conversion from 'struct irc_param *' to nolang=CCERR: line 143: illeg
- ov015_func_0217A674.c..ov015_func_0217A7AC.c: c99=CCERR: line 110: illegal implicit conversion from 'struct irc_param *' to | line 110: 'struct  *' | line 112: illegal implicit conversion from 'struct irc_param *' to nolang=CCERR: line 110: illeg
- ov015_func_0217A718.c..ov015_func_0217A7AC.c: c99=CCERR: line 96: illegal implicit conversion from 'struct irc_param *' to | line 96: 'struct  *' | line 109: illegal implicit conversion from 'struct irc_param *' to nolang=CCERR: line 96: illegal 

Members, in address order:

- `ov015_func_0217A674.c`
- `ov015_func_0217A718.c`
- `ov015_func_0217A7AC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217A5B4.c` again.
