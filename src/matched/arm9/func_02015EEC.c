/*
 * function: func_02015EEC
 * address:  0x02015EEC
 * packet:   pkt_02015EEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned short u16;

u16 func_02015EEC(char *p)
{
    return **(u16 **)(p + 0x28);
}
