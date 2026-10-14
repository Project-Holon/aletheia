/*
 * function: WORLDTRADE_SEARCH_StateWaitMessageOrKey
 * address:  0x021FF0BC
 * packet:   pkt_021FF0BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_IsStreamDone  0x02202840  thumb  ov135
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9

 * When the build query answers 0 and either probe is set, roll the state word over.
 */
#include "../include/Obj12217.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 WORLDTRADE_ADAPTER_IsStreamDone(u8 *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);

int WORLDTRADE_SEARCH_StateWaitMessageOrKey(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone(p + 0xfa0) == 0) {
        if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
            ((struct Obj12217 *)p)->f28 = ((struct Obj12217 *)p)->f2C;
        }
    }
    return 2;
}
