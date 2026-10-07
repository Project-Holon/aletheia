/*
 * file:     btlv_effvm_p88.c
 * unit:     yes
 * function: func_022025B4, func_022025D8
 * address:  0x022025B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0202173C  0x0202173C  thumb
 *   func_02030DA8  0x02030DA8  arm
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_02204A3C  0x02204A3C  thumb  ov094
 *   func_02204A70  0x02204A70  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 */
#include "../../matched/include/Obj03718.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 i);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *file, u16 line);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, unsigned int a3);
extern void func_0220684C(char *p, int a, int b);
extern void func_02204A3C(void *a, char **s);
extern void func_02204A70(void *h);
void func_022025B4(void);
void func_022025D8(char *o, int flag);
extern char d_0220AEB0[];


void func_022025B4(void)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_02040588((u8)(i + 4), (int)0);
        func_020403F4((u8)(i + 4));
    }
}


/*
 * lever: the flag test is two whole func_0202173C calls, one per arm, differing only
 *   in the fifth argument (0 / 0xC). The compiler cross-jumps them after the [sp] store,
 *   hoists the shared `ldr r2, =0xFFFF` above the branch and pools the three zeros of the
 *   two calls in r6 before the alloc call. A u8 local set in an if/else (or an enum
 *   zero) gave the same size with flag and the zero in each other's registers
 *   (docs/notes/pkt_ov094_022025D8.c.txt).
 */
void func_022025D8(char *o, int flag)
{
    int *p;

    p = func_02030734((u16)((((struct Obj03718 *)o)->f240 & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x4F7);
    if (flag == 1)
        func_0202173C(((struct Obj03718 *)o)->f64, 0xA, 0xFFFF, 1, 0, 0x10, 0, ((struct Obj03718 *)o)->f0);
    else
        func_0202173C(((struct Obj03718 *)o)->f64, 0xA, 0xFFFF, 1, 0xC, 0x10, 0, ((struct Obj03718 *)o)->f0);
    ((struct Obj03718 *)o)->f68 = (((struct Obj03718 *)o)->f68 & 0xFFFE7FFF) | 0x8000;
    p[0] = (int)o;
    func_0220684C(o, (int)func_02030DA8(((struct Obj03718 *)o)->f0, (void (*)(void *, void *))func_02204A3C, p, 0), (int)func_02204A70);
}
