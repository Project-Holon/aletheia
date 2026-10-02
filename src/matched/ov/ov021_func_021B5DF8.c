/*
 * function: func_021B5DF8
 * address:  0x021B5DF8
 * packet:   pkt_ov021_021B5DF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case blocks are in source order 3, 2, 1; per-case stores to *o1 but a
 * single *o2 store after the switch is what spills o2 (register pressure)
 * and gives o1 r4.
 *
 * Case 3 reads d_021D98DC and case 1 d_021D992C (pool words in that order);
 * the earlier draft had the two swapped, which only the relocation check saw.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CF08  0x0200CF08  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200D0F8  0x0200D0F8  thumb
 *   func_0200D2C4  0x0200D2C4  thumb
 *   func_0200CF54  0x0200CF54  thumb
 *   func_0200D2B0  0x0200D2B0  thumb
 *   func_021B5DD0  0x021B5DD0  thumb  ov021
 *   d_021D98DC     0x021D98DC  data  a4
 *   d_021D9904     0x021D9904  data  a4
 *   d_021D992C     0x021D992C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_0215A5CC(u32 a);
extern void *func_0215A5E4(void *a0);
extern u32 func_0200CA1C(void *a);
extern u32 func_0200CA38(u32 a);
extern u32 func_0200CF08(u32 a, u32 b);
extern u32 func_0200D298(u32 a);
extern u32 func_0200D0F8(u32 a, u32 b);
extern u32 func_0200D2C4(u32 a, u32 b);
extern u32 func_0200CF54(u32 a, u32 b);
extern u32 func_0200D2B0(u32 a, u32 b);
extern u32 func_021B5DD0(u16 *t, u32 k);
extern u16 d_021D98DC[];
extern u16 d_021D9904[];
extern u16 d_021D992C[];

int func_021B5DF8(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    u32 id;
    u32 w;
    u32 x;

    mode = func_02159B10(a, b);
    o1 = func_02159AE8((void *)a, (void *)b);
    o2 = func_02159AE8((void *)a, (void *)b);
    id = func_0215A5CC(b);
    w = func_0200CA1C(func_0215A5E4((void *)b));
    func_0200CA38(w);
    *o1 = 5;
    *o2 = 0;
    switch (mode) {
    case 3:
        x = func_0200CF54(w, id);
        if (func_0200D2B0(w, id) == 1)
            *o1 = 0x1e;
        else
            *o1 = func_021B5DD0(d_021D98DC, x);
        break;
    case 2:
        x = func_0200D0F8(w, id);
        if (func_0200D2C4(w, id) == 1)
            *o1 = 0xd;
        else
            *o1 = func_021B5DD0(d_021D9904, x);
        break;
    case 1:
        x = func_0200CF08(w, id);
        if (func_0200D298(w) == 1)
            *o1 = 0x32;
        else
            *o1 = func_021B5DD0(d_021D992C, x);
        break;
    default:
        return 0;
    }
    *o2 = x;
    return 0;
}
