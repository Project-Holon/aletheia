/*
 * file:     button_man_p03.c
 * unit:     yes
 * function: func_02052984, func_02052A50, func_02052DC8, func_02052F58, func_02052F90, func_02052FC8, func_02053044
 * address:  0x02052984
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
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex       0x0207F7FC  arm
 *   GX_EndLoadTex    0x0207F9B4  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020582CC  0x020582CC  arm
 *   func_02058204  0x02058204  arm
 *   func_02058180  0x02058180  arm
 *   func_020580A8  0x020580A8  arm
 *   func_02057F8C  0x02057F8C  arm
 *   func_02057EF8  0x02057EF8  arm
 *   func_020583CC  0x020583CC  arm
 *   g_020A8148  0x020A8148  data
 *   g_020A8140  0x020A8140  data
 *   func_0205312C  0x0205312C  arm
 *   func_02053D30  0x02053D30  arm
 *   func_02053E1C  0x02053E1C  arm
 *   func_02054718  0x02054718  arm
 *   func_02054DB8  0x02054DB8  arm
 *   func_02055B80  0x02055B80  arm
 */
struct Obj_02052FC8;
struct S;
struct SPLManager;
struct SPLParticle;
struct SPLTexture;
struct List;
struct Node;
struct A;
struct B;
struct C;
struct Src;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    u8  pad0[0x40];
    u32 *f40;
} S02052FC8;

typedef struct {
    unsigned f0   : 21;
    unsigned b21  : 1;
    unsigned b22  : 1;
    unsigned rest : 9;
} B02052FC8;

typedef unsigned short u16;

struct Node {
    struct Node *next;
};

struct Desc {
    u16 flags;
};

struct Sub {
    void *f00;
    u32 pad[4];
    struct Desc *f14;
};

struct Blk {
    u32 pad0[5];
    struct Node *f14;
    u32 pad1[2];
    struct Sub *f20;
};

struct Obj_02052FC8 {
    u32 pad0[11];
    void *f2c;
    u32 pad1[4];
    struct Blk *f40;
};

typedef void (*Fn)(struct Obj_02052FC8 *, struct Node *);

typedef void *(*AllocFn)(u32 size);

struct Head_02052DC8 {
    AllocFn alloc;       /* 0x00 */
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u16 f32;
    u16 f34;
    u16 f36;
    u32 b0  : 6;
    u32 b6  : 6;
    u32 b12 : 6;
    u32 b18 : 6;
    u32 b24 : 1;
    u32 b25 : 7;
    u32 f3c;
    u32 f40;
    u32 f44;
    u16 f48;
    u16 f4a;
};

struct Node9C { u8 b[0x9c]; };

struct Node44 { u8 b[0x44]; };

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

