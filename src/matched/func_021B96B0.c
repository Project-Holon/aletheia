/*
 * function: func_021B96B0
 * address:  0x021B96B0
 * packet:   pkt_021B96B0
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 */

extern int func_020221A4(void *);

int func_021B96B0(char *p)
{
    if (func_020221A4(p) == 1)
        return *(int *)(p + 0x2f0);
    return 1;
}
