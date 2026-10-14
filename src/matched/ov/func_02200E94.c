/*
 * function: WORLDTRADE_SERVER_DeleteWindows
 * address:  0x02200E94
 * packet:   pkt_02200E94
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_DeletePrintStream  0x02202940  thumb  ov135
 *   BMP_WIN_Delete  0x020452E8  arm  arm9

 * Tear down the +0xfa0 sub-object, then release the +0xd40 resource.
 */
#include "../include/Obj18609.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Obj;
extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void WORLDTRADE_SERVER_DeleteWindows(u8 *p)
{
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj18609 *)p)->fD40));
}
