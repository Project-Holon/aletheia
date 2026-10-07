/*
 * file:     unit_021BB954_p03.c
 * unit:     yes
 * function: func_021BBD0C, func_021BBD80, func_021BBDD0
 * address:  0x021BBD0C
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
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_021BBC34  0x021BBC34  thumb  ov099
 *   func_021BBE50  0x021BBE50  thumb  ov099
 *   func_02049238  0x02049238  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../../matched/include/Obj03731.h"
#include "../../matched/include/Obj09193.h"

struct Obj;
typedef unsigned short u16;

typedef signed int     s32_021BBD0C;

typedef unsigned int   u32_021BBD0C;

typedef unsigned char  u8;

typedef unsigned long  u32_021BBD80;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BBD80;

typedef int BOOL;

typedef unsigned long  u32_021BBDD0;

typedef signed long    s32_021BBDD0;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32_021BBD0C a1, u32_021BBD0C a2, u32_021BBD0C a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern s32_021BBD0C func_0204AF28(void *owner, u32_021BBD0C first, u32_021BBD0C second, u32_021BBD0C mode);
extern void func_021BBC34(char *p, void *a, int k, u32_021BBD0C o);
extern void func_021BBE50(void *p);
extern void func_02049238(void *o);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32_021BBD80 i);
extern void func_0204ADA4(u32_021BBD80 i);
extern void func_0204AFD8(u32_021BBD80 i);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_021BBD0C(char *p, int a, int b);
void func_021BBD80(char *s);
void func_021BBDD0(void *pv, int flag);


void func_021BBD0C(char *p, int a, int b)
{
    void *o;
    int t;

    o = func_020490F4(7, 0x21);
    ((struct Obj03731 *)p)->f148 = (void *)func_0204ACEC(o, func_0201BC3C(), 0, 0x160, 0x21);
    t = func_0201BC78();
    ((struct Obj03731 *)p)->f14C = (void *)func_0204AF28(o, t, func_0201BCB4(), 0x21);
    func_021BBC34(p, (void *)a, 0, (u32_021BBD0C)o);
    func_021BBC34(p, (void *)b, 6, (u32_021BBD0C)o);
    func_021BBE50(p);
    func_02049238(o);
}


void func_021BBD80(char *s)
{
    int i;

    if (((struct Obj09193 *)s)->f150 != 0) {
        for (i = 0; i < 12; i++) {
            if (*(void **)(s + i * 4 + 0x150) != 0) {
                func_0204B3B4(*(void **)(s + i * 4 + 0x150));
                func_0204A8D4((u32_021BBD80)(*(void **)(s + i * 4 + 0x118)));
            }
            *(u32_021BBD80 *)(s + i * 4 + 0x150) = 0;
        }
        func_0204ADA4((u32_021BBD80)(((struct Obj09193 *)s)->f148));
        func_0204AFD8((u32_021BBD80)(((struct Obj09193 *)s)->f14C));
    }
}


/*
 * Walks the twelve pointers at +0x150 in two halves of six: the first half is
 * handed pair (callee, then join call) with flag ? 1 : 0, the second half with
 * flag ? 0 : 1, each half skipping empty slots.
 *
 * Two rules of this overlay are load-bearing here.  First the duplicated call
 * per arm: the image has two call sites for each of the two calls, each with
 * its own literal, and 1.1p1 does not merge them because the arms are written
 * out.  A computed selector (`int k = flag ? 1 : 0;` passed to one call site)
 * compiles to 116 bytes against the image's 128, with the selector parked in a
 * callee-saved register.  Second the walked address is index-first
 * (`s + i * 4 + 0x150`) so that the scaled index is computed once into r5 (r4
 * in the second half) and the field constant stays in a register.
 *
 * The two halves share one counter: re-initialising the same variable
 * (`for (i = 6; i < 12; i++)`) is the image's shape - a second counter
 * variable costs 8 bytes and swaps r4/r5.
 */
void func_021BBDD0(void *pv, int flag)
{
    char *s = (char *)pv;
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x150) != 0) {
            if (flag != 0) {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 1);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 1);
            } else {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 0);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 0);
            }
        }
    }

    for (i = 6; i < 12; i++) {
        if (*(void **)(s + i * 4 + 0x150) != 0) {
            if (flag != 0) {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 0);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 0);
            } else {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 1);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 1);
            }
        }
    }
}
