/*
 * function: TOWNMAP_BackButtonUpdate
 * address:  0x021B9F50
 * packet:   pkt_ov072_021B9F50
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the unlabelled follower at 0x021BA028 (push {r4,lr}; getter
 * over func_021B6448) is outside the handed 216-byte extent.
 * Lever: each sprite-animation pick written as if/else of two calls
 * (tail-merged, h load hoisted over the bne), and CLACT_SetActorAnimSeq's second
 * parameter int here (no truncation before the blx).
 *
 * symbols:
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   TOWNMAP_IsScrollZooming  0x021BB0E0  thumb  ov072
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 */
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 x, y;
} Pt;

typedef unsigned char  u8;
struct Actor;
struct Obj;
struct S;
extern void TOUCHBAR_Update(struct S *p);
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int TOWNMAP_IsScrollZooming(void *p);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_StartActorAnim(struct Actor *a);

void TOWNMAP_BackButtonUpdate(u32 *p, void *q)
{
    u32 x;
    u32 y;
    Pt pt;
    int hit;

    TOUCHBAR_Update((void *)p[3]);
    p[6] = -1;
    switch (p[7]) {
    case 0:
        hit = 0;
        CLACT_GetActorSurfacePos((void *)p[5], (struct PtS *)&pt, 0);
        if (func_02035D20(&x, &y)) {
            if (x - pt.x <= 0x18 && y - pt.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        } else if (func_020362DC() & 4) {
            func_020355D8(hit);
            hit = 1;
        }
        if (hit && CLACT_IsActorAnimActive((void *)p[5]) == 0 && TOWNMAP_IsScrollZooming(q) == 0) {
            if (CLACT_GetActorAnimSeq((void *)p[5]) == 7)
                CLACT_SetActorAnimSeq((void *)p[5], 9);
            else
                CLACT_SetActorAnimSeq((void *)p[5], 10);
            CLACT_StartActorAnim((void *)p[5]);
            p[6] = 7;
            p[7] = 1;
        }
        break;
    case 1:
        if (CLACT_IsActorAnimActive((void *)p[5]) == 0) {
            if (CLACT_GetActorAnimSeq((void *)p[5]) == 9)
                CLACT_SetActorAnimSeq((void *)p[5], 8);
            else
                CLACT_SetActorAnimSeq((void *)p[5], 7);
            p[7] = 0;
        }
        break;
    }
}
