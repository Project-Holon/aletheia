/*
 * function: func_021C0AC0
 * address:  0x021C0AC0
 * packet:   pkt_ov021_021C0AC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021C0BE8  0x021C0BE8  thumb  ov021
 *   func_021C0C48  0x021C0C48  thumb  ov021
 *   func_021C0C80  0x021C0C80  thumb  ov021
 *   func_021C0BD8  0x021C0BD8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C0BE8(u8 *p);
extern void func_021C0C48(u8 *p);
extern int func_021C0C80(u8 *p);
extern void func_021C0BD8(u8 *p);

int func_021C0AC0(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)*(u16 *)(p + 0x16) % 20 == 0) {
            func_021C0BE8(p);
            if (p[0x14] <= p[0x15]) {
                *st = *st + 1;
                *(u16 *)(p + 0x16) = 0;
            }
        }
        break;
    case 1:
        if (*(u16 *)(p + 0x16) > 10) {
            func_021C0C48(p);
            *st = *st + 1;
            *(u16 *)(p + 0x16) = 0;
        }
        break;
    case 2:
        if (func_021C0C80(p) != 0) {
            *st = *st + 1;
        }
        break;
    case 3:
        func_021C0BD8(p);
        return 1;
    }
    *(u16 *)(p + 0x16) = *(u16 *)(p + 0x16) + 1;
    return 0;
}
