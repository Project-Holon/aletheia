/*
 * function: func_021BCC3C
 * address:  0x021BCC3C
 * packet:   pkt_ov021_021BCC3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021BCA88  0x021BCA88  thumb  ov021
 *   func_021BCA6C  0x021BCA6C  thumb  ov021
 *   func_021BCA74  0x021BCA74  thumb  ov021
 *   func_021BCA8C  0x021BCA8C  thumb  ov021
 *   func_021BCA80  0x021BCA80  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BCA88(u8 *p);
extern u8 *func_021BCA6C(u8 *p);
extern u32 func_021BCA74(u8 *p);
extern int func_021BCA8C(void *p);
extern void func_021BCA80(u8 *p);
extern void func_021BCB9C(void *p, int a);

void func_021BCC3C(void *p)
{
    int r = 0;

    if (func_021BCA88(p)) {
        r = 1;
        func_021BCA6C(p);
    } else if (func_021BCA74(p)) {
        if (func_021BCA8C(p)) {
            r = 1;
        }
        func_021BCA80(p);
    }
    if (r) {
        func_021BCB9C(p, 1);
    }
}
