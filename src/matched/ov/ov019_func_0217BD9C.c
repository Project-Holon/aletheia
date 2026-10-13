/*
 * function: UNION_ONESELF_ChatInputMain
 * address:  0x0217BD9C
 * packet:   pkt_ov019_0217BD9C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * UNION_COMM_SetChatPms is an unlabelled ov012 thumb leaf, now filed as
 * src/matched/ov/ov012_func_021736A0.c (pkt_ov012_021736A0), which resolves its call.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   UNION_MAIN_RequestScene  0x0217422C  thumb  ov012
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   UNION_COMM_SetChatPms  0x021736A0  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 */
#include "../include/Obj04183.h"

typedef unsigned char u8;

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
typedef unsigned short u16;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void UNION_MAIN_RequestScene(u8 *p, int a, int b);
extern int UNION_MAIN_IsScenePending(u8 *a);
extern void UNION_COMM_SetChatPms(u8 *a, volatile u16 *s);
extern u32 func_020307B0(void *p);
extern int d_021807E8[];

int UNION_ONESELF_ChatInputMain(u8 *a, int b, int c, u8 *d)
{
    int *p;
    int *q;
    int x, y;
    switch (*d) {
    case 0:
        if (a[0x282E] == 0)
            return 1;
        a[0x282E] = 0;
        GFL_USE_PlaySeDefaultVolume(0x54B);
        p = func_02030734(4, 12, 1, (const char *)d_021807E8, 0x41A);
        *p = (int)GAME_DATA_GetSaveControl((struct Big *)(*(int *)(((struct Obj04183 *)a)->f0 + 8)));
        *(int * *)&((struct Obj04183 *)a)->f3558 = p;
        UNION_MAIN_RequestScene(a, 0x1d, (int)p);
        (*d)++;
        break;
    case 1:
        if (UNION_MAIN_IsScenePending(a) == 0)
            (*d)++;
        break;
    case 2:
        q = *(int * *)&((struct Obj04183 *)a)->f3558;
        x = q[2];
        y = q[1];
        if (y == 0)
            UNION_COMM_SetChatPms(a, (volatile u16 *)x);
        func_020307B0(*(int **)(a + 0x3558));
        *(int **)(a + 0x3558) = 0;
        return 1;
    }
    return 0;
}
