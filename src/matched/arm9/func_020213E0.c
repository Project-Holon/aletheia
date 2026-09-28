/*
 * unit:     no
 * address:  0x020213E0
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020213E0
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020213E0.c  *       --func func_020213E0 --addr 0x020213E0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_020213E0(u16 v)
{
    if ((u16)(v + 0xFE14) > 8) {
        return 1;
    }
    return 0;
}
