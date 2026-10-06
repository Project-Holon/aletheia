/*
 * file:     gf_font_p01.c
 * unit:     yes
 * function: func_0201CEE0, func_0201D110, func_0201D26C, func_0201D2C8, func_0201D304, func_0201D33C, func_0201D37C, func_0201D42C, func_0201D478, func_0201D4BC, func_0201D528, func_0201D5C4, func_0201D5CC, func_0201D5F4, func_0201D60C, func_0201D658, func_0201D670, func_0201D688, func_0201D69C, func_0201D6B8, func_0201D6C4, func_0201D6D8, func_0201D768, func_0201D7C4, func_0201D7EC, func_0201D83C, func_0201D854
 * address:  0x0201CEE0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02013020  0x02013020  thumb
 *   func_02013050  0x02013050  thumb
 *   sub_0201CDF4   0x0201CDF4  thumb
 *   sub_0201DC6C  0x0201DC6C  thumb
 *   sub_02045A90  0x02045A90  arm
 *   sub_0204581C  0x0204581C  arm
 *   sub_02045AFC  0x02045AFC  arm
 *   sub_0201DC80  0x0201DC80  thumb
 *   func_0201D69C  0x0201D69C  thumb
 *   func_0201D768  0x0201D768  thumb
 *   func_0201D7C4  0x0201D7C4  thumb
 *   func_02045A90  0x02045A90  arm
 *   memcpy         0x02082D44  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201D854 0x0201D854 thumb
 *   func_0201DA00 0x0201DA00 thumb
 *   lbl_020A7358  0x020A7358 data
 *   func_0201DADC  0x0201DADC  thumb
 *   func_0201D9C8  0x0201D9C8  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201D854_File  0x020A7358  data
 *   func_0201DC88       0x0201DC88  thumb
 *   func_0201DD58       0x0201DD58  thumb
 *   func_020494F4       0x020494F4  arm
 *   func_020493D4       0x020493D4  arm
 *   sub_0204944C        0x0204944C  arm
 */
struct Bmp;
struct CharBuf;
struct Descriptor;
struct Font;
struct U16Vec;
struct PrintSys;
struct Ring;
struct ArcFile;
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

struct StrObj {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

struct Ring {
    u16 head;
    u16 tail;
    u16 size;
};

typedef struct {
    u8  pad00[4];
    u16 f04;
    u8  pad06[0x10 - 6];
    void *f10;
    u32   f14;
} Blk;

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    u32 unk08;
    u32 unk0C;
    void *unk10;
    void *unk14;
    u8  buf[4];
};

struct GfFont {
    char pad_00[0x50];
    void *field_50;
    int field_54;
};

struct Font {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void  func_02045334(struct Descriptor *a);
extern u16  *func_0201C974(struct PrintCtx *c, u16 *p, u32 f);
extern void  sub_0201CEB8(struct Rec *p);
extern void  sub_0201D110(struct Rec *p);
extern signed char func_02013020(void);
extern signed char func_02013050(void);
extern void sub_0201CDF4(s32 v, u8 *out);
extern u32 sub_0201DC6C(struct Font *p, u16 ch);
extern u16 *sub_02045A90(struct U16Vec *vec);
extern void sub_0204581C(struct U16Vec *vec);
extern void sub_02045AFC(struct U16Vec *vec, u16 value);
extern u32 sub_0201DC80(struct Font *p);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u32 func_0201DC6C(struct Font *p, u16 ch);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern u16 func_020458F8(struct U16Vec *vec);
u32 sub_0201D26C(u16 *p, void *font, u32 spacing, u16 **next);
u32 func_0201D478(void *s);
u32 func_0201D4BC(void *s, u8 v);
u32 func_0201D528(void *s, u8 b, void *c, u32 d);
u32 func_0201D5C4(void);
u32 func_0201D5CC(const u16 *p);
u32 func_0201D5F4(const u16 *p);
void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
u32 func_0201D658(const u16 *p);
u32 func_0201D670(const u16 *p, u32 i);
u16 *func_0201D688(u16 *p);
u32 func_0201D69C(void *s);
u32 func_0201D6B8(void *s);
extern void *func_0201D768(struct Ring *ring, const u8 *src, u16 len, u16 unit);
extern void *func_0201D7C4(struct PrintSys *p, void *q);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0201D854(struct Font *f, int resid, u32 flag, u32 heap);
extern void func_0201DA00(struct Font *f, u32 fmt, u32 heap);
extern void func_0201DADC(struct Font *f);
extern void func_0201D9C8(struct Font *p);
extern u32 func_020307B0(void *p);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void func_020494F4(struct ArcFile *arc, u32 member, u32 *out);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern u32   func_0201DB20(struct Font *f, u16 ch);
extern u8 func_0201DC88(u8 *obj, u32 id);
extern u32 func_0201DD58(struct Font *p);
struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
u32 func_0201D83C(void *ptr);
void func_0201D6D8(Blk *p, void *b, void *c);
extern const char lbl_020A7358[];
extern const char func_0201D854_File[];



static inline u32 CtrlCode(u16 c, const u16 *p)
{
    if (c == 0xF000)
        return (u8)(p[1] >> 8);
    return 0xFF;
}



/*
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
 *    with `ctx = &p->ctx;` in the guarded preheader.  A `for` loop puts
 *    the store before the guard and duplicates the test.
 *  - The dispatch is a switch on the loaded halfword, and the control-code
 *    helper takes that VALUE: its own `== 0xF000` test then reuses the
 *    switch's compare, which is the dead `bne` at 0x0201D01E.  Given the
 *    pointer it reloads the halfword and is eight bytes long.
 *  - `case 1: default:` share one arm in the inner mode switch, which is
 *    why the image has `cmp r0, #1` followed by an unconditional `b`.
 *
 * note 2026-10-05: removed the stand-in first store of the pair
 * `ctx = (struct PrintCtx *)p; ctx = &p->ctx;`. The single
 * `ctx = &p->ctx;` is EXACT in --lang c99 and --lang c.
 */
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
                w = func_020437DC((const struct Bmp *)p->win);
                h = func_020437E4((const struct Bmp *)p->win) - k;
                func_020439A0((struct Bmp *)p->win, (struct Bmp *)p->win, 0, k, 0, 0, w, h, 0xFFFF);
                func_02043AF4((struct Bmp *)p->win, 0, (s16)h, w, k, p->color);
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
                func_02043B5C((struct CharBuf *)p->win, p->color);
                p->state = 0;
                return;
            }
        }
        return;
    }
