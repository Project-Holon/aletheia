/*
 * function: func_021C1024
 * address:  0x021C1024
 * packet:   pkt_ov021_021C1024
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DE3AC     0x021DE3AC  data  ov021  a4
 *   func_021A3068  0x021A3068  thumb  ov021
 *   func_021A36E0  0x021A36E0  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_021C10B4  0x021C10B4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05075.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u8 d_021DE3AC;
extern u32 func_021A3068(u32 a);
extern u32 func_021A36E0(u8 *p);
extern u16 func_021AB0F0(u32 a);
extern int func_021AB2E8(int id);
extern u32 func_02188D30(u8 *p);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern void func_021C10B4();

void func_021C1024(u32 a, u16 b, u32 c, u32 d)
{
    u32 *r;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x18, 1, (const char *)&d_021DE3AC, 0x1e6);
    r[3] = func_021A3068(a);
    ((struct Obj05075 *)r)->f6 = b;
    r[4] = a;
    r[5] = func_021A36E0((u8 *)a);
    if (func_021AB2E8(func_021AB0F0(c)) == 1)
        ((struct Obj05075 *)r)->f8 = 1;
    func_02030DA8(func_02188D30((u8 *)r[3]), func_021C10B4, r, 0);
}
