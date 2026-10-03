/*
 * function: func_02161F00
 * address:  0x02161F00
 * packet:   pkt_02161F00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082BCC(void *dst, u8 data, u32 size);

void func_02161F00(void *p)
{
    func_02082BCC(p, 0, 4);
    *(u16 *)((char *)p + 2) = 10;
}
