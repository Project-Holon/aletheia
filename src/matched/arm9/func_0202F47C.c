/*
 * function: SAVE_EVENT_SetDoneFlag
 * address:  0x0202F47C
 * packet:   pkt_0202F1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled 12-byte Thumb leaf (a tail call through a pool word
 *           to POKE_TOOL_SetBoxValue with id 0x77, value 0x15) after SAVE_EVENT_CopyDoneFlag;
 *           filed as the witness for SAVE_EVENT_WriteMode's call at +0x58, the
 *           only branch to it image-wide.  Needs a seed in
 *           layout/function_starts.txt.
 * symbols:
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 */
typedef unsigned int u32;

extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);

void SAVE_EVENT_SetDoneFlag(void *p)
{
    POKE_TOOL_SetBoxValue(p, 0x77, 0x15);
}
