/*
 * function: UNION_SUBDISP_SetKnobFromScroll
 * address:  0x021F0CEC
 * packet:   pkt_ov031_021F0CEC
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * UNION_SUBDISP_GetKnobStep is filed as a 12-byte tail stub (r0 = 0x8000, r1 kept); the
 * call sites pass (b, n), so it is declared with two arguments here.
 *
 * symbols:
 *   UNION_SUBDISP_SetKnobFromScroll  0x021F0CEC  thumb
 *   UNION_SUBDISP_GetScrollRange  0x021F0D40  thumb  ov031
 *   UNION_SUBDISP_GetKnobStep  0x021F0D58  thumb  ov031
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 */
#include "../include/Obj20409.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    char pad[0x43C];
    int a;
    int n;
} B;

extern int UNION_SUBDISP_GetScrollRange(B *);
extern u32 UNION_SUBDISP_GetKnobStep(void *unused, u32 d);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void UNION_SUBDISP_SetKnobFromScroll(char *o, B *b)
{
    u16 t[2];
    int k;
    int c;

    k = UNION_SUBDISP_GetScrollRange(b);
    c = UNION_SUBDISP_GetKnobStep(b, k);
    if (b->a - b->n > 0x1B)
        b->n = b->a - 0x1B;
    t[1] = 0x9C - ((u32)((b->a - b->n) * c) >> 8);
    t[0] = 0xF4;
    CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj20409 *)o)->f2C), (const struct Vec2 *)t, 1);
}
