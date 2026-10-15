/*
 * function: func_021B9748
 * address: 0x021B9748
 * packet: pkt_ov221_021B9748
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9770 hardware DISPCNT sub masked read.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   CHIHOU_ZUKAN_AWARD_DeleteActor 0x021B9CCC thumb ov221
 *   CHIHOU_ZUKAN_AWARD_DeleteWindows 0x021B9AEC thumb ov221
 *   CHIHOU_ZUKAN_AWARD_Noop 0x021B9960 thumb ov221
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete 0x021B9F20 thumb ov221
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021BA148 0x021BA148 data a4
 */
#include "../include/Obj02557.h"
struct Node; struct PrintSys;
typedef enum { LAYER_FIRST=0,LAYER_LIMIT=1 } Layer;
extern const unsigned d_021BA148[][11];
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void CHIHOU_ZUKAN_AWARD_DeleteActor(char *);
extern void CHIHOU_ZUKAN_AWARD_DeleteWindows(char *);
extern void CHIHOU_ZUKAN_AWARD_Noop(char *);
extern void func_02030EAC(struct Node *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
int func_021B9748(void *owner,void *unused1,void *unused2,char *p)
{
    Layer i=LAYER_FIRST;
    do {
        func_020403F4((unsigned char)d_021BA148[i][0]);
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
    func_020315D4((struct S020315D4 *)owner);
    func_020306F0(0x83);
    return 1;
}
