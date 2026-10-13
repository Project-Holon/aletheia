/*
 * file:     demo3d_cmdsys.c
 * unit:     yes
 * function: func_021BEE1C, func_021BEE40, func_021BEE8C, func_021BEEF8, func_021BEF84, func_021BEFC4, func_021BF0B4, func_021BF128, func_021BF168, func_021BF1CC, func_021BF248, func_021BF26C, func_021BF290, func_021BF2DC, func_021BF320, func_021BF404, func_021BF470, func_021BF4C4, func_021BF510, func_021BF550, func_021BF710, func_021BF758, func_021BF78C, func_021BF79C, func_021BF7AC, func_021BF7C0, func_021BF810, func_021BF858, func_021BF8E8, func_021BF924, func_021BF964, func_021BF9B8
 * address:  0x021BEE1C
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
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_020311B8 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   TCBL_DeleteTask 0x02031194 arm
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   sub_020311B8 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   sub_0207C768 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021BDF74 0x021BDF74 thumb ov203
 *   func_021BDF88 0x021BDF88 thumb ov203
 *   TCBL_DeleteTask 0x02031194 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_0201F79C 0x0201F79C thumb
 *   sub_02045C04 0x02045C04 arm
 *   func_0204047C 0x0204047C arm
 *   sub_02040588 0x02040588 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02040588 0x02040588 arm
 *   GAME_VERSION_Code 0x0209DF08 data a1
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   func_02049990 0x02049990 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02049658 0x02049658 arm
 *   memset 0x02082BCC arm
 *   func_020414AC 0x020414AC arm
 *   func_021BE9B8 0x021BE9B8 thumb
 *   func_021BE9E8 0x021BE9E8 thumb
 *   func_02030734 0x02030734 arm
 *   d_021C3D4C 0x021C3D4C data a4
 *   func_021BE9A4 0x021BE9A4 thumb ov203
 *   TCBL_Main 0x020310C4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BE990 0x021BE990 thumb ov203
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   d_021C3D00 0x021C3D00 data a4
 */
#include "../../matched/include/Obj03917.h"
#include "../../matched/include/Obj01291.h"
#include "../../matched/include/Obj25324.h"
#include "../../matched/include/Obj25327.h"
#include "../../matched/include/Obj14596.h"
#include "../../matched/include/Obj14597.h"
#include "../../matched/include/Obj14599.h"
#include "../../matched/include/Obj25328.h"
#include "../../matched/include/Obj10867.h"
#include "../../matched/include/Obj02250.h"
#include "../../matched/include/Obj01776.h"
#include "../../matched/include/Obj02250.h"

struct Owner;
struct TcblNode;
struct Tcbl;
struct S02030FB4;
struct Context_021BF290;
struct MsgBank;
struct Descriptor;
struct Cfg;
struct Rec;
struct CharBuf;
struct Rec3;
struct U16Vec;
struct GfFont;
struct S02031140;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Config {unsigned words[11];} Config;

typedef struct Task_021BEE1C {char *owner;unsigned reserved;unsigned char done,a,b,mode;int channel,start,end;} Task_021BEE1C;

struct Owner { char pad[0x20]; struct Tcbl *manager; };

struct Work { struct Owner *owner; int state,mask,kind,duration,start,end,current,step; int *counter; };

typedef struct Task_021BF168 {char *owner;unsigned reserved;unsigned char done;signed char a,b,c;int start,end,count;unsigned index,mask;} Task_021BF168;

struct Triple{unsigned short x,y,z;};

typedef signed char s8;

struct Config_021BF290 { u16 a0,a2; u32 a4,a8,ac,a10,a14; s8 a18; u8 pad[7]; u32 a20,a24; };

struct Context_021BF290 { struct Config_021BF290 *cfg; int state,count,limit; u32 file,index,base; void *desc; u32 printer; void *text; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;void *text;void *window;int pad20[2]; } Work_021BF290;

struct Config_021BF470 { u16 a0,heap; u32 a4,a8,stop,a10,a14,a18,a1c,a20,a24; void *archive; };

struct Context_021BF470 { struct Config_021BF470 *cfg; int state,count,wait; u32 first,a14,second; int fadein,fadeout,blend,step; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;int d;int e;int f;int pad24[2]; } Work_021BF470;

