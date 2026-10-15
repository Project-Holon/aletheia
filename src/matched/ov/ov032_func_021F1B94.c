/*
 * function: BEACON_VIEW_PowerAnimTaskA
 * address:  0x021F1B94
 * packet:   pkt_ov032_021F1B94
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_PowerAnimTaskA 0x021F1B94 thumb
 *   d_021F352C 0x021F352C data ov032 a1
 *   BEACON_VIEW_SetupMessageText 0x021F0A98 thumb ov032
 *   BEACON_VIEW_ShowWindowText 0x021F0B80 thumb ov032
 *   BEACON_VIEW_StartScrollStep 0x021F178C thumb ov032
 *   BEACON_VIEW_SetPrintQueueLimit 0x021F029C thumb ov032
 *   BEACON_VIEW_CreateTaskMenuButtons 0x021F0C04 thumb ov032
 *   BEACON_VIEW_ClearWindow 0x021F0B64 thumb ov032
 *   BEACON_VIEW_SetActorVisible 0x021F0E04 thumb ov032
 *   BEACON_VIEW_UpdateTaskMenuButtons 0x021F0C70 thumb ov032
 *   BEACON_VIEW_RequestTransition 0x021F253C thumb ov032
 *   BEACON_VIEW_DeleteTaskMenuButtons 0x021F0D38 thumb ov032
 *   BEACON_VIEW_FinishTaskMenuButtons 0x021F0CF8 thumb ov032
 *   BEACON_VIEW_ShowPlayTime 0x021F0B10 thumb ov032
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb ov032
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj00007.h"
#include "../include/Obj01037.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021F352C[];
struct TcblNode;
extern void BEACON_VIEW_SetupMessageText(char *p, unsigned a);
extern void BEACON_VIEW_ShowWindowText(char *p, void *t, unsigned a);
extern void BEACON_VIEW_StartScrollStep(char *p, u8 a, int *s);
extern void BEACON_VIEW_SetPrintQueueLimit(char *p, int a);
extern void BEACON_VIEW_CreateTaskMenuButtons(char *p, int flag);
extern void BEACON_VIEW_ClearWindow(char *p);
extern void BEACON_VIEW_SetActorVisible(char *p, unsigned a);
extern int BEACON_VIEW_UpdateTaskMenuButtons(char *p, int flag);
extern void BEACON_VIEW_RequestTransition(char *p, int v);
extern void BEACON_VIEW_DeleteTaskMenuButtons(char *p);
extern int BEACON_VIEW_FinishTaskMenuButtons(char *p, int i);
extern void BEACON_VIEW_ShowPlayTime(char *p, int a, int b);
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_PowerAnimTaskA(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj01037 *)t)->f1C;
    if (((struct Obj01037 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        BEACON_VIEW_SetupMessageText(p, d_021F352C[t[3]]);
        BEACON_VIEW_ShowWindowText(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        BEACON_VIEW_StartScrollStep(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        BEACON_VIEW_SetPrintQueueLimit(p, 1);
        BEACON_VIEW_CreateTaskMenuButtons(p, 0);
        BEACON_VIEW_ClearWindow(p);
        BEACON_VIEW_SetActorVisible(p, 0);
        t[0]++;
        break;
    case 3:
        r = BEACON_VIEW_UpdateTaskMenuButtons(p, 0);
        if (r < 0)
            break;
        t[5] = r;
        switch (t[5]) {
        case 0:
            BEACON_VIEW_RequestTransition(p, 6);
            t[0] = 3;
            break;
        case 1:
            p[0x7f] = ((struct Obj01037 *)t)->fC;
            BEACON_VIEW_RequestTransition(p, 5);
            t[0] = 4;
            break;
        case 2:
            t[0] = 5;
            break;
        }
        break;
    case 4:
        if (*(u8 *)&((struct Obj00007 *)p)->f7F != 0x30) {
            p[0x7f] = 0x30;
            t[0] = 3;
            break;
        }
        BEACON_VIEW_DeleteTaskMenuButtons(p);
        t[0] = 6;
        break;
    case 5:
        if (BEACON_VIEW_FinishTaskMenuButtons(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 6:
        BEACON_VIEW_ShowPlayTime(p, 1, (int)((int *)(t + 8)));
        BEACON_VIEW_SetActorVisible(p, 1);
        BEACON_VIEW_StartScrollStep(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        BEACON_VIEW_SetArrowAnim((u8 *)p, 4, 0);
        BEACON_VIEW_SetPrintQueueLimit(p, 0);
        (**(int * *)&((struct Obj01037 *)t)->f20)--;
        TCBL_DeleteTask(h);
        break;
    }
}
