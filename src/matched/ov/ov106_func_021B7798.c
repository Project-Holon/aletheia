/*
 * function: IRC_RANKING_ProcExit
 * address: 0x021B7798
 * packet: pkt_ov106_021B7798
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RANKING_LabelDelete 0x021B9360 thumb ov106
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   IRC_RANKING_ListExit 0x021B8304 thumb ov106
 *   IRC_RANKING_InertiaExit 0x021B8FC4 thumb ov106
 *   IRC_RANKING_InputExit 0x021B8D9C thumb ov106
 *   IRC_RANKING_SeqClear 0x021B78AC thumb ov106
 *   IRC_RANKING_DisplayExit 0x021B807C thumb ov106
 *   IRC_RANKING_DataDelete 0x021B8D5C thumb ov106
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj03744.h"
typedef unsigned char u8;
struct PrintSys;
struct Rec;
struct S020315D4;
extern void IRC_RANKING_LabelDelete(u8 *p);
extern void IRC_APPBAR_Delete(void *);
extern void IRC_RANKING_ListExit(u8 *p);
extern void IRC_RANKING_InertiaExit(void *);
extern void IRC_RANKING_InputExit(void *);
extern void IRC_RANKING_SeqClear(void *);
extern void IRC_RANKING_DisplayExit(u8 *p);
extern void IRC_RANKING_DataDelete(u8 *p);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void BMP_OAM_DeleteSys(void *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void GAME_DATA_Delete(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int IRC_RANKING_ProcExit(void *a,int b,int *state,u8 *p)
{
 int i;
 for(i=0;i<4;i++)IRC_RANKING_LabelDelete(*(void **)(p+0x62C+i*4));
 CLACT_ReleasePalette((u32)(((struct Obj03744 *)p)->f644));
 IRC_APPBAR_Delete(((struct Obj03744 *)p)->f614);
 IRC_RANKING_ListExit(p+0x38);
 IRC_RANKING_InertiaExit(p+0x600); IRC_RANKING_InputExit(p+0x5D4);IRC_RANKING_SeqClear(p+0x28);
 BMP_OAM_DeleteSys(((struct Obj03744 *)p)->f624);IRC_RANKING_DisplayExit(p);IRC_RANKING_DataDelete(((struct Obj03744 *)p)->f63C);
 MSGDATA_Delete(((struct Obj03744 *)p)->f620);GF_FONT_Delete(((struct Obj03744 *)p)->f618);PRINTSYS_QUE_Delete(((struct Obj03744 *)p)->f61C);
 if(*state==0)GAME_DATA_Delete(((struct Obj03744 *)p)->f628);
 func_020315D4(a);GFL_HEAP_DeleteChecked(67);return 1;
}
