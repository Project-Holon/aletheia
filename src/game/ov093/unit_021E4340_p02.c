/*
 * file:     unit_021E4340_p02.c
 * unit:     yes
 * function: func_021E4748
 * address:  0x021E4748
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F2774     0x021F2774  data   ov093  a4
 */
extern int d_021F2774[];
int *func_021E4748(int *p);

int *func_021E4748(int *p)
{
    *p = 1;
    return d_021F2774;
}
