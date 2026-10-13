/*
 * function: WIH_StepDS
 * address:  0x021793B8
 * packet:   pkt_ov014_021793B8
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls the arm9 function at 0x020902D8 with the data-sharing info
 * (+0x1444) and buffer (+0x1C64) of the work block behind gWihWork; result
 * 7 or 5 counts as failure without the error setter, other nonzero results
 * call WIH_SetError and fail, zero succeeds.
 *
 * symbols:
 *   gWihWork     0x021797A8  data   ov014  a4
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WM_StepDataSharing  0x020902D8  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern u8 *gWihWork;

extern void WIH_SetError(int err);
typedef unsigned short u16;
struct WMDataSet;
struct WMDataSharingInfo;
extern int WM_StepDataSharing(struct WMDataSharingInfo *dsInfo, const u16 *sendData, struct WMDataSet *receiveData);

BOOL WIH_StepDS(int arg)
{
    int r;

    r = WM_StepDataSharing((struct WMDataSharingInfo *)(gWihWork + 0x1444), (const u16 *)arg, (struct WMDataSet *)(gWihWork + 0x1C64));
    if (r == 7)
        return 0;
    if (r == 5)
        return 0;
    if (r != 0) {
        WIH_SetError(r);
        return 0;
    }
    return 1;
}
