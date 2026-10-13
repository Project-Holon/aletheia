/*
 * function: BTLV_CORE_MakeSlotKind2
 * address:  0x021E896C
 * packet:   pkt_ov093_021E896C
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

struct S { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };

int BTLV_CORE_MakeSlotKind2(u32 a, u32 b)
{
    struct S s = {0};

    s.a = 2;
    s.b = a & 0x3f;
    s.c = b;
    return *(int *)&s;
}
