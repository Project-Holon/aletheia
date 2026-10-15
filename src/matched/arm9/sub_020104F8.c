/*
 * function: WIH_DWC_IsSsidInFilterList
 * address:  0x020104F8
 * packet:   pkt_0201045C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWihDwc     0x021461E0  data
 *   GF_STANDARD_GetStringLength  0x0203F004  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *
 * Three 0x100-byte slots at +0x640 of the object hanging off +0x304 of the
 * global at 0x021461E0 (the same global WIH_DWC_AddBeacon reads); the first slot
 * with a positive GF_STANDARD_GetStringLength whose GF_STANDARD_CompareBytes against obj+0xC returns
 * zero makes the function return 1.
 *
 * Three spellings the previous pass (docs/notes/pkt_0201045C.c.txt) did not
 * have, and each is needed:
 *
 *  1. the pool word is 0x021461E0, not 0x020461E0, and it holds a POINTER,
 *     not the object: the original does one `ldr r1, [r7]` and then
 *     `ldr r1, [r1, r0]` with r0 = 0x304.  Reading it as `**` costs an extra
 *     dereference at both sites.  It is the same global WIH_DWC_AddBeacon reads.
 *  2. GF_STANDARD_CompareBytes takes THREE arguments, and the third is the result of
 *     GF_STANDARD_GetStringLength.  That is what the otherwise pointless `adds r2, r0, #0`
 *     at 0x02010518 is: r2 is set right after the first call and is still
 *     live, unwritten, at the `blx` to GF_STANDARD_CompareBytes twenty-four bytes
 *     later.  Two arguments plus a named local for the comparison folds the
 *     copy away (80 bytes); a function-scope or volatile local gives it a
 *     stack home (`str r0, [sp]` / `ldr r0, [sp]`) instead of r2.  The local
 *     must be declared inside the loop body.
 *     docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md
 *  3. `i` must be initialised before `q`: the original opens
 *     `movs r4, #0` then `adds r6, #0xc`, and writing the loop as a plain
 *     `for (i = 0; ...)` after `u8 *q = obj + 0xC;` emits those two the
 *     other way round.  That swap is the last two bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_IsSsidInFilterList.c \
 *       --func WIH_DWC_IsSsidInFilterList --addr 0x020104F8 --cc 1.1p1 --thumb
 */

#include "../include/G_WihCtx.h"

typedef unsigned char u8;

extern struct WihCtx gWihDwc;

typedef signed int     s32;
typedef unsigned int   u32;
extern u32 GF_STANDARD_GetStringLength(const u8 *s);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

int WIH_DWC_IsSsidInFilterList(u8 *obj)
{
    int i = 0;
    u8 *q = obj + 0xC;

    for (; i < 3; i++) {
        u8 *slot = *(u8 **)((*(u8 * *)&gWihDwc) + 0x304) + 0x640 + i * 0x100;
        int n = GF_STANDARD_GetStringLength(slot);

        if (n > 0) {
            slot = *(u8 **)((*(u8 * *)&gWihDwc) + 0x304) + 0x640 + i * 0x100;
            if (GF_STANDARD_CompareBytes(slot, q, n) == 0)
                return 1;
        }
    }
    return 0;
}
