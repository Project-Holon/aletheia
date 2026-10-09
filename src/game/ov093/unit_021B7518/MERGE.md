# unit_021B7518.c (ov093)

Round 3 (lane r3_ov08): p01 and p02 (old numbering) merged into unit_021B7518_p01.c. 3 part files remain, each byte-exact.

- func_021B6818 is now declared `u8 (int *)` and func_021BAB10 `(int, u8, int)` in the merged part, with casts at the old p01 call sites (bytes unchanged).
- p01 | p02 (CTRDGi_IsTaskBusy at 0x021B86CA, an SDK libctrdg function): merge compiles to DIFF. Different object (SDK code), real boundary.
- p02 | p03 (func_021B86DC and later): merge compiles to DIFF. Probably the same SDK object, not game code; boundary stays until that is shown.
