/*
 * function: BTL_SICK_OnHealBlockAdded
 * address: 0x0689C1A4
 * packet: pkt_ov095_0689C1A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding at 0x0689C1D2.
 * symbols:
 *   func_0689C1D4 0x0689C1D4 thumb ov095
 *   func_0689C1E4 0x0689C1E4 thumb ov095
 *   func_0689C1F4 0x0689C1F4 thumb ov095
 *   func_0689C204 0x0689C204 thumb ov095
 */
#include "../include/Obj13638.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0689C1D4(void *);
extern void *func_0689C1E4(void *, int, int);
extern int func_0689C1F4(void *);
extern void func_0689C204(void *, void *);
void BTL_SICK_OnHealBlockAdded(void *a, void *b)
{
    void *r;
    r = func_0689C1E4(a, 0x21, func_0689C1D4(b));
    ((struct Obj13638 *)((u32)r))->f4 = func_0689C1F4(b);
    ((struct Obj13638 *)((u32)r))->f8 = 0;
    func_0689C204(a, r);
}
