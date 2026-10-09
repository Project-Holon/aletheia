/*
 * file:     unit_021E7164_p03.c
 * unit:     yes
 * function: func_021E72F4, func_021E7300, func_021E7320, func_021E732C, func_021E737C, func_021E7388, func_021E7414, func_021E7420
 * address:  0x021E72F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2834     0x021F2834  data   ov093  a4
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F27F4     0x021F27F4  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F282C     0x021F282C  data   ov093  a4
 *   func_021E74C8  0x021E74C8  thumb  ov093
 *   d_021F27DC     0x021F27DC  data   ov093  a4
 */
#include "../../matched/include/Obj13541.h"
#include "../../matched/include/Obj07835.h"
#include "../../matched/include/Obj07836.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021E8CF0(int a);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021E74C8(u16 k);
int *func_021E72F4(int *p);
void func_021E7300(int a, int b, int c);
int *func_021E7320(int *p);
void func_021E732C(int a, int b, int c);
int *func_021E737C(int *p);
void func_021E7388(int a, void *b, int c);
int *func_021E7414(int *p);
void func_021E7420(int a, int b, int c);
extern int d_021F2834[];
extern int d_021F27F4[];
extern int d_021F282C[];
extern int d_021F27DC[];



int *func_021E72F4(int *p)
{
    *p = 1;
    return d_021F2834;
}



void func_021E7300(int a, int b, int c)
{
    u8 k;

    if (c == func_021D775C(3)) {
        k = func_021D775C(4);
        func_021D76BC(0x3b, k);
    }
}



int *func_021E7320(int *p)
{
    *p = 1;
    return d_021F282C;
}



void func_021E732C(int a, int b, int c)
{
    u32 i;
    u32 n;
    u8 *p;

    if (c == func_021D775C(3)) {
        n = func_021D775C(5);
        for (i = 0; i < n; i++) {
            p = func_021C88A4((char *)b, 0x14, c);
            ((struct Obj13541 *)p)->f4 = func_021E8CF0(10);
            ((struct Obj13541 *)p)->f6 = func_021D775C(i + 6);
            func_021C88C8((void *)b, p);
        }
    }
}




int *func_021E737C(int *p)
{
    *p = 1;
    return d_021F27F4;
}




void func_021E7388(int a, void *b, int c)
{
    u32 i;
    u32 n;
    u8 *m;

    if (c == func_021D775C(3)) {
        n = func_021D775C(5);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(func_021C7CF4(b, (u8)func_021D775C(i + 6)), 0x10) != 0x36) {
                m = (u8 *)func_021C88A4(b, 0x1f, c);
                m[6] = func_021D775C(i + 6);
                ((struct Obj07835 *)m)->f4 = 0x56;
                func_021C8838(m + 0xc, 2, 0x195);
                func_021C8860((struct S *)(m + 0xc), m[6]);
                func_021C8860((struct S *)(m + 0xc), ((struct Obj07835 *)m)->f4);
                func_021C88C8(b, m);
            }
        }
    }
}


int *func_021E7414(int *p)
{
    *p = 1;
    return d_021F27DC;
}


/*
 * The narrowed scan key is a `u8` local assigned from the call, then passed:
 * the inline cast `(u8)func_021D775C(i + 6)` adds an `adds r1, r0` copy the
 * image does not have.
 */
void func_021E7420(int a, int b, int c)
{
    u16 k;
    u32 i;
    u32 n;
    u8 *p;
    u8 t;

    if (c == func_021D775C(3)) {
        k = func_021D59B4(func_021C7CF4((int *)b, c), 0x10);
        if (func_021E74C8(k) == 0) {
            n = func_021D775C(5);
            for (i = 0; i < n; i++) {
                t = func_021D775C(i + 6);
                if (func_021D59B4(func_021C7CF4((int *)b, t), 0x10) != 0x36) {
                    p = func_021C88A4((char *)b, 0x1f, c);
                    ((struct Obj07836 *)p)->f6 = func_021D775C(i + 6);
                    ((struct Obj07836 *)p)->f4 = k;
                    func_021C8838(p + 0xc, 2, 0x195);
                    func_021C8860((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f6);
                    func_021C8860((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f4);
                    func_021C88C8((void *)b, p);
                }
            }
        }
    }
}
