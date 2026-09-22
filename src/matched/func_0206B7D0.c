/*
 * function: func_0206B7D0
 * address:  0x0206B7D0
 * packet:   pkt_0206B7A8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The three-byte opcode of the script object family (func_0206B94C is the
 * two-byte form one slot over).  Bit 9 of the flag word at +0x08 aborts; the
 * operand byte at f00[1] is cached at +0xac, bit 2 is set, the output cursor
 * at +0xb8 is pointed at the object's own +0x184 word, and the state byte at
 * +0x8e (read through the +0x14 hook, zero when the hook is null) selects
 * three stops.  Between stops 1 and 2 the value is produced either by the
 * sub-object's +0x1c resolver (guarded by its +0x18 handle and the bitmap at
 * +0x4c) or by f00[2] & 1, and after stop 2 bit 0 of the flag word mirrors
 * it.  The tail advances the program counter by three.
 *
 * 2.0/sp2 pin: docs/notes/func_0206B7D0.c.txt records a whole pass stuck at
 * 368 bytes against 380 under the project default dsi/1.1p1, diagnosed there
 * as the front end hoisting the `p->f14 ? p->f8e : 0` ternary above the field
 * stores.  It is not a source problem: this identical body is byte-exact
 * under ../2.0/sp2, the same front end its sibling func_0206B94C is pinned
 * to.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Sub0206B7D0 Sub0206B7D0;
typedef struct Obj0206B7D0 Obj0206B7D0;

struct Sub0206B7D0 {
    u8    pad00[0x18];
    void *f18;
    u32 (*f1c)(u32 *out, void *ctx, u32 id);
    u8    pad20[0x4c - 0x20];
    u32   f4c[1];
};

struct Obj0206B7D0 {
    u8   *f00;
    Sub0206B7D0 *f04;
    u32   f08;
    u32   f0c;
    u32   f10;
    void (*f14)(Obj0206B7D0 *);
    u8    pad18[0x8e - 0x18];
    u8    f8e;
    u8    pad8f[0xac - 0x8f];
    u8    fac;
    u8    padad[0xb8 - 0xad];
    u32  *fb8;
    u8    padbc[0x184 - 0xbc];
    u32   f184;
};

void func_0206B7D0(Obj0206B7D0 *p)
{
    if (!(p->f08 & 0x200)) {
        u32 b;
        u32 st;
        u32 flag;

        b = p->f00[1];
        p->fac = b;
        p->f08 |= 4;
        p->fb8 = &p->f184;
        st = p->f14 ? p->f8e : 0;

        if (st == 1) {
            p->f08 &= ~0x40;
            p->f14(p);
            st = p->f14 ? p->f8e : 0;
            flag = p->f08 & 0x40;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            Sub0206B7D0 *s = p->f04;
            if (s->f18 == 0
                || (s->f4c[b >> 5] & (1u << (b & 0x1f))) == 0
                || s->f1c(p->fb8, s->f18, b) == 0) {
                p->fb8[0] = p->f00[2] & 1;
            }
        }
        if (st == 2) {
            p->f08 &= ~0x40;
            p->f14(p);
            st = p->f14 ? p->f8e : 0;
            flag = p->f08 & 0x40;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            if (*p->fb8) {
                p->f08 |= 1;
            } else {
                p->f08 &= ~1;
            }
        }
        if (st == 3) {
            p->f08 &= ~0x40;
            p->f14(p);
        }
    }
    p->f00 += 3;
}
