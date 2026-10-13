/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov173_021B6100
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   func_021B63AC 0x021B63AC thumb ov173
 *   func_021B7ADC 0x021B7ADC thumb ov173
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj06563.h"
#include "../include/Obj24149.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
struct GfFont;
struct Tcbl;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_021B63AC(u8 *p);
extern void func_021B7ADC(unsigned char *p, u32 idx, int unused);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
int func_021B6100(struct Obj0203159C *obj, int unused, u8 *input)
{
    u8 *p;
    GFL_HEAP_CreateChildHeap(1,79,0x50000);
    p=PROCSYS_AllocProcWork(obj,0x228,79);
    func_02082BCC(p,0,0x228);
    *(u8 * *)&((struct Obj06563 *)p)->f0=input;
    ((struct Obj06563 *)p)->f60=(u32)GF_FONT_Create(23,0,0,0,79);
    ((struct Obj06563 *)p)->f64=(u32)TCBL_Create(79,79,32,32);
    func_021B63AC(p);
    func_021B7ADC(p,(u8)(((struct Obj24149 *)(*(u8 * *)&((struct Obj06563 *)p)->f0))->f14),3);
    ((struct Obj06563 *)p)->f1B0=1;
    GFL_NET_RestartWithDefaultTimeout(1,79);
    return 1;
}
