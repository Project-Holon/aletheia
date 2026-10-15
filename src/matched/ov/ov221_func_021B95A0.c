/*
 * function: CHIHOU_ZUKAN_AWARD_Init
 * address: 0x021B95A0
 * packet: pkt_ov221_021B95A0
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 every callee rederived from its owner or observed register setup; 2 ov222 pending twin and matched 9748 enum loop re-read; 3 enum do-while alone remained DIFF2, named BG_MODE0 plus uncast call rescued MATCH424; 4 enum-zero and enum-folding idioms cover the lever; 5 full idiom directory and own/sibling neighbors refreshed; prior once300 not repeated.
 * residual: zero concrete differences in 424/424 bytes; 35/36 relocations resolved. Required tu --suggest-split MATCH424, no viable partition.
 * dependency: sole unresolved ARM9 02043588 omitted from src/matched/arm9/unit_02043570.c's function header.
 *   Blocker C reverified EXACT16 at fixed flags and --arm this retry (scratch only):
 *   symbols for blocker: BG_SYS_ClearSubBgPlanes 0x02043558 arm; BG_SYS_ClearSubObjPlane 0x02043570 arm.
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) {BG_SYS_ClearSubBgPlanes();BG_SYS_ClearSubObjPlane();}
 * volatile: 021B9638..021B9648 BLDCNT store and two DISPCNT reads/writes.
 * prototype: 3159C leaves allocation result in r0; original consumes it despite legacy void declaration. Resource calls retain observed u8 argument truncations despite wide owner declarations.
 * retry: FINAL; owner-blocked MATCH, no overlay leaves filed while ARM9 also blocks.
 * lever: BGMode i; i=BG_MODE0; func_0207D518(i); do resource row, increment, while((u32)i<1u). Literal zero and a cast folded the copy even with the enum do-while.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Create 0x021B9E78 thumb ov221
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   CHIHOU_ZUKAN_AWARD_Task 0x021B98FC thumb ov221
 *   CHIHOU_ZUKAN_AWARD_LoadBgAssets 0x021B9900 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_SetupWindows 0x021B9964 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_SetupTiles 0x021B9B84 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_CreateActor 0x021B9C4C thumb ov221
 *   func_02012944 0x02012944 thumb
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
 *   CHIHOU_ZUKAN_AWARD_SetupActorPos 0x021B9CEC thumb ov221
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   tbl_021BA148 0x021BA148 data a4
 *   tbl_021BA2C0 0x021BA2C0 data a4
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id;u8 cfg[32];u32 type,enable;} Row;
extern const Row tbl_021BA148[];
typedef struct {u32 a,b,c;} Assets;
extern Assets tbl_021BA2C0[];
struct BgTemplate;
struct Obj;
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void*,int,u32);
extern void *CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(u32,u32);
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void*);
extern void BG_SYS_SetVisibleLayer(int,u16);
extern void *func_020056A0(u32,void*,u32);
extern void CHIHOU_ZUKAN_AWARD_Task(void);
extern void CHIHOU_ZUKAN_AWARD_LoadBgAssets(u8*);
extern void CHIHOU_ZUKAN_AWARD_SetupWindows(struct Obj *p);
extern void CHIHOU_ZUKAN_AWARD_SetupTiles(char*);
extern void CHIHOU_ZUKAN_AWARD_CreateActor(u8*);
extern char *func_02012944(void*);
typedef enum { BG_MODE0=0, BG_MODE1=1 } BGMode;
extern void BG_SYS_ClearSubPlanes(void),BG_SYS_ClearSubBgPlanes(void),func_0207D518(BGMode);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void*,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void*,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void*);
extern void CHIHOU_ZUKAN_AWARD_SetupActorPos(char *p);
extern void FADE_Start(u32,int,int,int),BG_SYS_PushTile(u32),GFL_NET_RestartWithDefaultTimeout(u32,u32),GFL_USE_FadeOutBgm(u32);
int CHIHOU_ZUKAN_AWARD_Init(void *owner,void *unused,void *input)
{
 char *p,*settings;
 BGMode i;
 int selected,zero;
 const Row *row;
 u32 id;
 u16 heap;
 void *h;
 GFL_HEAP_CreateChildHeap((u32)((void*)1),131,0x30000);
 p=PROCSYS_AllocProcWork(owner,88,131);
 i=BG_MODE0;
 MI_CpuFill8(p,i,88);
 *(u16*)p=131;
 *(void**)(p+4)=input;
 *(void**)(p+8)=CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(1,*(u16*)p);
 *(void**)(p+12)=GF_FONT_Create(23,0,0,0,*(u16*)p);
 *(u32*)(p+16)=PRINTSYS_QUE_Create((void*)*(u16*)p);
 BG_SYS_SetVisibleLayer(1,1);BG_SYS_SetVisibleLayer(2,0);
 *(void**)(p+20)=func_020056A0((u32)CHIHOU_ZUKAN_AWARD_Task,p,1);
 CHIHOU_ZUKAN_AWARD_LoadBgAssets((u8*)p);CHIHOU_ZUKAN_AWARD_SetupWindows((struct Obj *)p);CHIHOU_ZUKAN_AWARD_SetupTiles(p);CHIHOU_ZUKAN_AWARD_CreateActor((u8*)p);
 settings=func_02012944(*(void**)(*(char**)(p+4)));
 *(volatile u16*)0x04001050=i;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 *(volatile u32*)0x04001000 |= 0x10000;
 BG_SYS_ClearSubPlanes();func_0207D518(i);BG_SYS_ClearSubBgPlanes();
 do {
  row=&tbl_021BA148[i];id=row->id;
  BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)row->cfg,(u8)row->type);BG_SYS_FreeSlot(id);func_02040588(id,row->enable);
  i++;
 } while((u32)i<1u);
 BG_SYS_SetSubPlaneVisible(16,1);
 heap=*(u16*)p;
 selected=1;if(*(u8*)(settings+29)!=1) selected=0;
 h=func_020490F4(30,heap);
 zero=0;
 func_02049B68(h,tbl_021BA2C0[selected].a,4,zero,zero,heap);
 func_02049658(h,tbl_021BA2C0[selected].b,4,zero,zero,zero,heap);
 func_020498F4(h,tbl_021BA2C0[selected].c,4,zero,zero,zero,heap);
 ARC_TOOL_DeleteHandle(h);BG_SYS_PushTile(4);CHIHOU_ZUKAN_AWARD_SetupActorPos((char *)p);
 FADE_Start(3,16,16,0);GFL_NET_RestartWithDefaultTimeout(0,*(u16*)p);
 if(*(int*)(*(char**)(p+4)+4)==0) GFL_USE_FadeOutBgm(6);
 return 1;
}
