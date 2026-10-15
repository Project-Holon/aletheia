/*
 * function: BR_CODEIN_RecordStepFadeInB
 * address: 0x021DBCF4
 * packet: pkt_ov183_021DBCF4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_RecordStepDeleteProfile 0x021DBD40 thumb ov183
 */
#include "../include/Obj14422.h"
#include "../include/Obj24547.h"
#include "../include/Obj24548.h"
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_RecordStepDeleteProfile(int *task, int b, char *p);
void BR_CODEIN_RecordStepFadeInB(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        BR_FADE_Start(((struct Obj24547 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC,2,3,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24548 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC)) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepDeleteProfile);
        break;
    }
}
