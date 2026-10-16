/*
 * file:     musical_shot_sys.c
 * unit:     yes
 * function: MUSICAL_SHOT_SYS_Create, MUSICAL_SHOT_SYS_Exit, MUSICAL_SHOT_SYS_Update, MUSICAL_SHOT_SYS_InitGraphics, MUSICAL_SHOT_SYS_ExitGraphics, MUSICAL_SHOT_SYS_CreateScene, MUSICAL_SHOT_SYS_DeleteScene, MUSICAL_SHOT_SYS_DrawScene, MUSICAL_SHOT_SYS_Init3D, MUSICAL_SHOT_SYS_LoadBg, MUSICAL_SHOT_SYS_Exit3D, MUSICAL_SHOT_SYS_InitActors
 * address:  0x021F36C0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   MUSICAL_MCSS_AllocMon  0x021F67E0  thumb  ov112
 *   MUSICAL_MCSS_DrawLabel  0x021F40F4  thumb  ov112
 *   STA_ACT_LIGHT_AllocElem  0x021F6F24  thumb  ov112
 *   STA_ACT_LIGHT_CreateModel  0x021F6FB0  thumb  ov112
 *   STA_ACT_LIGHT_SetElemFrame  0x021F75DC  thumb  ov112
 *   STA_ACT_LIGHT_SetModelFrame  0x021F7098  thumb  ov112
 *   d_021F8380     0x021F8380  data  ov112  a1
 *   STA_ACT_LIGHT_DeleteUnit 0x021F6C7C thumb ov112
 *   STA_ACT_LIGHT_DeleteModel 0x021F6F4C thumb ov112
 *   STA_ACT_LIGHT_DeleteBillboardImage 0x021F7120 thumb ov112
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   MUSICAL_MCSS_DeleteActorPool 0x021F4948 thumb ov112
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STA_ACT_LIGHT_UpdateBillboard 0x021F7160 thumb ov112
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   STA_ACT_LIGHT_UpdateElemActors 0x021F6CB0 thumb ov112
 *   STA_ACT_LIGHT_NoOp 0x021F6E74 thumb ov112
 *   STA_ACT_LIGHT_UpdateElem 0x021F75A0 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   STA_ACT_LIGHT_UpdateSprite 0x021F718C thumb ov112
 *   STA_ACT_LIGHT_DrawModel 0x021F6F8C thumb ov112
 *   MUSICAL_MCSS_NoOp 0x021F4280 thumb ov112
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   BG_SYS_SetLowBit  0x0204044C  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   BILLBOARD_Create  0x0204EBD4  arm
 *   BILLBOARD_SetScale  0x0204ED70  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021F81AC  0x021F81AC  data  a4
 *   d_021F81B8  0x021F81B8  data  ov112  a4
 *   d_021F81A0  0x021F81A0  data  ov112  a4
 *   d_021F81C4  0x021F81C4  data  a4
 *   d_021F8274  0x021F8274  data  a4
 *   d_021F8258  0x021F8258  data  ov112  a4
 *   d_021F8214  0x021F8214  data  a4
 *   d_021F81D4  0x021F81D4  data  ov112  a4
 *   d_021F81F4  0x021F81F4  data  ov112  a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderFieldA 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   STA_ACT_LIGHT_AddBillboardImage 0x021F709C thumb ov112
 *   STA_ACT_LIGHT_AddPokemonElem 0x021F760C thumb ov112
 *   STA_ACT_LIGHT_ResetRenderAnim 0x021F80B0 thumb ov112
 *   STA_ACT_LIGHT_SetElemValue 0x021F8154 thumb ov112
 *   STA_ACT_LIGHT_CreateUnit 0x021F6BD8 thumb ov112
 *   MUSICAL_MCSS_SetObjectValue 0x021F40D0 thumb ov112
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   STA_ACT_LIGHT_SetActorOffset 0x021F8084 thumb ov112
 *   STA_ACT_LIGHT_CreateActor 0x021F6E78 thumb ov112
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   d_021F8240 0x021F8240 data a4
 *   d_021F8234 0x021F8234 data a4
 *   d_021F824C 0x021F824C data a4
 *   ov132_id 0x84 data
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 */
struct Proc;
struct RtcDate;
struct Node;
struct Proc;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Descriptor;
struct Board;
struct Camera;
struct Lights;
struct Blk3;
struct Light;
struct BgTemplate;
struct Object;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 x,y,z,week;} Options;

typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;

typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} State;

typedef enum {ConfigSize=432} AllocSize;

typedef short s16;

#include "musical_shot_types.h"

typedef struct { u32 w[7]; } T28;

typedef struct { u32 w[3]; } T12;

typedef struct 
{
  int x;
  int y;
  int z;
} Vec;

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
extern char *MUSICAL_MCSS_AllocMon(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
extern void MUSICAL_MCSS_DrawLabel(u8 *p);
extern u8 *STA_ACT_LIGHT_AllocElem(u32 heap, u32 v);
extern void STA_ACT_LIGHT_CreateModel(void *a, u8 b);
extern void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);
extern void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v);
extern void STA_ACT_LIGHT_DeleteUnit(char *p);
extern void STA_ACT_LIGHT_DeleteModel(u8 *p);
extern void STA_ACT_LIGHT_DeleteBillboardImage(char *p);
extern void MUSICAL_MCSS_DeleteRenderObj(int a);
extern void MUSICAL_MCSS_DeleteActorPool(u8 *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void STA_ACT_LIGHT_UpdateBillboard(u8 *p);
extern void MUSICAL_MCSS_TickAnim(u8 *);
extern void STA_ACT_LIGHT_UpdateElemActors(char *p);
extern void STA_ACT_LIGHT_NoOp(u32);
extern void STA_ACT_LIGHT_UpdateElem(u8 *p);
extern void MUSICAL_MCSS_DrawRenderObj(void **p);
extern void STA_ACT_LIGHT_UpdateSprite(char *p);
extern void STA_ACT_LIGHT_DrawModel(u8 *p);
extern void MUSICAL_MCSS_NoOp(u8 *);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void G3D_SYSTEM_DrawEnd(void);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern void BG_SYS_SetLowBit(u32 mode);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, const void *, const void *, const void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *a);
extern void *BILLBOARD_Create(u8 *src, void *heap);
extern void BILLBOARD_SetScale(u8 *dst, struct Blk3 *src);
extern void BG_SYS_FillScrollArea(u32, u32, u32);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_PushTile(u32 index);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_FreeLayerBuf(u32);
extern void BILLBOARD_Delete(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void *MUSICAL_MCSS_CreateRenderObj(u32);
extern struct Object *MUSICAL_MCSS_CreateActorPool(u32 owner, int count, u16 heap);
extern u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *STA_ACT_LIGHT_AddPokemonElem(u8 *, u8 *);
extern void MUSICAL_MCSS_SetRenderFieldA(void **p, int b);
extern void STA_ACT_LIGHT_ResetRenderAnim(int, int);
extern int STA_ACT_LIGHT_SetElemValue(int, int *, int);
extern void *STA_ACT_LIGHT_CreateUnit(u16, void *);
extern u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);
extern u32 MUSICAL_MCSS_SetObjectValue(void *p, u32 i, u16 c);
extern void STA_ACT_LIGHT_SetActorPos(void *unused, u32 *p, const u32 *q);
extern void STA_ACT_LIGHT_SetActorOffset(void *unused, u32 *p, const u32 *q);
extern void STA_ACT_LIGHT_CopyElemA(void *unused, u32 *p, const u32 *q);
int MUSICAL_SHOT_SYS_Create(void *owner,int unused,const Save *save);
int MUSICAL_SHOT_SYS_Exit(void *owner,void *arg,int flag,u8 *p);
int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p);
void MUSICAL_SHOT_SYS_VBlank(void);
void MUSICAL_SHOT_SYS_InitGraphics(u8 *p);
void MUSICAL_SHOT_SYS_ExitGraphics(void *a0);
u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap);
void MUSICAL_SHOT_SYS_DeleteScene(u8 *p);
void MUSICAL_SHOT_SYS_DrawScene(u8 *p);
void MUSICAL_SHOT_SYS_Init3D(char *p);
void MUSICAL_SHOT_SYS_LoadBg(const void *a,u32 b,u32 c);
void MUSICAL_SHOT_SYS_Exit3D(u8 *p);
void MUSICAL_SHOT_SYS_InitActors(ShotScene *p);
extern char ov132_id[];
extern const char d_021F836C[];
extern u8 ov_abs_84[];
extern char d_021F816C[],d_021F815C[],gClActorInitParam[];
extern char d_021F8380[];
extern const char d_021F81AC[];
extern const char d_021F81B8[];
extern const char d_021F81A0[];
extern const char d_021F81C4[];
extern const T28 d_021F8274;
extern const T12 d_021F8258;
extern const char d_021F8214[];
extern const char d_021F81D4[];
extern const char d_021F81F4[];
extern const Vec d_021F8240;
extern const Vec d_021F8234;
extern const Vec d_021F824C;


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


