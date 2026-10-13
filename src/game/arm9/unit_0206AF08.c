/*
 * file:     unit_0206AF08.c
 * unit:     yes
 * function: func_0206AF08, func_0206AF74, func_0206AFE4
 * address:  0x0206AF08
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   MIi_CpuCopy32     0x02082A90  arm
 *   FX_Div      0x0207C768  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Normalize     0x0207CCA4  arm
 */
struct Node0206AF08;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef void (*Cb0206AF08)(u32 a0, struct Node0206AF08 *n, u32 v);

struct Node0206AF08 {
    u32 pad00[3];
    Cb0206AF08 cb;
    struct Node0206AF08 *next;
    u32 pad14;
    u8  pad18;
    u8  count;
    u16 v[1];
};

typedef signed int s32;

typedef struct Node0206AFE4 Node0206AFE4;

struct Node0206AFE4 {
    u32   f00;
    s32   f04;
    u32   f08;
    void (*f0c)(void *out, Node0206AFE4 *self, u32 mode);
    Node0206AFE4 *f10;
    u8    pad14[0x19 - 0x14];
    u8    f19;
    u16   f1a[1];
};

typedef struct Acc0206AFE4 {
    u32 f00;
    s32 f04[3];
    s32 f10[3];
    s32 f1c[3];
    s32 f28[3];
    s32 f34[3];
    s32 f40[3];
    s32 f4c[3];
} Acc0206AFE4;

typedef struct Work0206AFE4 {
    u32 f00;
    s32 f04[3];
    s32 f10[3];
    s32 f1c[3];
    s32 f28[3];
    s32 f34[3];
    s32 f40[3];
    s32 f4c[3];
} Work0206AFE4;

extern void MIi_CpuClearFast(u32 val, void *dst, u32 len);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 len);
extern s32  FX_Div(s32 num, s32 den);
extern void VEC_CrossProduct(const s32 *a, const s32 *b, s32 *c);
extern void VEC_Normalize(const s32 *a, s32 *b);
int func_0206AF08(u32 a0, struct Node0206AF08 *n, u32 idx);
void func_0206AF74(volatile s32 *dst, s32 *src, s32 v, int flag);
int func_0206AFE4(Acc0206AFE4 *out, Node0206AFE4 *n, u32 idx);



int func_0206AF08(u32 a0, struct Node0206AF08 *n, u32 idx)
{
    int r = 0;

    while (n != 0) {
        if (idx < n->count) {
            u16 v = n->v[idx];

            if ((v & 0x300) == 0x100) {
                Cb0206AF08 cb = n->cb;

                if (cb != 0) {
                    cb(a0, n, v & 0xff);
                    r = 1;
                }
            }
        }
        n = n->next;
    }
    return r;
}



/*
 * Mixes two three-word vectors into dst: with `flag` set it just adds the
 * scalar v to each word, otherwise it accumulates the 12.12 fixed-point
 * product (v * src[i]) >> 12.
 *
 * `dst` must be spelled `volatile`: with a plain `s32 *` mwcc schedules the
 * two arms differently.  The plain-pointer spelling matches the `else` arm
 * exactly (ldr src, ldr dst, mul, add, str) but groups the `if` arm into
 * three hoisted loads, three adds and three stores; the volatile spelling
 * reproduces the original's strictly sequential ldr/add/str per word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AF74.c \
 *       --func func_0206AF74 --addr 0x0206AF74 --arm --cc 1.1p1
 */
void func_0206AF74(volatile s32 *dst, s32 *src, s32 v, int flag)
{
    if (flag) {
        dst[0] += v;
        dst[1] += v;
        dst[2] += v;
    } else {
        dst[0] += (v * src[0]) >> 12;
        dst[1] += (v * src[1]) >> 12;
        dst[2] += (v * src[2]) >> 12;
    }
}


/*
 * The WEIGHTED BLEND of the node list src/matched/func_0206AF08.c walks.
 * Each node contributes a 0x58-byte transform (position triple at +0x04,
 * two more triples at +0x10/+0x1c, two 3-vectors at +0x28/+0x34, another at
 * +0x40 and a scaled triple at +0x4c) weighted by its own +0x04 field,
 * clamped to 0x1000 (1.0 in 20.12) and normalised against the running total
 * through the hardware divider FX_Div.  Three shortcuts come first:
 * a single-node list dispatches straight through the node's +0x0c callback;
 * a zero total returns 0; and exactly one live contributor dispatches that
 * one node.  The tail re-orthonormalises the accumulated basis with
 * VEC_CrossProduct / VEC_Normalize, falling back to the FIRST contributor's
 * own vectors (saved into the `b`/`a` stack copies on the seen == 0 pass)
 * when an axis accumulated to zero.  The +0x4c triple is the only one whose
 * product is taken 64-bit (`smull` + `lsr #12` + `orr lsl #20` in the
 * image), which is what fixes the `(long long)` cast there against the plain
 * `mul`/`asr #12` of the +0x28/+0x34 arms.
 *
 * 2.0/sp2 pin, the docs/FRONTEND-PINS.md "repeated small constant takes a
 * callee-saved register" tell exactly: under dsi/1.1p1 this same source is
 * 1008 bytes, with 0x58 and 0xc hoisted into r4 and rematerialised as
 * `sub r0, r4, #0x59` / `mov r2, r4`; 2.0/sp2 rematerialises each literal at
 * its use and is byte-exact.
 *
 * Four spellings measured against the listing:
 *   - the single-node fast path must be NESTED ifs with a `return 0` per
 *     arm, not a chain of early-return guards: the guard chain predicates
 *     the epilogue (`addhs sp / movhs r0 / pophs`) where the original
 *     branches to three separate `mov r0,#0` epilogues.
 *   - `live` is declared AFTER `p`, which is what puts the node cursor in
 *     r2 and the counter in r3 rather than the other way round
 *     (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *   - `b` is declared before `a`, giving the later declaration the lower
 *     stack address (sp+0 for `a`, sp+0xc for `b`).
 *   - the `w.f00 & 2` arm adds the scalar to f28[0] and f34[1], the
 *     image's +0x28 and +0x38 stores.
 */
