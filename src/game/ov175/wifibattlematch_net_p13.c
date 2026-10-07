/*
 * file:     wifibattlematch_net_p13.c
 * unit:     yes
 * function: func_021D8EC8, func_021D8FA8, func_021D9064, func_021D9090, func_021D9344, func_021D95B0, func_021D965C, func_021D97A4, func_021D97B8, func_021D97C4, func_021D97D0, func_021D97E4
 * address:  0x021D8EC8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021DBC04 0x021DBC04 thumb ov175
 *   func_021DBDAC 0x021DBDAC thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D9A1C 0x021D9A1C thumb ov175
 *   func_021D9A30 0x021D9A30 thumb ov175
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_021DD020 0x021DD020 thumb ov175
 *   func_021DC8B4 0x021DC8B4 thumb ov175
 *   func_021DC908 0x021DC908 thumb ov175
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_0203CD98 0x0203CD98 arm
 *   func_02089004 0x02089004 arm
 *   func_020891E0 0x020891E0 arm
 *   func_02088F58 0x02088F58 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0200FA84 0x0200FA84 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBFC 0x0200BBFC thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_021D98E4 0x021D98E4 thumb ov175
 *   func_021D99F4 0x021D99F4 thumb ov175
 *   func_021D9A08 0x021D9A08 thumb ov175
 *   func_021DCB58 0x021DCB58 thumb ov175
 *   func_021DCC28 0x021DCC28 thumb ov175
 *   func_021D9B18 0x021D9B18 thumb ov175
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02012944  0x02012944  thumb
 *   func_0200B358  0x0200B358  thumb
 *   func_0200B204  0x0200B204  thumb
 *   func_0200B074  0x0200B074  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0200DFD8  0x0200DFD8  thumb
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_021E5D68  0x021E5D68  thumb  ov177
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb  ov119
 *   func_021E5F24   0x021E5F24  thumb
 *   func_021E64C8  0x021E64C8  thumb  ov177
 *   func_021E65FC  0x021E65FC  thumb  ov177
 */
#include "../../matched/include/Obj02886.h"
#include "../../matched/include/Obj10683.h"
#include "../../matched/include/Obj24281.h"
#include "../../matched/include/Obj00013.h"
#include "../../matched/include/Obj08276.h"
#include "../../matched/include/Obj24283.h"
#include "../../matched/include/Obj00728.h"
#include "../../matched/include/Obj08277.h"
#include "../../matched/include/Obj00781.h"
#include "../../matched/include/Obj08278.h"
#include "../../matched/include/Obj24288.h"
#include "../../matched/include/Obj24292.h"
#include "../../matched/include/Obj24293.h"
#include "../../matched/include/Obj03868.h"
#include "../../matched/include/Obj24294.h"
#include "../../matched/include/Obj24302.h"
#include "../../matched/include/Obj24303.h"

struct Record;
struct Obj;
struct Reg2;
struct Big;
struct Rec1E;
struct RecBig;
struct Sub0200852CObj;
typedef unsigned long u32_021D8EC8;

typedef unsigned char  u8;

typedef unsigned long u32_021D8FA8;

typedef unsigned int u32_021D9064;

typedef unsigned long u32_021D9090;

typedef unsigned short u16;

typedef long long s64;

struct RTCDate { u32_021D9090 year,month,day,week; };

struct RTCTime { u32_021D9090 hour,minute,second; };

struct Request { u8 a,b,c,d; u32_021D9090 id; };

typedef signed int     s32;

typedef unsigned int u32_021D9344;

typedef struct { u8 a,b,c,d; u32_021D9344 id; } Request;

typedef unsigned long u32_021D95B0;

typedef unsigned long u32_021D965C;

struct Save {
    u32_021D965C f00;
    u32_021D965C f04;
    u32_021D965C *f08;
    u32_021D965C f0c;
    u32_021D965C f10;
};

