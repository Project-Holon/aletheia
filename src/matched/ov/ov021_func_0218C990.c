/*
 * function: func_0218C990
 * address:  0x0218C990
 * packet:   pkt_ov021_0218C990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C944  0x0218C944  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
int func_0218C944(void *p, u32 idx, u16 *out);

int func_0218C990(unsigned char *p, int v)
{
    if (p == 0)
        return 0;
    return func_0218C944(p, *(int *)(p + 4), (u16 *)v);
}
