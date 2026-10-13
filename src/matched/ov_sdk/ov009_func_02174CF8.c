/*
 * function: DWCi_QR2AddErrorCallback
 * address:  0x02174CF8
 * packet:   pkt_ov009_02174CF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    defined in src/game/ov009/unit_02174CF0.c without a verification
 *           entry.
 *
 * symbols:
 *   DWCi_HandleQR2Error  0x02173E30  arm
 */

extern int DWCi_HandleQR2Error(int error);

int DWCi_QR2AddErrorCallback(int error)
{
    return DWCi_HandleQR2Error(error);
}