struct Res_02052A50 {
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

struct Row_02052A50 {
    struct Res_02052A50 *res;
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

struct Head_02052984 {
    AllocFn alloc;       /* 0x00 */
    u32 pad04[9];
    struct Rec *f28;     /* 0x28 */
    struct Row_02052A50 *f2c;     /* 0x2c */
    u16 f30;
    u16 f32;
};

struct Res_02052984 {
    u32 f00;
    u32 kind : 4;
    u32 b4 : 13;
    u32 shared : 1;
    u32 idx : 8;
    u32 hi : 6;
    void *f08;
};

struct Row_02052984 {
    struct Res_02052984 *res;
    u32 vram;
    u32 pad[3];
};

struct Obj_02052984 {
    u32 pad0[11];
    struct Row_02052984 *f2c;
    u16 pad1[1];
    u16 f32;
};

typedef u32 (*Alloc)(void *, u32);

extern void func_0205312C(struct Obj_02052FC8 *o);
extern void func_02053D30(struct SPLTexture *tex);
extern void func_02053E1C(struct Obj_02052FC8 *obj, struct S *s);
extern void func_02054718(struct Obj_02052FC8 *obj, struct S *s);
extern void func_02054DB8(struct SPLManager *mgr, struct SPLParticle *ptcl);
extern void func_02055B80(struct Obj_02052FC8 *obj, struct S *s);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_020583CC(volatile struct List *list, volatile struct Node *node);
extern void func_020582CC(struct Obj_02052984 *o, void *s, int *dst);
extern void func_02058204(struct Obj_02052984 *o, struct Src *s, int *dst);
extern void func_02058180(struct A *a, struct B *b, volatile int *c);
extern void func_020580A8(struct Obj_02052984 *o, u8 *dst);
extern void func_02057F8C(struct A *a, struct S *s, int unused, struct C *c);
extern void func_02057EF8(struct A *a, struct B *b);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *dst, u32 a, void *b);
extern void GX_EndLoadTex(void);
void func_02053044(struct Obj_02052FC8 *o);
void func_02052FC8(S02052FC8 *o);
int func_02052F90(u32 a0, u32 a1);
int func_02052F58(u32 a0, u32 a1);
struct Head_02052DC8 *func_02052DC8(AllocFn alloc, u16 n1, u16 n2, u16 a3, u16 a4, u16 a5);
void func_02052A50(struct Head_02052984 *h, struct Hdr *d);
int func_02052984(struct Obj_02052984 *o, Alloc alloc);



/*
 * Per-frame dispatch for one render list.  Reads the object's block at +0x40,
 * bails when bit 16 of the first word of the sub-block's *f00 chain is clear,
 * calls func_02053D30 on the 0x14-byte row the descriptor's byte at +0x0f
 * selects, then picks a per-node handler from a 2-bit field of the
 * descriptor's halfword (bits 8..9, spelled as the shift pair `lsl #23` /
 * `lsr #30`), and walks the singly linked list at block+0x14 calling it.
 *
 * Cases 3 and 4 share func_02053E1C, and the `cmp r0, #4` says the switch has
 * exactly five arms, none of them empty; a sixth arm makes the table one entry
 * longer and shifts every branch.
 *
 * COMPILER PIN: ../1.2/sp2, on two tells at once, both documented in
 * docs/FRONTEND-PINS.md and both already carried by this region's
 * pkt_020526A8 family (func_020525A0.c, func_02052634.c, func_020528A8.c):
 *   - the interworking conflict, `blx r4` at 0x02053100 (`34 ff 2f e1`)
 *     beside the ARMv4T-style return `pop {r4, r5, r6, r7, lr}` / `bx lr` at
 *     0x02053114/0x02053118 (`f0 40 bd e8` / `1e ff 2f e1`); under
 *     -proc arm946e no dsi front end emits that pair, it emits `pop {..., pc}`;
 *   - the frame-padding tell, `sub sp, sp, #4` at 0x02053048 (`04 d0 4d e2`)
 *     where 1.1p1 pads the five-register frame with a dead `push {r3}` and
 *     gives `push {r3, r4, r5, r6, r7, lr}` at +0000.
 * Under 1.1p1 -O4,p the same C is 208 bytes against the original's 232, 161
 * concrete bytes out (all three epilogues one instruction short); under
 * ../2.0/sp2 it is 204 bytes and 161 out.  Under the pin it is 232 bytes with
 * ZERO concrete mismatches.
 *
 * Three of the five relocation sites are ABS32 pool words at +0x00D8/DC/E4
 * naming func_02055B80, func_02054DB8 and func_02053E1C.  Each is an unfiled
 * 3D-rig row (see docs/FRONTEND-PINS.md, "The 3D rig unit"), so neither the
 * `matched` class nor `literal` has a witness: this function's own pool at
 * 0x0205311C is the only place in the image those words appear, and the
 * sibling at 0x0205312C carries a DISJOINT handler set (0x02055FD4,
 * 0x02055498, 0x02054A68, 0x0205429C), so it cannot attest them either.
 * Filing any one of the three (func_02055B80 is the highest-value) promotes
 * this file toward EXACT with no change to the C.  func_02054718 already
 * resolves `matched x1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02053044.c \
 *       --func func_02053044 --addr 0x02053044 --cc ../1.2/sp2 --arm
 */
void func_02053044(struct Obj_02052FC8 *o)
{
    struct Blk *b = o->f40;
    struct Sub *s = b->f20;
    Fn fn = 0;
    struct Node *n;

    if ((((u32 *)s->f00)[0] << 15) >> 31 ? 0 : 1)
        return;

    func_02053D30((struct SPLTexture *)((char *)o->f2c + ((u8 *)s->f14)[0xf] * 0x14));

    switch ((u32)(s->f14->flags << 23) >> 30) {
    case 0:
        fn = (Fn)func_02055B80;
        break;
    case 1:
        fn = (Fn)func_02054DB8;
        break;
    case 2:
        fn = (Fn)func_02054718;
        break;
    case 3:
        fn = (Fn)func_02053E1C;
        break;
    case 4:
        fn = (Fn)func_02053E1C;
        break;
    }

    n = b->f14;
    if (n == 0)
        return;

    do {
        fn(o, n);
        n = n->next;
    } while (n != 0);
}



/*
 * Blocking class: label.  Both callees, 0x02053044 and 0x0205312C, are
 * reached only from the two call sites inside this function, so neither has a
 * witness outside the compared range and all four PC24 fields stay
 * wildcarded (0x02052FC8 is the last function of the packet before them).
 * Every concrete byte matches under the packet's 1.2 pin; both callees are
 * still-open rows of pkt_020526A8, and filing either one EXACT would move
 * this to EXACT through the `matched` class.
 *
 * The two branches are bit 21 and bit 22 of *v, and they must be written as a
 * 21/1/1/9 bitfield struct: the spelled-out `(*v << 10) >> 31` form loads the
 * word into the wrong scratch register (r2 where the image uses r1, and the
 * in-place `lsl r1, r1, #9` of the second test becomes a move), a six-byte
 * residue that the bitfield declaration removes.  See
 * docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02052FC8.c \
 *       --func func_02052FC8 --addr 0x02052FC8 --arm --cc ../1.2/sp2
 */
void func_02052FC8(S02052FC8 *o)
{
    B02052FC8 *v = (B02052FC8 *)((u32 **)o->f40[8])[0];

    if (v->b21) {
        func_02053044((struct Obj_02052FC8 *)o);
        if (v->b22)
            return;
        func_0205312C((struct Obj_02052FC8 *)o);
        return;
    }
    if (v->b22 == 0)
        func_0205312C((struct Obj_02052FC8 *)o);
    func_02053044((struct Obj_02052FC8 *)o);
}




extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);




extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);




/*
 * Twin of src/matched/func_02052F58.c: same twelve instructions and the same
 * two pool words by position, differing only in the global function pointer
 * it calls (0x020A8140 against 0x020A8148).  Carries the same per-file pin
 * for the same measured tells (register `blx r3` beside an ARMv4T
 * `ldm sp!, {lr}; bx lr` return, and `sub sp, sp, #4` where 1.1p1 pads with a
 * dead `push {r3}`).
 *
 * Evidence recorded in docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052F90.c \
 *       --func func_02052F90 --addr 0x02052F90 --arm --cc ../1.2/sp2
 */
int func_02052F90(u32 a0, u32 a1)
{
    return (g_020A8140(a0, a1, 0) & 0xffff) << 3;
}




/*
 * Calls the routine held in the global function pointer at 0x020A8148 with
 * (a0, a1, 0) and returns (result & 0xffff) << 3.  The 8-byte frame is
 * push {lr} plus the AAPCS alignment word.
 *
 * Built by the 1.2 front end, on two measured tells at once: the image has a
 * register `blx r3` beside an ARMv4T return `ldm sp!, {lr}; bx lr`, a pair no
 * dsi build emits, and the frame is `sub sp, sp, #4` where 1.1p1 pads with a
 * dead `push {r3}`.  Under 1.1p1 the 16-bit mask also folds into a shift pair
 * (`lsl r0,r0,#0x10; lsr r0,r0,#0xd`) where the image ANDs with a pooled
 * 0xffff; ../1.2/sp2 reproduces all of it.  Measured, same packet as
 * src/matched/func_020525A0.c (pinned for the frame tell).
 *
 * Evidence recorded in docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052F58.c \
 *       --func func_02052F58 --addr 0x02052F58 --arm --cc ../1.2/sp2
 */
int func_02052F58(u32 a0, u32 a1)
{
    return (g_020A8148(a0, a1, 0) & 0xffff) << 3;
}




/*
 * The rig constructor: allocate and zero the 0x4c-byte Head_02052DC8 through the
 * caller's allocator, record the two pool sizes (+0x34, +0x36), pack the
 * 6-bit fields of the +0x38 word (b0 = a4, b6 = a5, b12 = b0, b18 = a3,
 * b24 and b25..31 cleared, one read-modify-write per field under 1.2), clear
 * the three list headers and the counters, then allocate n1 nodes of 0x9c
 * bytes pushed onto the recycle list at +0x10 and n2 records of 0x44 bytes
 * pushed onto the list at +0x1c.  Returns the Head_02052DC8.  Caller 0x02050D88 passes
 * every scalar argument truncated to u16.
 *
 * Closed by indexing: `&p[i]` over a 0x9c-byte element type rather than a
 * hand-advanced `char *` (8 bytes out, a p/i register swap, otherwise).
 */
