/*
 * function: func_021CDDDC
 * address:  0x021CDDDC
 * packet:   pkt_ov093_021CDDDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 *
 * symbols:
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021BA5C4  0x021BA5C4  thumb  ov093
 *   func_021BA5D0  0x021BA5D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021CDECC  0x021CDECC  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021D3FA8  0x021D3FA8  thumb  ov093
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *func_021B86B8(void ***p);
extern void func_021E90A0(void *o, int v);
extern int func_021E90D0(void *o);
extern u16 func_021BA5C4(void *p);
extern u16 func_021BA5D0(void *p);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(int a, int b, int c);
extern void func_021CDECC(u8 *p);
extern u32 func_021CD9E0(u8 *p);
extern u32 func_021D3FA8(u8 *p);
extern void func_021EAEA8(void *o, u16 v);

int func_021CDDDC(u8 *p, int *st)
{
    switch (*st) {
    case 0:
        if ((int)func_021B86B8(*(void ****)p) != 4) {
            func_021E90A0(*(void **)(p + 0x54), 0);
        } else {
            func_021E90A0(*(void **)(p + 0x54), 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_021E90D0(*(void **)(p + 0x54)) == 0) {
            break;
        }
        *(u16 *)(p + 0xe4) = func_021BA5C4(*(void **)p);
        *(u16 *)(p + 0xe6) = func_021BA5D0(*(void **)p);
        if (*(u16 *)(p + 0xe4) != 0 || *(u16 *)(p + 0xe6) != 0) {
            func_021F84E8(*(u16 *)(p + 0xe6), *(u16 *)(p + 0xe4));
            if (*(u16 *)(p + 0xe6) != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        func_021CDECC(p);
        if (func_021CD9E0(p) != 0) {
            func_021EAEA8(*(void **)(p + 0x54), func_021D3FA8(p + 0x18));
        }
        return 1;
    }
    return 0;
}
