/*
 * function: func_0201CEE0
 * address:  0x0201CEE0
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_020439A0  0x020439A0  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201C974  0x0201C974  thumb
 *   sub_0201CEB8   0x0201CEB8  thumb
 *   sub_0201D110   0x0201D110  thumb
 *
 * The per-frame task callback that func_0201CD10 installs for a printsys
 * text record (the 0x50-byte object, struct PrintCtx at +0x34).  State 0
 * either scrolls the window up by at most four lines (flag bit 1) or, once
 * the wait counter at +0x1e is spent, prints up to f1b/f1d glyphs through
 * func_0201C974, handling 0xFFFF (end: state 2), 0xFFFE (line break) and
 * the 0xF000/0xBE control block (sub_0201D110).  State 1 waits on flag
 * bit 2 and then clears or scrolls the window.
 *
 * Shape facts, each measured against the bytes:
 *  - The flag byte at +0x22 is a struct of 1-bit fields.  Reads through
 *    the bitfield give the lsls/lsrs pairs off ONE cached ldrb; writes
 *    through the same bitfield reload the byte each time.  Spelled with
 *    `((u8 *)p)[0x22]` masks the tests fold to `tst` and the writes reuse
 *    the cached byte.
 *  - The two early exits are `goto end`, not `return`: they land on the
 *    function's LAST epilogue through a branch island, as a `break` would
 *    (docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *  - The glyph loop is `i = 0; if (i < n) { ...; do { } while (i < n); }`
 *    with the dead-store pair `ctx = p; ctx = &p->ctx;` in the guarded
 *    preheader (docs/idioms/a-dead-store-to-a-spilled-local-survives-when-
 *    the-second-assignment-recomputes.md).  A `for` loop puts the stores
 *    before the guard and duplicates the test.
 *  - The dispatch is a switch on the loaded halfword, and the control-code
 *    helper takes that VALUE: its own `== 0xF000` test then reuses the
 *    switch's compare, which is the dead `bne` at 0x0201D01E.  Given the
 *    pointer it reloads the halfword and is eight bytes long.
 *  - `case 1: default:` share one arm in the inner mode switch, which is
 *    why the image has `cmp r0, #1` followed by an unconditional `b`.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct PrintCtx {
    s16   unk00;
    s16   unk02;
    s32   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

struct Rec {
    u32  state;        /* 0x00 */
    u32  mode;         /* 0x04 */
    u32  f08;          /* 0x08 */
    u32  win;          /* 0x0c */
    void *task;        /* 0x10 */
    u16 *cur;          /* 0x14 */
    u8   f18;
    u8   f19;
    u8   f1a;
    u8   f1b;
    u8   f1c;
    u8   f1d;
    u8   wait;         /* 0x1e */
    u8   scroll;       /* 0x1f */
    u8   color;        /* 0x20 */
    u8   cbres;        /* 0x21 */
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 rest : 3;
    } flags;           /* 0x22 */
    u8   pad23;
    u8 (*cb)(u32);     /* 0x24 */
    u32  f28;
    u32  f2c;
    u32  cbarg;        /* 0x30 */
    struct PrintCtx ctx; /* 0x34 */
};

extern u32   func_020437DC(u32 win);
extern u32   func_020437E4(u32 win);
extern void  func_020439A0(u32 src, u32 dst, u32 a2, u32 a3, u32 a4, u32 a5,
                           u32 a6, u32 a7, u32 a8);
extern void  func_02043AF4(u32 win, u32 x, s16 y, u32 w, u32 h, u32 c);
extern void  func_02043B5C(u32 win, u32 c);
struct Descriptor;
extern void  func_02045334(struct Descriptor *a);
extern u16  *func_0201C974(struct PrintCtx *c, u16 *p, u32 f);
extern void  sub_0201CEB8(struct Rec *p);
extern void  sub_0201D110(struct Rec *p);

static inline u32 CtrlCode(u16 c, const u16 *p)
{
    if (c == 0xF000)
        return (u8)(p[1] >> 8);
    return 0xFF;
}

void func_0201CEE0(void *task, struct Rec *p)
{
    s32 n;
    s32 i;
    u32 w;
    s32 h;
    struct PrintCtx *ctx;
    u16 c;

    if (p->cb != 0 && p->cbres != 0) {
        p->cbres = p->cb(p->cbarg);
        if (p->cbres != 0)
            goto end;
        p->cbarg = p->f2c;
    }

    if (p->flags.b0)
        goto end;

    switch (p->state) {
    case 0:
        if (p->flags.b1) {
            if (p->scroll < 0x10) {
                u16 k = 4;
                if (p->scroll + 4 > 0x10)
                    k = 0x10 - p->scroll;
                p->scroll += (u8)k;
                w = func_020437DC(p->win);
                h = func_020437E4(p->win) - k;
                func_020439A0(p->win, p->win, 0, k, 0, 0, w, h, 0xFFFF);
                func_02043AF4(p->win, 0, h, w, k, p->color);
                func_02045334((struct Descriptor *)p->f08);
                return;
            }
            p->ctx.unk00 = p->ctx.unk04;
            p->ctx.unk02 = 0x10;
            p->flags.b1 = 0;
            return;
        }
        if (p->wait == 0) {
            if (p->flags.b3)
                n = p->f1d;
            else
                n = p->f1b;
            if (p->flags.b4) {
                sub_0201CEB8(p);
                p->flags.b4 = 0;
            }
            i = 0;
            if (i < n) {
                ctx = (struct PrintCtx *)p;
                ctx = &p->ctx;
                do {
                    c = *p->cur;
                    switch (c) {
                    case 0xFFFF:
                        p->state = 2;
                        break;
                    case 0xF000:
                        if (CtrlCode(c, p->cur) == 0xBE) {
                            sub_0201D110(p);
                            if (p->cb != 0) {
                                p->cbres = p->cb(p->cbarg);
                                if (p->cbres != 0)
                                    i = n;
                                else
                                    p->cbarg = p->f2c;
                            }
                            if (p->state != 0 || p->wait != 0)
                                i = n;
                            break;
                        }
                    default:
                        p->cur = func_0201C974(ctx, p->cur, 0);
                        c = *p->cur;
                        if (c == 0xFFFF) {
                            p->state = 2;
                        } else if (c != 0xFFFE) {
                            if (p->flags.b3)
                                p->wait = p->f1c;
                            else
                                p->wait = p->f1a;
                        }
                        func_02045334((struct Descriptor *)p->f08);
                        if (p->cb != 0) {
                            p->cbres = p->cb(p->cbarg);
                            if (p->cbres != 0)
                                i = n;
                            else
                                p->cbarg = p->f2c;
                        }
                        break;
                    }
                    i++;
                } while (i < n);
            }
        } else {
            p->wait--;
        }
        return;
    case 1:
        if (p->flags.b2) {
            switch (p->mode) {
            case 0:
                p->flags.b1 = 1;
                p->state = 0;
                return;
            case 1:
            default:
                func_02043B5C(p->win, p->color);
                p->state = 0;
                return;
            }
        }
        return;
    }
end:
    ;
}
