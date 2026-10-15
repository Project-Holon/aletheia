/*
 * function: BR_BTN_UpdateCollapse
 * address: 0x021FA920
 * packet: pkt_ov186_021FA920
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_BTN_SetAnimMode 0x021FAD18 thumb ov186
 *   BR_BTN_SetDrawPriority 0x021FAFA0 thumb ov186
 *   BR_BTN_StepAnim 0x021FAD74 thumb ov186
 *   BR_BTN_SetTailSelection 0x021FA21C thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_BTN_UpdatePress 0x021FA500 thumb ov186
 *   d_02200358 0x02200358 data a4
 */
#include "../include/Obj02234.h"
typedef unsigned char u8;
extern int BR_BTN_DATA_GetRowField(void *,int);
extern void BR_BTN_SetAnimMode(char *,int,const int *);
extern int BR_BTN_SetDrawPriority(void *,int),BR_BTN_StepAnim(char *);
extern void BR_BTN_SetTailSelection(u8 *,int);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_UpdatePress(void *,int *,u8 *);
extern const int d_02200358[];
void BR_BTN_UpdateCollapse(int *task,int *state,u8 *ctx)
{
    int position[2];
    int i;
    int ready;
    switch(*state) {
    case 0:
        for(i=0;i<ctx[0x3B];i++) {
            if(i==ctx[0x3B]-1) {
                position[0]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),0);
                position[1]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),1);
                BR_BTN_SetAnimMode(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,3,position);
                BR_BTN_SetDrawPriority(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,1);
            } else BR_BTN_SetAnimMode(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,4,(const int *)((unsigned)d_02200358+(ctx[0x3B]-i-2)*8));
        }
        for(i=0;i<ctx[0x39];i++)BR_BTN_SetDrawPriority(*(char * *)&((struct Obj02234 *)ctx)->f40+i*0x44,3);
        *state=1;
        break;
    case 1:
        ready=1;
        for(i=0;i<ctx[0x3B];i++)ready&=BR_BTN_StepAnim(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44);
        if(ready){BR_BTN_SetTailSelection(ctx,1);*state=2;}
        break;
    case 2:BR_UTIL_SetTaskStep(task,(int)BR_BTN_UpdatePress);break;
    }
}
