/*
 * function: func_020507A0
 * address:  0x020507A0
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * The listing labels this function at 0x020507A4, not 0x020507A0: disasm.py
 * only auto-labels a prologue that saves lr, so the four bytes at 0x020507A0
 * that home the four argument registers (`push {r0,r1,r2,r3}`, the tell for
 * an address-taken register parameter,
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) are
 * printed as a stray `.word` and the label lands on the `push {r3, lr}` four
 * bytes later.  The real entry is 0x020507A0 and the function is 48 bytes,
 * not the worklist's 44; verified from 0x020507A0, where the extent runs to
 * the next label at 0x020507D0.
 *
 * The third parameter is not a pointer but a scalar whose address is taken
 * (`&x`, compiled as the home slot).  Written as `u8 *buf` it compiles to 32
 * bytes; as `u8 buf[16]`, 32; only `&x` on a scalar reproduces the home push.
 *
 * Reads element `idx` of a 40-byte record array hanging off p+24 and hands it,
 * together with p's own word at +4 and the caller's buffer address, to
 * func_0204F720.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020507A0.c \
 *       --func func_020507A0 --addr 0x020507A0 --cc 1.1p1 --arm
 */
#include "../include/Obj11454.h"

typedef unsigned int u32;

extern int func_0204F720(u32 a, u32 b, void *buf);

int func_020507A0(void *p, int idx, u32 x)
{
    return func_0204F720(((struct Obj11454 *)p)->f4,
                         *(u32 *)(((struct Obj11454 *)p)->f18 + idx * 40),
                         &x);
}
