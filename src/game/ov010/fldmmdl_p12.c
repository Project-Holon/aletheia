/*
 * file:     fldmmdl_p12.c
 * unit:     yes
 * function: func_0216D230, func_0216D244, func_0216D268, func_0216D28C
 * address:  0x0216D230
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E400  0x0216E400  thumb  ov010
 *   func_0216DF64 0x0216DF64 thumb ov010
 *   func_0216D568 0x0216D568 thumb ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_02163010  0x02163010  thumb  ov010
 *   func_0219D6B8  0x0219D6B8  thumb
 *   func_02163028   0x02163028  thumb  ov010
 *   func_0219D6CC   0x0219D6CC  thumb
 */
#include "../../matched/include/Obj17772.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u16 func_0216D5A0(void *p);
extern u32 func_0216E400(int i);
extern void func_0216DF64(u8 *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216D55C(int a0, int a1);
extern int func_02163010();
extern int func_0219D6B8();
extern void func_02163028(void *a);
extern void func_0219D6CC(void *);
int func_0216D230(int a0);
void func_0216D244(u32 v, u8 *p);
int func_0216D268(int a0, int a1);
void func_0216D28C(void *a0);


/*
 * blocked:  listing 20 compiled 18
 */
int func_0216D230(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D5A0((void *)a0);
loc_0216D238:
    a0 = func_0216E400(a0);
loc_0216D23C:
t4 = t4 + 0x8c;
((struct Obj17772 *)((char *)t4))->f0 = a0;
    return a0;}

void func_0216D244(u32 v, u8 *p)
{
    func_0216D230((int)p);
    func_0216DF64(p, v);
    func_0216D568(p, 0x1820);
}


int func_0216D268(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
a1 = 2;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = func_0216D55C(a0, a1);
loc_0216D276:
    if (a0 != 0) goto loc_0216D282;
loc_0216D27A:
a0 = t4 + 0;
    a0 = func_02163010(a0);
loc_0216D280:
    return a0;
loc_0216D282:
a0 = t4 + 0;
    a0 = func_0219D6B8(a0);
loc_0216D288:
    return a0;}


/*
 * The mask test picks between the overlay's own handler and the arm9
 * field setter.
 */
void func_0216D28C(void *a0)
{
    if (func_0216D55C((int)a0, 0x2000) == 0) {
        func_02163028((void *)a0);
    } else {
        func_0219D6CC(a0);
    }
}
