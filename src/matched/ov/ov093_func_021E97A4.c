/*
 * function: func_021E97A4
 * address:  0x021E97A4
 * packet:   pkt_ov093_021E97A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E9738  0x021E9738  thumb  ov093
 */
extern int func_021E9738(void *p);

int func_021E97A4(char *p)
{
    if (func_021E9738(p) != 0) {
        return *(int *)(p + 0xc4);
    }
    return 0;
}
