/*
 * function: SCRIPT_WORK_ResetCheckFlag
 * address: 0x02159168
 * packet: pkt_ov010_02159168
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum-typed BIT keeps the shifted mask opaque; plain int folds
 * the complement to mvns and shortens the body by four bytes.
 * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7;
 * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0,
 * 021AF03A passes 13; 021B10C8 forwards its saved literal 3).
 * On these traced paths n is nonnegative and below 14 before the shift.
 * symbols:
 *   SCRIPT_WORK_IsCheckFlagSet 0x02159198 thumb ov010
 *   gScriptCheckFlags 0x02172BA0 data a4
 */
extern int gScriptCheckFlags;
extern int SCRIPT_WORK_IsCheckFlagSet(int);
typedef enum { BIT = 1 } Mask;
void SCRIPT_WORK_ResetCheckFlag(int n)
{
    if (n < 14 && SCRIPT_WORK_IsCheckFlagSet(n)) {
        Mask bit = BIT;
        gScriptCheckFlags &= (bit << n) ^ -1;
    }
}
