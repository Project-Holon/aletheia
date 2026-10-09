/*
 * file:     unit_021E0A74.c
 * unit:     yes
 * function: func_021E0A74
 * address:  0x021E0A74
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
 *   d_021F264C     0x021F264C  data   ov093  a4
 */
extern int d_021F264C[];
int *func_021E0A74(int *p);

int *func_021E0A74(int *p)
{
    *p = 1;
    return d_021F264C;
}
