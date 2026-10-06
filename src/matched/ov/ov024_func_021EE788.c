/*
 * function: func_021EE788
 * address:  0x021EE788
 * packet:   pkt_ov024_021EE788
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A2400  0x021A2400  thumb  ov021
 *   func_021A240C  0x021A240C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A23F4  0x021A23F4  thumb  ov021
 *   func_021A2418  0x021A2418  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 */

int *func_021A21B8(int *p);
int func_021A23E8(int *p);
int func_021A2400(int *p);
int func_021A240C(int *p);
typedef unsigned char  u8;
void func_021A232C(u8 *p, int a, int b, int c, int d);
int func_021A23F4(int *p);
int func_021A2418(int *p);
typedef unsigned int   u32;
int func_021A2108(u32 a, int b, int c);
int func_021A23B0(int *p);

int func_021EE788(int *p, int v)
{
    int *s = func_021A21B8(p);
    int t;

    if (*s == 0) {
        if (func_021A23E8(p)) {
            t = func_021A2400(p);
            func_021A232C((u8 *)p, func_021A240C(p), t, 0xA0, v);
        }
        if (func_021A23F4(p)) {
            func_021A2108((u32)p, 0x52, func_021A2418(p));
        }
        *s = 1;
    }
    if (func_021A23B0(p)) {
        return 1;
    }
    return 0;
}
