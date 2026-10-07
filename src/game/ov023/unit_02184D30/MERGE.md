# unit_02184D30.c (ov023)

Translation unit 02184D30..02186A04, 74 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02184D30.c` is blocked by:

- ov023_func_02184D30.c..ov023_func_021869C0.c: global d_02186BEC declared two ways (src/matched/ov/ov023_func_021852B4.c); prototype of func_0203996C differs between members (src/matched/ov/ov023_func_021867C4.c); type typedef Grp differs between 
- ov023_func_02184D30.c..ov023_func_02185BBC.c: prototype of func_021864C4 differs between members (src/matched/ov/ov023_func_021850A0.c); global d_02186BEC declared two ways (src/matched/ov/ov023_func_021852B4.c)
- ov023_func_02184D30.c..ov023_func_021855EC.c: prototype of func_021864C4 differs between members (src/matched/ov/ov023_func_021850A0.c); global d_02186BEC declared two ways (src/matched/ov/ov023_func_021852B4.c)
- ov023_func_02184D30.c..ov023_func_0218530C.c: prototype of func_021864C4 differs between members (src/matched/ov/ov023_func_021850A0.c); global d_02186BEC declared two ways (src/matched/ov/ov023_func_021852B4.c)
- ov023_func_02185080.c..ov023_func_0218530C.c: prototype of func_021864C4 differs between members (src/matched/ov/ov023_func_021850A0.c)
- ov023_func_02185080.c..ov023_func_021850A0.c: prototype of func_021864C4 differs between members (src/matched/ov/ov023_func_021850A0.c)
- ov023_func_02185628.c..ov023_func_02185BBC.c: c99=DIFF nolang=DIFF
- ov023_func_02185854.c..ov023_func_02185BBC.c: c99=DIFF nolang=DIFF
- ov023_func_02185854.c..ov023_func_02185954.c: c99=DIFF nolang=DIFF
- ov023_func_021858B8.c..ov023_func_02185954.c: c99=DIFF nolang=DIFF
- ov023_func_02185C38.c..ov023_func_021869C0.c: type typedef Grp differs between members (src/matched/ov/ov023_func_02186988.c)
- ov023_func_021864A8.c..ov023_func_021869C0.c: type typedef Grp differs between members (src/matched/ov/ov023_func_02186988.c)
- ov023_func_02186708.c..ov023_func_021869C0.c: type typedef Grp differs between members (src/matched/ov/ov023_func_02186988.c)
- ov023_func_021868C8.c..ov023_func_021869C0.c: type typedef Grp differs between members (src/matched/ov/ov023_func_02186988.c)

Members, in address order:

- `ov023_func_02185080.c`
- `ov023_func_021850A0.c`
- `ov023_func_021858B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02184D30.c` again.
