/*
 * function: func_0689CAB0
 * address: 0x0689CAB0
 * packet: pkt_ov095_0689CAB0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689CAD8 0x0689CAD8 thumb ov095
 */
typedef unsigned char u8;
extern void func_0689CAD8(u8 *p, u8 v, int i);
void func_0689CAB0(u8 *p, u8 n)
{
    u8 i;
    for (i = 0; i < n; i++)
        func_0689CAD8(p, 2, i);
}
