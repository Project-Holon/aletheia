/*
 * file:     unit_021BE9B8.c
 * unit:     yes
 * function: func_021BE9B8, func_021BE9E8, func_021BE9F8, func_021BEA48, func_021BEAB8, func_021BEAF8, func_021BEB48, func_021BEBC8, func_021BEC24, func_021BEC3C, func_021BEC60, func_021BEC84, func_021BECA8, func_021BED94, func_021BEDCC
 * address:  0x021BE9B8
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
 *   d_021C3B98 0x021C3B98 data a4
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   func_02080C54 0x02080C54 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_0208068C 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   func_02030EAC 0x02030EAC arm
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BF7AC 0x021BF7AC thumb
 *   FX_Div 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 */
#include "../../matched/include/Obj10864.h"
#include "../../matched/include/Obj02919.h"

struct Owner;
struct TcblNode;
struct CaptureConfig;
struct S02030FB4;
struct Node;
struct Tcbl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Config_021BE9B8 {unsigned words[11];} Config_021BE9B8;

typedef struct Config_021BE9E8 { unsigned words[11]; } Config_021BE9E8;

typedef enum {GX_CAPTURE_SIZE_128x128=0,GX_CAPTURE_SIZE_256x64=1,GX_CAPTURE_SIZE_256x128=2,GX_CAPTURE_SIZE_256x192=3} GXCaptureSize;

typedef enum {GX_CAPTURE_MODE_A=0,GX_CAPTURE_MODE_B=1,GX_CAPTURE_MODE_AB=2} GXCaptureMode;

typedef enum {GX_CAPTURE_SRCA_2D3D=0,GX_CAPTURE_SRCA_3D=1} GXCaptureSrcA;

typedef enum {GX_CAPTURE_SRCB_VRAM_0x00000=0,GX_CAPTURE_SRCB_MRAM=1,GX_CAPTURE_SRCB_VRAM_0x08000=2,GX_CAPTURE_SRCB_VRAM_0x10000=4,GX_CAPTURE_SRCB_VRAM_0x18000=6} GXCaptureSrcB;

typedef enum {GX_CAPTURE_DEST_VRAM_A_0x00000=0,GX_CAPTURE_DEST_VRAM_D_0x18000=15} GXCaptureDest;

typedef struct CaptureConfig {int bank,pad[2];GXCaptureSize size;GXCaptureMode mode;GXCaptureSrcA a;GXCaptureSrcB b;GXCaptureDest dest;} CaptureConfig;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Config {unsigned words[11];} Config;

struct Owner { u8 pad[0x20]; struct Tcbl *manager; };

struct Work { struct Owner *owner; u8 state,kind,target,pad; int duration,start,end,current,step; };

