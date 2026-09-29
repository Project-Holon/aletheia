/*
 * function: func_021B83D8
 * address:  0x021B83D8
 * packet:   pkt_ov091_021B83D8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8A8C  0x021B8A8C  thumb  ov091
 *   func_021B86D8  0x021B86D8  thumb  ov091
 *   func_021B8758  0x021B8758  thumb  ov091
 *   func_021B8508  0x021B8508  thumb  ov091
 */

typedef unsigned char u8;

extern void func_021B8A8C(u8 *p);
extern void func_021B86D8(u8 *p);
extern void func_021B8758(u8 *p);
extern void func_021B8508(u8 *p);

void func_021B83D8(u8 *p)
{
    switch (p[0xe]) {
    case 0:
        p[0xe] = 1;
        p[0xf] = 4;
        break;
    case 1:
        func_021B8A8C(p);
        break;
    case 2:
        if (p[0xc] == 3) {
            func_021B86D8(p);
        } else if (p[0xc] == 4) {
            func_021B8758(p);
        } else {
            func_021B8508(p);
        }
        break;
    }
}
