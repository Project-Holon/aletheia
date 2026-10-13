/*
 * file:     unit_02090B9C.c
 * function: WM_StartKeySharing, WM_EndKeySharing
 * address:  0x02090B9C
 * packet:   pkt_02090B9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WM_StartDataSharing 0x0209004C arm
 *   WM_EndDataSharing  0x0209028C  arm
 */

typedef unsigned short u16;
typedef int BOOL;
typedef int WMErrCode;

extern WMErrCode WM_StartDataSharing(void *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);

extern void WM_EndDataSharing(void);
void WM_EndKeySharing(void);
WMErrCode WM_StartKeySharing(void *dsInfo, u16 port)
{
    return WM_StartDataSharing(dsInfo, port, 0xFFFF, 2, 1);
}

void WM_EndKeySharing(void)
{
    WM_EndDataSharing();
}
