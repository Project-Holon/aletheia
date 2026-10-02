/*
 * function: func_021D6E50
 * address: 0x021D6E50
 * packet: pkt_ov093_021D6E50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_021D6E50(u8 *p, u8 *id, u16 *value)
{
    if (p[0x1f6] != 0x1f) {
        *id = p[0x1f6];
        *value = *(u16 *)(p + 0x1f4);
        return 1;
    }
    return 0;
}
