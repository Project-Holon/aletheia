/*
 * function: IRCBATTLEMENU_HookRuleMenuPressed
 * address:  0x02196E70
 * packet:   pkt_ov021_02196E70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State step: picks the next handler from the state word and a status query.
 *
 * symbols:
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqSetupKindMenu  0x02196A60  thumb  ov021
 *   IRCBATTLEMENU_SeqSetupPartyMenu  0x02196E04  thumb  ov021
 *   IRCBATTLEMENU_SeqStartFadeOut  0x02196804  thumb  ov021
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12633.h"
#include "../include/Obj19636.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
extern void IRCBATTLEMENU_SeqSetupKindMenu(u8 *p);
extern void IRCBATTLEMENU_SeqSetupPartyMenu(u8 *p);
extern void IRCBATTLEMENU_SeqStartFadeOut(u8 *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);

void IRCBATTLEMENU_HookRuleMenuPressed(u8 *p)
{
    if (((struct Obj12633 *)p)->f8 == 0xC) {
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqSetupKindMenu, 0x558);
    } else {
        if (func_0200BBA8(func_0200BAC8(((struct Obj19636 *)(*(u8 * *)&((struct Obj12633 *)p)->f2E4))->f4C)) != 0) {
            IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqSetupPartyMenu, 0x55D);
        } else {
            IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqStartFadeOut, 0x560);
        }
    }
}
