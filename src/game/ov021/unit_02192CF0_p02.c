/*
 * file:     unit_02192CF0_p02.c
 * unit:     yes
 * function: func_02193044, func_02193060, func_02193068, func_021930C0, func_02193130, func_02193144, func_02193170, func_0219319C
 * address:  0x02193044
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
 *   func_0207D63C  0x0207D63C  arm  arm9
 *   func_02040DA8  0x02040DA8  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02192FA4  0x02192FA4  thumb  ov021
 *   func_02195588  0x02195588  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_0201F548  0x0201F548  thumb  arm9
 *   func_02049B90  0x02049B90  arm  arm9
 */
#include "../../matched/include/Obj04209.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02193044;

typedef signed short   s16_02193130;

typedef signed char    s8;

typedef short          s16_02193144;

typedef short          s16_02193170;

typedef short          s16_0219319C;

extern void func_0207D63C(void *reg, u32 a, u32 b, u32 c, u32 d);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02192FA4(int, int);
extern void func_02195588(u8 *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_02193044(u32 v);
void func_02193060(u32 a);
void func_02193068(char *p);
int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
int func_02193130(struct Descriptor *a);
void func_02193144(u32 heap);
void func_02193170(u32 heap);
int func_0219319C(u8 *p, u32 v);


/*
 * Addresses are Black-image addresses.
 */
void func_02193044(u32 v)
{
    if (v == 1)
        func_0207D63C((void *)0x04000050, 4, 0x1B, 0x10, 4);
}


/*
 * Tail-call thunk: forwards to func_02193044 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02193060(u32 a)
{
    func_02193044(a);
}


void func_02193068(char *p)
{
    func_02040DA8(((struct Obj04209 *)p)->f2, 1, 0);
    func_02040C14(((struct Obj04209 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj04209 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj04209 *)p)->f2 & 0xff);
    func_02192FA4(((struct Obj04209 *)p)->f2, ((struct Obj04209 *)p)->f0);
    func_02195588((u8 *)(((struct Obj04209 *)p)->f15C));
}


int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f)
{
    int r;
    int k;

    r = func_020450F0(a & 0xff, b & 0xff, c & 0xff, d & 0xff, e & 0xff, f & 0xff, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)r)), 0xff);
    func_02045374((struct Cfg *)r);
    func_02045334((struct Descriptor *)r);
    func_020409B4((u8)a);
    k = 0xd;
    if (f != 0xe) {
        k = 0xa;
    }
    func_0201F73C((void *)r, 0, 1, k & 0xff);
    return r;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02193130(struct Descriptor *a)
{
func_0201F7A8((void *)a, 0);
return func_020452E8(a);
}


void func_02193144(u32 heap)
{
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1A0, 0x20, heap);
}


void func_02193170(u32 heap)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0x140, 0x20, heap);
}


int func_0219319C(u8 *p, u32 v)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((u32 *)(p + 0xA0))[i] == 0) {
            ((u32 *)(p + 0xA0))[i] = v;
            return i;
        }
    }
    return i;
}
