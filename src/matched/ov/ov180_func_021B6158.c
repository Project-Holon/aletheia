/*
 * function: func_021B6158
 * address:  0x021B6158
 * packet:   pkt_021B6158
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 */

extern int func_020056A0(void *, int *, int);

void func_021B6158(int *p)
{
    *(int *)((char *)p + 4) = func_020056A0((void *)0x021B6195, p, 0);
}
