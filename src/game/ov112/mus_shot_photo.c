/*
 * file:     mus_shot_photo.c
 * unit:     yes
 * function: MUSICAL_SHOT_SYS_CreateScene, MUSICAL_SHOT_SYS_DeleteScene, MUSICAL_SHOT_SYS_DrawScene, MUSICAL_SHOT_SYS_Init3D, MUSICAL_SHOT_SYS_LoadBg, MUSICAL_SHOT_SYS_Exit3D, MUSICAL_SHOT_SYS_InitActors, MUSICAL_SHOT_SYS_GetActorSlotX, MUSICAL_SHOT_SYS_DrawCaption, MUSICAL_SHOT_SYS_NoOp
 * address:  0x021F3AF0
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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_MCSS_AllocMon  0x021F67E0  thumb  ov112
 *   MUSICAL_SHOT_SYS_DrawCaption  0x021F40F4  thumb  ov112
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
 *   MUSICAL_SHOT_SYS_NoOp 0x021F4280 thumb ov112
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   BG_SYS_EnableBg0WithPriority  0x0204044C  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3X_SetEdgeColorTable  0x0207DCF8  arm
 *   BILLBOARD_Create  0x0204EBD4  arm
 *   BILLBOARD_SetScale  0x0204ED70  arm
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
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
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderCellVramBase 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   STA_ACT_LIGHT_AddBillboardImage 0x021F709C thumb ov112
 *   STA_ACT_LIGHT_AddPokemonElem 0x021F760C thumb ov112
 *   STA_ACT_LIGHT_ResetRenderAnim 0x021F80B0 thumb ov112
 *   STA_ACT_LIGHT_SetElemValue 0x021F8154 thumb ov112
 *   STA_ACT_LIGHT_CreateUnit 0x021F6BD8 thumb ov112
 *   MUSICAL_SHOT_SYS_GetActorSlotX 0x021F40D0 thumb ov112
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   STA_ACT_LIGHT_SetActorOffset 0x021F8084 thumb ov112
 *   STA_ACT_LIGHT_CreateActor 0x021F6E78 thumb ov112
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   d_021F8240 0x021F8240 data a4
 *   d_021F8234 0x021F8234 data a4
 *   d_021F824C 0x021F824C data a4
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   d_021F8264 0x021F8264 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_SetString 0x02045924 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../sdk_gx.h"
#include "musical_shot_sys_shared_types.h"
#include "mus_shot_photo_shared_types.h"
#include "musical_shot_types.h"

struct G3dCamera;

struct Lights;

struct Blk3;

struct Light;

struct Object;

typedef struct { u32 w[7]; } T28;

typedef struct { u32 w[3]; } T12;

typedef struct 
{
  int x;
  int y;
  int z;
} MusShotPhotoVec;

#ifdef __MWERKS__
#define ARC_UTIL_UploadPaletteFromHandle ARC_UTIL_UploadPaletteFromHandle_hdr
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_UploadPaletteFromHandle
u32 ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
#endif
#ifdef __MWERKS__
#define BG_SYS_FreeSlot BG_SYS_FreeSlot_hdr
#define BG_SYS_SetPlaneVisible BG_SYS_SetPlaneVisible_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_FreeSlot
#undef BG_SYS_SetPlaneVisible
void BG_SYS_FreeSlot(u32);
void BG_SYS_SetPlaneVisible(u32 which, unsigned char enable);
#endif
#include "../arm9/g3d_camera.h"
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_Init_hdr
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
#endif
#include "sta_act_light.h"
#include "sta_act_poke.h"
#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/g2.h"


#include "musical_system.h"

extern void MUSICAL_SHOT_SYS_DrawCaption(u8 *p);

#include "sta_act_bg.h"


extern void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);


extern void STA_ACT_LIGHT_DeleteUnit(char *p);


extern void STA_ACT_LIGHT_DeleteBillboardImage(char *p);

#include "mus_poke_draw.h"

#include "mus_item_draw.h"
struct BmpWin;

#include "../arm9/bmp_win.h"
struct GfFont;

#include "../arm9/gf_font.h"

extern void STA_ACT_LIGHT_UpdateBillboard(u8 *p);


extern void STA_ACT_LIGHT_UpdateElemActors(char *p);


extern void STA_ACT_LIGHT_UpdateElem(u8 *p);


extern void STA_ACT_LIGHT_UpdateSprite(char *p);


extern void MUSICAL_SHOT_SYS_NoOp(u8 *);

extern void G3D_SYSTEM_DrawStart(void);

extern void G3D_SYSTEM_ApplyLookAt(void);
struct LightSlot;
struct BbBoard;
struct G3dCamera;

#include "../arm9/billboard.h"

extern void G3D_SYSTEM_DrawEnd(void);


extern void BG_SYS_EnableBg0WithPriority(u32 mode);

extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);

struct G3dCamera;

extern void G3D_CAMERA_Reset(struct G3dCamera *camera);

#include "../arm9/g3x.h"



extern void BG_SYS_ChangeScrollImmediate(u32, u32, u32);

#include "../arm9/arc_tool.h"


extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void BG_SYS_PushTile(u32 index);


extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);



extern void BG_SYS_FreeLayerBuf(u32);


extern u32 G3D_CAMERA_Delete(void *ptr);

extern void G3D_SYSTEM_Exit(void);

struct McssActorPool;


extern u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);






extern u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);

extern u32 MUSICAL_SHOT_SYS_GetActorSlotX(void *p, u32 i, u16 c);

extern void STA_ACT_LIGHT_SetActorPos(void *unused, u32 *p, const u32 *q);

extern void STA_ACT_LIGHT_SetActorOffset(void *unused, u32 *p, const u32 *q);

extern void STA_ACT_LIGHT_CopyElemA(void *unused, u32 *p, const u32 *q);

u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap);

void MUSICAL_SHOT_SYS_DeleteScene(u8 *p);

void MUSICAL_SHOT_SYS_DrawScene(u8 *p);

void MUSICAL_SHOT_SYS_Init3D(char *p);

void MUSICAL_SHOT_SYS_LoadBg(const void *a,u32 b,u32 c);

void MUSICAL_SHOT_SYS_Exit3D(u8 *p);

void MUSICAL_SHOT_SYS_InitActors(ShotScene *p);

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

extern const MusShotPhotoVec d_021F8240;

extern const MusShotPhotoVec d_021F8234;

extern const MusShotPhotoVec d_021F824C;

u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap)
{
    u8 i;
    u8 *o;
    u8 j;
    o = GFL_HEAP_Alloc(heap, 100, 1, d_021F8380, 0x85);
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
    MUSICAL_SHOT_SYS_DrawCaption(o);
    ((ShotScene *)o)->model = STA_ACT_LIGHT_AllocElem(*(u16 *)o, 0);
    STA_ACT_LIGHT_CreateModel(((ShotScene *)o)->model, (u8)((ShotScene *)o)->record->programId);
    STA_ACT_LIGHT_SetElemFrame(((ShotScene *)o)->sprite, 0x80);
    STA_ACT_LIGHT_SetModelFrame(((ShotScene *)o)->model, 0x80);
    return o;
}

void MUSICAL_SHOT_SYS_DeleteScene(u8 *scene)
{
    u8 i;
    STA_ACT_LIGHT_DeleteUnit((char *)((ShotScene *)scene)->unit);
    STA_ACT_LIGHT_DeleteModel((u8 *)((ShotScene *)scene)->model);
    STA_ACT_LIGHT_DeleteBillboardImage(((ShotScene *)scene)->sprite);
    MUSICAL_MCSS_DeleteRenderObj((int)((ShotScene *)scene)->renderObj);
    MUSICAL_MCSS_DeleteActorPool(((ShotScene *)scene)->actorPool);
    BMP_WIN_Delete(((ShotScene *)scene)->winB);
    BMP_WIN_Delete(((ShotScene *)scene)->winA);
    GF_FONT_Delete(((ShotScene *)scene)->fontB);
    GF_FONT_Delete(((ShotScene *)scene)->fontA);
    MUSICAL_SHOT_SYS_Exit3D(scene);
    for(i=0;i<4;i++) GFL_HEAP_Free(*(void **)(scene+i*4+8));
    GFL_HEAP_Free(scene);
}

/*
 * extent: two-byte padding at 0x021F3CA2.
 */
