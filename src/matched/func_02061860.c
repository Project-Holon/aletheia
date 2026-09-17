/*
 * function: func_02061860
 * address:  0x02061860
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns whether the +0xc halfword equals the +4 word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061860.c \
 *       --func func_02061860 --addr 0x02061860 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02061860(u8 *p)
{
    u16 a = *(u16 *)(p + 0xc);
    u32 b = *(u32 *)(p + 4);

    return a == b ? 1 : 0;
}
