/*
 * file:     musical_shot_sys.c
 * unit:     yes
 * function: func_021F36C0, func_021F3970, func_021F3A08, func_021F3A54, func_021F3AE0, func_021F3AF0, func_021F3BF0, func_021F3C50, func_021F3CA4, func_021F3EAC, func_021F3ED0, func_021F3F00
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
 *   func_0203F4E4 0x0203F4E4 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_0203630C 0x0203630C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F4284 0x021F4284 thumb ov112
 *   WIPE_SYS_Start 0x0202208C thumb
 *   d_021F836C 0x021F836C data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021F4300 0x021F4300 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ov_abs_84 0x00000084 data
 *   func_021F4350 0x021F4350 thumb ov112
 *   func_021F44E8 0x021F44E8 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   d_021F816C 0x021F816C data a4
 *   d_021F815C 0x021F815C data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_021F67E0  0x021F67E0  thumb  ov112
 *   func_021F40F4  0x021F40F4  thumb  ov112
 *   func_021F6F24  0x021F6F24  thumb  ov112
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *   func_021F75DC  0x021F75DC  thumb  ov112
 *   func_021F7098  0x021F7098  thumb  ov112
 *   d_021F8380     0x021F8380  data  ov112  a1
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_020452E8 0x020452E8 arm
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_021F4280 0x021F4280 thumb ov112
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   func_0204044C  0x0204044C  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   func_0204EBD4  0x0204EBD4  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_02040618  0x02040618  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
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
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_0204ED24 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F80B0 0x021F80B0 thumb ov112
 *   func_021F8154 0x021F8154 thumb ov112
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F40D0 0x021F40D0 thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_021F8084 0x021F8084 thumb ov112
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   d_021F8240 0x021F8240 data a4
 *   d_021F8234 0x021F8234 data a4
 *   d_021F824C 0x021F824C data a4
 *   ov132_id 0x84 data
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 */
#include "../../matched/include/Obj00587.h"
#include "../../matched/include/Obj08019.h"
#include "../../matched/include/Obj10295.h"
#include "../../matched/include/Obj05308.h"
#include "../../matched/include/Obj22509.h"
#include "../../matched/include/Obj22510.h"
#include "../../matched/include/Obj08020.h"
#include "../../matched/include/Obj10296.h"
#include "../../matched/include/Obj03246.h"
#include "../../matched/include/Obj02823.h"
#include "../../matched/include/Obj13824.h"

struct Obj0203159C;
struct RtcDate;
struct Node;
struct S020315D4;
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

typedef struct {u32 a:5,b:4,c:7,d:5,e:6,f:5;} Settings;

typedef struct {u32 x,y,z,week;} Options;

typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;

typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} State;

typedef enum {ConfigSize=432} AllocSize;

typedef short s16;

struct F5 { u32 v : 5; };

struct BF { u16 a : 2; u16 c : 1; u16 b : 5; };

typedef struct { u32 w[7]; } T28;

typedef struct { u32 w[3]; } T12;

typedef struct 
{
  int x;
  int y;
  int z;
} Vec;

typedef struct 
{
  u32 low : 5;
  u32 flags : 4;
  u32 high : 23;
} Flags;

