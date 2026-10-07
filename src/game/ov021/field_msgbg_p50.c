/*
 * file:     field_msgbg_p50.c
 * unit:     yes
 * function: func_021901E8, func_021901EC, func_02190270, func_0219027C, func_021902A4, func_021902AC, func_021902BC
 * address:  0x021901E8
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
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_021931F4  0x021931F4  thumb
 *   d_021DDA50  0x021DDA50  data  ov021  a4
 *   func_02192BD0  0x02192BD0  thumb
 *   func_02192CF0  0x02192CF0  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02192EB8  0x02192EB8  thumb
 *   func_02192FA4  0x02192FA4  thumb
 *   func_02192FEC  0x02192FEC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02194798  0x02194798  thumb  ov021
 *   func_02031140  0x02031140  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 */
#include "../../matched/include/Obj17920.h"
#include "../../matched/include/Obj01849.h"
#include "../../matched/include/Obj12600.h"

struct GfFont;
struct NitroFileHeader;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef struct Obj {
    u16  f00;
    u16  f02;
    u16  f04;
    u16  f06;
    u32  f08;
    u32  f0c;
    Slot slot[4];
} Obj;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_021931F4(u32 a);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_02192BD0(char *p, int flag);
extern void func_02192CF0(char *p, int flag);
extern void *func_020056A0(void (*fn)(void *, void *), void *arg, u32 pri);
extern void func_02192EB8(u32 a, u8 *b);
extern void func_02192FA4(int a, int b);
extern void func_02192FEC(int a, int b, int c);
extern u32 func_020307B0(void *p);
extern void func_02194798(unsigned char *a);
extern void func_02031140(struct S02031140 *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 i);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
u32 func_021901E8(u8 *p);
u8 *func_021901EC(u16 heap, u32 b);
void func_02190270(u32 a);
void func_0219027C(u8 *a);
void func_021902A4(u32 a0, u32 a1);
void func_021902AC(u16 *p, int v);
void func_021902BC(Obj *o);
extern const char d_021DDA50[];


/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021901E8(u8 *p)
{
    return ((struct Obj17920 *)p)->f8;
}


u8 *func_021901EC(u16 heap, u32 b)
{
    u8 *o = func_02030734(heap, 0x17c, 1, d_021DDA50, 0x1a4);
    ((struct Obj01849 *)o)->f0 = heap;
    ((struct Obj01849 *)o)->f2 = 0xff;
    ((struct Obj01849 *)o)->f4 = 0xff;
    ((struct Obj01849 *)o)->f168 = b;
    ((struct Obj01849 *)o)->f8 = (u32)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj01849 *)o)->f0);
    ((struct Obj01849 *)o)->fC = func_0201C440((void *)(((struct Obj01849 *)o)->f0));
    ((struct Obj01849 *)o)->f164 = (u32)func_0203101C(((struct Obj01849 *)o)->f0, ((struct Obj01849 *)o)->f0, 1, 4);
    func_021931F4((u32)(o + 0x160));
    ((struct Obj01849 *)o)->f174 = func_0204A1BC(5, 0xc, 0, heap);
    func_02062A4C((struct NitroFileHeader *)(((struct Obj01849 *)o)->f174), (void **)(o + 0x178));
    return o;
}


/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_02190270(u32 a)
{
    func_02192BD0((char *)a, 1);
}


void func_0219027C(u8 *a)
{
    func_02192CF0((char *)a, 0);
    if (((struct Obj12600 *)a)->f16C == 0)
        ((struct Obj12600 *)a)->f16C = func_020056A0((void (*)(void *, void *))func_02192EB8, a, 0);
}


/*
 * Tail-call thunk: forwards to func_02192FA4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021902A4(u32 a0, u32 a1)
{
    func_02192FA4(a0, a1);
}


/*
 * Unlabelled tail-call forwarder, called from func_021BEF8C.
 */
void func_021902AC(u16 *p, int v)
{
    func_02192FEC(p[1], p[0], v);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021902BC(Obj *o)
{
    int i;
    Slot *s;

    i = 0;
    s = o->slot;

    if (((u32 *)o)[0x5d] != 0) {
        func_020307B0((void *)((u32 *)o)[0x5d]);
    }
    if (((u32 *)o)[0x57] != 0) {
        func_02194798((unsigned char *)(((u32 *)o)[0x57]));
    }
    if (((u32 *)o)[0x59] != 0) {
        func_02031140((struct S02031140 *)(((u32 *)o)[0x59]));
    }
    if (o->f02 != 0xff) {
        func_02040DA8(o->f02, 1, 0);
        func_020403F4((u8)o->f02);
    }
    if (o->f04 != 0xff) {
        func_020403F4((u8)o->f04);
    }
    do {
        if (s->f18 != 0) {
            func_02045808((struct U16Vec *)s->f18);
        }
        i++;
        s++;
    } while (i < 4);
    if (o->f0c != 0) {
        func_0201C4C0((struct PrintSys *)o->f0c);
    }
    if (o->f08 != 0) {
        func_0201D83C((void *)o->f08);
    }
    func_020307B0(o);
}
