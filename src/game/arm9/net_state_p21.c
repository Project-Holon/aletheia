/*
 * file:     net_state_p21.c
 * unit:     yes
 * function: func_0203CA98, func_0203CADC, func_0203CB00, func_0203CB34, func_0203CBAC, func_0203CD98
 * address:  0x0203CA98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714   0x02034714  arm
 *   unk_021469DC    0x021469DC  data
 *   file_020A7BA8   0x020A7BA8  data
 *   file_020A7C70   0x020A7C70  data
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7C7C     0x020A7C7C  data
 *   g_021469DC     0x021469DC  data
 *   g_021469E0     0x021469E0  data
 *   file_020A7CA0  0x020A7CA0  data
 *   str_020A7CA8   0x020A7CA8  data
 *   str_020A7CB8   0x020A7CB8  data
 *   str_020A7CE8   0x020A7CE8  data
 *   func_0203064C  0x0203064C  arm
 *   func_02030734  0x02030734  arm
 *   func_0200F17C  0x0200F17C  thumb
 *   func_0203D8F0  0x0203D8F0  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203AFCC  0x0203AFCC  arm
 *   func_02039834  0x02039834  arm
 *   func_0203A494  0x0203A494  arm
 *   func_02037010  0x02037010  arm
 *   func_0203D788  0x0203D788  arm
 */
struct Base;
typedef unsigned int u32;

typedef unsigned char u8;

struct Card0203CB00 {
    unsigned char pad[8];
    void *cb;
};

typedef signed char   s8;

typedef unsigned short u16;

struct Req {
    u32 f00;
    u32 f04;
    u8  pad_08[0x40];
    u32 f48;
    u8  pad_4c[8];
    u16 f54;
    u16 f56;
    u16 f58;
    u16 f5a;
    u16 f5c;
    u16 f5e;
    u8  pad_60[1];
    u8  f61;
    u8  pad_62[3];
    u8  f65;
    u8  pad_66[1];
    u8  f67;
};

struct Sess {
    u8  pad_000[0x340];
    u32 (**f340)(void);
    u8  pad_344[8];
    u32 f34c;
    u8  pad_350[2];
    u8  f352;
};

struct Mod {
    u8  pad_00[8];
    struct Sess *f08;
};

typedef int (*Fn)(void);

struct Table {
    unsigned char pad_00[0x6c];
    Fn            unk_6c;
};

struct Singleton {
    unsigned char  pad_00[0x340];
    struct Table  *unk_340;
};

