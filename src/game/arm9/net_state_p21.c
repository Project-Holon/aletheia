/*
 * file:     net_state_p21.c
 * unit:     yes
 * function: func_02038A48, func_02038A90, func_02038AE0, func_02038C18, func_02038D30, func_02038D4C, func_02038D68, func_02038DF0
 * address:  0x02038A48
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
 *   g_020A7A20     0x020A7A20  data
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   func_02034714  0x02034714  arm
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A50   0x020A7A50  data
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02037224  0x02037224  arm
 *   func_0203D788  0x0203D788  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020366A8  0x020366A8  arm
 *   func_02036A50  0x02036A50  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   g_021469D0     0x021469D0  data
 *   func_02039414  0x02039414  arm
 *   func_0203C990  0x0203C990  arm
 *   func_02039594  0x02039594  arm
 *   func_020368C0  0x020368C0  arm
 *   func_02039548  0x02039548  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02039338   0x02039338  arm
 *   func_0203996C   0x0203996C  arm
 *   func_0203A770   0x0203A770  arm
 *   func_02037234   0x02037234  arm
 *   func_020365E8  0x020365E8  arm
 *   func_02036540  0x02036540  arm
 *   func_02036500  0x02036500  arm
 *   func_020364D4  0x020364D4  arm
 *   func_0203A804  0x0203A804  arm
 *   func_0203A7EC  0x0203A7EC  arm
 *   func_0203A634  0x0203A634  arm
 *   func_0203A81C  0x0203A81C  arm
 *   func_02082D44  0x02082D44  arm
 */
struct Entry;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int s32;

struct Hdr
{
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 body[1];
};

struct Glob
{
    u8 pad_00[0x65];
    u8 f65;
};

struct Conn
{
    u8 pad_00[0x24];
    u32 f24;
};

struct Vt
{
    u8 pad_00[0x7c];
    u8 (*f7c)(void);
    u8 pad_80[0x30];
    s32 (*fb0)(void);
};

struct Sys
{
    u8 pad_00[0x340];
    struct Vt *f340;
};

struct Buf
{
    void *ptr;
    u16 len;
};

struct Rec {
    u8  pad_00[0x64];
    u8  f64;
};

struct Handle {
    u8  pad_00[0x1e0];
    u32 f1e0;
};

