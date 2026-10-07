# unit_021D9ADC.c (ov093)

Translation unit 021D9ADC..021DA2F0, 20 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D9ADC.c` is blocked by:

- ov093_func_021D9ADC.c..ov093_func_021DA150.c: prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021D9CBC.c); prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021D9CEC.c); prototype of func_
- ov093_func_021D9ADC.c..ov093_func_021D9D1C.c: prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021D9CBC.c); prototype of func_021D9E08 differs between members (src/matched/ov/ov093_func_021D9CBC.c); prototype of func_
- ov093_func_021D9ADC.c..ov093_func_021D9BC8.c: c99=DIFF nolang=DIFF
- func_021D9BA4.c..ov093_func_021D9BC8.c: c99=DIFF nolang=DIFF
- func_021D9BF8.c..ov093_func_021D9D1C.c: prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021D9CBC.c); prototype of func_021D9E08 differs between members (src/matched/ov/ov093_func_021D9CBC.c); prototype of func_
- func_021D9BF8.c..ov093_func_021D9C8C.c: c99=DIFF nolang=DIFF
- ov093_func_021D9CBC.c..ov093_func_021D9D1C.c: prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021D9CEC.c); prototype of func_021D9E08 differs between members (src/matched/ov/ov093_func_021D9CEC.c); prototype of func_
- ov093_func_021D9CEC.c..ov093_func_021D9D1C.c: prototype of func_021D9E08 differs between members (src/matched/ov/ov093_func_021D9D1C.c)
- ov093_func_021D9DB0.c..ov093_func_021DA150.c: c99=CCERR: line 137: illegal implicit conversion from 'union USlot' to | line 137: 'struct ' nolang=CCERR: line 137: illegal implicit conversion from 'union USlot' to | line 137: 'struct '
- ov093_func_021D9DB0.c..ov093_func_021D9F1C.c: c99=CCERR: line 92: illegal implicit conversion from 'union USlot' to | line 92: 'struct ' nolang=CCERR: line 92: illegal implicit conversion from 'union USlot' to | line 92: 'struct '
- ov093_func_021D9DB0.c..ov093_func_021D9E08.c: c99=CCERR: line 77: illegal implicit conversion from 'union USlot' to | line 77: 'struct ' nolang=CCERR: line 77: illegal implicit conversion from 'union USlot' to | line 77: 'struct '
- ov093_func_021D9E80.c..ov093_func_021D9F1C.c: c99=DIFF nolang=DIFF
- func_021D9FC4.c..ov093_func_021DA150.c: c99=DIFF nolang=DIFF
- func_021D9FC4.c..ov093_func_021DA04C.c: c99=DIFF nolang=DIFF
- func_021DA0FC.c..ov093_func_021DA150.c: c99=DIFF nolang=DIFF
- func_021DA120.c..ov093_func_021DA150.c: c99=DIFF nolang=DIFF
- no verified entry for 021DA2D0, 021DA2E0

Members, in address order:

- `func_021D9BA4.c`
- `ov093_func_021D9BC8.c`
- `func_021D9BF8.c`
- `ov093_func_021D9C8C.c`
- `ov093_func_021D9CBC.c`
- `ov093_func_021D9CEC.c`
- `ov093_func_021D9D1C.c`
- `ov093_func_021D9DB0.c`
- `ov093_func_021D9E08.c`
- `ov093_func_021D9E80.c`
- `ov093_func_021D9F1C.c`
- `func_021D9FC4.c`
- `ov093_func_021DA04C.c`
- `func_021DA0FC.c`
- `func_021DA120.c`
- `ov093_func_021DA150.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D9ADC.c` again.
