/*
 * file:     zukan_toroku_graphic.c
 * unit:     yes
 * function: ZUKAN_TOROKU_GRAPHIC_Init, ZUKAN_TOROKU_GRAPHIC_Exit, ZUKAN_TOROKU_GRAPHIC_Main, ZUKAN_TOROKU_GRAPHIC_CreateBg, ZUKAN_TOROKU_GRAPHIC_DeleteBg, ZUKAN_TOROKU_GRAPHIC_ClearTask, ZUKAN_TOROKU_GRAPHIC_CreateDisplay, ZUKAN_TOROKU_GRAPHIC_DeleteDisplay, ZUKAN_TOROKU_GRAPHIC_Draw, ZUKAN_TOROKU_GRAPHIC_Update, ZUKAN_TOROKU_GRAPHIC_UpdateSub, ZUKAN_TOROKU_GRAPHIC_GetDisplay, ZUKAN_TOROKU_GRAPHIC_VBlank, ZUKAN_TOROKU_GRAPHIC_InitBg, ZUKAN_TOROKU_GRAPHIC_ExitBg, ZUKAN_TOROKU_GRAPHIC_UpdateBg, ZUKAN_TOROKU_GRAPHIC_ResetDisplay, ZUKAN_TOROKU_GRAPHIC_InitActors, ZUKAN_TOROKU_GRAPHIC_DeleteActors, ZUKAN_TOROKU_GRAPHIC_DrawActors, ZUKAN_TOROKU_GRAPHIC_VBlankActors
 * address:  0x0220AF40
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   overlay67 0x00000043 data
 *   overlay206 0x000000CE data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021B9DE0 0x021B9DE0 thumb ov206
 *   ZUKAN_NICKNAME_Create 0x0220B55C thumb ov207
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   FADE_Start 0x0204E720 arm
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_NICKNAME_Delete 0x0220B6E4 thumb ov207
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BA374 0x021BA374 thumb ov206
 *   ZUKAN_NICKNAME_Main 0x0220B72C thumb ov207
 *   FADE_IsActive 0x0204E804 arm
 *   func_021BA544 0x021BA544 thumb ov206
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_021BA514 0x021BA514 thumb ov206
 *   func_021BA524 0x021BA524 thumb ov206
 *   func_021BA534 0x021BA534 thumb ov206
 *   func_0207D67C 0x0207D67C arm
 *   func_021BA4CC 0x021BA4CC thumb ov206
 *   func_021BA51C 0x021BA51C thumb ov206
 *   ZUKAN_NICKNAME_SetupScreen 0x0220B908 thumb ov207
 *   ZUKAN_NICKNAME_GetResult 0x0220B940 thumb ov207
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   func_02040588 0x02040588 arm
 *   func_02030734 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   d_0220BC20 0x0220BC20 data a1
 *   d_0220BAE8 0x0220BAE8 data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   d_0220BABC 0x0220BABC data a4
 *   d_0220BB18 0x0220BB18 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
#include "../../matched/include/Obj00162.h"
#include "../../matched/include/Obj14641.h"
#include "../../matched/include/Obj14642.h"

struct GfFont;
struct Obj0203159C;
struct Node;
struct PrintSys;
struct S020315D4;
struct DispVram;
struct Bank;
struct BgTemplate;
struct DispConfig;
struct Cfg;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct Main { u16 heap,pad; void *display,*font; u32 gfx; int enabled,zero; u32 unused[2]; void *mon,*other,*task; int flag,last; };

typedef enum OverlayId { OVERLAY_ZERO=0 } OverlayId;

struct Entry { unsigned id; char fields[32]; unsigned a,b; };

extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern void *func_021B9DE0(u16,void *,u32,u32,u32,u32,u8,u32,u32,u32,u32,u32,u32);
extern char *ZUKAN_NICKNAME_Create(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void *func_020056A0(u32,u32,u32);
extern void FADE_Start(u32,int,int,int);
extern void func_02030EAC(struct Node *n);
extern void ZUKAN_NICKNAME_Delete(unsigned *p);
extern void func_021BA2CC(char *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(int);
extern void func_021BA374(char *);
extern int ZUKAN_NICKNAME_Main(char *);
extern int FADE_IsActive(void);
extern void func_021BA544(char *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8);
extern void func_021BA514(char *);
extern int func_021BA524(char *);
extern int func_021BA534(char *);
extern void func_0207D67C(u32,int,int,int,int,int);
extern void func_021BA4CC(char *);
extern void func_021BA51C(char *);
extern void ZUKAN_NICKNAME_SetupScreen(char *);
extern int ZUKAN_NICKNAME_GetResult(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void BG_SYS_ClearSlot(u32 i);
extern void func_0204047C(int idx, unsigned short val);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32 index);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
int ZUKAN_TOROKU_GRAPHIC_Init(void *owner,int unused,u32 *args);
int ZUKAN_TOROKU_GRAPHIC_Exit(void *a,int b,int c,unsigned *p);
int ZUKAN_TOROKU_GRAPHIC_Main(void *unused,int unused2,u32 *args,u32 *p);
void ZUKAN_TOROKU_GRAPHIC_CreateBg(unsigned *p);
void ZUKAN_TOROKU_GRAPHIC_DeleteBg(u32*p);
void ZUKAN_TOROKU_GRAPHIC_ClearTask(int unused, char *p);
void *ZUKAN_TOROKU_GRAPHIC_CreateDisplay(int a,int heap);
void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(unsigned *p);
void ZUKAN_TOROKU_GRAPHIC_Draw(u8*p);
void ZUKAN_TOROKU_GRAPHIC_Update(void *a0);
void ZUKAN_TOROKU_GRAPHIC_UpdateSub(void *a0);
u32 ZUKAN_TOROKU_GRAPHIC_GetDisplay(u8*p);
void ZUKAN_TOROKU_GRAPHIC_VBlank(void*unused,u8*p);
void ZUKAN_TOROKU_GRAPHIC_InitBg(void *p,int heap);
void ZUKAN_TOROKU_GRAPHIC_ExitBg(void*p);
void ZUKAN_TOROKU_GRAPHIC_UpdateBg(void*p);
void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(void*p);
void ZUKAN_TOROKU_GRAPHIC_InitActors(unsigned char *p, int a, int b);
void ZUKAN_TOROKU_GRAPHIC_DeleteActors(struct Bank**p);
void ZUKAN_TOROKU_GRAPHIC_DrawActors(void*p);
void ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*p);
u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*p);
extern char overlay67[],overlay206[];
extern char overlay206[],overlay67[];
extern char d_0220BC20[];
extern unsigned d_0220BAE8[];
extern const unsigned d_0220BABC[];
extern const struct Entry d_0220BB18[];






int ZUKAN_TOROKU_GRAPHIC_Init(void *owner,int unused,u32 *args)
{
    struct Main *p;
    int flag;
    func_02034AC4((int)overlay67);
    func_02034AC4((int)overlay206);
    GFL_HEAP_CreateChildHeap((u32)((void *)1),0x6a,0x80000);
    p=PROCSYS_AllocProcWork(owner,0x34,0x6a);
    MI_CpuFill8(p,0,0x34);
    p->heap=0x6a;
    p->display=ZUKAN_TOROKU_GRAPHIC_CreateDisplay(1,p->heap);
    p->font=GF_FONT_Create(0x17,0,0,0,p->heap);
    p->gfx=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    if(args[0]==0) { p->enabled=0; p->zero=0; } else { p->enabled=1; p->zero=0; }
    flag=0;
    if(args[0]!=0) flag=1;
    p->mon=func_021B9DE0(p->heap,(void *)args[1],args[2],1,flag,0,0,ZUKAN_TOROKU_GRAPHIC_GetDisplay(p->display),(u32)p->font,p->gfx,0,0,0);
    p->other=ZUKAN_NICKNAME_Create(p->heap,args[1],args[3],args[4],args[5],ZUKAN_TOROKU_GRAPHIC_GetDisplay(p->display),(u32)p->font,p->gfx,args[6]);
    GFL_NET_RestartWithDefaultTimeout(0,p->heap);
    if(p->enabled==1) ZUKAN_TOROKU_GRAPHIC_CreateBg((u32 *)p);
    p->task=func_020056A0((u32)ZUKAN_TOROKU_GRAPHIC_ClearTask,(u32)p,1);
    FADE_Start(3,16,0,2);
    return 1;
}






/*
 * lever: extern overlay-id addresses preserve the pooled FS_OVERLAY_ID values.
 */
