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
 * function: PALANM_IsOutsideReservedIdRange
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_IsOutsideReservedIdRange.c  *       --func PALANM_IsOutsideReservedIdRange --addr 0x020213E0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 PALANM_IsOutsideReservedIdRange(u16 v)
{
    if ((u16)(v + 0xFE14) > 8) {
        return 1;
    }
    return 0;
}
