/*
 * function: IRC_BATTLE_ENTRY_RestoreBgm
 * address:  0x02155A6C
 * packet:   pkt_ov010_02155A6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stops the sound handle at +0x54 (if any) and clears it.
 *
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx {
    u8 pad00[0x54];
    u32 f54;
};

extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);
extern void GFL_USE_FadeInBgmFull(u32 a);

void IRC_BATTLE_ENTRY_RestoreBgm(struct Ctx *ctx)
{
    if (ctx->f54 != 0) {
        GFL_USE_CancelChangeAndPlayBgm(ctx->f54, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3c);
        ctx->f54 = 0;
    }
}
