/*
 * function: func_021B6170
 * address:  0x021B6170
 * packet:   pkt_021B6170
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

void func_021B6170(int *p)
{
    *(int *)((char *)p + 4) = func_020056A0((void *)0x021B61B5, p, 0);
}
