/*
 * function: func_021B75FC
 * address:  0x021B75FC
 * packet:   pkt_021B75FC
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7460  0x021B7460  thumb  ov173
 */

extern void func_021B7460(int *, int);

int func_021B75FC(int *p)
{
    func_021B7460(p, 8);
    *(int *)((char *)p + 0x1B0) = 8;
    *(unsigned char *)(*(int *)p + 0x1a) = 1;
    return 2;
}
