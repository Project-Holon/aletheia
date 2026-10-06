/*
 * function: func_021BB374
 * address:  0x021BB374
 * packet:   pkt_ov099_021BB374
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C37D4     0x021C37D4  data   ov099  a2
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_02009864  0x02009864  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_0202DA04  0x0202DA04  thumb
 *   func_0202DA48  0x0202DA48  thumb
 *   func_0202DA18  0x0202DA18  thumb
 *   func_0202DA6C  0x0202DA6C  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 */
#include "../include/Obj00008.h"

typedef unsigned short u16;

typedef struct {
    u16 v[4];
} T4;

extern const T4 d_021C37D4;
extern void func_021BB42C(void *p);
typedef unsigned int   u32;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern u32 func_02025C88(u32 x);
extern int func_0202DA04(int a0);
extern void *func_0202DA48(void *a, int b, int c, u16 d);
typedef signed int     s32;
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_02049238(void *o);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

void func_021BB374(char *p, int a, int b)
{
    T4 t;
    int r;
    void *o;

    t = d_021C37D4;
    if (((struct Obj00008 *)p)->f180 != 0)
        func_021BB42C(p);
    r = func_02009864(((struct Obj00008 *)p)->f4, a, 8);
    r = func_02025C88(r);
    o = (void *)func_0202DA04((u16)b);
    ((struct Obj00008 *)p)->f184 = func_0202DA48(o, r, 1, b);
    ((struct Obj00008 *)p)->f188 = (void *)func_0202DA18((u32)o, r, 1, 0, b);
    ((struct Obj00008 *)p)->f18C = (void *)func_0202DA6C(r, 2, 1, b);
    func_02049238(o);
    ((struct Obj00008 *)p)->f180 = func_0204B294(((struct Obj00008 *)p)->f110, (unsigned int)((struct Obj00008 *)p)->f184, (unsigned int)((struct Obj00008 *)p)->f188, (unsigned int)((struct Obj00008 *)p)->f18C, &t, 1, b);
}
