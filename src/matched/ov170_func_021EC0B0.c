/*
 * function: func_021EC0B0
 * address:  0x021EC0B0
 * packet:   pkt_ov170_021EC0B0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B454 0x0204B454 arm
 */

extern void func_0204B454(int actor, short *out, unsigned short space);

void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space)
{
    short t[2];
    func_0204B454(*(int *)(p + i * 4 + 0x9E74), t, space);
    *a = t[0];
    *b = t[1];
}
