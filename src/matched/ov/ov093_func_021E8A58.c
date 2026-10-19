/*
 * function: BTL_SICKCONT_MakeKind1Index15
 * address:  0x021E8A58
 * packet:   pkt_ov093_021E8A58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S { unsigned a:3; unsigned b:6; unsigned c:23; };

int BTL_SICKCONT_MakeKind1Index15(void)
{
    struct S s = {0};

    s.a = 1;
    s.b = 0xf;
    return *(int *)&s;
}
