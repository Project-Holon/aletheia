/*
 * function: func_021BCDD8
 * address:  0x021BCDD8
 * packet:   pkt_ov021_021BCDD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BD20C  0x021BD20C  thumb  ov021
 *   func_021BC9C0  0x021BC9C0  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_021BC9CC  0x021BC9CC  thumb  ov021
 *   func_021BCA48  0x021BCA48  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_021BC92C  0x021BC92C  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021BD0C0(char *p);
extern int func_021BD20C(u32 a);
extern void func_021BC9C0(char *p);
extern void func_021BD0D0(char *p);
extern void func_021BC9CC(char *p);
extern int func_021BCA48(char *p);
extern void func_02045334(u32 a);
extern void func_021BC92C(char *p);
extern void func_021BCB9C(char *p, int a);

void func_021BCDD8(char *p)
{
    int r6 = 1;
    int i;

    switch (func_021BD0C0(p)) {
    case 0:
        for (i = 0; i < *(u8 *)(p + 0x20); i++) {
            u32 v = *(u32 *)(p + 0xc8 + i * 4);
            if (v != 0 && func_021BD20C(v) != 0) {
                r6 = 0;
                break;
            }
        }
        if (r6 != 0) {
            func_021BC9C0(p);
            func_021BD0D0(p);
        }
        break;
    case 1:
        func_021BC9CC(p);
        if (func_021BCA48(p) != 0) {
            func_021BD0D0(p);
        }
        break;
    case 2:
        func_02045334(*(u32 *)(p + 0x24));
        func_021BD0D0(p);
        break;
    case 3:
        func_021BC92C(p);
        func_021BD0D0(p);
        break;
    case 4:
        if (*(u16 *)(p + 0x42) > 0x1e) {
            func_021BCB9C(p, 6);
        }
        break;
    }
}
