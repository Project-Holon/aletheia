/*
 * function: func_02178138
 * address: 0x02178138
 * packet: pkt_ov014_02178138
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *g_021797A8;
void func_02178138(int state)
{
    *(int *)(g_021797A8 + 0x1e70) = state;
}
