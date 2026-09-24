/*
 * function: func_021BD868
 * address:  0x021BD868
 * packet:   pkt_021BD868
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int   u32;
typedef unsigned short u16;

int func_021BD868(const void *p)
{
    u32 r1 = *(u32 *)((const char *)p + 8);
    u32 r0 = *(u16 *)((const char *)p + 0x28);
    return r1 == r0;
}
