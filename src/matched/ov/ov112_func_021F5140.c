/*
 * function: func_021F5140
 * address:  0x021F5140
 * packet:   pkt_021F5140
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4F54  0x021F4F54  thumb  ov112
 */

unsigned char func_021F4F54(void *);

unsigned char func_021F5140(void *p)
{
    return *(unsigned char *)(func_021F4F54(p) + 9);
}
