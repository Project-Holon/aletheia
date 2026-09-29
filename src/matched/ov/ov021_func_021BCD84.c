/*
 * function: func_021BCD84
 * address:  0x021BCD84
 * packet:   pkt_ov021_021BCD84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_021BC948  0x021BC948  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 func_021BD0C0(char *p);
extern void func_021BD0D0(char *p);
extern void func_021BC948(char *p);
extern void func_021BCB9C(char *p, int a);

void func_021BCD84(char *p)
{
    switch (func_021BD0C0(p)) {
    case 0:
        p[0x149] = 0;
        func_021BD0D0(p);
        break;
    case 1:
        if (*(u16 *)(p + 0x42) % 3 == 0) {
            func_021BC948(p);
            if (*(u8 *)(p + 0x20) <= *(u8 *)(p + 0x149)) {
                func_021BCB9C(p, 5);
            }
        }
        break;
    }
}
