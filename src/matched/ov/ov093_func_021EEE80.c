/*
 * function: BTL_MSG_FormatWithSide
 * address:  0x021EEE80
 * packet:   pkt_ov093_021EEE80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_IsLocalSide  0x021B8BD0  thumb  ov093
 *   BTL_MSG_BuildString  0x021EEEC8  thumb  ov093
 *   sBtlMsgSidePairIds     0x021F39A0  data  a2
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 */

#include "../include/G_ov093_021F6398.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_IsLocalSide(unsigned char *p, unsigned char k);
extern void BTL_MSG_BuildString(u32 a, u32 b, u32 c);
extern const u16 sBtlMsgSidePairIds[];
extern struct G_ov093_021F6398 gBtlMsgState;

void BTL_MSG_FormatWithSide(u32 a, u16 k, u32 *p)
{
    u32 i;

    for (i = 0; i < 27; i++) {
        if (k == sBtlMsgSidePairIds[i]) {
            if (BTL_MAIN_IsLocalSide((*(void * *)&gBtlMsgState), (u8)*p) == 0)
                k = k + 1;
            break;
        }
    }
    BTL_MSG_BuildString(a, k, (u32)p);
}
