/*
 * function: func_02196F44
 * address:  0x02196F44
 * packet:   pkt_ov021_02196F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Handler: stores the request at +0x300 and dispatches on it (five cases).
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196ECC  0x02196ECC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196ECC(void);
extern void func_020061E4(int n);

int func_02196F44(u32 v, u8 *p)
{
    int r = 0;

    *(u32 *)(p + 0x300) = v;
    switch (v) {
    case 0:
        func_020061E4(0x73B);
        r = 1;
        *(u32 *)(p + 8) = 1;
        func_02196034(p, func_02196ECC, 0x5B1);
        break;
    case 1:
        func_020061E4(0x73B);
        *(u32 *)(p + 8) = 2;
        func_02196034(p, func_02196ECC, 0x5B7);
        r = 1;
        break;
    case 2:
        func_020061E4(0x73B);
        *(u32 *)(p + 8) = 3;
        func_02196034(p, func_02196ECC, 0x5BD);
        r = 1;
        break;
    case 3:
        func_020061E4(0x73B);
        *(u32 *)(p + 8) = 4;
        func_02196034(p, func_02196ECC, 0x5C3);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        *(u32 *)(p + 8) = 0xC;
        func_02196034(p, func_02196ECC, 0x5C9);
        break;
    }
    return r;
}
