# chihou_zukan_award.c (ov221)

Translation unit 021B95A0..021B9E78, 15 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`chihou_zukan_award.c` is blocked by:

- ov221_func_021B95A0.c..ov221_func_021B9DD4.c: c99=CCERR: line 169: struct/union/enum/class tag 'Vec2' redefined nolang=CCERR: line 169: struct/union/enum/class tag 'Vec2' redefined
- ov221_func_021B9B18.c..ov221_func_021B9DD4.c: c99=CCERR: line 82: struct/union/enum/class tag 'Vec2' redefined nolang=CCERR: line 82: struct/union/enum/class tag 'Vec2' redefined
- ov221_func_021B9CEC.c..ov221_func_021B9DD4.c: c99=CCERR: line 41: struct/union/enum/class tag 'Vec2' redefined nolang=CCERR: line 41: struct/union/enum/class tag 'Vec2' redefined
- ov221_func_021B9CEC.c..ov221_func_021B9D38.c: c99=CCERR: line 32: struct/union/enum/class tag 'Vec2' redefined nolang=CCERR: line 32: struct/union/enum/class tag 'Vec2' redefined

Members, in address order:

- `ov221_func_021B9CEC.c`
- `ov221_func_021B9D38.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names chihou_zukan_award.c` again.
