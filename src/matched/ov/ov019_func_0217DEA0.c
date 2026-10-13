/*
 * function: UNION_ONESELF_ColosseumFreeMoveMain
 * address:  0x0217DEA0
 * packet:   pkt_ov019_0217DEA0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   UNION_ONESELF_CheckNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   COLOSSEUM_GetStandPosIndex  0x0217FE44  thumb  ov019
 *   COLOSSEUM_SetMyChoice  0x021750B0  thumb  ov012
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   COLOSSEUM_IsAnyFinished  0x0217FEF4  thumb  ov019
 *   COLOSSEUM_IsOnCounterPos  0x0217FF14  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   COMM_PLAYER_ForwardRequest  0x021679A4  thumb  ov010
 */
#include "../include/Obj12527.h"
#include "../include/Obj19419.h"

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern int UNION_ONESELF_CheckNetErrorExit(char *p);
extern void UNION_MSG_CloseAllWindows(void *ctx);
extern int UNION_MSG_GetCategoryTableValue(int i);
extern int COLOSSEUM_GetStandPosIndex(int a, int mode, unsigned *out);
extern void COLOSSEUM_SetMyChoice(u8 *p, int v);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
extern int COLOSSEUM_IsAnyFinished(u8 *p);
extern int COLOSSEUM_IsOnCounterPos(void *a);
extern u32 func_020362DC(void);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern int COMM_PLAYER_ForwardRequest(void *a0, int a1, int a2, int a3, int a4, int a5);

int UNION_ONESELF_ColosseumFreeMoveMain(void *ctx, Obj *obj, int a2, u8 *state)
{
    u8 *w = *(u8 * *)&((struct Obj19419 *)ctx)->f355C;
    void *a;
    int m;
    unsigned out;
    int k;
    s16 v[3];

    a = FIELDMAP_GetFieldPlayer((void *)a2);
    if (UNION_ONESELF_CheckNetErrorExit(ctx) == 1) {
        UNION_MSG_CloseAllWindows(ctx);
        return 1;
    }

    if (*state == 0) {
        if (COLOSSEUM_GetStandPosIndex(a2, UNION_MSG_GetCategoryTableValue(obj->f2d), &out) == 1) {
            COLOSSEUM_SetMyChoice(w, out);
            UNION_ONESELF_SetNextPlayCategory(ctx, 0x2b);
            UNION_ONESELF_SetFieldBusy(ctx, a2, 1);
            return 1;
        }
        if (COLOSSEUM_IsAnyFinished(w) == 1) {
            UNION_ONESELF_SetNextPlayCategory(ctx, 0x32);
            UNION_ONESELF_SetFieldBusy(ctx, a2, 1);
            return 1;
        }
        if (COLOSSEUM_IsOnCounterPos((void *)a2) == 1) {
            UNION_ONESELF_SetNextPlayCategory(ctx, 0x31);
            UNION_ONESELF_SetFieldBusy(ctx, a2, 1);
            return 1;
        }
        if (func_020362DC() & 1) {
            k = 0;
            FIELD_PLAYER_GetFrontGridPos((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
            if (COMM_PLAYER_ForwardRequest((void *)(((struct Obj12527 *)w)->f0), v[2], v[1], v[0], (int)(&m), (int)(&k)) == 1) {
                w[0x16c] = m;
                UNION_ONESELF_SetNextPlayCategory(ctx, 0x33);
                UNION_ONESELF_SetFieldBusy(ctx, a2, 1);
                return 1;
            }
        }
    }
    return 0;
}
