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
 *   func_02023F60 0x02023F60 thumb
 *   func_02031194 0x02031194 arm
 *   func_021BEFC4 0x021BEFC4 thumb ov203
 */
#include "../include/Obj01291.h"
#include "../include/Obj25324.h"
typedef unsigned int   u32;
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02031194(void *);
extern void func_021BEFC4(char *,int,int,int,int,int,int *);
void func_021BF1CC(void *task,char *work)
{
    if(((struct Obj25324 *)(*(char * *)&((struct Obj01291 *)work)->f0))->fC) {
        func_02023F60(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
        func_02031194(task);return;
    }
    switch(((struct Obj01291 *)work)->f8) {
    case 0:
        if(((struct Obj01291 *)work)->f14==0) {
            func_021BEFC4(*(char * *)&((struct Obj01291 *)work)->f0,*(int *)&((struct Obj01291 *)work)->f18,*(int *)&((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->fA,((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f10,(int *)(work+0x14));
            (((struct Obj01291 *)work)->f8)++;
        }
        break;
    case 1:
        if(((struct Obj01291 *)work)->f14) return;
        break;
    }
    func_02023F60(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
    func_02031194(task);
}
