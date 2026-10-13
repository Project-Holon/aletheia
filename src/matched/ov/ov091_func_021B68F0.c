/*
 * function: POKELIST_UpdatePhase
 * address:  0x021B68F0
 * packet:   pkt_ov091_021B68F0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 20 is written before case 19: case 19's fallback repeats case 20's
 * body and mwcc tail-merges it into the earlier copy, which puts case 20's
 * code first in the original.
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   POKELIST_UpdateInputStage  0x021B83D8  thumb  ov091
 *   POKELIST_UpdateSwapAnimation  0x021B981C  thumb  ov091
 *   POKELIST_RunContextMenu  0x021B9020  thumb  ov091
 *   POKELIST_UpdateMessagePhase  0x021B9750  thumb  ov091
 *   POKELIST_UpdateChoiceMenu  0x021B97D4  thumb  ov091
 *   PLIST_PLATE_StartHpAnim  0x021BB30C  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   PLIST_PLATE_StepHpAnim  0x021BB358  thumb  ov091
 *   PLIST_COMM_SendStatus  0x021B6184  thumb  ov090
 *   PLIST_MENU_ButtonWinOpen  0x021BBE44  thumb  ov091
 *   PLIST_MESSAGE_OpenWindow  0x021BB714  thumb  ov091
 *   PLIST_MESSAGE_PrintText  0x021BB7E8  thumb  ov091
 *   PLIST_MESSAGE_RequestPrompt  0x021BBA68  thumb  ov091
 *   PLIST_MENU_UpdateLevelUp  0x021BC6CC  thumb  ov091
 *   PLIST_BATTLE_StartEffect  0x021BD8B0  thumb  ov091
 *   PLIST_BATTLE_UpdateEffect  0x021BD9C8  thumb  ov091
 *   PLIST_BATTLE_FinishEffect  0x021BD8E4  thumb  ov091
 *   PLIST_COMM_StartSync  0x021B61E8  thumb  ov090
 *   PLIST_COMM_IsSyncDoneOrFinished  0x021B61FC  thumb  ov090
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   PLIST_PLATE_Update  0x021BA8CC  thumb  ov091
 *   PLIST_MESSAGE_Update  0x021BB644  thumb  ov091
 *   POKELIST_UpdatePaletteFade  0x021B6B24  thumb  ov091
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   PLIST_MENU_UpdateTimer  0x021BCDE8  thumb  ov091
 *   PLIST_MENU_ButtonWinClose  0x021BBE50  thumb  ov091
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 */
#include "../include/Obj00009.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Actor;
struct PrintSys;
struct S;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern void POKELIST_UpdateInputStage(u8 *p);
extern void POKELIST_UpdateSwapAnimation(u8 *p);
extern void POKELIST_RunContextMenu(u8 *p);
extern void POKELIST_UpdateMessagePhase(unsigned p);
extern void POKELIST_UpdateChoiceMenu(u8 *p);
extern void PLIST_PLATE_StartHpAnim(u8 *p, int s);
extern void func_020061E4(u32 id);
extern int PLIST_PLATE_StepHpAnim(u8 *p, struct S *s);
extern u32 PLIST_COMM_SendStatus(u8 *p, u8 b, u16 a);
extern void PLIST_MENU_ButtonWinOpen(int x);
extern void PLIST_MESSAGE_OpenWindow(void *a, u32 *s, u32 k);
extern void PLIST_MESSAGE_PrintText(u8 *a, u32 *s, u32 x);
extern void PLIST_MESSAGE_RequestPrompt(u8 *p, u8 *s);
extern void PLIST_MENU_UpdateLevelUp(u8 *p);
struct Pal;
extern void PLIST_BATTLE_StartEffect(char *p);
extern void PLIST_BATTLE_UpdateEffect(u8 *p);
extern void PLIST_BATTLE_FinishEffect(u8 *p);
extern void PLIST_COMM_StartSync(void *a, int b);
extern int PLIST_COMM_IsSyncDoneOrFinished(int w, int a);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void PLIST_PLATE_Update(u8 *p, int s);
extern void PLIST_MESSAGE_Update(u8 *p, u8 *s);
extern void POKELIST_UpdatePaletteFade(struct Pal *p);
extern int POKELIST_IsItemMode(u32 p);
extern void PLIST_MENU_UpdateTimer(char *a);
extern void PLIST_MENU_ButtonWinClose(int x);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);