extern void func_02034714(const char *file, u32 line, const char *fmt);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void func_020371AC(unsigned short a, unsigned int b);
extern void func_020370C8(void);
extern int func_0200F17C(u32 sel);
extern void func_0200F234(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Base *func_0203D8F0(const struct Base *src, u32 a1);
extern void  func_02082D44(void *dst, void *src, u32 n);
extern void func_0203AFCC(void *a, u32 b);
extern void  func_02039834(struct Sess *s);
extern void  func_0203A494(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void  func_02037010(u32 a, u32 b, u32 c, u32 d);
extern void *func_0203D788(void);
u32 func_0203CA98(void);
void func_0203CADC(void);
int func_0203CB00(void);
void func_0203CB34(u32 a, u32 b, u32 c, u32 d);
int func_0203CD98(void);
extern u32  unk_021469DC;
extern const char file_020A7BA8[];
extern const char file_020A7C70[];
extern u8  g_020A7BA8[];
extern u8  g_020A7C7C[];
extern struct Card0203CB00 *g_021469DC;
extern const char file_020A7CA0[];
extern const char str_020A7CA8[];
extern const char str_020A7CB8[];
extern const char str_020A7CE8[];
extern struct Mod g_021469E0;


/*
 * Returns the object's work area at +0x30, reporting through func_02034714
 * with the source file at 0x020A7BA8 and line 0x8CA (2250) when the object has
 * not been created - the report is not fatal, the address of the null object's
 * field is still what comes back.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA98.c \
 *       --func func_0203CA98 --addr 0x0203CA98 --cc 1.1p1 --arm
 */
u32 func_0203CA98(void)
{
    if (unk_021469DC == 0)
        func_02034714(file_020A7BA8, 0x8CA, file_020A7C70);
    return unk_021469DC + 0x30;
}


/*
 * Unlabelled ARM assert thunk: tail call func_02034714(g_020A7BA8, 0x8D8, g_020A7C7C), the fall-through failure path after func_0203CA98.
 */
void func_0203CADC(void)
{
    func_02034714((const char *)((u32)g_020A7BA8), 0x8D8, (const char *)((u32)g_020A7C7C));
}


/*
 * Unlabelled ARM predicate: the card task object exists and its callback at +8 is func_0203CADC.
 * MATCH only because 0x0203CADC (func_0203CADC.c, EXACT) is not yet a labelled
 * function start: the pool word has no outside witness until the seed lands.
 */
int func_0203CB00(void)
{
    struct Card0203CB00 *c = g_021469DC;
    if (c != 0 && c->cb == (void *)func_0203CADC) {
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CB34.c \
 *       --func func_0203CB34 --addr 0x0203CB34 --cc 1.1p1 --arm
 */
void func_0203CB34(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_0200F17C(1);
    u32 v = a;

    if (p != 0)
        ((void (*)(u32, u32))p[0])(a, b);

    func_0200F234(1);

    if (c != d) {
        *(u16 *)0x021469E0 = (u16)d;
        func_0203064C(c, d, 0x9E80);
    }

    func_020371AC(0, 0);
    func_020370C8();
}


/*
 * note:     net.c: start one network session (0x354-byte record on the
 *           request's +0x56 heap, published into g_021469E0's +8 slot, the
 *           vtable from func_0200F17C for mode +0x65, then a seven-way mode
 *           switch).  Closed in wave 16 after the 80-byte residue of
 *           docs/notes/pkt_0203CBAC.c.txt:
 *           - the id guard at the head and in the beacon arm is a call in
 *             BOTH arms with the non-zero arm written FIRST; the image's
 *             kept `beq; b` pair is the empty (cross-jumped) then-arm, and
 *             the beacon arm's cross-jump into the shared `bl` follows;
 *           - case map per the note's finding 1 (1/2/6 vtable, 3/4 beacon,
 *             0/5 break, default the line-0x8e error), both arms `break`;
 *           - the tail boolean is `f = 0; if (...) f = 1;`, which is the
 *             image's `mov r2, #0` / `movls r2, #1`, and the 3-or-4 exit
 *             test is bound to `int done` (otherwise it folds to a range
 *             check).
 *           func_0203D8F0 and func_0203AFCC resolve as sole-ref/code.
 */
void func_0203CBAC(struct Req *req, u32 a2, u32 a3)
{
    struct Sess *s;
    u8 m;
    u32 f;

    if (*(u16 *)&g_021469E0 != 0)
        func_0203064C(*(u16 *)&g_021469E0, req->f56, 0x7800);
    else
        func_0203064C(req->f54, req->f56, 0x7800);
    s = (struct Sess *)func_02030734(req->f56, 0x354, 1, file_020A7CA0, 0x6a);
    g_021469E0.f08 = s;
    s->f352 = 1;
    s->f340 = (u32 (**)(void))func_0200F17C(req->f65);
    if (s->f340 == 0)
        func_02034714(file_020A7CA0, 0x6f, str_020A7CA8);
    if (req->f65 == 4)
        req = (struct Req *)func_0203D8F0((const struct Base *)req, a3);
    func_02082D44(req, s, 0x70);
    switch (req->f65) {
    case 1:
    case 2:
    case 6:
        ((void (*)(u32, u32))(*s->f340))(req->f54, 0);
        func_0203064C(req->f54, (u16)(req->f58 | 0x8000), req->f48);
        break;
    case 3:
    case 4:
        if (req->f61 > 0x80)
            func_02034714(file_020A7CA0, 0x84, str_020A7CB8);
        if (*(u16 *)&g_021469E0 != 0)
            func_0203064C(*(u16 *)&g_021469E0, req->f5a, 0x1b00);
        else
            func_0203064C(req->f54, req->f5a, 0x1b00);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(file_020A7CA0, 0x8e, str_020A7CE8);
        return;
    }
    s->f34c = a3;
    func_0203AFCC((void *)req->f56, a2);
    func_02039834(s);
    func_0203A494(req->f67 << 8, req->f00, req->f04, s->f34c, req->f56);
    m = req->f65;
    {
        int done = (m == 3) || (m == 4);
        if (done)
            return;
    }
    f = 0;
    if ((u8)(m + 0xff) <= 1)
        f = 1;
    func_02037010(req->f5c, req->f5e, f, req->f56);
}


/*
 * Guarded call through a function-pointer table: fetch the singleton via
 * func_0203D788, bail to 0 if it is null, then chase the pointer at +0x340
 * to a table and call its +0x6c entry through a register (no relocation
 * site there, `blx r0`).  func_0203D788 has many outside callers, so its
 * own call closes on the `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CD98.c \
 *       --func func_0203CD98 --addr 0x0203CD98 --cc 1.1p1 --arm
 */
int func_0203CD98(void)
{
    struct Singleton *s = func_0203D788();

    if (s == 0) {
        return 0;
    }

    return s->unk_340->unk_6c();
}
