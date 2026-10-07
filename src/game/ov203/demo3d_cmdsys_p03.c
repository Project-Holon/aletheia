/*
 * file:     demo3d_cmdsys_p03.c
 * unit:     yes
 * function: func_021BF290, func_021BF2DC, func_021BF320, func_021BF404
 * address:  0x021BF290
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
 *   func_021BF7AC 0x021BF7AC thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_021BF470 0x021BF470 thumb
 *   sub_02031194 0x02031194 arm
 *   sub_02045B38 0x02045B38 arm
 *   sub_02045EC0 0x02045EC0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   sub_02045334 0x02045334 arm
 *   sub_02045374 0x02045374 arm
 *   sub_02045730 0x02045730 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_0201F79C 0x0201F79C thumb
 *   sub_02045C04 0x02045C04 arm
 *   func_0204047C 0x0204047C arm
 *   sub_02040588 0x02040588 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 */
#include "../../matched/include/Obj25327.h"
#include "../../matched/include/Obj03917.h"
#include "../../matched/include/Obj14596.h"

struct Context;
struct S02030FB4;
struct TcblNode;
struct MsgBank;
struct Descriptor;
struct Cfg;
struct Rec;
struct CharBuf;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

struct Config { u16 a0,a2; u32 a4,a8,ac,a10,a14; s8 a18; u8 pad[7]; u32 a20,a24; };

struct Context { struct Config *cfg; int state,count,limit; u32 file,index,base; void *desc; u32 printer; void *text; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;void *text;void *window;int pad20[2]; } Work;

extern int func_021BF7AC(char *p, int v);
extern void * func_020311B8(void *,void (*)(void *,void *),unsigned,unsigned);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021BF470(char *p);
extern void sub_02031194(struct TcblNode *);
extern struct MsgBank *sub_02045B38(u32,u32,u32,u32);
extern void *sub_02045EC0(struct MsgBank *,u32);
extern void func_0201DD78(u32,u32,u32);
/* The caller stores the live r0 result, although the matched wrapper was typed void. */
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void sub_02045334(struct Descriptor *);
extern void sub_02045374(struct Cfg *);
extern u8 sub_02045730(struct Descriptor *);
extern void sub_020409B4(u32);
extern void func_0201F79C(void *,u32,u32,u32);
extern u32 sub_02045C04(struct Rec *rec);
extern void func_0204047C(int,u16);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_02082BCC(void *,int,int);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_0201F5DC(void *,unsigned,unsigned,unsigned);
extern void *func_02045770(struct Descriptor *);
extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
void func_021BF290(int a, int b, int *s);
void func_021BF2DC(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);
void func_021BF320(struct TcblNode *task, struct Context *ctx);
void func_021BF404(char *p,Work *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);


void func_021BF290(int a, int b, int *s)
{
    unsigned char x = ((struct Obj25327 *)b)->f80;
    int r6 = s[2] * x;
    int r4 = s[1];
    int t = func_021BF7AC((char *)a, s[3]);

    func_021BF2DC((char *)a, s[0], r4 + r6, t, (unsigned char)s[4],
                  (unsigned char)s[5], (unsigned char)s[6], (unsigned char)s[7]);
}

void func_021BF2DC(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    func_021BF404(p,func_02031290(func_020311B8(((struct Obj03917 *)p)->f20,(void (*)(void *, void *))func_021BF320,0x28,1)),a,b,c,d,e,f,g);
}

void func_021BF320(struct TcblNode *task, struct Context *ctx)
{
    struct Config *cfg = ctx->cfg;
    if (cfg->ac != 0) {
        func_021BF470((char *)ctx);
        sub_02031194(task);
        return;
    }
    switch (ctx->state) {
    case 0: {
        struct MsgBank *bank = sub_02045B38(0,2,(u16)ctx->file,cfg->a2);
        void *desc;
        ctx->text = sub_02045EC0(bank,ctx->index);
        func_0201DD78(1,2,15);
        ctx->printer = func_0201CCE4((u32)ctx->desc,0,0,(u32)ctx->text,cfg->a24,cfg->a18,cfg->a20,0,cfg->a0,15);
        desc = ctx->desc;
        sub_02045334(desc);
        sub_02045374(desc);
        sub_020409B4(sub_02045730(desc));
        func_0201F79C(ctx->desc,1,ctx->base,0);
        sub_02045C04((struct Rec *)bank);
        func_0204047C(1,0);
        func_0204047C(0,1);
        sub_02040588(1,1);
        ctx->state++;
        break;
    }
    case 1:
        if (ctx->count++ >= ctx->limit) {
            func_021BF470((char *)ctx);
            sub_02031194(task);
        }
        break;
    }
}

void func_021BF404(char *p,Work *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    func_02082BCC(out,0,0x28);
    out->a=a;out->c=c;out->ctx=p;out->b=b;
    out->text=func_0201F5DC((void *)1,0,1,((struct Obj14596 *)p)->f2);
    func_02049B40(23,5,0,32,32,((struct Obj14596 *)p)->f2);
    out->window=(void *)func_020450F0(1,d,e,f,g,1,0);
    func_02043B5C(func_02045770(out->window),15);
}