struct Obj {
    u32_021D965C f00;
    u32_021D965C f04;
    u32_021D965C f08;
    u32_021D965C f0c;
    u32_021D965C f10;
    u32_021D965C f14;
    u32_021D965C f18;
    u32_021D965C f1c;
    u8 pad20[0xe4];
    struct Save *f104;
    u32_021D965C f108;
};

struct Profile {
    u8 name[0x94];
    u32_021D965C f94;
    u32_021D965C f98;
    u32_021D965C f9c;
    u16 fa0;
    u16 fa2;
    u32_021D965C fa4;
    u16 fa8;
    u16 faa;
};

typedef unsigned long u32_021D97A4;

typedef unsigned long u32_021D97B8;

typedef unsigned long u32_021D97C4;

typedef unsigned long u32_021D97D0;

typedef unsigned long u32_021D97E4;

extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32_021D8EC8,u32_021D8EC8);
extern int func_02012DAC(int a0);
extern int func_02012DD0(u8 *p);
extern void func_021DBC04(u8 *p, u32_021D8EC8 mode, struct Record *src);
extern int func_021DBDAC(char *p);
extern int func_021D9F04(char *,void *,void *);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AB8(u32_021D8EC8);
extern int func_021E8844(const int *p);
extern void func_021D9A1C(char *, void *);
extern u32_021D8FA8 func_021D9A30(char *);
extern void func_021E8AA8(int a);
extern void func_021D9EA0(u8 *p);
extern u32_021D9064 func_0200FBB0(void);
extern u32_021D9090 func_021DD020(char *);
extern void func_021DC8B4(char *,void *,unsigned);
extern int func_021DC908(char *);
extern int func_0203CD98(void);
extern int func_02167ED8(void *date, void *time);
extern void func_0200FA84(void);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern void func_020891E0(struct RTCDate *,struct RTCTime *,s64);
extern s32 func_02088F58(struct RTCDate *date);
extern s32 func_0200B078(struct Reg2 *p, u32_021D9090 id);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern unsigned int func_0200BBFC(struct Obj *,unsigned int);
extern void func_0200BBD8(struct Obj *p, int v);
extern void func_0200B110(struct Reg2 *,unsigned int,int);
extern void func_02082BCC(void *,int,unsigned);
extern int func_021D9A08(char *);
extern void func_021DCB58(char *p, void *q, int mode);
extern int func_021DCC28(char *p, u8 *out);
extern void func_021D9B18(char *save, char *response);
extern void MI_CpuFill8(void *dst, u8 val, u32_021D965C size);
extern void MI_CpuCopy8(const void *src, void *dst, u32_021D965C size);
extern u8 *func_02012944(void *p);
extern void *func_0200B358(void *sys);
extern struct Rec1E *func_0200B204(struct RecBig *p, u32_021D965C index);
extern u8 *func_0200B074(struct Reg2 *p);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32_021D965C func_0200DFD8(u32_021D965C a, u32_021D965C b, u32_021D965C c);
extern int func_021E5548(int *p);
extern char *func_021E5D68(char *info, u32_021D965C a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
extern void func_021E5EF8(void *p);
extern u32_021D97B8 func_021E64C8(u32_021D97B8 p);
extern u32_021D97C4 func_021E65FC(u32_021D97C4 p);
extern void func_021E5F24(u32_021D97E4 a, u32_021D97E4 b, u32_021D97E4 c, u32_021D97E4 d, u32_021D97E4 e, u32_021D97E4 f);
void func_021D8EC8(u32_021D8EC8 sys,int *state,char *p);
void func_021D8FA8(u32_021D8FA8 sys, int *state, char *ctx);
void func_021D905C(u32_021D8FA8 sys);
void func_021D9064(void *obj,int unused,u8 *p);
void func_021D9090(u32_021D9090 sys,int *state,char *p);
void func_021D9344(u32_021D9344 sys,int *state,char *p);
void func_021D95B0(u32_021D95B0 sys, int *state, char *ctx);
void func_021D965C(struct Obj *obj);
void func_021D97A4(char *obj);
u32_021D97B8 func_021D97B8(char *obj);
int func_021D97C4(char *obj);
void func_021D97D0(char *obj);
void func_021D97E4(char *obj, u32_021D97E4 arg);

void func_021D8EC8(u32_021D8EC8 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj02886 *)p)->f104;
    switch(*state) {
    case 0:func_021E8738((int *)(((struct Obj02886 *)p)->f2C),((struct Obj02886 *)p)->f14,40,2);
        func_021E8AB4(sys,1);*state=7;break;
    case 1:func_02012DAC((int)(**(void ** *)&((struct Obj10683 *)q)->f8));*state=2;break;
    case 2:if(func_02012DD0(**(void ** *)&((struct Obj10683 *)q)->f8)==2) *state=3;break;
    case 3:func_021E8738((int *)(((struct Obj02886 *)p)->f2C),((struct Obj02886 *)p)->f14,37,2);
        func_021E8AB4(sys,4);*state=7;break;
    case 4:if(**(u32_021D8EC8 * *)&((struct Obj10683 *)q)->f20==0) {func_021DBC04(((struct Obj02886 *)p)->f34,2,0);*state=5;}break;
    case 5:if(func_021DBDAC(((struct Obj02886 *)p)->f34)) {
        **(u32_021D8EC8 * *)&((struct Obj24281 *)(*(char * *)&((struct Obj02886 *)p)->f104))->f20=1800;*state=6;
        func_021D9F04(*(char * *)&((struct Obj02886 *)p)->f34,(void *)1,0);
    }break;
    case 6:func_021E8AA0((int *)sys,(int)func_021D905C);break;
    case 7:if(func_021E8844((const int *)(((struct Obj02886 *)p)->f2C))) func_021E8AB8(sys);break;
    }
}

