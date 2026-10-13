/*
 * function: ITEMMENU_IsBackButtonTouched
 * address: 0x021B66B8
 * packet: pkt_ov070_021B66B8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 */
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
int ITEMMENU_IsBackButtonTouched(void)
{
    unsigned int x;
    unsigned int y;
    if (TOUCHPANEL_GetPointTrg(&x, &y) == 1 && x >= 0xE0 && x <= 0xF7 && y >= 0xA8 && y <= 0xBF) return 1;
    return 0;
}
