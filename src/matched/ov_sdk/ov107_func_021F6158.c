/*
 * function: MBi_SetMPData
 * address:  0x021F6158
 * packet:   pkt_ov107_021F6158
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * symbols:
 *   WM_SetMPDataToPortEx             0x0208fcb4 arm
 *   MBi_CheckWmErrcode               0x021f6334 arm
 */
typedef unsigned short u16;

extern int WM_SetMPDataToPortEx(void (*callback)(void *), void *arg, u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);

static int MBi_SetMPData(void (*callback)(void *), u16 *sendData, u16 sendDataSize, u16 unused, u16 pollbmp)
{
    int errcode;

    errcode = WM_SetMPDataToPortEx(callback, 0, sendData, sendDataSize, pollbmp, 1, 3);
    MBi_CheckWmErrcode(0xF, errcode);
    return errcode;
}
