# draw_system.c (ov172)

Translation unit 021B6A00..021B77E8, 30 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`draw_system.c` is blocked by:

- ov172_func_021B6A00.c..ov172_func_021B77B8.c: c99=CCERR: line 398: illegal implicit conversion from 'const struct Stroke_021B6C4C *' to | line 398: 'const struct  *' nolang=CCERR: line 398: illegal implicit conversion from 'const struct Stroke_02
- ov172_func_021B6A00.c..ov172_func_021B6EA8.c: c99=CCERR: line 254: illegal implicit conversion from 'const struct Stroke_021B6C4C *' to | line 254: 'const struct  *' nolang=CCERR: line 254: illegal implicit conversion from 'const struct Stroke_02
- ov172_func_021B6C34.c..ov172_func_021B6EA8.c: c99=CCERR: line 92: illegal implicit conversion from 'const struct Stroke_021B6C4C *' to | line 92: 'const struct  *' nolang=CCERR: line 92: illegal implicit conversion from 'const struct Stroke_021B6
- ov172_func_021B6C34.c..ov172_func_021B6C78.c: c99=CCERR: line 72: illegal implicit conversion from 'const struct Stroke_021B6C4C *' to | line 72: 'const struct  *' nolang=CCERR: line 72: illegal implicit conversion from 'const struct Stroke_021B6
- ov172_func_021B6C4C.c..ov172_func_021B6C78.c: c99=CCERR: line 51: illegal implicit conversion from 'const struct Stroke_021B6C4C *' to | line 51: 'const struct  *' nolang=CCERR: line 51: illegal implicit conversion from 'const struct Stroke_021B6
- ov172_func_021B6CA4.c..ov172_func_021B6EA8.c: c99=DIFF nolang=DIFF
- ov172_func_021B6CA4.c..ov172_func_021B6E5C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov172_func_021B6C4C.c`
- `ov172_func_021B6C78.c`
- `ov172_func_021B6CA4.c`
- `ov172_func_021B6E5C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names draw_system.c` again.