void MUSICAL_SHOT_SYS_DrawScene(u8 *scene)
{
    STA_ACT_LIGHT_UpdateBillboard((u8 *)((ShotScene *)scene)->sprite);
    MUSICAL_MCSS_TickAnim(((ShotScene *)scene)->renderObj);
    STA_ACT_LIGHT_UpdateElemActors((char *)((ShotScene *)scene)->unit);
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    STA_ACT_LIGHT_NoOp(((ShotScene *)scene)->unit);
    STA_ACT_LIGHT_UpdateElem((u8 *)((ShotScene *)scene)->sprite);
    MUSICAL_MCSS_DrawRenderObj((void **)((ShotScene *)scene)->renderObj);
    STA_ACT_LIGHT_UpdateSprite((char *)((ShotScene *)scene)->sprite);
    STA_ACT_LIGHT_DrawModel((u8 *)((ShotScene *)scene)->model);
    BILLBOARD_Draw((struct BbBoard *)((ShotScene *)scene)->board,(struct G3dCamera *)((ShotScene *)scene)->camera,0);
    MUSICAL_SHOT_SYS_NoOp(scene);
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
 *   come out as in the original. ARC_UTIL_UploadBgCharFromHandle is u32 as in the matched ov123 021D9D3C and
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
    BG_SYS_EnableBg0WithPriority(3);
    G3D_SYSTEM_SetSwapBuffersMode(0, 1);
    cam = G3D_CAMERA_Create(2, 0xC000, 0, 0, 0x10000, 0x1000, 0x3E8000, 0,
                        (VecFx32 *)d_021F81AC, (VecFx32 *)d_021F81B8, (VecFx32 *)d_021F81A0, *(u16 *)p);
    *(void **)(p + 0x18) = cam;
    G3D_CAMERA_Reset(cam);
    G3X_SetEdgeColorTable(d_021F81C4);
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
    BG_SYS_ChangeScrollImmediate(2, 3, 0xE0);
    h = ARC_TOOL_CreateHandle(0x2F, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 3, 0, 0, 0, 0x20, *(u16 *)p);
    ARC_UTIL_UploadBgCharFromHandle(h, 9, 2, 0, 0, 0, *(u16 *)p);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0xF, 2, 0, 0, 0, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 0, 0x20, 0x20, 0x20, *(u16 *)p);
    ARC_UTIL_UploadBgCharFromHandle(h, 8, 3, 0, 0, 0, *(u16 *)p);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0xE, 3, 0, 0, 0, *(u16 *)p);
    BG_SYS_PushTile(2);
    BG_SYS_PushTile(3);
    ARC_TOOL_DeleteHandle(h);
    G2x_SetBlendAlpha_((void *)0x04000050, 8, 1, 0, 0xA);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    G2_SetWndOBJInsidePlane(0x17, 1);
    G2_SetWndOutsidePlane(0x1F, 1);
}

