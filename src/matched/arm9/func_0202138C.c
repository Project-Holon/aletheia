/*
 * unit:     no
 * address:  0x0202138C
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202138C
 *
 * symbols:
 *   g_0209E8EC     0x0209E8EC  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202138C.c  *       --func func_0202138C --addr 0x0202138C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 g_0209E8EC[];

u8 func_0202138C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return (u8)i;
        }
    }
    return 0;
}
