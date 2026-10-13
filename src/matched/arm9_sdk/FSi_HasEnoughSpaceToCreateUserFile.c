/*
 * function: WM_Initialize
 * address:  0x0208F370
 * packet:   pkt_0208F370
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208F398 0x0208F398 arm
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int WMErrCode;
typedef void (*WMCallbackFunc)(void *arg);

extern WMErrCode func_0208F398(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags);

WMErrCode WM_Initialize(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo)
{
    return func_0208F398(wmSysBuf, callback, dmaNo, 0);
}