typedef struct 
{
  u16 heap;
  u16 pad;
  Flags *cfg;
  u8 *objects[4];
  void *unused;
  void *owner;
  void *scene;
  void *actors;
  void *unused28;
  void *render;
  void *models[4];
  void *effect;
  void *effects[4];
} Context;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern int func_02034AC4(int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0203F4E4(struct RtcDate *date);
extern u16 STRBUF_GetEosChar(void);
extern u32 func_0203630C(void);
extern void *func_020056A0(u32,u32,u32);
extern void *func_021F4284(u8 *,u32,u32,u32,u16);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern unsigned WIPE_SYS_EndCheck(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021F4300(u8 *);
extern void func_02030EAC(struct Node *n);
extern void func_02034A5C(int);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_021F4350(u8 *p);
extern int func_021F44E8(u32 *p);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern u32 WIPE_ResetWndMask(void *win);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern char *func_021F67E0(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
extern void func_021F40F4(u8 *p);
extern u8 *func_021F6F24(u32 heap, u32 v);
extern void func_021F6FB0(void *a, u8 b);
extern void func_021F75DC(u8 *p, u16 v);
extern void func_021F7098(u8 *p, u16 v);
extern void func_021F6C7C(char *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021F7160(u8 *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u32);
extern void func_021F75A0(u8 *p);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *p);
extern void func_021F4280(u8 *);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void G3D_SYSTEM_DrawEnd(void);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern void func_0204044C(u32 mode);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, const void *, const void *, const void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *a);
extern void *func_0204EBD4(u8 *src, void *heap);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_02040618(u32, u32, u32);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 index);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020403F4(u32);
extern void func_0204ED24(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void *func_021F5164(u32);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *func_021F760C(u8 *, u8 *);
extern void func_021F5438(void **p, int b);
extern void func_021F80B0(int, int);
extern int func_021F8154(int, int *, int);
extern void *func_021F6BD8(u16, void *);
extern u8 *func_021F6E78(u8 *p, int v);
extern u32 func_021F40D0(void *p, u32 i, u16 c);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern void func_021F8084(void *unused, u32 *p, const u32 *q);
extern void func_021F6EF4(void *unused, u32 *p, const u32 *q);
int func_021F36C0(void *owner,int unused,const Save *save);
int func_021F3970(void *owner,void *arg,int flag,u8 *p);
int func_021F3A08(int a,int b,int c,u8 *p);
void func_021F3A4C(void);
void func_021F3A54(u8 *p);
void func_021F3AE0(void *a0);
u8 *func_021F3AF0(u8 *src, u16 heap);
void func_021F3BF0(u8 *p);
void func_021F3C50(u8 *p);
void func_021F3CA4(char *p);
void func_021F3EAC(const void *a,u32 b,u32 c);
void func_021F3ED0(u8 *p);
void func_021F3F00(Context *p);
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


int func_021F36C0(void *owner,int unused,const Save *save)
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
  func_0203F4E4((struct RtcDate *)(&options));
  ((Settings *)cfg)->a=3;((Settings *)cfg)->b=(u8)2;
  ((Settings *)cfg)->c=options.x;((Settings *)cfg)->d=options.y;((Settings *)cfg)->e=options.z;
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
  ((struct Obj08019 *)cfg)->f4=643;((struct Obj08019 *)cfg)->f5C=643;((struct Obj08019 *)cfg)->fB4=643;((struct Obj08019 *)cfg)->f10C=643;
  for(i=0;i<4;i++){
   u8 *q;
   q=cfg+88U*i;
   ((struct Obj00587 *)q)->fC=0x30C8;((struct Obj00587 *)q)->fE=0x30EC;((struct Obj00587 *)q)->f10=0x30FC;((struct Obj00587 *)q)->f12=0x30CA;((struct Obj00587 *)q)->f14=0xFF11+i;((struct Obj00587 *)q)->f16=0;
   for(j=0;j<8;j++){u8 *slot;slot=q+8*j;((struct Obj10295 *)slot)->f1C=255;((struct Obj10295 *)slot)->f1E=0;((struct Obj10295 *)slot)->f20=10;}
   q=cfg+88*i;
   ((struct Obj00587 *)q)->f1C=11;((struct Obj00587 *)q)->f1E=0;q[32]=7;
   ((struct Obj00587 *)q)->f24=11;((struct Obj00587 *)q)->f26=0;q[40]=8;
   ((struct Obj00587 *)q)->f2C=11;((struct Obj00587 *)q)->f2E=0;q[48]=6;
   ((struct Obj00587 *)q)->f34=11;((struct Obj00587 *)q)->f36=0;q[56]=4;
   ((struct Obj00587 *)q)->f3C=11;((struct Obj00587 *)q)->f3E=0;q[64]=2;
   ((struct Obj00587 *)q)->f44=11;((struct Obj00587 *)q)->f46=0;q[72]=1;
   ((struct Obj00587 *)q)->f4C=11;((struct Obj00587 *)q)->f4E=0;q[80]=0;
  }
  if(func_0203630C()&256)p->save->a=1;else p->save->a=0;
  p->save->c=0;
 }else p->save=(Save *)save;
 if(p->save->b==1)func_02034AC4((u32)ov132_id);
 p->task=func_020056A0((u32)func_021F3A4C,(u32)p,64);
 func_021F3A54((u8 *)p);
 p->scene=func_021F3AF0(p->save->config,p->heap);
 p->actors=func_021F4284(p->save->config,p->save->c,p->save->a,p->save->d,p->heap);
 WIPE_SYS_Start(0,1,1,0,6,1,p->heap);return 1;
}