/*
 * follower: 021D905C tail-call stub included; function_starts seed 021D905C.
 */
void func_021D8FA8(u32_021D8FA8 sys, int *state, char *ctx)
{
    int result;
    switch (*state) {
    case 0:
        result = func_021D9F04(((struct Obj00013 *)ctx)->f34, (void *)1, 0);
        switch (result) {
        case 1: case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        case 0:
            func_021D9A1C(ctx, func_021D9090);
            *state = 1;
            break;
        }
        break;
    case 1:
        result = func_021D9A30(ctx);
        if (result != 0xffff) *state = 2;
        if (result == 3) func_021E8AA0((int *)sys, (int)func_021D9064);
        result = func_021D9F04(((struct Obj00013 *)ctx)->f34, (void *)1, 0);
        switch (result) {
        case 1: case 2: func_021E8AA0((int *)sys, (int)func_021D9064); break;
        }
        break;
    case 2: func_021E8AA0((int *)sys, (int)func_021D8EC8); break;
    case 3:
        if (func_021E8844((const int *)(((struct Obj00013 *)ctx)->f2C))) func_021E8AB8(sys);
        break;
    }
}

void func_021D905C(u32_021D8FA8 sys)
{
    func_021E8AA8(sys);
}

void func_021D9064(void *obj,int unused,u8 *p) { ((struct Obj24283 *)(*(u8 * *)&((struct Obj08276 *)p)->f104))->f4=3; if(((struct Obj08276 *)p)->f34) { func_021D9EA0(((struct Obj08276 *)p)->f34); *(u32_021D9064 *)&((struct Obj08276 *)p)->f34=0; } func_0200FBB0(); func_021E8AA8((int)obj); }

/*
 * Lever: byte range test uses (u8)(value + 255), preserving adds #255.
 * Extent: final 021D9342..021D9344 is zero alignment padding.
 */