void MUSICAL_SHOT_SYS_LoadBg(const void *a,u32 b,u32 c) { BG_SYS_InitBgLayer(b,a,c); BG_SYS_SetPlaneVisible(b,1); BG_SYS_FreeSlot(b); BG_SYS_PushTile(b); }

void MUSICAL_SHOT_SYS_Exit3D(u8 *scene) { BG_SYS_FreeLayerBuf(3); BG_SYS_FreeLayerBuf(1); BG_SYS_FreeLayerBuf(2); BILLBOARD_Delete(((ShotScene *)scene)->board); G3D_CAMERA_Delete(((ShotScene *)scene)->camera); G3D_SYSTEM_Exit(); BG_SYS_FreeLayerBuf(0); }

/*
 * checks: retry rederived all callees; prior permuter 300 retained. Original table pool is 8240,8234,824C; declaration order restores it and all three resolve.
 * match: u32 offset and integer row address retain the spilled row and live index; vectors follow frame order; second loop reuses the earlier j as mask and mask as index; final mask advances before i.
 * ABI: 760C leaves a live result used by this caller despite its own void declaration.
 */
void MUSICAL_SHOT_SYS_InitActors(ShotScene *p)
{
  u32 offset;
  MusShotPhotoVec pos = d_021F8240;
  MusShotPhotoVec scale = d_021F8234;
  int z[4];
  MusShotPhotoVec temp;
  MusShotPhotoVec base;
  u8 i;
  u8 mask;
  u8 j;
  int flags;
  int current;
  void *q;
  u8 *row;
  int scaleY;
  void *tmp;
  current = 5 << 16;
  p->renderObj = MUSICAL_MCSS_CreateRenderObj(p->heap);
  MUSICAL_MCSS_SetRenderCellVramBase(p->renderObj, 2 << 16);
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
      STA_ACT_LIGHT_ResetRenderAnim(p->sprite, (StaActPokeElem *)q);
      STA_ACT_LIGHT_SetElemValue(p->sprite, *((int **) (row + 0x30)), 1);
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
    scale.x = MUSICAL_SHOT_SYS_GetActorSlotX(p, i, *((u16 *) ((*((u8 **) (row + 8))) + 8)));
    if (p->record->winnerMask & mask)
    {
      u8 *actor;
      temp = base;
      actor = ((u8 *) p) + offset;
      pos.x = MUSICAL_SHOT_SYS_GetActorSlotX(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
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
      pos.x = MUSICAL_SHOT_SYS_GetActorSlotX(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      STA_ACT_LIGHT_SetActorPos(p->sprite, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      scaleY = 2 << 18;
      scale.y = scaleY;
    }
    *((void **) (row + 0x44)) = STA_ACT_LIGHT_CreateActor(p->unit, 1);
    STA_ACT_LIGHT_CopyElemA(p->unit, *((void **) (row + 0x44)), (const u32 *)(&scale));
  }

}

struct WordSet;

struct Strbuf;

typedef struct { u32 words[4]; } Quad;

struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"


extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);

#include "../arm9/strbuf.h"


#include "../arm9/msgdata.h"


#include "../arm9/wordset.h"


#include "../arm9/printsys.h"







extern void BG_SYS_PushTile(u32);



void MUSICAL_SHOT_SYS_NoOp(u8 *unused);

extern const Quad d_021F8264;

u32 MUSICAL_SHOT_SYS_GetActorSlotX(void *p,u32 i,u16 c) { Quad q=d_021F8264; return q.words[i]; }

void MUSICAL_SHOT_SYS_DrawCaption(u8 *scene)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((ShotScene *)scene)->winA=(void *)BMP_WIN_Create(1,24,22,8,2,10,1);
    ((ShotScene *)scene)->winB=(void *)BMP_WIN_Create(1,1,1,30,2,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((ShotScene *)scene)->winA),0);
    BMP_Clear(BMP_WIN_GetBmp(((ShotScene *)scene)->winB),0);
    ((ShotScene *)scene)->fontA=GF_FONT_Create(23,3,0,0,((ShotScene *)scene)->heap);
    ((ShotScene *)scene)->fontB=GF_FONT_Create(23,0,0,0,((ShotScene *)scene)->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,320,32,((ShotScene *)scene)->heap);
    buf=STRBUF_Create(128,((ShotScene *)scene)->heap);
    t=WORDSET_CreateDefault(((ShotScene *)scene)->heap);
    f=MSGDATA_CreateFromArchive(0,2,78,((ShotScene *)scene)->heap);
    b=MSGDATA_AllocString(f,0);
    WORDSET_SetSlotNumber(t,0,((ShotScene *)scene)->record->year,2,2,1);
    WORDSET_SetSlotNumber(t,1,((ShotScene *)scene)->record->month,2,2,1);
    WORDSET_SetSlotNumber(t,2,((ShotScene *)scene)->record->day,2,2,1);
    WORDSET_CopyTaggedText(t,buf,b);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((ShotScene *)scene)->winA),0,0,buf,((ShotScene *)scene)->fontA,3424);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
    WORDSET_Delete(t);
    MSGDATA_Delete(f);
    buf=STRBUF_Create(37,((ShotScene *)scene)->heap);
    STRBUF_SetString(buf,(const u16 *)(*(u8 * *)&((ShotScene *)scene)->record+356));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((ShotScene *)scene)->winB),0,0,buf,((ShotScene *)scene)->fontB,15424);
    STRBUF_Delete(buf);
    BMP_WIN_TransferChars(((ShotScene *)scene)->winA);
    BMP_WIN_MakeScreen(((ShotScene *)scene)->winA);
    BMP_WIN_TransferChars(((ShotScene *)scene)->winB);
    BMP_WIN_MakeScreen(((ShotScene *)scene)->winB);
    BG_SYS_PushTile(1);
}

void MUSICAL_SHOT_SYS_NoOp(u8 *unused) { }
