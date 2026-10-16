/*
 * file:     musical_shot_sys.c
 * unit:     yes
 * function: MUSICAL_SHOT_SYS_Create, MUSICAL_SHOT_SYS_Exit, MUSICAL_SHOT_SYS_Update, MUSICAL_SHOT_SYS_VBlank, MUSICAL_SHOT_SYS_InitGraphics, MUSICAL_SHOT_SYS_ExitGraphics
 * address:  0x021F36C0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_shot_sys.c, musical_mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   GF_STANDARD_SetField00_F4E4 0x0203F4E4 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   KEY_GetCont 0x0203630C arm
 *   func_020056A0 0x020056A0 thumb
 *   MUSICAL_MCSS_Create 0x021F4284 thumb ov112
 *   WIPE_SYS_Start 0x0202208C thumb
 *   d_021F836C 0x021F836C data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   MUSICAL_MCSS_Delete 0x021F4300 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   ov_abs_84 0x00000084 data
 *   MUSICAL_MCSS_Main 0x021F4350 thumb ov112
 *   MUSICAL_MCSS_NoOp2 0x021F44E8 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021F816C 0x021F816C data a4
 *   d_021F815C 0x021F815C data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ov132_id 0x84 data
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   MUSICAL_SHOT_SYS_CreateScene 0x021F3AF0 thumb ov112
 *   MUSICAL_SHOT_SYS_DeleteScene 0x021F3BF0 thumb ov112
 *   MUSICAL_SHOT_SYS_DrawScene 0x021F3C50 thumb ov112
 */
#include "musical_shot_sys_shared_types.h"
#include "musical_shot_types.h"

struct Proc;

struct RtcDate;

struct Proc;

struct DispConfig;

struct DispVram;

typedef struct {u32 x,y,z,week;} Options;

typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;

typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} State;

typedef enum {ConfigSize=432} AllocSize;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern int func_02034AC4(int);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);

extern u16 STRBUF_GetEosChar(void);

extern u32 KEY_GetCont(void);

extern void *func_020056A0(u32,u32,u32);

extern void *MUSICAL_MCSS_Create(u8 *,u32,u32,u32,u16);

extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern unsigned WIPE_SYS_EndCheck(void);

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

extern void func_0207D63C(void *,int,int,int,int);

extern void MUSICAL_MCSS_Delete(u8 *);

extern void func_02030EAC(struct Node *n);

extern void func_02034A5C(int);

extern u32 func_020307B0(void *p);

extern void func_020315D4(struct Proc *p);

extern void GFL_HEAP_DeleteChecked(unsigned int);

extern void MUSICAL_MCSS_Main(u8 *p);

extern int MUSICAL_MCSS_NoOp2(u32 *p);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);

extern u32 WIPE_ResetWndMask(void *win);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_Create(u16);

extern void BMP_WIN_Init(u16);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void CLACT_ExitSystem(void);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

int MUSICAL_SHOT_SYS_Create(void *owner,int unused,const Save *save);

int MUSICAL_SHOT_SYS_Exit(void *owner,void *arg,int flag,u8 *p);

int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p);

void MUSICAL_SHOT_SYS_VBlank(void);

void MUSICAL_SHOT_SYS_InitGraphics(u8 *p);

void MUSICAL_SHOT_SYS_ExitGraphics(void *a0);

u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap);

void MUSICAL_SHOT_SYS_DeleteScene(u8 *p);

void MUSICAL_SHOT_SYS_DrawScene(u8 *p);

extern char ov132_id[];

extern const char d_021F836C[];

extern u8 ov_abs_84[];

extern char d_021F816C[],d_021F815C[],gClActorInitParam[];

