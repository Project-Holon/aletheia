/*
 * function: func_02028230
 * address:  0x02028230
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f   0x0209C0A4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028230.c \
 *       --func func_02028230 --addr 0x02028230 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_02028230(u8 *p)
{
    s32 r = 0x10 / (s32)*(u16 *)(p + 0x12);

    if ((s32)*(u16 *)(p + 0x10) < r) {
        return 0;
    }
    return 1;
}