typedef signed short s16;

typedef signed int s32;

struct Q { char pad[6]; unsigned short flag : 1; };

typedef struct {unsigned short heap,alternate;int config;int ended;int done;int previous;int index;char flags[4];char *owner;struct Tcbl *task;int text;int assets;int extra;} Context;

typedef struct {int kind;unsigned time;int values[8];} Record;

extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern struct TcblNode *func_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),unsigned,unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void func_02082BCC(void *,int,int);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void),GFL_USE_PopBgm(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void TCBL_DeleteTask(struct TcblNode *);
extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);
extern struct TcblNode *sub_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),u32,u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern u32 sub_0207C768(u32,u32);
extern void func_021BDF74(char *p, unsigned i, unsigned short val);
extern void func_021BDF88(char *p, int a, int b);
extern void TCBL_DeleteTask(struct TcblNode *);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32,u32,u32,u32);
extern void *MSGDATA_AllocString(struct MsgBank *,u32);
extern void GF_FONT_SetTextColor(u32,u32,u32);
/* The caller stores the live r0 result, although the matched wrapper was typed void. */
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void sub_020409B4(u32);
extern void func_0201F79C(void *,u32,u32,u32);
extern u32 sub_02045C04(struct Rec *rec);
extern void func_0204047C(int,u16);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_0201F5DC(void *,unsigned,unsigned,unsigned);
extern void *func_02045770(struct Descriptor *);
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201DD68(void);
extern void func_0201F7A8(void *,unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F614(int a, u32 x);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *,u32,u32,u32,u32,u32,u32,u16);
extern void func_0207D63C(u32,int,int,int,int);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *memset(void *,int,unsigned);
extern void func_020414AC(unsigned char);
extern void *func_021BE9B8(void *p, unsigned a, unsigned b);
extern void func_021BE9E8(int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021BE9A4(u32 id);
extern void TCBL_Main(struct Tcbl *p);
extern u32 func_020307B0(void *p);
extern Record *func_021BE990(int);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
extern struct GfFont *GF_FONT_Create(int,int,int,int,unsigned);
extern void *func_020490F4(u32 id, u32 heap);
extern signed char func_02012FFC(void);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
void func_021BEE1C(char *p,int unused,int *s);
void func_021BEE40(char *p,int unused,int *s);
void func_021BEE8C(char *p,int channel,int start,int end,unsigned mode);
void func_021BEEF8(struct TcblNode *node,Task_021BEE1C *t);
void func_021BEF84(char *p,int unused,int *s);
void func_021BEFC4(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter);
void func_021BF0B4(struct TcblNode *node,int *s);
void func_021BF128(char *p,int unused,int *s);
void func_021BF168(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end);
void func_021BF1CC(void *task,char *work);
void func_021BF248(unsigned unused,char **q,unsigned *v);
void func_021BF26C(unsigned unused,char **q,unsigned *v);
void func_021BF290(int a, int b, int *s);
void func_021BF2DC(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);
void func_021BF320(struct TcblNode *task, struct Context_021BF290 *ctx);
void func_021BF404(char *p,Work_021BF290 *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);
void func_021BF470(char *p);
void func_021BF4C4(char *p,int unused,int *record);
void func_021BF510(char *p,int a,int b,int c,int d,int e,int f);
void func_021BF550(struct TcblNode *task,struct Context_021BF470 *ctx);
void func_021BF710(char *p,Work_021BF470 *out,int a,int b,int c,int d,int e,int f);
void func_021BF758(void *p);
void func_021BF78C(char *a, int unused, int *p);
void func_021BF79C(char *a);
int func_021BF7AC(char *p, int v);
Context *func_021BF7C0(char *owner,unsigned heap);
void func_021BF810(char *p);
void func_021BF858(Context *p,int time,int flag);
void func_021BF8E8(char *p);
void func_021BF924(char *p);
int func_021BF964(char *p,char *owner,int *index);
void func_021BF9B8(Context *ctx,char *owner,Record *r);
extern const unsigned char GAME_VERSION_Code;
extern const char d_021C3D4C[];





void func_021BEE1C(char *p,int unused,int *s) { int x;x=func_021BF7AC(p,s[1]);if(s[0]==0)GFL_USE_FadeInBgmFull((u16)x);else GFL_USE_FadeOutBgm((u16)x); }





void func_021BEE40(char *p,int unused,int *s)
{
    int channel,a,b;
    channel=s[0];a=func_021BF7AC(p,s[1]);b=func_021BF7AC(p,s[2]);
    if(s[3]==0){GFL_USE_CancelChangeAndPlayBgm(channel,0xffff);GFL_USE_FadeInBgmFull((unsigned short)b);}
    else {func_021BEE8C(p,channel,a,b,s[3]);}
}





void func_021BEE8C(char *p,int channel,int start,int end,unsigned mode)
{
    Task_021BEE1C *t;
    int flag=0;
    t=TCBL_GetWork((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BEEF8,24,0));
    func_02082BCC(t,0,24);
    t->owner=p;t->mode=mode;
    if(mode==3)flag=1;
    t->a=flag;
    if(mode==4)t->b=1;else t->b=0;
    t->channel=channel;t->start=start;t->end=end;
    if(start!=0)GFL_USE_FadeOutBgm((unsigned short)start);else t->done=1;
}





void func_021BEEF8(struct TcblNode *node,Task_021BEE1C *t)
{
    switch(t->done){
    case 0:
        if(GFL_USE_IsBgmFading()!=0)return;
        ++t->done;
    case 1:
        if(t->a){
            if((unsigned char)t->owner[25]==0){GFL_USE_SetBgmPlayerParam((void *)1);GFL_USE_PushBgm();t->owner[25]=1;}
        }else {GFL_USE_CancelChangeAndStopBgm();if(t->mode==1)break;}
        if(t->b){
            if((unsigned char)t->owner[25]!=0){GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);t->owner[25]=0;}
        }else {GFL_USE_CancelChangeAndPlayBgm(t->channel,0xffff);}
        if(t->end!=0)GFL_USE_FadeInBgmFull((unsigned short)t->end);
        break;
    }
    TCBL_DeleteTask(node);
}





