/*
 * file:     gsync_disp.c
 * unit:     yes
 * function: GSYNC_DISP_GetPokeIconActor, GSYNC_DISP_Init, GSYNC_DISP_Draw, GSYNC_DISP_Exit, GSYNC_DISP_InitBgLayers, GSYNC_DISP_VBlankTask, GSYNC_DISP_LoadResources, GSYNC_DISP_CreateEffectActorDefault, GSYNC_DISP_CreateSlotActor, GSYNC_DISP_SetSlotAnimSeq, GSYNC_DISP_SetSlotAnimCommand, GSYNC_DISP_DeleteSlotActor, GSYNC_DISP_CreateEffectActorAt, GSYNC_DISP_CreateSlotActorAt, GSYNC_DISP_SetMainActorAnimSeq, GSYNC_DISP_DeleteMainActor, GSYNC_DISP_LoadEffectResources, GSYNC_DISP_CreateMonIconActor, GSYNC_DISP_EnableActorAutoAnim, GSYNC_DISP_RestartActorAnim, GSYNC_DISP_PaletteWaveTask, GSYNC_DISP_StartPaletteWave, GSYNC_DISP_SetFadeDirection, GSYNC_DISP_UpdateBlendFade, GSYNC_DISP_UpdateProgressPosition, GSYNC_DISP_SpawnParticleLeft, GSYNC_DISP_HideParticle, GSYNC_DISP_SpawnParticleRight, GSYNC_DISP_UpdateParticle, GSYNC_DISP_UpdateParticles, GSYNC_DISP_SetIconRecord, GSYNC_DISP_SetIconRecordSpecies, GSYNC_DISP_LoadIconResources, GSYNC_DISP_CopyIconPaletteMain, GSYNC_DISP_CopyIconPaletteSub, GSYNC_DISP_CreatePokeIconActor, GSYNC_DISP_CreateBackdropActors
 * address:  0x021D5D8C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_state.c by tools/splitfile.py.
 *
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0204BA00 0x0204BA00 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E468 0x0207E468 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_0204363C 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   ov067_id 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   d_021DAB68 0x021DAB68 data a1
 *   d_021DAA9C 0x021DAA9C data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DAA78 0x021DAA78 data a4
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   d_021DA758 0x021DA758 data a4
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DAACC 0x021DAACC data a4
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   d_021DA738 0x021DA738 data a4
 *   d_021DA748 0x021DA748 data a4
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   d_021DAA88 0x021DAA88 data a2
 *   func_02005624 0x02005624 thumb
 *   PMSI_PARAM_MakeSineTable 0x02024230 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   d_021DA730 0x021DA730 data a2
 *   d_021DA750 0x021DA750 data a4
 *   d_021DA734 0x021DA734 data a2
 *   d_021DA740 0x021DA740 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_GetActorScale 0x0204B5C0 arm
 *   func_020056EC 0x020056EC thumb
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02019D30 0x02019D30 thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   func_020056A0 0x020056A0 thumb
 */
#include "gsync_types.h"
#include "gsync_common_types.h"
#include "gsync_disp_shared_types.h"

struct Vec2;

struct PtS;

struct ArcFile;

struct NitroFileHeader;

struct Struct36;


struct Point_021D5BD4 { s16 x, y; u16 f4; u8 f6, f7; };

typedef signed short s16_021D634C;

struct Point_021D634C { s16_021D634C x,y; u16 f4; u8 f6,f7; };

struct Entry { int x,y,n; };

struct Pair_021D634C { int a,b; };

struct Pos_021D634C { short x,y; };

typedef short s16_021D6830;

struct Pos_021D6830 { s16_021D6830 x,y; };

struct Pair_021D6830 { int x,y; };

typedef signed short s16_021D6A70;

typedef struct { u32 x[9]; } Desc;

typedef signed short s16_021D6CD8;

struct Point_021D6830 { s16_021D6CD8 x,y; u16 f4; u8 f6,f7; };

struct Point { s16_021D634C x,y; u16 f4; u8 f6,f7; };

extern void func_0203FCA0(u32, const struct BgTemplate *, u32);

