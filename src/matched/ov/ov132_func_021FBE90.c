/*
 * function: func_021FBE90
 * address: 0x021FBE90
 * packet: pkt_ov132_021FBE90
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACTING_GetSlot 0x021F9DB0 thumb ov132
 *   STA_ACT_OBJ_SetEntryTarget 0x021F6B9C thumb ov112
 *   STA_ACT_OBJ_GetEntryTarget 0x021F6BB0 thumb ov112
 *   func_02030734 0x02030734 arm
 *   VEC_Subtract 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FBF74 0x021FBF74 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj02193.h"
#include "../include/Obj05402.h"
#include "../include/Obj08167.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *STA_ACTING_GetActObj(void *);
extern u32 *STA_ACTING_GetSlot(void *,u8);
extern void STA_ACT_OBJ_SetEntryTarget(void *,u32 *,u32 *);
extern void STA_ACT_OBJ_GetEntryTarget(void *,u32 *,u32 *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void VEC_Subtract(void *,void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FBF74(int,char *);
extern const char d_021FDD00[];
int func_021FBE90(int unused,char *p)
{
    char *owner,*q;
    u32 pos[3];
    int delta[3];
    u32 e,d,c,b,a;
    u32 *target;
    void *ctx;
    owner=*(char * *)&((struct Obj05402 *)p)->f0;
    a=VM_GetU32(((struct Obj05402 *)p)->f4);
    b=VM_GetU32(((struct Obj05402 *)p)->f4);
    c=VM_GetU32(((struct Obj05402 *)p)->f4);
    d=VM_GetU32(((struct Obj05402 *)p)->f4);
    e=VM_GetU32(((struct Obj05402 *)p)->f4);
    ctx=STA_ACTING_GetActObj(((struct Obj08167 *)owner)->f34);
    target=STA_ACTING_GetSlot(((struct Obj08167 *)owner)->f34,a);
    if (b==0) {
        pos[0]=c;pos[1]=d;pos[2]=e;
        STA_ACT_OBJ_SetEntryTarget(ctx,target,pos);
    } else {
        q=func_02030734(((struct Obj08167 *)owner)->f0,56,0,d_021FDD00,0x601);
        *(char * *)&((struct Obj02193 *)q)->f30=owner;
        *(u32 * *)&((struct Obj02193 *)q)->f0=target;
        ((struct Obj02193 *)q)->f4=((struct Obj08167 *)owner)->f34;
        ((struct Obj02193 *)q)->f2E=0;
        STA_ACT_OBJ_GetEntryTarget(ctx,target,(u32 *)(q+8));
        ((struct Obj02193 *)q)->f14=c;((struct Obj02193 *)q)->f18=d;((struct Obj02193 *)q)->f1C=e;
        ((struct Obj02193 *)q)->f2C=b;
        VEC_Subtract(q+20,q+8,delta);
        ((struct Obj02193 *)q)->f20=delta[0]/(int)b;
        ((struct Obj02193 *)q)->f24=delta[1]/(int)b;
        ((struct Obj02193 *)q)->f28=delta[2]/(int)b;
        ((struct Obj02193 *)q)->f34=func_021FADA0(owner,(u32)func_021FBF74,(u32)q,10);
    }
    return 0;
}
