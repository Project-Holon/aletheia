/*
 * function: func_02084F44
 * address:  0x02084F40
 * packet:   pkt_02084F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * promoted: was MATCH (blocker 0x02084F68, whose only call site is inside
 *           this range, so the `label` class refuses it).  Filing
 *           src/matched/func_02084F68.c as an EXACT entry gave the site the
 *           `matched` class and the file is EXACT with no change to the C.
 *
 * The address is 0x02084F40, four bytes below the label 0x02084F44: this is
 * the variadic entry point whose first instruction is the argument
 * home-area push `stmfd sp!, {r0, r1, r2, r3}`, and disasm.py labels the
 * ordinary `push {r3, lr}` that follows it, one word late
 * (docs/idioms/a-home-area-push-hides-the-real-function-start-one-word-early.md).
 * The 40 bytes here therefore cover the whole original function, and the
 * worklist's 36-byte entry at 0x02084F44 is the same code with its first
 * four bytes cut off.
 *
 * Only the 3rd parameter is variadic; the two home slots that matter are
 * the align-down of `&a1` (`bic r2, r2, #3` with no preceding `+ 3` -- the
 * `va_start` this front end emits for a four-byte parameter) and the
 * reload of a1 from its home slot for the call, which is what taking its
 * address costs.
 */

typedef char *va_list;

extern void func_02084F68(int a0, int a1, va_list ap);

void func_02084F44(int a0, int a1, ...)
{
    va_list ap;

    ap = (va_list)(((unsigned int)&a1 & ~3u) + 4);
    func_02084F68(a0, a1, ap);
}
