# unit_02067FE4 (arm9)

2 files remain (was 5), both EXACT, compiler ../2.0/sp2, -O4,p, c99.

- `unit_02067FE4_p01.c`: func_02067FE4 .. func_02068FC4
- `unit_02067FE4_p02.c`: func_02068FF0 .. func_02069818

Round w10d: one NNSG2dFont/Information/Glyph/Width block and one Ctx in every part; func_020681E4 takes
two ints instead of a by-value struct; func_02068E78 and func_02068150 have one prototype; p02|p03 merged.

Blocker p01|p02: func_02068EA0 (p01) has `u16 code`, which the image narrows inside the callee. Its callers
in p02 (func_020694D8) pass an s32 without narrowing. In one file the definition comes first, so the caller
narrows and the bytes change (tested: `int code` in the definition, K&R definition, `u16 c` in the caller:
all DIFF). The original most likely had the two in different files.

Round 17 (L12) re-test: merged file differs only in func_02068EA0 and func_020694D8. The image loads the
stack argument with `ldrh r1, [sp, #0x2c]` in the callee (so the callee parameter is u16), and the caller
passes its s32 unnarrowed. `int code` in the callee (with func_02067F9C taking int) gives the right sizes
but the callee loads `ldr`, 7 bytes off. A block-scope unprototyped redeclaration is refused by this mwcc
("redeclared"). Real boundary.
