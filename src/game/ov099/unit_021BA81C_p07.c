/*
 * file:     unit_021BA81C_p07.c
 * unit:     yes
 * function: func_021BB2F0, func_021BB374
 * address:  0x021BB2F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   func_02040AF0  0x02040AF0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BB528  0x021BB528  thumb  ov099
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045334  0x02045334  arm
 *   func_02043598  0x02043598  arm
 *   d_021C37D4     0x021C37D4  data   ov099  a2
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_02025C88  0x02025C88  thumb
 *   func_0202DA04  0x0202DA04  thumb
 *   func_0202DA48  0x0202DA48  thumb
 *   func_0202DA18  0x0202DA18  thumb
 *   func_0202DA6C  0x0202DA6C  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj22020.h"

struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
struct Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u16 v[4];
} T4;

typedef signed int     s32;

extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020414AC(int a);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021BB528(char *p, int v);
extern void func_02041B6C(u32 bit);
extern void func_02045334(struct Descriptor *d);
extern void func_02043598(u32 mask, u32 enable);
extern void func_021BB42C(void *p);
extern u32 func_02025C88(u32 x);
extern int func_0202DA04(int a0);
extern void *func_0202DA48(void *a, int b, int c, u16 d);
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_02049238(void *o);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_021BB2F0(char *p, int v);
void func_021BB374(char *p, int a, int b);
extern const T4 d_021C37D4;


void func_021BB2F0(char *p, int v)
{
    char *q;

    func_02009864(((struct Obj00008 *)p)->f4, ((struct Obj00008 *)p)->f8ED - 1, 9);
    q = *(char * *)&((struct Obj00008 *)p)->f8C0;
    func_02040AF0(6, q + 0xC, (u32)(((struct Obj22020 *)q)->f8), 0);
    func_020414AC(7);
    func_02043B5C(func_02045770(((struct Obj00008 *)p)->f95C), 0);
    func_02043B5C(func_02045770(((struct Obj00008 *)p)->f958), 0);
    func_021BB528(p, v);
    func_02041B6C(7);
    func_02045334(((struct Obj00008 *)p)->f95C);
    func_02045334(((struct Obj00008 *)p)->f958);
    func_02043598(2, 0);
    func_02043598(8, 1);
}


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
