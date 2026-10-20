/*
 * file:     shinka_demo_view.c
 * unit:     yes
 * function: SHINKA_DEMO_VIEW_Create, SHINKA_DEMO_VIEW_Destroy, SHINKA_DEMO_VIEW_Main, SHINKA_DEMO_VIEW_Draw, SHINKA_DEMO_VIEW_RequestStart, SHINKA_DEMO_VIEW_IsStartDone, SHINKA_DEMO_VIEW_RequestConfirm, SHINKA_DEMO_VIEW_IsConfirmDone, SHINKA_DEMO_VIEW_RequestEvolve, SHINKA_DEMO_VIEW_RequestFadeOut, SHINKA_DEMO_VIEW_IsEvolveReady, SHINKA_DEMO_VIEW_IsEvolveStarted, SHINKA_DEMO_VIEW_IsEvolveDone, SHINKA_DEMO_VIEW_TrySecondForm, SHINKA_DEMO_VIEW_InitMcss, SHINKA_DEMO_VIEW_ExitMcss, SHINKA_DEMO_VIEW_GetModelOffset, SHINKA_DEMO_VIEW_CreateModels, SHINKA_DEMO_VIEW_DeleteModels, SHINKA_DEMO_VIEW_OtherSlot, SHINKA_DEMO_VIEW_UpdateModelOffsets, SHINKA_DEMO_VIEW_SetModelPosX, SHINKA_DEMO_VIEW_CreateWork, SHINKA_DEMO_VIEW_DeleteWork, SHINKA_DEMO_VIEW_Update, SHINKA_DEMO_VIEW_Draw3d, SHINKA_DEMO_VIEW_BeginIntro, SHINKA_DEMO_VIEW_IsMenuReady, SHINKA_DEMO_VIEW_ShowMenu, SHINKA_DEMO_VIEW_SetModelsPos, SHINKA_DEMO_VIEW_SetModelOffset, SHINKA_DEMO_VIEW_StartFadeOut, SHINKA_DEMO_VIEW_AreModelsState0, SHINKA_DEMO_VIEW_AreModelsState4, SHINKA_DEMO_VIEW_CreateGrid, SHINKA_DEMO_VIEW_DeleteGrid, SHINKA_DEMO_VIEW_InitGrid, SHINKA_DEMO_VIEW_SetupGridCells, SHINKA_DEMO_VIEW_DrawGrid, SHINKA_DEMO_VIEW_DrawGridRotated, SHINKA_DEMO_VIEW_InitGridFromPokemon, SHINKA_DEMO_VIEW_StartGridFade, SHINKA_DEMO_VIEW_IsGridFadeDone, SHINKA_DEMO_VIEW_StepGridFade, SHINKA_DEMO_VIEW_ApplyGridPalette, SHINKA_DEMO_VIEW_IsGridState0, SHINKA_DEMO_VIEW_IsGridState1, SHINKA_DEMO_VIEW_StartGridFadeOut, SHINKA_DEMO_VIEW_IsGridState3, SHINKA_DEMO_VIEW_IsGridState4, SHINKA_DEMO_VIEW_UpdateGridFade, SHINKA_DEMO_VIEW_CreateQuad, SHINKA_DEMO_VIEW_FreeQuad, SHINKA_DEMO_VIEW_UpdateQuadVerts, SHINKA_DEMO_VIEW_DrawQuad, SHINKA_DEMO_VIEW_SetQuadOffset
 * address:  0x02205C74
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from shinka_demo_view.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   d_02208F68 0x02208F68 data
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKE_TOOL_CopyPartyPokemon 0x02019CE0 thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   PM_VOICE_Play 0x02006984 thumb
 *   PM_VOICE_IsAnyActive 0x02006650 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   NNS_G2dRestartMCAnimation 0x02064CBC arm
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_GetSizeY 0x02015F0C thumb
 *   MCSS_GetOfsY 0x02015F1C thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   d_02208E74 0x02208E74 data
 *   d_02208E80 0x02208E80 data
 *   FX_SinCosTable_ 0x020A1B38 data
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   d_02208E8C 0x02208E8C data
 *   d_02148BCC 0x02148BCC data
 *   G3D_SYSTEM_GetProjection 0x020467EC arm
 *   G3D_SYSTEM_GetLookAt 0x02046AFC arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   NNS_G3dGlbBaseTrans 0x0206A9DC arm
 *   MI_Copy36B 0x02082B60 arm
 *   NNS_G3dGlbBaseScale 0x0206AA0C arm
 *   NNS_G3dGeFlushBuffer 0x0206DB80 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   G3D_SYSTEM_SetLookAt 0x02046B40 arm
 *   BMP_Create 0x02043678 arm
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   POKEGRA_GetCgrArcIndex 0x0202D064 thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   BMP_ConvertToLinear 0x02044F64 arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   BMP_Delete 0x020437AC arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   FX_Div 0x0207C768 arm
 *   MTX_RotY43_ 0x0207B640 thumb
 *   MTX_MultVec43 0x0207BC08 arm
 *   FX_InvSqrt 0x0207C7E8 arm
 *   d_02208E4C 0x02208E4C data
 *   d_02208E38 0x02208E38 data
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fgr                         0x0209BBB0  arm
 */
#include "shinka_demo_graphic_shared_types.h"
#include "../sdk_ioreg_reg.h"
#include "shinka_demo_view_shared_types.h"

#define W(n) (*(u32 *)(p+(n)))

#define P(n) (*(void **)(p+(n)))

#define B(n) (*(u8 *)(p+(n)))

#define NODE(i) (*(void **)(p+0x50+(u32)(i)*4))












#define REG_TEXIMAGE_PARAM (*(vu32 *)REG_TEXIMAGE_PARAM_ADDR)

#define REG_TEXPLTT_BASE   (*(vu32 *)REG_TEXPLTT_BASE_ADDR)



#define G(n) (*(u32 *)(p+(n)))

#define Q(n) (*(int *)(q+(n)))

#define H(n) (*(s16 *)(p+(n)))

#define V(n) (*(ShinkaDemoViewVec *)(q+(n)))


struct RecDC;

struct McssFade;

struct Obj;

struct Owner;

struct McssSys;

struct Quad;

struct Fade;

struct Grid;

struct Bmp;

#include "../types.h"

typedef struct ShinkaDemoViewCell {
    u32 life;
    fx32 s0, s1, t0, t1;
    u8 visible;
    u8 pad15;
    fx16 v[4][3];
    u8 pad2e[2];
    s32 reserved30;
    VecFx32 start;
    s32 velX, velY, velZ, angle, radius, height, targetX, targetY, targetZ, progress;
    VecFx32 cur;
    VecFx32 org;
} ShinkaDemoViewCell;

typedef struct Row {
    ShinkaDemoViewCell cell[0x12];
} Row;

typedef struct ShinkaDemoViewCharData {
    u8 pad00[0x14];
    u8 *raw;
} ShinkaDemoViewCharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Grid {
    ShinkaDemoViewCharData *chr;
    PlttData *pltt;
    void *chrRes;
    void *plttRes;
    void *canvas;
    u32 tex;
    u32 plttAddr;
    VecFx32 v;
    s32 state;
    u16 pal[16];
    u16 color;
    s16 fcur;
    s16 fend;
    s16 fwait;
    s16 fstep;
    s16 flevel;
    s16 fcount;
    s16 x0, y0, x1, y1;
    u8 pad62[2];
    s32 f64, f68, f6c, f70;
    Row row[0x12];
    u8 rows;
} Grid;

typedef struct Quad {
    u32 tex;
    u32 pltt;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u32 polyId;
    fx32 s0, s1, t0, t1;
    u8 alpha;
    u8 pad35;
    fx16 v[4][3];
    u8 rowCount;
} Quad;

typedef struct ShinkaDemoViewWork {
    u32 phase;
    void *camera;
    Grid *grid[2];
    Quad *quad;
} ShinkaDemoViewWork;

typedef struct Owner {
    u16 heap;
    u16 pad02;
    void *res0;
    u32 mode;
    u16 evolvedSpecies;
    u16 pad0e;
    void *res1;
    u32 state;
    u32 wait;
    u32 startRequested;
    u32 startDone;
    u32 confirmRequested;
    u32 confirmDone;
    u32 evolveRequested;
    u32 fadeOutRequested;
    u32 evolveReady;
    u32 evolveStarted;
    u32 evolveDone;
    u32 secondForm;
    float scale;
    u8 slot;
    u8 pad49[3];
    void *sys;
    void *obj[2];
    ShinkaDemoViewWork *work;
    u32 useMcss;
} Owner;

typedef struct GlbState {
    u8 pad00[0x3c];
    MtxFx33 baseRot;
    u8 pad60[0x7c - 0x60];
    u32 flag;
} GlbState;

typedef struct SC {s16 s;s16 c;} SC;

typedef struct {fx32 x,y,z;} ShinkaDemoViewVec;

typedef struct {fx32 a[12];} Matrix;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/g3d_camera.h"

struct G3dCamera;


#include "../arm9/g3d_system.h"

#include "../arm9/poke_tool.h"
struct PartyPokemon;

struct PokemonParam;



#include "../arm9/pm_voice.h"

