/*
 * function: func_021D213C
 * address:  0x021D213C
 * packet:   pkt_ov021_021D213C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020249B0  0x020249B0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern int func_020249B0(u32 a, u16 b);

int func_021D213C(u32 a, u32 b)
{
    u32 base, s, r7, r4;
    u16 *p;

    r4 = func_02159B10(a, b);
    s = func_02159B10(a, b);
    r7 = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    switch (r4) {
    case 1:
        base = 0x5C0;
        r4 = base + 0xBB;
        break;
    case 2:
        base = 0x664;
        r4 = base + 0x53;
        break;
    default:
        *p = 0;
        return 0;
    }
    if (func_020249B0(base, s & 0x7FF) && func_020249B0(r4, r7 & 0x7FF)) {
        *p = 1;
    } else {
        *p = 0;
    }
    return 0;
}
