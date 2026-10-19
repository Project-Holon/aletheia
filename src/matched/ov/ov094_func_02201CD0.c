/*
 * function: BTLV_CLACT_StartPosTween
 * address:  0x02201CD0
 * packet:   pkt_ov094_02201CD0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   BTLV_CLACT_StartMoveTask  0x02201E04  thumb  ov094
 *   BTLV_CLACT_MoveTaskMain  0x02201F98  thumb  ov094
 *   BTLV_CLACT_MoveTaskEnd  0x02201FD8  thumb  ov094
 */
#include "../include/Obj07895.h"
typedef short s16;

typedef struct {
    int x, y, z;
} Vec;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void BTLV_CLACT_MoveTaskMain(void *a, void *b);
extern void BTLV_CLACT_MoveTaskEnd(void *a);
extern void BTLV_CLACT_StartMoveTask(void *o, int idx, int c, Vec *v, Vec *w, int s1, int s2, int s3,
                          void (*f1)(void *, void *), void (*f2)(void *));

void BTLV_CLACT_StartPosTween(char *o, int idx, int c, s16 *p, int s1, int s2, int s3)
{
    Vec b;
    Vec a;
    s16 t[2];

    a.x = p[0] << 12;
    a.y = p[1] << 12;
    a.z = 0;
    CLACT_GetActorSurfacePos(*(void **)(o + idx * 16 + 8), (struct PtS *)t, 0);
    b.x = t[0] << 12;
    b.y = t[1] << 12;
    b.z = 0;
    if (c == 1) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    }
    BTLV_CLACT_StartMoveTask(o, idx, c, &b, &a, s1, s2, s3, BTLV_CLACT_MoveTaskMain, BTLV_CLACT_MoveTaskEnd);
    ((struct Obj07895 *)o)->f78 |= 1 << idx;
}
