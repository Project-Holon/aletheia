/*
 * function: BEACON_VIEW_PowerAnimTaskB
 * address:  0x021F1CF0
 * packet:   pkt_ov032_021F1CF0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_PowerAnimTaskB 0x021F1CF0 thumb
 *   BEACON_VIEW_SetupMessageText 0x021F0A98 thumb ov032
 *   BEACON_VIEW_ShowWindowText 0x021F0B80 thumb ov032
 *   BEACON_VIEW_StartScrollStep 0x021F178C thumb ov032
 *   BEACON_VIEW_CreateTaskMenuButtons 0x021F0C04 thumb ov032
 *   BEACON_VIEW_ClearWindow 0x021F0B64 thumb ov032
 *   BEACON_VIEW_SetActorVisible 0x021F0E04 thumb ov032
 *   BEACON_VIEW_UpdateTaskMenuButtons 0x021F0C70 thumb ov032
 *   BEACON_VIEW_RequestTransition 0x021F253C thumb ov032
 *   BEACON_VIEW_DeleteTaskMenuButtonsAlt 0x021F0D9C thumb ov032
 *   BEACON_VIEW_FinishTaskMenuButtonsAlt 0x021F0D5C thumb ov032
 *   BEACON_VIEW_ShowPlayTime 0x021F0B10 thumb ov032
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb ov032
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj00007.h"
#include "../include/Obj00879.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BEACON_VIEW_SetupMessageText(char *p, unsigned a);
extern void BEACON_VIEW_ShowWindowText(char *p, void *t, unsigned a);
extern void BEACON_VIEW_StartScrollStep(char *p, u8 a, int *s);
extern void BEACON_VIEW_CreateTaskMenuButtons(char *p, int flag);
extern void BEACON_VIEW_ClearWindow(char *p);
struct TcblNode;
extern void BEACON_VIEW_SetActorVisible(char *p, unsigned a);
extern int BEACON_VIEW_UpdateTaskMenuButtons(char *p, int flag);
extern void BEACON_VIEW_RequestTransition(char *p, int v);
extern void BEACON_VIEW_DeleteTaskMenuButtonsAlt(char *p);
extern int BEACON_VIEW_FinishTaskMenuButtonsAlt(char *p, int i);
extern void BEACON_VIEW_ShowPlayTime(char *p, int a, int b);
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_PowerAnimTaskB(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj00879 *)t)->f1C;
    if (((struct Obj00879 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        if (((struct Obj00879 *)t)->f14 != 0)
            BEACON_VIEW_SetupMessageText(p, (u8)((((struct Obj00879 *)t)->f16 != 0 ? 1 : 0) + 9));
        else if (((struct Obj00879 *)t)->f10 < ((struct Obj00879 *)t)->f12)
            BEACON_VIEW_SetupMessageText(p, (u8)8);
        BEACON_VIEW_ShowWindowText(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        BEACON_VIEW_StartScrollStep(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        BEACON_VIEW_SetActorVisible(p, 0);
        t[0]++;
        break;
    case 3:
        BEACON_VIEW_CreateTaskMenuButtons(p, 1);
        BEACON_VIEW_ClearWindow(p);
        t[0]++;
        break;
    case 4:
        r = BEACON_VIEW_UpdateTaskMenuButtons(p, 1);
        if (r < 0)
            break;
        t[5] = r;
        if (t[5] == 0) {
            BEACON_VIEW_RequestTransition(p, 7);
            p[0x79] = 1;
            t[0] = 5;
        } else {
            t[0] = 6;
        }
        break;
    case 5:
        if (((struct Obj00007 *)p)->f79 != 0) {
            t[0] = 4;
            break;
        }
        BEACON_VIEW_DeleteTaskMenuButtonsAlt(p);
        t[0] = 7;
        break;
    case 6:
        if (BEACON_VIEW_FinishTaskMenuButtonsAlt(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 7:
        BEACON_VIEW_ShowPlayTime(p, 1, (int)((int *)(t + 8)));
        BEACON_VIEW_SetActorVisible(p, 1);
        BEACON_VIEW_StartScrollStep(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        BEACON_VIEW_SetArrowAnim((u8 *)p, 4, (int)0);
        (**(int * *)&((struct Obj00879 *)t)->f20)--;
        TCBL_DeleteTask(h);
        break;
    }
}
