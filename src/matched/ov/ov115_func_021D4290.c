/*
 * function: WIFILOGIN_COMMON_GetSessionId
 * address: 0x021D4290
 * packet: pkt_ov115_021D4290
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov115/unit_021D4240.c and filed here.
 *
 * symbols:
 *   gWifiloginDialogId 0x021D6640 data a4
 */

typedef unsigned char u8;
extern u8 gWifiloginDialogId[];

u8 *WIFILOGIN_COMMON_GetSessionId(void)
{
    return gWifiloginDialogId;
}