struct McssWork;

#include "../arm9/mcss.h"



struct MultiCellAnim;

#include "../arm9/nns_g2d_multi_cell_animation.h"






















struct G3dProjection;

struct G3dLookAt;


#include "../arm9/fx_mtx33.h"

#include "../arm9/nns_g3d_glb.h"

#include "../arm9/mi_memory.h"


#include "../arm9/nns_g3d_ge.h"



typedef short s16_p07;
#include "../arm9/bmp.h"

#include "../arm9/pokegra.h"



#include "../arm9/arc_util.h"






#include "../arm9/nns_gfd_vram_transfer.h"


#include "../arm9/fx_cp.h"


#include "../arm9/fx_mtx43.h"
union MtxFx43;
struct VecFx32;



Owner *SHINKA_DEMO_VIEW_Create(u16 heap, u32 mode, void *res0, u16 evolvedSpecies);

void SHINKA_DEMO_VIEW_Destroy(char *p);

void SHINKA_DEMO_VIEW_Main(char *p);

void SHINKA_DEMO_VIEW_Draw(Owner *o);

void SHINKA_DEMO_VIEW_RequestStart(int *p);

int SHINKA_DEMO_VIEW_IsStartDone(int *p);

void SHINKA_DEMO_VIEW_RequestConfirm(int *p);

int SHINKA_DEMO_VIEW_IsConfirmDone(int *p);

void SHINKA_DEMO_VIEW_RequestEvolve(int *p);

void SHINKA_DEMO_VIEW_RequestFadeOut(int *p);

int SHINKA_DEMO_VIEW_IsEvolveReady(int *p);

int SHINKA_DEMO_VIEW_IsEvolveStarted(int *p);

int SHINKA_DEMO_VIEW_IsEvolveDone(int *p);

int SHINKA_DEMO_VIEW_TrySecondForm(int *p);

void SHINKA_DEMO_VIEW_InitMcss(char *a);

void SHINKA_DEMO_VIEW_ExitMcss(char *p);

fx32 SHINKA_DEMO_VIEW_GetModelOffset(void *p);

void SHINKA_DEMO_VIEW_CreateModels(Owner *o);

void SHINKA_DEMO_VIEW_DeleteModels(Owner *o);

u8 SHINKA_DEMO_VIEW_OtherSlot(u8 i);

void SHINKA_DEMO_VIEW_UpdateModelOffsets(Owner *o);

void SHINKA_DEMO_VIEW_SetModelPosX(char *a, u32 v);

void SHINKA_DEMO_VIEW_CreateWork(Owner *o);

void SHINKA_DEMO_VIEW_DeleteWork(char *p);

void SHINKA_DEMO_VIEW_Update(Owner *o);

void SHINKA_DEMO_VIEW_Draw3d(Owner *o);

void SHINKA_DEMO_VIEW_BeginIntro(Owner *o);

int SHINKA_DEMO_VIEW_IsMenuReady(int *p);

void SHINKA_DEMO_VIEW_ShowMenu(int *p);

void SHINKA_DEMO_VIEW_SetModelsPos(char *a, u32 x, u32 y, u32 z);

void SHINKA_DEMO_VIEW_SetModelOffset(char *a, int b, int c, int d, int e);

void SHINKA_DEMO_VIEW_StartFadeOut(Owner *o);

int SHINKA_DEMO_VIEW_AreModelsState0(char *a);

int SHINKA_DEMO_VIEW_AreModelsState4(char *a);

Grid *SHINKA_DEMO_VIEW_CreateGrid(u32 monsNo, u32 formNo, u32 sex, u32 isShiny, u32 dir, u32 isEgg, u32 tex, u32 pltt, u16 heap);

void SHINKA_DEMO_VIEW_DeleteGrid(char *p, int unused);

void SHINKA_DEMO_VIEW_InitGrid(Grid *p, u16 heap);

void SHINKA_DEMO_VIEW_SetupGridCells(Grid *p, u16 heap);

void SHINKA_DEMO_VIEW_DrawGrid(Grid *w, u16 heap);

void SHINKA_DEMO_VIEW_DrawGridRotated(Owner *o);

void SHINKA_DEMO_VIEW_InitGridFromPokemon(char *p,u16 heap);

void SHINKA_DEMO_VIEW_StartGridFade(Grid *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step);

int SHINKA_DEMO_VIEW_IsGridFadeDone(Grid *p, int x);

void SHINKA_DEMO_VIEW_StepGridFade(Grid *p, int x);

void SHINKA_DEMO_VIEW_ApplyGridPalette(Grid *p, int x);

int SHINKA_DEMO_VIEW_IsGridState0(char *p, u16 unused);

int SHINKA_DEMO_VIEW_IsGridState1(char *p, u16 heap);

void SHINKA_DEMO_VIEW_StartGridFadeOut(Grid *p, int x);

int SHINKA_DEMO_VIEW_IsGridState3(char *p, u16 heap);

int SHINKA_DEMO_VIEW_IsGridState4(char *p, u16 heap);

void SHINKA_DEMO_VIEW_UpdateGridFade(Grid *p, int x);

Quad *SHINKA_DEMO_VIEW_CreateQuad(u32 tex, u32 pltt, u16 heap);

void SHINKA_DEMO_VIEW_FreeQuad(void *p,int n);

void SHINKA_DEMO_VIEW_UpdateQuadVerts(Quad *p, u16 heap);

void SHINKA_DEMO_VIEW_DrawQuad(Quad *p, u16 heap);

void SHINKA_DEMO_VIEW_SetQuadOffset(char *a, int b, int c, int d, int e);

extern char d_02208F68[];

extern const VecFx32 d_02208E74;

extern const VecFx32 d_02208E80;

extern const s16 FX_SinCosTable_[];

extern const VecFx32 d_02208E8C;

extern GlbState d_02148BCC;

extern const s16 d_02208E4C[];

extern const u8 d_02208E38[];

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

Owner *SHINKA_DEMO_VIEW_Create(u16 heap, u32 mode, void *res0, u16 evolvedSpecies)
{
    Owner *o = GFL_HEAP_Alloc(heap, 0x60, 1, d_02208F68, 0x201);

    o->heap = heap;
    o->mode = mode;
    o->res0 = res0;
    o->evolvedSpecies = evolvedSpecies;
    o->res1 = 0;
    if (mode == 0) {
        o->res1 = GFL_HEAP_Alloc(o->heap, POKE_TOOL_GetPartyParamSize(), 1, d_02208F68, 0x213);
        POKE_TOOL_CopyPartyPokemon(o->res0, o->res1);
        POKE_TOOL_ChangeSpecies(o->res1, o->evolvedSpecies);
    }
    if (o->mode == 0)
        o->state = 0;
    else
        o->state = 0x16;
    o->wait = 0;
    o->startRequested = 0;
    o->startDone = 0;
    o->confirmRequested = 0;
    o->evolveReady = 0;
    o->evolveStarted = 0;
    o->evolveDone = 0;
    o->secondForm = 0;
    o->scale = 16.0f;
    if (o->mode == 0)
        o->slot = 0;
    else
        o->slot = 1;
    SHINKA_DEMO_VIEW_InitMcss((char *)o);
    SHINKA_DEMO_VIEW_CreateModels((Owner *)o);
    SHINKA_DEMO_VIEW_CreateWork((Owner *)o);
    o->useMcss = 1;
    return o;
}

void SHINKA_DEMO_VIEW_Destroy(char *owner){SHINKA_DEMO_VIEW_DeleteWork(owner);SHINKA_DEMO_VIEW_DeleteModels((Owner *)((Owner *)owner));SHINKA_DEMO_VIEW_ExitMcss(owner);if(((Owner *)owner)->res1)GFL_HEAP_Free(((Owner *)owner)->res1);GFL_HEAP_Free(owner);}

