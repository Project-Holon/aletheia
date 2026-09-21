/*
 * function: func_02038C18
 * address:  0x02038C18
 * packet:   pkt_02038C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 *   func_02039414  0x02039414  arm
 *   func_0203C990  0x0203C990  arm
 *   func_02039594  0x02039594  arm
 *   func_020368C0  0x020368C0  arm
 *   func_02039548  0x02039548  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *
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

typedef unsigned char  u8;
typedef unsigned int   u32;

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

extern struct Handle *g_021469D0;

extern struct Rec *func_0203D798(void);
extern int    func_02039414(void);
extern int    func_0203C990(void);
extern int    func_02039594(void);
extern int    func_020368C0(void *tbl, u32 a, u32 b, u32 c, u32 d, u32 e,
                            u32 f);
extern void   func_02039548(void);
extern struct Err *func_0203CA98(void);
extern void   func_0203C9AC(u32 a, u32 b, u32 c, u32 line);

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
    err = func_0203CA98();
    if (err->f0c == 0)
        func_0203C9AC(err->f00, err->f04, err->f08, 0x3f4);
    return 0;
}
