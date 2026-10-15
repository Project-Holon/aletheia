/*
 * function: SPL_EMITTER_AllocPlttVramList
 * address:  0x020528D0
 * packet:   pkt_020528D0
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt       0x0207FA40  arm
 *   GX_EndLoadTexPltt    0x0207FADC  arm
 *
 * The texture-palette upload pass: GX_BeginLoadTexPltt, then for every row
 * of o->f2c with a non-zero resource size, allocate through the caller's
 * callback (first argument is the SIZE word, second is kind == 2) and upload
 * with GX_LoadTexPltt; the handle (0 when skipped) goes to row+0x08.  Then
 * GX_EndLoadTexPltt; always returns 1.  Twin of SPL_EMITTER_AllocTexVramList (textures).
 *
 * What closed it (wave 9): array indexing o->f2c[i] and "kind == 2 ? 1 : 0"
 * instead of hand-written offset/one/zero locals (the wave-7 note's 8-byte
 * register swap was the compiler's strength reduction disagreeing with the
 * hand-reduced loop).
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Res {
    u32 f00;
    u32 kind : 4;
    u32 f04_hi : 28;
    u32 f08;
    u32 f0c;
    u32 f10;
};

struct Row {
    struct Res *res;
    u32 tex_vram;
    u32 pltt_vram;
    u32 pad[2];
};

struct Obj {
    u32 pad0[11];
    struct Row *f2c;
    u16 pad1[1];
    u16 f32;
};

typedef u32 (*Alloc)(u32, u32);

extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(void *dst, u32 a, u32 b);
extern void GX_EndLoadTexPltt(void);

int SPL_EMITTER_AllocPlttVramList(struct Obj *o, Alloc alloc)
{
    int i;

    GX_BeginLoadTexPltt();

    for (i = 0; i < o->f32; i++) {
        struct Row *r = &o->f2c[i];
        struct Res *res = r->res;
        u32 v = 0;

        if (res->f10 != 0) {
            v = alloc(res->f10, res->kind == 2 ? 1 : 0);
            GX_LoadTexPltt((char *)r->res + res->f0c, v, res->f10);
        }
        r->pltt_vram = v;
    }

    GX_EndLoadTexPltt();
    return 1;
}
