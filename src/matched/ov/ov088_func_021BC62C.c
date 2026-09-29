/*
 * function: func_021BC62C
 * address:  0x021BC62C
 * packet:   pkt_ov088_021BC62C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_021BC734  0x021BC734  thumb  ov088
 *   func_02045088  0x02045088  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0204E720  0x0204E720  arm
 *   d_021BD8B8     0x021BD8B8  data  ov088  a4
 *   d_021BD848     0x021BD848  data  a4
 *   d_021BD858     0x021BD858  data  a4
 *   d_021BD878     0x021BD878  data  a4
 *   d_021BD898     0x021BD898  data  a4
 *
 * The POWCNT clear is spelled `& ~0x8000` (the SDK display-select inline):
 * the original pools 0xFFFF7FFF, where `&= 0x7FFF` derives the mask from
 * the -16 already in a register.  The four ov088 data hints were contested
 * or unwitnessed with the ov088 token; without it they resolve as sole-ref.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D534(u32 a, int b);
extern void func_02043534(int a);
extern void func_020435F4(int a);
extern void func_020433E0(void *p);
extern void func_0203F8F4(int);
extern void func_0203FC28(void *);
extern void func_021BC734(void *tmpl, int layer);
extern void func_02045088(int);
extern void func_02049B40(int, int, int, int, int, int);
extern u32 func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern void func_0201F5BC(int, int, int, int, int);
extern void func_0204E720(int a, int b, int c, int d);
extern char d_021BD8B8[];
extern char d_021BD848[];
extern char d_021BD858[];
extern char d_021BD878[];
extern char d_021BD898[];

void func_021BC62C(char *p)
{
    func_0207D534(0x0400006C, -16);
    func_0207D534(0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    func_020433E0(d_021BD8B8);
    func_0203F8F4(0x39);
    func_0203FC28(d_021BD848);
    *(u16 *)0x04000304 = (u16)(*(u16 *)0x04000304 & ~0x8000);
    func_021BC734(d_021BD858, 3);
    func_021BC734(d_021BD878, 1);
    func_021BC734(d_021BD898, 5);
    func_02045088(0x39);
    func_02049B40(0x17, 5, 0, 0, 0x20, 0x39);
    func_02049B40(0x17, 5, 4, 0, 0x20, 0x39);
    *(u32 *)(p + 8) = func_0201D7EC(0x17, 0, 0, 0, 0x39);
    func_0201F5BC(1, 1, 3, 0, 0x39);
    func_0201F5BC(1, 0x1f, 4, 0, 0x39);
    func_0201F5BC(5, 1, 1, 0, 0x39);
    *(u16 *)0x05000000 = 0x7D8C;
    *(u16 *)0x05000400 = 0x7D8C;
    func_0204E720(3, 0x10, 0, 0);
}
