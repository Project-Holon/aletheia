/*
 * function: func_021F4078
 * address:  0x021F4078
 * packet:   pkt_ov046_021F4078
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The table row is indexed inside the loop; the compiler hoists the
 * invariant row address (b's register reused for it). A `t = d[b][c]`
 * local before the loop colours b and the counter apart.
 * func_021BB3DC is ov021's thunk (reads r0-r2); ov214's label at the same
 * address is a different two-argument function.
 *
 * symbols:
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3DC  0x021BB3DC  thumb  ov021
 *   d_021F4430  0x021F4430  data  ov046  a4
 */

typedef unsigned int u32;
extern u32 func_02188C5C(u32);
extern void func_021BB3DC(u32, int, int);
extern int d_021F4430[][4][6];

void func_021F4078(u32 a, int b, int c)
{
    int v1[6];
    int v2[6];
    u32 h = func_02188C5C(a);
    int i;

    for (i = 0; i < 6; i++) {
        v1[i] = d_021F4430[b][c][i];
        v2[i] = 0;
    }
    if (c != 1) {
        v2[0] = 1;
        v2[1] = 1;
    }
    for (i = 0; i < 6; i++)
        func_021BB3DC(h, v1[i], v2[i]);
}
