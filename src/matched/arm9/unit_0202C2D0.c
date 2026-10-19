/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C2D0
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_SWITCH_SYS_GetPlayingBgm, ISS_SWITCH_SYS_IsOn
 *
 * symbols:
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *
 * ISS_SWITCH_SYS_GetPlayingBgm is a pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * GFL_USE_GetBgmNo, which is open elsewhere in the image. ISS_SWITCH_SYS_IsOn is a
 * plain read of the object's first word.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C2D0.c \
 *       --addr 0x0202C2D0 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 GFL_USE_GetBgmNo(void);

u32 ISS_SWITCH_SYS_GetPlayingBgm(u32 v)
{
    return GFL_USE_GetBgmNo();
}

u32 ISS_SWITCH_SYS_IsOn(u32 *p)
{
    return *p;
}
