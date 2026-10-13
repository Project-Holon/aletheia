/*
 * unit: yes
 * function: P_STA_SUB_UpdatePet,P_STA_SUB_StartPetReaction
 * address: 0x021D6F54
 * packet: pkt_ov131_021D6F54
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021D703C complete reset helper is included; 021D7060 is filed
 *   separately. Reset contains constant stores only, preserving order.
 * semantic: unsigned full-word state dispatch guarded at six by the
 *   original; byte counters compared directly. No signed arithmetic.
 * symbols:
 *   P_STA_SUB_StartPetReaction 0x021D703C thumb ov131
 *   P_STA_SUB_StepPetTimer 0x021D7060 thumb ov131
 *   P_STA_SUB_PetWiggle 0x021D708C thumb ov131
 *   P_STA_SUB_PetHop 0x021D7248 thumb ov131
 *   P_STA_SUB_PetRise 0x021D72E8 thumb ov131
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 */
#include "../include/Obj01740.h"
#include "../include/Obj05387.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void P_STA_SUB_StartPetReaction(void *,u8 *);
extern int P_STA_SUB_StepPetTimer(void *,u8 *,u8 *);
extern int P_STA_SUB_PetWiggle(u8 *,u8 *);
extern int P_STA_SUB_PetHop(u8 *,u8 *);
extern int P_STA_SUB_PetRise(u8 *,u8 *,int);
extern void MCSS_ResetAnmStopFlag(void *);
void P_STA_SUB_UpdatePet(u8 *p,u8 *q)
{
    switch(((struct Obj01740 *)q)->f5C) {
    case 0:
        if(q[0x78]>10) {((struct Obj01740 *)q)->f5C=1;P_STA_SUB_StartPetReaction(p,q);}
        if(q[0x80]>10) {((struct Obj01740 *)q)->f5C=2;P_STA_SUB_StartPetReaction(p,q);}
        if(q[0x88]>20) {((struct Obj01740 *)q)->f5C=3;P_STA_SUB_StartPetReaction(p,q);}
        break;
    case 1:
        P_STA_SUB_PetWiggle(p,q);
        if(P_STA_SUB_StepPetTimer(p,q,q+0x78)==0) ((struct Obj01740 *)q)->f5C=4;
        break;
    case 4:
        if(P_STA_SUB_PetWiggle(p,q)==1) ((struct Obj01740 *)q)->f5C=0;
        break;
    case 2:
        P_STA_SUB_PetHop(p,q);
        if(P_STA_SUB_StepPetTimer(p,q,q+0x80)==0) ((struct Obj01740 *)q)->f5C=5;
        break;
    case 5:
        if(P_STA_SUB_PetHop(p,q)==1) ((struct Obj01740 *)q)->f5C=0;
        break;
    case 3:
        P_STA_SUB_PetRise(p,q,1);
        if(P_STA_SUB_StepPetTimer(p,q,q+0x88)==0) ((struct Obj01740 *)q)->f5C=6;
        break;
    case 6:
        if(P_STA_SUB_PetRise(p,q,0)==1) {
            MCSS_ResetAnmStopFlag(((struct Obj01740 *)q)->f0);
            ((struct Obj01740 *)q)->f5C=0;
        }
        break;
    }
}
typedef unsigned short u16;
void P_STA_SUB_StartPetReaction(void *unused,u8 *q)
{
    ((struct Obj05387 *)q)->f58=1;
    ((struct Obj05387 *)q)->f64=0;
    ((struct Obj05387 *)q)->f68=0;
    ((struct Obj05387 *)q)->f62=0;
    ((struct Obj05387 *)q)->f66=0;
    ((struct Obj05387 *)q)->f60=0;
}
