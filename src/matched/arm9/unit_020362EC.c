/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: KEY_GetContSys, KEY_GetCont, KEY_GetRepeatSys, KEY_GetRepeat,
 *           KEY_GetRepeatSpeedSys, KEY_GetRepeatSpeed
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
 * context from func_02035224().  KEY_GetRepeatSpeedSys is the two-output form and
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
struct UiCtx;
extern struct UiCtx *func_02035224(void);

u32 KEY_GetContSys(struct Ctx *ctx);
u32 KEY_GetRepeatSys(struct Ctx *ctx);
void KEY_GetRepeatSpeedSys(struct Ctx *ctx, u32 *outA, u32 *outB);

u32 KEY_GetContSys(struct Ctx *ctx)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_24;
    }
    return rec->unk_18;
}

u32 KEY_GetCont(void)
{
    return KEY_GetContSys((struct Ctx *)func_02035224());
}

u32 KEY_GetRepeatSys(struct Ctx *ctx)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_2c;
    }
    return rec->unk_20;
}

u32 KEY_GetRepeat(void)
{
    return KEY_GetRepeatSys((struct Ctx *)func_02035224());
}

void KEY_GetRepeatSpeedSys(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)ctx);

    *outA = rec->unk_40;
    *outB = rec->unk_44;
}

void KEY_GetRepeatSpeed(u32 *outA, u32 *outB)
{
    KEY_GetRepeatSpeedSys((struct Ctx *)func_02035224(), outA, outB);
}
