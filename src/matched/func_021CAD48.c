/*
 * function: func_021CAD48
 * address:  0x021CAD48
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Clears a 0x110-byte record and both of its end markers.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082BCC(void *, int, int);

void func_021CAD48(u8 *p)
{
    func_02082BCC(p, 0, 0x110);
    *(u32 *)p = 0;
    *(u32 *)(p + 0x108) = 0;
}
