/*
 * function: func_0218C3E0
 * address:  0x0218C3E0
 * packet:   pkt_ov021_0218C3E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Dispatches a slot-group operation by mode 0..4.
 *
 * symbols:
 *   func_0218C388  0x0218C388  thumb  ov021
 *   func_0218C23C  0x0218C23C  thumb  ov021
 *   func_0218C2E4  0x0218C2E4  thumb  ov021
 *   func_0218C290  0x0218C290  thumb  ov021
 *   func_0218C350  0x0218C350  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0218C388(u32 *st);
extern void func_0218C23C(u32 *st, int n);
extern void func_0218C2E4(u32 *st, int n);
extern void func_0218C290(u32 *st, int n);
extern void func_0218C350(u32 *st, int n);

void func_0218C3E0(u32 *st, int n, int mode)
{
    switch (mode) {
    case 0:
        func_0218C388(st);
        func_0218C23C(st, n);
        break;
    case 1:
        func_0218C388(st);
        func_0218C2E4(st, n);
        break;
    case 2:
        func_0218C388(st);
        func_0218C290(st, n);
        break;
    case 3:
        func_0218C350(st, n);
        break;
    case 4:
        func_0218C388(st);
        break;
    }
}
