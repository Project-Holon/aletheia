/*
 * function: func_021BD814
 * address:  0x021BD814
 * packet:   pkt_021BD814
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Stores +4 and either re-arms +8 from +0x24 or takes it from +0x26 before handing the pair to 0x0204B878.
 */


extern void func_0204B878(int, int);

void func_021BD814(char *p, int v)
{
    *(int *)(p + 4) = v;
    if (v != 0) {
        if (*(int *)(p + 8) == *(unsigned short *)(p + 0x28))
            *(int *)(p + 8) = *(unsigned short *)(p + 0x24);
        func_0204B878(*(int *)p, (unsigned short)*(int *)(p + 8));
    } else {
        func_0204B878(*(int *)p, *(unsigned short *)(p + 0x26));
    }
}