void func_021D9090(u32_021D9090 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00728 *)p)->f104;
    struct RTCDate startDate;
    struct RTCDate endDate;
    struct RTCDate nowDate;
    struct RTCTime nowTime;
    struct Request req;
    struct Reg2 *reg;
    struct Obj *box;
    int got;
    int startDay,endDay,nowDay,v;
    switch(*state) {
    case 0:*state=1;break;
    case 1:reg=*(struct Reg2 * *)&((struct Obj00728 *)p)->f108;
        if(!func_0203CD98())func_0200FA84();
        got=func_02167ED8((int *)&nowDate,(int *)&nowTime);
        if(got)func_020891E0(&nowDate,&nowTime,func_02089004(&nowDate,&nowTime));
        startDate.year=func_0200B078(reg,4);
        startDate.month=func_0200B078(reg,5);
        startDate.day=func_0200B078(reg,6);startDate.week=0;
        endDate.year=func_0200B078(reg,7);
        endDate.month=func_0200B078(reg,8);
        endDate.day=func_0200B078(reg,9);endDate.week=0;
        startDay=func_02088F58(&startDate);
        endDay=func_02088F58(&endDate);
        nowDay=func_02088F58(&nowDate);
        if(got && nowDay<startDay) {((struct Obj00728 *)p)->f40=2;*state=2;}
        else if(got && startDay<=nowDay && nowDay<=endDay) {((struct Obj00728 *)p)->f40=0;*state=13;}
        else {((struct Obj00728 *)p)->f40=1;*state=3;}
        break;
    case 2:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,96,1);
        *state=14;func_021E8AB4(sys,13);break;
    case 3:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,80,1);
        *state=14;func_021E8AB4(sys,4);break;
    case 4:if((u8)((*(u8 **)(q+48))[5]+255)<=1) *state=5;
        else *state=13;break;
    case 5:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,40,2);
        *state=14;func_021E8AB4(sys,6);break;
    case 6:box=func_0200BAC8(func_02012EBC(**(void ** *)&((struct Obj08277 *)q)->f8));
        ((struct Obj00728 *)p)->f26C=func_0200BBFC(box,1);
        func_0200BBD8(box,1);
        func_0200B110(*(struct Reg2 * *)&((struct Obj00728 *)p)->f108,10,3);
        func_02012DAC(**(int * *)&((struct Obj08277 *)q)->f8);*state=7;break;
    case 7:if(func_02012DD0(**(void ** *)&((struct Obj08277 *)q)->f8)==2) *state=8;break;
    case 8:func_0200BAC8(func_02012EBC(**(void ** *)&((struct Obj08277 *)q)->f8));
        if(((struct Obj00728 *)p)->f26C!=0) *state=9;else *state=10;break;
    case 9:func_021D97E4(p,1);
        func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,81,1);
        *state=14;func_021E8AB4(sys,10);break;
    case 10:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,70,2);
        *state=14;func_021E8AB4(sys,11);break;
    case 11:func_02082BCC(&req,0,8);req.b=3;
        req.id=func_021DD020(*(char * *)&((struct Obj00728 *)p)->f34);
        (*(u8 **)(*(char * *)&((struct Obj00728 *)p)->f104+48))[5]=3;
        func_021DC8B4(*(char * *)&((struct Obj00728 *)p)->f34,&req,87);*state=12;break;
    case 12:v=func_021DC908(*(char * *)&((struct Obj00728 *)p)->f34);
        if(v==1) *state=13;
        else if(v==3) {((struct Obj00728 *)p)->f40=3;*state=13;}
        break;
    case 13:func_021E8AA8(sys);break;
    case 14:if(func_021E8844((const int *)(((struct Obj00728 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}

void func_021D9344(u32_021D9344 sys,int *state,char *p) {
    char *ctx=*(char * *)&((struct Obj00781 *)p)->f104;
    int r;
    Request request;
    switch(*state) {
    case 0:
        r=((struct Obj24288 *)(*(char * *)&((struct Obj08278 *)ctx)->f30))->f5;
        if((u8)(r+255)<=1) { ((struct Obj00781 *)p)->f40=1; *state=2; }
        else { ((struct Obj00781 *)p)->f40=2; *state=1; }
        break;
    case 1:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,82,1);
        *state=16; func_021E8AB4(sys,15); break;
    case 2:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,83,1);
        *state=16; func_021E8AB4(sys,3); break;
    case 3: func_021D98E4((u32_021D9344 *)p,5); *state=4; break;
    case 4:
        r=func_021D9A08(p);
        if(r!=-1) { func_021D99F4(p); switch(r) { case 0:*state=5;break; case 1:*state=15;break; } }
        break;
    case 5:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,84,1);
        *state=16; func_021E8AB4(sys,6); break;
    case 6: func_021D98E4((u32_021D9344 *)p,5); *state=7; break;
    case 7:
        r=func_021D9A08(p);
        if(r!=-1) { func_021D99F4(p); switch(r) { case 0:*state=8;break; case 1:*state=15;break; } }
        break;
    case 8:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,40,2);
        *state=16; func_021E8AB4(sys,9); break;
    case 9:
        func_0200BBD8(func_0200BAC8(func_02012EBC(**(struct Big ** *)&((struct Obj08278 *)ctx)->f8)),1);
        func_0200B110((struct Reg2 *)(((struct Obj00781 *)p)->f108),10,4);
        func_02012DAC(**(int * *)&((struct Obj08278 *)ctx)->f8); *state=10; break;
    case 10:
        r=func_02012DD0(**(u8 ** *)&((struct Obj08278 *)ctx)->f8);
        if(r==2) { ((struct Obj00781 *)p)->f40=0; *state=11; }
        else if(r==3) *state=15;
        break;
    case 11:
        func_021D97E4(p,1);
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,81,1);
        *state=16; func_021E8AB4(sys,12); break;
    case 12:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,70,2);
        *state=16; func_021E8AB4(sys,13); break;
    case 13:
        func_02082BCC(&request,0,8); request.b=4;
        request.id=func_021DD020(*(char * *)&((struct Obj00781 *)p)->f34);
        ((struct Obj24293 *)(*(char * *)&((struct Obj24292 *)(*(char * *)&((struct Obj00781 *)p)->f104))->f30))->f5=4;
        func_021DC8B4(*(char * *)&((struct Obj00781 *)p)->f34,&request,87); *state=14; break;
    case 14:
        r=func_021DC908(*(char * *)&((struct Obj00781 *)p)->f34);
        if(r==1) *state=15;
        else if(r==3) { ((struct Obj00781 *)p)->f40=3; *state=15; }
        break;
    case 15: func_021E8AA8(sys); break;
    case 16: if(func_021E8844(*(int * *)&((struct Obj00781 *)p)->f2C)) func_021E8AB8(sys); break;
    }
}

