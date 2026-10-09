/*
 * file:     unit_021E6DA0.c
 * unit:     yes
 * function: func_021E6DA0
 * address:  0x021E6DA0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Hidden setter that follows a linker veneer, so it cannot join the unit before it.
 *
 * symbols:
 *   d_021F2574     0x021F2574  data   ov093  a4
 */
extern int d_021F2574[];
int *func_021E6DA0(int *p);

int *func_021E6DA0(int *p)
{
    *p = 1;
    return d_021F2574;
}
