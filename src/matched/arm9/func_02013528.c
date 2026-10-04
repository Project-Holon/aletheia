/*
 * function: func_02013528
 * address:  0x02013528
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020130C4   0x020130C4  thumb
 *   func_0201333C   0x0201333C  thumb
 *   func_02013360   0x02013360  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_0200846C   0x0200846C  thumb
 *   func_0201320C   0x0201320C  thumb
 *
 * btl_setup.c. The eight-argument setup builder (sibling of func_020135C0).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 152/152, 6 bytes out for four
 * waves, docs/notes/pkt_02013528.c.txt): the eighth (stack) parameter is a
 * heap id and is u16, with u16 on the matching parameter of func_0201333C,
 * func_0200846C and func_0201A920 (func_020135C0 already declares the first
 * and last that way). With u32 there, 1.1p1 schedules the r3 home store
 * `str r3, [sp]` after the three parameter copies; with u16 it comes first,
 * as in the image. docs/idioms/a-u16-stack-parameter-passed-to-a-u16-callee-
 * stays-behind-a-spill-store.md is the same lever.
 */
#include "../include/Obj00155.h"
#include "../include/Obj06858.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020130C4(u8 *p);
extern void func_0201320C(u32 *a);
extern void func_02013360(u8 *o, void *a1, const void *a2);
extern void func_0201333C(void *a, void *b, u16 c);
extern void *func_0200846C(int a0);
extern u32  func_0201A920(u16 a);

void func_02013528(u8 *o, void *a1, u32 a2, u8 a3, u32 a4, u8 a5, u8 a6, u16 a7)
{
    u32 sub[4];
    u32 i;

    func_020130C4(o);
    func_0201320C(sub);
    sub[0] = 9;
    sub[1] = 1;
    func_02013360(o, a1, sub);
    func_0201333C(o, a1, a7);
    ((struct Obj00155 *)o)->f0 = 3;
    ((struct Obj00155 *)o)->f4 = a2;
    ((struct Obj00155 *)o)->f1C = a4;
    *(o + 0x20) = a5;
    *(o + 0x22) = a3;
    *(o + 0x21) = a6;
    ((struct Obj00155 *)o)->f84 = 0xff;
    ((struct Obj00155 *)o)->f1A = 0x47d;
    i = 0;
    do {
        if (i != 0) {
            u8 *e = o + i * 4;
            if (((struct Obj06858 *)e)->f34 == 0)
                ((struct Obj06858 *)e)->f34 = (u32)func_0200846C(a7);
            if (((struct Obj06858 *)e)->f24 == 0)
                ((struct Obj06858 *)e)->f24 = func_0201A920(a7);
        }
        i++;
    } while (i < 4);
}
