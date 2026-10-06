/*
 * file:     iss_city_sys_p04.c
 * unit:     yes
 * function: func_0202AC60, func_0202ACBC, func_0202ACC8, func_0202ACCC, func_0202ACFC
 * address:  0x0202AC60
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
 *   func_0202ABFC 0x0202ABFC  thumb
 *   func_0202AC4C 0x0202AC4C  thumb
 *   func_0202ACC8 0x0202ACC8  thumb
 *   func_0202AD8C 0x0202AD8C  thumb
 *   func_0202ADA0 0x0202ADA0  thumb
 *   func_0202ADB4 0x0202ADB4  thumb
 *   func_0202AE60 0x0202AE60  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0202ABF8  0x0202ABF8  thumb
 *   func_0202AD10  0x0202AD10  thumb
 *   func_0202AD44  0x0202AD44  thumb
 */
#include "../../matched/include/Obj16757.h"

struct Rec44;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_0202ACC8(void *obj);
extern int func_0202AD8C(int a0);
extern int func_0202ADA0(int a0, int a1);
extern int func_0202AC4C(int a0);
extern int func_0202ADB4(int a0, int a1);
extern void func_0202AE60(void *obj, u32 value);
extern void func_0202ABFC(void *obj, u32 value);
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_0202ABF8(void *obj);
extern void func_0202AD10(void *obj);
extern void func_0202AD44(void *obj);
void func_0202AC60(u8 *p, u32 a1);
u32 func_0202ACBC(u32 *p);
u32 sub_0202ACC8(void *obj);
void func_0202ACCC(u8 *p);
int func_0202ACFC(int a0);



void func_0202AC60(u8 *p, u32 a1)
{
    if (func_0202ACC8(p) == 0) {
        return;
    }
    if (func_0202AD8C((int)p) == 1) {
        if (func_0202ADA0((int)p, a1) == 1) {
            func_0202AC4C((int)p);
            return;
        }
    }
    func_0202ADB4((int)p, a1);
    if (func_0202AD8C((int)p) == 1) {
        func_0202AE60(p, 0);
        func_0202ABFC(p, 1);
        return;
    }
    func_0202ABFC(p, 2);
}



u32 func_0202ACBC(u32 *p)
{
    return func_02012AC8((const struct Rec44 *)*p);
}



/*
 * A plain word getter at offset 4. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202ACC8.c \
 *       --func sub_0202ACC8 --addr 0x0202ACC8 --cc 1.1p1 --thumb
 */
u32 sub_0202ACC8(void *obj)
{
    return ((struct Obj16757 *)obj)->f4;
}



/*
 * Dispatches on the state word returned by func_0202ABF8 over a three-way
 * state machine.  One `switch` on the call result is what puts the result
 * straight into r0 for all three `cmp`s: a named local would have stored it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ACCC.c \
 *       --func func_0202ACCC --addr 0x0202ACCC --thumb --cc 1.1p1
 */
void func_0202ACCC(u8 *p)
{
    switch (func_0202ABF8(p)) {
    case 0:
        func_0202ACFC((int)p);
        break;
    case 1:
        func_0202AD10(p);
        break;
    case 2:
        func_0202AD44(p);
        break;
    }
}


int func_0202ACFC(int a0){ int t0, t1; t0 = func_0202AE68(a0); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = func_0202AEBC((int)((a0 + 0) + 0)); } else {  return t0; } }
