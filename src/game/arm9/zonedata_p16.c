/*
 * file:     zonedata_p16.c
 * unit:     yes
 * function: func_020145FC, func_02014628
 * address:  0x020145FC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */
#include "../../matched/include/Obj08750.h"

struct Evt;
typedef unsigned int u32;

typedef unsigned char  u8;

extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
int func_020145FC(int a0);
u32 func_02014628(void *obj, u32 *mode, u32 *p);


int func_020145FC(int a0){ int t0, t1, t2; t0 = func_020122C0((int)a0, (int)0, (int)0x2014585, (int)0x10); t1 = func_020124E8((int)t0); ((struct Obj08750 *)((char *)((t1 + 0))))->f0 = (int)(a0 + 0); ((struct Obj08750 *)((char *)((t1 + 0))))->f4 = (int)0; t2 = func_020120F4((int)((a0 + 0) + 0)); ((struct Obj08750 *)((char *)((t1 + 0))))->f8 = (int)t2; return ((t0 + 0) + 0); }


/*
 * The shared tail of the three working cases sits INSIDE case 0's arm (a
 * label a later arm jumps back to is what makes 0x02014658 fall out of case 0
 * with no branch) and the default arm's `return 0` is reached by a `goto`
 * rather than copied, which is what puts the single `movs r0, #0` epilogue at
 * 0x02014692.  `u32 a0 = p[0];` before the switch is load-bearing: without it
 * each arm reloads p[0] and the whole dispatch shifts.
 */
u32 func_02014628(void *obj, u32 *mode, u32 *p)
{
    u32 a0 = p[0];
    void *r;

    switch (*mode) {
    case 0:
        r = (void *)func_021BE8D4((void *)a0, p[1], 0, 0);
    tail:
        func_02012374(obj, r);
        (*mode)++;
        goto ret0;
    case 1:
        r = (void *)func_02014728((char *)a0, p[1], p[2], p[3], p[4]);
        goto tail;
    case 2:
        r = (void *)func_021BE92C((void *)a0, p[1], 0, 0, 1, 0, 0);
        goto tail;
    case 3:
        return 1;
    default:
    ret0:
        return 0;
    }
}