int MUSICAL_SHOT_SYS_Create(void *owner,int unused,const Save *save)
{
 State *p;u8 *cfg;u8 i,j;Options options;u32 length;
 GFL_HEAP_CreateChildHeap(1,74,1<<19);
 p=PROCSYS_AllocProcWork(owner,20,74);p->heap=74;
 if(save==0){
  func_02034AC4((u32)ov132_id);
  p->save=func_02030734(74,20,0,d_021F836C,110);
  length=ConfigSize;
  p->save->config=func_02030734(74,length,1,d_021F836C,111);
  p->save->b=0;
  cfg=p->save->config;
  GF_STANDARD_SetField00_F4E4((struct RtcDate *)(&options));
  ((MusicalShowRecord *)cfg)->programId=3;((MusicalShowRecord *)cfg)->winnerMask=(u8)2;
  ((MusicalShowRecord *)cfg)->year=options.x;((MusicalShowRecord *)cfg)->month=options.y;((MusicalShowRecord *)cfg)->day=options.z;
  *(u16 *)((u32)cfg+(length-0x4C))=0x30DD;
  *(u16 *)((u32)cfg+(length-0x4A))=0x30B1;
  *(u16 *)((u32)cfg+(length-0x48))=0x30C3;
  *(u16 *)((u32)cfg+(length-0x46))=0x30BF;
  *(u16 *)((u32)cfg+(length-0x44))=0x30FC;
  *(u16 *)((u32)cfg+(length-0x42))=0x30EA;
  *(u16 *)((u32)cfg+(length-0x40))=0x30E2;
  *(u16 *)((u32)cfg+(length-0x3E))=0x30F3;
  *(u16 *)((u32)cfg+(length-0x3C))=0x30B9;
  *(u16 *)((u32)cfg+(length-0x3A))=0x30BF;
  *(u16 *)((u32)cfg+(length-0x38))=0x30FC;
  *(u16 *)((u32)cfg+(length-0x36))=0x30EA;
  *(u16 *)((u32)cfg+(length-0x34))=STRBUF_GetEosChar();
  ((MusicalShowRecord *)cfg)->performers[0].monsNo=643;((MusicalShowRecord *)cfg)->performers[1].monsNo=643;((MusicalShowRecord *)cfg)->performers[2].monsNo=643;((MusicalShowRecord *)cfg)->performers[3].monsNo=643;
  for(i=0;i<4;i++){
   u8 *q;
   q=cfg+88U*i;
   ((MusicalShowPerformerView *)q)->performer.name[0]=0x30C8;((MusicalShowPerformerView *)q)->performer.name[1]=0x30EC;((MusicalShowPerformerView *)q)->performer.name[2]=0x30FC;((MusicalShowPerformerView *)q)->performer.name[3]=0x30CA;((MusicalShowPerformerView *)q)->performer.name[4]=0xFF11+i;((MusicalShowPerformerView *)q)->performer.name[5]=0;
   for(j=0;j<8;j++){u8 *slot;slot=q+8*j;((MusicalShowPerformerView *)slot)->performer.props[0].propId=255;((MusicalShowPerformerView *)slot)->performer.props[0].offset=0;((MusicalShowPerformerView *)slot)->performer.props[0].bodySlot=10;}
   q=cfg+88*i;
   ((MusicalShowPerformerView *)q)->performer.props[0].propId=11;((MusicalShowPerformerView *)q)->performer.props[0].offset=0;((MusicalShowPerformerView *)q)->performer.props[0].bodySlot=7;
   ((MusicalShowPerformerView *)q)->performer.props[1].propId=11;((MusicalShowPerformerView *)q)->performer.props[1].offset=0;((MusicalShowPerformerView *)q)->performer.props[1].bodySlot=8;
   ((MusicalShowPerformerView *)q)->performer.props[2].propId=11;((MusicalShowPerformerView *)q)->performer.props[2].offset=0;((MusicalShowPerformerView *)q)->performer.props[2].bodySlot=6;
   ((MusicalShowPerformerView *)q)->performer.props[3].propId=11;((MusicalShowPerformerView *)q)->performer.props[3].offset=0;((MusicalShowPerformerView *)q)->performer.props[3].bodySlot=4;
   ((MusicalShowPerformerView *)q)->performer.props[4].propId=11;((MusicalShowPerformerView *)q)->performer.props[4].offset=0;((MusicalShowPerformerView *)q)->performer.props[4].bodySlot=2;
   ((MusicalShowPerformerView *)q)->performer.props[5].propId=11;((MusicalShowPerformerView *)q)->performer.props[5].offset=0;((MusicalShowPerformerView *)q)->performer.props[5].bodySlot=1;
   ((MusicalShowPerformerView *)q)->performer.props[6].propId=11;((MusicalShowPerformerView *)q)->performer.props[6].offset=0;((MusicalShowPerformerView *)q)->performer.props[6].bodySlot=0;
  }
  if(KEY_GetCont()&256)p->save->a=1;else p->save->a=0;
  p->save->c=0;
 }else p->save=(Save *)save;
 if(p->save->b==1)func_02034AC4((u32)ov132_id);
 p->task=func_020056A0((u32)MUSICAL_SHOT_SYS_VBlank,(u32)p,64);
 MUSICAL_SHOT_SYS_InitGraphics((u8 *)p);
 p->scene=MUSICAL_SHOT_SYS_CreateScene(p->save->config,p->heap);
 p->actors=MUSICAL_MCSS_Create(p->save->config,p->save->c,p->save->a,p->save->d,p->heap);
 WIPE_SYS_Start(0,1,1,0,6,1,p->heap);return 1;
}

