/*
 * function: DWCi_MOV_WH_StateInStartScan
 * address:  0x0217863C
 * packet:   pkt_ov014_0217863C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The DWC copy of the NitroSDK demo wh.c's scan start: checks
 * WM_GetAllowedChannel (0x8000 -> error 3, 0 -> error 0x16), picks the next
 * allowed channel after the one in the scan parameter's channel list (or the
 * fixed channel at +0x1EB2), fills the WMScanExParam at +0x1400 of the work
 * block behind g_021797A8 (buffer at +0x1000, 0x400, scan type 1, no SSID)
 * and calls WM_StartScanEx with callback DWCi_MOV_WH_StateOutStartScan; anything but
 * WM_ERRCODE_OPERATING (2) goes to the error setter func_0217814C.
 *
 * symbols:
 *   g_021797A8                   0x021797A8  data   ov014  a4
 *   DWCi_MOV_WH_StateOutStartScan                0x02178788  thumb  ov014
 *   func_0217814C                0x0217814C  thumb  ov014
 *   WM_GetAllowedChannel         0x0208EE60  arm
 *   WM_GetDispersionScanPeriod   0x0208EFC4  arm
 *   WM_StartScanEx               0x0208F698  arm
 */
#include "../include/Obj05923.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern u8 *g_021797A8;

extern void DWCi_MOV_WH_StateOutStartScan(void *arg);
extern void func_0217814C(int err);
extern u16 WM_GetAllowedChannel(void);
extern u16 WM_GetDispersionScanPeriod(void);
extern int WM_StartScanEx(void (*cb)(void *), void *param);

BOOL DWCi_MOV_WH_StateInStartScan(void)
{
    int result;
    u16 chanpat;
    u8 *w;

    chanpat = WM_GetAllowedChannel();
    if (chanpat == 0x8000) {
        func_0217814C(3);
        return 0;
    }
    if (chanpat == 0) {
        func_0217814C(0x16);
        return 0;
    }

    w = g_021797A8;
    if (((struct Obj05923 *)w)->f1EB2 == 0) {
        int n;
        u32 channel = ((struct Obj05923 *)w)->f1406;

        for (n = 0; n < 32; n++) {
            if (channel & 1)
                break;
            channel >>= 1;
        }
        channel = n + 1;

        while (1) {
            channel++;
            if (channel > 16)
                channel = 1;
            if (chanpat & (1 << (channel - 1)))
                break;
        }
        ((struct Obj05923 *)w)->f1406 = (u16)(1 << (channel - 1));
    } else {
        ((struct Obj05923 *)w)->f1406 = (u16)(1 << (((struct Obj05923 *)w)->f1EB2 - 1));
    }

    *(u16 *)(g_021797A8 + 0x1408) = WM_GetDispersionScanPeriod();
    *(u8 **)(g_021797A8 + 0x1400) = g_021797A8 + 0x1000;
    *(u16 *)(g_021797A8 + 0x1404) = 0x400;
    *(u16 *)(g_021797A8 + 0x1410) = 1;
    *(u16 *)(g_021797A8 + 0x1412) = 0;

    result = WM_StartScanEx(DWCi_MOV_WH_StateOutStartScan, g_021797A8 + 0x1400);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}