struct Err {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

typedef signed short   s16;

struct Src {
    u8  pad00[0x0c];
    s16 pos;
};

struct St {
    s32 done;
    u8 *dst;
    u16 left;
    u16 total;
    u16 h;
    u8  f0E;
    u8  f0F;
};

extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern void *func_0203D798(void);
extern void func_02037224(u8 v, int b);
extern void *func_0203D788(void);
extern void MI_CpuFill8(void *, u8, u32);
extern s32 func_020366A8(struct Conn *);
extern int func_02036A50(u32 list, u16 *info);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern u32 func_02039414(void);
extern u32 func_0203C990(void);
extern int    func_02039594(void);
extern int    func_020368C0(void *tbl, u32 a, u32 b, u32 c, u32 d, u32 e,
                            u32 f);
extern void   func_02039548(void);
extern u32 func_0203CA98(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern int func_020365E8(char *p);
extern u16 func_02039338(void);
extern struct Entry *func_0203996C(s32 idx);
extern void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
extern void func_02037234(u8 *p);
extern u32 func_02036540(u32 a);
extern u32 func_02036500(u32 a);
extern int  func_020364D4(struct Src *s, u8 *buf, u32 n, u32 max);
extern int  func_0203A804(u32 h);
extern int  func_0203A7EC(u32 h);
extern u32 func_0203A634(u32 a0);
extern u32 func_0203A81C(u32 a0, u32 a1, u32 a2);
extern void func_02082D44(void *dst, const void *src, int n);
int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void func_02038D30(int a0, int a1, int a2, int a3);
void func_02038D4C(int a0, int a1, int a2, int a3);
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3);
int func_02038A48(int a);
int func_02038A90(u32 a);
extern u8   g_020A7A20[];
extern u8   g_020A7A24[];
extern u8   g_020A7A50[];
extern const u8 str_020A7A24[];
extern const u8 str_020A7A50[];
extern struct Handle *g_021469D0;



/*
 * Idempotent bring-up: when the argument is non-zero and the mode byte at
 * 0x020A7A21 still reads 2, it is flipped to 4 and the call is skipped; in
 * every other case the 0x5C0-byte block at 0x020A7A24 is handed to
 * func_02034714 with 0x020A7A50 as the third argument.  Either way the
 * function answers 1 through the single shared epilogue (`mov r0, #1;
 * pop {r3, pc}`), which is why the taken arm ends in `beq` to that epilogue
 * and not in a predicated return.
 *
 * The three globals are *arrays*, not pointers: the image loads the pool word
 * straight into r0 and then does `ldrb r1, [r0, #1]`, so `extern u8
 * g_020A7A20[]` with a `[1]` subscript is the spelling that reproduces it - as
 * `extern u8 *g_020A7A20` the compiler adds a second load and the file grows
 * to 88 bytes.  The arm's two instructions are predicated (`moveq`/`strbeq`)
 * rather than branched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038A48.c \
 *       --func func_02038A48 --addr 0x02038A48 --cc 1.1p1 --arm
 */
int func_02038A48(int a)
{
    if (a != 0 && g_020A7A20[1] == 2) {
        g_020A7A20[1] = 4;
    } else {
        func_02034714((const char *)g_020A7A24, 0x5C0, (const char *)g_020A7A50);
    }
    return 1;
}



int func_02038A90(u32 a)
{
    func_0203D6BC();
    func_0203D680();
    func_0203D798();
    if (a != 0) {
        func_02037224(4, 0x5d4);
    } else {
        func_02034714((const char *)str_020A7A24, 0x5d8, (const char *)str_020A7A50);
    }
    return 1;
}



s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3)
{
    struct Glob *g;
    struct Sys *sys;
    struct Buf buf;
    s32 n;
    u16 v;

    g = func_0203D798();
    sys = func_0203D788();

    MI_CpuFill8(h, 0, (u32)len);

    if (c->f24 == 0)
        h->f04 = 1;
    else
        h->f04 = 2;
    c->f24 = 0;

    h->f03 = sys->f340->f7c();

    if (func_020366A8(c) == 0)
    {
        if ((u8)(g->f65 + 0xfd) > 1)
            goto body;
        if (sys->f340->fb0() != 1)
            goto body;
    }
    h->f04 = 0xff;
    return 0;

body:
    ;

    buf.len = (u16)(len - 7);
    buf.ptr = &h->body[0];
    if (func_02036A50((u32)c, (u16 *)(&buf)) == 0)
        c->f24 = 1;

    if (buf.len != 0xffff)
        n = (len - buf.len) - 7;
    else
        n = len - 7;

    if (n > 0xff)
    {
        n = n + 1;
        h->f04 = h->f04 | 8;
    }

    h->f02 = (u8)n;
    h->f05 = a3;

    v = func_0203F1FC(&h->f02, len - 2);
    h->f00 = (u8)v;
    h->f01 = (u8)((v & 0xff00) >> 8);

    return 1;
}


/*
 * Seven-argument entry to the comms send path.  The seventh argument is a
 * flag whose INVERSE becomes the `broadcast` byte handed to func_020368C0:
 * `flag == 0` gives 1, anything else gives 0, materialised as
 * `mov r5,#1` / `cmp r4,#0` / `movne r5,#0` before the first call.
 *
 * The module handle behind the global at 0x021469D0 is fetched once and every
 * later read comes off the same pooled base; a null handle, a busy queue
 * (func_02039414 non-zero or func_0203C990 zero) and a failed func_02039594
 * all return 0 early.  func_0203D798's result is only used for its +0x64
 * byte, which selects the +0xf4 table over the +0xcc one when the fifth
 * argument is the 0xff wildcard.
 *
 * The broadcast flag is additionally cleared when the third argument is not
 * less than the handle's +0x1e0 word: `cmp r7,r0` / `cmpge r5,#1` /
 * `moveq r5,#0` is the conjunction `if (a3 >= lim && flag != 0) flag = 0;`
 * written as one expression
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * On a failed send the error path reports through func_0203CA98's three-word
 * record with line 0x3f4 and returns 0; a successful send returns 1.
 *
 * Addresses are Black-image addresses.
 *
 * BYTE-CORRECT, PARKED: 280 bytes, 0 concrete mismatches.  Capped at MATCH by
 * the sole unresolved site, the PC24 at +0x00D0 naming func_020368C0
 * (0x020368C0).  That address has no branch anywhere in the image outside this
 * function's own `bl` and no manifest entry, so neither `label` nor `matched`
 * can attest it; the call is the last thing before the function's two tail
 * exits, so no cut frees it either.  Filing 0x020368C0 promotes this file
 * unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038C18.c \
 *       --func func_02038C18 --addr 0x02038C18 --cc 1.1p1 --arm
 */
