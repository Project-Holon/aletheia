/*
 * function: DWC_GdbProcess
 * address:  0x021E1414
 * packet:   pkt_021E1414
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0217CE1C  0x0217CE1C  arm  ov009
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   DWC_ProcessGHTTP  0x021BF5B8  arm  ov114
 *
 * Runs the ov009 status query 0x0217CE1C; unless it reports 2 it releases
 *  *  the ov009 object through 0x0217CCCC(0), then always finishes with the
 *  *  0x021BF5B8 (ov114) step.
 */

extern int  func_0217CE1C(void);
extern void func_0217CCCC(unsigned int theMS);
extern int DWC_ProcessGHTTP(void);

void DWC_GdbProcess(void)
{
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
    DWC_ProcessGHTTP();
}

