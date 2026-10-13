/*
 * file:     unit_021E74E4.c
 * unit:     yes
 * function: func_021E74E4, func_021E7554, func_021E75D4
 * address:  0x021E74E4
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
 *   d_021F277C     0x021F277C  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F279C     0x021F279C  data   ov093  a4
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_GetItem   0x021D5B40  thumb ov093
 *   PALANM_IsColorCodeKnown   0x020213C0  thumb
 */
#include "../../matched/include/Obj12159.h"

struct S;
struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void *func_021C7CF4(int *p, int i);
u16 BTL_POKEPARAM_GetItem(struct QI *p);
int PALANM_IsColorCodeKnown(u32 a);
void func_021E74E4(int a, int b, int c);
int *func_021E7548(int *p);
void func_021E7554(void *a, int b, int c);
extern int d_021F279C[];


void func_021E74E4(int a, int b, int c)
{
    u8 k;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x46) == 0) {
            k = BTL_EVENT_GetVar(4);
            p = func_021C88A4((char *)b, 0x10, c);
            p[4] = 1;
            p[5] = k;
            func_021C88C8((void *)b, p);
            p = func_021C88A4((char *)b, 4, c);
            func_021C8838(p + 4, 2, 0xc3);
            func_021C8860((struct S *)(p + 4), k);
            func_021C88C8((void *)b, p);
        }
    }
}


int *func_021E7548(int *p)
{
    *p = 1;
    return d_021F279C;
}


/*
 * Gate on BTL_EVENT_GetVar(3) and on BTL_EVENT_GetVar(0x46) being zero, then the
 * (u8) of BTL_EVENT_GetVar(4) keys func_021C7CF4 and the (u16) of
 * BTL_POKEPARAM_GetItem is the value PALANM_IsColorCodeKnown must accept.  Both truncations
 * are materialised in the image, so both callees are declared int.
 */
void func_021E7554(void *a, int b, int c)
{
    u8 k;
    u16 v;
    u8 *p;

    if (c != BTL_EVENT_GetVar(3))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    k = (u8)BTL_EVENT_GetVar(4);
    v = (u16)(int)BTL_POKEPARAM_GetItem(func_021C7CF4((int *)b, k));
    if (PALANM_IsColorCodeKnown(v) == 0)
        return;
    p = func_021C88A4((char *)b, 0x20, c);
    ((struct Obj12159 *)p)->f6 = k;
    ((struct Obj12159 *)p)->f4 = 0;
    func_021C8838(p + 0xc, 2, 0x454);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C8860((struct S *)(p + 0xc), v);
    func_021C88C8((void *)b, p);
}


extern int d_021F277C[];
int *func_021E75D4(int *p);

int *func_021E75D4(int *p)
{
    *p = 1;
    return d_021F277C;
}
