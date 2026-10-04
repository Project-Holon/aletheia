/*
 * function: func_021793B8
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
 * (+0x1444) and buffer (+0x1C64) of the work block behind g_021797A8; result
 * 7 or 5 counts as failure without the error setter, other nonzero results
 * call func_0217814C and fail, zero succeeds.
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_020902D8  0x020902D8  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern u8 *g_021797A8;

extern void func_0217814C(int err);
typedef unsigned short u16;
struct WMDataSet;
struct WMDataSharingInfo;
extern int func_020902D8(struct WMDataSharingInfo *dsInfo, const u16 *sendData, struct WMDataSet *receiveData);

BOOL func_021793B8(int arg)
{
    int r;

    r = func_020902D8((struct WMDataSharingInfo *)(g_021797A8 + 0x1444), (const u16 *)arg, (struct WMDataSet *)(g_021797A8 + 0x1C64));
    if (r == 7)
        return 0;
    if (r == 5)
        return 0;
    if (r != 0) {
        func_0217814C(r);
        return 0;
    }
    return 1;
}
