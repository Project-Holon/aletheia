/*
 * function: func_021FEEF4
 * address: 0x021FEEF4
 * packet: pkt_ov186_021FEEF4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: sub_0204B294 returns the allocated object pointer in r0.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   sub_02034714 0x02034714 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   sub_0204B294 0x0204B294 arm
 *   sub_0204B570 0x0204B570 arm
 *   sub_0204B5D4 0x0204B5D4 arm
 *   sub_0204B688 0x0204B688 arm
 *   sub_0204B3DC 0x0204B3DC arm
 *   d_02200D88 0x02200D88 data a4
 */
#include "../include/Obj02527.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {int x,y,z;} Triple;
typedef struct {short x,y,z,pad;u32 word8,wordC,mode,word14;} Config;
typedef struct {short x,y,z;u8 pad,flag;} Request;
struct Actor;
struct Obj;
extern void func_02082BCC(void *,u32,u32);
extern int func_021FC124(char *,int,Triple *);
extern void sub_02034714(const char *,u32,const char *);
extern struct Obj *sub_0204B294(void *owner,u32 i,u32 j,u32 k,const void *position,u16 space,u16 heap);
extern void sub_0204B570(struct Actor *,u32);
extern void sub_0204B5D4(struct Actor *,u32,u32);
extern void sub_0204B688(struct Actor *,u32);
extern void sub_0204B3DC(struct Obj *,u32);
extern const char d_02200D88[];
static inline int roundFixed(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}
void func_021FEEF4(char *p,u32 owner,char *resources,const Config *config,u16 heap)
{
    Triple triple;
    Request request;
    int index;
    func_02082BCC(p,0,0x4c);
    *(Config *)(p+0x34)=*config;
    index=4;
    if(config->mode)index=5;
    if(!func_021FC124(resources,index,&triple))sub_02034714(d_02200D88,0,d_02200D88);
    func_02082BCC(&request,0,sizeof(request));
    request.x=config->x;
    request.y=config->y;
    request.flag=1;
    ((struct Obj02527 *)p)->f8=roundFixed(request.x);
    ((struct Obj02527 *)p)->fC=roundFixed(request.y);
    *(int *)&((struct Obj02527 *)p)->f14=config->z;
    *(u32 *)&((struct Obj02527 *)p)->f4=(u32)sub_0204B294((void *)owner,triple.y,triple.z,triple.x,&request,((struct Obj02527 *)p)->f44,heap);
    sub_0204B570(*(struct Actor * *)&((struct Obj02527 *)p)->f4,2);
    sub_0204B5D4(*(struct Actor * *)&((struct Obj02527 *)p)->f4,((struct Obj02527 *)p)->f14,0);
    sub_0204B688(*(struct Actor * *)&((struct Obj02527 *)p)->f4,0);
    sub_0204B3DC(*(struct Obj * *)&((struct Obj02527 *)p)->f4,0);
    ((struct Obj02527 *)p)->f0=1;
}