extern void func_020409B4(u32);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void func_02040C14(u32, u32, u32, u32);

extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *, u32, u32, u32, u32, u16);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(const void *, void *, u32);

extern u32 func_020307B0(void *p);

extern u32 func_02049740(void *, u32, u32, u32, u32, u16);

extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern void ARC_TOOL_DeleteHandle(void *);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void func_02040DA8(u32 idx, u32 count, u32 tile);

extern void func_020403F4(u32 i);

extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void func_0207E468(void *, int, int);

extern void CLACT_VBlankSystem(void);

extern void func_0204363C(u32 swap);

extern void GX_DispOn(void);

extern void func_0203F8F4(u16 heapId);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void func_0203FC28(struct DispConfig *cfg);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *func_020056A0(void *,void *,int);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void func_0207D63C(void *,int,int,int,int);

extern void CLACT_DrawSystem(void);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void func_02030EAC(struct Node *n);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void func_0203F9B4(void);

extern int func_02034AC4(int);

extern void func_02034A5C(int);

extern void GX_LoadBGPltt(const void *, int, int);

extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

extern int func_0201BC3C(void);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern u32 POKE_TOOL_GetGraphicIndex(void *mon);

extern int POKE_TOOL_GetIconPalette(void *a0);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void *func_02005624(u32 a, u32 b, u32 c);

extern void PMSI_PARAM_MakeSineTable(s16_021D634C *out, u32 count, u16 step, s32 amp);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);

extern void CLACT_SetActorScale(struct Obj *dst, struct Pair_021D634C *src);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern void CLACT_GetActorScale(const struct Obj *o, struct Pair_021D6830 *p);

extern u32 func_020056EC(u32 range);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);

extern u32 func_02020E60(u16, int);

extern s32 func_02062A98(struct NitroFileHeader *file, void **out);

extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);

extern u32 func_02019D30(u32 a, u32 n);

extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);

extern void GX_LoadOBJPltt(void *,int,int);

void *GSYNC_DISP_GetPokeIconActor(GsyncStateObj2 *p);

u8 *GSYNC_DISP_Init(u32 heap);

void GSYNC_DISP_Draw(GsyncStateObj2 *p);

void GSYNC_DISP_Exit(GsyncStateObj2 *p);

void GSYNC_DISP_InitBgLayers(GsyncStateObj2 *p);

void GSYNC_DISP_VBlankTask(void *a, u8 *p);

void GSYNC_DISP_LoadResources(GsyncStateObj2 *p);

void GSYNC_DISP_CreateEffectActorDefault(GsyncStateObj15 *p);

void GSYNC_DISP_CreateSlotActor(GsyncStateObj17 *p,unsigned int i);

void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v);

void GSYNC_DISP_SetSlotAnimCommand(u8 *p, int i, int v);

void GSYNC_DISP_DeleteSlotActor(u8 *p, int i);

void GSYNC_DISP_CreateEffectActorAt(GsyncStateObj15 *p, int x, int y);

void GSYNC_DISP_CreateSlotActorAt(GsyncStateObj17 *p, unsigned int i);

void GSYNC_DISP_SetMainActorAnimSeq(GsyncStateObj2 *p);

void GSYNC_DISP_DeleteMainActor(GsyncStateObj2 *p);

void GSYNC_DISP_LoadEffectResources(GsyncStateObj2 *p);

void GSYNC_DISP_CreateMonIconActor(struct GsyncObj171 *p, void *n, int i);

void GSYNC_DISP_EnableActorAutoAnim(GsyncStateObj2 *p);

void GSYNC_DISP_RestartActorAnim(GsyncStateObj2 *p);

void GSYNC_DISP_PaletteWaveTask(void *unused, u8 *p);

void GSYNC_DISP_StartPaletteWave(GsyncStateObj2 *p);

void GSYNC_DISP_SetFadeDirection(GsyncStateObj1 *p,int flag);

void GSYNC_DISP_UpdateBlendFade(GsyncStateObj1 *p);

