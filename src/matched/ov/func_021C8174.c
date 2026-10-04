/*
 * function: func_021C8174
 * address:  0x021C8174
 * packet:   pkt_021C8174
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8714  0x021B8714  thumb  ov093
 */

char *func_021B8714(char **p);

int func_021C8174(int *p)
{
    return *(int *)((char *)func_021B8714((char **)(*(int *)((char *)p + 4))) + 4);
}
