/*
 * function: SCRIPT_WORK_IsCheckFlagSet
 * address: 0x02159198
 * packet: pkt_ov010_02159198
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Input evidence: direct callers are 0215914C, 02159170, 021591D0.
 * Set/clear callers use fixed nonnegative IDs 0..13; the 02159190 tail
 * forwarder has constant-ID callers in ov010/ov021/ov082 (021F5756: 3).
 * The task caller's index starts at zero (0215922E), advances by one
 * (021591EA), and sees a NULL callback at table index 14 (02170628)
 * before the test call. Its fourteen callbacks leave task+0x10 alone;
 * state updates use only task+0x0c. Thus shifted IDs are 0..13 on the
 * traced primary paths; no invented guard or domain was added.
 * symbols:
 *   gScriptCheckFlags 0x02172BA0 data a4
 */
extern int gScriptCheckFlags;
int SCRIPT_WORK_IsCheckFlagSet(int n)
{
    if (n >= 14) return 0;
    if ((gScriptCheckFlags >> n) & 1) return 1;
    return 0;
}
