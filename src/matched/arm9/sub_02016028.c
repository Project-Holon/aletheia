/*
 * function: MCSS_SetAnimeIndex
 * address:  0x02016028
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 * status:   EXACT*
 *
 * symbols:
 *   NNS_G2dGetAnimSequenceByIdx  0x020627D8  arm
 *   func_020307B0  0x020307B0  arm
 *   MCSS_InitAnimCtrl  0x02016984  thumb
 *   NNS_G2dSetAnimSequenceToMCAnimation  0x0206469C  arm
 *
 * Reconfigures the object: derives a value from NNS_G2dGetAnimSequenceByIdx on field
 * +0x28 and a caller-supplied flag truncated to 16 bits (the explicit
 * lsls/lsrs #0x10 pair in the original is exactly that narrowing cast in
 * the callee, not something the caller is trusted to have done), releases
 * the handle at +0x98 through func_020307B0 if one is set, calls
 * MCSS_InitAnimCtrl(a, 1), passes the derived value into NNS_G2dSetAnimSequenceToMCAnimation on the
 * member at +0x34, then clears bit 0 of the word at +0x144.
 *
 * Every concrete byte matches; MCSS_InitAnimCtrl (0x02016984, later in this
 * same packet, not yet matched) is called from exactly this one site in
 * the whole ROM, so that relocation stays unresolved under the honesty
 * rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/MCSS_SetAnimeIndex.c \
 *       --func MCSS_SetAnimeIndex --addr 0x02016028 --cc 1.1p1
 *
 * The `matched` class does not reach it: MCSS_InitAnimCtrl is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */
#include "../include/Obj02301.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
extern struct AnimSequence *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx);
extern u32 func_020307B0(void *p);
extern void MCSS_InitAnimCtrl(char *a0, int a1);
extern void NNS_G2dSetAnimSequenceToMCAnimation(struct Obj0206469C *o, void *bank);

void MCSS_SetAnimeIndex(void *a, u32 flag)
{
    u8 *p = (u8 *)a;
    u32 value = (u32)NNS_G2dGetAnimSequenceByIdx((struct AnimBank *)(((struct Obj02301 *)p)->f28), (u16)flag);

    if (((struct Obj02301 *)p)->f98 != 0) {
        func_020307B0((void *)(((struct Obj02301 *)p)->f98));
    }

    MCSS_InitAnimCtrl(a, 1);
    NNS_G2dSetAnimSequenceToMCAnimation((struct Obj0206469C *)(p + 0x34), (void *)value);
    ((struct Obj02301 *)p)->f144 &= ~1u;
}
