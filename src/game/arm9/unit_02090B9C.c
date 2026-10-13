/*
 * file:     unit_02090B9C.c
 * function: WM_StartKeySharing, func_02090BB8
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
 *   func_0209028C  0x0209028C  arm
 */

typedef unsigned short u16;
typedef int BOOL;
typedef int WMErrCode;

extern WMErrCode func_0209004C(void *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);

extern void func_0209028C(void);
void func_02090BB8(void);
WMErrCode WM_StartKeySharing(void *dsInfo, u16 port)
{
    return func_0209004C(dsInfo, port, 0xFFFF, 2, 1);
}

void func_02090BB8(void)
{
    func_0209028C();
}
