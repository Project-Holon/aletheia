/*
 * function: func_021D6D9C
 * address: 0x021D6D9C
 * packet: pkt_ov093_021D6D9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bind the requested halfword, keeping the object's remaining value inline.
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_021D6D9C(u8 *p, u16 *value)
{
    u16 requested;
    requested = *value;
    if (*(u16 *)(p + 0x1f2) <= requested) {
        *value = *(u16 *)(p + 0x1f2);
        *(u16 *)(p + 0x1f2) = 0;
        return 1;
    }
    *(u16 *)(p + 0x1f2) -= requested;
    return 0;
}
