/*
 * file:     field_msgbg_p61.c
 * unit:     yes
 * function: func_0219097C, func_02190988, func_021909BC, func_021909E4
 * address:  0x0219097C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02190960  0x02190960  thumb  ov021
 *   func_02020D10  0x02020D10  thumb  arm9
 *   func_02190860  0x02190860  thumb  ov021
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_020200CC  0x020200CC  thumb  arm9
 *   func_0219049C  0x0219049C  thumb  ov021
 */
#include "../../matched/include/Obj07209.h"

struct Handle;
struct Obj;
struct Slot;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_0219097C;

typedef signed char    s8;

typedef short          s16_02190988;

typedef struct Handle {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

typedef signed short   s16_021909BC;

typedef short          s16_021909E4;

typedef signed int     s32;

extern struct Handle *func_02190960(u16 *a, const u8 *b, u32 c, u16 d, u16 e);
extern Handle *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i);
extern void func_02020D10(u8 *p, u32 v);
extern u32 func_0201F868(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_020307B0(void *p);
extern void func_02190538(struct Slot *s);
extern int func_02193130(struct Descriptor *a);
extern int func_0219049C(u8 *p);
extern s32 func_020200CC(struct Obj *o);
u32 func_0219097C(u32 a, const void *b, u32 c);
Handle *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
int func_021909BC(void *a);
int func_021909E4(Handle *h);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219097C(u32 a, const void *b, u32 c)
{
return (int)func_02190960((u16 *)a, (const u8 *)b, c, 0, 0);
}


/*
 * Addresses are Black-image addresses.
 */
Handle *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w)
{
    Handle *r = func_02190860(a, b, c, y, z, a[3], d, 0, x);
    if (w == 0)
        func_02020D10((u8 *)r->obj, 1);
    return r;
}


int func_021909BC(void *a)
{
func_0202020C((struct Obj *)(((struct Obj07209 *)((u8 *)(a)))->f10), 0, 0);
func_0201F868((void *)(((struct Obj07209 *)((u8 *)(a)))->fC));
func_02193130((struct Descriptor *)(((struct Obj07209 *)((u8 *)(a)))->f8));
func_02190538((struct Slot *)(((struct Obj07209 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}


int func_021909E4(Handle *h)
{
    int v;

    if (func_0219049C((u8 *)h->owner) == 0)
        return -1;
    v = func_020200CC((struct Obj *)h->obj);
    if (v == -1)
        return -1;
    if (v == -2)
        return -2;
    return v;
}
