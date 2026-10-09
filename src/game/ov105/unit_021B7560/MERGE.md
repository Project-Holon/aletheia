# unit_021B7560.c (ov105)

Merged as far as the verifier and the compile allow. Remaining parts:

- `unit_021B7560_p01.c`: func_021B7560 .. func_021B80D8 (37 functions)
- `unit_021B7560_p02.c`: func_021B80E8,func_021B8340 .. func_021B8840 (12 functions)

Blockers:

- data labels d_021B8974 and d_021B8984 have no witness outside a whole-TU window. Compile is clean after: unify Data_021B80E8 into Data_021B7560 and Display_021B8348 into Display (identical fields), (Window *)(p+0xc0) cast at the func_021B8008 calls. The two parts are the verifier's floor.

Shared rule: the part files must stay separate where a data label only has witnesses in the other part.
