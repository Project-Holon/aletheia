/*
 * unit:     yes
 * address:  0x0201F41C
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201F41C, func_0201F448
 *
 * Two wide-string helpers.  func_0201F41C is a bounded copy that always
 * terminates the destination; func_0201F448 is an equality test.  Both read
 * the terminator character from func_02045A98 rather than from a constant,
 * and both hold it in a named local, which is what puts the call result in
 * the left slot of func_0201F41C's `cmp r0, r1`
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * The last store of func_0201F41C is `*(dst + n - 1) = eos`, not
 * `dst[n - 1] = eos`.  The two are the same value and different code: the
 * subscript form folds the subtraction into the index and scales once
 * (`subs`/`lsls`/`strh` with a register offset), while the pointer form
 * scales `n`, adds it to the base and then subtracts the element size
 * (`lsls`/`adds`/`subs #2`/`strh`).  Seven bytes, and nothing else in the
 * function moves; see
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F41C.c  *       --addr 0x0201F41C --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02045A98(void);

void func_0201F41C(const u16 *src, u16 *dst, u32 n)
{
    u16 eos = func_02045A98();
    u32 i;

    for (i = 0; i < n; i++) {
        dst[i] = src[i];
        if (eos == src[i]) {
            break;
        }
    }
    *(dst + n - 1) = eos;
}

u32 func_0201F448(const u16 *a, const u16 *b)
{
    u16 eos = func_02045A98();

    while (*a != eos) {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
    }
    if (*b != eos) {
        return 0;
    }
    return 1;
}
