# bmp_menulist (arm9)

Round 17 (lane L11): 3 parts -> 2. p01 is the old p01 and p02 over one `struct Menu` (union Flags1A at +0x1A for the
three bitfield layouts; func_020208B8 takes u16 n).

Boundary left: p01 | p02 (func_02020CA0 ..). func_02020CA0 passes `(u32)(tile << 21) >> 16` to func_02020A58 and
func_02020B5C, whose fifth parameter is u16 (the callee reads it with ldrh from the stack). With the u16 prototype in
scope mwcc adds lsls/lsrs #16 at the call (6 bytes per call off); u32 or unprototyped declarations of the callee
close the caller but break the callee. The caller was compiled against a different declaration: probably a real
source file boundary. The rest of p02 builds on struct Menu (func_02020CF8 uses f3C).