int ZUKAN_TOROKU_GRAPHIC_Exit(void *a,int b,int c,unsigned *p)
{
    func_02030EAC((void *)p[10]);
    ZUKAN_TOROKU_GRAPHIC_DeleteBg(p);
    ZUKAN_NICKNAME_Delete((void *)p[9]);
    func_021BA2CC((void *)p[8]);
    PRINTSYS_QUE_Clear((void *)p[3]);
    PRINTSYS_QUE_Delete((void *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    ZUKAN_TOROKU_GRAPHIC_DeleteDisplay((void *)p[1]);
    func_020315D4(a);
    func_020306F0(106);
    func_02034A5C((OverlayId)overlay206);
    func_02034A5C((OverlayId)overlay67);
    return 1;
}






/*
 * ABI: 02035C60 is void in its matched forwarder, but this caller keeps and tests live r0.
 */
int ZUKAN_TOROKU_GRAPHIC_Main(void *unused,int unused2,u32 *args,u32 *p)
{
    int done=0;
    int result,flag,input;
    func_021BA374((char *)p[8]);
    result=ZUKAN_NICKNAME_Main((char *)p[9]);
    switch(p[4]) {
    case 0:
        switch(p[5]) {
        case 0:
            if(FADE_IsActive()==0) { func_021BA544((char *)p[8]); p[5]=1; }
            break;
        case 1:
            flag=0;
            input=TOUCHPANEL_GetTrg();
            if(KEY_GetTrg()&3) { func_020355D8(0); flag=1; }
            if(input!=0) { func_020355D8(1); flag=1; }
            if(flag!=0) { func_021BA514((char *)p[8]); p[5]=2; }
            break;
        case 2:
            if(func_021BA524((char *)p[8])!=0 || func_021BA534((char *)p[8])!=0) { p[7]=0; p[6]=16; p[5]=3; }
            break;
        case 3:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]--; }
            func_0207D67C(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==0) { func_021BA4CC((char *)p[8]); ZUKAN_TOROKU_GRAPHIC_CreateBg(p); p[5]=4; }
            break;
        case 4:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]++; }
            func_0207D67C(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==16) p[5]=5;
            break;
        case 5:
            if(func_021BA534((char *)p[8])!=0) { p[4]=1; p[5]=1; }
            break;
        }
        break;
    case 1:
        switch(p[5]) {
        case 0:
            if(FADE_IsActive()==0) { func_021BA51C((char *)p[8]); p[5]=1; }
            break;
        case 1:
            ZUKAN_NICKNAME_SetupScreen((char *)p[9]); p[5]=2;
            break;
        case 2:
            if(result==1) { FADE_Start(3,0,16,2); p[5]=3; }
            break;
        case 3:
            if(FADE_IsActive()==0) {
                switch(ZUKAN_NICKNAME_GetResult((char *)p[9])) {
                case 0: args[7]=0; break;
                case 1: args[7]=1; break;
                }
                p[5]=4; done=1;
            }
            break;
        }
        break;
    }
    PRINTSYS_QUE_Main((struct PrintSys *)p[3]);
    ZUKAN_TOROKU_GRAPHIC_Draw((void *)p[1]);
    ZUKAN_TOROKU_GRAPHIC_Update((void *)p[1]);
    ZUKAN_TOROKU_GRAPHIC_UpdateSub((void *)p[1]);
    return done;
}






