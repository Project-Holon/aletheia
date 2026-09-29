/*
 * function: func_021B6100
 * address:  0x021B6100
 * packet:   pkt_ov017_021B6100
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Waits for A/B to be released, then pressed, reading the pad the way
 * PAD_Read does (KEYINPUT | the ARM7 XY buffer, inverted) with opposite
 * d-pad directions cancelled.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021B61F8  0x021B61F8  thumb  ov017
 *   func_020053EC  0x020053EC  thumb
 *   func_02034F5C  0x02034F5C  arm
 *   func_021B641C  0x021B641C  thumb  ov017
 */

typedef unsigned short u16;

extern int func_0202EB0C(void);
extern void func_021B61F8(int x);
extern void func_020053EC(void);
extern void func_02034F5C(void);
extern void func_021B641C(void);

static inline u16 ReadKeys(void)
{
    u16 k = (u16)(((*(volatile u16 *)0x04000130 | *(volatile u16 *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF);
    k = (u16)(k & ~((k & 0x40) << 1) & ~((k & 0x20) >> 1));
    return k;
}

void func_021B6100(void)
{
    func_021B61F8(func_0202EB0C() ? 0x2A : 0x10);
    while (ReadKeys() & 3) {
        func_020053EC();
        func_02034F5C();
    }
    while (!(ReadKeys() & 3)) {
        func_020053EC();
        func_02034F5C();
    }
    func_021B641C();
}
