/*
 * function: func_021BDF58
 * address:  0x021BDF58
 * packet:   pkt_ov217_021BDF58
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02006238  0x02006238  thumb
 *   func_021BE4DC  0x021BE4DC  thumb  ov217
 *   func_021BE4E0  0x021BE4E0  thumb  ov217
 *   func_021BFC60  0x021BFC60  thumb  ov217
 *   func_021BF704  0x021BF704  thumb  ov217
 *   func_021BF568  0x021BF568  thumb  ov217
 *   func_021BEC84  0x021BEC84  thumb  ov217
 *   func_021BF76C  0x021BF76C  thumb  ov217
 *   func_021C1184  0x021C1184  thumb  ov217
 *   func_021C1154  0x021C1154  thumb  ov217
 *   func_021BE930  0x021BE930  thumb  ov217
 *   func_021BF3D8  0x021BF3D8  thumb  ov217
 *   func_021BEFF8  0x021BEFF8  thumb  ov217
 *   func_021BE7F0  0x021BE7F0  thumb  ov217
 *   func_021BF574  0x021BF574  thumb  ov217
 *   func_021BF08C  0x021BF08C  thumb  ov217
 *   func_021BF15C  0x021BF15C  thumb  ov217
 *   func_021BF264  0x021BF264  thumb  ov217
 *   func_021BF3B4  0x021BF3B4  thumb  ov217
 *   func_021BF2FC  0x021BF2FC  thumb  ov217
 *   func_021BEEA4  0x021BEEA4  thumb  ov217
 *   func_021BF47C  0x021BF47C  thumb  ov217
 *   func_021BE934  0x021BE934  thumb  ov217
 *   func_021BE448  0x021BE448  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020061E4(u32 a);
extern int func_02006238(void);
extern u32 func_021BE4DC(void *p);
extern void func_021BE4E0(void *p);
extern void func_021BFC60(void *p);
extern void func_021BF704(void *p);
extern void func_021BF568(void *p);
extern void func_021BEC84(u8 *p, int mode);
extern u8 *func_021BF76C(void *p);
extern void func_021C1184(u8 *h, u32 v);
extern void func_021C1154(u8 *h);

extern void func_021BE930(void *p, u32 v);
extern void func_021BF3D8(void *p);
extern void func_021BEFF8(u8 *p);
extern u32 func_021BE7F0(u32 a0);
extern void func_021BF574(void *p);
extern void func_021BF08C(void *p);
extern void func_021BF15C(void *p);
extern void func_021BF264(void *p);
extern void func_021BF3B4(void *p);
extern void func_021BF2FC(void *p);
extern void func_021BEEA4(void *p);
extern void func_021BF47C(void *p);
extern void func_021BE934(void *p);
extern void func_021BE448(void *p);

void func_021BDF58(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BFC60(p);
        func_021BF704(p);
        func_021BF568(p);
        func_021BEC84(p, 0);
        func_021BEC84(p, 1);
        func_021C1184(func_021BF76C(p), 1);
        func_021C1154(func_021BF76C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (*(u32 *)(p + 0x28) >= 0x78)
                func_021BE4E0(p);
            else
                func_020061E4(0x76B);
        }
        break;
    case 2:
        *(int *)(p + 0x3C8) = 1;
        func_021BE930(p, 1);
        func_021BF3D8(p);
        func_021BEFF8(p);
        func_021BE7F0((u32)p);
        func_021BF574(p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF3B4(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF47C(p);
        if (*(int *)(p + 0x3CC) == 0)
            func_021BE934(p);
        func_020061E4(0x76C);
        func_021BE448(p);
        break;
    }
}