/*
 * The rig constructor: allocate and zero the 0x4c-byte Head through the
 * caller's allocator, record the two pool sizes (+0x34, +0x36), pack the
 * 6-bit fields of the +0x38 word (b0 = a4, b6 = a5, b12 = b0, b18 = a3,
 * b24 and b25..31 cleared, one read-modify-write per field under 1.2), clear
 * the three list headers and the counters, then allocate n1 nodes of 0x9c
 * bytes pushed onto the recycle list at +0x10 and n2 records of 0x44 bytes
 * pushed onto the list at +0x1c.  Returns the Head.  Caller 0x02050D88 passes
 * every scalar argument truncated to u16.
 *
 * Closed by indexing: `&p[i]` over a 0x9c-byte element type rather than a
 * hand-advanced `char *` (8 bytes out, a p/i register swap, otherwise).
 */
struct Head_02052DC8 *func_02052DC8(AllocFn alloc, u16 n1, u16 n2, u16 a3, u16 a4, u16 a5)
{
    struct Head_02052DC8 *h;
    struct Node9C *p;
    struct Node44 *q;
    int i;

    h = alloc(sizeof(struct Head_02052DC8));
    MI_CpuFill8(h, 0, sizeof(struct Head_02052DC8));
    h->f34 = n1;
    h->f36 = n2;
    h->b0 = a4;
    h->b6 = a5;
    h->b12 = h->b0;
    h->b18 = a3;
    h->b24 = 0;
    h->b25 = 0;
    h->alloc = alloc;
    h->f08 = 0;
    h->f14 = 0;
    h->f20 = 0;
    h->f04 = 0;
    h->f10 = 0;
    h->f1c = 0;
    h->f3c = 0;
    h->f48 = 0;

    p = alloc(n1 * sizeof(struct Node9C));
    MI_CpuFill8(p, 0, n1 * sizeof(struct Node9C));
    for (i = 0; i < n1; i++)
        func_020583CC((volatile struct List *)(&h->f10), (volatile struct Node *)(&p[i]));

    q = alloc(n2 * sizeof(struct Node44));
    MI_CpuFill8(q, 0, n2 * sizeof(struct Node44));
    for (i = 0; i < n2; i++)
        func_020583CC((volatile struct List *)(&h->f1c), (volatile struct Node *)(&q[i]));

    h->f28 = 0;
    h->f2c = 0;
    h->f30 = h->f32 = 0;
    return h;
}




/*
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
void func_02052A50(struct Head_02052984 *h, struct Hdr *d)
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
            if (fl.b24) { p->data = (char *)d + off; p->fn = (void (*)(void))func_020582CC; off += 8; p++; }
            if (fl.b25) { p->data = (char *)d + off; p->fn = (void (*)(void))func_02058204; off += 8; p++; }
            if (fl.b26) { p->data = (char *)d + off; p->fn = (void (*)(void))func_02058180; off += 0x10; p++; }
            if (fl.b27) { p->data = (char *)d + off; p->fn = (void (*)(void))func_020580A8; off += 4; p++; }
            if (fl.b28) { p->data = (char *)d + off; p->fn = (void (*)(void))func_02057F8C; off += 8; p++; }
            if (fl.b29) { p->data = (char *)d + off; p->fn = (void (*)(void))func_02057EF8; off += 0x10; }
        } else {
            rec->anims = 0;
        }
    }

    h->f2c = h->alloc(h->f32 * sizeof(struct Row_02052A50));
    MI_CpuFill8(h->f2c, 0, h->f32 * sizeof(struct Row_02052A50));

    for (i = 0; i < h->f32; i++) {
        struct Row_02052A50 *row = &h->f2c[i];
        struct Res_02052A50 *res = (struct Res_02052A50 *)((char *)d + off);
        row->res = res;
        row->w = 1 << (res->w + 3);
        row->h = 1 << (res->h + 3);
        row->f0c = ((u32 *)res)[1];
        off += res->size;
    }
}




/*
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
int func_02052984(struct Obj_02052984 *o, Alloc alloc)
{
    int i;

    GX_BeginLoadTex();

    for (i = 0; i < o->f32; i++) {
        struct Row_02052984 *r = &o->f2c[i];
        struct Res_02052984 *res = r->res;

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