void SHINKA_DEMO_VIEW_Main(char *p)
{
    switch(W(0x14)) {
    case 0:
        if(W(0x1c)) {
            u32 a,b;
            W(0x14)=1;
            a=POKE_TOOL_GetPartyValue(P(4),5,0);
            b=POKE_TOOL_GetPartyValue(P(4),0x6f,0);
            PM_VOICE_Play(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 1:
        if(!PM_VOICE_IsAnyActive()){W(0x14)=2;W(0x20)=1;}
        break;
    case 2:if(W(0x24))W(0x14)=3;break;
    case 3:
        W(0x14)=4;
        MCSS_SetPaletteFade((struct McssWork *)NODE(B(0x48)),0,16,0,0x7fff);
        MCSS_SetPaletteFade((struct McssWork *)NODE(SHINKA_DEMO_VIEW_OtherSlot(B(0x48))),16,16,0,0x7fff);
        MCSS_SetAnmStopFlag(NODE(B(0x48)));
        break;
    case 4:if(!MCSS_CheckPaletteFade(NODE(B(0x48))))W(0x14)=5;break;
    case 5:
        if(W(0x18)>=8){W(0x14)=6;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 6:
        W(0x14)=8;
        SHINKA_DEMO_VIEW_SetModelPosX(p,0x100000);
        SHINKA_DEMO_VIEW_SetModelsPos(p,0,0xfffff800,0);
        W(0x5c)=0;
        NNS_G2dRestartMCAnimation((struct MultiCellAnim *)MCSS_GetAnimCtrl(NODE(B(0x48))));
        break;
    case 7:
        if(W(0x18)>=1){W(0x14)=8;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 8:W(0x14)=9;SHINKA_DEMO_VIEW_StartFadeOut((Owner *)((struct Owner *)p));break;
    case 9:
        if(SHINKA_DEMO_VIEW_AreModelsState0(p)){W(0x14)=10;W(0x38)=1;SHINKA_DEMO_VIEW_BeginIntro((Owner *)((struct Owner *)p));}
        break;
    case 10:if(SHINKA_DEMO_VIEW_AreModelsState4(p))W(0x14)=11;break;
    case 11:
        if(W(0x18)>=30){W(0x14)=13;W(0x18)=0;W(0x3c)=1;W(0x28)=1;}
        else W(0x18)++;
        break;
    case 12:if(SHINKA_DEMO_VIEW_AreModelsState4(p)){W(0x14)=13;W(0x3c)=1;W(0x28)=1;}break;
    case 13:if(W(0x2c))W(0x14)=14;break;
    case 14:
        W(0x14)=15;
        if(W(0x40))W(0x18)=0;
        else {
            B(0x48)=SHINKA_DEMO_VIEW_OtherSlot(B(0x48));
            MCSS_ResetVanishFlag(NODE(B(0x48)));
            MCSS_SetVanishFlag(NODE(SHINKA_DEMO_VIEW_OtherSlot(B(0x48))));
            W(0x18)=30;
        }
        SHINKA_DEMO_VIEW_SetModelPosX(p,0);
        SHINKA_DEMO_VIEW_SetModelsPos(p,0x100000,0xfffff800,0);
        W(0x5c)=1;
        break;
    case 15:if(W(0x30))W(0x14)=16;break;
    case 16:
        W(0x14)=17;
        MCSS_SetPaletteFade((struct McssWork *)NODE(B(0x48)),16,0,1,0x7fff);
        break;
    case 17:
        if(!MCSS_CheckPaletteFade(NODE(B(0x48)))){W(0x14)=18;MCSS_ResetAnmStopFlag(NODE(B(0x48)));}
        break;
    case 18:
        if(!W(0x18)){W(0x14)=19;W(0x18)=0;}
        else W(0x18)--;
        break;
    case 19:
        {
            void *obj;
            u32 a,b;
            W(0x14)=20;
            if(W(0x40))obj=P(4);else obj=P(0x10);
            a=POKE_TOOL_GetPartyValue(obj,5,0);
            b=POKE_TOOL_GetPartyValue(obj,0x6f,0);
            PM_VOICE_Play(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 20:if(!PM_VOICE_IsAnyActive()){W(0x14)=21;W(0x18)=0;W(0x34)=1;}break;
    case 21:case 22:break;
    }
    if(W(0x5c))MCSS_Main(P(0x4c));
    SHINKA_DEMO_VIEW_Update((Owner *)((struct Owner *)p));
}

void SHINKA_DEMO_VIEW_Draw(Owner *o)
{
    if (o->useMcss != 0)
        MCSS_Draw(o->sys);
    else
        SHINKA_DEMO_VIEW_Draw3d(o);
}

/*
 * Setter for the +0x1c flag word of the ov195 scene object driven by
 * SHINKA_DEMO_Main.  Unlabelled in the listing (a leaf that saves no lr, so it
 * prints inside a .word run); region-qualified because ov094 overlaps.
 */
void SHINKA_DEMO_VIEW_RequestStart(int *p)
{
    p[7] = 1;
}

/*
 * Getter for the +0x20 word of the ov195 scene object (unlabelled leaf).
 */
int SHINKA_DEMO_VIEW_IsStartDone(int *p)
{
    return p[8];
}

/*
 * Setter for the +0x24 flag word of the ov195 scene object (unlabelled leaf).
 */
void SHINKA_DEMO_VIEW_RequestConfirm(int *p)
{
    p[9] = 1;
}

/*
 * Getter for the +0x28 word of the ov195 scene object (unlabelled leaf).
 */
int SHINKA_DEMO_VIEW_IsConfirmDone(int *p)
{
    return p[10];
}

/*
 * Setter for the +0x2c flag word of the ov195 scene object (unlabelled leaf).
 */
void SHINKA_DEMO_VIEW_RequestEvolve(int *p)
{
    p[11] = 1;
}

/*
 * Setter for the +0x30 flag word of the ov195 scene object (unlabelled leaf).
 */
void SHINKA_DEMO_VIEW_RequestFadeOut(int *p)
{
    p[12] = 1;
}

/*
 * Getter for the +0x34 word of the ov195 scene object (unlabelled leaf).
 */
int SHINKA_DEMO_VIEW_IsEvolveReady(int *p)
{
    return p[13];
}

/*
 * Getter for the +0x38 word of the ov195 scene object (unlabelled leaf).
 */
int SHINKA_DEMO_VIEW_IsEvolveStarted(int *p)
{
    return p[14];
}

/*
 * Getter for the +0x3c word of the ov195 scene object (unlabelled leaf).
 */
int SHINKA_DEMO_VIEW_IsEvolveDone(int *p)
{
    return p[15];
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: on a positive SHINKA_DEMO_VIEW_IsMenuReady
 * probe it sets the +0x40 word and the +0x14 state word of the scene object
 * and notifies SHINKA_DEMO_VIEW_ShowMenu; returns 1, else 0.
 */
int SHINKA_DEMO_VIEW_TrySecondForm(int *p)
{
    int SHINKA_DEMO_VIEW_IsMenuReady(int *);
    void SHINKA_DEMO_VIEW_ShowMenu(int *);

    if (SHINKA_DEMO_VIEW_IsMenuReady(p) != 0) {
        p[0x10] = 1;
        p[5] = 0xc;
        SHINKA_DEMO_VIEW_ShowMenu(p);
        return 1;
    }
    return 0;
}

/*
 * 0x02016020 (arm9 Thumb leaf `str r1,[r0,#0x30]; bx lr`) resolves as label
 * since its function_starts seed (2026-09-27). EXACT*: the listing extent
 * includes the 2 bytes of alignment padding at 0x022060BA.
 */
void SHINKA_DEMO_VIEW_InitMcss(char *owner)
{
    ((Owner *)owner)->sys = (void *)(uptr)MCSS_Init((unsigned int)2, (unsigned int)(((Owner *)owner)->heap));
    MCSS_SetTextureTransAdrs((void *)(((Owner *)owner)->sys), 0x30000);
    MCSS_SetOrthoMode((void *)(((Owner *)owner)->sys));
}

void SHINKA_DEMO_VIEW_ExitMcss(char *owner){MCSS_Exit(((Owner *)owner)->sys);}

fx32 SHINKA_DEMO_VIEW_GetModelOffset(void *p)
{
    int v = POKE_TOOL_GetPartyValue(p, 5, 0);
    fx32 r = -0x12000;

    switch (v) {
    case 0x260:
        r = -0x1b000;
        break;
    case 0x261:
        r = -0x27000;
        break;
    case 0x40:
        r = -0x11e66;
        break;
    }
    return r;
}

/*
 * mwccarm calls the add helper (0x0209C95C) _fadd and the subtract helper
 * (0x0209CB8C) _fsub, as layout/runtime_arm9.txt now does (swapped there
 * until 2026-09-28).
 */
void SHINKA_DEMO_VIEW_CreateModels(Owner *o)
{
    u8 i;
    VecFx32 scale;

    for (i = 0; i < 2; i++)
        o->obj[i] = 0;
    scale.x = FX_F32_TO_FX32(o->scale);
    scale.y = FX_F32_TO_FX32(o->scale);
    scale.z = 0x1000;
    if (o->mode == 0) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                o->obj[i] = MCSS_TOOL_AddPokeMcss(o->sys, o->res0, 0, 0, SHINKA_DEMO_VIEW_GetModelOffset(o->res0), 0);
            else
                o->obj[i] = MCSS_TOOL_AddPokeMcss(o->sys, o->res1, 0, 0, SHINKA_DEMO_VIEW_GetModelOffset(o->res1), 0);
            MCSS_SetShadowVanishFlag(o->obj[i], 1);
            MCSS_TOOL_SetAnimeStopCallback(o->obj[i]);
            MCSS_SetScale(o->obj[i], (u32 *)(&scale));
            if (i != 0) {
                MCSS_SetVanishFlag(o->obj[i]);
                MCSS_SetAnmStopFlag(o->obj[i]);
            }
        }
    } else {
        o->obj[1] = MCSS_TOOL_AddPokeMcss(o->sys, o->res0, 0, 0, SHINKA_DEMO_VIEW_GetModelOffset(o->res0), 0);
        MCSS_SetShadowVanishFlag(o->obj[1], 1);
        MCSS_TOOL_SetAnimeStopCallback(o->obj[1]);
        MCSS_SetScale(o->obj[1], (u32 *)(&scale));
    }
    SHINKA_DEMO_VIEW_UpdateModelOffsets((Owner *)o);
}

void SHINKA_DEMO_VIEW_DeleteModels(Owner *o)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            MCSS_SetVanishFlag(o->obj[i]);
            MCSS_Del(o->sys, o->obj[i]);
        }
    }
}

/*
 * Unlabelled Thumb leaf (saves no lr), seeded by address: flips a 0/1
 * slot index.
 */
u8 SHINKA_DEMO_VIEW_OtherSlot(u8 i)
{
    u8 r;

    if (i == 0)
        r = 1;
    else
        r = 0;
    return r;
}

#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

void SHINKA_DEMO_VIEW_UpdateModelOffsets(Owner *o)
{
    u8 i;
    float w, h, d;
    float x, y;
    VecFx32 pos;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            w = MCSS_GetSizeY(o->obj[i]);
            h = MCSS_GetOfsY(o->obj[i]);
            d = MCSS_GetOfsX(o->obj[i]);
            w = w * (o->scale / 16.0f);
            if (w > 96.0f)
                w = 96.0f;
            h = h * (o->scale / 16.0f);
            d = d * (o->scale / 16.0f);
            x = ((96.0f - w) / 2.0f + h) * 0.33f;
            y = (0.0f - d) * 0.33f;
            pos.x = FX_F32_TO_FX32(y);
            pos.y = FX_F32_TO_FX32(x);
            pos.z = 0;
            MCSS_SetOfsPosition(o->obj[i], (u32 *)(&pos));
        }
    }
}

