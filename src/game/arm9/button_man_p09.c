/*
 * file:     button_man_p09.c
 * unit:     yes
 * function: func_02052FC8, func_02053044
 * address:  0x02052FC8
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
 *   func_02053044  0x02053044  arm
 *   func_0205312C  0x0205312C  arm
 *   func_02053D30  0x02053D30  arm
 *   func_02053E1C  0x02053E1C  arm
 *   func_02054718  0x02054718  arm
 *   func_02054DB8  0x02054DB8  arm
 *   func_02055B80  0x02055B80  arm
 */
struct Obj;
struct S;
struct SPLManager;
struct SPLParticle;
struct SPLTexture;
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

struct Obj {
    u32 pad0[11];
    void *f2c;
    u32 pad1[4];
    struct Blk *f40;
};

typedef void (*Fn)(struct Obj *, struct Node *);

extern void func_02053044(struct Obj *o);
extern void func_0205312C(struct Obj *o);
extern void func_02053D30(struct SPLTexture *tex);
extern void func_02053E1C(struct Obj *obj, struct S *s);
extern void func_02054718(struct Obj *obj, struct S *s);
extern void func_02054DB8(struct SPLManager *mgr, struct SPLParticle *ptcl);
extern void func_02055B80(struct Obj *obj, struct S *s);
void func_02052FC8(S02052FC8 *o);


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
void func_02053044(struct Obj *o)
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
        func_02053044((struct Obj *)o);
        if (v->b22)
            return;
        func_0205312C((struct Obj *)o);
        return;
    }
    if (v->b22 == 0)
        func_0205312C((struct Obj *)o);
    func_02053044((struct Obj *)o);
}
