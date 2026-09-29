/*
 * function: func_0218409C
 * address:  0x0218409C
 * packet:   pkt_ov020_0218409C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[7]; } Blk28;

extern int func_021BE89C(int a, int b);
extern int func_021BE8B8(int a, int b);
extern u8 sub_0202E8A4(u8 a);

void func_0218409C(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    *(int *)(q + 4) = *(int *)(p + 0);
    *(int *)(q + 8) = *(int *)(p + 4);
    *(int *)(q + 0xc) = *(int *)(p + 8);
    *(int *)(q + 0x10) = *(int *)(p + 0x2c);
    *(int *)(p + 0x4c) = arg;
    *(u16 *)(q + 0x18) = *(u16 *)(p + 0xc);
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    *(int *)(q + 0x38) = func_021BE89C(*(u16 *)(p + 0xc), *(u16 *)(p + 0x14));
    *(int *)(q + 0x3c) = func_021BE8B8(*(u16 *)(p + 0xc), *(u16 *)(p + 0x14));
    *(int *)(q + 0x40) = (*(int *)(p + 0x40) != 0 && *(int *)(p + 0x44) != 0) ? 1 : 0;
    *(u8 *)(q + 0x44) = sub_0202E8A4(*(u16 *)(p + 0x48));
    *(u8 *)(q + 0x45) = *(u16 *)(p + 0x4a);
    *(int *)(q + 0x48) = 0;
    *(int *)(q + 0x4c) = 0;
}
