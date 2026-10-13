/*
 * function: ov208_func_021C0A8C
 * address:  0x021C0A8C
 * packet:   pkt_ov208_021C0A8C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 */
#include "../include/Obj06683.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

extern void *ov208_func_021BC3B4(int key);
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(u32 obj, u32 anim);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
extern void ov208_func_021BDC48(void *s, u32 on);

#define OBJ(i) (((u32 *)(p + 0xbc))[i])

void ov208_func_021C0A8C(u16 *heap, u8 *p, int key)
{
    void *scene;
    u8 sel;
    u32 anim;
    u32 next;
    u32 nextAnim;

    scene = ov208_func_021BC3B4(key);
    sel = p[0xd8];
    if (sel == 2) {
        anim = 2;
        next = 1;
        nextAnim = 4;
    } else if (sel == 1) {
        anim = 4;
        next = 2;
        nextAnim = 2;
    }
    if (sel != 7 && CLACT_IsActorAnimActive((struct Actor *)OBJ(sel)) == 0) {
        CLACT_SetActorAnimSeq(OBJ(p[0xd8]), anim);
        CLACT_SetActorAutoAnim((struct Obj *)OBJ(next), 1);
        CLACT_SetActorAnimSeq(OBJ(next), nextAnim);
        p[0xd8] = 7;
        if (((struct Obj06683 *)p)->f6C == 0 || ((struct Obj06683 *)p)->f6C == 5)
            ov208_func_021BDC48(scene, 1);
    }
}