void SHINKA_DEMO_VIEW_SetModelPosX(char *a, u32 v)
{
    u32 buf[3];
    u8 i;

    for (i = 0; i < 2; i++) {
        char *p = a + i * 4;
        if (((Owner *)p)->obj[0] != 0) {
            MCSS_GetPosition((void *)(((Owner *)p)->obj[0]), buf);
            buf[0] = v;
            MCSS_SetPosition((void *)(((Owner *)p)->obj[0]), buf);
        }
    }
}

static inline fx32 FX_SinIdx(int idx)
{
    return FX_SinCosTable_[idx * 2];
}

static inline fx32 FX_CosIdx(int idx)
{
    return FX_SinCosTable_[idx * 2 + 1];
}

void SHINKA_DEMO_VIEW_CreateWork(Owner *o)
{
    ShinkaDemoViewWork *w = GFL_HEAP_Alloc(o->heap, sizeof(ShinkaDemoViewWork), 1, d_02208F68, 0x54c);
    Grid *g;
    u32 a, b, c;
    u8 j, k;

    w->grid[0] = 0;
    w->grid[1] = 0;
    w->quad = 0;
    if (o->mode == 0)
        w->phase = 0;
    else
        w->phase = 3;

    a = POKE_TOOL_GetPartyValue(o->res0, 5, 0);
    b = POKE_TOOL_GetPartyValue(o->res0, 0x6f, 0);
    c = POKE_TOOL_GetGender(o->res0);
    g = w->grid[0] = SHINKA_DEMO_VIEW_CreateGrid(a, b, c, POKE_TOOL_IsShiny(o->res0), 0, 0, 0x26000, 0x960, o->heap);
    if (o->mode == 0) {
        SHINKA_DEMO_VIEW_InitGrid(g, o->heap);
        g->state = 3;
        SHINKA_DEMO_VIEW_StartGridFade((Grid *)((struct Fade *)g), o->heap, 0x7fff, 31, 31, 0, 31);
    } else {
        SHINKA_DEMO_VIEW_SetupGridCells(g, o->heap);
    }

    if (o->mode == 0) {
        a = POKE_TOOL_GetPartyValue(o->res1, 5, 0);
        b = POKE_TOOL_GetPartyValue(o->res1, 0x6f, 0);
        c = POKE_TOOL_GetGender(o->res1);
        g = w->grid[1] = SHINKA_DEMO_VIEW_CreateGrid(a, b, c, POKE_TOOL_IsShiny(o->res1), 0, 0, 0x28000, 0x980, o->heap);
        SHINKA_DEMO_VIEW_InitGrid(g, o->heap);
        g->state = 3;
        SHINKA_DEMO_VIEW_StartGridFade((Grid *)((struct Fade *)g), o->heap, 0x7fff, 31, 31, 0, 31);
        for (j = 0; j < 0x12; j++) {
            for (k = 0; k < 0x12; k++)
                g->row[j].cell[k].visible = 0;
        }
    }

    if (o->mode == 0)
        w->quad = (struct Quad *)SHINKA_DEMO_VIEW_CreateQuad(0x26000, 0x960, o->heap);
    o->work = w;
    SHINKA_DEMO_VIEW_SetModelsPos((char *)o, 0x100000, -0x800, 0);
    {
        VecFx32 cameraPos = d_02208E74;
        VecFx32 cameraTarget = d_02208E80;
        VecFx32 cameraUp = {0, 0, 0};

        w->camera = (void *)G3D_CAMERA_Create(0, FX_SinIdx(0xe3), FX_CosIdx(0xe3), 0x1555, 0, 0x1000, 0x400000, 0, (VecFx32 *)&cameraPos, (VecFx32 *)&cameraTarget, (VecFx32 *)&cameraUp, o->heap);
    }
}

#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

void SHINKA_DEMO_VIEW_DeleteWork(char *owner){char *q;u8 i;q=*(char * *)&((Owner *)owner)->work;G3D_CAMERA_Delete((void *)(((ShinkaDemoViewWork *)q)->camera));if(((ShinkaDemoViewWork *)q)->quad)SHINKA_DEMO_VIEW_FreeQuad(((ShinkaDemoViewWork *)q)->quad,((Owner *)owner)->heap);for(i=0;i<2;i++){if(*(char **)(q+i*4+8))SHINKA_DEMO_VIEW_DeleteGrid(*(char **)(q+i*4+8),((Owner *)owner)->heap);}GFL_HEAP_Free(q);}

void SHINKA_DEMO_VIEW_Update(Owner *o)
{
    ShinkaDemoViewWork *w = o->work;
    u16 heap = o->heap;
    u8 i;
    Grid *g;

    switch (w->phase) {
    case 0:
        break;
    case 1:
        SHINKA_DEMO_VIEW_DrawGridRotated(o);
        break;
    case 2:
    case 3:
        break;
    }
    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            if (o->secondForm != 0 && SHINKA_DEMO_VIEW_IsGridState3((char *)g, heap))
                g->state = 4;
            SHINKA_DEMO_VIEW_UpdateGridFade((Grid *)((struct Fade *)g), heap);
        }
    }
}

void SHINKA_DEMO_VIEW_Draw3d(Owner *o)
{
    u8 save0[0x20];
    u8 save1[0x24];
    ShinkaDemoViewWork *w = o->work;
    u8 i;

    G3D_SYSTEM_GetProjection((struct G3dProjection *)save0);
    G3D_SYSTEM_GetLookAt((struct G3dLookAt *)save1);
    {
        VecFx32 scale = d_02208E8C;
        MtxFx33 rot;
        VecFx32 trans = {0, 0, 0};

        MTX_Identity33_(&rot);
        NNS_G3dGlbBaseTrans(&trans);
        MI_Copy36B(&rot, &d_02148BCC.baseRot);
        d_02148BCC.flag &= ~0xa4;
        NNS_G3dGlbBaseScale(&scale);
    }
    G3D_CAMERA_Reset((struct G3dCamera *)w->camera);
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGeFlushBuffer();
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    REG_DIF_AMB = 0x7fff7fff;
    REG_SPE_EMI = 0x7fff7fff;
    for (i = 0; i < 2; i++) {
        if (w->grid[i] != 0)
            SHINKA_DEMO_VIEW_DrawGrid((Grid *)(w->grid[i]), o->heap);
    }
    if (w->quad != 0)
        SHINKA_DEMO_VIEW_DrawQuad((Quad *)w->quad, o->heap);
    G3D_SYSTEM_SetProjection((struct G3dProjection *)save0);
    G3D_SYSTEM_SetLookAt((struct G3dLookAt *)save1);
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGeFlushBuffer();
}

/*
 * Unlabelled Thumb leaf (saves no lr), seeded by address.
 */
void SHINKA_DEMO_VIEW_BeginIntro(Owner *o)
{
    ShinkaDemoViewWork *w = o->work;

    if (w->phase == 0)
        w->phase = 1;
}

int SHINKA_DEMO_VIEW_IsMenuReady(int *owner)
{
    int v = **(int * *)&((Owner *)owner)->work;

    return v != 0 && v != 4;
}

void SHINKA_DEMO_VIEW_ShowMenu(int *owner)
{
    char *q = *(char * *)&((Owner *)owner)->work;
    int *r = *(int * *)&((ShinkaDemoViewWork *)q)->grid[0];
    int v = r[0x28 / 4];

    if (v == 1) return;
    if (v == 2) return;
    if (v == 3) return;
    r[0x28 / 4] = 1;
}

void SHINKA_DEMO_VIEW_SetModelsPos(char *owner, u32 x, u32 y, u32 z)
{
    char *t = *(char * *)&((Owner *)owner)->work;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(void **)(t + i * 4 + 8) != 0)
            SHINKA_DEMO_VIEW_SetModelOffset(*(void **)(t + i * 4 + 8), ((Owner *)owner)->heap, x, y, z);
    }
    if (((ShinkaDemoViewWork *)t)->quad != 0)
        SHINKA_DEMO_VIEW_SetQuadOffset((char *)((ShinkaDemoViewWork *)t)->quad, ((Owner *)owner)->heap, x, y, z);
}

