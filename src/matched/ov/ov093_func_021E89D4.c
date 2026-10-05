/*
 * function: func_021E89D4
 * address:  0x021E89D4
 * packet:   pkt_ov093_021E89D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned int u32;
struct S { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };
int func_021E89D4(u32 a)
{
    struct S s = {0};
    s.a = 1;
    s.c = a;
    return *(int *)&s;
}
