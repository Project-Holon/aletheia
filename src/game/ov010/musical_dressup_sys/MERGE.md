# musical_dressup_sys.c (ov010)

Translation unit 02155478..0215766C, 71 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`musical_dressup_sys.c` is blocked by:

- ov010_func_02155478.c..ov010_func_02157650.c: prototype of func_020120F4 differs between members (src/matched/ov/ov010_func_021559E4.c); prototype of func_020120F0 differs between members (src/matched/ov/ov010_func_02155C0C.c); prototype of func_
- ov010_func_02155478.c..ov010_func_02156A3C.c: prototype of func_020120F4 differs between members (src/matched/ov/ov010_func_021559E4.c); prototype of func_020120F0 differs between members (src/matched/ov/ov010_func_02155C0C.c); prototype of func_
- ov010_func_02155478.c..ov010_func_02156420.c: prototype of func_020120F4 differs between members (src/matched/ov/ov010_func_021559E4.c); prototype of func_020120F0 differs between members (src/matched/ov/ov010_func_02155C0C.c); prototype of func_
- ov010_func_02155478.c..ov010_func_02155A98.c: prototype of func_020120F4 differs between members (src/matched/ov/ov010_func_021559E4.c)
- ov010_func_02155478.c..ov010_func_02155A6C.c: prototype of func_020120F4 differs between members (src/matched/ov/ov010_func_021559E4.c)
- ov010_func_02155C0C.c..ov010_func_02156420.c: prototype of func_021FD904 differs between members (src/matched/ov/func_02155F24.c); type typedef Party differs between members (src/matched/ov/ov010_func_0215611C.c); type typedef Party differs betwe
- ov010_func_02155C0C.c..func_02155F9C.c: prototype of func_021FD904 differs between members (src/matched/ov/func_02155F24.c)
- ov010_func_02155C0C.c..func_02155F24.c: prototype of func_021FD904 differs between members (src/matched/ov/func_02155F24.c)
- ov010_func_02155FB4.c..ov010_func_02156420.c: type typedef Party differs between members (src/matched/ov/ov010_func_0215611C.c); type typedef Party differs between members (src/matched/ov/ov010_func_02156420.c)
- ov010_func_02156074.c..ov010_func_02156420.c: type typedef Party differs between members (src/matched/ov/ov010_func_0215611C.c); type typedef Party differs between members (src/matched/ov/ov010_func_02156420.c)
- ov010_func_0215611C.c..ov010_func_02156420.c: type typedef Party differs between members (src/matched/ov/ov010_func_02156420.c)
- ov010_func_02156530.c..ov010_func_02156A3C.c: prototype of func_021854B0 differs between members (src/matched/ov/ov010_func_02156824.c); type typedef Party differs between members (src/matched/ov/ov010_func_02156934.c); type typedef Party differs
- ov010_func_02156908.c..ov010_func_02156A3C.c: type typedef Party differs between members (src/matched/ov/ov010_func_02156954.c); type typedef Party differs between members (src/matched/ov/ov010_func_02156978.c); type typedef Party differs between
- ov010_func_02156978.c..ov010_func_02156A3C.c: prototype of func_021568E8 differs between members (src/matched/ov/ov010_func_02156A3C.c); prototype of func_021568A8 differs between members (src/matched/ov/ov010_func_02156A3C.c)
- ov010_func_021569A4.c..ov010_func_02156A3C.c: prototype of func_021568E8 differs between members (src/matched/ov/ov010_func_02156A3C.c); prototype of func_021568A8 differs between members (src/matched/ov/ov010_func_02156A3C.c)
- ov010_func_021569EC.c..ov010_func_02156A3C.c: prototype of func_021568E8 differs between members (src/matched/ov/ov010_func_02156A3C.c); prototype of func_021568A8 differs between members (src/matched/ov/ov010_func_02156A3C.c)
- ov010_func_02156AD4.c..ov010_func_02157650.c: global ov112_id declared two ways (src/matched/ov/ov010_func_02156EDC.c)
- ov010_func_02156AD4.c..ov010_func_0215700C.c: global ov112_id declared two ways (src/matched/ov/ov010_func_02156EDC.c)
- ov010_func_02156CE0.c..ov010_func_0215700C.c: global ov112_id declared two ways (src/matched/ov/ov010_func_02156EDC.c)
- ov010_func_02156CE0.c..ov010_func_02156F68.c: global ov112_id declared two ways (src/matched/ov/ov010_func_02156EDC.c)
- ov010_func_02156F98.c..ov010_func_0215700C.c: type typedef Stage differs between members (src/matched/ov/ov010_func_02156FD0.c); type typedef Stage differs between members (src/matched/ov/ov010_func_0215700C.c)
- ov010_func_02156FD0.c..ov010_func_0215700C.c: type typedef Stage differs between members (src/matched/ov/ov010_func_0215700C.c)

Members, in address order:

- `ov010_func_02155C0C.c`
- `func_02155F24.c`
- `ov010_func_02156074.c`
- `ov010_func_0215611C.c`
- `ov010_func_02156420.c`
- `ov010_func_021569A4.c`
- `ov010_func_021569EC.c`
- `ov010_func_02156A3C.c`
- `ov010_func_02156FD0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names musical_dressup_sys.c` again.
