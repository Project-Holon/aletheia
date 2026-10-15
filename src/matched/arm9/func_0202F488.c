/*
 * unit:     no
 * function: SAVE_EVENT_IsStageDone
 * address:  0x0202F488
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   SAVE_EVENT_CheckStage  0x0202F498  thumb
 */

int SAVE_EVENT_IsStageDone(int a0, int a1){ int t0 = POKE_TOOL_Dummy(); int t1 = SAVE_EVENT_CheckStage((int)t0, (int)((a1 + 0) + 0)); return t1; }
