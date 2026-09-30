/*
 * function: func_021C97E0
 * address: 0x021C97E0
 * packet: pkt_ov114_021C97E0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   DWC_UpdateConnection 0x0205D074 arm
 *   DWC_ClearError 0x02059F18 arm
 */
extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);
int func_021C97E0(unsigned type)
{
    int r;
    switch (type) {
    case 0: case 1: case 2: r = -7; break;
    case 3: r = -6; break;
    case 5: r = -6; break;
    case 4: r = -7; break;
    case 6: r = -6; break;
    case 7: r = -5; break;
    default: r = -6; break;
    }
    if (r != -5) {
        if (DWC_UpdateConnection() != 0) r = -6;
        DWC_ClearError();
    }
    return r;
}