void GSYNC_DISP_UpdateProgressPosition(GsyncStateObj2 *p, int n);

void GSYNC_DISP_SpawnParticleLeft(GsyncStateObj2 *p, int i);

void GSYNC_DISP_HideParticle(GsyncStateObj3 *p);

void GSYNC_DISP_SpawnParticleRight(GsyncStateObj2 *p, int i);

void GSYNC_DISP_UpdateParticle(struct Record *p);

void GSYNC_DISP_UpdateParticles(struct Obj *p);

void GSYNC_DISP_SetIconRecord(u8 *p,int i,int a,int b,int c);

void GSYNC_DISP_SetIconRecordSpecies(char *p, int i, u16 v);

void GSYNC_DISP_LoadIconResources(GsyncStateObj2 *p);

void GSYNC_DISP_CopyIconPaletteMain(GsyncStateObj2 *p,int i,void *h);

void GSYNC_DISP_CopyIconPaletteSub(GsyncStateObj2 *p,int i,void *h);

void GSYNC_DISP_CreatePokeIconActor(GsyncStateObj2 *p);

void GSYNC_DISP_CreateBackdropActors(GsyncStateObj2 *p);

extern const char d_021DAB68[];

extern char ov067_id[];

extern const u32 d_021DAA9C[];

extern const u32 d_020A1464[];

extern const u32 d_021DAA78[];

extern unsigned char ov_id[];

extern const struct BgTemplate d_021DA758[7];

extern struct Entry d_021DAACC[];

extern const struct Pair_021D634C d_021DA738;

extern const struct Pair_021D634C d_021DA748;

extern const u16 d_021DAA88[10];

extern const struct Pos_021D634C d_021DA730;

extern const struct Pair_021D634C d_021DA750;

extern const struct Pos_021D634C d_021DA734;

extern const struct Pair_021D634C d_021DA740;

extern const s16_021D6830 FX_SinCosTable_[][2];

void *GSYNC_DISP_GetPokeIconActor(GsyncStateObj2 *p){return p->fAC;}

/*
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 */
u8 *GSYNC_DISP_Init(u32 heap)
{
    GsyncStateObj2 *p;
    p=(GsyncStateObj2 *) func_02030734(heap,0x4568,1,d_021DAB68,0xfe);
    p->f43C4=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0); func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    func_0203F8F4(p->f43C4);
    CLACT_InitSystem((const struct Cfg *)d_020A1464,(u32)d_021DAA9C,p->f43C4);
    p->fC=CLACT_CreateUnit(40,0,p->f43C4);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DAA9C); func_0203FC28((struct DispConfig *)d_021DAA78);
    GSYNC_DISP_InitBgLayers(p); GSYNC_DISP_LoadResources(p); GSYNC_DISP_CreatePokeIconActor(p); GSYNC_DISP_CreateBackdropActors(p);
    p->f10=func_020056A0(GSYNC_DISP_VBlankTask,p,0);
    p->f455C=200;
    BG_SYS_SetSubVisiblePlanes(31); BG_SYS_SetMainVisiblePlanes(27);
    return (u8 *)p;
}

void GSYNC_DISP_Draw(GsyncStateObj2 *p){(p->f43C6)++;if(p->f43C6>=192)p->f43C6=0;CLACT_DrawSystem();GSYNC_DISP_UpdateBlendFade((GsyncStateObj1 *)(void *)p);GSYNC_DISP_UpdateParticles((struct Obj *)p);}

void GSYNC_DISP_Exit(GsyncStateObj2 *p)
{
    Counter i;
    GSYNC_DISP_DeleteMainActor(p);
    func_020307B0(p->f1C);
    CLACT_DeleteActor(p->fB4);
    CLACT_DeleteActor(p->fB8);
    i=0;
    do { if(*(void **)((u8 *)p+i*4+0x20)) CLACT_ReleasePalette((u32)(*(void **)((u8 *)p+i*4+0x20))); i++; } while(i<6);
    for(;i<13;i++) if(*(void **)((u8 *)p+i*4+0x20)) CLACT_ReleaseCharacter((u32)(*(void **)((u8 *)p+i*4+0x20)));
    for(;i<20;i++) if(*(void **)((u8 *)p+i*4+0x20)) CLACT_ReleaseCellAnim((u32)(*(void **)((u8 *)p+i*4+0x20)));
    if(p->f14) func_02030EAC(p->f14);
    func_02030EAC(p->f10);
    CLACT_DeleteUnit(p->fC);
    CLACT_ExitSystem();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); func_0203F9B4(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}

