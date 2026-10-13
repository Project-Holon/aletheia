/*
 * function: P_STA_SKILL_StepCursor
 * address: 0x021DB3F0
 * packet: pkt_ov131_021DB3F0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   P_STA_SKILL_SetCursor 0x021DB468 thumb ov131
 */
#include "../include/Obj00112.h"
#include "../include/Obj23169.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *P_STATUS_GetPokePara(u8 *);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern unsigned func_02017E88(void *,unsigned,unsigned);
extern void P_STA_SKILL_SetCursor(u8 *,u8 *,u8,int);
void P_STA_SKILL_StepCursor(u8 *a,u8 *b) {
    void *p;
    int i,step;
    unsigned v;
    p=P_STATUS_GetPokePara(a);
    i=b[41];
    if(KEY_GetTrg()==64) step=-1;else step=1;
    GFL_USE_PlaySeDefaultVolume(1352);
    do {
        i+=step;
        if(i<0) i=b[43]-1;
        else if(i>b[43]-1) i=0;
        if(i<4) v=(u16)func_02017E88(p,i+54,0);
        else v=((struct Obj23169 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f14;
    } while(v==0);
    P_STA_SKILL_SetCursor(a,b,i,0);
}
