/*
 * function: func_0209159C
 * address:  0x0209159C
 * packet:   pkt_0209159C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Three field moves on the object, in source order and nothing else:
 * `p->f24 = p->f1c; p->f28 = p->f20 - (p->f18 & p->f2c); p->f34 = p->f18;`.
 *
 * The load order (0x18, 0x2c, 0x1c, 0x20) is the scheduler hoisting the
 * second statement's two loads above the first statement's store, and the
 * register numbering ([r2, r1, ip, r3] for the four loads) follows from the
 * object being a struct: reading the fields through a `struct S *` keeps the
 * word loads independent, and the whole function is then a straight line with
 * no prologue at all.  No relocation sites, so the 40 bytes are compared
 * byte for byte with nothing wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209159C.c \
 *       --func func_0209159C --addr 0x0209159C --cc 1.1p1 --arm
 *   EXACT, 40 bytes, no relocation sites.
 */

typedef unsigned int u32;

struct S0209159C {
    u32 pad00[6];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 pad30;
    u32 f34;
};

void func_0209159C(struct S0209159C *p)
{
    p->f24 = p->f1c;
    p->f28 = p->f20 - (p->f18 & p->f2c);
    p->f34 = p->f18;
}
