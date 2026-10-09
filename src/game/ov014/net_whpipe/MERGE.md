# net_whpipe (ov014)

Round 5 (r5s09): 4 parts to 2, both EXACT. g_021797A4 is now one declaration (`extern u8 *g_021797A4;`)
in the whole second part, as the former func_021777FC part needs (a `struct W *` or a cast moves its
registers). The other functions already used it as `u8 *` through casts, so those casts are gone;
func_021773E0 keeps one `W *base = (W *)g_021797A4` view.

Remaining boundary:
- p01|p02: four linker veneers at 0x0217725C..0x0217727C (real file boundary, not C code).
