/*
 * function: func_021A1934
 * address:  0x021A1934
 * packet:   pkt_ov021_021A1934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only the OR association/load order differs (orig loads +0x1F
 * first, ORs 0x8080 with the +0x1E<<24 term, then the +0x1F<<16 term).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_021A1934(u8 *p)
{
    *(volatile u32 *)0x040004C0 = 0x7FFFFFFF;
    *(volatile u32 *)0x040004A4 = (p[0x1F] << 16) | (p[0x1E] << 24) | 0x8080;
}
