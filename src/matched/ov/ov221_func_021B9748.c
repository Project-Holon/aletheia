/*
 * function: CHIHOU_ZUKAN_AWARD_Exit
 * address: 0x021B9748
 * packet: pkt_ov221_021B9748
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9770 hardware DISPCNT sub masked read.
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   CHIHOU_ZUKAN_AWARD_DeleteActor 0x021B9CCC thumb ov221
 *   CHIHOU_ZUKAN_AWARD_DeleteWindows 0x021B9AEC thumb ov221
 *   CHIHOU_ZUKAN_AWARD_Noop 0x021B9960 thumb ov221
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete 0x021B9F20 thumb ov221
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   d_021BA148 0x021BA148 data a4
 */
#include "../include/Obj02557.h"
struct Node; struct PrintSys;
typedef enum { LAYER_FIRST=0,LAYER_LIMIT=1 } Layer;
extern const unsigned d_021BA148[][11];
typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void CHIHOU_ZUKAN_AWARD_DeleteActor(char *);
extern void CHIHOU_ZUKAN_AWARD_DeleteWindows(char *);
extern void CHIHOU_ZUKAN_AWARD_Noop(char *);
extern void func_02030EAC(struct Node *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char *);
struct Proc;
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
int CHIHOU_ZUKAN_AWARD_Exit(void *owner,void *unused1,void *unused2,char *p)
{
    Layer i=LAYER_FIRST;
    do {
        BG_SYS_FreeLayerBuf((unsigned char)d_021BA148[i][0]);
        i++;
    } while((unsigned)i<1);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    CHIHOU_ZUKAN_AWARD_DeleteActor(p);
    CHIHOU_ZUKAN_AWARD_DeleteWindows(p);
    CHIHOU_ZUKAN_AWARD_Noop(p);
    func_02030EAC(*(struct Node * *)&((struct Obj02557 *)p)->f14);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj02557 *)p)->f10);
    PRINTSYS_QUE_Delete(((struct Obj02557 *)p)->f10);
    GF_FONT_Delete(((struct Obj02557 *)p)->fC);
    CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(*(char * *)&((struct Obj02557 *)p)->f8);
    func_020315D4((struct Proc *)owner);
    GFL_HEAP_DeleteChecked(0x83);
    return 1;
}
