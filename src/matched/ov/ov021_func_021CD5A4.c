/*
 * function: func_021CD5A4
 * address:  0x021CD5A4
 * packet:   pkt_ov021_021CD5A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CE760  0x021CE760  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_021CF17C  0x021CF17C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 func_021CE760(u8 *p);
extern void func_021CE81C(u32 *p);
struct Rec;
extern int func_021909BC(void *a);
struct U16Vec;
struct WordSet;
extern void func_02045808(struct U16Vec *vec);
extern int func_02190E40(u32 a);
extern u32 func_021904C8(struct Rec *a0);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_0203CD98(void);
extern void func_021CF17C(void);
extern u32 func_020307B0(void *p);

u32 func_021CD5A4(u32 *p)
{
    u32 r;

    r = func_021CE760((u8 *)p);
    func_021CE81C(p);
    if (p[0x4c]) {
        func_021909BC((void *)p[0x4c]);
        p[0x4c] = 0;
    }
    func_02045808((struct U16Vec *)p[10]);
    func_02045808((struct U16Vec *)p[9]);
    func_02045808((struct U16Vec *)p[8]);
    func_02045808((struct U16Vec *)p[7]);
    func_02045808((struct U16Vec *)p[6]);
    func_02190E40(p[5]);
    func_021904C8((struct Rec *)p[2]);
    func_0201ED04((struct WordSet *)p[1]);
    if (func_0203CD98() == 1) {
        func_021CF17C();
    }
    func_020307B0(p);
    return r;
}
