/*
 * file:     fldeff_namipoke_p02.c
 * unit:     yes
 * function: func_021AC9D8, func_021ACA38
 * address:  0x021AC9D8
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
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   d_021D90C0     0x021D90C0  data
 *   d_021DE080  0x021DE080  data
 *   func_021ACA70  0x021ACA70  thumb  ov021
 */
#include "../../matched/include/Obj05039.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; u32 f8; } P;

extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u16 func_0216D608(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ACA70(u32 *a);
int func_021AC9D8(u8 *p);
P *func_021ACA38(u32 a, int heap);
extern u8 d_021D90C0[];
extern char d_021DE080[];


/*
 * Addresses are Black-image addresses.
 */
int func_021AC9D8(u8 *p)
{
    u32 a = ((struct Obj05039 *)p)->f8;
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 f = d_021D90C0[((struct Obj05039 *)p)->f24];
    if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
        goto yes;
    if (f == 0 && func_0216D608((void *)a) == 0) {
        x = func_0216D804((void *)a);
        y = func_0216D81C((void *)a);
        if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
            return 1;
    }
    return 0;
yes:
    return 1;
}


P *func_021ACA38(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0xc, 1, d_021DE080, 0xac);
    p->f0 = a;
    func_021ACA70((u32 *)p);
    return p;
}
