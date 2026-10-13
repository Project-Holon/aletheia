/*
 * function: C_GEAR_TickIndicators
 * address: 0x021F2D50
 * packet: pkt_ov029_021F2D50
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_IsAnyIndicatorShown 0x021F2DA8 thumb ov029
 *   C_GEAR_FadeBackground 0x021F0EB0 thumb ov029
 */
typedef unsigned char u8;
extern int C_GEAR_IsAnyIndicatorShown(u8 *p);
extern void C_GEAR_FadeBackground(char *p, int flag);
void C_GEAR_TickIndicators(u8 *p)
{
    if (p[0x45e] != 0) {
        p[0x45f]++;
        if (p[0x45f] >= 8) {
            C_GEAR_FadeBackground((char *)p, C_GEAR_IsAnyIndicatorShown(p));
            p[0x45e] = 0;
        }
    }
}