/*
 * trailing: two-byte zero alignment padding at 021BEFC2.
 */
void func_021BEF84(char *p,int unused,int *s)
{
    if(s[1]==0){BRIGHTNESS_Set((short)s[2],0x3f,s[0]);}
    else {func_021BEFC4((struct Owner *)p,s[0],0x3f,s[2],s[3],func_021BF7AC(p,s[1]),0);}
}





void func_021BEFC4(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct S02030FB4 *)sub_020311B8(owner->manager,(void (*)(struct TcblNode *, void *))func_021BF0B4,0x28,0));
    func_02082BCC(work,0,0x28);
    work->owner=owner;
    work->mask=mask;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=duration;
    work->counter=counter;
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=sub_0207C768(final-work->current,(int)b);
    if(counter != 0) (*counter)++;
    BRIGHTNESS_Set((short)work->start,work->kind,work->mask);
}





void func_021BF0B4(struct TcblNode *node,int *s)
{
    if(*(int *)((char *)s[0]+12)!=0){
        BRIGHTNESS_Set((short)s[6],s[3],s[2]);
        if(s[9]!=0)--*(int *)s[9];
        TCBL_DeleteTask(node);return;
    }
    if(s[4]-->0){BRIGHTNESS_Set((short)(s[7]>>12),s[3],s[2]);s[7]+=s[8];}
    else {BRIGHTNESS_Set((short)s[6],s[3],s[2]);if(s[9]!=0)--*(int *)s[9];TCBL_DeleteTask(node);}
}





void func_021BF128(char *p,int unused,int *s)
{
    int a,b;
    a=func_021BF7AC(p,s[4]);b=func_021BF7AC(p,s[5]);
    func_021BF168(p,s[0],s[1],s[2],s[3],a,b);
}





void func_021BF168(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end)
{
    Task_021BF168 *t;
    t=TCBL_GetWork((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BF1CC,32,1));
    func_02082BCC(t,0,32);
    t->owner=p;t->a=a;t->b=b;t->c=c;t->index=index;t->mask=63;t->start=start;t->end=end;
    func_021BEFC4((struct Owner *)p,t->index,t->mask,a,b,start,&t->count);
}





