/*
 * function: func_021D10A8
 * address:  0x021D10A8
 * packet:   pkt_ov021_021D10A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_0200E588 is an unlabelled arm9 leaf (Ilias's, not filed here);
 * its relocation has no outside witness. Verified C for the leaf (EXACT, arm9,
 * thumb, -O4,p; no symbols): u32 func_0200E588(void) { return 0x5C8; }
 * Re-run this file once the leaf's shard exists.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E684  0x0200E684  thumb
 *   func_0200E588  0x0200E588  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012E4C  0x02012E4C  thumb
 *   func_02012E7C  0x02012E7C  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021D11D8  0x021D11D8  thumb  ov021
 *   func_021D1194  0x021D1194  thumb  ov021
 *   d_021DE674     0x021DE674  data    ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u32 func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020072CC(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_020073D8(u32 a, u32 b, u32 c);
extern void func_0200E684(u32 a);
extern u32 func_0200E588(void);
extern void func_02082BCC(u32 p, int v, u32 n);
extern void func_02012E4C(u32 a, u32 b);
extern u32 func_02012E7C(u32 a, u32 b);
extern void func_0200734C(u32 a, u32 b);
extern void func_020307B0(u32 p);
extern void func_021D11D8(u32 a);
extern void func_021D1194(u32 a);
extern char d_021DE674[];

int func_021D10A8(u32 a, u32 *b, u32 *c)
{
    u32 s4 = func_020120F4(c[0]);
    u32 r6 = func_02012EBC(s4);
    u32 x;

    switch (b[0]) {
    case 0:
        c[1] = func_02030734(0x8004, 0x1000, 0, d_021DE674, 0x34C);
        func_020072CC(r6, 5, 0x8004, c[1], 0x1000);
        x = func_020073D8(r6, 5, 0);
        if (c[2] == 1) {
            func_0200E684(x);
        } else {
            func_02082BCC(x, 0, func_0200E588());
        }
        func_02012E4C(s4, 5);
        b[0] = b[0] + 1;
        break;
    case 1:
        if (func_02012E7C(s4, 5) == 2) {
            func_0200734C(r6, 5);
            func_020307B0(c[1]);
            func_021D11D8(c[3]);
            func_021D1194(c[3]);
            return 1;
        }
        break;
    }
    return 0;
}
