# unit_0273042C.c (twl)

Parts: p01 (0273042C..027312D0), p02 (027312D0..).

An empty `asm void f(void) {}` stand-in lays out 0 bytes, so the status of its file says EXACT or EXACT* without any code being compared. Merging a part that holds such a stand-in with the next part moves the next part's code and the merged TU is DIFF. The boundary stays until the stand-in is written as real C (or asm with a body) that lays out the original bytes.

p01 holds 29 empty stand-ins and no real code: func_0273042C, 02730440, 02730454 (20 bytes each), 02730468 (468), 0273063C (556), 02730868 (320), 027309A8, 027309FC, 02730B04, 02730B48, 02730BD8, 02730C2C, 02730CC0, 02730D50, 02730DE4, 02730EEC, 02730FBC, 02731000, 02731060, 027310C0, 0273112C, 02731154, 027311A0, 027311E8, 02731210, 02731234, 02731254, 0273126C, 027312B4. p01|p02 is DIFF for that reason.

