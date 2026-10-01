/*
 * function: func_021CF12C
 * address:  0x021CF12C
 * packet:   pkt_ov021_021CF12C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020399A8(void);
extern int func_0203D1A4(int);
extern int func_0203D1C0(int a);

int func_021CF12C(u32 mask)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (i != func_0203D1A4(func_020399A8()) && ((1 << i) & mask) && func_0203D1C0(i) == 1) {
            return 1;
        }
    }
    return 0;
}
