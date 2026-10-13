/*
 * function: DWC_RAP_AllocRecvBuffer
 * address:  0x02156C00
 * packet:   pkt_ov009_02156C00
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_RAP_FreeRecvBuffer  0x02156BD8  thumb  ov009
 *   func_0203D798  0x0203D798  arm
 *   GFL_NET_AllocAligned  0x0203D7C8  arm
 *   func_021770EC  0x021770EC  arm  ov009
 *   d_021A1C60  0x021A1C60  data  ov009  a4
 */
#include "../include/Obj18654.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern u8 d_021A1C60[];
extern void DWC_RAP_FreeRecvBuffer(u32);
extern void *func_0203D798(void);
extern void *GFL_NET_AllocAligned(u32, u32, const char *, u16);
extern void func_021770EC(u8, u32, u32);

void DWC_RAP_AllocRecvBuffer(u32 a)
{
    u8 *p = func_0203D798();
    DWC_RAP_FreeRecvBuffer(a);
    if (*(u32 *)(g_021A8264 + a * 4 + 0x174) == 0) {
        u32 n = 0x1000;
        *(u32 *)(g_021A8264 + a * 4 + 0x174) =
            (u32)GFL_NET_AllocAligned(((struct Obj18654 *)p)->f56, n, (const char *)d_021A1C60, 0xb74);
        func_021770EC(a, *(u32 *)(g_021A8264 + a * 4 + 0x174), n);
    }
}
