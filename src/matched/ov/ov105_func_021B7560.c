/*
 * function: func_021B7560
 * address: 0x021B7560
 * packet: pkt_ov105_021B7560
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: Caller-only tu --suggest-split confirmed no viable partition
 * with unresolved80D8; parent-cleared leaf now verified in its own shard.
 * prototype: 3159C and 78D4 forward full-word allocation/accessor r0;
 * callers read it. Explicit third 3064C and sixth 7F78 inputs retained.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012138 0x02012138 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02041F6C 0x02041F6C arm
 *   func_02041FB0 0x02041FB0 arm
 *   func_021B784C 0x021B784C thumb ov105
 *   func_021B7C20 0x021B7C20 thumb ov105
 *   func_021B7CB0 0x021B7CB0 thumb ov105
 *   func_021B7D20 0x021B7D20 thumb ov105
 *   func_021B7E48 0x021B7E48 thumb ov105
 *   func_021B8348 0x021B8348 thumb ov105
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B7F78 0x021B7F78 thumb ov105
 *   func_021B78D4 0x021B78D4 thumb ov105
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B728C 0x021B728C thumb ov101
 *   func_021B84B4 0x021B84B4 thumb ov105
 *   func_021B8840 0x021B8840 thumb ov105
 *   func_021B80BC 0x021B80BC thumb ov105
 *   func_021B80D8 0x021B80D8 thumb ov105
 */
#include "../include/Obj03234.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4; u8 high:4; u8 tail[32]; } Data;
typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display;
struct Task;
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(struct Task *,u32,u32);
extern void func_02082BCC(void *,int,int);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern void func_0201F73C(void *,int,u16,int);
extern void func_02041F6C(u32,u32,u16),func_02041FB0(u32,u32,u16);
extern void func_021B784C(u8 *,int);
extern void func_021B7C20(u8 *,int,int);
extern void func_021B7CB0(u8 *,u32,u32,u32,u8,u8,u8,u16);
extern void func_021B7D20(u8 *,u32,u32,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B7E48(u8 *,void *,int);
extern void func_021B8348(Display *,void *,int);
extern void func_021B658C(void *,Data *);
extern void func_021B7F78(u8 *,void *,int,u8 *,u8 *,int);
extern u32 func_021B78D4(u8 *);
extern int func_021B7CA0(void *),func_021B7CA4(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B728C(int,int);
extern void func_021B84B4(u8 *,int,int,int);
extern unsigned int func_021B8840(unsigned int x, int y);
extern void func_021B80BC(unsigned char *p, unsigned int v);
extern void func_021B80D8(u8 *p);
#define CTX (*(u8 **)(p+0x1a4))
int func_021B7560(struct Task *a,void *b,u8 *context)
{
    Data first,second;
    u8 *p;
    u32 handle;
    int tag,font;
    func_0203064C(1,60,0x20000);
    p=func_0203159C(a,0x1a8,60);
    func_02082BCC(p,0,0x1a8);
    *(u8 * *)&((struct Obj03234 *)p)->f1A4=context;
    func_021B784C(p,60);
    func_021B7C20(p+0xb0,0,60);
    if(*(void **)CTX) func_02012138(*(void **)CTX);
    func_021B7CB0(p+0xc0,5,1,18,30,5,5,60);
    func_0201F73C(((struct Obj03234 *)p)->fC0,0,((struct Obj03234 *)p)->f0,6);
    func_021B7D20(p+0xd4,7,6,3,20,5,8,1,1,60);
    func_021B7E48(p+0xd4,p+0xb0,1);
    func_02041F6C(7,3,4096);
    func_02041F6C(7,6,4096);
    func_02041FB0(7,9,128);
    func_02041FB0(7,12,40);
    func_021B8348((Display *)(p+0xe8),p,CTX[12]);
    if(*(void **)CTX) {
        func_021B658C(*(void **)CTX,&first);
        func_021B7F78(p+0xc0,p+0xb0,0,(u8 *)&first,*(u8 **)(CTX+8),60);
    }
    handle=func_021B78D4(p);
    tag=func_021B7CA0(p+0xb0);
    font=func_021B7CA4(p+0xb0);
    ((struct Obj03234 *)p)->f188=func_021B70DC(2,handle,0,13,13,2,tag,font,60);
    func_021B728C(*(int *)&((struct Obj03234 *)p)->f188,0);
    func_021B84B4(p+0x128,3,CTX[12],60);
    if(*(void **)CTX) {
        func_021B658C(*(void **)CTX,&second);
        if(second.low && ((Data *)*(void **)(CTX+8))->low) ((struct Obj03234 *)p)->f19C=1;
        else ((struct Obj03234 *)p)->f19C=0;
        ((struct Obj03234 *)p)->f1A0=func_021B8840(CTX[12],((struct Obj03234 *)p)->f19C);
    }
    func_021B80BC(p,(unsigned int)func_021B80D8);
    return 1;
}
