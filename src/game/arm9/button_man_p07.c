/*
 * file:     button_man_p07.c
 * unit:     yes
 * function: func_020528BC, func_020528D0
 * address:  0x020528BC
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02052984  0x02052984  arm
 *   func_02052F90  0x02052F90  arm
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt       0x0207FA40  arm
 *   GX_EndLoadTexPltt    0x0207FADC  arm
 */
typedef unsigned int u32;

typedef unsigned short u16;

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

extern void func_02052984(u32 a0, void *cb);
extern int func_02052F90(u32 a0, u32 a1);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(void *dst, u32 a, u32 b);
extern void GX_EndLoadTexPltt(void);
void func_020528BC(u32 a0);


/*
 * The texture-palette upload pass: GX_BeginLoadTexPltt, then for every row
 * of o->f2c with a non-zero resource size, allocate through the caller's
 * callback (first argument is the SIZE word, second is kind == 2) and upload
 * with GX_LoadTexPltt; the handle (0 when skipped) goes to row+0x08.  Then
 * GX_EndLoadTexPltt; always returns 1.  Twin of func_02052984 (textures).
 *
 * What closed it (wave 9): array indexing o->f2c[i] and "kind == 2 ? 1 : 0"
 * instead of hand-written offset/one/zero locals (the wave-7 note's 8-byte
 * register swap was the compiler's strength reduction disagreeing with the
 * hand-reduced loop).
 */
int func_020528D0(struct Obj *o, Alloc alloc)
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


/*
 * Twin of src/matched/func_020528A8.c, same twelve bytes by position: forward
 * r0 to 0x02052984 with the address of func_02052F90 as the second argument.
 * Same 1.2 pin and same tail-call schedule tell.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/func_02052F90.c is in the manifest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528BC.c \
 *       --func func_020528BC --addr 0x020528BC --arm --cc ../1.2/sp2
 */
void func_020528BC(u32 a0)
{
    func_02052984(a0, (void *)func_02052F90);
}
