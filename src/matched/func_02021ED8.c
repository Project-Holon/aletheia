/*
 * function: func_02021ED8
 * address:  0x02021ED8
 * packet:   pkt_02021EE4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02021ED8(const char *ptr)
{
    u16 v = *(u16 *)(ptr + 0x118);
    return (u32)(v << 16) >> 18;
}