u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap)
{
    u8 i;
    u8 *o;
    u8 j;
    o = func_02030734(heap, 100, 1, d_021F8380, 0x85);
    *(u16 *)o = heap;
    *(u8 **)(o + 4) = src;
    for (i = 0; i < 4; i++) {
        u32 off = i * 0x58;
        u8 *row;
        *(u32 *)(o + i * 4 + 8) = (u32)MUSICAL_MCSS_AllocMon(*(u16 *)(src + off + 4), (u8)((MusicalPerformerBits *)(src + 6 + off))->gender, (u8)((MusicalPerformerBits *)(src + 6 + off))->form, (u8)((MusicalPerformerBits *)(src + 6 + off))->shiny, *(u32 *)(src + off + 8), heap);
        row = (u8 *)((u32)src + off);
        for (j = 0; j < 8; j++) {
            u8 k = row[j * 8 + 0x20];
            if (k != 10) {
                *(u16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x14) = *(u16 *)(row + j * 8 + 0x1c);
                *(s16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x16) = *(s16 *)(row + j * 8 + 0x1e);
                *(u8 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x18) = j;
            }
        }
    }
    MUSICAL_SHOT_SYS_Init3D((char *)o);
    MUSICAL_SHOT_SYS_InitActors((ShotScene *)o);
    MUSICAL_MCSS_DrawLabel(o);
    ((ShotScene *)o)->model = STA_ACT_LIGHT_AllocElem(*(u16 *)o, 0);
    STA_ACT_LIGHT_CreateModel(((ShotScene *)o)->model, (u8)((ShotScene *)o)->record->programId);
    STA_ACT_LIGHT_SetElemFrame(((ShotScene *)o)->sprite, 0x80);
    STA_ACT_LIGHT_SetModelFrame(((ShotScene *)o)->model, 0x80);
    return o;
}


void MUSICAL_SHOT_SYS_DeleteScene(u8 *p)
{
    u8 i;
    STA_ACT_LIGHT_DeleteUnit((char *)((ShotScene *)p)->unit);
    STA_ACT_LIGHT_DeleteModel((u8 *)((ShotScene *)p)->model);
    STA_ACT_LIGHT_DeleteBillboardImage(((ShotScene *)p)->sprite);
    MUSICAL_MCSS_DeleteRenderObj((int)((ShotScene *)p)->renderObj);
    MUSICAL_MCSS_DeleteActorPool(((ShotScene *)p)->actorPool);
    BMP_WIN_Delete(((ShotScene *)p)->winB);
    BMP_WIN_Delete(((ShotScene *)p)->winA);
    GF_FONT_Delete(((ShotScene *)p)->fontB);
    GF_FONT_Delete(((ShotScene *)p)->fontA);
    MUSICAL_SHOT_SYS_Exit3D(p);
    for(i=0;i<4;i++) func_020307B0(*(void **)(p+i*4+8));
    func_020307B0(p);
}


/*
 * extent: two-byte padding at 0x021F3CA2.
 */
void MUSICAL_SHOT_SYS_DrawScene(u8 *p)
{
    STA_ACT_LIGHT_UpdateBillboard((u8 *)((ShotScene *)p)->sprite);
    MUSICAL_MCSS_TickAnim(((ShotScene *)p)->renderObj);
    STA_ACT_LIGHT_UpdateElemActors((char *)((ShotScene *)p)->unit);
    func_02047964();
    G3D_SYSTEM_ApplyLookAt();
    STA_ACT_LIGHT_NoOp((u32)((ShotScene *)p)->unit);
    STA_ACT_LIGHT_UpdateElem((u8 *)((ShotScene *)p)->sprite);
    MUSICAL_MCSS_DrawRenderObj((void **)((ShotScene *)p)->renderObj);
    STA_ACT_LIGHT_UpdateSprite((char *)((ShotScene *)p)->sprite);
    STA_ACT_LIGHT_DrawModel((u8 *)((ShotScene *)p)->model);
    BILLBOARD_Draw((struct Board *)((ShotScene *)p)->board,(struct Camera *)((ShotScene *)p)->camera,0);
    MUSICAL_MCSS_NoOp(p);
    G3D_SYSTEM_DrawEnd();
}



