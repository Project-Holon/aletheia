/*
 * function: P_STA_RIBBON_PrintDetail
 * address: 0x021D949C
 * packet: pkt_ov131_021D949C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D9566 follow the 202-byte body.
 * proof: index is ldrb at 021D94DA, hence 0..255; index*8+316
 * is at most 2356 and has no signed overflow. No selector bound assumed.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   P_STA_RIBBON_GetRibbonInfo 0x021DBF2C thumb ov131
 *   P_STA_RIBBON_GetRibbonDescMsg 0x021DBF94 thumb ov131
 */
#include "../include/Obj00136.h"
#include "../include/Obj03815.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 P_STA_RIBBON_GetRibbonInfo(u32,u32);
extern unsigned int P_STA_RIBBON_GetRibbonDescMsg(int i);
void P_STA_RIBBON_PrintDetail(u8 *a,u8 *p)
{
    u8 index;
    void *text;
    *(u32 *)&((struct Obj03815 *)p)->f20=BMP_WIN_Create(4,5,7,22,2,14,1);
    *(u32 *)&((struct Obj03815 *)p)->f24=BMP_WIN_Create(4,1,16,30,4,14,1);
    index=(p+p[0x59]*8)[0x13c];
    text=func_02045EC0(((struct Obj03815 *)p)->f50,P_STA_RIBBON_GetRibbonInfo(index,3));
    PRINTSYS_PrintQueColor(((struct Obj00136 *)a)->f84,(u32)func_02045770(((struct Obj03815 *)p)->f20),1,1,(u32)text,((struct Obj00136 *)a)->f80,1088);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj03815 *)p)->f50,P_STA_RIBBON_GetRibbonDescMsg(index));
    PRINTSYS_PrintQueColor(((struct Obj00136 *)a)->f84,(u32)func_02045770(((struct Obj03815 *)p)->f24),1,1,(u32)text,((struct Obj00136 *)a)->f80,1088);
    STRBUF_Delete(text);
    ((struct Obj03815 *)p)->f8=1;
}
