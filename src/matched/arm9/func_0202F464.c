/*
 * unit:     no
 * function: SAVE_EVENT_CopyDoneFlag
 * address:  0x0202F464
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 */

int SAVE_EVENT_CopyDoneFlag(int a0){ int t0 = func_02017E88((int)a0, (int)0x9e, (int)0); int t1 = POKE_TOOL_SetBoxValue((int)((a0 + 0) + 0), (int)0x99, (int)(t0 + 0)); return t1; }
