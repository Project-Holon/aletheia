/*
 * function: func_021B70DC
 * address: 0x021B70DC
 * packet: pkt_ov101_021B70DC
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: distinct enum first/choice values preserve branch-local setup and saved-register allocation.
 * prototype: own 27F60 fixes layer/x/heap as u16; stack x/heap forward unchanged without truncation.
 * symbols:
 * func_02030734 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * func_021B732C 0x021B732C thumb ov101
 * APP_TASKMENU_RES_Create 0x02027F60 thumb
 * func_020416D4 0x020416D4 arm
 * func_021B739C 0x021B739C thumb ov101
 * func_02045B38 0x02045B38 arm
 * func_02045EC0 0x02045EC0 arm
 * APP_TASKMENU_WIN_Create 0x02027FEC thumb
 * STRBUF_Delete 0x02045808 arm
 * MSGDATA_Delete 0x02045C04 arm
 * d_021B7550 0x021B7550 data a1
 */
#include "../include/Obj03227.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { SIDE_ZERO, SIDE_ONE } Side;
typedef struct { void *str; u16 color,pad; u32 flag; } Desc;
extern char d_021B7550[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32);
extern void func_021B732C(int *p, unsigned b, int c, int unused, int unused2, u8 d, unsigned e);
struct MsgBank;
struct R;
struct Rec;
struct U16Vec;
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u8 func_020416D4(u32);
extern void func_021B739C(unsigned *p, unsigned b, int c, unsigned d, u8 e, u16 f);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void *func_021B70DC(u32 a,u32 b,u16 layer,u16 x,u8 y,u32 extra,u32 c,u32 d,u16 heap)
{
    Side side=SIDE_ZERO;
    Desc desc;
    char *p;
    void *bank;
    Side choice,first;
    p=func_02030734(heap,96,0,d_021B7550,125);
    MI_CpuFill8(p,0,96);
    ((struct Obj03227 *)p)->f3C=layer;
    ((struct Obj03227 *)p)->f44=side-1;
    ((struct Obj03227 *)p)->f48=side-1;
    ((struct Obj03227 *)p)->f54=side;
    ((struct Obj03227 *)p)->f58=heap;
    ((struct Obj03227 *)p)->f5C=1;
    if(layer>=4) { side=1; first=1; choice=4; }
    else { first=0; choice=0; }
    func_021B732C((int *)p,first,choice,extra,x,y,heap);
    ((struct Obj03227 *)p)->f4=APP_TASKMENU_RES_Create(layer,x,c,d,heap);
    func_021B739C((unsigned int *)p,b,a,side,func_020416D4(layer),heap);
    bank=func_02045B38(0,2,49,heap);
    MI_CpuFill8(&desc,0,12);
    desc.color=0x39e3;
    desc.str=func_02045EC0(bank,8);
    desc.flag=1;
    ((struct Obj03227 *)p)->f0=APP_TASKMENU_WIN_Create((u32)(((struct Obj03227 *)p)->f4),(u32)(&desc),19,21,13,heap);
    STRBUF_Delete(desc.str);
    MSGDATA_Delete(bank);
    return p;
}