static inline void G2_SetWndOBJInsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~0x3F00u) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}


static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}



/*
 * 2026-10-05 (user decision): the u32 return in the ARC_UTIL_UploadPaletteFromHandle declaration (void definition) is accepted as a real mismatched declaration.
 * note (2026-10-05, wave D9r lane 70): closed from 422 differing bytes. The residue (3 and 1 held
 *   in r7/r4 in the head, late r3 zeros copied from r6) came from the return type of
 *   ARC_UTIL_UploadPaletteFromHandle: declared u32 instead of void, the head constant webs and the fresh late zeros
 *   come out as in the original. func_02049658 is u32 as in the matched ov123 021D9D3C and
 *   ov210 021BC5DC callers (its helper 0x0204968C returns r4). Caveat for review: the matched
 *   arm9 definition of ARC_UTIL_UploadPaletteFromHandle is void, and its helper 0x02049C28 sets no return value on
 *   its last path, so u32 is the game header's declaration, not a computed result. Constants
 *   are plain literals (0xC000, 0x10000, 0x1000). The four contested data hints (d_021F81AC,
 *   d_021F81C4, d_021F8274, d_021F8214) resolve without the overlay token.
 * note 2026-10-05 (integrator): parked in pending although it verifies EXACT. It closes only with
 * ARC_UTIL_UploadPaletteFromHandle declared u32; its matched arm9 definition is void and every matched caller declares
 * it void. Waiting for the user to accept or reject that declaration.
 */
