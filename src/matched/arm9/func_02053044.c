/*
 * function: func_02053044
 * address:  0x02053044
 * packet:   pkt_02053044
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02053D30  0x02053D30  arm
 *   func_02053E1C  0x02053E1C  arm
 *   func_02054718  0x02054718  arm
 *   func_02054DB8  0x02054DB8  arm
 *   func_02055B80  0x02055B80  arm
 *
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
 * BLOCKER: capped at MATCH for lack of an outside witness, not for codegen.
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern void func_02053D30(void *p);
extern void func_02053E1C(struct Obj *, struct Node *);
extern void func_02054718(struct Obj *, struct Node *);
extern void func_02054DB8(struct Obj *, struct Node *);
extern void func_02055B80(struct Obj *, struct Node *);

void func_02053044(struct Obj *o)
{
    struct Blk *b = o->f40;
    struct Sub *s = b->f20;
    Fn fn = 0;
    struct Node *n;

    if ((((u32 *)s->f00)[0] << 15) >> 31 ? 0 : 1)
        return;

    func_02053D30((char *)o->f2c + ((u8 *)s->f14)[0xf] * 0x14);

    switch ((u32)(s->f14->flags << 23) >> 30) {
    case 0:
        fn = func_02055B80;
        break;
    case 1:
        fn = func_02054DB8;
        break;
    case 2:
        fn = func_02054718;
        break;
    case 3:
        fn = func_02053E1C;
        break;
    case 4:
        fn = func_02053E1C;
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