int func_021F3970(void *owner,void *arg,int flag,u8 *p) {
    if (!WIPE_SYS_EndCheck()) return 0;
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    func_021F4300(*(u8 * *)&((struct Obj05308 *)p)->f10);
    func_021F3BF0(*(u8 * *)&((struct Obj05308 *)p)->fC);
    func_021F3AE0(p);
    func_02030EAC(((struct Obj05308 *)p)->f4);
    if (((struct Obj22509 *)(*(u8 * *)&((struct Obj05308 *)p)->f8))->f4==1) func_02034A5C((int)ov_abs_84);
    if (flag==0) {
        func_020307B0(((struct Obj22510 *)(*(u8 * *)&((struct Obj05308 *)p)->f8))->f8);
        func_020307B0(((struct Obj05308 *)p)->f8);
        func_02034A5C((int)ov_abs_84);
    }
    func_020315D4(owner);
    func_020306F0(74);
    return 1;
}


int func_021F3A08(int a,int b,int c,u8 *p)
{
    func_021F3C50(*(u8 * *)&((struct Obj08020 *)p)->fC);
    func_021F4350(((struct Obj08020 *)p)->f10);
    CLACT_DrawSystem();
    if(func_021F44E8(((struct Obj08020 *)p)->f10)==1) {
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj08020 *)p)->f0);
        return 1;
    }
    return 0;
}


/*
 * follower: tail stub at 0x021F3A4C; function_starts seed.
 */
void func_021F3A4C(void) { CLACT_VBlankSystem(); }


/*
 * volatile: hardware read-modify-writes at 0x021F3A64, 0x021F3A6E,
 *   0x021F3A94 (0x04000000, 0x04001000, 0x04000304).
 */
void func_021F3A54(u8 *p)
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
    func_0203F8F4(((struct Obj10296 *)p)->f0);
    BMP_WIN_Init(((struct Obj10296 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021F815C);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021F816C,((struct Obj10296 *)p)->f0);
    func_020434DC(16,1);
}


void func_021F3AE0(void *a0) { CLACT_ExitSystem(); BMP_WIN_Exit(); func_0203F9B4(); }


u8 *func_021F3AF0(u8 *src, u16 heap)
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
        *(u32 *)(o + i * 4 + 8) = (u32)func_021F67E0(*(u16 *)(src + off + 4), (u8)((struct BF *)(src + 6 + off))->a, (u8)((struct BF *)(src + 6 + off))->b, (u8)((struct BF *)(src + 6 + off))->c, *(u32 *)(src + off + 8), heap);
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
    func_021F3CA4((char *)o);
    func_021F3F00((Context *)o);
    func_021F40F4(o);
    *(void **)(o + 0x28) = func_021F6F24(*(u16 *)o, 0);
    func_021F6FB0(*(void **)(o + 0x28), (u8)((struct F5 *)*(u8 **)(o + 4))->v);
    func_021F75DC(*(void **)(o + 0x2c), 0x80);
    func_021F7098(*(void **)(o + 0x28), 0x80);
    return o;
}


void func_021F3BF0(u8 *p)
{
    u8 i;
    func_021F6C7C((char *)(((struct Obj03246 *)p)->f40));
    func_021F6F4C((u8 *)(((struct Obj03246 *)p)->f28));
    func_021F7120(((struct Obj03246 *)p)->f2C);
    func_021F51B0(((struct Obj03246 *)p)->f20);
    func_021F4948(*(u8 * *)&((struct Obj03246 *)p)->f24);
    func_020452E8(((struct Obj03246 *)p)->f58);
    func_020452E8(((struct Obj03246 *)p)->f54);
    GF_FONT_Delete(((struct Obj03246 *)p)->f60);
    GF_FONT_Delete(((struct Obj03246 *)p)->f5C);
    func_021F3ED0(p);
    for(i=0;i<4;i++) func_020307B0(*(void **)(p+i*4+8));
    func_020307B0(p);
}


/*
 * extent: two-byte padding at 0x021F3CA2.
 */
