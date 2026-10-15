/*
 * function: SPL_EMITTER_UpdateSubB
 * address:  0x0205312C
 * packet:   pkt_02053044
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SPL_EMITTER_Noop  0x02053D2C  arm
 *   SPL_EMITTER_SetTextureParam  0x02053D30  arm
 *   SPL_EMITTER_UpdateFrameMain  0x0205429C  arm
 *   SPL_EMITTER_UpdateFrameA68  0x02054A68  arm
 *   SPL_EMITTER_UpdateParticleMotion  0x02055498  arm
 *   SPL_EMITTER_UpdateFrame  0x02055FD4  arm
 *
 * The sibling of SPL_EMITTER_UpdateSubX in the same file: the same per-frame dispatch
 * over a render list, but on the block's OTHER list (+0x08 rather than +0x14)
 * and with a disjoint handler set.  Unconditionally calls SPL_EMITTER_SetTextureParam on the
 * 0x14-byte row the descriptor's byte at +0x47 selects, picks the per-node
 * handler from bits 4..5 of the descriptor's first word (the `lsl #26` /
 * `lsr #30` pair), and picks a SECOND per-node function from bit 11 of the
 * same word (`lsl #20` / `lsrs #31`, materialised as the `ldrne`/`ldreq`
 * pair at 0x020531B8/0x020531BC), then walks the list calling both.
 * Cases 3 and 4 share SPL_EMITTER_UpdateFrameMain, exactly as cases 3/4 do in the sibling.
 *
 * The descriptor's first word is READ TWICE, once for the switch field and
 * once for the bit-11 test (`ldr r0, [r5]` at 0x02053158 and again at
 * 0x020531A8).  A plain second read of the same field is CSE'd away and
 * costs the whole bit-11 block its shape; the load has to be spelled
 * `*(volatile u32 *)&d->flags` at both sites to survive, the same tell as
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md.
 *
 * COMPILER PIN: ../1.2/sp2, the interworking-conflict tell, same as the
 * sibling and same as this region's pkt_020526A8 family: `blx r5` at
 * 0x020531DC (`35 ff 2f e1`) and `blx r4` at 0x020531E8 (`34 ff 2f e1`)
 * beside the ARMv4T-style return `pop {r4, r5, r6, r7, r8, lr}` / `bx lr` at
 * 0x020531F8/0x020531FC (`f0 41 bd e8` / `1e ff 2f e1`), which no dsi front
 * end emits under -proc arm946e.
 *
 * BLOCKER: capped at MATCH for lack of an outside witness, not for codegen;
 * 236 bytes, ZERO concrete mismatches.  Three of seven relocation sites are
 * ABS32 pool words at +0x00D4/D8/E8 naming SPL_EMITTER_UpdateFrame, SPL_EMITTER_UpdateParticleMotion and
 * SPL_EMITTER_Noop, and this function's own pool at 0x02053200 is the only place
 * in the image those three words appear.  SPL_EMITTER_UpdateFrameA68 and SPL_EMITTER_UpdateFrameMain
 * already resolve `matched x1`; filing any one of the remaining three
 * promotes this file toward EXACT with no change to the C.  SPL_EMITTER_UpdateParticleMotion and
 * SPL_EMITTER_UpdateFrame are unfiled 3D-rig rows (docs/FRONTEND-PINS.md); SPL_EMITTER_Noop
 * is an unlabelled leaf four bytes below SPL_EMITTER_SetTextureParam.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/SPL_EMITTER_UpdateSubB.c \
 *       --func SPL_EMITTER_UpdateSubB --addr 0x0205312C --cc ../1.2/sp2 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Node {
    struct Node *next;
    u32 pad[10];
    u8 f2c;
};

struct Desc {
    u32 flags;
    u8 pad[0x43];
    u8 f47;
};

struct Sub {
    struct Desc *f00;
};

struct Blk {
    u32 pad0[2];
    struct Node *f08;
    u32 pad1[5];
    struct Sub *f20;
};

struct Obj {
    u32 pad0[11];
    void *f2c;
    u32 pad1[4];
    struct Blk *f40;
};

typedef void (*Fn)(struct Obj *, struct Node *);
typedef void (*Fn1)(void *);

extern void SPL_EMITTER_Noop(void);
struct S;
struct SPLManager;
struct SPLParticle;
struct SPLTexture;
extern void SPL_EMITTER_SetTextureParam(struct SPLTexture *tex);
extern void SPL_EMITTER_UpdateFrameMain(struct Obj *obj, struct S *s);
extern void SPL_EMITTER_UpdateFrameA68(struct Obj *obj, struct S *s);
extern void SPL_EMITTER_UpdateParticleMotion(struct SPLManager *mgr, struct SPLParticle *ptcl);
extern void SPL_EMITTER_UpdateFrame(struct Obj *obj, struct S *s);

void SPL_EMITTER_UpdateSubB(struct Obj *o)
{
    struct Blk *b = o->f40;
    struct Desc *d = b->f20->f00;
    Fn fn = 0;
    Fn1 g;
    struct Node *n;

    SPL_EMITTER_SetTextureParam((struct SPLTexture *)((char *)o->f2c + d->f47 * 0x14));

    switch ((u32)(*(volatile u32 *)&d->flags << 26) >> 30) {
    case 0:
        fn = (Fn)SPL_EMITTER_UpdateFrame;
        break;
    case 1:
        fn = (Fn)SPL_EMITTER_UpdateParticleMotion;
        break;
    case 2:
        fn = (Fn)SPL_EMITTER_UpdateFrameA68;
        break;
    case 3:
        fn = (Fn)SPL_EMITTER_UpdateFrameMain;
        break;
    case 4:
        fn = (Fn)SPL_EMITTER_UpdateFrameMain;
        break;
    }

    if ((*(volatile u32 *)&d->flags << 20) >> 31)
        g = (Fn1)SPL_EMITTER_SetTextureParam;
    else
        g = (Fn1)SPL_EMITTER_Noop;

    n = b->f08;
    if (n == 0)
        return;

    do {
        g((char *)o->f2c + n->f2c * 0x14);
        fn(o, n);
        n = n->next;
    } while (n != 0);
}
