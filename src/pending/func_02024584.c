/*
 * function: func_02024584
 * address:  0x02024584
 * packet:   pkt_02024584
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  0209F71C literal
 *
 * symbols:
 *   g_0209F71C  0x0209F71C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u8 g_0209F71C[];

u8 func_02024584(u32 i)
{
    if (i < 7) {
        return g_0209F71C[i];
    }
    return 0;
}
