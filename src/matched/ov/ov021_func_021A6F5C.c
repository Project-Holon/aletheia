/*
 * function: func_021A6F5C
 * address:  0x021A6F5C
 * packet:   pkt_ov021_021A6F5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A2FA4  0x021A2FA4  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A2FB0  0x021A2FB0  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021BB1A0  0x021BB1A0  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021A71E4  0x021A71E4  thumb  ov021
 *   func_021A70D0  0x021A70D0  thumb  ov021
 *   func_021A35BC  0x021A35BC  thumb  ov021
 *   func_021A35F0  0x021A35F0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void *func_021A3074(unsigned char *p);
extern u32 func_021A2FA4(u32 a, u32 b);
extern u32 func_0216D3CC(u32 a);
extern u32 func_021A2FB0(u32 a);
extern u32 func_021A30C8(u32 a);
extern u32 func_021A3128(u32 a, u32 b);
extern u32 func_021AB0F0(u32 a);
extern u32 func_021BB1A0(u32 a);
extern u32 func_021AB11C(u32 a);
extern u32 func_021A71E4(u32 a, u32 *b, u16 *c, u32 d);
extern void func_021A70D0(u32 a, u32 *b, u32 c, u32 d, u16 *e, u32 f, u32 g);
extern u32 func_021A35BC(u32 a);
extern void func_021A35F0(u32 a, u32 b, u32 c, u32 d);

void func_021A6F5C(u32 a, u32 *b)
{
    u16 out[4];
    u32 v1c;
    u32 v18;
    void *v14;
    u32 v10;
    u32 r7;
    u32 fl;
    u32 r4;
    v10 = func_020362DC();
    r7 = func_0203630C();
    fl = 0;
    v14 = func_021A3074(b[1]);
    r4 = func_021A2FA4(b[1], r7);
    if (func_0216D3CC(v14) == 1 || func_021A2FB0(b[1]) == 1) {
        if (r4 != 9) {
            v18 = func_021A30C8(b[1]);
            v1c = func_021A3128(b[1], r4);
            if (func_021BB1A0(func_021AB0F0(v18)) != 0) {
                if (func_021AB11C(v1c) != 0) {
                    if (func_021A71E4(a, b, out, r4) != 0) {
                        func_021A70D0(a, b, r4, 1, out, v10, r7);
                        return;
                    }
                }
            }
        }
    }
    if (func_021A35BC(b[1]) == 1)
        fl |= 1;
    func_021A35F0(b[1], v10, r7, fl);
}
