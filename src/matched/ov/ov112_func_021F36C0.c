/*
 * function: MUSICAL_SHOT_SYS_Create
 * address: 0x021F36C0
 * packet: pkt_ov112_021F36C0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: retry rederived allocator, RTC, callback and final seven-argument call signatures; prior permuter 300 retained.
 * match: unsigned 88U*i and signed 88*i keep both row computations; a block slot pointer fixes the inner loop colouring; u32 allocation length fixes the final instruction schedule.
 * ABI: 3159C stores the allocation but leaves r0 live, used here as the State pointer. RTC copies four words.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   GF_STANDARD_SetField00_F4E4 0x0203F4E4 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   KEY_GetCont 0x0203630C arm
 *   func_020056A0 0x020056A0 thumb
 *   MUSICAL_SHOT_SYS_VBlank 0x021F3A4C thumb ov112
 *   MUSICAL_SHOT_SYS_InitGraphics 0x021F3A54 thumb ov112
 *   MUSICAL_SHOT_SYS_CreateScene 0x021F3AF0 thumb ov112
 *   MUSICAL_MCSS_Create 0x021F4284 thumb ov112
 *   WIPE_SYS_Start 0x0202208C thumb
 *   ov132_id 0x84 data
 *   d_021F836C 0x021F836C data a4
 */
#include "../include/Obj00587.h"
#include "../include/Obj08019.h"
#include "../include/Obj10295.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 a:5,b:4,c:7,d:5,e:6,f:5;} Settings;
typedef struct {u32 x,y,z,week;} Options;
typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;
typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} State;
typedef enum {ConfigSize=432} AllocSize;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern int func_02034AC4(int);
extern void *func_02030734(u32,u32,int,const char *,u16);
struct RtcDate;
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern u16 STRBUF_GetEosChar(void);
extern u32 KEY_GetCont(void);
extern void *func_020056A0(u32,u32,u32);
extern void MUSICAL_SHOT_SYS_VBlank(void);
extern void MUSICAL_SHOT_SYS_InitGraphics(u8 *);
extern u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap);
extern void *MUSICAL_MCSS_Create(u8 *,u32,u32,u32,u16);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern char ov132_id[];
extern const char d_021F836C[];
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
