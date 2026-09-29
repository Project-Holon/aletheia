/*
 * function: func_021A1D04
 * address:  0x021A1D04
 * packet:   pkt_ov021_021A1D04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_021A2050  0x021A2050  thumb  ov021
 *   func_021A21B0  0x021A21B0  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u32 d_021D8868[];
extern void func_021A2050(u32 obj, int a, int b);
extern int func_021A21B0(u32 obj);
extern void func_021A1FEC(u32 obj, u32 v, int b, int c, int d, int e, int f);

void func_021A1D04(u8 *p, int x)
{
    u32 t;

    switch (*(u16 *)(p + 0xa)) {
    case 0:
        break;
    case 1:
        func_021A1FEC(*(u32 *)(p + 0x24), d_021D8868[*(u16 *)(p + 0xe) * 2], 1, 1, 2,
                      *(u32 *)(p + 0x10), x);
        func_021A2050(*(u32 *)(p + 0x20), 1, 2);
        *(u16 *)(p + 0xa) = 2;
        break;
    case 2:
        if (func_021A21B0(*(u32 *)(p + 0x20)) == 0) {
            t = *(u32 *)(p + 0x20);
            *(u32 *)(p + 0x20) = *(u32 *)(p + 0x24);
            *(u32 *)(p + 0x24) = t;
            *(u16 *)(p + 0xc) = *(u16 *)(p + 0xe);
            *(u16 *)(p + 0xe) = 0xFFFF;
            *(u32 *)(p + 0x10) = 1;
            *(u16 *)(p + 0xa) = 0;
        }
        break;
    }
}
