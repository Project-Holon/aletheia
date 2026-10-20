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
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GF_STANDARD_GetCachedDate 0x0203F4E4 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   KEY_GetCont 0x0203630C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   MUSICAL_SHOT_INFO_Create 0x021F4284 thumb ov112
 *   WIPE_SYS_Start 0x0202208C thumb
 *   d_021F836C 0x021F836C data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   MUSICAL_SHOT_INFO_Delete 0x021F4300 thumb ov112
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   ov_abs_84 0x00000084 data
 *   MUSICAL_SHOT_INFO_Main 0x021F4350 thumb ov112
 *   MUSICAL_SHOT_INFO_IsFinished 0x021F44E8 thumb ov112
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
#include "../sdk_ioreg.h"
#include "musical_shot_types.h"

struct Proc;

struct RtcDate;

struct Proc;

struct DispConfig;

struct DispVram;

typedef struct {u32 x,y,z,week;} Options;

typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;

typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} MusicalShotSysState;

typedef enum {ConfigSize=432} AllocSize;

#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"

#include "../arm9/gf_overlay.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/gf_standard.h"

#include "../arm9/strbuf.h"

#include "../arm9/key.h"

#include "../arm9/gfl_use.h"


#include "../arm9/wipe.h"


#include "../arm9/gx.h"

#include "../arm9/g2.h"

#include "mus_shot_info.h"
struct TcbTask;

#include "../arm9/tcb_list.h"







#include "../arm9/clact.h"


#include "../arm9/bg_sys.h"






#include "../arm9/bmp_win.h"

struct DispVramCfg;
struct SysInit;






int MUSICAL_SHOT_SYS_Create(void *owner,int unused,const Save *save);

int MUSICAL_SHOT_SYS_Exit(void *owner,void *arg,int flag,u8 *p);

int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p);

void MUSICAL_SHOT_SYS_VBlank(void);

void MUSICAL_SHOT_SYS_InitGraphics(u8 *p);

void MUSICAL_SHOT_SYS_ExitGraphics(void *unused);

#include "mus_shot_photo.h"



extern char ov132_id[];

extern const char d_021F836C[];

extern u8 ov_abs_84[];

extern char d_021F816C[],d_021F815C[],gClActorInitParam[];

int MUSICAL_SHOT_SYS_Create(void *owner,int unused,const Save *save)
{
 MusicalShotSysState *p;u8 *cfg;u8 i,j;Options options;u32 length;
 GFL_HEAP_CreateChildHeap(1,74,1<<19);
 p=PROCSYS_AllocProcWork(owner,20,74);p->heap=74;
 if(save==0){
  GF_OVERLAY_Load((uptr)ov132_id);
  p->save=GFL_HEAP_Alloc(74,20,0,d_021F836C,110);
  length=ConfigSize;
  p->save->config=GFL_HEAP_Alloc(74,length,1,d_021F836C,111);
  p->save->b=0;
  cfg=p->save->config;
  GF_STANDARD_GetCachedDate((struct RtcDate *)(&options));
  ((MusicalShotRecord *)cfg)->programId=3;((MusicalShotRecord *)cfg)->winnerMask=(u8)2;
  ((MusicalShotRecord *)cfg)->year=options.x;((MusicalShotRecord *)cfg)->month=options.y;((MusicalShotRecord *)cfg)->day=options.z;
  *(u16 *)((uptr)cfg+(length-0x4C))=0x30DD;
  *(u16 *)((uptr)cfg+(length-0x4A))=0x30B1;
  *(u16 *)((uptr)cfg+(length-0x48))=0x30C3;
  *(u16 *)((uptr)cfg+(length-0x46))=0x30BF;
  *(u16 *)((uptr)cfg+(length-0x44))=0x30FC;
  *(u16 *)((uptr)cfg+(length-0x42))=0x30EA;
  *(u16 *)((uptr)cfg+(length-0x40))=0x30E2;
  *(u16 *)((uptr)cfg+(length-0x3E))=0x30F3;
  *(u16 *)((uptr)cfg+(length-0x3C))=0x30B9;
  *(u16 *)((uptr)cfg+(length-0x3A))=0x30BF;
  *(u16 *)((uptr)cfg+(length-0x38))=0x30FC;
  *(u16 *)((uptr)cfg+(length-0x36))=0x30EA;
  *(u16 *)((uptr)cfg+(length-0x34))=STRBUF_GetEosChar();
  ((MusicalShotRecord *)cfg)->performers[0].monsNo=643;((MusicalShotRecord *)cfg)->performers[1].monsNo=643;((MusicalShotRecord *)cfg)->performers[2].monsNo=643;((MusicalShotRecord *)cfg)->performers[3].monsNo=643;
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
 if(p->save->b==1)GF_OVERLAY_Load((uptr)ov132_id);
 p->task=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))((uptr)MUSICAL_SHOT_SYS_VBlank),(void *)((uptr)p),64);
 MUSICAL_SHOT_SYS_InitGraphics((u8 *)p);
 p->scene=MUSICAL_SHOT_SYS_CreateScene(p->save->config,p->heap);
 p->actors=MUSICAL_SHOT_INFO_Create((uptr)p->save->config,p->save->c,p->save->a,p->save->d,p->heap);
 WIPE_SYS_Start(0,1,1,0,6,1,p->heap);return 1;
}

int MUSICAL_SHOT_SYS_Exit(void *owner,void *arg,int flag,u8 *p) {
    if (!WIPE_SYS_EndCheck()) return 0;
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR,-16);
    GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR,-16);
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,0,0,31,31);
    MUSICAL_SHOT_INFO_Delete(((MusicalShotSysState *)p)->actors);
    MUSICAL_SHOT_SYS_DeleteScene(((MusicalShotSysState *)p)->scene);
    MUSICAL_SHOT_SYS_ExitGraphics(p);
    TCB_DeleteTask(((MusicalShotSysState *)p)->task);
    if (((MusicalShotSysState *)p)->save->b==1) GF_OVERLAY_Unload((sptr)ov_abs_84);
    if (flag==0) {
        GFL_HEAP_Free(((MusicalShotSysState *)p)->save->config);
        GFL_HEAP_Free(((MusicalShotSysState *)p)->save);
        GF_OVERLAY_Unload((sptr)ov_abs_84);
    }
    PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked(74);
    return 1;
}

int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p)
{
    MUSICAL_SHOT_SYS_DrawScene(((MusicalShotSysState *)p)->scene);
    MUSICAL_SHOT_INFO_Main(((MusicalShotSysState *)p)->actors);
    CLACT_DrawSystem();
    if(MUSICAL_SHOT_INFO_IsFinished(((MusicalShotSysState *)p)->actors)==1) {
        WIPE_SYS_Start(0,0,0,0,6,1,((MusicalShotSysState *)p)->heap);
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
    BG_SYS_Create(((MusicalShotSysState *)p)->heap);
    BMP_WIN_Init(((MusicalShotSysState *)p)->heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021F815C);
    CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam,(const struct DispVramCfg *)d_021F816C,((MusicalShotSysState *)p)->heap);
    BG_SYS_SetMainPlaneVisible(16,1);
}

void MUSICAL_SHOT_SYS_ExitGraphics(void *unused) { CLACT_ExitSystem(); BMP_WIN_Exit(); BG_SYS_Delete(); }
