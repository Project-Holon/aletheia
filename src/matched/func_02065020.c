/*
 * unit:     no
 * function: func_02065020
 * address:  0x02065020
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
