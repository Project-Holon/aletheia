/*
 * function: IRCBATTLEMENU_SeqSetupTopMenu
 * address:  0x021966F0
 * packet:   pkt_ov021_021966F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_LoadSubBgScreen  0x021966B0  thumb  ov021
 *   IRCBATTLEMENU_CreateTopMenuActors  0x0219707C  thumb  ov021
 *   IRCBATTLEMENU_CreateButtonWindows  0x0219630C  thumb  ov021
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_TouchCallback  0x0219649C  thumb  ov021
 *   IRCBATTLEMENU_TouchTopMenu  0x02196974  thumb  ov021
 *   IRCBATTLEMENU_SeqUpdateTouchTop  0x02196A4C  thumb  ov021
 *   sTopMenuMsgIds     0x021D4070  data  a4
 *   sTopMenuTextCenterX     0x021D4014  data  a4
 *   sTopMenuTextCenterY     0x021D4024  data  a4
 *   sTopMenuTouchRects     0x021D404C  data  a4
 *   sTopMenuWinDescs     0x021DDB84  data  a4
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } Blk;

extern Blk sTopMenuMsgIds;
extern u8 sTopMenuTextCenterX[];
extern u8 sTopMenuTextCenterY[];
extern u8 sTopMenuTouchRects[];
extern u8 sTopMenuWinDescs[];
struct Cb;
extern void IRCBATTLEMENU_LoadSubBgScreen(u8 *p, u32 a);
extern void IRCBATTLEMENU_CreateTopMenuActors(u8 *p);
extern void IRCBATTLEMENU_CreateButtonWindows(u32 a, void *b, void *c, void *d, void *e, void *f);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern void IRCBATTLEMENU_SetSeq(void *p, void *fn, u32 n);
extern void IRCBATTLEMENU_TouchCallback(void *a, int b, struct Cb *c);
extern int IRCBATTLEMENU_TouchTopMenu(u32 s, u8 *p);
extern void IRCBATTLEMENU_SeqUpdateTouchTop(u8 *a);

void IRCBATTLEMENU_SeqSetupTopMenu(u8 *p)
{
    Blk t = sTopMenuMsgIds;

    IRCBATTLEMENU_LoadSubBgScreen(p, 0xB);
    IRCBATTLEMENU_CreateTopMenuActors(p);
    IRCBATTLEMENU_CreateButtonWindows(4, &t, p, sTopMenuWinDescs, sTopMenuTextCenterX, sTopMenuTextCenterY);
    *(u32 *)&((struct Obj00093 *)p)->f24 = (u32)BUTTON_MAN_Create(sTopMenuTouchRects, (int)((void *)IRCBATTLEMENU_TouchCallback), (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = (void *)IRCBATTLEMENU_TouchTopMenu;
    IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqUpdateTouchTop, 0x340);
}
