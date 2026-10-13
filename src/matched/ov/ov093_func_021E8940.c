/*
 * function: BTLV_CORE_MakeSlotKind2Index
 * address:  0x021E8940
 * packet:   pkt_ov093_021E8940
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-03 EXACT (wave B3, lane 21): the second pool word is 0xFE0001FF, not
 * 0x000001FF. It is the c:16 clear mask of the BTLV_CORE_MakeSlotKind2 struct, so this is
 * BTLV_CORE_MakeSlotKind2 with c = 0 and d left zero from the initialiser.
 *
 * symbols:

 */

typedef unsigned int u32;

struct S { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };

int BTLV_CORE_MakeSlotKind2Index(u32 a)
{
    struct S s = {0};

    s.a = 2;
    s.b = a & 0x3f;
    s.c = 0;
    return *(int *)&s;
}