end:
    ;
}


static inline u32 KB(const u16 *p)
{
    return (u8)p[1];
}


static inline u16 CtrlKind(u16 c, const u16 *p)
{
    if (c == 0xF000)
        return KB(p);
    return 0xFFFF;
}


static inline u16 CtrlArg(u16 c, const u16 *p, u32 i)
{
    if (c == 0xF000)
        return *(p + i + 3);
    return 0;
}


static inline u16 CtrlArgP(const u16 *p, u32 i)
{
    u16 c = p[0];
    if (c == 0xF000)
        return *(p + i + 3);
    return 0;
}


static inline u16 *CtrlSkip(u16 *p)
{
    if (p[0] == 0xF000)
        return p + 3 + p[2];
    return p;
}


static inline void SetMode(struct Rec *r, u32 m)
{
    r->state = 1;
    r->mode = m;
}

/*
 * Applies the 0xF000 control block the text record's cursor is parked on
 * and steps the cursor past it (struct Rec as in func_0201CEE0.c).  The
 * block's kind (low byte of its second halfword) is a dense 0..9 switch:
 * 0/1 pause for a key (mode 0 or 1) and home the pen, 2 sets the wait,
 * 3/4/9 set the per-glyph delay pair at +0x1a/+0x1b (9 through the
 * speed setting func_02013020 / func_02013050 and sub_0201CDF4), 5/6/7
 * set the callback argument, 8 clears the window.  A pause also skips a
 * 0xFFFE that directly follows the block.
 *
 * Shape facts measured against the bytes:
 *  - `*cur` is a named local: it is the LEFT operand of the header test
 *    (docs/idioms/cmp-operand-order-names-the-temporary.md), and the
 *    per-case argument reads reuse it.  Only case 6's second read goes
 *    back through p->cur, after the +0x2c store.
 *  - The kind helper returns u32 `(u8)p[1]` into a u16 return, which is
 *    the (u8) then (u16) shift-pair stack in the header arm only.
 *  - state/mode are written by an inline taking the record as its own
 *    parameter; written in line, mwcc hoists the flag-byte load above
 *    those two stores and cases 0/1 stop cross-jumping (20 bytes).
 *  - In the shared tail the pen x copy precedes the pen y clear.
 */