void func_021D95B0(u32_021D95B0 sys, int *state, char *ctx)
{
    char *save;
    int result;
    save = *(char * *)&((struct Obj24294 *)(*(char * *)&((struct Obj03868 *)ctx)->f104))->f14;
    switch (*state) {
    case 0: *state = 1; break;
    case 1:
        func_02082BCC(ctx + 0x44, 0, 0x9c);
        func_021DCB58(((struct Obj03868 *)ctx)->f34, save + 0xd4, 1);
        *state = 2;
        break;
    case 2:
        result = func_021DCC28(((struct Obj03868 *)ctx)->f34, (u8 *)(ctx + 0x44));
        if (result == 1) *state = 3;
        else if (result == 2) { ((struct Obj03868 *)ctx)->f40 = 2; *state = 4; }
        else if (result == 3) { ((struct Obj03868 *)ctx)->f40 = 3; *state = 4; }
        break;
    case 3:
        if (((struct Obj03868 *)ctx)->f44 == 0) {
            func_021D9B18(save, ctx + 0x44);
            ((struct Obj03868 *)ctx)->f40 = 0;
            *state = 4;
        } else {
            ((struct Obj03868 *)ctx)->f40 = 1;
            *state = 4;
        }
        break;
    case 4: func_021E8AA8(sys); break;
    }
}


/*
 * Opens the +0x1c profile exchange when none is open: builds a 0xac-byte
 *     profile (0x92 bytes copied from the +0x108 block, three packed byte
 *     triples, the play-time words from the +0x104 save), then hands it to
 *     0x021E5D68 with the +0x04..+0x18 words.
 *
 * The three calls to 0x0200DFD8 resolve since seeds_2 labelled and matched
 *     it (src/matched/unit_0200DFD8.c).
 */
