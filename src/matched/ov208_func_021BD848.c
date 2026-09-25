/*
 * function: func_021BD848
 * address:  0x021BD848
 * packet:   pkt_021BD848
 * region:   ov208
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 */

extern void func_0204B878(void *, int);

void func_021BD848(char *p, int which)
{
    if (which != 0)
    {
        *(unsigned int *)(p + 8) = *(unsigned short *)(p + 0x28);
    }
    else
    {
        *(unsigned int *)(p + 8) = *(unsigned short *)(p + 0x24);
    }
    func_0204B878(*(void **)p, (unsigned short)*(unsigned int *)(p + 8));
}