void sub_0201D110(struct Rec *p)
{
    u32 skip;
    u8 buf[2];
    u16 *cur;
    u16 c;

    cur = p->cur;
    c = cur[0];
    skip = 0;
    switch (CtrlKind(c, cur)) {
    case 0:
        skip = 1;
        SetMode(p, 0);
        p->scroll = 0;
        ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~4u;
        p->ctx.unk00 = p->ctx.unk04;
        p->ctx.unk02 = 0;
        break;
    case 1:
        skip = 1;
        SetMode(p, 1);
        p->scroll = 0;
        ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~4u;
        p->ctx.unk00 = p->ctx.unk04;
        p->ctx.unk02 = 0;
        break;
    case 2:
        p->wait = CtrlArg(c, cur, 0);
        break;
    case 3:
        p->f1a = CtrlArg(c, cur, 0);
        break;
    case 4:
        p->f1a = p->f18;
        break;
    case 9:
        switch ((u8)CtrlArg(c, cur, 0)) {
        case 0:
        default:
            buf[0] = p->f18;
            buf[1] = p->f19;
            break;
        case 1:
            sub_0201CDF4(func_02013020(), buf);
            break;
        case 2:
            sub_0201CDF4(func_02013050(), buf);
            break;
        }
        p->f1a = buf[0];
        p->f1b = buf[1];
        break;
    case 5:
        p->cbarg = CtrlArg(c, cur, 0);
        break;
    case 6:
        p->f2c = CtrlArg(c, cur, 0);
        p->cbarg = CtrlArgP(p->cur, 0);
        break;
    case 7:
        p->f2c = p->f28;
        p->cbarg = p->f28;
        break;
    case 8:
        func_02043B5C((struct CharBuf *)p->win, p->color);
        break;
    }

    cur = CtrlSkip(p->cur);
    p->cur = cur;
    if (skip != 0 && *cur == 0xFFFE)
        p->cur = cur + 1;
}


/*
 * printsys.c: measures one line of a string object.  It sums the per-glyph
 * advance sub_0201DC6C returns plus a fixed inter-character spacing until it
 * hits the line break 0xFFFE or the terminator 0xFFFF, steps over embedded
 * 0xF000 blocks (three header halfwords plus the payload count at +4), and,
 * when the fourth argument is non-NULL, writes back the cursor for the next
 * line (past the break, if that is what stopped it).
 *
 * 0xFFFF is not pooled: the compiler keeps the pooled 0xFFFE in a register and
 * derives the terminator as `adds r6, r0, #1`.
 *
 * The repeated `c == 0xF000` test is the source's own: the block skip re-tests
 * the code word it was selected by, and the compiler keeps the second branch
 * while folding away the second compare.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D26C.c
 *       --func sub_0201D26C --addr 0x0201D26C --cc 1.1p1 --thumb
 */
u32 sub_0201D26C(u16 *p, void *font, u32 spacing, u16 **next)
{
    u32 sum;
    u16 c;

    sum = 0;
    while ((c = *p) != 0xFFFF && c != 0xFFFE) {
        if (c != 0xF000) {
            sum += spacing + sub_0201DC6C(font, c);
            p++;
        } else {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        }
    }
    if (next != 0) {
        if (c == 0xFFFE) {
            p++;
        }
        *next = p;
    }
    return sum;
}


/*
 * printsys.c: counts the lines of a string object, i.e. one plus the number
 * of 0xFFFE line-break codes before the 0xFFFF terminator.  0xF000 opens an
 * embedded block whose halfword length sits at +4, so the walker steps over
 * three header halfwords plus that many payload halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D2C8.c
 *       --func sub_0201D2C8 --addr 0x0201D2C8 --cc 1.1p1 --thumb
 */
u32 sub_0201D2C8(struct StrObj *s)
{
    u16 *p;
    u32 n;
    u16 c;

    p = sub_02045A90((struct U16Vec *)s);
    c = *p;
    n = 1;
    while (c != 0xFFFF) {
        if (c != 0xF000) {
            if (c == 0xFFFE) {
                n++;
            }
            p++;
        } else {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        }
        c = *p;
    }
    return n;
}


/*
 * printsys.c: the width of the widest line of a multi-line string.  It walks
 * the string object's halfword payload one line at a time with sub_0201D26C,
 * which measures one line and writes the cursor for the next one back through
 * its fourth argument, and keeps the running maximum.  0xFFFF is the string
 * terminator (the same sentinel sub_0201C8BC stops on).
 *
 * The cursor is a local whose address is taken, so it lives on the stack and
 * the loop test reloads it every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D304.c
 *       --func sub_0201D304 --addr 0x0201D304 --cc 1.1p1 --thumb
 */
u32 sub_0201D304(struct StrObj *s, u32 a, u32 b)
{
    u16 *p;
    u32 best;
    u32 w;

    best = 0;
    p = sub_02045A90((struct U16Vec *)s);
    while (*p != 0xFFFF) {
        w = sub_0201D26C(p, (void *)a, b, &p);
        if (w > best) {
            best = w;
        }
    }
    return best;
}


/*
 * printsys.c: fills a caller-supplied array with the pixel width of each line
 * of a string object, at most `max` of them, and returns how many were
 * written.  sub_0201D26C measures one line and hands back the cursor for the
 * next through its fourth argument; the cursor is a stack local because its
 * address is taken.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D33C.c
 *       --func sub_0201D33C --addr 0x0201D33C --cc 1.1p1 --thumb
 */
u32 sub_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max)
{
    u16 *p;
    u32 i;

    p = sub_02045A90((struct U16Vec *)s);
    i = 0;
    while (i < max) {
        if (*p == 0xFFFF) {
            break;
        }
        out[i] = sub_0201D26C(p, (void *)a, b, &p);
        i++;
    }
    return i;
}