int func_0206AFE4(Acc0206AFE4 *out, Node0206AFE4 *n, u32 idx)
{
    Work0206AFE4 w;
    s32 b[3];
    s32 a[3];
    s32 total;
    int seen;
    Node0206AFE4 *last;
    Node0206AFE4 *p;
    int live;
    s32 wgt;
    u16 e;

    if (n == 0) {
        return 0;
    }
    if (n->f10 == 0) {
        if (idx < n->f19) {
            e = n->f1a[idx];
            if ((e & 0x300) == 0x100) {
                if (n->f0c == 0) {
                    return 0;
                }
                n->f0c(out, n, e & 0xff);
                return 1;
            }
            return 0;
        }
        return 0;
    }

    total = 0;
    live = 0;
    seen = 0;
    p = n;
    do {
        if (idx < p->f19 && (p->f1a[idx] & 0x300) == 0x100) {
            if (p->f04 > 0x1000) {
                total += 0x1000;
            } else if (p->f04 > 0) {
                total += p->f04;
            }
            last = p;
            live++;
        }
        p = p->f10;
    } while (p != 0);

    if (total == 0) {
        return 0;
    }
    if (live == 1) {
        e = last->f1a[idx];
        if (last->f0c == 0) {
            return 0;
        }
        last->f0c(out, last, e & 0xff);
        return 1;
    }

    MIi_CpuClearFast(0, out, 0x58);
    out->f00 = -1;

    p = n;
    do {
        if (idx < p->f19 && (p->f1a[idx] & 0x300) == 0x100
            && p->f04 > 0 && p->f0c != 0) {
            p->f0c(&w, p, p->f1a[idx] & 0xff);
            if (seen == 0) {
                MIi_CpuCopy32(w.f28, b, 0xc);
                MIi_CpuCopy32(w.f40, a, 0xc);
            }
            if (total == 0x1000) {
                wgt = p->f04;
            } else {
                wgt = FX_Div(p->f04, total);
            }
            func_0206AF74(out->f04, w.f04, wgt, w.f00 & 1);
            func_0206AF74(out->f10, w.f10, wgt, w.f00 & 8);
            func_0206AF74(out->f1c, w.f1c, wgt, w.f00 & 0x10);
            if (!(w.f00 & 4)) {
                out->f4c[0] += (s32)(((long long)wgt * w.f4c[0]) >> 12);
                out->f4c[1] += (s32)(((long long)wgt * w.f4c[1]) >> 12);
                out->f4c[2] += (s32)(((long long)wgt * w.f4c[2]) >> 12);
            }
            if (!(w.f00 & 2)) {
                out->f28[0] += (wgt * w.f28[0]) >> 12;
                out->f28[1] += (wgt * w.f28[1]) >> 12;
                out->f28[2] += (wgt * w.f28[2]) >> 12;
                out->f34[0] += (wgt * w.f34[0]) >> 12;
                out->f34[1] += (wgt * w.f34[1]) >> 12;
                out->f34[2] += (wgt * w.f34[2]) >> 12;
            } else {
                out->f28[0] += wgt;
                out->f34[1] += wgt;
            }
            out->f00 &= w.f00;
        }
        p = p->f10;
        seen++;
    } while (p != 0);

    VEC_CrossProduct(out->f28, out->f34, out->f40);
    if (out->f28[0] == 0 && out->f28[1] == 0 && out->f28[2] == 0) {
        MIi_CpuCopy32(b, out->f28, 0xc);
    } else {
        VEC_Normalize(out->f28, out->f28);
    }
    if (out->f40[0] == 0 && out->f40[1] == 0 && out->f40[2] == 0) {
        MIi_CpuCopy32(a, out->f40, 0xc);
    } else {
        VEC_Normalize(out->f40, out->f40);
    }
    VEC_CrossProduct(out->f40, out->f28, out->f34);
    return 1;
}
