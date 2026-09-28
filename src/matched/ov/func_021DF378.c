/*
 * function: func_021DF378
 * address:  0x021DF378
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *
 * Mirror a word into a halfword field, forward, return 0.
 */

extern void func_020307B0(void *);

int func_021DF378(char *p)
{
    char *q = *(char **)(p + 0xc);

    *(short *)(p + 0x10) = *(int *)(q + 0x38);
    func_020307B0(q);
    return 0;
}

