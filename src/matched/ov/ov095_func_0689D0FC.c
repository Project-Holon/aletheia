/*
 * function: func_0689D0FC
 * address: 0x0689D0FC
 * packet: pkt_ov095_0689D0FC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_0689D0FC(u8 *p)
{
    u32 i;
    p[0] = 0;
    for (i = 0; i < 24; i++) {
        p[i + 25] = 31;
        p[i + 1] = 0;
    }
}
