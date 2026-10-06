/*
 * function: func_021B7604
 * address:  0x021B7604
 * packet:   pkt_021B7604
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B75E8  0x021B75E8  thumb  ov180
 */

extern void func_021B75E8(char *p, int i);

void func_021B7604(int *p)
{
    unsigned int i;

    for (i = 0; i < 0x21; i++)
        func_021B75E8((char *)p, i);
}
