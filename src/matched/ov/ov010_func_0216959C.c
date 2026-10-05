/*
 * function: func_0216959C
 * address:  0x0216959C
 * packet:   pkt_ov010_0216959C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears five word fields of a record (offsets 0xB4, 0xC0, 0xC8, 0xCC, 0xD0).
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned int u32;

void func_0216959C(u8 *p)
{
    *(u32 *)(p + 0xB4) = 0;
    *(u32 *)(p + 0xC0) = 0;
    *(u32 *)(p + 0xC8) = 0;
    *(u32 *)(p + 0xCC) = 0;
    *(u32 *)(p + 0xD0) = 0;
}
