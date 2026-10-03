/*
 * function: func_0689D118
 * address: 0x0689D118
 * packet: pkt_ov095_0689D118
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0689D0FC 0x0689D0FC thumb ov095
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0689D0FC(u8 *p);
void func_0689D118(u8 *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0689D0FC(p + i * 49);
    }
}
