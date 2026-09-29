/*
 * function: func_02184120
 * address:  0x02184120
 * packet:   pkt_ov020_02184120
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[7]; } Blk28;

extern int func_021BE89C(int a, int b);
extern int func_021BE8B8(int a, int b);
extern u8 sub_0202E8A4(u8 a);
extern int func_02012844(int a);
extern int func_021625CC(int a, int b);
extern int func_021626E8(int a);

void func_02184120(u8 *p, int arg)
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
    if (*(int *)(p + 0x10) == 1) {
        *(int *)(q + 0x14) = 0;
        return;
    }
    *(int *)(q + 0x14) = func_021626E8(func_021625CC(func_02012844(*(int *)(p + 4)), *(u16 *)(p + 0x16)));
}
