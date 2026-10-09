# button_man (arm9)

Round 5 (lane s13): 10 files, all verified by tools/match.py.

- `button_man_p01.c`: func_02051788 .. func_020522E4 (compiler 1.1p1, flags -O4,p, isa arm)
- `button_man_p02.c`: func_020524C8 .. func_02053044 (compiler ../1.2/sp2, flags -O4,p, isa arm)
- `button_man_p03.c`: func_0205312C .. func_02053E1C (compiler ../1.2/sp2, flags -O4,p, isa arm)
- `button_man_p04.c`: func_0205429C (compiler ../1.2/sp2, flags -O4,p -proc arm946e, isa arm)
- `button_man_p05.c`: func_02054718 (compiler ../1.2/sp2, flags -O4,p -proc arm946e, isa arm)
- `button_man_p06.c`: func_02054A68 .. func_02055B80 (compiler ../1.2/sp2, flags -O4,p, isa arm)
- `button_man_p07.c`: func_02055FD4 (compiler ../1.2/sp2, flags -O4,p -proc arm946e, isa arm)
- `button_man_p08.c`: func_02056460 .. func_02057E68 (compiler ../1.2/sp2, flags -O4,p, isa arm)
- `button_man_p09.c`: func_02057EF8 .. func_020583CC (compiler ../1.2/sp2, flags -O4,p, isa arm)
- `button_man_p10.c`: func_0205841C (compiler 1.1p1, flags -O4,p -proc arm7tdmi, isa arm)

Boundaries:
- p01 (1.1p1): real, func_02051788.. builds DIFF under ../1.2/sp2.
- p02 | p03 (old p02..p03 and p04): local struct views `Row_020524C8`/`Row_02052984`, `Obj_02052FC8` against `Obj`, `Node_020524C8` field f24_b3 and prev missing in the other view: needs one canonical Row/Node/Obj struct by offset.
- p06 | p07, p07 | p08, p08 | p09, p09 | p10: bitfield views `Bf16`, `Bf23`, `BfZero` (members sel, sel1, sel2, flag differ per view), `SubB_0205429C` f7c, `SubC_02054718`, `SubC_02054A68`, `SubC_02055FD4`. One canonical struct per object is still to be built.
- p10 | p11: DIFF when merged (not located). p11 | p12: `Obj_02057EF8` fields f00, f02 against the merged `struct Obj`.
- Round 5 retag: func_02053D2C (old p05), func_02058300 (old p13) and func_02058380 (old p14) build EXACT under ../1.2/sp2 -O4,p; they were tagged 1.1p1 (arm7tdmi). Now merged into the 1.2 runs.
- The last file, func_0205841C (old p16, 1.1p1 -proc arm7tdmi), is DIFF under 1.2: real boundary.
