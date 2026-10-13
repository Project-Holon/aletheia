/*
 * function: MCSS_SetMosaic
 * address:  0x02016078
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_FreeResource  0x02016BA0  thumb
 *   MCSS_LoadResource  0x020163C4  thumb
 *
 * Updates a packed 4-bit mode field at b+0x140 (bits 24-27 of that word;
 * see docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md) if
 * the caller's requested mode (clamped to 15) differs from the current
 * one, then reinitialises through MCSS_FreeResource and forwards a nested
 * word and struct pointer into MCSS_LoadResource. The bitfield pointer is
 * recomputed fresh for the store rather than kept in a local across the
 * clamp branch: the original re-issues the same "5 << 6" multiply instead
 * of reusing the register from the read, the same shape as
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * EXACT* because the 72 compiled bytes fall short of the disasm.py extent
 * (92 bytes): the extent runs into the next function's own literal pool,
 * not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_SetMosaic.c \
 *       --func MCSS_SetMosaic --addr 0x02016078 --cc 1.1p1
 */
#include "../include/Obj16729.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Sub02016078Word {
    u32 low24 : 24;
    u32 mode  : 4;
    u32 hi4   : 4;
};

extern void MCSS_FreeResource(void *b);
struct Ctx;
struct Src;
extern void MCSS_LoadResource(struct Ctx *a0, u32 idx, const struct Src *a2);

void MCSS_SetMosaic(void *a, void *b, int mode)
{
    u8 *pb = (u8 *)b;

    if (((struct Sub02016078Word *)(pb + 0x140))->mode != (u32)mode) {
        if (mode > 15) {
            mode = 15;
        }
        ((struct Sub02016078Word *)(pb + 0x140))->mode = mode;

        MCSS_FreeResource(b);
        MCSS_LoadResource(a, ((struct Obj16729 *)pb)->f148, (const struct Src *)(pb + 0x150));
    }
}
