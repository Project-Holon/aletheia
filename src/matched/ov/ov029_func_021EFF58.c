/*
 * function: func_021EFF58
 * address:  0x021EFF58
 * packet:   pkt_ov029_021EFF58
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFF58  0x021EFF58  thumb  ov029
 *   func_021F0000  0x021F0000  thumb  ov029
 *   func_021F0D14  0x021F0D14  thumb  ov029
 *   func_0204B878  0x0204B878  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   CLACT_SetActorSurfacePosAxis  0x0204B49C  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj05112.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct Slot {
    void *obj;
    int a;
    int b;
};

struct Pt {
    s16 x;
    s16 y;
    u16 w;
    u8 z;
    u8 t;
};

extern void func_021F0D14(int a, int b, int *x, int *y);
struct Owner;
extern struct Slot *func_021F0000(struct Owner *p);
struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021EFF58(u8 *p, int a, int c)
{
    struct Pt s;
    int x;
    int y;
    struct Slot *sl;

    func_021F0D14(a, c, &x, &y);
    s.x = x * 8 + 16;
    s.y = y * 8 + 16;
    s.w = p[0x414] + 10;
    s.z = 0;
    s.t = 2;
    sl = func_021F0000((struct Owner *)p);
    if (sl->obj != 0) {
        func_0204B878(sl->obj, s.w);
        func_0204B9A0(sl->obj);
        CLACT_SetActorSurfacePosAxis(sl->obj, s.x, 0, 0);
        CLACT_SetActorSurfacePosAxis(sl->obj, s.y, 0, 1);
    } else {
        sl->obj = func_0204B294((void *)((struct Obj05112 *)p)->f34, ((struct Obj05112 *)p)->f2C, ((struct Obj05112 *)p)->f28, ((struct Obj05112 *)p)->f30, &s, 0, ((struct Obj05112 *)p)->fC);
        func_0204B92C(sl->obj, 1);
        func_0204B3DC(sl->obj, 1);
    }
    sl->a = a;
    sl->b = c;
}
