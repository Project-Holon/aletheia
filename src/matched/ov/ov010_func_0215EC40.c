/*
 * function: func_0215EC40
 * address:  0x0215EC40
 * packet:   pkt_0215EC40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call: passes two pointer fields of b and the low byte of *a to
 * func_021C6078 and returns its result.
 *
 * symbols:
 *   func_021C6078  0x021C6078  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Obj12315 {
    unsigned char pad_0[8];
    void *f8;
    unsigned char pad_C[4];
    void *f10;
};

extern void *func_021C6078(void *, void *, u8);

void *func_0215EC40(u16 *a, void *b)
{
    return func_021C6078(((struct Obj12315 *)b)->f8, ((struct Obj12315 *)b)->f10, *a);
}
