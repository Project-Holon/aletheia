/*
 * function: func_0217814C
 * address: 0x0217814C
 * packet: pkt_ov014_0217814C
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
void func_0217814C(int error)
{
    if ((unsigned)(*(int *)(g_021797A8 + 0x1e70) - 9) > 1)
        *(int *)(g_021797A8 + 0x1e98) = error;
}
