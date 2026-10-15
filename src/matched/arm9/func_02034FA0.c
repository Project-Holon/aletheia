/*
 * function: UI_ClearKeepAwakeFlags
 * address:  0x02034FA0
 * packet:   pkt_02034FA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void UI_ClearKeepAwakeFlags(unsigned char *p, unsigned char flags)
{
    p[0x38] &= (unsigned char)~flags;
}
