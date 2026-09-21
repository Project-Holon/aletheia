/*
 * function: func_0206A17C
 * address:  0x0206A17C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clear the "loaded" bit of the flags halfword at +0x32, detach the buffer
 * pointer at +0x2c and return the old pointer.
 *
 * Pin evidence (2.0), measured 2026-09-21: the "kept constants" tell.  The
 * image materialises the store's zero EARLY, `mov r1, #0` at 0x0206A180
 * (`00 10 a0 e3`) between the `ldrh` and the `bic`, and only loads the buffer
 * pointer at 0x0206A18C, after the flags read-modify-write has retired.
 * dsi/1.1p1 -O4,p hoists the buffer load instead and sinks the constant,
 * giving `ldrh r3 / ldr r2,[r0,#0x2c] / mov r1,#0 / bic r3,r3,#1 / strh r3`:
 * the same 32 bytes with the first five instructions permuted, 16 concrete
 * bytes out.  Three source orderings (block-scoped old, statement-split
 * compound assign, raw pointer casts) all schedule identically under 1.1p1.
 * Under the pin the C below is 32 bytes, 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A17C.c \
 *       --func func_0206A17C --addr 0x0206A17C --arm --cc ../2.0/sp2
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    char  pad00[0x2c];
    void *buf;
    char  pad30[2];
    u16   flags;
} S;

void *func_0206A17C(S *p)
{
    void *old;
    u32   f = p->flags;

    p->flags = (u16)(f & ~1u);
    old = p->buf;
    p->buf = 0;
    return old;
}
