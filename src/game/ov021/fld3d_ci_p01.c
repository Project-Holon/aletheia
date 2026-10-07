/*
 * file:     fld3d_ci_p01.c
 * unit:     yes
 * function: func_021C1988, func_021C19B4, func_021C1A08, func_021C1A48
 * address:  0x021C1988
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
 *   func_021C16AC  0x021C16AC  thumb  ov021
 *   d_021DA128     0x021DA128  data  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021DE3C8     0x021DE3C8  data  ov021  a4
 */
#include "../../matched/include/Obj12917.h"

struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021C1988;

typedef int (*Fn)(u16 *s);

typedef signed short   s16_021C19B4;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 fC;
} S;

extern void func_021C16AC(u8 *p);
extern void *func_021A572C(u8 *p);
extern void *func_0216D67C(void *a0);
extern int func_0216D83C(void *p);
extern int func_021641E8(int a);
extern int func_0216D86C(void *p);
extern int func_021641F8(int a);
extern u32 func_0216D8AC(void *p);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02050B80(u32);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_02051788(char *p);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
void func_021C1988(void *a, u16 *s);
u32 func_021C19B4(u8 *a, u32 b);
u32 *func_021C1A08(u32 a);
u32 func_021C1A48(S *p);
extern Fn d_021DA128[];
extern u8 d_021DE3C8;


/*
 * Runs the state table until a state returns other than 1.
 */
void func_021C1988(void *a, u16 *s)
{
    if (s[0] != 0) {
        while (d_021DA128[(s16_021C1988)s[1]](s) == 1)
            ;
    } else {
        func_021C16AC((u8 *)s);
    }
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021C19B4(u8 *a, u32 b)
{
    u32 r6;
    u32 h;
    int x;
    int y;

    r6 = (u32)func_021A572C(a);
    h = (u32)func_0216D67C((void *)r6);
    x = func_0216D83C((void *)r6);
    x += func_021641E8(b);
    y = func_0216D86C((void *)r6);
    y += func_021641F8(b);
    return (u32)func_0216DDDC(h, (s16_021C19B4)x, (s16_021C19B4)y, (u32)func_0216D8AC((void *)r6), (u32)1, 0);
}


u32 *func_021C1A08(u32 a)
{
    u32 *r;

    r = func_02030734(a, 0x10, 1, (const char *)&d_021DE3C8, 0x2e);
    ((struct Obj12917 *)r)->f4 = a;
    func_02050B80(a);
    r[2] = (u32)func_02030734(a, 0x4800, 1, (const char *)&d_021DE3C8, 0x34);
    return r;
}


/*
 * Creates the effect instance and sets its two scale parameters.
 */
u32 func_021C1A48(S *p)
{
    u32 a;
    u32 b;
    u32 o;

    p->fC = func_02050C04(p->f8, 0x4800, 1, p->f4);
    o = func_02051788((char *)p->fC);
    a = 1 << 12;
    b = 0x384000;
    func_02048B60((struct Light *)o, &a);
    func_02048B6C((struct Light *)o, &b);
    return p->fC;
}