/*
 * printsys.c: copies line `n` of a string object into a second, freshly
 * cleared string object and returns whether the line existed.  Phase one skips
 * n line breaks, phase two appends the line a halfword at a time and closes it
 * with the 0xFFFF terminator.  Embedded 0xF000 blocks are skipped in phase one
 * and copied verbatim in phase two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D37C.c
 *       --func sub_0201D37C --addr 0x0201D37C --cc 1.1p1 --thumb
 */
u32 sub_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n)
{
    u16 *end;
    u16 *p;
    u16 c;

    p = sub_02045A90((struct U16Vec *)src);
    sub_0204581C((struct U16Vec *)dst);
    while (n != 0) {
        while ((c = *p) != 0xFFFF && c != 0xFFFE) {
            if (c != 0xF000) {
                p++;
            } else {
                if (c == 0xF000) {
                    p = p + 3 + p[2];
                }
            }
        }
        n--;
        if (c == 0xFFFF) {
            break;
        }
        p++;
    }
    if (n == 0 && *p != 0xFFFF) {
        while ((c = *p) != 0xFFFF && c != 0xFFFE) {
            if (c != 0xF000) {
                sub_02045AFC((struct U16Vec *)dst, *p++);
            } else {
                if (c == 0xF000) {
                    end = p + 3;
                end = end + p[2];
                } else {
                    end = p;
                }
                while (p < end) {
                    sub_02045AFC((struct U16Vec *)dst, *p++);
                }
            }
        }
        sub_02045AFC((struct U16Vec *)dst, 0xFFFF);
        return 1;
    }
    return 0;
}


/*
 * printsys.c: the pixel height of a string object, i.e. its line count times
 * the font's line height (sub_0201DC80).  The line counter is a u16, so the
 * increment carries the halfword truncation pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D42C.c
 *       --func sub_0201D42C --addr 0x0201D42C --cc 1.1p1 --thumb
 */
u32 sub_0201D42C(struct StrObj *s, void *font)
{
    u16 *p;
    u16 c;
    u16 n;

    p = sub_02045A90((struct U16Vec *)s);
    c = *p;
    n = 0;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            n++;
        }
        if (c == 0xF000) {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        } else {
            p++;
        }
        c = *p;
    }
    return (n + 1) * sub_0201DC80(font);
}


/*
 * Counts the control tags of a message string for which func_0201D5CC returns
 * true.  The walk is the one every routine in this neighbourhood uses: 0xF000
 * opens a tag and func_0201D688 steps over it, anything else is one halfword,
 * and 0xFFFF ends the string.
 *
 * The counter and the cursor are interchanged unless the cursor is declared
 * first: the original keeps the cursor in r4 and the counter in r5 while the
 * counter is the one initialised first, which is
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md read in
 * the direction that costs the time.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D478.c \
 *       --addr 0x0201D478 --thumb
 */
u32 func_0201D478(void *s)
{
    u16 *p;
    u16 n = 0;

    p = func_02045A90(s);

    while (p[0] != 0xFFFF) {
        if (p[0] == 0xF000) {
            if (func_0201D5CC(p) != 0) {
                n = (u16)(n + 1);
            }
            p = func_0201D688(p);
        } else {
            p = p + 1;
        }
    }
    return n;
}


/*
 * Finds the index of the 0xBD06 tag whose first parameter is the caller's
 * value, counting 0xFFFE separators as it goes.  The tag's parameter is read
 * with func_0201D670's body written out inline (`p[0] == 0xF000 ? p[3] : 0`),
 * including the redundant re-test of p[0] that the caller has already made: that
 * guard is in the bytes and removing it costs four instructions.
 *
 * 0xFFFE is not a second pool word.  The original loads 0xFFFF once and derives
 * 0xFFFE with `subs r4, r0, #1`, which is ordinary common subexpression
 * elimination on the constant and needs nothing in the source.
 *
 * The leading call to func_02045A90 whose result is discarded is in the original
 * and is reproduced rather than tidied.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D4BC.c \
 *       --addr 0x0201D4BC --thumb
 */
u32 func_0201D4BC(void *s, u8 v)
{
    u16 *p;
    u16 n = 0;
    u32 t;

    func_02045A90(s);
    p = func_02045A90(s);
    while (p[0] != 0xFFFF) {
        if (p[0] == 0xFFFE) {
            n = (u16)(n + 1);
        }
        if (p[0] == 0xF000) {
            if (p[1] == 0xBD06) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                if (v == t) {
                    return (u8)n;
                }
            }
            p = func_0201D688(p);
        } else {
            p = p + 1;
        }
    }
    return 0;
}


