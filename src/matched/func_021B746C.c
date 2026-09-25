/*
 * function: func_021B746C
 * address:  0x021B746C
 * packet:   pkt_021B746C
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

extern void func_0204B3DC(int, int);

void func_021B746C(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0x9048);

    if (v)
        func_0204B3DC(v, a);
}
