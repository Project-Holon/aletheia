/*
 * function: func_021780FC
 * address: 0x021780FC
 * packet: pkt_ov014_021780FC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 *   func_0217778C 0x0217778C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_021797A4;
extern void func_0217778C(void);
void func_021780FC(u8 value)
{
    if (g_021797A4) {
        g_021797A4[0xcea] = value;
        func_0217778C();
    }
}
