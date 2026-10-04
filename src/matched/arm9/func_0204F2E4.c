/*
 * function: func_0204F2E4
 * address:  0x0204F2E4
 * packet:   pkt_0204E8C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Word getter through an out-parameter on one 0x28-byte slot; the `mla`
 * means the stride is the entry type's sizeof, not a byte offset.
 */
#include "../include/Obj16130.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Slot {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8  pad_18[8];
    u32 unk_20;
    u32 unk_24;
};

void func_0204F2E4(u8 *a0, int i, u32 *out)
{
    struct Slot *p = (struct Slot *)((struct Obj16130 *)a0)->f4;

    *out = p[i].unk_20;
}
