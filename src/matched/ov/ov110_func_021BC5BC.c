/*
 * function: func_021BC5BC
 * address: 0x021BC5BC
 * packet: pkt_ov110_021BC5BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: C564 full body writes both signed-halfword base coordinates;
 *   position x/y initialized before sprite read. Descriptor getters return
 *   u8; all arithmetic uses promoted values and observed halfword wrapping.
 *   B404 third extern is u16 because original truncates just before call;
 *   own B404 full body forwards only that value as the selector. Font pointer
 *   preserves BAC44 full 32-bit payload. Sentinel returns before any local
 *   read. All other prototypes copied from full own matched bodies/units.
 * symbols:
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BC564 0x021BC564 thumb ov110
 *   PMSI_PARAM_IsDecoWord 0x02024508 thumb
 *   PMSI_PARAM_GetDecoId 0x02024520 thumb
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_021BC6D0 0x021BC6D0 thumb ov110
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_020416D4 0x020416D4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   PMS_WORD_LoadString 0x02024838 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 */
#include "../include/Obj10277.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Vec2 { s16 x,y; } Vec2;
struct Descriptor;
struct Obj;
extern u32 func_021BAC44(u8 *);
extern void func_021BC564(s16 *p, s16 *out);
extern u32 PMSI_PARAM_IsDecoWord(u32);
extern u32 PMSI_PARAM_GetDecoId(u32);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern u32 func_021BC6D0(u32);
extern u8 BMP_WIN_GetPosX(struct Descriptor *);
extern u8 BMP_WIN_GetPosY(struct Descriptor *);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern u8 func_020416D4(u32);
extern void CLACT_SetActorBgPriority(struct Obj *,u32);
extern void PMS_WORD_LoadString(u32,void *,u32);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
void func_021BC5BC(u8 *p,struct Descriptor *window,const Vec2 *input,u32 id,struct Obj *sprite)
{
    Vec2 base;
    Vec2 pos;
    u32 font;
    u32 index;
    u32 layer;
    font=func_021BAC44(*(u8 * *)&((struct Obj10277 *)p)->f0);
    if(id==0xffff) return;
    func_021BC564((s16 *)input,(s16 *)(&base));
    if(PMSI_PARAM_IsDecoWord(id)!=0) {
        index=PMSI_PARAM_GetDecoId(id)-1;
        layer=func_021BC6D0(BMP_WIN_GetBgLayer(window));
        pos.x=base.x+BMP_WIN_GetPosX(window)*8;
        pos.y=base.y+BMP_WIN_GetPosY(window)*8;
        if(layer==1) pos.y+=192;
        CLACT_SetActorAnimSeq(sprite,index);
        CLACT_AddActorSurfacePos(sprite,&pos,(u16)layer);
        CLACT_SetActorDrawEnable(sprite,1);
        CLACT_SetActorBgPriority(sprite,func_020416D4(BMP_WIN_GetBgLayer(window)));
    } else {
        PMS_WORD_LoadString(id,((struct Obj10277 *)p)->f30,42);
        GF_FONT_SetTextColor(3,4,14);
        PRINTSYS_Print(BMP_WIN_GetBmp(window),base.x,base.y,((struct Obj10277 *)p)->f30,(void *)font);
    }
}