extern void *TCBL_AddTask(void *, void (*)(void *, void *), unsigned, unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern unsigned short func_02080C54(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0208068C(int);
extern void MIi_CpuClearFast(unsigned,void *,unsigned);
extern void TCBL_DeleteTask(struct TcblNode *);
extern void func_02030EAC(struct Node *n);
extern void GFL_USE_PlaySeInSlot(void *,int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int GFL_USE_GetSeSlot(unsigned);
extern void GFL_USE_SetSeSlotVolume(int,unsigned);
extern void GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);
extern void GFL_USE_StopSeSlot(int);
extern void MI_CpuFill8(void *,u32,u32);
extern int func_021BF7AC(char *p, int v);
extern u32 FX_Div(u32,u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_CancelChangeAndStopBgm(void);
void * func_021BE9B8(void *p,unsigned a,unsigned b);
void func_021BE9E8(int a);
void *func_021BE9F8(void *manager, const Config_021BE9E8 *source);
void func_021BEA48(int *s,unsigned a,unsigned b,unsigned c);
void func_021BEAB8(void *task, const int *ctx);
void func_021BEAF8(void *node,int *s);
void func_021BEB48(CaptureConfig *s);
void func_021BEBC8(void *unused,int ignored,int *s);
void func_021BEC24(u32 a, u32 b, int *c);
void func_021BEC3C(int a0, int a1, int *src);
void func_021BEC60(struct Owner *p,int unused,int *v);
void func_021BEC84(struct Owner *p,int unused,int *s);
void func_021BECA8(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag);
void func_021BED94(struct TcblNode *p,char *q);
void func_021BEDCC(int mode,int channel,int value);
void func_021BEE04(int a,int b,int *s);
void func_021BEE14(void);
extern const Config_021BE9B8 d_021C3B98;



void * func_021BE9B8(void *p,unsigned a,unsigned b) { Config_021BE9B8 c;c=d_021C3B98;c.words[8]=a;c.words[9]=b;return func_021BE9F8(p, (const Config_021BE9E8 *)&c); }





void func_021BE9E8(int a)
{
    func_021BEA48((int *)a, 1, 0, 1);
}




void *func_021BE9F8(void *manager, const Config_021BE9E8 *source)
{
    void *task;
    char *ctx;
    task = TCBL_AddTask(manager, (void (*)(void *, void *))func_021BEAB8, 56, 5);
    ctx = TCBL_GetWork(task);
    *(Config_021BE9E8 *)(ctx + 4) = *source;
    ((struct Obj10864 *)ctx)->f34 = task;
    ((struct Obj10864 *)ctx)->f30 = 0;
    ((struct Obj10864 *)ctx)->f0 = func_02080C54();
    func_021BEB48((struct CaptureConfig *)(ctx + 4));
    func_020056A0((unsigned)func_021BEAF8, (unsigned)ctx, 0);
    return ctx;
}



void func_021BEA48(int *s,unsigned a,unsigned b,unsigned c)
{
    func_0207D4B0(a,b,c);func_0208068C(s[0]);
    switch(s[1]){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    default:func_0208068C(0);break;
    }
    TCBL_DeleteTask((struct TcblNode *)s[13]);
}



static inline void GX_SetCapture(GXCaptureSize sz, GXCaptureMode mode, GXCaptureSrcA a, GXCaptureSrcB b, GXCaptureDest dest, int eva, int evb)
{
    *(volatile unsigned *)0x04000064 = 0x80000000 | (mode << 29) | (b << 25) | (a << 24) | (sz << 20) | (dest << 16) | (evb << 8) | eva;
}



void func_021BEAB8(void *task, const int *ctx)
{
    if (ctx[12]) {
        GX_SetCapture(ctx[4], ctx[5], ctx[6], ctx[7], ctx[8], ctx[9], ctx[10]);
    }
}



void func_021BEAF8(void *node,int *s)
{
    int bank;
    switch(s[1]){case 2:bank=1;break;case 6:bank=2;break;case 10:bank=4;break;case 14:bank=8;break;default:bank=0;break;}
    func_0208068C(bank);func_0207D4B0(s[1],s[2],s[3]);s[12]=1;func_02030EAC(node);
}





/*
 * volatile: SDK GX_SetCapture write to DISPCAPCNT 04000064 at 021BEBB4.
 */
void func_021BEB48(CaptureConfig *s)
{
    switch(s->bank){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    }
    GX_SetCapture(s->size,s->mode,s->a,s->b,s->dest,16,0);
}



void func_021BEBC8(void *unused,int ignored,int *s)
{
    int channel;
    if(s[4]!=-1){GFL_USE_PlaySeInSlot((void *)s[0],s[4]);channel=s[4];}
    else {GFL_USE_PlaySeDefaultVolume(s[0]);channel=GFL_USE_GetSeSlot(s[0]);}
    if(s[1]!=-1)GFL_USE_SetSeSlotVolume(channel,s[1]);
    if(s[2]!=-1)GFL_USE_SetSeSlotParams(channel,-1,-1,s[2]);
    if(s[3]!=-1)GFL_USE_SetSeSlotParams(channel,-1,s[3],-1);
}




void func_021BEC24(u32 a, u32 b, int *c)
{
    int ch = c[1];
    if (ch == -1) {
        ch = GFL_USE_GetSeSlot(c[0]);
    }
    GFL_USE_StopSeSlot(ch);
}




void func_021BEC3C(int a0, int a1, int *src)
{
    func_021BECA8((struct Owner *)a0, 0, (unsigned short)src[0], src[1], src[2], src[3], src[4]);
}



void func_021BEC60(struct Owner *p,int unused,int *v) {func_021BECA8(p,1,(u16)v[0],v[1],v[2],v[3],v[4]);}



void func_021BEC84(struct Owner *p,int unused,int *s) { func_021BECA8(p,2,s[0],s[1],s[2],s[3],s[4]); }



/*
 * The u16 target parameter fixes the otherwise swapped home stores at +6/+8.
 */
void func_021BECA8(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(owner->manager,(void (*)(void *, void *))func_021BED94,0x1c,0));
    MI_CpuFill8(work,0,0x1c);
    work->owner=owner;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=func_021BF7AC((char *)owner,duration);
    if(flag == -1) work->target=flag;
    else work->target=GFL_USE_GetSeSlot(target);
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=FX_Div(final-work->current,(int)b);
}



void func_021BED94(struct TcblNode *p,char *q) { int old;old=((struct Obj02919 *)q)->f8;((struct Obj02919 *)q)->f8=old-1;if(old>0){func_021BEDCC(((struct Obj02919 *)q)->f5,((struct Obj02919 *)q)->f6,((struct Obj02919 *)q)->f14>>12);((struct Obj02919 *)q)->f14+=((struct Obj02919 *)q)->f18;}else {func_021BEDCC(((struct Obj02919 *)q)->f5,((struct Obj02919 *)q)->f6,((struct Obj02919 *)q)->f10);TCBL_DeleteTask(p);} }



void func_021BEDCC(int mode,int channel,int value)
{
    switch(mode){case 0:GFL_USE_SetSeSlotVolume(channel,value);break;case 1:GFL_USE_SetSeSlotParams(channel,-1,-1,value);break;case 2:GFL_USE_SetSeSlotParams(channel,-1,value,-1);break;}
}



void func_021BEE04(int a,int b,int *s){GFL_USE_CancelChangeAndPlayBgm(s[0],0xffff);}



void func_021BEE14(void){GFL_USE_CancelChangeAndStopBgm();}