int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7)
{
    struct Rec *rec;
    struct Handle *h;
    struct Err *err;
    void *tbl;
    u32 flag;

    flag = 1;
    if (a7 != 0)
        flag = 0;

    rec = func_0203D798();
    if (g_021469D0 == 0)
        return 0;
    if (func_02039414() != 0 || func_0203C990() != 0)
        return 0;
    if (func_02039594() == 0)
        return 0;

    h = g_021469D0;
    if ((int)a3 >= (int)h->f1e0 && flag == 1)
        flag = 0;

    if (rec->f64 != 0 && a5 == 0xff)
        tbl = (u8 *)h + 0xf4;
    else
        tbl = (u8 *)h + 0xcc;

    if (func_020368C0(tbl, a1, a2, a3, a4, flag, a6) != 0)
        return 1;

    func_02039548();
    err = (struct Err *)func_0203CA98();
    if (err->f0c == 0)
        func_0203C9AC(err->f00, err->f04, err->f08, 0x3f4);
    return 0;
}

void func_02038D30(int a0, int a1, int a2, int a3){ func_020365E8((char *)((int)(*(int *)((char *)(0x21469D0)) + 0x1c))); }

void func_02038D4C(int a0, int a1, int a2, int a3){ func_020365E8((char *)((int)(*(int *)((char *)(0x21469D0)) + 0x3c))); }


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038D68.c \
 *       --func func_02038D68 --addr 0x02038D68 --cc 1.1p1 --arm
 */
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3)
{
    u32 v;

    func_0203D798();
    v = (u32)func_0203996C(func_02039338());
    func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);

    if (func_02039338() == 0) {
        v = (u32)func_0203996C(0xFF);
        if (a0 < 0x11)
            func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);
    }

    func_02037234(a3);
}


/*
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header func_0203640C builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - func_020364D4 is written in BOTH arms of the func_0203A804 test,
 *       if (!func_0203A804(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     func_02036540's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */
void func_02038DF0(struct Src *src, u32 a1, u8 *buf, struct St *st, u32 n)
{
    int len;
    s16 sv;
    u8 *p;
    u32 h;
    int cnt;

    func_0203D798();
    while (func_020365E8((char *)src) != 0) {
        h = st->h;
        if (h == 0) {
            h = func_02036540((u32)src);
            if (h == 0) {
                func_02034714((const char *)str_020A7A24, 0x6E3, (const char *)str_020A7A50);
                continue;
            }
        }
        sv = src->pos;
        st->h = h;
        if (st->total == 0xFFFF) {
            if (func_020365E8((char *)src) < 3) {
                src->pos = sv;
                return;
            }
            {
                u16 v = func_02036540((u32)src);
                st->left = v;
                st->total = v;
            }
            st->f0E = a1;
            st->f0F = func_02036500((u32)src);
        }
        sv = src->pos;
        if (func_0203A804(h) && func_0203A634(st->f0F)) {
            if (st->dst == 0)
                st->dst = (u8 *)func_0203A81C(h, st->f0E, st->total);
            p = st->dst + st->done;
        } else {
            p = buf;
            st->dst = buf;
        }
        if (!func_0203A634(st->f0F))
            p = 0;
        if (!func_0203A804(h))
            len = func_020364D4(src, buf, st->left, st->left);
        else
            len = func_020364D4(src, buf, st->left, n - 7);
        st->left = st->left - (u16)len;
        cnt = len;
        if (st->total > st->done) {
            cnt = st->total - st->done;
            if (cnt > len)
                cnt = len;
            if (p != 0)
                func_02082D44(buf, p, cnt);
        }
        st->done += cnt;
        if (st->left == 0) {
            func_02038D68(h, st->total, (u32)st->dst, (u8 *)st);
            continue;
        }
        if (!func_0203A7EC(h))
            return;
        if (func_0203A804(h))
            return;
        if (!func_0203A634(st->f0F))
            return;
        st->left += (u16)len;
        src->pos = sv;
        return;
    }
}
