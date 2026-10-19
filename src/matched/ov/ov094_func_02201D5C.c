/*
 * function: BTLV_CLACT_StartScaleTween
 * address:  0x02201D5C
 * packet:   pkt_ov094_02201D5C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CLACT_StartMoveTask  0x02201E04  thumb  ov094
 *   BTLV_CLACT_MoveTaskMainWide  0x02201FF4  thumb  ov094
 *   BTLV_CLACT_MoveTaskEndWide  0x0220203C  thumb  ov094
 *
 * lever: a brace-initialised Vec local compiles to an @N rodata template; three field stores do not.
 */
#include "../include/Obj07895.h"
typedef struct {
    int x, y, z;
} Vec;

extern void BTLV_CLACT_MoveTaskMainWide(void *a, void *b);
extern void BTLV_CLACT_MoveTaskEndWide(void *a);
extern void BTLV_CLACT_StartMoveTask(void *o, int idx, int c, Vec *v, void *d, int s1, int s2, int s3,
                          void (*f1)(void *, void *), void (*f2)(void *));

void BTLV_CLACT_StartScaleTween(char *o, int idx, int c, void *d, int s1, int s2, int s3)
{
    Vec v;

    v.x = 0x1000;
    v.y = 0x1000;
    v.z = 0x1000;

    BTLV_CLACT_StartMoveTask(o, idx, c, &v, d, s1, s2, s3, BTLV_CLACT_MoveTaskMainWide, BTLV_CLACT_MoveTaskEndWide);
    ((struct Obj07895 *)o)->f7C |= 1 << idx;
}