void func_021F3C50(u8 *p)
{
    func_021F7160((u8 *)(((struct Obj02823 *)p)->f2C));
    func_021F51E8(*(u8 * *)&((struct Obj02823 *)p)->f20);
    func_021F6CB0((char *)(((struct Obj02823 *)p)->f40));
    func_02047964();
    G3D_SYSTEM_ApplyLookAt();
    func_021F6E74(((struct Obj02823 *)p)->f40);
    func_021F75A0((u8 *)(((struct Obj02823 *)p)->f2C));
    func_021F51F4((void **)(*(u32 *)&((struct Obj02823 *)p)->f20));
    func_021F718C((char *)(((struct Obj02823 *)p)->f2C));
    func_021F6F8C((u8 *)(((struct Obj02823 *)p)->f28));
    BILLBOARD_Draw((struct Board *)(((struct Obj02823 *)p)->f1C),(struct Camera *)(((struct Obj02823 *)p)->f18),0);
    func_021F4280(p);
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
void func_021F3CA4(char *p)
{
    void *h;
    void *cam;
    T28 a;
    T12 b;
    T12 *pb;

    G3D_SYSTEM_Init(0, 2, 0, 4, 0, *(u16 *)p, 0);
    func_0204044C(3);
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
    h = func_0204EBD4((u8 *)(&a), (void *)(*(u16 *)p));
    *(void **)(p + 0x1C) = h;
    func_0204ED70(h, (struct Blk3 *)pb);
    func_021F3EAC(d_021F8214, 1, 0);
    func_021F3EAC(d_021F81D4, 2, 0);
    func_021F3EAC(d_021F81F4, 3, 0);
    func_02040618(2, 3, 0xE0);
    h = func_020490F4(0x2F, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 3, 0, 0, 0, 0x20, *(u16 *)p);
    func_02049658(h, 9, 2, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xF, 2, 0, 0, 0, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 0, 0x20, 0x20, 0x20, *(u16 *)p);
    func_02049658(h, 8, 3, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xE, 3, 0, 0, 0, *(u16 *)p);
    func_020409B4(2);
    func_020409B4(3);
    ARC_TOOL_DeleteHandle(h);
    func_0207D63C((void *)0x04000050, 8, 1, 0, 0xA);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    G2_SetWndOBJInsidePlane(0x17, 1);
    G2_SetWndOutsidePlane(0x1F, 1);
}


void func_021F3EAC(const void *a,u32 b,u32 c) { func_0203FCA0(b,a,c); func_02040588(b,1); func_020414AC(b); func_020409B4(b); }


void func_021F3ED0(u8 *p) { func_020403F4(3); func_020403F4(1); func_020403F4(2); func_0204ED24(((struct Obj13824 *)p)->f1C); G3D_CAMERA_Delete(((struct Obj13824 *)p)->f18); G3D_SYSTEM_Exit(); func_020403F4(0); }


/*
 * checks: retry rederived all callees; prior permuter 300 retained. Original table pool is 8240,8234,824C; declaration order restores it and all three resolve.
 * match: u32 offset and integer row address retain the spilled row and live index; vectors follow frame order; second loop reuses the earlier j as mask and mask as index; final mask advances before i.
 * ABI: 760C leaves a live result used by this caller despite its own void declaration.
 */
void func_021F3F00(Context *p)
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
  p->scene = func_021F5164(p->heap);
  func_021F5438(p->scene, 2 << 16);
  p->actors = func_021F48C0((u32) p->owner, 36, p->heap);
  p->render = func_021F709C(p->heap, 0, (u32)p->scene, (u32)p->actors, (u32)p->owner);
  for (i = 0; i < 4; i++)
    p->models[i] = 0;

  for (j = 0; j < 4; j++)
  {
    row = ((u8 *) p) + (4 * j);
    q = func_021F760C(p->render, *((u8 **) (row + 8)));
    if (1)
    {
      *((void **) (row + 0x30)) = q;
      func_021F80B0((int)p->render, (int)q);
      func_021F8154((int) p->render, *((int **) (row + 0x30)), 1);
    }
  }

  flags = p->cfg->flags;
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
  tmp = func_021F6BD8(p->heap, 0);
  p->effect = tmp;
  base = d_021F824C;
  for (; i < 4; mask <<= 1, i++)
  {
    offset = 4 * i;
    row = (u8 *)(((u32)p) + offset);
    scale.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (row + 8))) + 8)));
    if (p->cfg->flags & mask)
    {
      u8 *actor;
      temp = base;
      actor = ((u8 *) p) + offset;
      pos.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      func_021F8054(p->render, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      func_021F8084(p->render, *((void **) (actor + 0x30)), (const u32 *)(&temp));
      scale.y = 22 << 14;
    }
    else
    {
      u8 *actor;
      actor = ((u8 *) p) + offset;
      pos.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      func_021F8054(p->render, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      tmp1 = 2 << 18;
      scale.y = tmp1;
    }
    *((void **) (row + 0x44)) = func_021F6E78(p->effect, 1);
    func_021F6EF4(p->effect, *((void **) (row + 0x44)), (const u32 *)(&scale));
  }

}
