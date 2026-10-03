/*
 * unit:     no
 * function: func_020651B8
 * address:  0x020651B8
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The actor object's third in-object callback (func_02065B74 stores it at
 * +0x20): applies the live actor's OAM overrides to one cell's OAM
 * attributes (GXOamAttr at +0x38 of the cell) and then dispatches the
 * actor vtable's +0x40 slot with the selected affine matrix as the stacked
 * fifth argument, the PART 2 matrix selection of
 * docs/families/cluster_02064B68.h.  The overrides: a palette remap through
 * func_02066740 / func_02063784 (the actor's +0x78 u16 table indexed by the
 * current colour parameter), then, keyed by the actor's +0x84 mask, bit 1
 * priority = +0x88, bit 2 colour parameter = +0x8a, bit 0x10 colour
 * parameter += +0x94, bit 4 mosaic = (+0x90 != 0), bit 8 OBJ mode = +0x8c
 * through the SDK's G2_SetOBJMode shape (unmasked mode << 10 into attr01,
 * colour parameter re-stored through attr2 as a halfword).
 *
 * Levers:
 *   - Compiler pin ../2.0/sp2 ("kept constants": the g_02147B88 pool word
 *     is reloaded before every mask test); 1.1p1 is 456 bytes, 413 out.
 *   - The priority / colour-parameter fields are u32 bitfields (ldr/bic/
 *     lsl/orr/str) while the palette index and the OBJ-mode path go through
 *     attr2 as a u16: the remap index is `(u16)((attr2 & 0xF000) >> 12)`,
 *     which is the image's lsl #4 / lsr #16 pair (without the cast: asr #12).
 *   - The image reads +0x84 TWICE on entry (the non-zero test, then the bit-1
 *     test): the bit-1 test is read through a volatile cast (else 4 short).
 *   - The OBJ-mode value +0x8c is read through a volatile cast of the actor
 *     pointer: that alone moves it from r0 to r1 (9 bytes out otherwise,
 *     which permuter hill could not move in 216 single mutations).
 *   - 0x02147D28 / 0x02147D2C are &g_02147D18[0].tx / .ty and 0x020A8200 is
 *     the scratch matrix inside g_020A81F8 (+8).
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_02147D18     0x02147D18  data  a4
 *   g_020A81F8     0x020A81F8  data  a4
 *   func_02066740  0x02066740  arm
 *   func_02063784  0x02063784  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            fx32;

typedef struct { fx32 m00, m01, m10, m11, tx, ty; } Mtx;

typedef union {
    u32 attr01;
    struct {
        u32 y:8;
        u32 rsMode:2;
        u32 objMode:2;
        u32 mosaic:1;
        u32 colorMode:1;
        u32 shape:2;
        u32 x:9;
        u32 rsParam:5;
        u32 size:2;
        u32 charNo:10;
        u32 priority:2;
        u32 cParam:4;
        u32 _2:16;
    };
    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 attr3;
    };
} OamAttr;

typedef void (*Fn40)(void *obj, void *vt, void *a1, void *a2, Mtx *m);

struct Vtbl {
    u8   pad_00[0x40];
    Fn40 f40;
};

struct Actor {
    u8           pad_00[0x74];
    struct Vtbl *vtbl;
    u8           pad_78[0x0c];
    u32          f84;
    u16          f88;
    u16          f8a;
    int          f8c;
    int          f90;
    u16          f94;
};

struct Manager {
    u8            pad_00[4];
    u32           unk_04;
    struct Actor *obj;
    u32           slot;
};

struct Scr {
    u8  pad_00[8];
    Mtx mtx;
};

struct Cell {
    u8      pad_00[0x38];
    OamAttr oam;
};

extern struct Manager g_02147B88;
extern Mtx            g_02147D18[];
extern struct Scr     g_020A81F8;

extern void *func_02066740(struct Actor *o);
extern int func_02063784(unsigned short *p, int i);

static inline int GetColorParam(const OamAttr *oam)
{
    return (oam->attr2 & 0xF000) >> 12;
}

static inline void SetObjMode(OamAttr *oam, int mode, int cParam)
{
    oam->attr01 = (oam->attr01 & ~0xC00) | (mode << 10);
    oam->attr2 = (u16)((oam->attr2 & ~0xF000) | (cParam << 12));
}

void func_020651B8(struct Cell *c, void *a1, void *a2)
{
    void *map;
    struct Actor *o;
    struct Vtbl *v;
    Mtx *m;
    u32 i;

    map = func_02066740(g_02147B88.obj);
    if (map != 0)
        c->oam.cParam = func_02063784(map, (u16)((c->oam.attr2 & 0xF000) >> 12));

    if (g_02147B88.obj->f84 != 0) {
        if (((volatile struct Actor *)g_02147B88.obj)->f84 & 1)
            c->oam.priority = g_02147B88.obj->f88;
        if (g_02147B88.obj->f84 & 2)
            c->oam.cParam = g_02147B88.obj->f8a;
        if (g_02147B88.obj->f84 & 0x10)
            c->oam.cParam = c->oam.cParam + g_02147B88.obj->f94;
        if (g_02147B88.obj->f84 & 4) {
            if (g_02147B88.obj->f90 != 0)
                c->oam.attr01 |= 0x1000;
            else
                c->oam.attr01 &= ~0x1000;
        }
        if (g_02147B88.obj->f84 & 8) {
            SetObjMode(&c->oam, ((volatile struct Actor *)g_02147B88.obj)->f8c, GetColorParam(&c->oam));
        }
    }

    o = g_02147B88.obj;
    v = o->vtbl;
    if (v->f40 == 0)
        return;

    if (g_02147B88.unk_04 == 0) {
        m = &g_02147D18[g_02147B88.slot];
    } else {
        g_020A81F8.mtx.tx = g_02147D18[g_02147B88.slot].tx;
        g_020A81F8.mtx.ty = g_02147D18[g_02147B88.slot].ty;
        m = &g_020A81F8.mtx;
    }

    v->f40(o, v, a1, a2, m);
}
