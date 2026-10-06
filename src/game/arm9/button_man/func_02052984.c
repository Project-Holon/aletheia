/*
 * function: func_02052984
 * address:  0x02052984
 * packet:   pkt_020528D0
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex       0x0207F7FC  arm
 *   GX_EndLoadTex    0x0207F9B4  arm
 *
 * The texture-upload pass of the rig's material rows: GX_BeginLoadTex, then
 * for every row of o->f2c (o->f32 rows of 0x14 bytes) either share another
 * row's texture handle (resource flag bit 17 set; the row index is the 8-bit
 * field at bits 18..25) or allocate through the caller's callback and upload
 * with GX_LoadTex, then GX_EndLoadTex.  Always returns 1.  Twin of
 * func_020528D0 (palettes).
 *
 * What closed it (wave 9): the natural spelling.  The byte-offset induction
 * variable and the two stack slots holding 1 and 0 are the compiler's own
 * strength reduction of o->f2c[i] and of "kind == 5 ? 1 : 0"; writing them
 * as locals (the wave-7 note) left a register swap no permutation moved.
 * The flags word is three declared bitfields (kind:4, shared at bit 17,
 * idx:8 at bits 18..25), and the row pointer is taken before the resource.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Res {
    u32 f00;
    u32 kind : 4;
    u32 b4 : 13;
    u32 shared : 1;
    u32 idx : 8;
    u32 hi : 6;
    void *f08;
};

struct Row {
    struct Res *res;
    u32 vram;
    u32 pad[3];
};

struct Obj {
    u32 pad0[11];
    struct Row *f2c;
    u16 pad1[1];
    u16 f32;
};

typedef u32 (*Alloc)(void *, u32);

extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *dst, u32 a, void *b);
extern void GX_EndLoadTex(void);

int func_02052984(struct Obj *o, Alloc alloc)
{
    int i;

    GX_BeginLoadTex();

    for (i = 0; i < o->f32; i++) {
        struct Row *r = &o->f2c[i];
        struct Res *res = r->res;

        if (res->shared) {
            r->vram = o->f2c[res->idx].vram;
        } else {
            u32 v = alloc(res->f08, res->kind == 5 ? 1 : 0);
            GX_LoadTex((char *)r->res + 0x20, v, res->f08);
            r->vram = v;
        }
    }

    GX_EndLoadTex();
    return 1;
}
