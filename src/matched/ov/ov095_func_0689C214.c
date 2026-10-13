/*
 * function: BTL_SICK_OnItemBlockAdded
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
 *   func_0689C244 0x0689C244 thumb ov095
 *   func_0689C254 0x0689C254 thumb ov095
 *   func_0689C264 0x0689C264 thumb ov095
 *   func_0689C274 0x0689C274 thumb ov095
 */
#include "../include/Obj13639.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0689C244(void *);
extern void *func_0689C254(void *, int, int);
extern int func_0689C264(void *);
extern void func_0689C274(void *, void *);
void BTL_SICK_OnItemBlockAdded(void *a, void *b)
{
    void *r;
    r = func_0689C254(a, 0x21, func_0689C244(b));
    ((struct Obj13639 *)((u32)r))->f4 = func_0689C264(b);
    ((struct Obj13639 *)((u32)r))->f8 = 1;
    func_0689C274(a, r);
}
