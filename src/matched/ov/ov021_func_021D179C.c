/*
 * function: func_021D179C
 * address:  0x021D179C
 * packet:   pkt_ov021_021D179C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * func_02012F8C (arm9 Thumb leaf) is filed as src/matched/arm9/func_02012F8C.c
 * to give the witness.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02012F8C  0x02012F8C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02009390  0x02009390  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_0215A5CC(u32 a);
extern u32 func_02158F74(void *a);
extern u32 func_02012F8C(u32 *p);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02009390(u32 a, u32 b);
extern u32 func_020457B0(u32 a, u32 b);
extern void func_02045994(u32 a, u16 *b, u32 c);
extern void func_0201EE0C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02045808(u32 a);

int func_021D179C(u32 a, u32 b)
{
    void *r6 = func_0215A5F4((void *)b);
    void *r7;
    u32 s8;
    u32 s12;
    u32 k0;
    u32 k1;
    u16 *e;
    u32 h;
    u32 id;

    func_0215A5DC((void *)b);
    r7 = func_0215A5E4((void *)b);
    s8 = func_0215A5CC(b);
    s12 = func_02158F74(r6);
    id = func_02012F8C(r7);
    k0 = func_02159B10(a, b);
    k1 = func_02159B10(a, b);
    e = func_02009390(id, k1);
    if (e != 0 && e[0] != 0x7E && e[0] != 0) {
        h = func_020457B0(0xE, s8);
        func_02045994(h, e + 1, 0xD);
        func_0201EE0C(s12, k0, h, 0, 0, 2);
        func_02045808(h);
    }
    return 0;
}
