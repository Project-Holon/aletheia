/*
 * function: func_021BEC24
 * address:  0x021BEC24
 * packet:   pkt_ov203_021BEC24
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Former blocker (4 bytes): the image loads c[1] into r0 and materialises the -1
 * sentinel into r1 (`movs r1,#0; mvns r1,r1; cmp r0,r1`); mwcc inverts the
 * pair (value r1, sentinel r0).  `-1 == c[1]`, `c[1] != -1`, a named `int v`,
 * a named `int z = 0` with `z - 1`, and a `c + 1` pointer local all reproduce
 * the same inversion; the comparison is symmetric so no operand order flips
 * it.  Addresses are Black-image addresses.
 *
 * 2026-10-05 (D8): also tried u32 *c with 0xFFFFFFFF, `int m = 0; m = ~m;`
 * compared to c[1], `~c[1] == 0` (same 4-byte residue), `c[1] + 1 == 0` (15
 * bytes differ), one-field-pair struct with ~0u, a static inline eq(v) with
 * a zero-local `v == ~s`, `if (c[1] != -1) {} else call`, and a (int)
 * 0xFFFFFFFF literal. All keep the value in r1, sentinel in r0. No fix.
 * Fix 2026-10-05 (D9): func_020061F8 takes an
 * argument (its listing reads r0). The call after the join receives the
 * channel: c[1], or func_02006148(c[0]) when c[1] is -1. The value stays in
 * r0 because it is that argument. EXACT.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_02006148(u32);
extern void func_020061F8(int);

void func_021BEC24(u32 a, u32 b, int *c)
{
    int ch = c[1];
    if (ch == -1) {
        ch = func_02006148(c[0]);
    }
    func_020061F8(ch);
}
