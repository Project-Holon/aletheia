/*
 * function: func_021BA978
 * address:  0x021BA978
 * packet:   pkt_ov099_021BA978
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012FFC  0x02012FFC  thumb
 *   func_021BA8D4  0x021BA8D4  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02028470  0x02028470  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02012FFC(void);
extern void func_021BA8D4(char *p);
extern u32 func_021BA8BC(u32 a);
extern int func_0201C6B4(u32 a);
extern void func_0201C6EC(u32 a);
extern void func_0201CE48(u32 a);
extern u32 func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045CAC(u32 a, u32 b, u32 c);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0201F73C(u32 a, u32 b, u16 c, u32 d);
extern void func_0201C7A4(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0201CCE4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern void func_02028470(char *a, u32 b);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern void func_02041B6C(u32 a);

void func_021BA978(char *p, u32 a1, int a2, int a3)
{
    int k, e;
    func_02012FFC();
    func_021BA8D4(p);
    *(u32 *)(p + 0x190) = func_021BA8BC(*(u32 *)(p + 0x190));
    if (func_0201C6B4(*(u32 *)(p + 0x1B8)) == 0)
        func_0201C6EC(*(u32 *)(p + 0x1B8));
    if (*(u32 *)(p + 0x1BC) != 0) {
        func_0201CE48(*(u32 *)(p + 0x1BC));
        *(u32 *)(p + 0x1BC) = 0;
    }
    *(u32 *)(p + 0x190) = func_020450F0(2, 2, 0x13, 0x1B, 4, 0xF, 1);
    if (a2)
        func_02045CAC(*(u32 *)(p + 0xE4), a1, *(u32 *)(p + 0xF0));
    else
        func_02045CAC(*(u32 *)(p + 0xE0), a1, *(u32 *)(p + 0xF0));
    func_0201F250(*(u32 *)(p + 0xDC), *(u32 *)(p + 0xF4), *(u32 *)(p + 0xF0));
    k = 0xFF;
    func_02043B5C(func_02045770(*(u32 *)(p + 0x190)), k);
    e = 0xE;
    func_0201F73C(*(u32 *)(p + 0x190), 1, *(u32 *)(p + 0x1334), e);
    if (a3 == 0) {
        func_0201C7A4(func_02045770(*(u32 *)(p + 0x190)), 0, 0, *(u32 *)(p + 0xF4), *(u32 *)(p + 0xE8));
    } else {
        u32 t = func_02012FFC();
        *(u32 *)(p + (k + 0xBD)) = func_0201CCE4(*(u32 *)(p + 0x190), 0, 0, *(u32 *)(p + 0xF4), *(u32 *)(p + 0xE8), t, *(u32 *)(p + e * 0x20), 2, 0x21, 0xF);
        func_02028470(p + 0x26C, 2);
    }
    func_02045334(*(u32 *)(p + 0x190));
    func_02045374(*(u32 *)(p + 0x190));
    func_02041B6C(2);
}
