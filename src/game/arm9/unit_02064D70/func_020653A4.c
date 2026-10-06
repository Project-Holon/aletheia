/*
 * unit:     no
 * function: func_020653A4
 * address:  0x020653A4
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The actor object's fourth in-object callback (func_02065B74 stores it at
 * +0x24): dispatches the live actor vtable's +0x44 slot as
 * (obj, vtbl, a1, a2, matrix), the matrix going on the stack; a null slot
 * returns at once.
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

typedef void (*Fn)(void *a, void *b, void *c, void *d, Mtx *m);

struct Obj74 {
    u8 pad_00[0x44];
    Fn f44;
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

extern struct Bank g_02147B88;
extern Mtx         g_02147D18[];
extern struct Scr  g_020A81F8;

static inline Mtx *GetMtx(void)
{
    if (g_02147B88.f04 != 0) {
        g_020A81F8.mtx.tx = g_02147D18[g_02147B88.f0c].tx;
        g_020A81F8.mtx.ty = g_02147D18[g_02147B88.f0c].ty;
        return &g_020A81F8.mtx;
    }
    return &g_02147D18[g_02147B88.f0c];
}

void func_020653A4(void *a0, void *a1, void *a2)
{
    struct Obj *o = g_02147B88.f08;
    struct Obj74 *v = o->f74;

    if (v->f44 == 0)
        return;

    v->f44(o, v, a1, a2, GetMtx());
}
