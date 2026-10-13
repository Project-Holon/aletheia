/*
 * function: BTLV_CORE_MakeSlotKind3
 * address:  0x021E899C
 * packet:   pkt_ov093_021E899C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: named callee of the parked ov093 HAND_ITEM_DestinyKnot_Infatuate
 * (+0080, `BTLV_CORE_MakeSlotKind3(c)` stored at record +8).  Packs a 3-bit constant
 * (3) with the low six bits of the argument shifted left by three, as a
 * bitfield union read back as a word; the empty frame is the compiler's
 * storage for the union local, and `= {0}` is what emits `movs r2,#0`
 * instead of reading the uninitialised slot back.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct S { unsigned a:3; unsigned b:6; unsigned c:23; };

int BTLV_CORE_MakeSlotKind3(u32 a)
{
    struct S s = {0};

    s.a = 3;
    s.b = a & 0x3f;
    return *(int *)&s;
}