void ZUKAN_TOROKU_GRAPHIC_CreateBg(unsigned *p)
{
    void *r;
    p[11]=1;
    BG_SYS_ClearSlot(3);
    func_0204047C(1,3);
    func_0204047C(3,0);
    r=func_020490F4(159,((struct Obj00162 *)p)->f0);
    func_02049B68(r,7,0,0,32,((struct Obj00162 *)p)->f0);
    p[12]=func_02049740(r,17,1,2048,0,((struct Obj00162 *)p)->f0);
    func_020498F4(r,(int)39,(int)1,(u16)p[12],(int)1536,(int)0,(unsigned)(((struct Obj00162 *)p)->f0));
    ARC_TOOL_DeleteHandle(r);
    func_020409B4(1);
}






void ZUKAN_TOROKU_GRAPHIC_DeleteBg(u32*p){u32 v,hi;v=p[12];hi=v>>16;BG_SYS_DeleteHalf(1,(u16)v,(u16)hi);}







void ZUKAN_TOROKU_GRAPHIC_ClearTask(int unused, char *p)
{
    if (((struct Obj14641 *)p)->f2C != 0)
    {
        func_02040588(0, 0);
        func_02040588(2, 0);
        ((struct Obj14641 *)p)->f2C = 0;
    }
}






