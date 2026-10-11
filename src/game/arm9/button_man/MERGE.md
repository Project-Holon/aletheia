# button_man (arm9)

Round 18 (lane L12b): 5 parts -> 3.
- p01: compiler 1.1p1 (real boundary, func_02051788.. builds DIFF under ../1.2/sp2).
- p02: old p02, p03 and p04 (func_020524C8 .. func_020583CC, ../1.2/sp2, -O4,p, EXACT). One Obj/SubB/SubX/SubC/SubD/S
  family for the 3D rig object, SPLTexture rows instead of Row/Res clones, SPLList/SPLNode for the list functions
  (no volatile), one FX_Mul, one Range struct.
- p03: func_0205841C, 1.1p1 -proc arm7tdmi (real boundary, DIFF under 1.2).

Left in p02 (stand-ins): fn = (Fn)func_02055498 and (Fn)func_02054DB8 (SPLManager/SPLParticle handlers stored in an
Obj/S row table); func_0205250C, func_020525A0, func_02052634, func_020526A8, func_02052770, func_020524C8 still use
char * offsets and Head_020524C8/Head_02052770 clones of the rig object; alias symbol rows SPL* for same-TU functions.
