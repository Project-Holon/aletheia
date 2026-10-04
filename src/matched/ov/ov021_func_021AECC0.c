/*
 * function: func_021AECC0
 * address:  0x021AECC0
 * packet:   pkt_ov021_021AECC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_0202A230(void *a, u32 idx);

int func_021AECC0(u32 a, u32 b)
{
    u32 x;
    u16 *out;
    u32 v;

    x = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    if (func_0202A230((void *)x, 9)) {
        v = 1;
    } else if (func_0202A230((void *)x, 11)) {
        v = 2;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}
