/*
 * function: BTLV_CORE_MakeSlotKind1Empty
 * address:  0x021E89C0
 * packet:   pkt_ov093_021E89C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned int u32;

struct S { unsigned a:3; unsigned b:29; };

int BTLV_CORE_MakeSlotKind1Empty(void)
{
    struct S s = {0};

    s.a = 1;
    return *(int *)&s;
}
