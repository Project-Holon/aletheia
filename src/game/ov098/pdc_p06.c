/*
 * file:     pdc_p06.c
 * unit:     yes
 * function: func_021B6B8C, func_021B6C34, func_021B6C60, func_021B6C90
 * address:  0x021B6B8C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02040588  0x02040588  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045334  0x02045334  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201CE0C  0x0201CE0C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0207D63C  0x0207D63C  arm
 */
#include "../../matched/include/Obj07937.h"
#include "../../matched/include/Obj04409.h"
#include "../../matched/include/Obj03220.h"

struct Descriptor;
struct CharBuf;
struct Cfg;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02045374(struct Cfg *);
extern void func_020409B4(u32);
extern void func_02045334(struct Descriptor *);
extern void func_0201DD78(u32, u32, u32);
extern void *func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201CE0C(void *);
extern void func_0201C7A4(void *, short, short, void *, void *);
extern void func_0207D63C(int, int, int, int, int);
void func_021B6B8C(char *a, int b);
void func_021B6C34(char *p, int a);
void func_021B6C60(char *p);
void func_021B6C90(char *p, int flag);


void func_021B6B8C(char *a, int b)
{
    func_02043B5C(func_02045770(*(struct Descriptor **)(a + 0x1c)), 0xc);
    func_0201DD78(1, 9, 0xc);
    func_02040588(1, 1);
    if (b != 0) {
        func_0201CE0C(*(void **)a = func_0201CCE4(*(u32 *)(a + 0x1c), 0, 0,
                                  *(int *)(a + 0x2c), *(int *)(a + 0x24),
                                  *(int *)(a + 0x34), *(int *)(a + 0x28), 0,
                                  *(u16 *)(a + 0x44), 0xc));
        *(char *)(a + 0x38) = 0;
    } else {
        func_0201C7A4(func_02045770(*(struct Descriptor **)(a + 0x1c)), 0, 0,
                      *(void **)(a + 0x2c), *(void **)(a + 0x24));
        func_02045374(*(struct Cfg **)(a + 0x1c));
        func_020409B4(1);
        func_02045334(*(struct Descriptor **)(a + 0x1c));
        *(char *)(a + 0x38) = 1;
    }
    *(char *)(a + 0x39) = 0;
    *(u16 *)(a + 0x40) = b;
    *(u16 *)(a + 0x42) = b;
    *(char *)(a + 0x3a) = 0;
}


void func_021B6C34(char *p, int a)
{
    ((struct Obj07937 *)p)->f0 = a;
    ((struct Obj07937 *)p)->f14 = 0;
    ((struct Obj07937 *)p)->f4 = 0x1f000;
    ((struct Obj07937 *)p)->f8 = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}


/*
 * Unlabelled leaf inside the handed extent of func_021B6C34.
 */
void func_021B6C60(char *p)
{
    u8 s = ((struct Obj04409 *)p)->f14;

    if (s == 0 || s == 3) {
        ((struct Obj04409 *)p)->f4 = 0x1f000;
        ((struct Obj04409 *)p)->f8 = 0x7000;
        ((struct Obj04409 *)p)->fC = -0x52aa;
        ((struct Obj04409 *)p)->f10 = 0x1800;
        ((struct Obj04409 *)p)->f15 = 6;
        ((struct Obj04409 *)p)->f14 = 1;
    }
}


void func_021B6C90(char *p, int flag)
{
    if ((u8)(((struct Obj03220 *)p)->f14 + 0xff) <= 1) {
        if (flag == 0) {
            func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03220 *)p)->f0)), 0xc);
            func_02045334((struct Descriptor *)((struct Obj03220 *)p)->f0);
        }
        ((struct Obj03220 *)p)->f4 = 0;
        ((struct Obj03220 *)p)->f8 = 0x10000;
        ((struct Obj03220 *)p)->fC = 0x52AA;
        ((struct Obj03220 *)p)->f10 = -0x1800;
        ((struct Obj03220 *)p)->f15 = 6;
        ((struct Obj03220 *)p)->f14 = 4;
    }
}
