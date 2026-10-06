/*
 * function: func_02091650
 * address:  0x02091650
 * packet:   pkt_0209159C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The commit half of the pair whose prepare half is func_020915C4: work out
 * the amount still to apply (f24 - f1c), and if there is one, publish it to
 * f28, pre-process it through func_02091594, run the object's f40 handler with
 * the same four arguments func_020915C4 uses, hand f28 back through the out
 * parameter, and fold the applied amount into f18 on success.  The trailing
 * func_0209159C and `return 0` are shared by both paths, which is why the
 * body's early exit is the loop-free `if (d != 0) { ... }` shape rather than a
 * `goto`.
 *
 * The handler is again a bare `blx ip` off a cast field; the f04 flag bit is
 * the same unequal-shift-pair test as in func_020915C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091650.c \
 *       --func func_02091650 --addr 0x02091650 --cc 1.1p1 --arm
 *   EXACT, 132 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   func_02091594  0x02091594  arm
 *   func_0209159C  0x0209159C  arm
 */

typedef unsigned int u32;

struct S02091650 {
    u32 f00;
    u32 f04;
    u32 pad08[4];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 pad30[3];
    u32 f3c;
    u32 f40;
    u32 pad44;
    u32 f48;
};

typedef u32 (*Fn02091650)(u32, u32, u32 *, u32);

struct S0209159C;
extern void func_0209159C(struct S0209159C *p);
extern void func_02091594(u32 a, u32 *b);

int func_02091650(struct S02091650 *p, u32 *a1)
{
    u32 d;
    u32 r;

    d = p->f24 - p->f1c;
    if (d != 0) {
        p->f28 = d;
        if (((p->f04 << 19) >> 31) == 0)
            func_02091594(p->f1c, &p->f28);
        r = ((Fn02091650)p->f40)(p->f00, p->f1c, &p->f28, p->f48);
        if (a1 != 0)
            *a1 = p->f28;
        if (r != 0)
            return r;
        p->f18 += p->f28;
    }
    func_0209159C((struct S0209159C *)p);
    return 0;
}