void SHINKA_DEMO_VIEW_SetModelOffset(char *grid, int unused, int c, int d, int e)
{
    ((Grid *)grid)->v.x = c;
    ((Grid *)grid)->v.y = d;
    ((Grid *)grid)->v.z = e;
}

void SHINKA_DEMO_VIEW_StartFadeOut(Owner *o)
{
    int heap = o->heap;
    ShinkaDemoViewWork *w = o->work;
    u8 i;
    Grid *g;

    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            g->state = 5;
            SHINKA_DEMO_VIEW_StartGridFade((Grid *)((struct Fade *)g), heap, 0x7fff, 31, 0, 0, -1);
        }
    }
}

int SHINKA_DEMO_VIEW_AreModelsState0(char *owner)
{
    u16 id = ((Owner *)owner)->heap;
    char *t = *(char * *)&((Owner *)owner)->work;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && SHINKA_DEMO_VIEW_IsGridState0(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}

int SHINKA_DEMO_VIEW_AreModelsState4(char *owner)
{
    u16 id = ((Owner *)owner)->heap;
    char *t = *(char * *)&((Owner *)owner)->work;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && SHINKA_DEMO_VIEW_IsGridState4(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}

Grid *SHINKA_DEMO_VIEW_CreateGrid(u32 monsNo, u32 formNo, u32 sex, u32 isShiny, u32 dir, u32 isEgg, u32 tex, u32 pltt, u16 heap)
{
    Grid *g = GFL_HEAP_Alloc(heap, sizeof(Grid), 1, d_02208F68, 0x720);
    u32 chrFile;
    u32 plttFile;
    u8 *src;
    u8 *buf;
    int i, j;
    int k;

    g->canvas = BMP_Create(16, 16, 32, heap);
    g->tex = tex;
    g->plttAddr = pltt;
    chrFile = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), monsNo, formNo, sex, isShiny, dir, isEgg);
    plttFile = POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(), monsNo, formNo, sex, isShiny, dir, isEgg);
    g->chr = 0;
    g->pltt = 0;
    g->chrRes = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), chrFile, 1, (&g->chr), heap);
    g->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(POKEGRA_GetArcID(), plttFile, (&g->pltt), heap);
    src = g->chr->raw;
    buf = BMP_GetPixels(g->canvas);
    MIi_CpuClear32(0, buf, 0x2000);
    k = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    BMP_ConvertToLinear(g->canvas, 0, heap);
    NNS_GfdRegisterNewVramTransferTask(0, tex, (uptr)BMP_GetPixels(g->canvas), 0x2000);
    NNS_GfdRegisterNewVramTransferTask((void *)1, pltt, (uptr)g->pltt->raw, 0x20);
    return g;
}

void SHINKA_DEMO_VIEW_DeleteGrid(char *grid, int unused)
{
    BMP_Delete(((Grid *)grid)->canvas);
    GFL_HEAP_Free(((Grid *)grid)->chrRes);
    GFL_HEAP_Free(((Grid *)grid)->plttRes);
    GFL_HEAP_Free(grid);
}

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((long long)a * b + 0x800) >> 12);
}

/*
 * 2026-10-05 (wave P2 lane Q1b, pengy share): EXACT* (974 B compiled, the
 * listing extent is 976 B with the trailing pad). Written bottom-up from the
 * matched twin SHINKA_DEMO_VIEW_SetupGridCells (same Grid/Ent, 18 x 18 entries of 0x80 bytes).
 * What closed the dx/dy/dz block: fx64 (long long) locals lx, ly, lz assigned
 * in the loop body (lz, then lx, then ly) and multiplied directly; LICM hoists
 * their sign words above the first _ll_mul and spills them, which gives the
 * extra frame word and the r6/r7 colours. Declaration order l2, dx.., row sets
 * the slots ([sp,#0x10] row, [sp,#0x18] l2). The pool word 0.13580248f
 * (0x3E0B0FCE) replaces the earlier 0.13636364f guess. Tried before: static
 * inline FX_Mul with long long parameters (966 B, no change).
 */
void SHINKA_DEMO_VIEW_InitGrid(Grid *grid, u16 heap)
{
    u8 i;
    u8 q;
    u8 j;
    u8 d;
    u8 v;
    int m;
    float s, t;
    int l2;
    ShinkaDemoViewCell *e;
    int dx, dy, dz, l1;
    ShinkaDemoViewCell *row;
    long long lx, ly, lz;

    SHINKA_DEMO_VIEW_SetupGridCells((Grid *)grid, heap);
    grid->state = 0;
    for (i = 0; i < 16; i++)
        grid->pal[i] = 0x7FFF;
    grid->color = 0x7FFF;
    q = 0;
    grid->flevel = q;
    grid->fwait = q;
    grid->fstep = q;
    grid->fcount = q;
    grid->x0 = 0x11;
    grid->y0 = 8;
    grid->x1 = q;
    grid->y1 = grid->y0 + 1;
    grid->f64 = q;
    grid->f68 = q;
    grid->f6c = q;
    grid->f70 = q;
    grid->rows = q;
    for (; q < 18; q++) {
        j = 0;
        d = q / 3;
        row = grid->row[q].cell;
        m = q % 3;
        for (; j < 18; j++) {
            e = &row[j];
            e->reserved30 = 0;
            e->start = e->cur;
            if (m == 0) {
                if (j < 9)
                    v = 6 * j;
                else
                    v = 6 * (j - 9) + 1;
            } else if (m == 1) {
                if (j < 9)
                    v = 6 * j + 2;
                else
                    v = 6 * (j - 9) + 3;
            } else {
                if (j < 9)
                    v = 6 * j + 4;
                else
                    v = 6 * (j - 9) + 5;
            }
            e->angle = ((int)v << 16) / 54;
            e->height = FX_F32_TO_FX32(22.0f - 7.3333335f * (float)d - 0.13580248f * (float)v);
            t = (float)e->height / 4096.0f;
            s = 10.0f + 2.0f * (2.0f * (t * (10.0f * t) / 44.0f / 44.0f));
            e->radius = FX_F32_TO_FX32(s);
            e->targetX = FX_Mul(e->radius, ((const SC *)FX_SinCosTable_)[e->angle >> 4].c);
            e->targetZ = FX_Mul(e->radius, ((const SC *)FX_SinCosTable_)[e->angle >> 4].s);
            e->targetY = e->height;
            dx = e->targetX - e->cur.x;
            dy = e->targetY - e->cur.y;
            dz = e->targetZ - e->cur.z;
            lz = dz;
            lx = dx;
            ly = dy;
            l1 = FX_Sqrt((fx32)((lx * lx + 0x800) >> 12) + (fx32)((lz * lz + 0x800) >> 12));
            l2 = FX_Sqrt((fx32)((ly * ly + 0x800) >> 12));
            if (l1 > 0x1000) {
                e->velX = FX_Div(dx, l1);
                e->velZ = FX_Div(dz, l1);
            } else {
                e->velX = dx;
                e->velZ = dz;
            }
            if (l2 > 0x1000)
                e->velY = FX_Div(dy, l2);
            else
                e->velY = dy;
            e->progress = 0;
        }
    }
}

/*
 * Builds a 18 x 18 grid of 0x80-byte entries: each gets two rounded fx32
 * corner sets, a position (cur) and its copy (org). The 0.0f offsets and the
 * 16/3 step are locals (z, k): the compiler propagates them only after folding,
 * so `z * (A / k)` stays a _fmul and `(float)r * k` keeps k as the second operand.
 */
void SHINKA_DEMO_VIEW_SetupGridCells(Grid *p, u16 heap)
{
    int i;
    float originX, originY, c, d;
    int q, r;
    float A, z, k;
    ShinkaDemoViewCell *e;

    p->v.x = 0;
    p->v.y = 0;
    p->v.z = 0;
    p->rows = 18;
    z = 0.0f;
    k = 5.3333335f;
    A = 2.0220568f;
    originX = -18.198511f + A / 2.0f;
    originY = 18.198511f - A / 2.0f;
    c = z * (A / k);
    d = z * (A / k);
    for (i = 0; i < 324; i++) {
        r = i % 18;
        q = i / 18;
        e = &p->row[q].cell[r];
        e->life = 60;
        e->visible = 31;
        e->v[0][0] = FX_F32_TO_FX32((0.0f - A) / 2.0f - c);
        e->v[0][1] = FX_F32_TO_FX32(A / 2.0f + d);
        e->v[0][2] = 0;
        e->v[1][0] = FX_F32_TO_FX32((0.0f - A) / 2.0f - c);
        e->v[1][1] = FX_F32_TO_FX32((0.0f - A) / 2.0f - d);
        e->v[1][2] = 0;
        e->v[2][0] = FX_F32_TO_FX32(A / 2.0f + c);
        e->v[2][1] = FX_F32_TO_FX32((0.0f - A) / 2.0f - d);
        e->v[2][2] = 0;
        e->v[3][0] = FX_F32_TO_FX32(A / 2.0f + c);
        e->v[3][1] = FX_F32_TO_FX32(A / 2.0f + d);
        e->v[3][2] = 0;
        e->cur = p->v;
        e->cur.x += FX_F32_TO_FX32(originX + A * (float)r);
        e->cur.y += FX_F32_TO_FX32(originY - A * (float)q);
        e->s0 = FX_F32_TO_FX32(16.0f + (float)r * k - z);
        e->t0 = FX_F32_TO_FX32(16.0f + (float)q * k - z);
        e->s1 = e->s0 + FX_F32_TO_FX32(k + 2.0f * z);
        e->t1 = e->t0 + FX_F32_TO_FX32(k + 2.0f * z);
        e->org = e->cur;
    }
}

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

