/*
 * function: func_021C8EB4
 * address:  0x021C8EB4
 * packet:   pkt_ov114_021C8EB4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Non-SDK callee of func_021C7C1C (ov114 dependency tree).  Switch on the
 * request kind maps to a DWC result code; DWC_UpdateConnection failing
 * demotes -13 to -14; DWC_ClearError always runs on the non--13 path.
 *
 * Case-order tell: mwcc lays the per-arm stubs down in SOURCE order, so the
 * only spelling that reproduces the image lists case 5 before case 4 even
 * though the jump table is indexed by value.  -15, -14, -13 are the three
 * result codes; the r5==-13 (case 7) path skips both calls entirely.
 *
 * symbols:
 *   DWC_UpdateConnection  0x0205D074  arm
 *   DWC_ClearError        0x02059F18  arm
 */

typedef unsigned int u32;

extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);

int func_021C8EB4(u32 type)
{
    int r;

    switch (type) {
    case 0:
    case 1:
    case 2:
        r = -15;
        break;
    case 3:
        r = -14;
        break;
    case 5:
        r = -14;
        break;
    case 4:
        r = -15;
        break;
    case 6:
        r = -14;
        break;
    case 7:
        r = -13;
        break;
    default:
        r = -14;
        break;
    }

    if (r != -13) {
        if (DWC_UpdateConnection() != 0)
            r = -14;
        DWC_ClearError();
    }

    return r;
}
