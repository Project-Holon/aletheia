/*
 * function: func_021BE21C
 * address:  0x021BE21C
 * packet:   pkt_ov217_021BE21C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE9B8 0x021BE9B8 thumb ov217
 *   func_021BE934 0x021BE934 thumb ov217
 *   func_021BE4DC 0x021BE4DC thumb ov217
 *   func_021BED10 0x021BED10 thumb ov217
 *   func_021C1184 0x021C1184 thumb ov217
 *   func_021C1178 0x021C1178 thumb ov217
 *   func_02006238 0x02006238 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021BF704 0x021BF704 thumb ov217
 *   func_021BF728 0x021BF728 thumb ov217
 *   func_021BFC60 0x021BFC60 thumb ov217
 *   func_021BF08C 0x021BF08C thumb ov217
 *   func_021BF15C 0x021BF15C thumb ov217
 *   func_021BF3B4 0x021BF3B4 thumb ov217
 *   func_021BF38C 0x021BF38C thumb ov217
 *   func_021BEEA4 0x021BEEA4 thumb ov217
 *   func_021BF3D8 0x021BF3D8 thumb ov217
 *   func_021BEF98 0x021BEF98 thumb ov217
 *   func_021BEC64 0x021BEC64 thumb ov217
 *   func_021BE4E0 0x021BE4E0 thumb ov217
 *   func_021BEC0C 0x021BEC0C thumb ov217
 *   func_021BF264 0x021BF264 thumb ov217
 *   func_021BF2FC 0x021BF2FC thumb ov217
 *   func_021BF4AC 0x021BF4AC thumb ov217
 *   func_021BF47C 0x021BF47C thumb ov217
 *   func_021BE448 0x021BE448 thumb ov217
 *   func_021BF77C 0x021BF77C thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BE4DC(void *p);
extern u8 *func_021BF77C(void *p);
extern void func_021BED10(void *p, u32 i);
extern void func_021C1184(u8 *h, u32 v);
extern void func_021C1178(u8 *h);

extern int func_02006238(void);
extern void func_020061E4(u32 a);
extern void func_021BF704(void *p);
extern void func_021BE9B8(void *p);
extern int func_021BE934(char *p);
extern void func_021BF728(void *p);
extern void func_021BFC60(void *p);
extern void func_021BF08C(char *p);
extern void func_021BF15C(char *p);
extern void func_021BF3B4(char *p);
extern void func_021BF38C(char *p);
extern void func_021BEEA4(char *p);
extern void func_021BF3D8(char *p);
extern void func_021BEF98(char *p);
extern void func_021BEC64(void *p);
extern void func_021BE4E0(void *p);
extern void func_021BEC0C(void *p);
extern void func_021BF264(char *p);
extern void func_021BF2FC(char *p);
extern void func_021BF4AC(char *p);
extern void func_021BF47C(char *p);
extern void func_021BE448(void *p);
void func_021BE21C(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        *(u32 *)(p + 0x3d0) = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BE9B8(p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10(p, 0);
        func_021BED10(p, 1);
        func_021BEC64(p);
        func_021C1184(func_021BF77C(p), 1);
        func_021C1178(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (*(u32 *)(p + 0x28) >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            func_020061E4(0x76b);
        }
        break;
    case 2:
        *(u32 *)(p + 0x3d0) = 0;
        func_021BEC0C(p);
        func_021C1184(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BE934(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        func_020061E4(0x76c);
        func_021BE448(p);
        break;
    }
}
