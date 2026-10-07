/*
 * file:     demo3d_cmdsys_p04.c
 * unit:     yes
 * function: func_021BF470, func_021BF4C4, func_021BF510, func_021BF550, func_021BF710, func_021BF758, func_021BF78C, func_021BF79C
 * address:  0x021BF470
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   d_0209DF08 0x0209DF08 data a1
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   sub_02031194 0x02031194 arm
 *   sub_02049B68 0x02049B68 arm
 *   func_02049990 0x02049990 arm
 *   sub_0207C768 0x0207C768 arm
 *   sub_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02049658 0x02049658 arm
 *   memset 0x02082BCC arm
 *   func_020414AC 0x020414AC arm
 *   func_021BE9B8 0x021BE9B8 thumb
 *   func_021BE9E8 0x021BE9E8 thumb
 */
#include "../../matched/include/Obj03917.h"
#include "../../matched/include/Obj14597.h"
#include "../../matched/include/Obj14599.h"

struct Descriptor;
struct Rec3;
struct U16Vec;
struct Context;
struct S02030FB4;
struct TcblNode;
typedef unsigned int   u32;

typedef unsigned short u16;

struct Config { u16 a0,heap; u32 a4,a8,stop,a10,a14,a18,a1c,a20,a24; void *archive; };

struct Context { struct Config *cfg; int state,count,wait; u32 first,a14,second; int fadein,fadeout,blend,step; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;int d;int e;int f;int pad24[2]; } Work;

extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201DD68(void);
extern void func_0201F7A8(void *,unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F614(int a, u32 x);
extern void func_02082BCC(void *,int,int);
extern void func_0204047C(int,unsigned short);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_021BF7AC(char *,int);
extern void * func_020311B8(void *,void (*)(void *,void *),unsigned,unsigned);
extern void *func_02031290(struct S02030FB4 *p);
extern void sub_02031194(struct TcblNode *);
extern void sub_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *,u32,u32,u32,u32,u32,u32,u16);
extern u32 sub_0207C768(u32,u32);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32,int,int,int,int);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *memset(void *,int,unsigned);
extern void func_020414AC(unsigned char);
extern void *func_021BE9B8(void *p, unsigned a, unsigned b);
extern void func_021BE9E8(int);
void func_021BF470(char *p);
void func_021BF4C4(char *p,int unused,int *record);
void func_021BF510(char *p,int a,int b,int c,int d,int e,int f);
void func_021BF550(struct TcblNode *task,struct Context *ctx);
void func_021BF710(char *p,Work *out,int a,int b,int c,int d,int e,int f);
void func_021BF758(void *p);
void func_021BF78C(char *a, int unused, int *p);
void func_021BF79C(char *a);
extern const unsigned char d_0209DF08;

/*
 * padding: 0x021BF4C2..0x021BF4C4 is zero alignment padding.
 */
void func_021BF470(char *p)
{
    if(*(void **)(p+0x20)) func_0201CE48(*(void **)(p+0x20));
    func_02045808(*(void **)(p+0x24));func_0201DD68();
    func_0201F7A8(*(void **)(p+0x1C),1);func_020452E8(*(void **)(p+0x1C));
    func_0201F614(1,*(int *)(p+0x18));func_02082BCC(p,0,0x28);
    func_0204047C(1,1);func_0204047C(0,0);func_02040588(1,0);
}

void func_021BF4C4(char *p,int unused,int *record)
{
    int a,b,c;
    if(record[0]==0xFF || record[0]==d_0209DF08) {
        a=func_021BF7AC(p,record[4]);b=func_021BF7AC(p,record[5]);c=func_021BF7AC(p,record[6]);
        func_021BF510(p,record[1],record[2],record[3],a,b,c);
    }
}

void func_021BF510(char *p,int a,int b,int c,int d,int e,int f)
{
    func_021BF710(p,func_02031290(func_020311B8(((struct Obj03917 *)p)->f20,(void (*)(void *, void *))func_021BF550,0x2C,1)),a,b,c,d,e,f);
}

/*
 * volatile: 0x04000052
 */
void func_021BF550(struct TcblNode *task,struct Context *ctx)
{
    struct Config *cfg=ctx->cfg;
    float a;
    if(cfg->stop != 0) {
        func_021BF758(ctx);
        sub_02031194(task);
        return;
    }
    switch(ctx->state) {
    case 0:
        sub_02049B68(cfg->archive,ctx->first,0,0,0,cfg->heap);
        func_02049990(cfg->archive,ctx->second,1,0,0,0,1,cfg->heap);
        ctx->state++;
        break;
    case 1:
        ctx->count=0;
        ctx->blend=0;
        if(ctx->fadein>0) a=0.5f+(float)(ctx->fadein<<12);
        else a=(float)(ctx->fadein<<12)-0.5f;
        ctx->step=sub_0207C768(0x10000,(int)a);
        func_0204047C(1,0);
        func_0204047C(0,1);
        func_0207D63C(0x04000050,2,1,0,16);
        sub_02040588(1,1);
        ctx->state++;
        break;
    case 2:
        if(ctx->count++ < ctx->fadein) {
            int value;
            ctx->blend += ctx->step;
            value=ctx->blend>>12;
            *(volatile u16 *)0x04000052=value|((16-value)<<8);
        } else {
            *(volatile u16 *)0x04000052=16;
            ctx->count=0;
            ctx->state++;
        }
        break;
    case 3:
        if(ctx->count++ >= ctx->wait) {
            ctx->count=0;
            ctx->blend=0;
            if(ctx->fadeout>0) a=0.5f+(float)(ctx->fadeout<<12);
            else a=(float)(ctx->fadeout<<12)-0.5f;
            ctx->step=sub_0207C768(0x10000,(int)a);
            ctx->state++;
        }
        break;
    case 4:
        if(ctx->count++ < ctx->fadeout) {
            int value;
            ctx->blend += ctx->step;
            value=ctx->blend>>12;
            *(volatile u16 *)0x04000052=(16-value)|(value<<8);
        } else {
            *(volatile u16 *)0x04000052=0x1000;
            ctx->count=0;
            ctx->state++;
        }
        break;
    default:
        func_021BF758(ctx);
        sub_02031194(task);
        break;
    }
}

void func_021BF710(char *p,Work *out,int a,int b,int c,int d,int e,int f)
{
    func_02082BCC(out,0,0x2C);
    out->ctx=p;out->c=d;out->a=a;out->d=c;out->b=b;out->e=e;out->f=f;
    func_02049658((void *)(((struct Obj03917 *)p)->f28),out->b,1,0,0,1,((struct Obj03917 *)p)->f2);
}

void func_021BF758(void *p){unsigned z=0;memset(p,0,0x2c);func_02040588(1,0);func_0204047C(0,0);func_0204047C(1,1);*(volatile unsigned short *)0x04000050=z;func_020414AC(1);}


void func_021BF78C(char *a, int unused, int *p)
{
    ((struct Obj14597 *)a)->f2C = (int)func_021BE9B8((void *)(((struct Obj14597 *)a)->f20), p[0], p[1]);
}


void func_021BF79C(char *a)
{
    func_021BE9E8(((struct Obj14599 *)a)->f2C);
    ((struct Obj14599 *)a)->f2C = 0;
}
