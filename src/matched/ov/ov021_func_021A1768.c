/*
 * function: func_021A1768
 * address:  0x021A1768
 * packet:   pkt_ov021_021A1768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047204  0x02047204  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Tagged;
u32 func_02047204(struct Tagged *p);

void func_021A1768(u8 *p)
{
    if (p[7] != 0) {
        func_02047204((struct Tagged *)(*(u32 *)(p + 8)));
        p[7] = 0;
    }
}
