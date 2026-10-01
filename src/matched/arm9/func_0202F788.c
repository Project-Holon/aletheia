/*
 * function: func_0202F788
 * address:  0x0202F788
 * packet:   pkt_0202F788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * time_icon.c: the power callback reached from func_0202F768 as
 * func_0202F788(0) (and registered through the pool word 0x0202F789 at
 * 0x0202F784).  disasm.py carried it as .word data until it was seeded in
 * layout/function_starts.txt.  It never returns: after the shutdown work it
 * spins on func_020053EC.
 *
 * symbols:
 *   func_02007084  0x02007084  thumb
 *   func_0202F7C4  0x0202F7C4  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_0203CF5C  0x0203CF5C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020351A0  0x020351A0  arm
 *   func_020053EC  0x020053EC  thumb
 */

typedef unsigned int u32;

extern void func_02007084(void);
extern void func_0202F7C4(u32 mode);
extern int  func_0203CD98(void);
extern void func_0203CF04(void);
extern void func_0203CEAC(u32 a);
extern void func_0203D0D0(void);
extern void func_0203CF5C(void);
extern int  func_0203CDBC(void);
extern void func_020351A0(u32 a);
extern void func_020053EC(void);

void func_0202F788(u32 mode)
{
    func_02007084();
    func_0202F7C4(mode);
    if (func_0203CD98()) {
        func_0203CF04();
        func_0203CEAC(0);
        func_0203D0D0();
        do {
            func_0203CF5C();
        } while (!func_0203CDBC());
    }
    func_020351A0(2);
    for (;;)
        func_020053EC();
}
