/*
 * unit: yes
 * function: BTLV_SCD_ShowTargetSetMenu, BTLV_SCD_IsTargetChosen
 * address: 0x0689B098
 * packet: pkt_ov095_0689B098
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: unlabelled byte accessor at 0x0689B0CC, followed by alignment padding.
 * symbols:
 *   BTLV_SCD_ShowTargetMenu 0x0689AE34 thumb ov095
 */
typedef unsigned char u8;
extern void BTLV_SCD_ShowTargetMenu(u8 *list, u8 n, int unused, u8 *s);

void BTLV_SCD_ShowTargetSetMenu(u8 *p, u8 *s)
{
    if (p[0] != 0) {
        BTLV_SCD_ShowTargetMenu(p + 3, p[0], 0, s);
    } else if (p[2] == 1) {
        BTLV_SCD_ShowTargetMenu(p + 3, p[1], 1, s);
    } else {
        BTLV_SCD_ShowTargetMenu(p + 3, p[1], 2, s);
    }
}

u8 BTLV_SCD_IsTargetChosen(u8 *p)
{
    return p[0x89];
}
