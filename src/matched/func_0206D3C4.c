/*
 * function: func_0206D3C4
 * address:  0x0206D3C4
 * packet:   pkt_0206D3C4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *
 * Bump a counter, and unless either of two status bits is set, push a
 * three-word packet of one repeated field (0xe0 or 0xe4, chosen by the second
 * argument) through the command queue as command 0x1b.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md).  The image
 * keeps `cmp r1, #0` at 0x0206D3E4 and `bne 0x0206D400` at 0x0206D3E8 over the
 * FOUR-instruction then-arm at 0x0206D3EC..0x0206D3F8 (`ldr r0,[r4,#0xe0]` /
 * three `str r0,[sp,...]`), and closes it with an unconditional `b 0x0206D410`
 * at 0x0206D3FC.  1.1p1 -O4,p predicates both arms instead -- `ldreq/streq x3`
 * then `ldrne/strne x3`, no branch and no join -- giving 104 bytes against the
 * original's 112, 46 concrete bytes out.  Under the pin the same C is 112
 * bytes, 0 mismatches.
 *
 * One lever under the pin: the field must be bound to a local `v` before the
 * three stores.  Written inline as `buf[2] = o->fe0; buf[1] = o->fe0; ...`,
 * 2.0 re-reads the field before EVERY store (six loads, 128 bytes); 1.1p1 CSEs
 * it either way, so the inline spelling looks equivalent under the default
 * compiler and is not.
 */

typedef unsigned int u32;

struct Obj {
    u32 f00;
    u32 p04;
    u32 f08;
    u32 p0c[(0xe0 - 0x0c) / 4];
    u32 fe0;
    u32 fe4;
};

extern void func_0206DDA4(u32 a, void *b, u32 c);

void func_0206D3C4(struct Obj *o, u32 which)
{
    u32 flags;
    u32 buf[3];

    flags = o->f08;
    if ((flags & 0x100) == 0 && (flags & 0x200) == 0) {
        u32 v;
        if (which == 0) {
            v = o->fe0;
            buf[2] = v;
            buf[1] = v;
            buf[0] = v;
        } else {
            v = o->fe4;
            buf[2] = v;
            buf[1] = v;
            buf[0] = v;
        }
        func_0206DDA4(0x1b, buf, 3);
    }
    o->f00 = o->f00 + 1;
}
