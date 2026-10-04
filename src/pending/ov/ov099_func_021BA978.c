/*
 * function: func_021BA978
 * address:  0x021BA978
 * packet:   pkt_ov099_021BA978
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): lane17 wave D2: 320 bytes, same size; first draft with guessed all-u32 prototypes. Residue: original prologue push {r4-r7,lr} sub sp,#0x1c keeps a1 in r6 and the flag in r7 (a3 spilled to [sp,#0x18]); ours spills a1 and keeps a3 in r7. The original holds 0xFF in r6 (call arg and 0x1BC = 0xFF+0xBD) and 0xE in r7 (call arg and 0xE<<5 = 0x1C0); plain int locals k, e were folded back to literals, so try enum-typed locals. Callee prototypes (020450F0, 0201CCE4, 0201C7A4) are guesses from register use.
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
extern u32 func_0201CCE4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
extern void func_02028470(char *a, u32 b);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern void func_02041B6C(u32 a);

void func_021BA978(char *p, u32 a1, int a2, int a3)
{
    u32 *q;
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
    q = (u32 *)(a2 ? p + 0xE4 : p + 0xE0);
    func_02045CAC(*q, a1, *(u32 *)(p + 0xF0));
    func_0201F250(*(u32 *)(p + 0xDC), *(u32 *)(p + 0xF4), *(u32 *)(p + 0xF0));
    k = 0xFF;
    func_02043B5C(func_02045770(*(u32 *)(p + 0x190)), k);
    e = 0xE;
    func_0201F73C(*(u32 *)(p + 0x190), 1, *(u32 *)(p + 0x1334), e);
    if (a3 == 0) {
        func_0201C7A4(func_02045770(*(u32 *)(p + 0x190)), 0, 0, *(u32 *)(p + 0xF4), *(u32 *)(p + 0xE8));
    } else {
        u32 t = func_02012FFC();
        *(u32 *)(p + (k + 0xBD)) = func_0201CCE4(*(u32 *)(p + 0x190), 0, 0, *(u32 *)(p + 0xF4), *(u32 *)(p + 0xE8), t, *(u32 *)(p + (e << 5)), 2, 0x21);
    }
    func_02028470(p + 0x26C, 2);
    func_02045334(*(u32 *)(p + 0x190));
    func_02045374(*(u32 *)(p + 0x190));
    func_02041B6C(2);
}
