/*
 * function: BR_RES_LoadUiPalette
 * address: 0x021FC148
 * packet: pkt_ov186_021FC148
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_02049B68 0x02049B68 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BR_RES_GetPaletteFileId 0x021FC31C thumb ov186
 *   BR_RES_GetCharFileId 0x021FC344 thumb ov186
 *   BR_RES_GetScreenFileId 0x021FC36C thumb ov186
 */
#include "../include/Obj01770.h"
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned CLACT_RegisterPaletteEx(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned short BR_RES_GetPaletteFileId(unsigned),BR_RES_GetCharFileId(unsigned),BR_RES_GetScreenFileId(unsigned);
void BR_RES_LoadUiPalette(char *p,unsigned i,unsigned heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    *(unsigned *)(p+i*4)=CLACT_RegisterPaletteEx(h,BR_RES_GetPaletteFileId(((struct Obj01770 *)p)->fF8),i,0,0,13,heap);
    if(i==0){
        func_02049B68(h,BR_RES_GetCharFileId(((struct Obj01770 *)p)->fF8),0,0,0,heap);
        func_02049B68(h,BR_RES_GetScreenFileId(((struct Obj01770 *)p)->fF8),0,0x1c0,0x20,heap);
    }else{
        func_02049B68(h,BR_RES_GetCharFileId(((struct Obj01770 *)p)->fF8),4,0,0,heap);
        func_02049B68(h,BR_RES_GetScreenFileId(((struct Obj01770 *)p)->fF8),4,0x1c0,0x20,heap);
    }
    ARC_TOOL_DeleteHandle(h);
}
