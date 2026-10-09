/*
 * file:     unit_021E74D8.c
 * unit:     yes
 * function: func_021E74D8
 * address:  0x021E74D8
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
 *   d_021F24E4     0x021F24E4  data   ov093  a4
 */
extern int d_021F24E4[];
int *func_021E74D8(int *p);

int *func_021E74D8(int *p)
{
    *p = 1;
    return d_021F24E4;
}
