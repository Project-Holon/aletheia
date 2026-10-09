/*
 * file:     unit_02064D70_p03.c
 * unit:     yes
 * function: func_02065020, func_02065134
 * address:  0x02065020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two in-object callbacks of the actor object (func_02065B74 stores them at
 * +0x18 and +0x1c). Both select the affine matrix with the PART 2 block of
 * docs/families/cluster_02064B68.h, written as an inline helper.
 *
 * The two functions only match with different spellings of that block, so
 * the file keeps two helpers: GetMtx (eq-first with a local) and GetMtxEarly
 * (else-first with early returns). Each is the only EXACT form for its own
 * function; one shared helper gives DIFF. They are most likely two distinct
 * inline helpers in the original source (guess: the names).
 *
 * symbols:
 *   g_02147B88  0x02147B88  data  a4
 *   g_02147D18  0x02147D18  data  a4
 *   g_020A81F8  0x020A81F8  data  a4
 */
typedef unsigned char u8;
typedef unsigned int  u32;
typedef int fx32;

typedef struct { fx32 m00, m01, m10, m11, tx, ty; } Mtx;

typedef int  (*Fn34)(void *a, Mtx *m, void *b);
typedef void (*Fn38)(void *a, void *b, void *c, Mtx *m);

struct Obj74 {
    u8   pad_00[0x34];
    Fn34 f34;
    Fn38 f38;
    Fn38 f3c;
};

struct Obj {
    u8            pad_00[0x74];
    struct Obj74 *f74;
};

struct Bank {
    u8          pad_00[4];
    int         f04;
    struct Obj *f08;
    u32         f0c;
};

struct Scr {
    u8  pad_00[8];
    Mtx mtx;
};

struct Host {
    u8  pad_00[0x30];
    u32 f30;
};

extern struct Bank g_02147B88;
extern Mtx         g_02147D18[];
extern struct Scr  g_020A81F8;

static inline Mtx *GetMtx(void)
{
    Mtx *m;

    if (g_02147B88.f04 == 0) {
        m = &g_02147D18[g_02147B88.f0c];
    } else {
        g_020A81F8.mtx.tx = g_02147D18[g_02147B88.f0c].tx;
        g_020A81F8.mtx.ty = g_02147D18[g_02147B88.f0c].ty;
        m = &g_020A81F8.mtx;
    }
    return m;
}

static inline Mtx *GetMtxEarly(void)
{
    if (g_02147B88.f04 != 0) {
        g_020A81F8.mtx.tx = g_02147D18[g_02147B88.f0c].tx;
        g_020A81F8.mtx.ty = g_02147D18[g_02147B88.f0c].ty;
        return &g_020A81F8.mtx;
    }
    return &g_02147D18[g_02147B88.f0c];
}

/*
 * First callback: runs the live actor vtable's +0x34 predicate with the
 * selected affine matrix, records its verdict in the host's +0x30 word (0
 * stops there), then dispatches the +0x38 slot with the matrix selected
 * afresh. The predicate is called (a1, matrix, vtbl). 0x02147D28 and
 * 0x02147D2C are &g_02147D18[0].tx / .ty and 0x020A8200 is the scratch
 * matrix at g_020A81F8+8.
 * EXACT under dsi/1.1p1; ../2.0/sp2 is 280 bytes (no predication).
 */
/*
 * The actor object's first in-object callback (func_02065B74 stores it at
 * +0x18): runs the live actor vtable's +0x34 predicate with the selected
 * affine matrix, records its verdict in the host's +0x30 word (0 stops
 * there), then dispatches the +0x38 slot with the matrix selected afresh.
 * The matrix selection is the PART 2 block of
 * docs/families/cluster_02064B68.h, written ONCE as an inline helper and
 * called at both sites.
 *
 * What closed it, after docs/notes/pkt_02065020.c.txt stalled at 35 out:
 *   - The +0x34 predicate is called (a1, matrix, vtbl): the matrix is in r1
 *     straight out of the selection (mlaeq r1 / ldr r1 = 0x020A8200) and
 *     the vtbl is moved into r2.  The note's (a1, vtbl, matrix) was the
 *     whole 35-byte residue.
 *   - 0x02147D28 / 0x02147D2C are &g_02147D18[0].tx / .ty and 0x020A8200 is
 *     the scratch matrix at g_020A81F8+8; with those declarations and the
 *     inline helper, the first selection reads the slot inside both arms
 *     and the second reads it once after the test, exactly as the image
 *     does, with no volatile casts.
 * EXACT under dsi/1.1p1; ../2.0/sp2 is 280 bytes (no predication).
 */
void func_02065020(struct Host *h, void *a1)
{
    struct Obj74 *v = g_02147B88.f08->f74;

    if (v->f34 != 0) {
        if (v->f34(a1, GetMtx(), v) == 0) {
            h->f30 = 0;
            return;
        }
        h->f30 = 1;
    }

    if (v->f38 == 0)
        return;

    v->f38(g_02147B88.f08, v, a1, GetMtx());
}

/*
 * Second callback: dispatches the live actor vtable's +0x3c slot as
 * (obj, vtbl, a1, matrix); a null slot returns at once. The eq-first
 * spelling is a register-allocation tie here (2 bytes out), so the
 * else-first helper is used.
 */
/*
 * The actor object's second in-object callback (func_02065B74 stores it at
 * +0x1c): dispatches the live actor vtable's +0x3c slot as
 * (obj, vtbl, a1, matrix); a null slot returns at once.
 * The matrix selection is the PART 2 block of
 * docs/families/cluster_02064B68.h as an inline helper, but written
 * ELSE-FIRST with early returns: if (f04 != 0) copy tx/ty and return the
 * scratch matrix, else return &g_02147D18[slot].  The eq-first spelling (the
 * one func_02065020 matches with) is a register-allocation tie here: 2 bytes
 * out (lr/r4) on func_02065134 and 31 out on func_020653A4, where whether
 * the two arms' slot reads land in the same register decides whether they
 * are merged above the test.  Neither the permuter (hill + anneal 2000, no
 * single mutation moves it) nor any other compiler build closed the
 * eq-first form; the else-first form is EXACT on the first compile.
 */
void func_02065134(void *a0, void *a1)
{
    struct Obj *o = g_02147B88.f08;
    struct Obj74 *v = o->f74;

    if (v->f3c == 0)
        return;

    v->f3c(o, v, a1, GetMtxEarly());
}
