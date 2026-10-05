/*
 * function: func_021BEC24
 * address:  0x021BEC24
 * packet:   pkt_021BEC24
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *
 * BLOCKER (4 bytes): the image loads c[1] into r0 and materialises the -1
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
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02006148(u32);
extern void func_020061F8(void);

void func_021BEC24(u32 a, u32 b, int *c)
{
    if (c[1] == -1) {
        func_02006148(c[0]);
    }
    func_020061F8();
}

