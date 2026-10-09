# button_man (arm9)

Translation unit 02051788..020584E0, confidence weak (tools/tuboundary.py). Sixteen files after
round 4 (was 9 parts and 58 single members), address order. Merges happen only inside runs of the
same compiler and flags (`-O4,p` and `-O4,p -proc arm946e` count as equal).

- p01 (02051788..): 1.1p1, 47 functions, one file now.
- p02, p03, p04 (020524C8.., 02052984.., 0205312C..): 1.2/sp2 run. Not merged yet:
  p02|p03 local struct views `Row_020524C8` and `Row_02052984` of one table (CCERR);
  p03|p04 `Obj_02052FC8` against `Obj` (CCERR, also `SPL_TEX_ANIM_MAX_FRAMES` and
  `reg_G3_POLYGON_ATTR` undefined in func_0205312C when merged).
- p05 (02053D2C): 1.1p1 `-proc arm7tdmi`, one function. Real boundary (flags change).
- p06..p12 (02053D30..020582CC): 1.2/sp2 run, same flags. Not merged yet:
  p06|p07|p08|p09 are views of one bitfield struct (`Bf16`, `Bf23`, `BfZero`, members `sel`,
  `sel1`, `sel2`, `flag` differ per view); p09|p10 `SubC_02054A68` against `SubC_02055FD4`;
  p10|p11 DIFF; p11|p12 `Obj_02057EF8` fields `f00`, `f02` against the merged `struct Obj`.
  Done in round 4: p11 absorbed func_02056684, func_020569A4, func_020576D0 etc. after one
  `FX_Mul` helper and one `s32`/`fx32`/`s64`/`VecFx32` typedef set was used in all of them.
  The code in this run is a particle-system library (SPL), probably several source files, so
  merging it all into one file may be wrong even where it verifies.
- p13 (02058300): 1.1p1 `-proc arm7tdmi`. p14 (02058380): 1.1p1 `-O4,p`. p15 (020583CC): 1.2/sp2.
  p16 (0205841C): 1.1p1 `-proc arm7tdmi`. All real boundaries (compiler or flag changes).
