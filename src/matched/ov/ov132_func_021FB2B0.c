/*
 * function: SCRIPT_COMMAND_CmdSetActorPos
 * address: 0x021FB2B0
 * packet: pkt_ov132_021FB2B0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   SCRIPT_COMMAND_GetActorMask 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   func_02030734 0x02030734 arm
 *   VEC_Subtract 0x0207CA00 arm
 *   STA_ACT_SCRIPT_AddTask 0x021FADA0 thumb ov132
 *   SCRIPT_COMMAND_TaskActorMove 0x021FB528 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj02192.h"
#include "../include/Obj03821.h"
#include "../include/Obj08162.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int SCRIPT_COMMAND_GetActorMask(char *,int);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void STA_ACT_LIGHT_CopyActorPos(void *unused, u32 *p, u32 *q);
extern void STA_ACT_LIGHT_SetActorPos(void *unused, u32 *p, const u32 *q);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void VEC_Subtract(void *,void *,void *);
extern void *STA_ACT_SCRIPT_AddTask(char *,u32,u32,u32);
extern void SCRIPT_COMMAND_TaskActorMove(int,char *);
extern const char d_021FDD00[];
int SCRIPT_COMMAND_CmdSetActorPos(int unused,char *p)
{
    int mask;
    char *owner,*q,*target;
    Vec pos;
    int delta[3];
    u32 wait,z,y,x,rate;
    char *ctx;
    u8 i;
    owner=*(char * *)&((struct Obj03821 *)p)->f0;
    mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct Obj03821 *)p)->f4));
    rate=VM_GetU32(((struct Obj03821 *)p)->f4);
    x=VM_GetU32(((struct Obj03821 *)p)->f4);
    y=VM_GetU32(((struct Obj03821 *)p)->f4);
    z=VM_GetU32(((struct Obj03821 *)p)->f4);
    wait=VM_GetU32(((struct Obj03821 *)p)->f4);
    ctx=STA_ACTING_GetActorSystem(((struct Obj08162 *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=STA_ACTING_GetActor(((struct Obj08162 *)owner)->f34,i);
            if (rate==0) {
                pos.x=x;pos.y=y;pos.z=z;
                STA_ACT_LIGHT_SetActorPos(ctx,(u32 *)target,(const u32 *)(&pos));
            } else {
                q=func_02030734(((struct Obj08162 *)owner)->f0,56,0,d_021FDD00,0x2DA);
                *(char * *)&((struct Obj02192 *)q)->f30=owner;
                *(char * *)&((struct Obj02192 *)q)->f0=target;
                ((struct Obj02192 *)q)->f4=((struct Obj08162 *)owner)->f34;
                ((struct Obj02192 *)q)->f2E=0;
                STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)target,(u32 *)(q+8));
                ((struct Obj02192 *)q)->f14=x;((struct Obj02192 *)q)->f18=y;((struct Obj02192 *)q)->f1C=z;
                ((struct Obj02192 *)q)->f2C=rate;
                VEC_Subtract(q+20,q+8,delta);
                ((struct Obj02192 *)q)->f20=delta[0]/(int)rate;
                ((struct Obj02192 *)q)->f24=delta[1]/(int)rate;
                ((struct Obj02192 *)q)->f28=delta[2]/(int)rate;
                ((struct Obj02192 *)q)->f34=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskActorMove,(u32)q,10);
            }
        }
    }
    if(wait==1) {((struct Obj03821 *)p)->f14=rate;return 1;}
    return 0;
}
