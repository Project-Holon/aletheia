/*
 * function: TH_AWARD_Exit
 * address: 0x021B9770
 * packet: pkt_ov220_021B9770
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses at 021B9794 and 021B9798/021B979E.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   TH_AWARD_DeleteWindows 0x021B9FF0 thumb ov220
 *   TH_AWARD_DeleteBgActors 0x021B9C70 thumb ov220
 *   TH_AWARD_DeleteSpeciesActors 0x021B9B20 thumb ov220
 *   TH_AWARD_Noop 0x021B99D8 thumb ov220
 *   TH_AWARD_GRAPHIC_Delete 0x021BA178 thumb ov220
 *   d_021BA370 0x021BA370 data a4
 */
#include "../include/Obj01297.h"
typedef unsigned char u8;
typedef struct {unsigned first;char pad[40];} Entry;
extern const Entry d_021BA370[];
typedef unsigned int   u32;
struct Node;
struct PrintSys;
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void TH_AWARD_DeleteWindows(u8 *p);
extern void TH_AWARD_DeleteBgActors(unsigned char *p);
extern void TH_AWARD_DeleteSpeciesActors(void *);
extern void TH_AWARD_Noop(void *);
extern void TH_AWARD_GRAPHIC_Delete(unsigned char *p);
int TH_AWARD_Exit(void *state,int unused1,int unused2,char *p)
{
    int i;
    for(i=0;i<1u;i++) func_020403F4((u8)d_021BA370[i].first);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    TH_AWARD_DeleteWindows((u8 *)p);
    TH_AWARD_DeleteBgActors((unsigned char *)p);
    TH_AWARD_DeleteSpeciesActors(p);
    TH_AWARD_Noop(p);
    func_02030EAC(((struct Obj01297 *)p)->f14);
    PRINTSYS_QUE_Clear(((struct Obj01297 *)p)->f10);
    PRINTSYS_QUE_Delete(((struct Obj01297 *)p)->f10);
    GF_FONT_Delete(((struct Obj01297 *)p)->fC);
    TH_AWARD_GRAPHIC_Delete(((struct Obj01297 *)p)->f8);
    func_020315D4(state);
    GFL_HEAP_DeleteChecked(131);
    return 1;
}