void func_021BF1CC(void *task,char *work)
{
    if(((struct Obj25324 *)(*(char * *)&((struct Obj01291 *)work)->f0))->fC) {
        BRIGHTNESS_Set(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
        TCBL_DeleteTask(task);return;
    }
    switch(((struct Obj01291 *)work)->f8) {
    case 0:
        if(((struct Obj01291 *)work)->f14==0) {
            func_021BEFC4((struct Owner *)(*(char * *)&((struct Obj01291 *)work)->f0),*(int *)&((struct Obj01291 *)work)->f18,*(int *)&((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->fA,((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f10,(int *)(work+0x14));
            (((struct Obj01291 *)work)->f8)++;
        }
        break;
    case 1:
        if(((struct Obj01291 *)work)->f14) return;
        break;
    }
    BRIGHTNESS_Set(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
    TCBL_DeleteTask(task);
}





void func_021BF248(unsigned unused,char **q,unsigned *v){func_021BDF74(*q,(unsigned char)v[0],v[1]|(v[2]<<5)|(v[3]<<10));}





void func_021BF26C(unsigned unused,char **q,unsigned *v){struct Triple t;t.x=v[1];t.y=v[2];t.z=v[3];func_021BDF88(*q,(unsigned char)v[0],(int)&t);}








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
    func_021BF404(p,TCBL_GetWork((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BF320,0x28,1)),a,b,c,d,e,f,g);
}







void func_021BF320(struct TcblNode *task, struct Context_021BF290 *ctx)
{
    struct Config_021BF290 *cfg = ctx->cfg;
    if (cfg->ac != 0) {
        func_021BF470((char *)ctx);
        TCBL_DeleteTask(task);
        return;
    }
    switch (ctx->state) {
    case 0: {
        struct MsgBank *bank = MSGDATA_CreateFromArchive(0,2,(u16)ctx->file,cfg->a2);
        void *desc;
        ctx->text = MSGDATA_AllocString(bank,ctx->index);
        GF_FONT_SetTextColor(1,2,15);
        ctx->printer = PRINTSYS_PrintStream((u32)ctx->desc,0,0,(u32)ctx->text,cfg->a24,cfg->a18,cfg->a20,0,cfg->a0,15);
        desc = ctx->desc;
        BMP_WIN_TransferChars(desc);
        BMP_WIN_MakeScreen(desc);
        sub_020409B4(BMP_WIN_GetBgLayer(desc));
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
            TCBL_DeleteTask(task);
        }
        break;
    }
}







void func_021BF404(char *p,Work_021BF290 *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    func_02082BCC(out,0,0x28);
    out->a=a;out->c=c;out->ctx=p;out->b=b;
    out->text=func_0201F5DC((void *)1,0,1,((struct Obj14596 *)p)->f2);
    func_02049B40(23,5,0,32,32,((struct Obj14596 *)p)->f2);
    out->window=(void *)BMP_WIN_Create(1,d,e,f,g,1,0);
    BMP_Clear(func_02045770(out->window),15);
}







/*
 * padding: 0x021BF4C2..0x021BF4C4 is zero alignment padding.
 */
void func_021BF470(char *p)
{
    if(*(void **)(p+0x20)) func_0201CE48(*(void **)(p+0x20));
    STRBUF_Delete(*(void **)(p+0x24));func_0201DD68();
    func_0201F7A8(*(void **)(p+0x1C),1);func_020452E8(*(void **)(p+0x1C));
    func_0201F614(1,*(int *)(p+0x18));func_02082BCC(p,0,0x28);
    func_0204047C(1,1);func_0204047C(0,0);func_02040588(1,0);
}







void func_021BF4C4(char *p,int unused,int *record)
{
    int a,b,c;
    if(record[0]==0xFF || record[0]==GAME_VERSION_Code) {
        a=func_021BF7AC(p,record[4]);b=func_021BF7AC(p,record[5]);c=func_021BF7AC(p,record[6]);
        func_021BF510(p,record[1],record[2],record[3],a,b,c);
    }
}







void func_021BF510(char *p,int a,int b,int c,int d,int e,int f)
{
    func_021BF710(p,TCBL_GetWork((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BF550,0x2C,1)),a,b,c,d,e,f);
}







/*
 * volatile: 0x04000052
 */
void func_021BF550(struct TcblNode *task,struct Context_021BF470 *ctx)
{
    struct Config_021BF470 *cfg=ctx->cfg;
    float a;
    if(cfg->stop != 0) {
        func_021BF758(ctx);
        TCBL_DeleteTask(task);
        return;
    }
    switch(ctx->state) {
    case 0:
        ARC_UTIL_UploadPaletteFromHandleWhole(cfg->archive,ctx->first,0,0,0,cfg->heap);
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
        TCBL_DeleteTask(task);
        break;
    }
}







void func_021BF710(char *p,Work_021BF470 *out,int a,int b,int c,int d,int e,int f)
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







int func_021BF7AC(char *p, int v)
{
    struct Q *q = *(struct Q * *)&((struct Obj25328 *)(*(char * *)&((struct Obj03917 *)p)->f1C))->f74;
    int flag = q->flag;

    if (flag == 1)
        v *= 2;
    return v;
}






Context *func_021BF7C0(char *owner,unsigned heap)
{
    Context *p;
    p=func_02030734(heap,0x30,1,d_021C3D4C,78);
    p->owner=owner;p->heap=heap;p->alternate=(heap&0x7FFF)|0x8000;
    p->config=((struct Obj10867 *)owner)->f78;p->previous=-1;
    func_021BF8E8((char *)p);
    p->ended=func_021BF964((char *)p,owner,&p->index);
    return p;
}




void func_021BF810(char *p)
{
    Record *r;
    int owner,i;
    owner=((struct Obj02250 *)p)->f1C;r=(Record *)func_021BE9A4(((struct Obj02250 *)p)->f4);
    for(i=0;i<9999;i++,r++) {
        if(r->kind==18) break;
        func_021BF9B8((Context *)p,(char *)owner,r);
    }
    ((struct Obj02250 *)p)->fC=1;
    TCBL_Main(((struct Obj02250 *)p)->f20);func_021BF924(p);func_020307B0(p);
}


void func_021BF858(Context *p,int time,int flag)
{
    Record *r;
    char *owner;
    int i;
    owner=p->owner;
    p->flags[2]=flag?1:0;
    TCBL_Main(p->task);
    if(p->ended==0 && time!=-4096) {
        r=func_021BE990(p->config)+p->index;
        time>>=12;
        if(r->time==time && p->previous!=time) {
            i=0;
            do {
                func_021BF9B8(p,owner,r);
                r++;
                p->ended=r->kind==18?1:0;
                p->index++;
                if(p->ended==1) break;
                if(r->time!=time) break;
                i++;
            } while(i<9999);
        }
        p->previous=time;
    }
}

extern void (*d_021C3D00[])(Context *, char *, int *);


void func_021BF8E8(char *p){*(struct Tcbl * *)&((struct Obj01776 *)p)->f20=TCBL_Create(((struct Obj01776 *)p)->f0,((struct Obj01776 *)p)->f0,16,128);*(struct GfFont * *)&((struct Obj01776 *)p)->f24=GF_FONT_Create(23,0,0,0,((struct Obj01776 *)p)->f0);((struct Obj01776 *)p)->f28=func_020490F4(161,((struct Obj01776 *)p)->f0);p[0x18]=func_02012FFC();}


void func_021BF924(char *p)
{
    if(((struct Obj02250 *)p)->f2C) func_021BE9E8(((struct Obj02250 *)p)->f2C);
    TCBL_DeleteAllTasks(((struct Obj02250 *)p)->f20);
    if(((struct Obj02250 *)p)->f19) {
        GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(60);
    }
    ARC_TOOL_DeleteHandle(((struct Obj02250 *)p)->f28);GF_FONT_Delete(((struct Obj02250 *)p)->f24);TCBL_Destroy(((struct Obj02250 *)p)->f20);
}


int func_021BF964(char *p,char *owner,int *index)
{
    Record *r;
    int i;
    r=func_021BE990(((struct Obj10867 *)owner)->f78);
    for(i=0;i<9999;i++) {
        if(r[i].kind==18) return 1;
        if(r[i].time==-1) func_021BF9B8((Context *)p,owner,&r[i]);
        else if(r[i].time>=((struct Obj10867 *)owner)->f7C) {*index=i;return 0;}
    }
    return 0;
}


void func_021BF9B8(Context *ctx,char *owner,Record *r){d_021C3D00[r->kind](ctx,owner,r->values);}