void GSYNC_DISP_InitBgLayers(GsyncStateObj2 *p)
{
    struct BgTemplate b[7];
    b[6]=d_021DA758[0]; func_0203FCA0(0, &b[6], 0); func_02040588(0,1); func_020409B4(0);
    b[5]=d_021DA758[1]; func_0203FCA0(1, &b[5], 0); func_02040588(1,1); func_020409B4(1);
    b[4]=d_021DA758[2]; func_0203FCA0(3, &b[4], 0); func_02040588(3,1); func_020409B4(3);
    b[3]=d_021DA758[3]; func_0203FCA0(4, &b[3], 0); func_02040588(4,1); func_020409B4(4);
    b[2]=d_021DA758[4]; func_0203FCA0(5, &b[2], 0);
    func_02040C14(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=d_021DA758[5]; func_0203FCA0(6, &b[1], 0); func_02040588(6,1);
    func_02040C14(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=d_021DA758[6]; func_0203FCA0(7, &b[0], 0); func_02040588(7,1); func_020409B4(7);
}

void GSYNC_DISP_VBlankTask(void *a, u8 *p)
{
    int n;
    u8 *base;
    int off;
    CLACT_VBlankSystem();
    n = ((GsyncStateObj3 *)p)->f4564 + 1;
    ((GsyncStateObj3 *)p)->f4564 = n;
    if (n % 10 == 1) {
        base = *(u8 * *)&((struct GsyncObj172 *)(((GsyncStateObj3 *)p)->f18))->fC;
        off = (n / 10 + 2) * 32;
        GX_LoadBGPltt(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (((GsyncStateObj3 *)p)->f4564 >= 80) ((GsyncStateObj3 *)p)->f4564 = 0;
}

void GSYNC_DISP_LoadResources(GsyncStateObj2 *p)
{
    void *h;
    h=func_020490F4((u32)((void *)143),p->f43C4);
    func_02049B68(h,2,4,0,0,p->f43C4);
    p->f0=func_02049740(h,8,4,0,0,p->f43C4);
    func_02049990(h,21,4,0,(u16)(p->f0),0,0,p->f43C4);
    func_02049990(h,24,7,0,(u16)(p->f4),0,0,p->f43C4);
    p->f1C=func_02049F78(h,2,(u32)((void **)((u8 *)p+0x18)),p->f43C4);
    func_02049B68(h,2,0,0,0,p->f43C4);
    p->f4=func_02049740(h,8,0,0,0,p->f43C4);
    func_02049990(h,23,0,0,(u16)(p->f4),0,0,p->f43C4);
    func_02049990(h,24,1,0,(u16)(p->f4),0,0,p->f43C4);
    p->f38=(void *)CLACT_RegisterCharacter(h,9,0,2,p->f43C4);
    p->f20=(void *)CLACT_RegisterPaletteEx(h,3,2,96,0,4,p->f43C4);
    p->f54=(void *)CLACT_RegisterCellAnim(h,12,25,p->f43C4);
    p->f3C=(void *)CLACT_RegisterCharacter(h,10,0,2,p->f43C4);
    p->f24=(void *)CLACT_RegisterPaletteEx(h,4,2,224,0,0,p->f43C4);
    p->f58=(void *)CLACT_RegisterCellAnim(h,13,26,p->f43C4);
    GSYNC_DISP_LoadEffectResources(p); ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_CreateEffectActorDefault(GsyncStateObj15 *p){GSYNC_DISP_CreateEffectActorAt(p,133,128);}

void GSYNC_DISP_CreateSlotActor(GsyncStateObj17 *p,unsigned int i){GSYNC_DISP_CreateSlotActorAt(p,i);}

void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v)
{
    CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x74), (u16)v);
}

void GSYNC_DISP_SetSlotAnimCommand(u8 *p, int i, int v)
{
    func_0204BA00(*(void **)(p + i * 4 + 0x74), (const struct Cmd *)v);
}

void GSYNC_DISP_DeleteSlotActor(u8 *p, int i)
{
    if (*(u32 *)(p + 0x74 + i * 4)) {
        CLACT_DeleteActor(*(void **)(p + 0x74 + i * 4));
        *(u32 *)(p + 0x74 + i * 4) = 0;
    }
}

void GSYNC_DISP_CreateEffectActorAt(GsyncStateObj15 *p, int x, int y)
{
    struct Point_021D5BD4 pt;
    if (p->fAC == 0) {
        pt.x = x; pt.y = y; pt.f4 = 0; pt.f6 = 0; pt.f7 = 1;
        p->fAC = CLACT_CreateActor((void *)p->fC, (u32)p->f3C, p->f24, p->f58, &pt, 1, p->f43C4);
        CLACT_SetActorAutoAnim(p->fAC, 1);
        CLACT_SetActorDrawEnable(p->fAC, 1);
    }
}

/*
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 */
void GSYNC_DISP_CreateSlotActorAt(GsyncStateObj17 *p, unsigned int i)
{
    struct Point_021D634C pt;
    if (*(void **)((u8 *)p + i*4 + 0x74)) CLACT_DeleteActor(*(void **)((u8 *)p+i*4+0x74));
    pt.x = d_021DAACC[i].x; pt.y = d_021DAACC[i].y;
    pt.f4 = i; pt.f6 = d_021DAACC[i].n; pt.f7 = 1;
    ((void **)((u8 *)p + 0x74))[i] = CLACT_CreateActor((void *)p->fC, (u32)p->f38, p->f20, p->f54, &pt, 0, p->f43C4);
    CLACT_SetActorAnimFrame(((void **)((u8 *)p+0x74))[i],0);
    CLACT_SetActorAutoAnim(((void **)((u8 *)p+0x74))[i],1);
    CLACT_SetActorDrawEnable(((void **)((u8 *)p+0x74))[i],1);
    CLACT_SetActorAffineMode(((void **)((u8 *)p+0x74))[i],2);
}

void GSYNC_DISP_SetMainActorAnimSeq(GsyncStateObj2 *p)
{
    CLACT_SetActorAnimSeq(p->fA8, 2);
}

void GSYNC_DISP_DeleteMainActor(GsyncStateObj2 *p){int i;for(i=0;i<16;i++){u8 *q=(u8 *)p+i*4;if(((GsyncStateObj18 *)q)->f74){CLACT_DeleteActor(((GsyncStateObj18 *)q)->f74);((GsyncStateObj18 *)q)->f74=0;}}}

void GSYNC_DISP_LoadEffectResources(GsyncStateObj2 *p)
{
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f28 = (void *)CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 2, 0, p->f43C4);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(143, p->f43C4);
    p->f5C = (void *)CLACT_RegisterCellAnim(h, 14, 27, p->f43C4);
    ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_CreateMonIconActor(struct GsyncObj171 *p, void *n, int i)
{
    struct Pair_021D634C a = d_021DA738;
    struct Pair_021D634C b = d_021DA748;
    struct Point_021D634C pt;
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f40 = (void *)CLACT_RegisterCharacter(h,POKE_TOOL_GetGraphicIndex((void *)n),0,2,p->f43C4);
    if(i==0) { pt.x=a.b; pt.y=b.b; }
    else { pt.x=a.a; pt.y=b.a; }
    pt.f4=0; pt.f6=3; pt.f7=1;
    p->fA8 = CLACT_CreateActor((void *)p->fC,(unsigned int)p->f40,p->f28,p->f5C,&pt,(u16)i,p->f43C4);
    CLACT_SetActorAutoAnim(p->fA8,0);
    CLACT_SetActorDrawEnable(p->fA8,1);
    CLACT_SetActorPaletteOffset(p->fA8,POKE_TOOL_GetIconPalette(n),1);
    ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_EnableActorAutoAnim(GsyncStateObj2 *p)
{
    CLACT_SetActorAutoAnim(p->fA8, 1);
}

void GSYNC_DISP_RestartActorAnim(GsyncStateObj2 *p)
{
    CLACT_SetActorAnimSeq(p->fA8, 1);
    CLACT_SetActorAutoAnim(p->fA8, 1);
}

void GSYNC_DISP_PaletteWaveTask(void *unused, u8 *p)
{
    int line;
    int idx;
    int d;
    int v;
    idx = *(s16_021D634C *)(p + 0x43C6) + 1;
    line = *(volatile u16 *)0x04000006;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x0400001C = *(s16_021D634C *)(p + 0x43C8 + idx * 2) & 0x1FF;
        v = *(int *)(p + 0x455C);
        if (v >= 0xC0) {
            GX_LoadBGPltt(d_021DAA88, 0x142, 2);
            return;
        }
        if (v == 0) {
            GX_LoadBGPltt(&d_021DAA88[9], 0x142, 2);
            return;
        }
        if (line > 200) {
            GX_LoadBGPltt(d_021DAA88, 0x142, 2);
            return;
        }
        if (v > line) {
            GX_LoadBGPltt(d_021DAA88, 0x142, 2);
            return;
        }
        d = line - v;
        if ((u32)d < 10 && d >= 0) {
            GX_LoadBGPltt(&d_021DAA88[d], 0x142, 2);
            return;
        }
        GX_LoadBGPltt(&d_021DAA88[9], 0x142, 2);
    }
}

void GSYNC_DISP_StartPaletteWave(GsyncStateObj2 *p)
{
    void *h;
    h = func_020490F4(143, p->f43C4);
    func_02049990(h, 22, 3, 0, (u16)p->f4, 0, 0, p->f43C4);
    ARC_TOOL_DeleteHandle(h);
    p->f14 = func_02005624((u32)GSYNC_DISP_PaletteWaveTask, (u32)p, 0);
    PMSI_PARAM_MakeSineTable((s16_021D634C *)((u8 *)p + 0x43c8), 192, 0x5b0, 0x1800);
}

void GSYNC_DISP_SetFadeDirection(GsyncStateObj1 *p,int flag){if(flag){p->f4554=0;p->f4558=1;}else{p->f4554=65536;p->f4558=-1;}}

void GSYNC_DISP_UpdateBlendFade(GsyncStateObj1 *p)
{
    int v;
    if (p->f4558 != 0) {
        p->f4554 += p->f4558 << 10;
        v = p->f4554 >> 12;
        func_02040588(3, 1);
        if (v > 10) { p->f4558 = 0; return; }
        if (v < 0) { v = 0; func_02040588(3, 0); p->f4558 = v; return; }
        func_0207D63C((void *)0x04000050, 8, 55, v, 8);
    }
}

void GSYNC_DISP_UpdateProgressPosition(GsyncStateObj2 *p, int n)
{
    float x = (float)(1.2 * (double)(float)n);
    int v;
    if (n > 100) v = 0;
    else v = (int)(120.0f - x);
    if (p->f455C > v) p->f455C = v;
}

void GSYNC_DISP_SpawnParticleLeft(GsyncStateObj2 *p, int i)
{
    struct Pos_021D634C pos;
    struct Pair_021D634C pair;
    void *h;
    GSYNC_DISP_CopyIconPaletteMain(p,i,p->fB4);
    h = p->fB4;
    pos = d_021DA730; pair = d_021DA750;
    CLACT_AddActorSurfacePos(h,(const struct Vec2 *)(&pos),0); CLACT_SetActorScale(h, (struct Pair_021D634C *)&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    *(void **)((u8 *)p+i*24+0x40f4) = h;
}

void GSYNC_DISP_HideParticle(GsyncStateObj3 *p){if(p->f0)CLACT_SetActorDrawEnable(p->f0,0);p->f0=0;}

void GSYNC_DISP_SpawnParticleRight(GsyncStateObj2 *p, int i)
{
    struct Pos_021D634C pos;
    struct Pair_021D634C pair;
    void *h;
    GSYNC_DISP_CopyIconPaletteSub(p,i,p->fB8);
    h = p->fB8;
    pos = d_021DA734; pair = d_021DA740;
    CLACT_AddActorSurfacePos(h,(const struct Vec2 *)(&pos),0); CLACT_SetActorScale(h, (struct Pair_021D634C *)&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    *(void **)((u8 *)p+i*24+0x40f4) = h;
}

/*
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 */
void GSYNC_DISP_UpdateParticle(struct Record *p)
{
    struct Pos_021D6830 pos;
    struct Pair_021D6830 scale;
    int a,b;
    if (p == 0) return;
    a = (s16_021D6830)(FX_SinCosTable_[p->a >> 4][0] * 4) >> 12;
    b = (s16_021D6830)(FX_SinCosTable_[p->b >> 4][0] * 3) >> 12;
    if (p->h) {
        CLACT_GetActorSurfacePos(p->h, (struct PtS *)&pos, 0);
        pos.x = p->x + a + b;
        pos.y = (p->y + a + b + p->age) >> 2;
        if (p->age % 8 == 0) {
            if (p->x > 128) p->x = p->x - 1;
            else p->x = p->x + 1;
        }
        CLACT_AddActorSurfacePos(p->h, (const struct Vec2 *)(&pos), 0);
        CLACT_SetActorDrawEnable(p->h, 1);
        p->age++;
        if (pos.y > 25) {
            CLACT_GetActorScale(p->h, (struct Pair_021D6830 *)&scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) GSYNC_DISP_HideParticle((GsyncStateObj3 *)p);
            else CLACT_SetActorScale(p->h, (struct Pair_021D634C *)&scale);
        }
        if (pos.y > 50) GSYNC_DISP_HideParticle((GsyncStateObj3 *)p);
    } else p->g = 1;
    if (p->g == 0) {
        p->a += (u16)(func_020056EC(12) + 200);
        p->b -= (u16)(func_020056EC(12) + 666);
    }
}

/*
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 */
void GSYNC_DISP_UpdateParticles(struct Obj *p)
{
    int active = 0;
    int i,n;
    for (i = 0; i < 20; i++) {
        if (p->records[i].c && !p->records[i].g) {
            GSYNC_DISP_UpdateParticle(&p->records[i]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 20; i++) {
            n = func_020056EC(20);
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                GSYNC_DISP_SpawnParticleRight((GsyncStateObj2 *)p, n);
                break;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        n = i + 20;
        if (p->records[n].c && !p->records[n].g) {
            GSYNC_DISP_UpdateParticle(&p->records[n]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 10; i++) {
            n = func_020056EC(10) + 20;
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                GSYNC_DISP_SpawnParticleLeft((GsyncStateObj2 *)p, n);
                return;
            }
        }
    }
}

void GSYNC_DISP_SetIconRecord(u8 *p,int i,int a,int b,int c){if(a!=0 && a<=493){*(s16_021D6A70 *)(p+(u32)i*24+0x4104)=a;*(s16_021D6A70 *)(p+(u32)i*24+0x4106)=b;if(c>2)c=0;*(s16_021D6A70 *)((u32)p+(u32)i*24+0x4108)=c;}}

void GSYNC_DISP_SetIconRecordSpecies(char *p, int i, u16 v)
{
    *(u16 *)(p + i * 0x18 + 0x4104) = v;
}

/*
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 */
void GSYNC_DISP_LoadIconResources(GsyncStateObj2 *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *out2;
    u8 *out;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, p->f43C4);
    for (i = 0; i < 20; i++) {
        species = ((struct Obj *)p)->records[i].d;
        if (species) {
            buf = ARC_TOOL_LoadHandleMember(h,func_02020E60(species,2),p->f43C4);
            func_02062A98(buf,(void **)(&out));
            MI_CpuCopy8(((GsyncStateObj30 *)out)->fC,(u8 *)p+0xbc+i*0x224,32);
            func_020307B0(buf);
            buf2 = ARC_TOOL_LoadHandleMember(h,func_02020E60(species,1),p->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            MI_CpuCopy8(((GsyncStateObj24 *)out2)->f14,(u8 *)p+0xdc+i*0x224,512);
            func_020307B0(buf2);
        }
    }
    ARC_TOOL_DeleteHandle(h);
    h2 = func_020490F4(7, p->f43C4);
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = ((struct Obj *)p)->records[n].d;
        if (species) {
            gender = ((struct Obj *)p)->records[n].f;
            form = (int)func_02019D30((u16)species,(u8)(((struct Obj *)p)->records[n].e));
            value = POKE_TOOL_CalcIconPalette(species,form,gender,0);
            id = POKE_TOOL_CalcGraphicIndex(species,form,gender,0);
            buf2 = ARC_TOOL_LoadHandleMember(h2,id,p->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            MI_CpuCopy8(((GsyncStateObj24 *)out2)->f14,(u8 *)p+0xdc+n*0x224,512);
            func_020307B0(buf2);
            *(u32 *)((u8 *)p+n*0x224+0x2dc) = value;
        }
    }
    ARC_TOOL_DeleteHandle(h2);
}

void GSYNC_DISP_CopyIconPaletteMain(GsyncStateObj2 *p,int i,void *h)
{
    Desc d;
    CLACT_GetActorImageProxy(h,(struct Struct36 *)(&d));
    MI_CpuCopy8((char *)p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    CLACT_SetActorPaletteOffset(h,(u8)(*(u32 *)((char *)p+i*0x224+0x2dc)),1);
}

void GSYNC_DISP_CopyIconPaletteSub(GsyncStateObj2 *p,int i,void *h)
{
    Desc d;
    CLACT_GetActorImageProxy(h,(struct Struct36 *)(&d));
    MI_CpuCopy8((char *)p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    DWCi_ScreenDC_FlushRange((char *)p+0xbc+i*0x224,0x20);
    GX_LoadOBJPltt((char *)p+0xbc+i*0x224,0x100,0x20);
}

/*
 * lever: narrow the helper result through a named u16 local before the call.
 */
void GSYNC_DISP_CreatePokeIconActor(GsyncStateObj2 *p)
{
    struct Point_021D6830 pt;
    void *h;
    u16 n;
    h=func_020490F4(7,p->f43C4);
    n=POKE_TOOL_CalcGraphicIndex(1,0,0,0);
    p->f44=(void *)CLACT_RegisterCharacter(h,n,0,0,p->f43C4);
    pt.x=133; pt.y=128; pt.f4=0; pt.f6=3; pt.f7=2;
    p->fB4=CLACT_CreateActor((void *)(*(unsigned int *)&p->fC),(u32)p->f44,(*(unsigned int *)&p->f28),(*(unsigned int *)&p->f5C),&pt,0,p->f43C4);
    CLACT_SetActorAutoAnim(p->fB4,0);
    CLACT_SetActorDrawEnable(p->fB4,0);
    ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_CreateBackdropActors(GsyncStateObj2 *p)
{
    struct Point pt;
    void *h;
    h=func_020490F4(25,p->f43C4);
    p->f34=(void *)CLACT_RegisterPaletteEx(h,func_02020E60(1,2),0,256,0,1,p->f43C4);
    p->f50=(void *)CLACT_RegisterCharacter(h,func_02020E60(1,1),0,0,p->f43C4);
    p->f6C=(void *)CLACT_RegisterCellAnim(h,1,0,p->f43C4);
    ARC_TOOL_DeleteHandle(h);
    pt.x=156; pt.y=28; pt.f4=0; pt.f6=0; pt.f7=2;
    p->fB8=CLACT_CreateActor((void *)(*(unsigned int *)&p->fC),(unsigned int)p->f50,*(u32 *)&p->f34,*(u32 *)&p->f6C,&pt,0,p->f43C4);
    CLACT_SetActorAutoAnim(p->fB8,0);
    CLACT_SetActorDrawEnable(p->fB8,0);
}
