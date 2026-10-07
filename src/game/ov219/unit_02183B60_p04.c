/*
 * file:     unit_02183B60_p04.c
 * unit:     yes
 * function: func_02184BAC, func_02184C2C, func_02184C8C, func_02184CB0, func_02184D30, func_02184D70
 * address:  0x02184BAC
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FEC 0x02027FEC thumb
 *   d_02185E40 0x02185E40 data ov219 a4
 *   func_02028148 0x02028148 thumb
 *   sub_02041B6C 0x02041B6C arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0201CE48 0x0201CE48 thumb
 */
#include "../../matched/include/Obj01439.h"
#include "../../matched/include/Obj14776.h"
#include "../../matched/include/Obj02933.h"
#include "../../matched/include/Obj02934.h"

struct MsgBank;
struct R;
struct TaskMenuState;
struct U16Vec;
struct Descriptor;
struct PrintSys;
struct CharBuf;
struct Ctx;
struct Rec;
struct Rec3;
typedef unsigned short u16;

typedef unsigned char u8;

struct Entry {unsigned x,y,z;};

typedef unsigned int u32;

struct Record {struct Descriptor *descriptor;u8 active;};

extern void *func_02045EC0(struct MsgBank *,unsigned);
extern struct R *func_02027F60(u16,u16,unsigned,unsigned,u16);
extern unsigned func_02027FEC(unsigned,unsigned,unsigned,unsigned,u8,u16);
extern void func_02028148(u8*);
extern void sub_02041B6C(u32);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020403F4(unsigned);
extern u32 func_0201D83C(void *ptr);
extern void func_0201DD78(unsigned,unsigned,unsigned);
extern void *func_02045770(struct Descriptor *);
extern void func_0201C6FC(struct PrintSys *,unsigned,unsigned,unsigned,void *,unsigned);
extern void func_02043B5C(struct CharBuf *,u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 func_0201CE30(void *);
extern void func_020286C4(struct Ctx *,void *,void *);
extern u32 func_0203630C(void);
extern void func_0201CE5C(struct Rec *,int);
extern void func_0201CE38(void *);
extern void func_020061E4(u32);
extern void func_0201CE48(struct Rec3 *);
void func_02184BAC(char *p);
void func_02184C2C(char *p,int i);
void func_02184C8C(u8 *p,u32 i);
void func_02184CB0(char *p);
void func_02184D30(char *p,struct Record *out,struct Descriptor *d,void *text,u8 x,u8 y);
int func_02184D70(char *p,u32 message,int force);
extern const struct Entry d_02185E40[];

void func_02184BAC(char *p)
{
    ((struct Obj01439 *)p)->fC064=func_02045EC0(*(struct MsgBank * *)&((struct Obj01439 *)p)->fC070,13);
    ((struct Obj01439 *)p)->fC068=func_02045EC0(*(struct MsgBank * *)&((struct Obj01439 *)p)->fC070,16);
    *(struct R * *)&((struct Obj01439 *)p)->fC058=func_02027F60(2,9,((struct Obj01439 *)p)->fC06C,((struct Obj01439 *)p)->fC080,(u16)((struct Obj01439 *)p)->f0);
    ((struct Obj01439 *)p)->fC08C=((struct Obj01439 *)p)->fC064;
    ((struct Obj01439 *)p)->fC090=0x39e3;((struct Obj01439 *)p)->fC094=0;
    ((struct Obj01439 *)p)->fC098=((struct Obj01439 *)p)->fC068;
    ((struct Obj01439 *)p)->fC09C=0x39e3;((struct Obj01439 *)p)->fC0A0=1;
}

void func_02184C2C(char *p,int i)
{
    if(*(unsigned *)(p+0xc05c+i*4)==0){
        *(unsigned *)(p+0xc05c+i*4)=func_02027FEC(((struct Obj14776 *)p)->fC058,(unsigned)(p+0xc08c+i*12),(u8)d_02185E40[i].x,(u8)d_02185E40[i].y,(u8)d_02185E40[i].z,(u16)((struct Obj14776 *)p)->f0);
    }
}

void func_02184C8C(u8 *p,u32 i){u32 off=i*4;u8 *slots=p+0xc05c;if(*(u8**)(slots+off)){func_02028148(*(u8**)(slots+off));sub_02041B6C(2);*(u8**)(slots+off)=0;}}

void func_02184CB0(char *p)
{
    func_02184C8C((u8 *)p,0);func_02184C8C((u8 *)p,1);
    func_02027FD8(*(struct TaskMenuState * *)&((struct Obj02933 *)p)->fC058);
    func_02045808(*(struct U16Vec * *)&((struct Obj02933 *)p)->fC064);func_02045808(*(struct U16Vec * *)&((struct Obj02933 *)p)->fC068);
    ((struct Obj02933 *)p)->fC05C=0;((struct Obj02933 *)p)->fC060=0;
    func_020452E8(*(struct Descriptor * *)&((struct Obj02933 *)p)->fC01C);
    func_020403F4(2);func_020403F4(6);func_020403F4(3);func_020403F4(7);
    func_0201D83C(((struct Obj02933 *)p)->fC06C);
    func_0201DD78((unsigned char)p[0xc084],(unsigned char)p[0xc085],(unsigned char)p[0xc086]);
}

void func_02184D30(char *p,struct Record *out,struct Descriptor *d,void *text,u8 x,u8 y)
{
    struct PrintSys *print;
    out->descriptor=d;out->active=0;
    print=*(struct PrintSys * *)&((struct Obj02934 *)p)->fC080;
    func_0201C6FC(print,(unsigned)func_02045770(d),x,y,text,((struct Obj02934 *)p)->fC06C);
    out->active=1;
}

/*
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 *
 * prototype: 0201CCE4's legacy void return is live r0 stored to p+C074; retain u32 return. Heap truncation at call sites uses u16.
 */
int func_02184D70(char *p,u32 message,int force)
{
    int result;
    u32 mode;
    result=0;
    switch(*(u32 *)(p+0xC0B0)) {
    case 0:
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
        *(struct U16Vec **)(p+0xC0AC)=func_020457B0(1024,(u16)(*(u32 *)p));
        func_02045CAC(*(struct MsgBank **)(p+0xC070),message,*(struct U16Vec **)(p+0xC0AC));
        *(u32 *)(p+0xC074)=func_0201CCE4(*(u32 *)(p+0xC01C),0,0,*(u32 *)(p+0xC0AC),*(u32 *)(p+0xC06C),func_02012FFC(),*(u32 *)(p+0xC0A4),0,*(u32 *)p,15);
        *(u32 *)(p+0xC0B0)=1;
        break;
    case 1:
        mode=func_0201CE30(*(void **)(p+0xC074));
        func_020286C4(*(struct Ctx **)(p+0xC088),*(void **)(p+0xC074),*(void **)(p+0xC01C));
        switch(mode) {
        case 0:
            if(func_0203630C()&1)func_0201CE5C(*(struct Rec **)(p+0xC074),0);
            break;
        case 1:
            if((*(u32 *)(p+0xC354)&1)||(*(u32 *)(p+0xC354)&2)) {
                func_0201CE38(*(void **)(p+0xC074));
                func_020061E4(0x547);
            }
            break;
        case 2: *(u32 *)(p+0xC0B0)=2;break;
        }
        break;
    case 2:
        if(force!=0 || (*(u32 *)(p+0xC354)&1)) {
            func_02045808(*(struct U16Vec **)(p+0xC0AC));
            func_0201CE48(*(struct Rec3 **)(p+0xC074));
            *(u32 *)(p+0xC0B0)=0;
            result=1;
        }
        break;
    }
    return result;
}
