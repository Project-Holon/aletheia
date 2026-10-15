/*
 * function: TH_AWARD_Init
 * address: 0x021B95A0
 * packet: pkt_ov220_021B95A0
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02043588 has no resolved witness; the integrator unit src/matched/arm9/unit_02043570.c contains its body but omits BG_SYS_ClearSubPlanes from its function value. No ARM9 source/shard filed. Standalone scratch one fixed flags ARM EXACT (16 bytes, 2/2): extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void); void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes();BG_SYS_ClearSubObjPlane(); }
 * checks: 1 owner files/readers retained; 2 ov220 neighbours read, no resource twin; 3 u16 variant unchanged47; nonconst resources47->MATCH; 4 enum/hardware/const-record/table-field idioms read; 5 directory/neighbours reread. TU --suggest-split MATCH, no viable piece, sole ARM9 blocker retained.
 * lever: enum counter with unsigned do-while retains the original single-iteration BG loop; nonconst Resources extern keeps outgoing stack stores before the three resource loads (const gave47 concrete bytes).
 * volatile: 021B965C BLDCNT write; 021B9660/966A hardware DISPCNT reads.
 * prototype: 0203159C's allocator return remains live in r0 and is used as the new buffer despite its void owner declaration; 020414AC asm passes r0 twice, original caller truncates layer/type IDs to u8.
 * symbols:
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * TH_AWARD_GRAPHIC_Create 0x021BA0D8 thumb ov220
 * GF_FONT_Create 0x0201D7EC thumb
 * PRINTSYS_QUE_Create 0x0201C440 thumb
 * BG_SYS_SetVisibleLayer 0x0204047C arm
 * func_020056A0 0x020056A0 thumb
 * TH_AWARD_TaskNoop 0x021B995C thumb ov220
 * TH_AWARD_GetLevelIndex 0x021BA068 thumb ov220
 * TH_AWARD_LoadBgAssets 0x021B9960 thumb ov220
 * TH_AWARD_CreateSpeciesActors 0x021B99DC thumb ov220
 * TH_AWARD_CreateBgActors 0x021B9B64 thumb ov220
 * TH_AWARD_SetupWindows 0x021B9CBC thumb ov220
 * BG_SYS_ClearSubPlanes 0x02043588 arm
 * func_0207D518 0x0207D518 arm
 * BG_SYS_ClearSubBgPlanes 0x02043558 arm
 * BG_SYS_InitBgLayer 0x0203FCA0 arm
 * BG_SYS_FreeSlot 0x020414AC arm
 * func_02040588 0x02040588 arm
 * BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * func_020490F4 0x020490F4 arm
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * func_020409B4 0x020409B4 arm
 * FADE_Start 0x0204E720 arm
 * GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * GFL_USE_FadeOutBgm 0x02005E30 thumb
 * bgtable 0x021BA370 data a4
 * resources 0x021BA4E0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { LOOP_ZERO=0 } Loop;
struct BgTemplate;
struct Row {u32 id;u8 body[32];u32 kind,on;};
struct Resources {u32 a,b,c;};
extern const struct Row bgtable[];
extern struct Resources resources[];
struct GfFont;
struct Obj;
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void*,u32,u32);
extern void * TH_AWARD_GRAPHIC_Create(u32,u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void*);
extern void BG_SYS_SetVisibleLayer(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void TH_AWARD_TaskNoop(void);
extern u8 TH_AWARD_GetLevelIndex(u32);
extern void TH_AWARD_LoadBgAssets(u16*);
extern void TH_AWARD_CreateSpeciesActors(char*);
extern void TH_AWARD_CreateBgActors(char*);
extern void TH_AWARD_SetupWindows(struct Obj *p);
extern void BG_SYS_ClearSubPlanes(void),BG_SYS_ClearSubBgPlanes(void),func_0207D518(int);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32),func_020409B4(u32),GFL_NET_RestartWithDefaultTimeout(u32,u32),GFL_USE_FadeOutBgm(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void*,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void*,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void*);
extern void FADE_Start(u32,int,int,int);
int TH_AWARD_Init(void *host,void *unused,void *args)
{
    char *p;
    char *desc;
    Loop i;
    u16 variant;
    void *owner;
    u16 heap;
    GFL_HEAP_CreateChildHeap((u32)((void *)1),131,0x50000);
    p=PROCSYS_AllocProcWork(host,0xB4,131);
    MI_CpuFill8(p,0,0xB4);
    *(u16 *)p=131;
    *(void **)(p+4)=args;
    *(void **)(p+8)=TH_AWARD_GRAPHIC_Create(1,*(u16 *)p);
    *(void **)(p+0xC)=GF_FONT_Create(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+0x10)=PRINTSYS_QUE_Create((void *)(u32)*(u16 *)p);
    BG_SYS_SetVisibleLayer(1,2);BG_SYS_SetVisibleLayer(2,1);BG_SYS_SetVisibleLayer(3,0);
    *(void **)(p+0x14)=func_020056A0((u32)TH_AWARD_TaskNoop,(u32)p,1);
    if (*(u32 *)(*(char **)(p+4)+8)) desc=*(char **)(*(char **)(p+4)+4)+0x14;
    else desc=*(char **)(*(char **)(p+4)+4);
    if (!*(u8 *)desc) *(u32 *)(p+0xB0)=7;
    else *(u32 *)(p+0xB0)=TH_AWARD_GetLevelIndex(*(u16 *)(desc+2));
    TH_AWARD_LoadBgAssets((u16*)p);TH_AWARD_CreateSpeciesActors(p);TH_AWARD_CreateBgActors(p);TH_AWARD_SetupWindows((struct Obj *)p);
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 |= 0x10000;
    BG_SYS_ClearSubPlanes();func_0207D518(0);BG_SYS_ClearSubBgPlanes();
    i=0;
    do {
        const struct Row *r=(const struct Row *)((u32)bgtable+i*44);
        u32 layer=r->id;
        BG_SYS_InitBgLayer((u8)layer,(const struct BgTemplate*)r->body,(u8)r->kind);
        BG_SYS_FreeSlot(layer);func_02040588(layer,r->on);
    } while ((u32)++i<1);
    BG_SYS_SetSubPlaneVisible(16,1);
    heap=*(u16 *)p;
    variant=1;
    if (*(u8 *)*(char **)(p+4)!=1) variant=0;
    owner=func_020490F4(30,heap);
    func_02049B68(owner,resources[variant].a,4,0,0,heap);
    func_02049658(owner,resources[variant].b,4,0,0,0,heap);
    func_020498F4(owner,resources[variant].c,4,0,0,0,heap);
    ARC_TOOL_DeleteHandle(owner);func_020409B4(4);FADE_Start(3,16,16,0);GFL_NET_RestartWithDefaultTimeout(0,*(u16 *)p);
    if (*(u32 *)(*(char **)(p+4)+0xC) && *(u32 *)(p+0xB0)!=7) GFL_USE_FadeOutBgm(6);
    return 1;
}
