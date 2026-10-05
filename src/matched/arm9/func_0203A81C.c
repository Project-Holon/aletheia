/*
 * function: func_0203A81C
 * address:  0x0203A81C
 * packet:   pkt_0203A81C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_0203A748  0x0203A748  arm
 *   func_0203A730  0x0203A730  arm
 *
 * Indirect dispatch: the first argument names a slot whose function pointer
 * comes back from func_0203A748; a null slot answers 0 with the conditional
 * `moveq`/`popeq` pair, and otherwise the pointer is called with the second
 * argument, the current value func_0203A730 reports and the third argument.
 * func_0203A730's own body ignores its parameter, but the caller still loads
 * one, so the source declares it with a parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A81C.c \
 *       --func func_0203A81C --addr 0x0203A81C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int func_0203A748(u32 idx);
extern u32  func_0203A730(u32 a0);

u32 func_0203A81C(u32 a0, u32 a1, u32 a2)
{
    u32 (*f)(u32, u32, u32) = (u32 (*)(u32, u32, u32))func_0203A748(a0);

    if (f == 0)
        return 0;
    return f(a1, func_0203A730(a0), a2);
}
