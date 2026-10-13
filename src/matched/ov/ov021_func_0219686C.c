/*
 * function: IRCBATTLEMENU_HookTopMenuPressed
 * address:  0x0219686C
 * packet:   pkt_ov021_0219686C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02155A94  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetButtonMode  0x02008428  thumb
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqStartFadeOut  0x02196804  thumb  ov021
 *   IRCBATTLEMENU_SeqSaveQuestion  0x02197700  thumb  ov021
 *   IRCBATTLEMENU_SeqSetupKindMenu  0x02196A60  thumb  ov021
 */
#include "../include/Obj09492.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sub02008700Obj;
extern u32 func_02155A94(u8 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int CONFIG_GetButtonMode(unsigned short *p);
extern void IRCBATTLEMENU_SetSeq(void *p, void *fn, u32 n);
extern void IRCBATTLEMENU_SeqStartFadeOut(u8 *p);
extern void IRCBATTLEMENU_SeqSaveQuestion(u8 *a);
extern void IRCBATTLEMENU_SeqSetupKindMenu(u8 *p);

void IRCBATTLEMENU_HookTopMenuPressed(u8 *p)
{
    if (((struct Obj09492 *)p)->f8 == 0xC) {
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqStartFadeOut, 0x38C);
        return;
    }
    if (CONFIG_GetButtonMode((unsigned short *)func_0200873C((void *)func_02155A94((u8 *)(((struct Obj09492 *)p)->f2E4)))) == 1) {
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqSaveQuestion, 0x38F);
        return;
    }
    if (((struct Obj09492 *)p)->f8 - 6 <= 2) {
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqStartFadeOut, 0x394);
        return;
    }
    IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqSetupKindMenu, 0x397);
}
