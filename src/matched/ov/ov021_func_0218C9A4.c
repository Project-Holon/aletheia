/*
 * function: func_0218C9A4
 * address:  0x0218C9A4
 * packet:   pkt_ov021_0218C9A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218C990  0x0218C990  thumb  ov021
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 */

int func_0218C990(void *p, unsigned short *out);
typedef unsigned int   u32;
int func_02006148(u32 a0);
int func_02006224(u32 a0);

int func_0218C9A4(void *p)
{
    unsigned short v;
    if (func_0218C990(p, &v) == 0)
        return 0;
    return func_02006224(func_02006148(v));
}
