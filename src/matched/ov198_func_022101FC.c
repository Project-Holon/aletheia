/*
 * function: func_022101FC
 * address:  0x022101FC
 * packet:   pkt_022101FC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02210C88 0x02210C88 thumb
 */

extern int func_02210C88(void *, int);

int func_022101FC(char *p)
{
    if (func_02210C88(p, 4) == 0)
    {
        return 0xf;
    }
    if (*(unsigned char *)((char *)*(void **)p + 0x1f) == 5)
    {
        return 0x1e;
    }
    return 7;
}