void MUSICAL_SHOT_SYS_Init3D(char *p)
{
    void *h;
    void *cam;
    T28 a;
    T12 b;
    T12 *pb;

    G3D_SYSTEM_Init(0, 2, 0, 4, 0, *(u16 *)p, 0);
    BG_SYS_SetLowBit(3);
    G3D_SYSTEM_SetSwapBuffersMode(0, 1);
    cam = G3D_CAMERA_Create(2, 0xC000, 0, 0, 0x10000, 0x1000, 0x3E8000, 0,
                        d_021F81AC, d_021F81B8, d_021F81A0, *(u16 *)p);
    *(void **)(p + 0x18) = cam;
    func_02048AD0(cam);
    func_0207DCF8(d_021F81C4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    a = d_021F8274;
    b = d_021F8258;
    pb = &b;
    h = BILLBOARD_Create((u8 *)(&a), (void *)(*(u16 *)p));
    *(void **)(p + 0x1C) = h;
    BILLBOARD_SetScale(h, (struct Blk3 *)pb);
    MUSICAL_SHOT_SYS_LoadBg(d_021F8214, 1, 0);
    MUSICAL_SHOT_SYS_LoadBg(d_021F81D4, 2, 0);
    MUSICAL_SHOT_SYS_LoadBg(d_021F81F4, 3, 0);
    BG_SYS_FillScrollArea(2, 3, 0xE0);
    h = func_020490F4(0x2F, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 3, 0, 0, 0, 0x20, *(u16 *)p);
    func_02049658(h, 9, 2, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xF, 2, 0, 0, 0, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 0, 0x20, 0x20, 0x20, *(u16 *)p);
    func_02049658(h, 8, 3, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xE, 3, 0, 0, 0, *(u16 *)p);
    BG_SYS_PushTile(2);
    BG_SYS_PushTile(3);
    ARC_TOOL_DeleteHandle(h);
    func_0207D63C((void *)0x04000050, 8, 1, 0, 0xA);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    G2_SetWndOBJInsidePlane(0x17, 1);
    G2_SetWndOutsidePlane(0x1F, 1);
}


void MUSICAL_SHOT_SYS_LoadBg(const void *a,u32 b,u32 c) { BG_SYS_InitBgLayer(b,a,c); func_02040588(b,1); BG_SYS_FreeSlot(b); BG_SYS_PushTile(b); }


void MUSICAL_SHOT_SYS_Exit3D(u8 *p) { BG_SYS_FreeLayerBuf(3); BG_SYS_FreeLayerBuf(1); BG_SYS_FreeLayerBuf(2); BILLBOARD_Delete(((ShotScene *)p)->board); G3D_CAMERA_Delete(((ShotScene *)p)->camera); G3D_SYSTEM_Exit(); BG_SYS_FreeLayerBuf(0); }


/*
 * checks: retry rederived all callees; prior permuter 300 retained. Original table pool is 8240,8234,824C; declaration order restores it and all three resolve.
 * match: u32 offset and integer row address retain the spilled row and live index; vectors follow frame order; second loop reuses the earlier j as mask and mask as index; final mask advances before i.
 * ABI: 760C leaves a live result used by this caller despite its own void declaration.
 */
void MUSICAL_SHOT_SYS_InitActors(ShotScene *p)
{
  u32 offset;
  Vec pos = d_021F8240;
  Vec scale = d_021F8234;
  int z[4];
  Vec temp;
  Vec base;
  u8 i;
  u8 mask;
  u8 j;
  int flags;
  int current;
  void *q;
  u8 *row;
  int tmp1;
  void *tmp;
  current = 5 << 16;
  p->renderObj = MUSICAL_MCSS_CreateRenderObj(p->heap);
  MUSICAL_MCSS_SetRenderFieldA(p->renderObj, 2 << 16);
  p->actorPool = MUSICAL_MCSS_CreateActorPool((u32) p->board, 36, p->heap);
  p->sprite = STA_ACT_LIGHT_AddBillboardImage(p->heap, 0, (u32)p->renderObj, (u32)p->actorPool, (u32)p->board);
  for (i = 0; i < 4; i++)
    p->models[i] = 0;

  for (j = 0; j < 4; j++)
  {
    row = ((u8 *) p) + (4 * j);
    q = STA_ACT_LIGHT_AddPokemonElem(p->sprite, *((u8 **) (row + 8)));
    if (1)
    {
      *((void **) (row + 0x30)) = q;
      STA_ACT_LIGHT_ResetRenderAnim((int)p->sprite, (int)q);
      STA_ACT_LIGHT_SetElemValue((int) p->sprite, *((int **) (row + 0x30)), 1);
    }
  }

  flags = p->record->winnerMask;
  for (i = 0, mask = 1; i < 4; i++, mask <<= 1)
  {
    if (!(flags & mask))
    {
      z[i] = current;
      current += 30 << 12;
    }
  }

  for (j = 1, mask = 0; mask < 4; j <<= 1, mask++)
  {
    if (flags & j)
    {
      z[mask] = current;
      current += 30 << 12;
    }
  }

  i = 0;
  mask = 1;
  tmp = STA_ACT_LIGHT_CreateUnit(p->heap, 0);
  p->unit = tmp;
  base = d_021F824C;
  for (; i < 4; mask <<= 1, i++)
  {
    offset = 4 * i;
    row = (u8 *)(((u32)p) + offset);
    scale.x = MUSICAL_MCSS_SetObjectValue(p, i, *((u16 *) ((*((u8 **) (row + 8))) + 8)));
    if (p->record->winnerMask & mask)
    {
      u8 *actor;
      temp = base;
      actor = ((u8 *) p) + offset;
      pos.x = MUSICAL_MCSS_SetObjectValue(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      STA_ACT_LIGHT_SetActorPos(p->sprite, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      STA_ACT_LIGHT_SetActorOffset(p->sprite, *((void **) (actor + 0x30)), (const u32 *)(&temp));
      scale.y = 22 << 14;
    }
    else
    {
      u8 *actor;
      actor = ((u8 *) p) + offset;
      pos.x = MUSICAL_MCSS_SetObjectValue(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      STA_ACT_LIGHT_SetActorPos(p->sprite, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      tmp1 = 2 << 18;
      scale.y = tmp1;
    }
    *((void **) (row + 0x44)) = STA_ACT_LIGHT_CreateActor(p->unit, 1);
    STA_ACT_LIGHT_CopyElemA(p->unit, *((void **) (row + 0x44)), (const u32 *)(&scale));
  }

}