/*
 * Measures a message string up to the 0xBD06 tag whose parameter is the
 * caller's value, in the font c, adding d of spacing per character.  0xFFFE
 * resets the running width, a 0xBD04 tag adds its parameter, and anything that
 * is not a tag is measured with func_0201DC6C.
 *
 * The halfword under the cursor has to be a named local.  Written as `p[0]` at
 * each of its five uses the compiler caches it in r1, which is the second
 * argument register, and the call to func_0201DC6C then needs no move; the
 * original caches it in r2 and spends `adds r1, r2, #0`, which is two bytes and
 * is the only difference between the two spellings.  That is the argument form
 * of docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D528.c \
 *       --addr 0x0201D528 --thumb
 */
u32 func_0201D528(void *s, u8 b, void *c, u32 d)
{
    u32 acc = 0;
    u16 *p;
    u32 t;
    u16 ch;

    p = func_02045A90(s);
    while (p[0] != 0xFFFF) {
        ch = p[0];
        if (p[0] == 0xFFFE) {
            acc = 0;
            p = p + 1;
        } else if (p[0] != 0xF000) {
            acc = acc + (d + func_0201DC6C(c, ch));
            p = p + 1;
        } else {
            if (p[1] == 0xBD06) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                if (b == t) {
                    return (u8)acc;
                }
            }
            if (p[1] == 0xBD04) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                acc = acc + t;
            }
            if (p[0] == 0xF000) {
                p = p + 3 + p[2];
            }
        }
    }
    return 0;
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 func_0201D5C4(void)
{
    return 0xF000;
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 func_0201D5CC(const u16 *p)
{
    u32 k;

    if (p[0] == 0xF000) {
        k = (u8)(p[1] >> 8);
    } else {
        k = 0xFF;
    }
    switch (k) {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 func_0201D5F4(const u16 *p)
{
    if (p[0] == 0xF000) {
        return (u8)(p[1] >> 8);
    }
    return 0xFF;
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr)
{
    u32 i;

    func_02045AFC(s, 0xF000);
    func_02045AFC(s, (u16)((u16)(b << 8) | c));
    func_02045AFC(s, n);
    for (i = 0; i < n; i = (u8)(i + 1)) {
        func_02045AFC(s, arr[i]);
    }
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 func_0201D658(const u16 *p)
{
    if (p[0] == 0xF000) {
        return (u8)p[1];
    }
    return 0xFF;
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 func_0201D670(const u16 *p, u32 i)
{
    if (p[0] == 0xF000) {
        return *(p + i + 3);
    }
    return 0;
}


/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u16 *func_0201D688(u16 *p)
{
    if (p[0] == 0xF000) {
        return p + 3 + p[2];
    }
    return p;
}


/*
 * The first three functions of gf_font.c.  The file identity is in the image:
 * the constructor at 0x0201D7EC passes 0x020A7358 to the debug allocator at
 * 0x02030734 and the bytes there spell "gf_font.c"; 0x0201D9BC and 0x0201DA88
 * name the same string.  This unit stops at 0x0201D6D8 because the two
 * functions after it are an unsolved register allocation, not a missing
 * declaration; see the note at the end of this comment.
 *
 * func_0201D69C sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * func_0201D6C4 is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: func_0201D6D8 and func_0201D768 reproduce the
 * right size and the right instruction multiset but allocate registers the
 * other way round.  The original keeps the ring's write cursor in a
 * callee-saved register across the MI_CpuCopy8 call and spills the loop
 * counter; every source shape tried so far (three local layouts, six
 * declaration orders, struct against scalars, one against two assignments of
 * the buffer base) gives the opposite choice and 72 differing bytes, with no
 * variation between them.  The buffer base is assigned twice, once as the
 * object pointer and once with 0x18 added, which is the aggregate-member
 * non-folding of
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md, but
 * modelling it as an aggregate member does not move the diff either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D69C.c \
 *       --addr 0x0201D69C --thumb
 */
u32 func_0201D69C(void *s)
{
    u32 n = (func_020458F8(s) + 1) * 2;

    while ((n & 3) != 0) {
        n++;
    }
    return n;
}


/*
 * The first three functions of gf_font.c.  The file identity is in the image:
 * the constructor at 0x0201D7EC passes 0x020A7358 to the debug allocator at
 * 0x02030734 and the bytes there spell "gf_font.c"; 0x0201D9BC and 0x0201DA88
 * name the same string.  This unit stops at 0x0201D6D8 because the two
 * functions after it are an unsolved register allocation, not a missing
 * declaration; see the note at the end of this comment.
 *
 * func_0201D69C sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * func_0201D6C4 is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: func_0201D6D8 and func_0201D768 reproduce the
 * right size and the right instruction multiset but allocate registers the
 * other way round.  The original keeps the ring's write cursor in a
 * callee-saved register across the MI_CpuCopy8 call and spills the loop
 * counter; every source shape tried so far (three local layouts, six
 * declaration orders, struct against scalars, one against two assignments of
 * the buffer base) gives the opposite choice and 72 differing bytes, with no
 * variation between them.  The buffer base is assigned twice, once as the
 * object pointer and once with 0x18 added, which is the aggregate-member
 * non-folding of
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md, but
 * modelling it as an aggregate member does not move the diff either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D69C.c \
 *       --addr 0x0201D69C --thumb
 */
u32 func_0201D6B8(void *s)
{
    return func_0201D69C(s) + 0x20;
}


/*
 * The first three functions of gf_font.c.  The file identity is in the image:
 * the constructor at 0x0201D7EC passes 0x020A7358 to the debug allocator at
 * 0x02030734 and the bytes there spell "gf_font.c"; 0x0201D9BC and 0x0201DA88
 * name the same string.  This unit stops at 0x0201D6D8 because the two
 * functions after it are an unsolved register allocation, not a missing
 * declaration; see the note at the end of this comment.
 *
 * func_0201D69C sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * func_0201D6C4 is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: func_0201D6D8 and func_0201D768 reproduce the
 * right size and the right instruction multiset but allocate registers the
 * other way round.  The original keeps the ring's write cursor in a
 * callee-saved register across the MI_CpuCopy8 call and spills the loop
 * counter; every source shape tried so far (three local layouts, six
 * declaration orders, struct against scalars, one against two assignments of
 * the buffer base) gives the opposite choice and 72 differing bytes, with no
 * variation between them.  The buffer base is assigned twice, once as the
 * object pointer and once with 0x18 added, which is the aggregate-member
 * non-folding of
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md, but
 * modelling it as an aggregate member does not move the diff either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D69C.c \
 *       --addr 0x0201D69C --thumb
 */
u32 func_0201D6C4(const struct Ring *p)
{
    if (p->head < p->tail) {
        return p->tail - p->head;
    }
    return p->tail + (p->size - p->head);
}



/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * 144 bytes, 0x0201D6D8..0x0201D768, one function, every concrete byte
 * reproduced (0 differing bytes of 144) -- the diff is empty apart from the
 * three wildcarded call fields.
 *
 * Blocked on the `label` class, and it is a one-address wall: all three
 * unresolved sites at +0x24, +0x32 and +0x44 call func_0201D768, which is the
 * function *immediately after this one* and whose only callers in the whole
 * image are these three.  The compared range ends where 0x0201D768 begins, so
 * shrinking the range is not possible (the callee cannot go in), and the
 * `matched` class needs an EXACT entry covering 0x0201D768 that does not
 * exist yet.  It graduates the day 0x0201D768 is matched -- nothing in this C
 * changes.
 *
 * What it is: the cache-side of a record reader.  It asks
 * func_0201D768(p, func_02045A90(c), (u16)func_0201D69C(c), 2) for a slot
 * keyed by the record at `c`, stores a second slot for `b` (0x1c/0x1c) in a
 * stack local, zero-initialises a 4-byte stack local through a third call,
 * and then walks the list hanging off p->f10 through func_0201D7C4 until it
 * runs out, rebasing the node pointer on p+0x18 and clamping the resulting
 * offset against p->f4 (u16) before a 4-byte memcpy into the local.  When
 * p->f10 is null it installs the two slots instead.
 *
 * Two details that cost a compile each: func_02045A90 is ARM, not Thumb (the
 * the offset is truncated to u16 twice -- once right after the subtraction and
 * once after the +0x1c -- which is the `(u16)(...) + 0x1c` spelling in a u16
 * local, not a single cast.
 *
 * Verified with
 *   python tools/match.py one --src src/pending/func_0201D6D8.c \
 *       --func func_0201D6D8 --addr 0x0201D6D8 --cc 1.1p1 --thumb
 */
void func_0201D6D8(Blk *p, void *b, void *c)
{
    void *e;
    void *q;
    void *t;
    u32 v;
    u32 x;

    x = (u32)func_0201D768((struct Ring *)p, (void *)func_02045A90(c),
                           (u16)func_0201D69C(c), 2);
    e = func_0201D768((struct Ring *)p, b, 0x1c, 0x1c);
    v = 0;
    func_0201D768((struct Ring *)p, (const u8 *)(&v), 4, 4);
    q = p->f10;
    if (q != 0) {
        for (;;) {
            t = func_0201D7C4((struct PrintSys *)p, q);
            if (t == 0) break;
            q = t;
        }
        {
            u16 off = (u16)((u32)q - ((u32)p + 0x18)) + 0x1c;

            if (off >= p->f04) off = 0;
            memcpy(&e, (char *)p + 0x18 + off, 4);
        }
        return;
    }
    p->f10 = e;
    p->f14 = x;
}



/*
 * printsys.c: append `len` bytes to the byte ring at +0x18 in `unit`-sized
 * copies, wrapping the head back to 0 at ring->size, and return the address
 * the first copy landed at.  The three callers are func_0201D6D8's.
 *
 * Rewritten from the start in wave 20 (lane printsys_fresh; 63 bytes out for
 * the inherited source).  What closed it: the head advance is the compound
 * `pos += unit` over a u16 `unit`.  The explicit `pos = (u16)(pos + unit)`
 * gives the loaded head and the advanced head separate webs, the loaded one
 * is cheaper than the counter and is spilled; the compound form keeps both in
 * one live range (r4 in the image), so the counter is the one spilled to
 * [sp,#4].  With a u32 `unit` the compound form truncates `unit` as a loop
 * invariant (100 bytes).  The remaining slot order is the declaration order
 * start, buf, i, pos.
 *
 * note 2026-10-05: removed the redundant first store `buf = ring;` (a
 * stand-in: arm9 game code has no line table to prove it). The single
 * `buf = (u8 *)ring + 0x18;` is EXACT in --lang c99 and --lang c; so is a
 * static inline accessor RingData(ring), so the plain form is kept.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201D768.c \
 *       --func func_0201D768 --addr 0x0201D768 --cc 1.1p1 --thumb
 */
void *func_0201D768(struct Ring *ring, const u8 *src, u16 len, u16 unit)
{
    u16 start;
    u8 *buf;
    u16 i;
    u16 pos;

    i = 0;
    buf = (u8 *)ring + 0x18;
    start = ring->head;
    while (i < len) {
        pos = ring->head;
        MI_CpuCopy8(src, buf + pos, unit);
        pos += unit;
        if (pos >= ring->size) {
            pos = 0;
        }
        ring->head = pos;
        src += unit;
        i += unit;
    }
    return buf + start;
}


/*
 * Steps the printsys.c record ring one slot on and returns the word stored
 * there, which is the next record or NULL.  The ring lives at +0x18 of the
 * object src/matched/unit_0201C450.c builds and its records are 0x1C bytes.
 *
 * Four `lsls #16` / `lsrs #16` pairs for one offset is the tell that the
 * arithmetic went through a `u16`-parameter helper the compiler inlined: the
 * argument is truncated, the parameter is truncated again on entry, the return
 * value is truncated, and the caller truncates it once more before indexing.
 * Reproducing them needs a `u32` local with an explicit `(u16)` written at each
 * of the four points; a `u16` local folds the redundant casts away and the
 * function is ten bytes short.
 *
 * func_0201D6D8 and func_0201D768, the two functions in front of this one, are
 * still open; see the note in src/matched/unit_0201D69C.c, which this work
 * narrows.  func_0201D6D8 is EXACT when it is compiled in a range with
 * func_0201D768, and func_0201D768 is four bytes short: the original spills the
 * byte counter and keeps the ring cursor in r4, and every source shape tried
 * makes the opposite choice.  Since func_0201D768's only callers are the three
 * inside func_0201D6D8 the two cannot be cut apart, so neither lands.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D7C4.c \
 *       --addr 0x0201D7C4 --thumb
 */
void *func_0201D7C4(struct PrintSys *p, void *q)
{
    u32 off = (u16)((u8 *)q - &p->buf[0]);

    off = (u16)((u16)off + 0x1C);
    if (off >= p->unk04) {
        off = 0;
    }
    return *(void **)&p->buf[(u16)off];
}


/*
 * gf_font.c's constructor: allocates the 0x94-byte font object, opens the
 * resource handle for `a0`, records the archive id at +0x54, then hands the
 * object to func_0201D854 (metrics and buffers) and func_0201DA00 (the format
 * selector).  A null allocation returns straight out, which is why both calls
 * sit inside the one guard.
 *
 * Promoted 2026-09-21 from src/pending/func_0201D7EC.c with no change to the
 * C: both calls now resolve on the `matched` class from
 * src/matched/sub_0201D854.c and src/matched/sub_0201DA00.c, which were
 * MATCH-parked when this file was written.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201D7EC.c \
 *       --func func_0201D7EC --addr 0x0201D7EC --cc 1.1p1 --thumb
 *   EXACT, 80 bytes, 5 relocation sites, all 5 resolved.
 */
struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId)
{
    struct GfFont *font = func_02030734(heapId, 0x94, 0, lbl_020A7358, 0xC0);

    if (font != 0) {
        font->field_50 = func_020490F4(a0, heapId);
        font->field_54 = a1;
        func_0201D854((struct Font *)font, a1, a3, heapId);
        func_0201DA00((struct Font *)font, a2, heapId);
    }
    return font;
}


u32 func_0201D83C(void *ptr)
{
    func_0201DADC(ptr);
    func_0201D9C8(ptr);
    return func_020307B0(ptr);
}


/*
 * note:     promoted 2026-09-21: the +0x16C ABS32 to 0x0201DC88 is now
 *           attested `matched` by src/matched/sub_0201DC88.c, which closed
 *           this file's last unresolved site.  13 of 13 relocations resolve.
 *
 * gf_font.c's metrics and buffer initialiser, 372 bytes, the largest function
 * in the file and the one func_0201D7EC calls right after the allocation.  It
 * pulls five sections out of the font resource: the 0x14-byte header block at
 * +0x58, the glyph directory at +0x80, either the whole glyph body (preloaded,
 * into a buffer at +0x84) or nothing (streamed), the eight metric bytes at
 * +0x74, and the character map at +0x88.  The hook at +0x6C is set to
 * func_0201DC88 for the streamed case and func_0201DD58 for the preloaded one,
 * and that is the pointer src/matched/unit_0201DC6C.c calls through.  It
 * finishes by priming the fallback advance at +0x70 from the glyph for '?'
 * (0x3F).
 *
 * Three details cost time:
 *
 *   - **`x / 8` and `x % 8` on the same `u8` field get different signedness
 *     treatment.**  The division is a bare `lsrs #3` and the modulo is the
 *     full signed `lsls #29` / `subs` / `rors #29` sequence, in the same
 *     expression, on the same `ldrb`.  Writing the field into a `u32` local
 *     first makes mwcc lower the modulo test to `movs #7` / `tst` and the
 *     function is sixteen bytes short; writing the field expression out twice
 *     keeps the `int` promotion and reproduces both.  An `s32` local does not
 *     compile at all here.
 *   - **248, 266 and 271 are three `__LINE__` arguments and only two pool
 *     words.**  248 is small enough for `movs`; 266 takes a pool word and 271
 *     is that word plus a constant `adds #5`
 *     (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *   - **The fallback advance is stored twice.**  `f->unk70 = 0;` then the
 *     result of func_0201DB20 over it; the first store is not dead, because
 *     func_0201DB20 reads the field on the path where no block matches.
 *
 * Every concrete byte is reproduced.  Three relocations stay wildcarded:
 *
 *   - func_020494F4 is an ARM SDK entry point whose only call site in the
 *     image is the one in this function, so the `label` class has nothing
 *     outside the range to point at.  This alone caps the function.
 *   - func_0201DC88 is a 64-byte unlabelled Thumb leaf, the streamed-glyph
 *     hook, and this pool word is its only reference image-wide.  It is not in
 *     any manifest entry: unit_0201DC6C stops at 0x0201DC88.  Matching it
 *     would convert this site to the `matched` class.
 *   - func_0201DD58 resolves on `matched` from src/matched/unit_0201DD58.c and
 *     is listed here only because the pool word sits inside the compared
 *     range.
 *
 * The fields at +0x60, +0x64 and +0x68 are declared `u32` here rather than the
 * `void *` src/matched/unit_0201DC6C.c gives them, because this function does
 * arithmetic on all three; the loads are identical either way.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201D854.c  *       --func func_0201D854 --addr 0x0201D854 --cc 1.1p1 --thumb
 */
void func_0201D854(struct Font *f, int resid, u32 flag, u32 heap)
{
    u32 size;

    if (f->unk50 == 0) {
        return;
    }
    sub_0204944C(f->unk50, resid, 0x18, 0x14, f->unk58);
    func_020494F4(f->unk50, resid, (u32 *)(&f->unk80));
    f->unk72 = (u8)flag;
    if (flag != 0) {
        f->unk84 = 0;
        f->unk6C = (u32)func_0201DD58;
    } else {
        size = f->unk68 - f->unk64;
        f->unk84 = func_02030734(heap, size, 0, func_0201D854_File, 248);
        f->unk6C = (u32)func_0201DC88;
        sub_0204944C(f->unk50, resid, f->unk64, size, f->unk84);
    }
    sub_0204944C(f->unk50, resid, f->unk60, 8, &f->unk74);
    f->unk7E = (u8)(f->unk74 / 8 + ((f->unk74 % 8) ? 1 : 0));
    f->unk7F = (u8)(f->unk75 / 8 + ((f->unk75 % 8) ? 1 : 0));
    f->unk7C = (u16)((f->unk74 * 2) % 8);
    if (f->unk7C == 0) {
        f->unk7C = 8;
    }
    f->unk8C = (void *)(f->unk60 + 8);
    f->unk90 = func_02030734(heap, f->unk76, 0, func_0201D854_File, 266);
    size = func_020493D4(f->unk50, resid) - f->unk68;
    f->unk88 = func_02030734(heap, size, 0, func_0201D854_File, 271);
    sub_0204944C(f->unk50, resid, f->unk68, size, f->unk88);
    f->unk70 = 0;
    f->unk70 = (u16)func_0201DB20(f, 0x3F);
}
