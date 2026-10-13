/*
 * function: UNION_ONESELF_TrainerCardMain
 * address:  0x0217CFA8
 * packet:   pkt_ov019_0217CFA8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   TRCARD_SYS_BuildProfile  0x0216F40C  thumb  ov010
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_MSG_CheckLanguageVersion  0x0217EE4C  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_COMMAND_SendTrainerCard  0x02173BB0  thumb  ov012
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   TRCARD_SYS_CreateEditWork  0x0216F7F4  thumb  ov010
 *   UNION_MAIN_RequestScene  0x0217422C  thumb  ov012
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   gUnionEmptyString1     0x021807E4  data  a4
 *   d_021807E8     0x021807E8  data  a4
 */
#include "../include/Obj00610.h"

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
    u8 pad18[0x5d - 0x18];
    u8 f5d;
} Obj;

typedef unsigned short u16;
struct Profile;
extern int UNION_ONESELF_CheckNetError(char *p);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void TRCARD_SYS_BuildProfile(struct Profile *out, void *save, int mode, int flag, volatile u16 heap);
extern void MI_CpuCopy8(void *a, void *b, int c);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
extern int UNION_MSG_CheckLanguageVersion(int **p, int x, int y);
typedef unsigned int   u32;
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern u32 UNION_COMMAND_SendTrainerCard(unsigned char *p);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern void *TRCARD_SYS_CreateEditWork(int a, void *b, int c);
extern void UNION_MAIN_RequestScene(u8 *p, int a, int b);
extern int UNION_MAIN_IsScenePending(u8 *a);
extern u32 func_020307B0(void *p);
extern u32 GFL_NET_IsParentAid(void);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern u8 gUnionEmptyString1[];
extern u8 d_021807E8[];

int UNION_ONESELF_TrainerCardMain(u8 *a, Obj *b, u8 *c, u8 *d)
{
    u8 *q;
    if (UNION_ONESELF_CheckNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (((struct Obj00610 *)a)->f3540 != 0 || ((struct Obj00610 *)a)->f3544 != 0)
            func_02034714((const char *)gUnionEmptyString1, 0, (const char *)gUnionEmptyString1);
        ((struct Obj00610 *)a)->f3540 = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B3);
        ((struct Obj00610 *)a)->f3544 = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B5);
        TRCARD_SYS_BuildProfile(((struct Obj00610 *)a)->f3540, (void *)((*(int **)a)[2]), 1, 0, 0x41);
        MI_CpuCopy8(((struct Obj00610 *)a)->f3540, ((struct Obj00610 *)a)->f3544, 0x678);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x14);
        UNION_MSG_SetupPrintTalkMsg(a, c, UNION_MSG_CheckLanguageVersion((int **)a, b->f14[0x26], b->f14[0x27]));
        (*d)++;
        break;
    case 1:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (UNION_COMMAND_SendTrainerCard(a) == 1)
            (*d)++;
        break;
    case 3:
        if (b->f5d == 1 && UNION_MSG_CheckTalkPrintEnd(a) == 1) {
            q = *(u8 * *)&((struct Obj00610 *)a)->f3544;
            q[4] |= 0x20;
            ((struct Obj00610 *)a)->f353C = TRCARD_SYS_CreateEditWork((*(int **)a)[2], ((struct Obj00610 *)a)->f3544, 0x41);
            (*d)++;
        }
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x14);
        (*d)++;
        break;
    case 5:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x14) == 1)
            (*d)++;
        break;
    case 6:
        UNION_MAIN_RequestScene(a, 1, (int)(((struct Obj00610 *)a)->f353C));
        (*d)++;
        break;
    case 7:
        if (UNION_MAIN_IsScenePending(a) == 0)
            (*d)++;
        break;
    case 8:
        UNION_MSG_SetupPrintTalkMsg(a, c, 0x10);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x14);
        (*d)++;
        break;
    case 9:
        if (UNION_MSG_CheckTalkPrintEnd(a) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x14) == 1) {
            func_020307B0(((struct Obj00610 *)a)->f3540);
            func_020307B0(((struct Obj00610 *)a)->f3544);
            ((struct Obj00610 *)a)->f353C = 0;
            ((struct Obj00610 *)a)->f3540 = 0;
            ((struct Obj00610 *)a)->f3544 = 0;
            if (GFL_NET_IsParentAid() == 1)
                UNION_ONESELF_SetNextPlayCategory((char *)a, 7);
            else
                UNION_ONESELF_SetNextPlayCategory((char *)a, 9);
            return 1;
        }
        break;
    }
    return 0;
}
