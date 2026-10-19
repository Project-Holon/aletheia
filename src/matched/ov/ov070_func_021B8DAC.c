/*
 * function: ITEMMENU_GetYesNoTouchChoice
 * address: 0x021B8DAC
 * packet: pkt_ov070_021B8DAC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   d_021BB978 0x021BB978 data a4
 */
extern const char d_021BB978[];
extern int TOUCHPANEL_HitTrg(const void *p);
typedef unsigned char  u8;
extern void UI_SetInputMode(u8 v);
int ITEMMENU_GetYesNoTouchChoice(void)
{
    int result;
    result = TOUCHPANEL_HitTrg(d_021BB978);
    if (result != -1)
        UI_SetInputMode(1);
    return result;
}