/*
 * volatile: hardware accesses 0x0220B33E-0x0220B352.
 */
void *ZUKAN_TOROKU_GRAPHIC_CreateDisplay(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_0220BC20,455);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_0220BAE8);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    ZUKAN_TOROKU_GRAPHIC_InitBg(p,heap);
    ZUKAN_TOROKU_GRAPHIC_InitActors((unsigned char *)(p+1),(int)d_0220BAE8,heap);
    p[3]=(unsigned)func_020056A0((u32)((void (*)(void *, void *))ZUKAN_TOROKU_GRAPHIC_VBlank), (u32)p, 0);
    return p;
}






/*
 * volatile: hardware accesses at 0x0220B3D6-0x0220B3EC.
 */
void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    ZUKAN_TOROKU_GRAPHIC_DeleteActors((struct Bank **)(p+1));
    ZUKAN_TOROKU_GRAPHIC_ExitBg(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}






void ZUKAN_TOROKU_GRAPHIC_Draw(u8*p){ZUKAN_TOROKU_GRAPHIC_DrawActors(p+4);ZUKAN_TOROKU_GRAPHIC_UpdateBg(p);}






void ZUKAN_TOROKU_GRAPHIC_Update(void *a0){}





void ZUKAN_TOROKU_GRAPHIC_UpdateSub(void *a0){}





u32 ZUKAN_TOROKU_GRAPHIC_GetDisplay(u8*p){return ZUKAN_TOROKU_GRAPHIC_GetWord((u32*)(p+4));}



void ZUKAN_TOROKU_GRAPHIC_VBlank(void*unused,u8*p){ZUKAN_TOROKU_GRAPHIC_ResetDisplay(p);ZUKAN_TOROKU_GRAPHIC_VBlankActors(p+4);}


void ZUKAN_TOROKU_GRAPHIC_InitBg(void *p,int heap)
{
    unsigned i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_0220BABC);
    for(i=0;i<4;i++) {
        const struct Entry *e=&d_0220BB18[i];
        unsigned id=e->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        func_020414AC(id);
        func_02040588(id,e->b);
    }
}


void ZUKAN_TOROKU_GRAPHIC_ExitBg(void*p){u32 i;for(i=0;i<4;i++)func_020403F4((u8)d_0220BB18[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}



void ZUKAN_TOROKU_GRAPHIC_UpdateBg(void*p){}



void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(void*p){func_020419E4();}




void ZUKAN_TOROKU_GRAPHIC_InitActors(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x0220BACC, a, b);
    ((struct Obj14642 *)p)->f0 = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14642 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void ZUKAN_TOROKU_GRAPHIC_DeleteActors(struct Bank**p){CLACT_DeleteUnit(*p);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}



void ZUKAN_TOROKU_GRAPHIC_DrawActors(void*p){CLACT_DrawSystem();}



void ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*p){CLACT_VBlankSystem();}



u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*p){return *p;}
