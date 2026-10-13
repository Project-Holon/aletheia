/*
 * function: POKEGRA_RegisterTrainerCellAnim
 * address:  0x0202DA6C
 * packet:   pkt_0202DA18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 */

int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3){ int t0, t1, t2, t3, t4, t5; t0 = func_02027718((int)((a1 + 0) + 0)); t1 = func_0202771C((int)((a1 + 0) + 0)); t2 = func_020275E4((int)t1); t3 = func_020490F4((int)t2, (int)((a3 + 0) + 0)); t4 = CLACT_RegisterCellAnim((int)t3, (int)((t0 + 0) + 0), (int)((t1 + 0) + 0), (int)((a3 + 0) + 0)); t5 = ARC_TOOL_DeleteHandle((int)((t3 + 0) + 0)); return ((t4 + 0) + 0); }
