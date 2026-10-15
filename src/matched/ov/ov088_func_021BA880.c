/*
 * unit:     yes
 * function: STARTMENU_StateUnlockNotices, STARTMENU_StateBeginFadeIn
 * address:  0x021BA880
 * packet:   pkt_ov088_021BA880
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x021BA984 is an unlabelled tail-call stub (function_starts seed);
 * verified with tu over 0x021BA880..0x021BA990 (272 bytes).
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   STARTMENU_BeginFadeOut  0x021BC054  thumb  ov088
 *   STARTMENU_HideMessageWindow  0x021BBF98  thumb  ov088
 *   STARTMENU_BeginFadeIn  0x021BC080  thumb  ov088
 *   STARTMENU_StartMessage  0x021BBF1C  thumb  ov088
 *   STARTMENU_UpdateMessage  0x021BBFA8  thumb  ov088
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   gStartMenuUnlockNotices     0x021BD784  data  ov088  a4
 */
#include "../include/Obj02127.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 mask;
    u32 msg;
} MsgEnt;

extern const MsgEnt gStartMenuUnlockNotices[8];

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern int STARTMENU_BeginFadeOut(char *p, int v);
extern void STARTMENU_HideMessageWindow(char *p);
extern int STARTMENU_BeginFadeIn(char *p, int v);
extern void STARTMENU_StartMessage(char *p, u32 a1);
extern int STARTMENU_UpdateMessage(char *p);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);

int STARTMENU_StateUnlockNotices(char *p)
{
    u32 i;
    switch (((struct Obj02127 *)p)->f12A) {
    case 0:
        BG_SYS_SetMainPlaneVisible(0x1e, 0);
        BG_SYS_SetSubPlaneVisible(0x17, 0);
        BG_SYS_LoadPlttEntry(0, 0x7d8c);
        BG_SYS_LoadPlttEntry(4, 0x7d8c);
        ((struct Obj02127 *)p)->f12A = ((struct Obj02127 *)p)->f12A + 1;
        return STARTMENU_BeginFadeOut(p, 10);
    case 1:
        for (;;) {
            i = ((struct Obj02127 *)p)->f14C;
            if (i >= 8) {
                STARTMENU_HideMessageWindow(p);
                ((struct Obj02127 *)p)->f12A = 3;
                return STARTMENU_BeginFadeIn(p, 10);
            }
            if ((gStartMenuUnlockNotices[i].mask & ((struct Obj02127 *)p)->f148) == 0) {
                ((struct Obj02127 *)p)->f14C += 1;
                continue;
            }
            STARTMENU_StartMessage(p, gStartMenuUnlockNotices[i].msg);
            ((struct Obj02127 *)p)->f14C += 1;
            ((struct Obj02127 *)p)->f12A = ((struct Obj02127 *)p)->f12A + 1;
            break;
        }
        break;
    case 2:
        if (STARTMENU_UpdateMessage(p) == 0 && (KEY_GetTrg() & 3)) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            ((struct Obj02127 *)p)->f12A = 1;
        }
        break;
    case 3:
        BG_SYS_SetMainPlaneVisible(0x1e, 1);
        BG_SYS_SetSubPlaneVisible(0x17, 1);
        ((struct Obj02127 *)p)->f12A = 0;
        return STARTMENU_BeginFadeOut(p, 5);
    }
    return 10;
}

int STARTMENU_StateBeginFadeIn(char *p)
{
    return STARTMENU_BeginFadeIn(p, 1);
}
