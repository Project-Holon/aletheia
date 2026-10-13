/*
 * function: SCRIPT_WORK_SetCheckFlag
 * address: 0x02159144
 * packet: pkt_ov010_02159144
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Input evidence: ov010 callers 0215F278/02164946 pass 11/7;
 * ov021 flag setters pass fixed IDs 0..13 (e.g. 021B5316 passes 0,
 * 021AEE1E passes 13). No traced setter call supplies a negative ID.
 * These primary paths make 1 << n defined; no new bound is assumed.
 * symbols:
 *   SCRIPT_WORK_IsCheckFlagSet 0x02159198 thumb ov010
 *   gScriptCheckFlags 0x02172BA0 data a4
 */
extern int gScriptCheckFlags;
extern int SCRIPT_WORK_IsCheckFlagSet(int);
void SCRIPT_WORK_SetCheckFlag(int n)
{
    if (n < 14 && !SCRIPT_WORK_IsCheckFlagSet(n)) gScriptCheckFlags |= 1 << n;
}
