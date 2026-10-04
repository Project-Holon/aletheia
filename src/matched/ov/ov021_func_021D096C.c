/*
 * function: func_021D096C
 * address:  0x021D096C
 * packet:   pkt_ov021_021D096C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_0200E588  0x0200E588  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_021D09D0  0x021D09D0  thumb  ov021
 *   d_021DE674     0x021DE674  data  a4
 */
#include "../include/Obj07595.h"

typedef unsigned short u16;

extern int d_021DE674;

typedef unsigned int   u32;
extern u32 func_0200E588(void);
struct Big;
struct Ctx;
struct Party;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct Party *func_0201A920(u32 heap);
extern void func_021D09D0(int a, char *out);

void *func_021D096C(int a)
{
    char *p;
    int r7;

    r7 = func_0200E588();
    func_02012EBC(func_020120F4((const struct Ctx *)a));
    p = func_02030734(5, 0x154, 1, (const char *)&d_021DE674, 0x5D);
    ((struct Obj07595 *)p)->f120 = 5;
    ((struct Obj07595 *)p)->f14C = (int)func_02030734(5, r7, 1, (const char *)&d_021DE674, 0x5F);
    func_021D09D0(a, p);
    ((struct Obj07595 *)p)->f128 = (int)func_0201A920(((struct Obj07595 *)p)->f120);
    return p;
}
