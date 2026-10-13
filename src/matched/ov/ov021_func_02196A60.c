/*
 * function: IRCBATTLEMENU_SeqSetupKindMenu
 * address:  0x02196A60
 * packet:   pkt_ov021_02196A60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State setup: copies an 8-byte record, calls the setup helpers, installs
 * the per-frame handler at +4 and registers the next step.
 *
 * symbols:
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_CreateButtonWindows  0x0219630C  thumb  ov021
 *   IRCBATTLEMENU_LoadSubBgScreen  0x021966B0  thumb  ov021
 *   IRCBATTLEMENU_CreateKindMenuActors  0x02197190  thumb  ov021
 *   IRCBATTLEMENU_TouchCallback  0x0219649C  thumb  ov021
 *   IRCBATTLEMENU_TouchKindMenu  0x02196BF8  thumb  ov021
 *   IRCBATTLEMENU_SeqUpdateTouchSub  0x02196FF0  thumb  ov021
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   sKindMenuMsgIds     0x021D3FE0  data  ov021  a4
 *   sKindMenuTouchRects     0x021D3FF4  data  ov021  a4
 *   sKindMenuWinDescs     0x021DDAF4  data  ov021  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec8 { u32 a; u32 b; };

extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
extern void IRCBATTLEMENU_CreateButtonWindows(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void IRCBATTLEMENU_LoadSubBgScreen(u8 *p, u32 n);
extern void IRCBATTLEMENU_CreateKindMenuActors(u8 *p);
struct Cb;
extern void IRCBATTLEMENU_TouchCallback(void *a, int b, struct Cb *c);
extern int IRCBATTLEMENU_TouchKindMenu(u32 v, u8 *p);
extern void IRCBATTLEMENU_SeqUpdateTouchSub(u8 *p);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern struct Rec8 sKindMenuMsgIds;
extern u8 sKindMenuTouchRects[];
extern u8 sKindMenuWinDescs[];

void IRCBATTLEMENU_SeqSetupKindMenu(u8 *p)
{
    struct Rec8 loc = sKindMenuMsgIds;

    IRCBATTLEMENU_CreateKindMenuActors(p);
    IRCBATTLEMENU_LoadSubBgScreen(p, 0xC);
    IRCBATTLEMENU_CreateButtonWindows(2, &loc, p, sKindMenuWinDescs, 0, 0);
    ((struct Obj00093 *)p)->f24 = BUTTON_MAN_Create(sKindMenuTouchRects, (int)IRCBATTLEMENU_TouchCallback, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = IRCBATTLEMENU_TouchKindMenu;
    IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqUpdateTouchSub, 0x432);
}
