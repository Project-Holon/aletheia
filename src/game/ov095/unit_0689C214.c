/*
 * file:     unit_0689C214.c
 * function: func_0689C214
 * address: 0x0689C214
 * packet: pkt_ov095_0689C214
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding at 0x0689C242.
 * symbols:
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D5440  0x021D5440  thumb
 */
#include "../../matched/include/Obj13639.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D5440(void *);
extern void *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
void func_0689C214(void *a, void *b)
{
    void *r;
    r = func_021C88A4(a, 0x21, func_021D5440(b));
    ((struct Obj13639 *)((u32)r))->f4 = func_021D5440(b);
    ((struct Obj13639 *)((u32)r))->f8 = 1;
    func_021C88C8(a, r);
}
