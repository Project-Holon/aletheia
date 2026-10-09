# field_ground_anime (ov021)

Two parts remain: field_ground_anime_p01.c (021A7360..021A7654) and
field_ground_anime_p02.c (021A7678..021A7B88). Both verify EXACT.

Blocker between them: func_02030734 (the heap allocator) is called with a u32
heap argument and a (u32 heapId, u32 size, int clear, const char *site, u16 tag)
prototype in p01, and with a u16 heap argument and (u16, u32, u32, char *, u32)
in p02. p02's func_021A7678 only matches with a u16 heap parameter, and then
func_021A75DC (p01) passes a u32 heap without the narrowing the compiler would
emit. A single prototype breaks one side by a few instructions. The two parts
look like two translation units (the tuboundary guess was weak).

Round 4 (r4_ov06) re-check: W.a is Obj a[16] (0x40 bytes) and E/E_021A74F4/Obj are one 0x40-byte element; merging with those unified compiles. The remaining blocker is only func_021A7678: with its prototype (heap u16) in view, p01's func_021A75DC (u32 heap on the stack) gets an extra narrowing; with no prototype in view mwcc rejects the later void definition ('redeclared', implicit int). With heap u16 in func_021A75DC the stack load changes (ldr r6,[sp,#0x20] becomes add r6,sp,#0x20). So this is a real unit boundary.
