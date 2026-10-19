/*
 * function: SUBWAY_MAP_GRAPHIC_Init
 * address: 0x021B95A0
 * packet: pkt_ov224_021B95A0
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 BG_SYS_ClearSubPlanes is defined in src/matched/arm9/unit_02043570.c
 *   but omitted from its function: header; the integrator owns this unit.
 * blocker: verified EXACT 16-byte ARM C copied from
 *   src/pending/ov/ov133_func_021B69AC.c after the caller's MATCH verdict:
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * tu: MATCH 376 bytes, 29/30 relocations; --suggest-split has no viable partition.
 * lever: non-const resource table retains original outgoing stack-store order.
 * volatile: display control rereads 021B961C-021B962C.
 * arity: 0203159C retains consumed r0 allocation despite own void declaration.
 * arity: BG callees narrow bytes explicitly before each call.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   SUBWAY_MAP_GRAPHIC_CreateScreen 0x021B9940 thumb ov224
 *   SUBWAY_MAP_GRAPHIC_TaskNoop 0x021B9820 thumb ov224
 *   SUBWAY_MAP_GRAPHIC_LoadCommonAssets 0x021B9824 thumb ov224
 *   gSubwayMapGraphicSubBgLayerTable 0x021B9C04 data a4
 *   gSubwayMapGraphicChoiceAssets 0x021B9D40 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ZERO=0,ONE=1 } Index;
typedef enum { MODE=2 } Mode;
struct BgTemplate {u32 words[8];};
struct Entry { u32 id; struct BgTemplate bg; u32 kind,visible; };
struct Assets {u32 palette,screen,chars;};
struct Work {u16 heap,pad2; void **args; void *screen,*font;u32 string;void *task;};
struct GfFont; struct Proc;
extern const struct Entry gSubwayMapGraphicSubBgLayerTable[];
extern struct Assets gSubwayMapGraphicChoiceAssets[];
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *,u32,u32);
extern void MI_CpuFill8(void *,u32,u32);
extern void *SUBWAY_MAP_GRAPHIC_CreateScreen(u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern void BG_SYS_SetPriority(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void SUBWAY_MAP_GRAPHIC_TaskNoop(void);
extern void SUBWAY_MAP_GRAPHIC_LoadCommonAssets(u16 *);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0207D518(u32);
extern void BG_SYS_ClearSubBgPlanes(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_PushTile(u32);
extern void FADE_Start(u32,int,int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
static inline void SetMode(Mode mode) {
 *(volatile u32 *)0x04001000 &= 0xffff1fff;
 *(volatile u32 *)0x04001000 |= mode<<15;
}
int SUBWAY_MAP_GRAPHIC_Init(struct Proc *proc,void *unused,void **args)
{
 struct Work *p;
 Index i;
 const struct Entry *row;
 u32 id,choice;
 u16 heap;
 void *arc;
 GFL_HEAP_CreateChildHeap((u32)((void *)1),0x88,0x30000);
 p=PROCSYS_AllocProcWork(proc,0x18,0x88);
 MI_CpuFill8(p,0,0x18);
 p->heap=0x88; p->args=args;
 p->screen=SUBWAY_MAP_GRAPHIC_CreateScreen(1,p->heap);
 p->font=GF_FONT_Create(23,0,0,0,p->heap);
 p->string=PRINTSYS_QUE_Create((void *)(u32)p->heap);
 BG_SYS_SetPriority(1,1); BG_SYS_SetPriority(2,0);
 p->task=func_020056A0((u32)SUBWAY_MAP_GRAPHIC_TaskNoop,(u32)p,1);
 SUBWAY_MAP_GRAPHIC_LoadCommonAssets((u16 *)p);
 i=ZERO;
 *(volatile u16 *)0x04001050=0;
 SetMode(MODE);
 BG_SYS_ClearSubPlanes();
 func_0207D518(0);
 BG_SYS_ClearSubBgPlanes();
 do {
  row=&gSubwayMapGraphicSubBgLayerTable[i]; id=row->id;
  BG_SYS_InitBgLayer((u8)id,&row->bg,(u8)row->kind);
  BG_SYS_FreeSlot(id);
  func_02040588(id,row->visible);
  i++;
 }while(i<1U);
 BG_SYS_SetSubPlaneVisible(16,1);
 heap=p->heap;
 choice=1;
 if(*((u8 *)*p->args+0x1d)!=1) choice=0;
 arc=func_020490F4(30,heap);
 func_02049B68(arc,gSubwayMapGraphicChoiceAssets[choice].palette,4,0,0,heap);
 func_02049658(arc,gSubwayMapGraphicChoiceAssets[choice].screen,4,0,0,0,heap);
 func_020498F4(arc,gSubwayMapGraphicChoiceAssets[choice].chars,4,0,0,0,heap);
 ARC_TOOL_DeleteHandle(arc);
 BG_SYS_PushTile(4);
 FADE_Start(3,16,0,0);
 GFL_NET_RestartWithDefaultTimeout(0,p->heap);
 return 1;
}
