/*
 * function: BTL_SICKCONT_MakeKind4
 * address:  0x021E8A28
 * packet:   pkt_ov093_021E8A28
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

struct S { unsigned a:3; unsigned b:6; unsigned c:6; unsigned d:17; };

int BTL_SICKCONT_MakeKind4(u32 a, u32 b)
{
    struct S s = {0};

    s.a = 4;
    s.b = b & 0x3f;
    s.c = a & 0x3f;
    return *(int *)&s;
}
