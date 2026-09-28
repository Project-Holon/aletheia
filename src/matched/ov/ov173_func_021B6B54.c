/*
 * function: func_021B6B54
 * address:  0x021B6B54
 * packet:   pkt_021B6B54
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B7460  0x021B7460  thumb  ov173
 */

extern void func_021B7460(int *, int);

int func_021B6B54(int *p)
{
    func_021B7460(p, 6);
    *(int *)((char *)p + 0x1B0) = 5;
    return 2;
}
