/*
 * function: func_021F514C
 * address:  0x021F514C
 * packet:   pkt_021F514C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F4F54  0x021F4F54  thumb  ov112
 */

unsigned char *func_021F4F54(unsigned char *p, int i);

unsigned char func_021F514C(void *p, int i)
{
    return *(unsigned char *)(func_021F4F54(p, i) + 10);
}
