/*
 * function: CTVT_MIC_Delete
 * address:  0x021BA01C
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears the +0x1f8 object down through its three slots.
 *
 * symbols:
 *   func_0200566C  0x0200566C  thumb
 *   CTVT_MIC_StopCapture  0x021BA120  thumb  ov172
 *   CTVT_MIC_FreeChannel  0x021BA1D8  thumb  ov172
 *   func_0208BEF0  0x0208BEF0  arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0200566C(void);
extern int CTVT_MIC_StopCapture(u32 *p);
extern void CTVT_MIC_FreeChannel(void *p);
extern unsigned int func_0208BEF0(unsigned int status);
extern void GFL_NET_FreeAligned(void *p);
extern u32 func_020307B0(void *p);

void CTVT_MIC_Delete(char *p)
{
    func_0200566C();
    *(u32 *)0x021C88EC = 0;
    CTVT_MIC_StopCapture((u32 *)p);
    CTVT_MIC_FreeChannel(p);
    func_0208BEF0(0);
    GFL_NET_FreeAligned(((struct Obj04554 *)p)->f4);
    func_020307B0(p);
}
