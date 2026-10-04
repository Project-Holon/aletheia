/*
 * function: func_021BC388
 * address:  0x021BC388
 * packet:   pkt_ov021_021BC388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCF88  0x021BCF88  thumb  ov021
 *   func_021BCFA4  0x021BCFA4  thumb  ov021
 *   func_021BD0E0  0x021BD0E0  thumb  ov021
 *   func_021BC810  0x021BC810  thumb  ov021
 *   func_021BCFE0  0x021BCFE0  thumb  ov021
 *   func_021BCFF0  0x021BCFF0  thumb  ov021
 *   func_021BD008  0x021BD008  thumb  ov021
 *   func_021BD098  0x021BD098  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_021BD09C  0x021BD09C  thumb  ov021
 *   func_021BC730  0x021BC730  thumb  ov021
 *   func_021BC75C  0x021BC75C  thumb  ov021
 *   func_021BC794  0x021BC794  thumb  ov021
 *   func_021BC7BC  0x021BC7BC  thumb  ov021
 *   func_021BC998  0x021BC998  thumb  ov021
 *   func_021BC7D4  0x021BC7D4  thumb  ov021
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_021BC664  0x021BC664  thumb  ov021
 *   func_021BC6E8  0x021BC6E8  thumb  ov021
 *   func_021BD01C  0x021BD01C  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BgTemplate;
struct S;
extern void *func_021BCF88(int a);
extern void func_021BCFA4(int a, int b);
extern void func_021BD0E0(int a);
extern void func_021BC810(int a);
extern void func_021BCFE0(int a);
extern void func_021BCFF0(int a);
extern void func_021BD008(int a);
extern void func_021BD098(int a, int b);
extern u32 func_021904AC(u8 *p);
extern void func_021BD09C(u8 *p, u32 v);
extern void func_021BC730(int a);
extern void func_021BC75C(int a);
extern void func_021BC794(int a);
extern void func_021BC7BC(int a, int b);
extern void func_021BC998(int a);
extern void func_021BC7D4(int a);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_021BC664(struct S *p);
extern void func_021BC6E8(int a);
extern void func_021BD01C(int a);
extern void func_021BCB9C(void *p, int keep);

int func_021BC388(int a, int b, int c)
{
    int r4;

    r4 = (int)func_021BCF88(b);
    func_021BCFA4(r4, a);
    func_021BD0E0(r4);
    func_021BC810(r4);
    func_021BCFE0(r4);
    func_021BCFF0(r4);
    func_021BD008(r4);
    func_021BD098(r4, b);
    func_021BD09C((u8 *)r4, func_021904AC((u8 *)c));
    func_021BC730(r4);
    func_021BC75C(r4);
    func_021BC794(r4);
    func_021BC7BC(r4, 0);
    func_021BC998(r4);
    func_021BC7D4(r4);
    func_0203FCA0(3, (const struct BgTemplate *)0x021DE334, 0);
    func_021BC664((struct S *)r4);
    func_021BC6E8(r4);
    func_021BD01C(r4);
    func_021BCB9C((void *)r4, 0);
    return r4;
}
