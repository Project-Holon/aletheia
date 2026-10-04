/*
 * function: func_0204D18C
 * address:  0x0204D18C
 * packet:   pkt_0204D18C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02066AE0  0x02066AE0  arm
 *   func_020627D8  0x020627D8  arm
 *   func_020637B4  0x020637B4  arm
 *   func_020642C8  0x020642C8  arm
 *
 * Record builder in clact.c.  Wave 15 (register-tie lane): the last 10
 * bytes (the image sinks `mov sb, r0` above the two a->f0c/a->f10 loads)
 * close with `const struct A *a`.  The read-only source pointer lets the
 * parameter copy of p be scheduled before the loads, freeing r0 for the
 * stmib pair {r0, r1}.  The rest is the 2026-09-22 source from
 * docs/notes/pkt_0204D18C.func_0204D224.c.txt: the nested t1/t0 block
 * (descending loads) for the stmib, and `two - 3` for the -1 argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D18C.c \
 *       --func func_0204D18C --addr 0x0204D18C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x64 - 0x0c];
    u32 f64;
};

struct A {
    u32 f00;
    u32 f04;
    u8  pad_08[4];
    u32 f0c;
    u32 f10;
    u8  pad_14[8];
    u32 f1c;
};

struct R {
    u8  pad_00[0x10];
    u32 f10;
    u32 f14;
};

extern int func_02066AE0(void);
struct AnimBank;
struct AnimSequence;
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern int func_020637B4(int *p, int i);
extern void func_020642C8(void *p, u32 a, u32 b, u32 c,
                          u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);

void func_0204D18C(struct P *p, const struct A *a)
{
    u32 zero = 0;
    u32 two;
    u32 h0, h1, h2;
    struct R *r;

    {
        u32 t1 = a->f10;
        u32 t0 = a->f0c;
        p->f04 = t0;
        p->f08 = t1;
    }
    p->f64 = func_02066AE0();
    r = (struct R *)a->f1c;
    h0 = (u32)func_020627D8((struct AnimBank *)p->f08, zero);
    h1 = func_020637B4((int *)a->f04, 1);
    two = 2;
    h2 = func_020637B4((int *)a->f04, two);
    func_020642C8((u8 *)p + 0xc, h0, p->f04, p->f64,
                  two - 3, h1, h2, r->f14, zero, r->f10);
}

