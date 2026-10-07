# unit_0272E9E8.c (twl)

Translation unit 0272E9E8..02730090, 34 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0272E9E8.c` is blocked by:

- func_0272E9E8.c..func_0272FFC8.c: global data_02732EFC declared two ways (src/matched/twl/func_0272FD7C.c); prototype of func_02087988 differs between members (src/matched/twl/func_0272FDDC.c); prototype of func_0208799C differs betwe
- func_0272E9E8.c..func_0272FB10.c: c99=CCERR: line 44: function call 'func_0272F740(void *)' does not match | line 44: 'func_0272F740()' nolang=CCERR: line 44: function call 'func_0272F740(void *)' does not match | line 44: 'func_0272F
- func_0272E9E8.c..func_0272EE98.c: c99=DIFF nolang=DIFF
- func_0272E9E8.c..func_0272EBDC.c: c99=DIFF nolang=DIFF
- func_0272EA74.c..func_0272EBDC.c: c99=DIFF nolang=DIFF
- func_0272EFB0.c..func_0272FB10.c: c99=DIFF nolang=DIFF
- func_0272F740.c..func_0272FB10.c: c99=DIFF nolang=DIFF
- func_0272F740.c..func_0272F804.c: c99=DIFF nolang=DIFF
- func_0272F8A8.c..func_0272FB10.c: c99=DIFF nolang=DIFF
- func_0272F9C4.c..func_0272FB10.c: c99=DIFF nolang=DIFF
- func_0272FB28.c..func_0272FFC8.c: global data_02732EFC declared two ways (src/matched/twl/func_0272FD7C.c); prototype of func_02087988 differs between members (src/matched/twl/func_0272FDDC.c); prototype of func_0208799C differs betwe

Members, in address order:

- `func_0272EA74.c`
- `func_0272EBDC.c`
- `func_0272F740.c`
- `func_0272F804.c`
- `func_0272F8A8.c`
- `func_0272F9C4.c`
- `func_0272FB10.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0272E9E8.c` again.
