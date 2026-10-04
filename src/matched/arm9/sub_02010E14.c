/*
 * function: sub_02010E14
 * address:  0x02010E14
 * packet:   pkt_02010DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02010F50  0x02010F50  thumb
 *   g_0214621C     0x0214621C  data
 *   g_021461E8     0x021461E8  data
 *   g_0214622A     0x0214622A  data
 *   g_02146228     0x02146228  data
 *
 * Records one play-time entry.  `rec` is an array of 0xc-byte records; the
 * record's +0xa byte is the SLOT (0..0xc) and +0xb is a count of hours, which
 * is stored as SECONDS in g_021461E8[slot] (0xe10 = 3600).  The +8 halfword
 * goes into the parallel halfword table at g_0214622A, and the selected-slot
 * byte g_02146228[0x1c] is cleared to 0xd when it named this slot and set to
 * this slot when `select` is 1.
 *
 * The four-case switch is emitted as a comparison TREE, not a table, because
 * the cases (0, 1, 7, 8) are not dense; the pairs are each other's partner
 * (slot 0 clears slot 1 and vice versa, slot 7 clears slot 8 and vice versa).
 *
 * EXACT* : the listing's extent runs to 0x02010EC0 because the two leaf
 * accessors that follow at 0x02010EA0 and 0x02010EB4 save no lr and so carry
 * no label (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Both should be seeded into layout/function_starts.txt.
 *
 * Addresses are Black-image addresses; 0x30 (the record-count bound) and 0xd
 * (the slot count) are content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010E14.c \
 *       --func sub_02010E14 --addr 0x02010E14 --cc 1.1p1 --thumb
 */
#include "../include/Obj08965.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02010F50(int idx);
extern u8  g_0214621C[];
extern u32 g_021461E8[];
extern u8  g_0214622A[];
extern u8  g_02146228[];

void sub_02010E14(int slot, u8 *rec, int select)
{
    int k;

    if (slot >= 0x30) {
        return;
    }
    rec = rec + slot * 0xc;
    k = rec[0xa];
    g_0214621C[k] = (u8)slot;
    g_021461E8[k] = rec[0xb] * 0xe10;
    *(u16 *)(g_0214622A + k * 2) = ((struct Obj08965 *)rec)->f8;
    if (g_02146228[0x1c] == k) {
        g_02146228[0x1c] = 0xd;
    }
    if (select == 1) {
        g_02146228[0x1c] = (u8)k;
    }
    switch (k) {
    case 0:
        func_02010F50(1);
        break;
    case 1:
        func_02010F50(0);
        break;
    case 7:
        func_02010F50(8);
        break;
    case 8:
        func_02010F50(7);
        break;
    }
}
