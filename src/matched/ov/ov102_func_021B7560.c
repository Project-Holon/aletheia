/*
 * function: func_021B7560
 * address: 0x021B7560
 * packet: pkt_ov102_021B7560
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: repeat the callback call in cases 0,1,2; cross-jumping preserves the case-0 branch into case 2. A grouped case or pointer join loses two bytes and pool alignment.
 * prototype: 3064C forwards all three inputs, including size 0x40000, to 0202FDC4; 3159C full body leaves allocated pointer live in r0; 879C preserves visible unused heap. 78F4 forwards to full 7C1C ldr r0,[r0];bx lr.
 * symbols:
 * func_0203064C 0x0203064C arm
 * func_0203159C 0x0203159C arm
 * func_02082BCC 0x02082BCC arm
 * func_021B7C20 0x021B7C20 thumb ov102
 * func_021B7860 0x021B7860 thumb ov102
 * func_021B7908 0x021B7908 thumb ov102
 * func_02012138 0x02012138 thumb
 * func_021B8464 0x021B8464 thumb ov102
 * func_021B7CC8 0x021B7CC8 thumb ov102
 * func_0201F73C 0x0201F73C thumb
 * func_021B7DFC 0x021B7DFC thumb ov102
 * func_021B7D38 0x021B7D38 thumb ov102
 * func_021B7E60 0x021B7E60 thumb ov102
 * func_02041F6C 0x02041F6C arm
 * func_02041FB0 0x02041FB0 arm
 * func_021B879C 0x021B879C thumb ov102
 * func_020120F4 0x020120F4 thumb
 * func_02012EBC 0x02012EBC thumb
 * func_020070A4 0x020070A4 thumb
 * func_0200A8A0 0x0200A8A0 thumb
 * func_021B8934 0x021B8934 thumb ov102
 * func_021B78F4 0x021B78F4 thumb ov102
 * func_021B7CBC 0x021B7CBC thumb ov102
 * func_021B7CC0 0x021B7CC0 thumb ov102
 * func_021B70DC 0x021B70DC thumb ov101
 * func_021B7F08 0x021B7F08 thumb ov102
 * func_021B8320 0x021B8320 thumb ov102
 * func_021B81B0 0x021B81B0 thumb ov102
 * GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 * func_021B63CC 0x021B63CC thumb ov101
 * d_021B8AD4 0x021B8AD4 data a4
 */
#include "../include/Obj03229.h"
#include "../include/Obj22136.h"
#include "../include/Obj22137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern void func_0203064C(u32 src,u32 dst,u32 size);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void func_021B7C20(u32 *,u16);
extern void func_021B7860(char *,u32);
extern void func_021B7908(u32 *,u16);
struct Big;
struct Ctx;
struct Sub02007084Ctrl;
extern u32 func_02012138(const struct Ctx *p);
struct Row;
struct State;
extern void func_021B8464(struct State *p, int bg, const struct Row *rows, int count, void *object, u16 heap);
extern void func_021B7CC8(void *,int,int,u8,u8,u8,u8,u16);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021B7DFC(u8 *,void *,int,int,s16);
extern void func_021B7D38(u8 *,int,int,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B7E60(u8 *,void *,int);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B879C(void *,u32);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern void *func_0200A8A0(void *);
extern void func_021B8934(u8 *a, void *b, void *c, int d);
extern unsigned func_021B78F4(unsigned *p);
extern int func_021B7CBC(void *);
extern int func_021B7CC0(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B7F08(unsigned p, unsigned x);
extern void func_021B8320(u8 *,u16 *),func_021B81B0(u8 *,u16 *);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021B63CC(int *,int);
extern u32 d_021B8AD4[];
int func_021B7560(void *owner,int unused,void *arg)
{
    u8 *p;
    void *save;
    u32 handle;
    int first,second;
    func_0203064C(1,59,0x40000);
    p=func_0203159C(owner,0x4a4,59);
    func_02082BCC(p,0,0x4a4);
    ((struct Obj03229 *)p)->f48C=arg;
    func_021B7C20((u32 *)(p+0x9c),59);
    func_021B7860((char *)p,59);
    func_021B7908((u32 *)(p+0x94),59);
    if(**(void ** *)&((struct Obj03229 *)p)->f48C) func_02012138(**(void ** *)&((struct Obj03229 *)p)->f48C);
    func_021B8464((struct State *)(p+0xc0),2,(const struct Row *)d_021B8AD4,2,p+0x9c,59);
    func_021B7CC8(p+0xac,5,1,18,30,5,8,59);
    func_0201F73C(((struct Obj03229 *)p)->fAC,0,(u16)(((struct Obj03229 *)p)->f94),6);
    func_021B7DFC(p+0xac,p+0x9c,5,0,0);
    func_021B7D38(p+0x46c,7,6,3,20,5,8,1,1,59);
    func_021B7E60(p+0x46c,p+0x9c,10);
    func_02041F6C(7,3,0x1000);
    func_02041F6C(7,6,0x1000);
    func_02041FB0(7,9,128);
    func_02041FB0(7,12,40);
    func_021B879C(p+0xfc,59);
    save=**(void ** *)&((struct Obj03229 *)p)->f48C;
    if(save) save=func_02012EBC(func_020120F4(save));
    else save=func_020070A4();
    func_021B8934((u8 *)((int)(p+0x118)),(void *)((int)p),(void *)((int)func_0200A8A0(save)),59);
    handle=func_021B78F4((unsigned int *)p);
    first=func_021B7CBC(p+0x9c);
    second=func_021B7CC0(p+0x9c);
    ((struct Obj03229 *)p)->f468=func_021B70DC(2,handle,0,14,0,2,first,second,59);
    switch(((struct Obj22136 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f8) {
    case 0: func_021B7F08((unsigned int)p,(unsigned int)func_021B81B0); break;
    case 1: func_021B7F08((unsigned int)p,(unsigned int)func_021B8320); break;
    case 2: func_021B7F08((unsigned int)p,(unsigned int)func_021B81B0); break;
    }
    GFL_USE_CancelChangeAndStopBgm();
    func_021B63CC(*(int * *)&((struct Obj22137 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f4,0);
    return 1;
}
