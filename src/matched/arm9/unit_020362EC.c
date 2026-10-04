/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_020362EC, sub_0203630C, sub_0203631C, sub_0203633C,
 *           sub_0203634C, sub_02036370
 * address:  0x020362EC
 * packet:   pkt_020362EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203521C  0x0203521C  arm
 *   func_02035224  0x02035224  arm
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
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

struct Ctx {
    u8 pad_00[0x3d];
    u8 unk_3d;
};

extern u32 func_0203521C(u32 *p);
extern struct Ctx *func_02035224(void);

u32 sub_020362EC(struct Ctx *ctx);
u32 sub_0203631C(struct Ctx *ctx);
void sub_0203634C(struct Ctx *ctx, u32 *outA, u32 *outB);

u32 sub_020362EC(struct Ctx *ctx)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_24;
    }
    return rec->unk_18;
}

u32 sub_0203630C(void)
{
    return sub_020362EC(func_02035224());
}

u32 sub_0203631C(struct Ctx *ctx)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_2c;
    }
    return rec->unk_20;
}

u32 sub_0203633C(void)
{
    return sub_0203631C(func_02035224());
}

void sub_0203634C(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)ctx);

    *outA = rec->unk_40;
    *outB = rec->unk_44;
}

void sub_02036370(u32 *outA, u32 *outB)
{
    sub_0203634C(func_02035224(), outA, outB);
}
