/*
 * function: func_021FB2B0
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
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_02030734 0x02030734 arm
 *   VEC_Subtract 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB528 0x021FB528 thumb ov132
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
extern int func_021FB1F4(char *,int);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void VEC_Subtract(void *,void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FB528(int,char *);
extern const char d_021FDD00[];
int func_021FB2B0(int unused,char *p)
{
    int mask;
    char *owner,*q,*target;
    Vec pos;
    int delta[3];
    u32 wait,z,y,x,rate;
    char *ctx;
    u8 i;
    owner=*(char * *)&((struct Obj03821 *)p)->f0;
    mask=func_021FB1F4(p,VM_GetU32(((struct Obj03821 *)p)->f4));
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
                func_021F8054(ctx,(u32 *)target,(const u32 *)(&pos));
            } else {
                q=func_02030734(((struct Obj08162 *)owner)->f0,56,0,d_021FDD00,0x2DA);
                *(char * *)&((struct Obj02192 *)q)->f30=owner;
                *(char * *)&((struct Obj02192 *)q)->f0=target;
                ((struct Obj02192 *)q)->f4=((struct Obj08162 *)owner)->f34;
                ((struct Obj02192 *)q)->f2E=0;
                func_021F8044(ctx,(u32 *)target,(u32 *)(q+8));
                ((struct Obj02192 *)q)->f14=x;((struct Obj02192 *)q)->f18=y;((struct Obj02192 *)q)->f1C=z;
                ((struct Obj02192 *)q)->f2C=rate;
                VEC_Subtract(q+20,q+8,delta);
                ((struct Obj02192 *)q)->f20=delta[0]/(int)rate;
                ((struct Obj02192 *)q)->f24=delta[1]/(int)rate;
                ((struct Obj02192 *)q)->f28=delta[2]/(int)rate;
                ((struct Obj02192 *)q)->f34=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    if(wait==1) {((struct Obj03821 *)p)->f14=rate;return 1;}
    return 0;
}
