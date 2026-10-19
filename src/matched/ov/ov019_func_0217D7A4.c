/*
 * function: UNION_ONESELF_ColosseumEnterParentMain
 * address:  0x0217D7A4
 * packet:   pkt_ov019_0217D7A4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   COLOSSEUM_Create  0x02174F4C  thumb  ov012
 *   UNION_MSG_GetColosseumStartMsg  0x0217EC94  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_SCENE_RequestScene  0x0217422C  thumb  ov012
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   gUnionEmptyString1     0x021807E4  data  a4
 */
#include "../include/Obj09412.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj;

extern int UNION_ONESELF_HandleNetError(char *p);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern int COLOSSEUM_Create(int a, int b, int c, int d);
extern u16 UNION_MSG_GetColosseumStartMsg(int i);
typedef unsigned int   u32;
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, u32 b, u32 c);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);
extern void UNION_SCENE_RequestScene(u8 *a, int b, int c);
extern int UNION_SCENE_IsScenePending(u8 *a);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern u8 gUnionEmptyString1[];

int UNION_ONESELF_ColosseumEnterParentMain(u8 *a, Obj *b, u8 *c, u8 *d)
{
    int *p;
    if (*d < 4 && UNION_ONESELF_HandleNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (((struct Obj09412 *)a)->f355C != 0)
            func_02034714((const char *)gUnionEmptyString1, 0, (const char *)gUnionEmptyString1);
        p = *(int * *)&((struct Obj09412 *)a)->f0;
        ((struct Obj09412 *)a)->f355C = COLOSSEUM_Create(p[2], p[3], p[0], b->b1);
        UNION_MSG_SetupPrintTalkMsg(a, c, UNION_MSG_GetColosseumStartMsg(b->f14->b3));
        (*d)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 1)
            (*d)++;
        break;
    case 2:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xb, 0x14);
        (*d)++;
        break;
    case 3:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xb, 0x14) == 1)
            (*d)++;
        break;
    case 4:
        UNION_SCENE_RequestScene(a, b->f2d + 1, 0);
        (*d)++;
        break;
    case 5:
        if (UNION_SCENE_IsScenePending(a) == 0) {
            UNION_ONESELF_SetFieldBusy((char *)a, (int)c, 1);
            UNION_ONESELF_SetNextPlayCategory((char *)a, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}
