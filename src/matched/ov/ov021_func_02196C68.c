/*
 * function: IRCBATTLEMENU_SeqSetupRuleMenu
 * address:  0x02196C68
 * packet:   pkt_ov021_02196C68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State setup: like IRCBATTLEMENU_SeqSetupKindMenu with a 16-byte record and other handlers.
 *
 * symbols:
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_CreateButtonWindows  0x0219630C  thumb  ov021
 *   IRCBATTLEMENU_LoadSubBgScreen  0x021966B0  thumb  ov021
 *   IRCBATTLEMENU_CreateMainMenuActors  0x0219728C  thumb  ov021
 *   IRCBATTLEMENU_TouchCallback  0x0219649C  thumb  ov021
 *   IRCBATTLEMENU_TouchRuleMenu  0x02196F44  thumb  ov021
 *   IRCBATTLEMENU_SeqUpdateTouchSub  0x02196FF0  thumb  ov021
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   sRuleMenuMsgIds     0x021D4080  data  ov021  a4
 *   sRuleMenuTouchRects     0x021D4034  data  ov021  a4
 *   sRuleMenuWinDescs     0x021DDB44  data  ov021  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec16 { u32 a; u32 b; u32 c; u32 d; };

extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
extern void IRCBATTLEMENU_CreateButtonWindows(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void IRCBATTLEMENU_LoadSubBgScreen(u8 *p, u32 n);
extern void IRCBATTLEMENU_CreateMainMenuActors(u8 *p);
struct Cb;
extern void IRCBATTLEMENU_TouchCallback(void *a, int b, struct Cb *c);
extern int IRCBATTLEMENU_TouchRuleMenu(u32 v, u8 *p);
extern void IRCBATTLEMENU_SeqUpdateTouchSub(u8 *p);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern struct Rec16 sRuleMenuMsgIds;
extern u8 sRuleMenuTouchRects[];
extern u8 sRuleMenuWinDescs[];

void IRCBATTLEMENU_SeqSetupRuleMenu(u8 *p)
{
    struct Rec16 loc = sRuleMenuMsgIds;

    IRCBATTLEMENU_CreateMainMenuActors(p);
    IRCBATTLEMENU_LoadSubBgScreen(p, 0xD);
    IRCBATTLEMENU_CreateButtonWindows(4, &loc, p, sRuleMenuWinDescs, 0, 0);
    ((struct Obj00093 *)p)->f24 = BUTTON_MAN_Create(sRuleMenuTouchRects, (int)IRCBATTLEMENU_TouchCallback, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = IRCBATTLEMENU_TouchRuleMenu;
    IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqUpdateTouchSub, 0x4CC);
}