int MUSICAL_SHOT_SYS_Exit(void *owner,void *arg,int flag,u8 *p) {
    if (!WIPE_SYS_EndCheck()) return 0;
    GXx_SetMasterBrightness_((void *)0x0400006c,-16);
    GXx_SetMasterBrightness_((void *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    MUSICAL_MCSS_Delete(((State *)p)->actors);
    MUSICAL_SHOT_SYS_DeleteScene(((State *)p)->scene);
    MUSICAL_SHOT_SYS_ExitGraphics(p);
    func_02030EAC(((State *)p)->task);
    if (((State *)p)->save->b==1) func_02034A5C((int)ov_abs_84);
    if (flag==0) {
        func_020307B0(((State *)p)->save->config);
        func_020307B0(((State *)p)->save);
        func_02034A5C((int)ov_abs_84);
    }
    func_020315D4(owner);
    GFL_HEAP_DeleteChecked(74);
    return 1;
}

int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p)
{
    MUSICAL_SHOT_SYS_DrawScene(((State *)p)->scene);
    MUSICAL_MCSS_Main(((State *)p)->actors);
    CLACT_DrawSystem();
    if(MUSICAL_MCSS_NoOp2(((State *)p)->actors)==1) {
        WIPE_SYS_Start(0,0,0,0,6,1,((State *)p)->heap);
        return 1;
    }
    return 0;
}

/*
 * follower: tail stub at 0x021F3A4C; function_starts seed.
 */
void MUSICAL_SHOT_SYS_VBlank(void) { CLACT_VBlankSystem(); }

/*
 * volatile: hardware read-modify-writes at 0x021F3A64, 0x021F3A6E,
 *   0x021F3A94 (0x04000000, 0x04001000, 0x04000304).
 */
void MUSICAL_SHOT_SYS_InitGraphics(u8 *p)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile unsigned *)0x04000000 &= 0xffffe0ff;
    *(volatile unsigned *)0x04001000 &= 0xffffe0ff;
    WIPE_SetBrightnessFadeOut(0,0);
    WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021F816C);
    BG_SYS_Create(((State *)p)->heap);
    BMP_WIN_Init(((State *)p)->heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021F815C);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021F816C,((State *)p)->heap);
    BG_SYS_SetMainPlaneVisible(16,1);
}

void MUSICAL_SHOT_SYS_ExitGraphics(void *a0) { CLACT_ExitSystem(); BMP_WIN_Exit(); BG_SYS_Delete(); }
