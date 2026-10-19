/*
 * file:     greeting_savedata.c
 * unit:     yes
 * function: GREETING_SAVEDATA_GetSize, GREETING_SAVEDATA_Init, GREETING_SAVEDATA_GetFromSaveThunk, GREETING_SAVEDATA_GetFromSave, GREETING_SAVEDATA_GetSentence, GREETING_SAVEDATA_SetSentence
 * address:  0x0200E6B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_examination.c, greeting_savedata.c by tools/splitfile.py.
 *
 * symbols:
 *   PMSI_PARAM_SetDefaultGreeting  0x02024344  thumb
 *   PMSI_PARAM_SetDefaultSentence  0x020242D8  thumb
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */
#include "misc_savedata_shared_types.h"
#include "greeting_savedata_shared_types.h"

extern void PMSI_PARAM_SetDefaultGreeting(void *obj);

extern void PMSI_PARAM_SetDefaultSentence(void *slot, u32 idx);

u32 GREETING_SAVEDATA_GetSize(void);

void GREETING_SAVEDATA_Init(void *obj);

u32 GREETING_SAVEDATA_GetSize(void)
{
    return 0x28;
}

/*
 * Promoted from src/pending/GREETING_SAVEDATA_Init.c: every concrete byte was
 * already reproduced, and both callees were unresolved relocations
 * because each is called from exactly this one place in the whole ROM,
 * the case the honesty rule's cut remedy cannot reach (docs/MATCHING.md,
 * "the limit of the remedy"). Both are now EXACT entries in their own
 * right (src/matched/PMSI_PARAM_InitSentence.c's PMSI_PARAM_SetDefaultGreeting, and
 * src/matched/unit_020242D8.c's PMSI_PARAM_SetDefaultSentence), so the `matched` class
 * attests both calls without a second caller, and this file closes to
 * EXACT.
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte
 * slots starting at obj+8, tagging each with its index 0..3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GREETING_SAVEDATA_Init.c \
 *       --func GREETING_SAVEDATA_Init --addr 0x0200E6B4 --cc 1.1p1 --thumb
 */
void GREETING_SAVEDATA_Init(void *greetings)
{
    PMSI_PARAM_SetDefaultGreeting(greetings);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 8, 0);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 0x10, 1);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 0x18, 2);
    greetings = (u8 *)greetings + 0x20;
    PMSI_PARAM_SetDefaultSentence(greetings, 3);
}

/* One 8-byte record of the four-halfword table the copy helpers move. */
struct QuadRecord {
    u16 data[4];
};

extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

void *GREETING_SAVEDATA_GetFromSaveThunk(u32 a);

void *GREETING_SAVEDATA_GetFromSave(u32 a);

void GREETING_SAVEDATA_GetSentence(struct QuadRecord *src, int idx, struct QuadRecord *dst);

void GREETING_SAVEDATA_SetSentence(struct QuadRecord *dst, int idx, struct QuadRecord *src);

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a two-hop tail-call chain. GREETING_SAVEDATA_GetFromSaveThunk is a pure forwarder to
 * GREETING_SAVEDATA_GetFromSave, which itself tail calls SAVE_CONTROL_GetBlock with a fixed id of
 * 0x3e; both pass their argument through unchanged. Neither carries a
 * register-saving prologue, so disasm.py's sweep does not label
 * GREETING_SAVEDATA_GetFromSave and it prints as data between the two literal pools; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md and
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E6E8.c \
 *       --addr 0x0200E6E8 --thumb
 */
void *GREETING_SAVEDATA_GetFromSaveThunk(u32 saveData)
{
    return GREETING_SAVEDATA_GetFromSave(saveData);
}

void *GREETING_SAVEDATA_GetFromSave(u32 saveData)
{
    return SAVE_CONTROL_GetBlock((struct Sub020071CCCtrl *)saveData, 0x3e);
}

/*
 * One 8-byte record copied out: four u16 fields, so the copy unrolls to four
 * ldrh/strh pairs rather than an ldm/stm.  It has to be written as a struct
 * assignment: the same copy spelled field by field, or through a `u16 *`
 * temporary, picks the other register for the scaled index (r1 instead of
 * r3) and lands six bytes wrong.  EXACT*: the listing extent runs 192 bytes
 * because the follower at 0x0200E714 saves nothing and carries no label.
 */
void GREETING_SAVEDATA_GetSentence(struct QuadRecord *src, int idx, struct QuadRecord *dst)
{
    *dst = src[idx];
}

/*
 * Unlabelled Thumb leaf that follows GREETING_SAVEDATA_GetSentence: copy one 8-byte record to dst[idx].
 */
void GREETING_SAVEDATA_SetSentence(struct QuadRecord *dst, int idx, struct QuadRecord *src)
{
    dst[idx] = *src;
}
