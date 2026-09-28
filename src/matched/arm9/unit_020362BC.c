/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_020362BC, sub_020362DC
 * address:  0x020362BC
 * packet:   pkt_020362BC
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
 * sub_020362BC picks one of two pointers out of the record returned by
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

typedef unsigned char u8;

struct Rec {
    u8 pad_00[0x1c];
    void *unk_1c;
    u8 pad_20[0x08];
    void *unk_28;
};

struct Ctx {
    u8 pad_00[0x3d];
    u8 unk_3d;
};

extern struct Rec *func_0203521C(struct Ctx *ctx);
extern struct Ctx *func_02035224(void);

void *sub_020362BC(struct Ctx *ctx)
{
    struct Rec *rec = func_0203521C(ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_28;
    }
    return rec->unk_1c;
}

void *sub_020362DC(void)
{
    return sub_020362BC(func_02035224());
}
