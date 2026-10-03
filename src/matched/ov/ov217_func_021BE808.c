/*
 * function: func_021BE808
 * address:  0x021BE808
 * packet:   pkt_ov217_021BE808
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF78C 0x021BF78C thumb ov217
 *   func_021BF764 0x021BF764 thumb ov217
 *   func_021BF08C 0x021BF08C thumb ov217
 *   func_021BE934 0x021BE934 thumb ov217
 *   func_021BF15C 0x021BF15C thumb ov217
 *   func_021BF264 0x021BF264 thumb ov217
 *   func_021BF2FC 0x021BF2FC thumb ov217
 *   func_021BF38C 0x021BF38C thumb ov217
 *   func_021BF3B4 0x021BF3B4 thumb ov217
 *   func_021BF47C 0x021BF47C thumb ov217
 *   func_021BEAF8 0x021BEAF8 thumb ov217
 *   func_021BEEA4 0x021BEEA4 thumb ov217
 *   func_021BEF98 0x021BEF98 thumb ov217
 *   func_021BEF30 0x021BEF30 thumb ov217
 *   func_021BEFD4 0x021BEFD4 thumb ov217
 *   func_021C116C 0x021C116C thumb ov217
 *   func_021C118C 0x021C118C thumb ov217
 *   func_021C1160 0x021C1160 thumb ov217
 *   func_021C1184 0x021C1184 thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_020061E4 0x020061E4 thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF78C(void *p);
extern void func_021BF764(void *p, u32 k);
extern void func_021BF08C(char *p);
extern int func_021BE934(char *p);
extern void func_021BF15C(char *p);
extern void func_021BF264(char *p);
extern void func_021BF2FC(char *p);
extern void func_021BF38C(char *p);
extern void func_021BF3B4(char *p);
extern void func_021BF47C(char *p);
extern void func_021BEAF8(void *p);
extern void func_021BEEA4(char *p);
extern void func_021BEF98(char *p);
extern void func_021BEF30(char *p);
extern void func_021BEFD4(char *p);
extern void func_021C116C(u8 *h);
extern void func_021C118C(u8 *h, u32 v);
extern void func_021C1160(u8 *h);
extern void func_021C1184(u8 *h, u32 v);
extern u32 func_021BF810(void *p);
extern u8 *func_021BF76C(void *p);

extern void func_020061E4(u32 a);
void func_021BE808(char *p)
{
    int flag = 0;
    u32 k;
    if (func_021BF78C(p) == 0) {
        return;
    }
    if (*(u32 *)(p + 0x3c8) != 0 && func_021BF810(p) != 0) {
        func_021C116C(func_021BF76C(p));
        flag = 1;
    }
    switch (*(u32 *)(p + 0x2cc)) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    }
    func_021BF764(p, k);
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF15C(p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BF3B4(p);
    func_021BF47C(p);
    func_021BEAF8(p);
    func_021BEEA4(p);
    func_021BEF98(p);
    if (*(u32 *)(p + 0x3c8) != 0 && func_021BF810(p) != 0) {
        func_021BEF30(p);
        func_021BEFD4(p);
    }
    if (*(u32 *)(p + 0x3c8) != 0 && func_021BF810(p) != 0) {
        if (flag != 0) {
            func_021C118C(func_021BF76C(p), 0x14);
        }
        func_021C1160(func_021BF76C(p));
        func_021C1184(func_021BF76C(p), 1);
    }
    func_020061E4(0x548);
}
