# compatible_irc_sys.c (ov101)

Translation unit 021B6100..021B70DC, 67 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`compatible_irc_sys.c` is blocked by:

- ov101_func_021B6100.c..ov101_func_021B70A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B66E0.c); global d_021B753C declared two ways (src/matched/ov/ov101_func_021B6CA0.c); prototype of func_02082BCC differ
- ov101_func_021B6100.c..ov101_func_021B67E4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B66E0.c)
- ov101_func_021B652C.c..ov101_func_021B67E4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6760.c)
- ov101_func_021B66A4.c..ov101_func_021B67E4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6760.c)
- ov101_func_021B66A4.c..ov101_func_021B6760.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6760.c)
- ov101_func_021B66E0.c..ov101_func_021B6760.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6760.c)
- ov101_func_021B67F8.c..ov101_func_021B70A8.c: global d_021B753C declared two ways (src/matched/ov/ov101_func_021B6CA0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6CA0.c); global d_021B753C declared two wa
- ov101_func_021B6AD8.c..ov101_func_021B70A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6CA0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6D04.c); prototype of func_
- ov101_func_021B6AD8.c..ov101_func_021B6D04.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6CA0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6D04.c)
- ov101_func_021B6C08.c..ov101_func_021B6D04.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6CA0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6D04.c)
- ov101_func_021B6D5C.c..ov101_func_021B70A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6DAC.c); prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6E8C.c); global d_021B753C 
- ov101_func_021B6D5C.c..ov101_func_021B6EBC.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6DAC.c); prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6E8C.c); global d_021B753C 
- ov101_func_021B6D5C.c..ov101_func_021B6DAC.c: prototype of func_02082BCC differs between members (src/matched/ov/ov101_func_021B6DAC.c)

Members, in address order:

- `ov101_func_021B66E0.c`
- `ov101_func_021B6760.c`
- `ov101_func_021B6D5C.c`
- `ov101_func_021B6DAC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names compatible_irc_sys.c` again.
