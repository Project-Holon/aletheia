/*
 * function: SCRIPT_WORK_ClearCheckFlags
 * address: 0x02159130
 * packet: pkt_ov010_02159130
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gScriptCheckFlags 0x02172BA0 data a4
 *   func_02082A7C 0x02082A7C arm
 */
extern int gScriptCheckFlags;
extern void func_02082A7C(int, void *, int);
void SCRIPT_WORK_ClearCheckFlags(void)
{
    func_02082A7C(0, &gScriptCheckFlags, 4);
}
