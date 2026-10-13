/*
 * function: WIFICLUB_ClosePanelIfSlotSelected
 * address:  0x021C1A14
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_GetSelectedSlotPlusOne  0x021C1C64  thumb  ov099
 *   WIFICLUB_ClosePartnerPanel  0x021C19DC  thumb  ov099
 *
 * When the byte 0x8ED bytes in matches, hands the block and the third argument on.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 WIFICLUB_GetSelectedSlotPlusOne(char *p);
extern void WIFICLUB_ClosePartnerPanel(char *p, int v);

void WIFICLUB_ClosePanelIfSlotSelected(char *p, int b, void *c)
{
    if (b == WIFICLUB_GetSelectedSlotPlusOne(p)) {
        WIFICLUB_ClosePartnerPanel(p, (int)c);
    }
}