void func_021D965C(struct Obj *obj)
{
    struct Profile prof;
    u32_021D965C sys;
    u32_021D965C id;
    u32_021D965C kind;
    u32_021D965C a;
    u32_021D965C b;
    u32_021D965C data;
    u32_021D965C c;

    if (obj->f1c == 0) {
        data = obj->f108;
        sys = (u32_021D965C)func_02012944((void *)(*obj->f104->f08));
        id = func_021E5548((int *)obj->f00);
        kind = (u32_021D965C)func_0200B204(func_0200B358(func_02012EBC((struct Big *)(*obj->f104->f08))), 0);
        MI_CpuFill8(&prof, 0, sizeof(prof));
        MI_CpuCopy8(func_0200B074((struct Reg2 *)data), &prof, 0x92);
        a = func_0200B078((struct Reg2 *)data, 6);
        b = func_0200B078((struct Reg2 *)data, 5);
        c = func_0200B078((struct Reg2 *)data, 4);
        prof.f94 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        a = func_0200B078((struct Reg2 *)data, 9);
        b = func_0200B078((struct Reg2 *)data, 8);
        c = func_0200B078((struct Reg2 *)data, 7);
        prof.f98 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        prof.f9c = func_02008554((const struct Sub0200852CObj *)sys);
        prof.fa0 = func_0200DFD8(obj->f104->f10, 10, 0);
        a = func_0200DFD8(obj->f104->f10, 10, 1);
        prof.fa4 = a + func_0200DFD8(obj->f104->f10, 10, 2);
        prof.faa = func_0200B078((struct Reg2 *)data, 11);
        if (prof.fa4 == 0 && prof.fa0 == 0)
            prof.fa0 = 1500;
        obj->f1c = (u32_021D965C)func_021E5D68((char *)(&prof), 0, (void *)sys, (void *)id, (void *)obj->f04, obj->f08, (void *)obj->f10, (void *)obj->f14, (void *)obj->f18, (void *)kind, 0, 0x57);
    }
}


/*
 * Release path for the +0x1c block pointer, freed through 0x021E5EF8
 *     and cleared; a second call is a no-op.  The callee address is shared by
 *     two overlays, so the symbols: line carries the ov177 hint that the
 *     image's call to it there fixes.
 */
void func_021D97A4(char *obj)
{
    u32_021D97A4 p = ((struct Obj00013 *)obj)->f1C;

    if (p != 0) {
        func_021E5EF8((void *)p);
        ((struct Obj00013 *)obj)->f1C = 0;
    }
}


u32_021D97B8 func_021D97B8(char *obj)
{
    return func_021E64C8(((struct Obj24302 *)obj)->f1C);
}


/*
 * Thunk: hands the +0x1c block to 0x021E65FC (ov177) and returns its result.
 */
int func_021D97C4(char *obj)
{
    return func_021E65FC(((struct Obj24303 *)obj)->f1C);
}


/*
 * Start-op for the ov175 object's +0x1c stream: func_021D965C, then spin
 *     on func_021D97B8 until it reports ready.  Mirrors func_021D63C8.
 */
void func_021D97D0(char *obj)
{
    func_021D965C((struct Obj *)obj);
    while (func_021D97B8(obj) == 0)
        ;
}


/*
 * If the +0x1c block is live, forward it to 0x021E5F24 together with the
 *     function's own second argument, the +0x14 and +0x10 words and the +8
 *     word, plus the literal 0x57.  Six arguments, so the last two ride on the
 *     stack; the two-word frame exists only for them.
 */
void func_021D97E4(char *obj, u32_021D97E4 arg)
{
    if (((struct Obj00013 *)obj)->f1C != 0)
        func_021E5F24(((struct Obj00013 *)obj)->f1C, arg, ((struct Obj00013 *)obj)->f14,
                      ((struct Obj00013 *)obj)->f10, ((struct Obj00013 *)obj)->f8, 0x57);
}
