# ghttpEncryption.c (ov114)

Translation unit 021C109C..021C1D30, 17 functions. The TU is now two files:
ghttpEncryption_p01.c (021C109C..) and ghttpEncryption_p02.c (021C121C..). All
parts use one compiler and one set of flags (dsi/1.1p1, -O4,p, ARM, c99).

Blocker, unmatched code:

- 0x021C1204..0x021C1210: 12 bytes between func_021C1184 and func_021C1210
  (CaseInsensitiveCompare) that no function covers. It is a linker veneer
  (ldr ip, [pc]; bx ip; literal word, branch to func_020948E0). A merged file
  lays CaseInsensitiveCompare 12 bytes too early and every later function
  shifts, so the boundary stays until veneers are generated or placed in a file.

Everything else was merged by hand: func_0217D254 has the definition's prototype
(int, char *, int, const char *, ...) with casts at the calls, the d_ and g_ names
for the same globals are one name, and the two views of CPSSslConnection are one
struct.
