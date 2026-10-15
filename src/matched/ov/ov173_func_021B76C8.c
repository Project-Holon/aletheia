/*
 * function: POKE_SUMMARY_ACTOR_RegisterResources
 * address: 0x021B76C8
 * packet: pkt_ov173_021B76C8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021B789E; the next function starts at 0x021B78A0.
 * abi: ABF0 and 185F0 returns are consumed; 185F0 preserves the passed r0 pointer. D7C8's three legacy trailing inputs are neither read nor forwarded to its zero-argument D060 and two-argument 490F4 callees, and this caller supplies only heap in r0.
 * symbols:
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 */
#include "../include/Obj01267.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 APP_ICON_GetArchiveId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern u32 APP_ICON_GetTypeCellFileId(u32);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern u32 APP_ICON_GetTouchBarFileId(void);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern u32 APP_ICON_GetTypePaletteFileId(u32);
extern u32 APP_ICON_GetTypeAnimFileId(u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern int POKEGRA_OpenHandle(int);
extern void *POKE_TOOL_Dummy(void *);
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);
extern int POKEGRA_RegisterPalettePP(int,void *,int,int,u16,u16);
extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
void POKE_SUMMARY_ACTOR_RegisterResources(char *p,void *other)
{
    void *bank;
    u32 i;
    u32 first;
    int second;
    void *mon;
    u32 save;
    bank=func_020490F4(APP_ICON_GetArchiveId(),79);
    ((struct Obj01267 *)p)->f70=CLACT_RegisterCharacter(bank,APP_ICON_GetMoveKindAnimFileId(),0,1,79);
    ((struct Obj01267 *)p)->f74=CLACT_RegisterCharacter(other,17,0,1,79);
    ((struct Obj01267 *)p)->f78=CLACT_RegisterCharacter(other,26,0,1,79);
    for(i=4;i<8;i++) *(int *)(p+i*4+0x70)=CLACT_RegisterCharacter(bank,APP_ICON_GetTypeCellFileId(0),0,0,79);
    ((struct Obj01267 *)p)->f7C=CLACT_RegisterCharacter(other,23,0,1,79);
    ((struct Obj01267 *)p)->f94=CLACT_RegisterPaletteEx(bank,APP_ICON_GetMoveKindPaletteFileId(),1,0,0,4,79);
    ((struct Obj01267 *)p)->f98=CLACT_RegisterPaletteEx(other,5,1,128,0,1,79);
    ((struct Obj01267 *)p)->f9C=CLACT_RegisterPaletteEx(bank,APP_ICON_GetTouchBarFileId(),1,192,0,3,79);
    ((struct Obj01267 *)p)->fA0=CLACT_RegisterPalette(bank,APP_ICON_GetTouchBarFileId(),0,0,79);
    first=APP_ICON_GetStatusCellFileId(1);
    ((struct Obj01267 *)p)->fB8=CLACT_RegisterCellAnim(bank,first,APP_ICON_GetStatusPaletteFileId(1),79);
    ((struct Obj01267 *)p)->fBC=CLACT_RegisterCellAnim(other,7,8,79);
    first=APP_ICON_GetTypePaletteFileId(1);
    ((struct Obj01267 *)p)->fC0=CLACT_RegisterCellAnim(bank,first,APP_ICON_GetTypeAnimFileId(1),79);
    ((struct Obj01267 *)p)->fC4=CLACT_RegisterCellAnim(other,24,25,79);
    ((struct Obj01267 *)p)->fC8=CLACT_RegisterCellAnim(other,27,28,79);
    ARC_TOOL_DeleteHandle(bank);
    second=POKEGRA_OpenHandle(79);
    mon=POKE_TOOL_Dummy(**(void ** *)&((struct Obj01267 *)p)->f0);
    save=POKE_TOOL_DecodeBoxParam(mon);
    ((struct Obj01267 *)p)->f90=POKEGRA_RegisterCgrPP(second,mon,0,0,79);
    ((struct Obj01267 *)p)->fA4=POKEGRA_RegisterPalettePP(second,mon,0,0,128,79);
    ((struct Obj01267 *)p)->fCC=POKEGRA_RegisterCellAnimPP((u32)mon,0,1,0,79);
    POKE_TOOL_EncodeBoxParam(mon,save);
    ARC_TOOL_DeleteHandle((void *)second);
}
