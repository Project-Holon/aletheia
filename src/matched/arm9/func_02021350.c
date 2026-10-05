/*
 * unit:     no
 * address:  0x02021350
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * function: func_02021350
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021350.c  *       --func func_02021350 --addr 0x02021350 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 func_02021350(u16 id)
{
    if (id >= 0x1A4 && id <= 0x1A9) {
        return (u8)(id - 0x1A4);
    }
    return 0xFF;
}
