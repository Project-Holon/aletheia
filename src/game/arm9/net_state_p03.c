/*
 * file:     net_state_p03.c
 * unit:     yes
 * function: func_02036290, func_020362A4, func_020362BC, func_020362DC, func_020362EC, func_0203630C, func_0203631C, func_0203633C, func_0203634C, func_02036370, func_02036390
 * address:  0x02036290
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
 *   func_02035224   0x02035224  arm
 *   func_0203521C  0x0203521C  arm
 */
#include "../../matched/include/Obj15897.h"

struct UiCtx;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Rec_020362BC {
    u8 pad_00[0x1c];
    u32 unk_1c;
    u8 pad_20[0x08];
    u32 unk_28;
};

struct Ctx {
    u8 pad_00[0x3d];
    u8 unk_3d;
};

struct Rec_020362EC {
    u8 pad_00[0x18];
    u32 unk_18;
    void *unk_1c;
    u32 unk_20;
    u32 unk_24;
    void *unk_28;
    u32 unk_2c;
    u8 pad_30[0x10];
    u32 unk_40;
    u32 unk_44;
};

struct Rec_02036390 {
    u8 pad_00[0x24];
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

extern struct UiCtx *func_02035224(void);
extern u32 func_0203521C(u32 *p);
u32 sub_020362EC(struct Ctx *ctx);
u32 sub_0203631C(struct Ctx *ctx);
void sub_0203634C(struct Ctx *ctx, u32 *outA, u32 *outB);
int func_02036290(int a0, const void *a1);
void func_020362A4(const void *p);



int func_02036290(int a0, const void *a1){ int t0; t0 = func_0203521C((u32 *)a0); ((struct Obj15897 *)((char *)(t0)))->f0 = (int)a1; return t0; }



void func_020362A4(const void *p)
{
    func_02036290((int)func_02035224(), p);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_020362BC picks one of two key masks out of the record returned by
 * func_0203521C, keyed on a one-byte mode tag at +0x3d of its own argument;
 * sub_020362DC is the two-call wrapper that runs func_02035224 first.
 *
 * The two are kept in one unit deliberately: sub_020362DC's only call to
 * sub_020362BC has no witness anywhere else in the image, so as separate
 * files sub_020362DC caps at MATCH.  Inside one range the site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362BC.c \
 *       --addr 0x020362BC --arm
 */
u32 sub_020362BC(struct Ctx *ctx)
{
    struct Rec_020362BC *rec = (struct Rec_020362BC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_28;
    }
    return rec->unk_1c;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_020362BC picks one of two key masks out of the record returned by
 * func_0203521C, keyed on a one-byte mode tag at +0x3d of its own argument;
 * sub_020362DC is the two-call wrapper that runs func_02035224 first.
 *
 * The two are kept in one unit deliberately: sub_020362DC's only call to
 * sub_020362BC has no witness anywhere else in the image, so as separate
 * files sub_020362DC caps at MATCH.  Inside one range the site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362BC.c \
 *       --addr 0x020362BC --arm
 */
u32 sub_020362DC(void)
{
    return sub_020362BC((struct Ctx *)func_02035224());
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
u32 sub_020362EC(struct Ctx *ctx)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_24;
    }
    return rec->unk_18;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
u32 sub_0203630C(void)
{
    return sub_020362EC((struct Ctx *)func_02035224());
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
u32 sub_0203631C(struct Ctx *ctx)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_2c;
    }
    return rec->unk_20;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
u32 sub_0203633C(void)
{
    return sub_0203631C((struct Ctx *)func_02035224());
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
void sub_0203634C(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    *outA = rec->unk_40;
    *outB = rec->unk_44;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
void sub_02036370(u32 *outA, u32 *outB)
{
    sub_0203634C((struct Ctx *)func_02035224(), outA, outB);
}


/*
 * Zeroes the six-word block at +0x24 of the record func_0203521C resolves
 * its argument to.  The other follow-up pass that src/pending/sub_02035660.c
 * runs (see src/matched/sub_02035E54.c for the first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02036390.c \
 *       --func sub_02036390 --addr 0x02036390 --cc 1.1p1 --arm
 */
void sub_02036390(struct Rec_02036390 *p)
{
    struct Rec_02036390 *rec = (struct Rec_02036390 *)func_0203521C((u32 *)p);

    rec->unk24 = 0;
    rec->unk28 = 0;
    rec->unk2c = 0;
    rec->unk30 = 0;
    rec->unk34 = 0;
    rec->unk38 = 0;
}
