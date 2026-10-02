/*
 * function: func_020399EC
 * address:  0x020399EC
 * packet:   pkt_020399EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Count how many of the eight slots answer non-zero to the probe: when
 * func_0203D788() is null the count is zero, otherwise every slot is asked
 * through func_0203996C(i) and func_020399B8(), and each non-zero answer bumps
 * the counter (the `addne r5, r5, #1` after the loop's `add r4, r4, #1`).
 *
 * The counter is left uninitialised at its declaration and assigned `0` in
 * BOTH arms of the guard.  That is what puts `mov r5, #0` between the guard's
 * `cmp` and its `beq`, and what keeps the exit a single shared epilogue
 * instead of the predicated `moveq r0, r5; popeq` pair.  Declaring
 * `int c = 0;` up front instead hoists the zero above the call (4 bytes of
 * different scheduling), and `if (f() == 0) return c;` predicates the whole
 * early exit and grows the body to 68 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020399B8  0x020399B8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020399EC.c \
 *       --func func_020399EC --addr 0x020399EC --cc 1.1p1 --arm
 */

extern int func_0203D788(void);
extern unsigned char *func_0203996C(int i);
extern int func_020399B8(unsigned char *p);

int func_020399EC(void)
{
    int i;
    int c;

    if (func_0203D788() != 0) {
        c = 0;
        for (i = 0; i < 8; i++) {
            if (func_020399B8(func_0203996C(i)) != 0)
                c++;
        }
    } else {
        c = 0;
    }
    return c;
}
