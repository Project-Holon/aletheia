/*
 * function: CLACT_SetSurfaceCulling
 * address:  0x0204BE38
 * packet:   pkt_0204BE38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CullOam   0x0204C2C8  arm
 *
 * Culling on/off for a 0x48-stride element array (the same f98/f9c pair
 * CLACT_InitRenderer allocates): on != 0 installs CLACT_CullOam as each element's
 * +0x40 callback, on == 0 sets obj->f30 = 1 and clears the callbacks.  Reached
 * only through a pool word at 0x0204B0FC; the pool word 0x0204C2C8 resolves
 * sole-ref/code.
 *
 * Two levers, both needed: the non-zero arm first (`if (on != 0)`), and `i`
 * declared before `fn` (tools/permuter.py found the decl-order swap).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef void (*CullFn)(void);

struct Elem {
    u8 pad_00[0x40];
    CullFn fn;
    u8 pad_44[4];
};

struct Obj {
    u8 pad_00[0x30];
    u32 f30;
    u8 pad_34[0x64];
    struct Elem *f98;
    u32 f9c;
};

typedef signed int     s32;
struct Box;
struct Pair;
extern void CLACT_CullOam(struct Elem *e, struct Pair *p, s32 u2, s32 u3, struct Box *box);

void CLACT_SetSurfaceCulling(struct Obj *obj, int on)
{
    u32 i;
    CullFn fn;

    if (on != 0) {
        fn = (CullFn)CLACT_CullOam;
    } else {
        obj->f30 = 1;
        fn = 0;
    }
    for (i = 0; i < obj->f9c; i++) {
        obj->f98[i].fn = fn;
    }
}
