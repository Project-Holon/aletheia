/*
 * function: func_021FC240
 * address: 0x021FC240
 * packet: pkt_ov186_021FC240
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 490F4 receives full heap, no caller truncation; E8E8 reads stack heap halfword.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021FC31C 0x021FC31C thumb ov186
 *   func_021FC344 0x021FC344 thumb ov186
 *   func_021FC36C 0x021FC36C thumb ov186
 *   func_021FE8E8 0x021FE8E8 thumb ov186
 */
#include "../include/Obj05501.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned short func_021FC31C(unsigned),func_021FC344(unsigned),func_021FC36C(unsigned);
extern void func_021FE8E8(char *p, void *arc, u32 file, u32 idx, u32 off, u32 count, u16 tag);
void func_021FC240(char *p,void *owner,unsigned short heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    func_021FE8E8(owner,h,func_021FC31C(((struct Obj05501 *)p)->fF8),2,0,0x1C0,heap);
    func_021FE8E8(owner,h,func_021FC31C(((struct Obj05501 *)p)->fF8),3,0,0x1C0,heap);
    func_021FE8E8(owner,h,func_021FC344(((struct Obj05501 *)p)->fF8),0,0,0,heap);
    func_021FE8E8(owner,h,func_021FC344(((struct Obj05501 *)p)->fF8),1,0,0,heap);
    func_021FE8E8(owner,h,func_021FC36C(((struct Obj05501 *)p)->fF8),0,0xE0,0x20,heap);
    func_021FE8E8(owner,h,func_021FC36C(((struct Obj05501 *)p)->fF8),1,0xE0,0x20,heap);
    ARC_TOOL_DeleteHandle(h);
}
