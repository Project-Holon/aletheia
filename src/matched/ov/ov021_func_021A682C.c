/*
 * function: func_021A682C
 * address:  0x021A682C
 * packet:   pkt_ov021_021A682C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A67A4  0x021A67A4  thumb  ov021
 *   func_021A6870  0x021A6870  thumb  ov021
 *   data_021D8AB8  0x021D8AB8  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef u32 (*Fn)(u8 *p, u32 a, u32 b);

extern int func_0216D3CC(u32 o);
extern u32 func_021A67A4(u8 *p);
extern void func_021A6870(u8 *p);
extern const Fn data_021D8AB8[];

u32 func_021A682C(u8 *p, u32 a1, u32 a2)
{
    u32 k;

    if (!func_0216D3CC(*(u32 *)(p + 0x1C)))
        return a1;
    if (a2 == 0) {
        k = func_021A67A4(p);
        if (k != 0)
            return data_021D8AB8[k](p, a1, a2);
    }
    func_021A6870(p);
    return a1;
}
