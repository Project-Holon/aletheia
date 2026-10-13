/*
 * function: NET_WHPIPE_SetAcceptChild
 * address: 0x02177EDC
 * packet: pkt_ov014_02177EDC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 79328 stores its r0 payload unchanged; caller passes a function pointer.
 * symbols:
 *   WIH_SetJudgeAcceptFunc 0x02179328 thumb ov014
 *   NET_WHPIPE_AcceptChild 0x02177ED4 thumb ov014
 *   NET_WHPIPE_RejectChild 0x02177ED8 thumb ov014
 */

extern void WIH_SetJudgeAcceptFunc(void *v);
extern int NET_WHPIPE_AcceptChild(void);
extern int NET_WHPIPE_RejectChild(void);
void NET_WHPIPE_SetAcceptChild(int a) { if (a != 0) WIH_SetJudgeAcceptFunc(NET_WHPIPE_AcceptChild); else WIH_SetJudgeAcceptFunc(NET_WHPIPE_RejectChild); }
