/*
 * function: sub_0201D110
 * address:  0x0201D110
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013020  0x02013020  thumb
 *   func_02013050  0x02013050  thumb
 *   sub_0201CDF4   0x0201CDF4  thumb
 *   func_02043B5C  0x02043B5C  arm
 *
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

extern signed char func_02013020(void);
extern signed char func_02013050(void);
extern void sub_0201CDF4(s32 v, u8 *out);
extern void func_02043B5C(u32 win, u32 c);

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
        func_02043B5C(p->win, p->color);
        break;
    }

    cur = CtrlSkip(p->cur);
    p->cur = cur;
    if (skip != 0 && *cur == 0xFFFE)
        p->cur = cur + 1;
}
