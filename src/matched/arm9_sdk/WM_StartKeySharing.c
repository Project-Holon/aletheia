/*
 * function: WM_StartKeySharing
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
 *   func_0209004C 0x0209004C arm
 */

typedef unsigned short u16;
typedef int BOOL;
typedef int WMErrCode;

extern WMErrCode func_0209004C(void *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);

WMErrCode WM_StartKeySharing(void *dsInfo, u16 port)
{
    return func_0209004C(dsInfo, port, 0xFFFF, 2, 1);
}
