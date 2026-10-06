/*
 * function: func_021CF0F4
 * address:  0x021CF0F4
 * packet:   pkt_ov021_021CF0F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021909BC  0x021909BC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021909BC(void *a);

void func_021CF0F4(u8 *p)
{
    u32 *q = (u32 *)(p + 0x130);

    if (q[0] != 0) {
        func_021909BC((void *)q[0]);
        q[0] = 0;
    }
    ((u8 *)q)[8] = 0;
}
