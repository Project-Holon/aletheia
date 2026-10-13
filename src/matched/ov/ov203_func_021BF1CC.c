/*
 * function: func_021BF1CC
 * address: 0x021BF1CC
 * packet: pkt_ov203_021BF1CC
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 *   func_021BEFC4 0x021BEFC4 thumb ov203
 */
#include "../include/Obj01291.h"
#include "../include/Obj25324.h"
typedef unsigned int   u32;
extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);
struct Owner;
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);
extern void func_021BEFC4(struct Owner *owner, int mask, int kind, int start, int end, int duration, int *counter);
void func_021BF1CC(void *task,char *work)
{
    if(((struct Obj25324 *)(*(char * *)&((struct Obj01291 *)work)->f0))->fC) {
        BRIGHTNESS_Set(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
        TCBL_DeleteTask(task);return;
    }
    switch(((struct Obj01291 *)work)->f8) {
    case 0:
        if(((struct Obj01291 *)work)->f14==0) {
            func_021BEFC4((struct Owner *)(*(char * *)&((struct Obj01291 *)work)->f0),*(int *)&((struct Obj01291 *)work)->f18,*(int *)&((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->fA,((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f10,(int *)(work+0x14));
            (((struct Obj01291 *)work)->f8)++;
        }
        break;
    case 1:
        if(((struct Obj01291 *)work)->f14) return;
        break;
    }
    BRIGHTNESS_Set(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
    TCBL_DeleteTask(task);
}
