/*
 * function: SPL_EMITTER_FreeNodeToHeap
 * address:  0x02052A50
 * packet:   pkt_020528D0
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   SPL_EMITTER_AddVec  0x020582CC  arm
 *   SPL_EMITTER_UpdateNode  0x02058204  arm
 *   SPL_EMITTER_AddScaledVec  0x02058180  arm
 *   SPL_EMITTER_BuildFrame  0x020580A8  arm
 *   SPL_EMITTER_InterpTarget  0x02057F8C  arm
 *   SPL_EMITTER_LerpVec  0x02057EF8  arm
 *
 * The rig's resource binder: walk a packed blob `d` from byte 0x20 on.
 * First h->f30 = d->nrec records of 0x20 bytes (h->f28): each takes a
 * 0x58-byte block whose first word is a flag set; flags 8..11 and 16 each
 * bind an optional sub-block (0xc/0xc/8/0xc/0x14 bytes) to rec->f04..f14,
 * and flags 24..29 each add one {callback, data} entry to a table allocated
 * at rec->f18 (count at rec->f1c) with data sizes 8/8/0x10/4/8/0x10 and the
 * six callbacks 0x020582CC..0x02057EF8.  Then h->f32 = d->nrow material
 * rows of 0x14 bytes (h->f2c): row->res points at the next resource, the two
 * 4-bit size codes at res+4 bits 4..7 and 8..11 give 1 << (code + 3), and
 * the resource's own size word at +0x1c advances the cursor.
 *
 * Levers: the optional fills are if/else statements (a `?:` gives separate
 * zero stack slots per arm and reorders), the callback entry stores data,
 * then fn, then advances `off` (any other order if-converts the blocks and
 * loses 40 bytes), `rec = &h->f28[i]` is bound before the data store, and
 * the entry count is summed straight from the six bitfields, the later
 * tests reading the same fields (separate u32 locals give a r4/r5/r6
 * register cycle, 22 bytes out).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Flags {
    u32 lo   : 8;
    u32 b8   : 1;
    u32 b9   : 1;
    u32 b10  : 1;
    u32 b11  : 1;
    u32 b12  : 4;
    u32 b16  : 1;
    u32 b17  : 7;
    u32 b24  : 1;
    u32 b25  : 1;
    u32 b26  : 1;
    u32 b27  : 1;
    u32 b28  : 1;
    u32 b29  : 1;
    u32 b30  : 2;
};

struct Anim {
    void (*fn)(void);
    void *data;
};

struct Rec {
    struct Flags *data;  /* 0x00 */
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    struct Anim *anims;  /* 0x18 */
    u16 nanims;          /* 0x1c */
    u16 pad1e;
};

struct Res {
    u32 f00;
    u32 kind : 4;
    u32 w    : 4;
    u32 h    : 4;
    u32 hi   : 20;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 size;            /* 0x1c */
};

struct Row {
    struct Res *res;
    u32 tex_vram;
    u32 pltt_vram;
    u32 f0c;
    u16 w;
    u16 h;
};

struct Hdr {
    u32 f00;
    u32 f04;
    u16 nrec;
    u16 nrow;
};

typedef void *(*AllocFn)(u32 size);

struct Head {
    AllocFn alloc;       /* 0x00 */
    u32 pad04[9];
    struct Rec *f28;     /* 0x28 */
    struct Row *f2c;     /* 0x2c */
    u16 f30;
    u16 f32;
};

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct A;
struct B;
struct C;
struct Obj;
struct S;
struct Src;
extern void SPL_EMITTER_AddVec(struct Obj *o, void *s, int *dst);
extern void SPL_EMITTER_UpdateNode(struct Obj *o, struct Src *s, int *dst);
extern void SPL_EMITTER_AddScaledVec(struct A *a, struct B *b, volatile int *c);
extern void SPL_EMITTER_BuildFrame(struct Obj *o, u8 *dst);
extern void SPL_EMITTER_InterpTarget(struct A *a, struct S *s, int unused, struct C *c);
extern void SPL_EMITTER_LerpVec(struct A *a, struct B *b);

void SPL_EMITTER_FreeNodeToHeap(struct Head *h, struct Hdr *d)
{
    u32 off;
    int i;

    off = 0x20;
    h->f30 = d->nrec;
    h->f32 = d->nrow;
    h->f28 = h->alloc(h->f30 * sizeof(struct Rec));
    MI_CpuFill8(h->f28, 0, h->f30 * sizeof(struct Rec));

    for (i = 0; i < h->f30; i++) {
        struct Rec *rec;
        struct Flags fl;

        rec = &h->f28[i];
        rec->data = (struct Flags *)((char *)d + off);
        fl = *rec->data;
        off += 0x58;

        if (fl.b8) { rec->f04 = (char *)d + off; off += 0xc; } else { rec->f04 = 0; }
        if (fl.b9) { rec->f08 = (char *)d + off; off += 0xc; } else { rec->f08 = 0; }
        if (fl.b10) { rec->f0c = (char *)d + off; off += 8; } else { rec->f0c = 0; }
        if (fl.b11) { rec->f10 = (char *)d + off; off += 0xc; } else { rec->f10 = 0; }
        if (fl.b16) { rec->f14 = (char *)d + off; off += 0x14; } else { rec->f14 = 0; }

        rec->nanims = fl.b24 + fl.b25 + fl.b26 + fl.b27 + fl.b28 + fl.b29;
        if (rec->nanims != 0) {
            struct Anim *p;
            rec->anims = h->alloc(rec->nanims * sizeof(struct Anim));
            p = rec->anims;
            if (fl.b24) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_AddVec; off += 8; p++; }
            if (fl.b25) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_UpdateNode; off += 8; p++; }
            if (fl.b26) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_AddScaledVec; off += 0x10; p++; }
            if (fl.b27) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_BuildFrame; off += 4; p++; }
            if (fl.b28) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_InterpTarget; off += 8; p++; }
            if (fl.b29) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_LerpVec; off += 0x10; }
        } else {
            rec->anims = 0;
        }
    }

    h->f2c = h->alloc(h->f32 * sizeof(struct Row));
    MI_CpuFill8(h->f2c, 0, h->f32 * sizeof(struct Row));

    for (i = 0; i < h->f32; i++) {
        struct Row *row = &h->f2c[i];
        struct Res *res = (struct Res *)((char *)d + off);
        row->res = res;
        row->w = 1 << (res->w + 3);
        row->h = 1 << (res->h + 3);
        row->f0c = ((u32 *)res)[1];
        off += res->size;
    }
}
