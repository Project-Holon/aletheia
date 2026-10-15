/*
 * function: __flush_buffer
 * address:  0x02091650
 * packet:   pkt_0209159C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The commit half of the pair whose prepare half is __load_buffer: work out
 * the amount still to apply (f24 - f1c), and if there is one, publish it to
 * f28, pre-process it through MSL_C_LIB_NopBufferHookA, run the object's f40 handler with
 * the same four arguments __load_buffer uses, hand f28 back through the out
 * parameter, and fold the applied amount into f18 on success.  The trailing
 * __prep_buffer and `return 0` are shared by both paths, which is why the
 * body's early exit is the loop-free `if (d != 0) { ... }` shape rather than a
 * `goto`.
 *
 * The handler is again a bare `blx ip` off a cast field; the f04 flag bit is
 * the same unequal-shift-pair test as in __load_buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__flush_buffer.c \
 *       --func __flush_buffer --addr 0x02091650 --cc 1.1p1 --arm
 *   EXACT, 132 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   MSL_C_LIB_NopBufferHookA  0x02091594  arm
 *   __prep_buffer  0x0209159C  arm
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
extern void __prep_buffer(struct S0209159C *p);
extern void MSL_C_LIB_NopBufferHookA(int a, void *b);

int __flush_buffer(struct S02091650 *p, u32 *a1)
{
    u32 d;
    u32 r;

    d = p->f24 - p->f1c;
    if (d != 0) {
        p->f28 = d;
        if (((p->f04 << 19) >> 31) == 0)
            MSL_C_LIB_NopBufferHookA(p->f1c, &p->f28);
        r = ((Fn02091650)p->f40)(p->f00, p->f1c, &p->f28, p->f48);
        if (a1 != 0)
            *a1 = p->f28;
        if (r != 0)
            return r;
        p->f18 += p->f28;
    }
    __prep_buffer((struct S0209159C *)p);
    return 0;
}
