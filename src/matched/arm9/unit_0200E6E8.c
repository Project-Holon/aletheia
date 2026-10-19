/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E6E8
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GREETING_SAVEDATA_GetFromSaveThunk, GREETING_SAVEDATA_GetFromSave
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
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

typedef unsigned int u32;

extern void *GREETING_SAVEDATA_GetFromSave(u32 a);
struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

void *GREETING_SAVEDATA_GetFromSaveThunk(u32 a)
{
    return GREETING_SAVEDATA_GetFromSave(a);
}

void *GREETING_SAVEDATA_GetFromSave(u32 a)
{
    return SAVE_CONTROL_GetBlock((struct Sub020071CCCtrl *)a, 0x3e);
}