/*
 * Grid of textured quads, rows of 0x12 cells of 0x80 bytes, one push /
 * translate / quad / pop per visible cell.
 */
void SHINKA_DEMO_VIEW_DrawGrid(Grid *w, u16 heap)
{
    int j;
    int i;
    ShinkaDemoViewCell *c;

    REG_TEXIMAGE_PARAM = (w->tex >> 3) | 0x6E430000;
    REG_TEXPLTT_BASE = w->plttAddr >> 4;
    j = 0;
    REG_MTX_PUSH = j;
    G3_Translate(w->v.x, w->v.y, w->v.z);
    REG_POLYGON_ATTR = 0x001F0080;
    for (; j < w->rows; j++) {
        for (i = 0; i < 0x12; i++) {
            c = &w->row[j].cell[i];
            if (c->visible != 0) {
                REG_MTX_PUSH = 0;
                G3_Translate(c->cur.x, c->cur.y, c->cur.z);
                REG_BEGIN_VTXS = 1;
                REG_NORMAL = 0x20000000;
                G3_TexCoord(c->s0, c->t0);
                G3_Vtx(c->v[0][0], c->v[0][1], c->v[0][2]);
                G3_TexCoord(c->s0, c->t1);
                G3_Vtx(c->v[1][0], c->v[1][1], c->v[1][2]);
                G3_TexCoord(c->s1, c->t1);
                G3_Vtx(c->v[2][0], c->v[2][1], c->v[2][2]);
                G3_TexCoord(c->s1, c->t0);
                G3_Vtx(c->v[3][0], c->v[3][1], c->v[3][2]);
                REG_END_VTXS = 0;
                REG_MTX_POP = 1;
            }
        }
    }
    REG_MTX_POP = 1;
}

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x)     ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

void SHINKA_DEMO_VIEW_DrawGridRotated(Owner *o)
{
    ShinkaDemoViewWork *w = o->work;
    u16 heap = o->heap;
    Grid *s;
    Grid *d;
    u8 j;
    u8 i;
    s16 x;
    s16 y;
    int flag;

    if (w->phase != 1)
        return;

    SHINKA_DEMO_VIEW_InitGridFromPokemon((char *)w->grid[0], heap);
    s = w->grid[0];
    d = w->grid[1];
    d->f68 = s->f68;
    for (j = 0; j < 0x12; j++) {
        for (i = 0; i < 0x12; i++)
            d->row[j].cell[i].cur = s->row[j].cell[i].cur;
    }

    for (y = d->y0; y >= s->y0; y--) {
        if (y == d->y0)
            x = d->x0;
        else
            x = 17;
        for (; x >= 0; x--) {
            if (y == s->y0) {
                if (x <= s->x0)
                    break;
                flag = 1;
            } else {
                flag = 1;
            }
            if (flag)
                d->row[y].cell[x].visible = 31;
        }
    }
    d->x0 = s->x0;
    d->y0 = s->y0;

    for (y = d->y1; y <= s->y1; y++) {
        if (y == d->y1)
            x = d->x1;
        else
            x = 0;
        for (; x < 0x12; x++) {
            if (y == s->y1) {
                if (x >= s->x1)
                    break;
                flag = 1;
            } else {
                flag = 1;
            }
            if (flag)
                d->row[y].cell[x].visible = 31;
        }
    }
    d->x1 = s->x1;
    d->y1 = s->y1;
    d->rows = s->rows;

    s = w->grid[0];
    d = w->grid[1];
    d->state = s->state;
    if (SHINKA_DEMO_VIEW_IsGridState1((char *)s, heap)) {
        SHINKA_DEMO_VIEW_StartGridFadeOut(s, heap);
        SHINKA_DEMO_VIEW_StartGridFadeOut(d, heap);
    }
    SHINKA_DEMO_VIEW_IsGridState4((char *)s, heap);
    if (w->quad != 0) {
        w->quad->rowCount = w->grid[0]->rows;
        SHINKA_DEMO_VIEW_UpdateQuadVerts((Quad *)w->quad, heap);
    }
}

static inline int mul(int a,int b){return (int)(((long long)a*b+2048)>>12);}

static inline int sub(int a,int b){return (int)((u32)a-(u32)b);}

static inline int add(int a,int b){return (int)((u32)a+(u32)b);}

/*
 * checks: 1 own matrix/vec/invsqrt bodies and matched callers confirm signatures; original explicitly forwards heap in r1 to 08410; 2 06274/063E0/06604/0685C no complete motion twin; 3 Boolean first/second, Boolean done and _Bool smallH/smallV each DIFF597; after stop s16 first/second DIFF599; writable p retained; 4 case2 cursor cache DIFF600 and case3 shared done-zero DIFF597, scheduling cap used, branch/stack idioms read; 5 refreshed unfiltered idioms and matched neighbours, declared-stack-struct idiom read.
 * recoup 2026-10-05 (P17L3): extent is 2340 B (not 114 B); compiled 2364 (24 B over). First divergence at +0x94 in case 1: original stores one movs r1 to the flag slots [sp+0x84],[sp+0x80] with done in r5 and loop counters i,j in the LOWEST slots [sp+0x20],[sp+0x18] (q at 0x58); ours puts i,j just under the flags (0x78,0x74) and done in r4. Tried (4 compiles): flags declared before the s16 counters (597->596), counters declared last (594), counters as case-block locals (594, same), first=second=1 chain (597, worse). Slot order does not follow declaration order here; not closed. Best form kept (594 differ).
 * recoup 2026-10-05 P30R8 (18 compiles, best 562 differ, was 594): instruction-aligned diff shows the code shape is the original's except 4 things. (1) Spill slots: original keeps the s16 counters in the LOWEST slots (j 0x18, j 0x1c, i 0x20, i 0x24, i 0x28, below all compiler temps); ours puts named locals above temps, so ~540 of the differing bytes are slot numbers. Declaring `s16 i,i,i,j,j,j` reproduces the original relative order of the counters (not their absolute position). Block-local `char *q` per loop (594->567) and separate `first3,second3,done3` for case 3 (567->562; flags3 now at 0x78/0x74 like the original) are kept. (2) Original shares one `movs r,#1` for the two flag stores (str [0x84]; str [0x80]); ours emits two movs. Tried first=second=1, second=first=1, first=1;second=first, `int first=1,second=1`, u8 flags: all keep two movs. (3) smallV=0 in the original is `movs r2,#0; str r2,[sp,#0x7c]` before the pool load, a zero separate from smallH; ours shares r0. Tried smallH=smallV=0 and u8 smallV: no change. (4) add order at +04F8 (adds r4,r3,r4 / lsls r3,r2,#7 swapped). Per-function pragmas on the final form (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments off: 1451 to 2225 differ; scheduling, peephole off: no change). Counters first-declared put them at the top (570); counters and flags as case-block locals 571.
 * final push 2026-10-05 G10L2 (30 compiles, 562 -> 23 bytes off): (1) ONE shared s16 i,j for all four loops (drops the counters to the original low slots, clears the case 2 q/j register swap); (2) case 3 locals (vx..inv, dx..inv) declared in their branch blocks; (3) `done=1;first=1;second=1;` with done FIRST makes first/second share one movs (literal CSE), also for case 3; (4) `smallH=0;smallV=0;` order gives the separate smallV zero; (5) case 2 first clear as `c=p+i*0x900;c+=j*0x80;c[0x88]=0` matches the original schedule. Remaining 23 B: case 3 second clear (j shift scheduled before the add; original sequential), dy1 spill slot 0x68 vs 0x60 with the case 3 vert slots shifted by one, and the five hoisted 2048 constants of case 3 branch 1 stored in order m4,m5,m1,m2,m3 (original m1..m5; slots equal). Tried without effect: plain/pointer/struct-view/(j<<7)/inline cell forms for the clear, dy declared last/block-local/as vy/unsigned, case 1 locals block-scoped, q at function scope (worse), split horiz sum (worse).
 * pass 2 2026-10-06 P2L35 (29 compiles, 23 -> EXACT in --lang c99 and --lang c): (1) both case 2 grid clears as
 *   `*(u8 *)(p+i*0x900+0x88+j*0x80)=0;` (constant before the j term: the deeper left sum is built first, so the j shift
 *   is born after the base add; replaces the c-pointer form); (2) the case 3 vertical squares written out as
 *   `(int)(((long long)vy*vy+2048)>>12)` like the sibling ov195 02206A5C (FX_Mul inline temps took the low slots; case 1
 *   vert must stay FX_Mul); (3) all case 3 locals at function scope, with four distinct `horiz1,horiz2,vert1,vert2`
 *   declared after first3,second3,done3 (slot order horiz1,horiz2,vert1,vert2); (4) branch 1 writes the step into new
 *   locals nx,ny,nz with an else arm for each clamp (`else{nx=vx;nz=vz;}`, `else ny=vy;`): the else blocks change the
 *   loop block list, so LICM hoists the 2048 constants in text order (K1..K5).
 * extent: handed2340 ends at 0220818C before pop02208190; pools through022081A0; next genuine022081A4. Full extent2364 proved by explicit show.
 */
