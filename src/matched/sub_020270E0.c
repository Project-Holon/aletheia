/*
 * function: func_020270E0
 * address:  0x020270E0
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146940  0x02146940  data
 */

typedef unsigned char u8;

extern void *g_02146940;

u8 func_020270E0(void)
{
    u8 *ptr = *(u8 **)&g_02146940;
    u8 ret;

    if (ptr == 0) {
        return 0;
    }

    ret = ptr[0xbaf];
    ptr[0xbaf] = 0;
    return ret;
}
