/*
 * function: func_02028D7C
 * address:  0x02028D7C
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void *func_02028D7C(void *obj)
{
    u8 idx = *((u8 *)obj + 0xa0);
    return (u8 *)obj + 0x28 + idx * 12;
}