#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

typedef void (*Fn)(u8 *p);

int POKELIST_UpdatePhase(u8 *p)
{
    u8 i;
    Fn fn;

    switch (p[0xc]) {
    case 0:
        WIPE_SYS_Start((void *)2, 1, 1, 0, 6, 1, H(0));
        p[0xc] = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            p[0xc] = p[0xd];
        break;
    case 2:
    case 3:
    case 4:
        POKELIST_UpdateInputStage(p);
        break;
    case 5:
        POKELIST_UpdateSwapAnimation(p);
        break;
    case 6:
        POKELIST_RunContextMenu(p);
        break;
    case 7:
        POKELIST_UpdateMessagePhase((unsigned int)p);
        break;
    case 9:
        POKELIST_UpdateChoiceMenu(p);
        break;
    case 10:
        PLIST_PLATE_StartHpAnim(p, *(int *)(p + W(0x2c) * 4 + 0x160));
        if (W(0x24) == 1) {
            W(0x24) = 0;
            func_020061E4(0x56f);
        }
        p[0xc] = 0xb;
    case 11:
        if (PLIST_PLATE_StepHpAnim(p, (struct S *)(*(int *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            fn = *(Fn *)&((struct Obj00009 *)p)->f120;
            if (fn != 0)
                fn(p);
            else
                p[0xc] = 0x15;
        }
        break;
    case 12:
        p[0x114]++;
        if (p[0x114] > 0x10) {
            if (W(0x20) == 1) {
                if (PLIST_COMM_SendStatus((u8 *)W(0x280), 0, 0) == 1) {
                    p[0xc] = 0x11;
                    PLIST_MENU_ButtonWinOpen(W(0x108));
                    PLIST_MENU_ButtonWinOpen(W(0x10c));
                    W(0x108) = 0;
                    W(0x10c) = 0;
                    PLIST_MESSAGE_OpenWindow(p, (u32 *)W(0x150), 0);
                    PLIST_MESSAGE_PrintText(p, (u32 *)W(0x150), 0xb0);
                    PLIST_MESSAGE_RequestPrompt(p, (u8 *)W(0x150));
                }
            } else {
                p[0xc] = 0x13;
            }
        }
        break;
    case 13:
        PLIST_MENU_UpdateLevelUp(p);
        break;
    case 14:
        PLIST_BATTLE_StartEffect((char *)p);
        break;
    case 15:
        PLIST_BATTLE_UpdateEffect(p);
        break;
    case 16:
        PLIST_BATTLE_FinishEffect(p);
        break;
    case 17:
        PLIST_COMM_StartSync((void *)W(0x280), 2);
        p[0xc] = 0x12;
        break;
    case 18:
        if (PLIST_COMM_IsSyncDoneOrFinished(W(0x280), 2) == 1)
            p[0xc] = 0x13;
        break;
    case 20:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, H(0));
        p[0xc] = 0x15;
        break;
    case 19:
        if (W(0x1e8) == 0 || CLACT_IsActorAnimActive((struct Actor *)W(0x1e8)) == 0) {
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, H(0));
            p[0xc] = 0x15;
        }
        break;
    case 21:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    for (i = 0; i < 6; i++)
        PLIST_PLATE_Update(p, ((int *)(p + 0x160))[i]);
    PLIST_MESSAGE_Update(p, (u8 *)W(0x150));
    POKELIST_UpdatePaletteFade((struct Pal *)p);
    if (POKELIST_IsItemMode((u32)p) == 1) {
        PLIST_MENU_UpdateTimer((char *)p);
        PLIST_MENU_ButtonWinClose(W(0x108));
        PLIST_MENU_ButtonWinClose(W(0x10c));
    }
    PRINTSYS_QUE_Main((struct PrintSys *)W(0x140));
    CLACT_DrawSystem();
    return 0;
}
