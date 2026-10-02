/*
 * function: func_021A7010
 * address:  0x021A7010
 * packet:   pkt_ov021_021A7010
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
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A2FB0  0x021A2FB0  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021BB1A0  0x021BB1A0  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021A7198  0x021A7198  thumb  ov021
 *   func_021A712C  0x021A712C  thumb  ov021
 *   func_021A3698  0x021A3698  thumb  ov021
 *   func_021A3674  0x021A3674  thumb  ov021
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
extern u32 func_0216D608(void *a);
extern u32 func_0216D3CC(void *a);
extern u32 func_021A2FB0(u32 a);
extern u32 func_021A30C8(u32 a);
extern u32 func_021A3128(u32 a, u32 b);
extern u32 func_021AB0F0(u32 a);
extern u32 func_021BB1A0(u32 a);
extern u32 func_021AB11C(u32 a);
extern u32 func_021A7198(u32 a, u32 *b, u16 *c, u32 d);
extern void func_021A712C(u32 a, u32 *b, u32 c, u32 d, u16 *e, u32 f, u32 g);
extern u32 func_021A3698(u32 a);
extern void func_021A3674(u32 a, u32 b, u32 c);

void func_021A7010(u32 a, u32 *b)
{
    u16 out[6];
    u32 v1c;
    u32 v18;
    u32 v14;
    void *v10;
    u32 r6;
    u32 r7;
    u32 r4;
    v14 = func_020362DC();
    r6 = func_0203630C();
    v10 = func_021A3074((unsigned char *)b[1]);
    if (b[2] == 0) {
        r4 = func_021A2FA4(b[1], r6);
        r7 = 1;
    } else {
        r4 = func_0216D608(v10);
        r7 = 0;
    }
    if (func_0216D3CC(v10) == 1 || func_021A2FB0(b[1]) == 1) {
        if (r4 != 9) {
            v18 = func_021A30C8(b[1]);
            v1c = func_021A3128(b[1], r4);
            if (func_021BB1A0(func_021AB0F0(v18)) != 0) {
                if (func_021AB11C(v1c) != 0) {
                    if (func_021A7198(a, b, out, r4) != 0) {
                        func_021A712C(a, b, r4, r7, out, v14, r6);
                        b[2] = 0;
                        return;
                    }
                }
            }
        }
    }
    b[2] = func_021A3698(b[1]);
    func_021A3674(b[1], v14, r6);
}
