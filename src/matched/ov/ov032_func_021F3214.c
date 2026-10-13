/*
 * function: func_021F3214
 * address:  0x021F3214
 * packet:   pkt_ov032_021F3214
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorVisible 0x0204BA20 arm
 */
#include "../include/Obj13068.h"

typedef struct {
    short x;
    short y;
    unsigned short w;
    unsigned char z;
    unsigned char h;
} Rect;

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);

void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z)
{
    Rect r;
    void *res;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    r.z = z;
    res = CLACT_CreateActor((void *)((struct Obj13068 *)p)->f128, a, b, c, &r, 0, ((struct Obj13068 *)p)->f94);
    CLACT_SetActorAutoAnim(res, 1);
    CLACT_SetActorVisible(res, 0);
    return res;
}
