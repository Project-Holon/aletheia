/*
 * unit: yes
 * function: STA_ACT_LIGHT_HandleElemAnim, STA_ACT_LIGHT_NoOp2, STA_ACT_LIGHT_NoOp3
 * address: 0x021F79A8
 * packet: pkt_ov112_021F79A8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Thumb followers7A80 (18 code+2 zero padding7A92) and7A94 (BX LR+2 zero padding7A96), parent-cleared.
 * ABI: 514C retains caller's explicitly loaded r1 halfword although its own legacy body ignores that input.
 * symbols:
 *   MUSICAL_MCSS_NoOp5 0x021F4F10 thumb ov112
 *   MUSICAL_MCSS_GetElemB 0x021F514C thumb ov112
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   STA_ACT_LIGHT_AnimA 0x021F7AEC thumb ov112
 *   STA_ACT_LIGHT_AnimC 0x021F7C90 thumb ov112
 *   STA_ACT_LIGHT_AnimE 0x021F7E2C thumb ov112
 *   STA_ACT_LIGHT_AnimG 0x021F7FA8 thumb ov112
 *   STA_ACT_LIGHT_StopSe 0x021F7A98 thumb ov112
 *   STA_ACT_LIGHT_AnimB 0x021F7BA8 thumb ov112
 *   STA_ACT_LIGHT_AnimD 0x021F7D30 thumb ov112
 *   STA_ACT_LIGHT_AnimF 0x021F7ECC thumb ov112
 *   STA_ACT_LIGHT_AnimH 0x021F7FAC thumb ov112
 *   d_021F832C 0x021F832C data a4
 */
#include "../include/Obj03248.h"
#include "../include/Obj13841.h"
#include "../include/Obj22558.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 MUSICAL_MCSS_NoOp5(u8 *);
extern unsigned char MUSICAL_MCSS_GetElemB(void *p, int i);
extern void GFL_USE_PlaySeInSlot(void *,int);
extern void *d_021F832C[];
extern void STA_ACT_LIGHT_AnimA(char *,char *);
extern void STA_ACT_LIGHT_AnimC(char *,char *);
extern void STA_ACT_LIGHT_AnimE(char *,char *);
extern void STA_ACT_LIGHT_AnimG(char *,char *);
extern void STA_ACT_LIGHT_StopSe(char *,char *);
extern void STA_ACT_LIGHT_AnimB(u8 *,u8 *);
extern void STA_ACT_LIGHT_AnimD(u8 *p, u8 *q);
extern void STA_ACT_LIGHT_AnimF(char *,char *);
extern void STA_ACT_LIGHT_AnimH(char *,char *);
void STA_ACT_LIGHT_NoOp3(char *,char *);
void STA_ACT_LIGHT_HandleElemAnim(char *p,char *q,int index)
{
    u32 v;
    if(*(int *)(q+132+index*4)==0 || *(int *)&((struct Obj03248 *)q)->f104!=0) return;
    v=MUSICAL_MCSS_GetElemB((void *)MUSICAL_MCSS_NoOp5((u8 *)((struct Obj13841 *)p)->f10),**(u16 **)(q+168+index*4));
    ((struct Obj03248 *)q)->fF0=0;
    ((struct Obj03248 *)q)->fF4=index;
    ((struct Obj03248 *)q)->fF8=0;
    GFL_USE_PlaySeInSlot(d_021F832C[v],2);
    ((struct Obj13841 *)p)->f43C+=1;
    switch(v) {
    case 0: STA_ACT_LIGHT_NoOp3(p,q); *(void (**)(char *,char *))(q+260)=STA_ACT_LIGHT_StopSe; break;
    case 1: STA_ACT_LIGHT_AnimA(p,q); *(void (**)(u8 *,u8 *))(q+260)=STA_ACT_LIGHT_AnimB; break;
    case 2: STA_ACT_LIGHT_AnimC(p,q); *(void (**)(char *,char *))(q+260)=(void (*)(char *, char *))STA_ACT_LIGHT_AnimD; break;
    case 3: STA_ACT_LIGHT_AnimE(p,q); *(void (**)(char *,char *))(q+260)=STA_ACT_LIGHT_AnimF; break;
    case 4: STA_ACT_LIGHT_AnimG(p,q); *(void (**)(char *,char *))(q+260)=STA_ACT_LIGHT_AnimH; break;
    }
}
int STA_ACT_LIGHT_NoOp2(char *p,char *q)
{
    if(((struct Obj22558 *)q)->f104!=0) return 1;
    return 0;
}
void STA_ACT_LIGHT_NoOp3(char *p,char *q)
{
}
