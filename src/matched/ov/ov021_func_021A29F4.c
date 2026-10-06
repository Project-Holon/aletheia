/*
 * function: func_021A29F4
 * address:  0x021A29F4
 * packet:   pkt_ov021_021A29F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
void func_0204A8D4(u32 i);
void func_0204ADA4(u32 i);
void func_0204AFD8(u32 i);

void func_021A29F4(u16 *p, u32 a1, u32 a2, u32 a3)
{
    if (p[0] != 0) {
        func_0204A8D4(p[1]);
        func_0204ADA4(p[2]);
        func_0204AFD8(p[3]);
        p[0] = 0;
    }
}
