/*
 * function: NNSi_FndSetGroupId
 * address:  0x02060F40
 * packet:   pkt_02060F40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Setter: stores a halfword at +0x34 and returns the old value.
 *
 * symbols:
 */

typedef unsigned short u16;

u16 NNSi_FndSetGroupId(char *p, u16 v)
{
    u16 old = *(u16 *)(p + 0x34);
    *(u16 *)(p + 0x34) = v;
    return old;
}