void SHINKA_DEMO_VIEW_InitGridFromPokemon(char *p,u16 heap)
{
    int first,second,done;
    int angle,dx,dy,dz,horiz,vert,inv,vx,vy,vz,smallH,smallV;
    ShinkaDemoViewVec goal;
    Matrix m1;
    ShinkaDemoViewVec source1;
    Matrix m2;
    ShinkaDemoViewVec source2;
    Matrix m3;
    ShinkaDemoViewVec source3;
    Matrix m4;
    ShinkaDemoViewVec source4;
    int first3,second3,done3;
    int horiz1,horiz2,vert1,vert2;
    int nx,ny,nz;
    s16 i,j;
    G(0x68)+=G(0x6c);
    if((int)G(0x68)>=65536)G(0x68)-=65536;
    for(i=0;i<18;i++)for(j=0;j<18;j++){
        char *q=p+0x74+i*0x900+j*0x80;
        V(0x74)=V(0x68);
    }
    switch(G(0x64)){
    case 0:
        G(0x64)=1;G(0x70)=0;G(0x6c)=0x600;return;
    case 1:
        done=1;first=1;second=1;
        for(i=0;i<18;i++)for(j=0;j<18;j++){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            MTX_RotY43_((union MtxFx43 *)&m1,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
            source1.x=Q(0x50);source1.y=0;source1.z=0;
            MTX_MultVec43((struct VecFx32 *)(&source1),(union MtxFx43 *)(&m1),(struct VecFx32 *)(&goal));goal.y=Q(0x54);
            if(Q(0x64)==0){
                if(first||second){Q(0x30)=0;Q(0x64)=1;if(first)first=0;else second=0;}
                done=0;
            }else if(Q(0x64)==1){
                if(Q(0x30)==0){
                    Q(0x68)=add(Q(0x68),Q(0x40));Q(0x6c)=add(Q(0x6c),Q(0x44));Q(0x70)=add(Q(0x70),Q(0x48));
                    Q(0x30)++;*(u8 *)(p+0xa274)=(u8)(i+1);
                }else{
                    dy=sub(Q(0x5c),Q(0x6c));dz=sub(Q(0x60),Q(0x70));dx=sub(Q(0x58),Q(0x68));
                    horiz=mul(dx,dx)+mul(dz,dz);vert=mul(dy,dy);
                    if(horiz<0x11ac&&vert<0x11ac){
                        Q(0x68)=Q(0x58);Q(0x70)=Q(0x60);Q(0x6c)=Q(0x5c);
                        Q(0x68)=goal.x;Q(0x70)=goal.z;Q(0x6c)=goal.y;Q(0x30)=0;Q(0x64)=2;
                    }else{
                        smallH=0;smallV=0;if(horiz<0x11ac)smallH=1;else if(vert<0x11ac)smallV=1;
                        if(smallH){Q(0x68)=Q(0x58);Q(0x70)=Q(0x60);}
                        else{
                            inv=FX_InvSqrt(horiz);
                            Q(0x68)=add(add(Q(0x68),mul(sub(Q(0x68),Q(0x74)),409)),mul(mul(dx,inv),3584));
                            Q(0x70)=add(add(Q(0x70),mul(sub(Q(0x70),Q(0x7c)),409)),mul(mul(dz,inv),3584));
                        }
                        if(smallV)Q(0x6c)=Q(0x5c);
                        else{vy=dy>=0?4096:-4096;Q(0x6c)=add(add(Q(0x6c),mul(sub(Q(0x6c),Q(0x78)),409)),mul(vy,3584));}
                        Q(0x30)++;
                    }
                }
                done=0;
            }else if(Q(0x64)==2){Q(0x68)=goal.x;Q(0x70)=goal.z;Q(0x6c)=goal.y;}
        }
        if(done){G(0x64)=2;if(G(0x28)!=1&&G(0x28)!=2)G(0x28)=1;}return;
    case 2:
        if(G(0x70)<100)G(0x6c)+=32;
        if(G(0x70)>=200&&G(0x70)<240)G(0x6c)-=32;
        for(i=0;i<18;i++)for(j=0;j<18;j++){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            MTX_RotY43_((union MtxFx43 *)&m2,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
            source2.x=Q(0x50);source2.y=0;source2.z=0;
            MTX_MultVec43((struct VecFx32 *)(&source2),(union MtxFx43 *)(&m2),(struct VecFx32 *)(&V(0x68)));Q(0x6c)=Q(0x54);
        }
        if(SHINKA_DEMO_VIEW_IsGridState3(p,heap)&&G(0x70)>=30){
            j=H(0x5a);i=H(0x5c);
            if(i>=0&&j>=0){
                *(u8 *)(p+i*0x900+0x88+j*0x80)=0;
                if(j-1<0){H(0x5a)=18;H(0x5c)--;}else H(0x5a)--;
            }
            j=H(0x5e);i=H(0x60);
            if(i<18&&j<18){
                *(u8 *)(p+i*0x900+0x88+j*0x80)=0;
                if(j+1>=18){H(0x5e)=0;H(0x60)++;}else H(0x5e)++;
            }
        }
        if(H(0x5c)<0&&H(0x60)>=18&&G(0x70)>=240){G(0x64)=3;G(0x70)=0;return;}
        G(0x70)++;return;
    case 3:
        done3=1;first3=1;second3=1;
        for(i=17;i>=0;i--)for(j=17;j>=0;j--){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            if(Q(0x64)==2){
                if(first3||second3){Q(0x30)=0;Q(0x64)=3;if(first3)first3=0;else second3=0;}
                else{
                    MTX_RotY43_((union MtxFx43 *)&m3,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
                    source3.x=Q(0x50);source3.y=0;source3.z=0;
                    MTX_MultVec43((struct VecFx32 *)(&source3),(union MtxFx43 *)(&m3),(struct VecFx32 *)(&V(0x68)));Q(0x6c)=Q(0x54);
                }
                done3=0;
            }else if(Q(0x64)==3){
                if(Q(0x30)==0){
                    MTX_RotY43_((union MtxFx43 *)&m4,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
                    source4.x=Q(0x50);source4.y=0;source4.z=0;
                    MTX_MultVec43((struct VecFx32 *)(&source4),(union MtxFx43 *)(&m4),(struct VecFx32 *)(&V(0x68)));Q(0x6c)=Q(0x54);
                    vx=sub(Q(0x68),Q(0x74));vy=sub(Q(0x6c),Q(0x78));vz=sub(Q(0x70),Q(0x7c));
                    horiz1=mul(vx,vx)+mul(vz,vz);vert1=(int)(((long long)vy*vy+2048)>>12);
                    if(horiz1>4096){inv=FX_InvSqrt(horiz1);nx=mul(vx,inv);nz=mul(vz,inv);}
                    else{nx=vx;nz=vz;}
                    if(vert1>4096)ny=vy>=0?4096:-4096;
                    else ny=vy;
                    Q(0x68)=add(Q(0x68),nx);Q(0x6c)=add(Q(0x6c),ny);Q(0x70)=add(Q(0x70),nz);Q(0x30)++;
                }else{
                    dx=sub(Q(0x34),Q(0x68));dy=sub(Q(0x38),Q(0x6c));dz=sub(Q(0x3c),Q(0x70));
                    horiz2=mul(dx,dx)+mul(dz,dz);vert2=(int)(((long long)dy*dy+2048)>>12);
                    if(horiz2<0x11ac&&vert2<0x11ac){Q(0x68)=Q(0x34);Q(0x70)=Q(0x3c);Q(0x6c)=Q(0x38);Q(0x30)=0;Q(0x64)=4;}
                    else{
                        if(horiz2>4096){inv=FX_InvSqrt(horiz2);dx=mul(dx,inv);dz=mul(dz,inv);}
                        if(vert2>4096)dy=dy>=0?4096:-4096;
                        Q(0x68)=add(Q(0x68),dx);Q(0x6c)=add(Q(0x6c),dy);Q(0x70)=add(Q(0x70),dz);
                    }
                }
                done3=0;
            }
        }
        if(done3){G(0x64)=4;G(0x28)=4;}return;
    case 4: return;
    }
}

void SHINKA_DEMO_VIEW_StartGridFade(Grid *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step)
{
    s16 v;

    p->color = color;
    p->fcur = cur;
    p->fend = end;
    p->fwait = wait;
    p->fstep = step;

    v = p->fcur;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->fcur = v;

    v = p->fend;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->fend = v;

    v = p->fstep;
    if (v > 31)
        v = 31;
    else if (v < -31)
        v = -31;
    p->fstep = v;

    if (p->fcur < p->fend) {
        if (p->fstep < 0)
            p->fstep = p->fstep * 0xFFFFFFFF;
    } else if (p->fcur > p->fend) {
        if (p->fstep > 0)
            p->fstep = p->fstep * 0xFFFFFFFF;
    } else {
        p->fstep = 0;
    }

    p->flevel = p->fcur;
    p->fcount = p->fwait;
    SHINKA_DEMO_VIEW_ApplyGridPalette(p, unused);
}

int SHINKA_DEMO_VIEW_IsGridFadeDone(Grid *p, int x)
{
    if (p->fstep == 0)
        return 1;
    return 0;
}

void SHINKA_DEMO_VIEW_StepGridFade(Grid *p, int x)
{
    s16 step = p->fstep;
    s16 v;

    if (step == 0)
        return;
    if (p->fcount > 0) {
        p->fcount = p->fcount - 1;
        return;
    }
    p->flevel = p->flevel + step;
    v = p->flevel;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->flevel = v;
    if (p->flevel == p->fend)
        p->fstep = 0;
    else
        p->fcount = p->fwait;
    SHINKA_DEMO_VIEW_ApplyGridPalette(p, x);
}

void SHINKA_DEMO_VIEW_ApplyGridPalette(Grid *p, int x)
{
    u16 *src = *(u16 * *)&((PlttData *)(p->pltt))->raw;
    u8 i;
    s16 tr, tg, tb;
    s16 r, g, b;
    s16 level;

    tr = (s16)(p->color & 0x1f);
    tg = (s16)((p->color & 0x3e0) >> 5);
    tb = (s16)((p->color & 0x7c00) >> 10);

    for (i = 1; i < 16; i++) {
        r = (s16)(src[i] & 0x1f);
        g = (s16)((src[i] & 0x3e0) >> 5);
        b = (s16)((src[i] & 0x7c00) >> 10);
        level = p->flevel;
        if (level == 31) {
            r = tr;
            g = tg;
            b = tb;
        } else {
            r = (s16)(r + ((tr - r) * level >> 5));
            g = (s16)(g + ((tg - g) * level >> 5));
            b = (s16)(b + ((tb - b) * level >> 5));
            r = r > 31 ? 31 : (r < 0 ? 0 : r);
            g = g > 31 ? 31 : (g < 0 ? 0 : g);
            b = b > 31 ? 31 : (b < 0 ? 0 : b);
        }
        p->pal[i] = r | (g << 5) | (b << 10);
    }
    NNS_GfdRegisterNewVramTransferTask((void *)1, p->plttAddr, (uptr)p->pal, 0x20);
}

int SHINKA_DEMO_VIEW_IsGridState0(char *grid, u16 unused)
{
    return ((Grid *)grid)->state == 0;
}

int SHINKA_DEMO_VIEW_IsGridState1(char *grid, u16 heap)
{
    return ((Grid *)grid)->state == 1;
}

void SHINKA_DEMO_VIEW_StartGridFadeOut(Grid *p, int x)
{
    p->state = 2;
    SHINKA_DEMO_VIEW_StartGridFade(p, x, 0x7fff, 0, 31, 0, 1);
}

int SHINKA_DEMO_VIEW_IsGridState3(char *grid, u16 heap)
{
    return ((Grid *)grid)->state == 3;
}

int SHINKA_DEMO_VIEW_IsGridState4(char *grid, u16 heap)
{
    return ((Grid *)grid)->state == 4;
}

void SHINKA_DEMO_VIEW_UpdateGridFade(Grid *grid, int x)
{
    switch (grid->state) {
    case 0:
    case 1:
        break;
    case 2:
        if (SHINKA_DEMO_VIEW_IsGridFadeDone((Grid *)grid, x))
            grid->state = 3;
        break;
    case 3:
    case 4:
        break;
    case 5:
        if (SHINKA_DEMO_VIEW_IsGridFadeDone((Grid *)grid, x))
            grid->state = 0;
        break;
    }
    SHINKA_DEMO_VIEW_StepGridFade((Grid *)grid, x);
}

Quad *SHINKA_DEMO_VIEW_CreateQuad(u32 tex, u32 pltt, u16 heap)
{
    Quad *p = GFL_HEAP_Alloc(heap, sizeof(Quad), 1, d_02208F68, 0xd31);

    p->tex = tex;
    p->pltt = pltt;
    p->tz = 0;
    p->ty = 0;
    p->tx = 0;
    p->sx = 0x2465a;
    p->sy = 0x2465a;
    p->sz = 0x1000;
    p->polyId = 0x3b;
    p->s0 = 0x10000;
    p->t0 = 0x10000;
    p->s1 = 0x70000;
    p->t1 = 0x70000;
    p->alpha = 0x1f;
    p->v[0][0] = -0x800;
    p->v[0][1] = 0x800;
    p->v[0][2] = 0;
    p->v[1][0] = -0x800;
    p->v[1][1] = -0x800;
    p->v[1][2] = 0;
    p->v[2][0] = 0x800;
    p->v[2][1] = -0x800;
    p->v[2][2] = 0;
    p->v[3][0] = 0x800;
    p->v[3][1] = 0x800;
    p->v[3][2] = 0;
    p->rowCount = 0;
    return p;
}

void SHINKA_DEMO_VIEW_FreeQuad(void *p,int n){GFL_HEAP_Free(p);}

/*
 * The rounding is the SDK FX_F32_TO_FX32 shape applied to an integer
 * (x * 4096 is an int multiply, converted for the +-0.5f). mwccarm calls
 * the add helper (0x0209C95C) as _fadd and the subtract helper
 * (0x0209CB8C) as _fsub, as layout/runtime_arm9.txt now does (swapped
 * there until 2026-09-28).
 */
void SHINKA_DEMO_VIEW_UpdateQuadVerts(Quad *p, u16 heap)
{
    u8 i = p->rowCount;
    u8 b;

    p->v[3][1] = d_02208E4C[i];
    p->v[0][1] = p->v[3][1];
    b = d_02208E38[i];
    p->t0 = FX_F32_TO_FX32(b);
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}

/*
 * One textured quad in immediate geometry: texture image and palette base,
 * push, polygon attributes, translate, scale, four vertices, pop.
 *
 * 2026-10-05 (D8): residue is only the z of the last vertex (v[3][2], offset
 * 0x46, beyond the ldrh immediate range). Original: movs r5,#0x46; ldrsh r6,[r4,r5]
 * then lsls/lsrs #16 before the store (sign load, explicit u16 truncation, not
 * folded). Ours folds to adds/adds/ldrh and stores r6 directly (6 bytes
 * shorter in that block, so the early skip branch differs only by length).
 * Everything before it is byte-identical. Tried: fx16 local, s32 local for z,
 * raw *(s16 *)((u8 *)p + 0x46). None changes the load form. The first three
 * z values (offsets 0x3a, 0x40) fold to ldrh in the original, so the last one
 * likely has a second signed use or a different source type; not found.
 *
 * 2026-10-05 (D9-14): closed, EXACT. The z of the third vertex (offset 0x46; the
 * D8 note said v[3][2], it is v[2][2]) is read into an int local after the third
 * texcoord and passed to G3_Vtx. The int local keeps the sign-extending load
 * (ldrsh) and the explicit u16 truncation after the x/y store. An fx16 local in the
 * same place folds to ldrh (81 bytes); the local read before G3_TexCoord gives the
 * ldrsh but schedules it into the texcoord block (29 bytes).
 */
void SHINKA_DEMO_VIEW_DrawQuad(Quad *p, u16 heap)
{
    int z;

    if (p->rowCount < 0x12) {
        REG_TEXIMAGE_PARAM = (p->tex >> 3) | 0x6E430000;
        REG_TEXPLTT_BASE = p->pltt >> 4;
        REG_MTX_PUSH = 0;
        REG_POLYGON_ATTR = ((p->alpha != 0 ? 2 : 0) << 6) | (p->polyId << 24) | (p->alpha << 16);
        G3_Translate(p->tx, p->ty, p->tz);
        G3_Scale(p->sx, p->sy, p->sz);
        REG_BEGIN_VTXS = 1;
        REG_NORMAL = 0x20000000;
        G3_TexCoord(p->s0, p->t0);
        G3_Vtx(p->v[0][0], p->v[0][1], p->v[0][2]);
        G3_TexCoord(p->s0, p->t1);
        G3_Vtx(p->v[1][0], p->v[1][1], p->v[1][2]);
        G3_TexCoord(p->s1, p->t1);
        z = p->v[2][2];
        G3_Vtx(p->v[2][0], p->v[2][1], z);
        G3_TexCoord(p->s1, p->t0);
        G3_Vtx(p->v[3][0], p->v[3][1], p->v[3][2]);
        REG_END_VTXS = 0;
        REG_MTX_POP = 1;
    }
}

void SHINKA_DEMO_VIEW_SetQuadOffset(char *quad, int unused, int c, int d, int e)
{
    ((Quad *)quad)->tx = c;
    ((Quad *)quad)->ty = d;
    ((Quad *)quad)->tz = e;
}
