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
#include "../sdk_ioreg.h"
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







#include "mus_poke_draw.h"

#include "mus_item_draw.h"
struct BmpWin;

#include "../arm9/bmp_win.h"
struct GfFont;

#include "../arm9/gf_font.h"









extern void MUSICAL_SHOT_SYS_NoOp(u8 *);


struct LightSlot;
struct BbBoard;
struct G3dCamera;

#include "../arm9/billboard.h"





struct G3dCamera;


#include "../arm9/g3x.h"




#include "../arm9/arc_tool.h"













struct McssActorPool;









extern u32 MUSICAL_SHOT_SYS_GetActorSlotX(void *p, u32 i, u16 c);




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
    ShotScene *o;
    u8 j;
    o = GFL_HEAP_Alloc(heap, sizeof(*o), 1, d_021F8380, 0x85);
    o->heap = heap;
    o->record = (MusicalShotRecord *)src;
    for (i = 0; i < 4; i++) {
        u32 off = i * 0x58;
        u8 *row;
        o->objects[i] = (u8 *)MUSICAL_MCSS_AllocMon(*(u16 *)(src + off + 4), (u8)((MusicalPerformerBits *)(src + 6 + off))->gender, (u8)((MusicalPerformerBits *)(src + 6 + off))->form, (u8)((MusicalPerformerBits *)(src + 6 + off))->shiny, *(u32 *)(src + off + 8), heap);
        row = (u8 *)((uptr)src + off);
        for (j = 0; j < 8; j++) {
            u8 k = row[j * 8 + 0x20];
            if (k != 10) {
                ((McssMon *)o->objects[i])->slots[k][0] = *(u16 *)(row + j * 8 + 0x1c);
                ((McssMon *)o->objects[i])->slots[k][1] = *(s16 *)(row + j * 8 + 0x1e);
                *(u8 *)&((McssMon *)o->objects[i])->slots[k][2] = j;
            }
        }
    }
    MUSICAL_SHOT_SYS_Init3D((char *)o);
    MUSICAL_SHOT_SYS_InitActors(o);
    MUSICAL_SHOT_SYS_DrawCaption((u8 *)o);
    o->model = STA_ACT_LIGHT_AllocElem(o->heap, 0);
    STA_ACT_LIGHT_CreateModel(o->model, (u8)o->record->programId);
    STA_ACT_LIGHT_SetElemFrame(o->sprite, 0x80);
    STA_ACT_LIGHT_SetModelFrame(o->model, 0x80);
    return (u8 *)o;
}

void MUSICAL_SHOT_SYS_DeleteScene(u8 *scene)
{
    u8 i;
    STA_ACT_LIGHT_DeleteUnit((char *)((ShotScene *)scene)->unit);
    STA_ACT_LIGHT_DeleteModel((u8 *)((ShotScene *)scene)->model);
    STA_ACT_LIGHT_DeleteBillboardImage(((ShotScene *)scene)->sprite);
    MUSICAL_MCSS_DeleteRenderObj(((ShotScene *)scene)->renderObj);
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
    STA_ACT_LIGHT_UpdateBillboard(((ShotScene *)scene)->sprite);
    MUSICAL_MCSS_TickAnim(((ShotScene *)scene)->renderObj);
    STA_ACT_LIGHT_UpdateElemActors((char *)((ShotScene *)scene)->unit);
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    STA_ACT_LIGHT_NoOp(((ShotScene *)scene)->unit);
    STA_ACT_LIGHT_UpdateElem(((ShotScene *)scene)->sprite);
    MUSICAL_MCSS_DrawRenderObj(((ShotScene *)scene)->renderObj);
    STA_ACT_LIGHT_UpdateSprite(((ShotScene *)scene)->sprite);
    STA_ACT_LIGHT_DrawModel((u8 *)((ShotScene *)scene)->model);
    BILLBOARD_Draw((struct BbBoard *)((ShotScene *)scene)->board,(struct G3dCamera *)((ShotScene *)scene)->camera,0);
    MUSICAL_SHOT_SYS_NoOp(scene);
    G3D_SYSTEM_DrawEnd();
}

static inline void G2_SetWndOBJInsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)REG_WINOUT_ADDR & ~0x3F00u) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)REG_WINOUT_ADDR = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)REG_WINOUT_ADDR & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)REG_WINOUT_ADDR = (u16)tmp;
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
    ((ShotScene *)p)->camera = cam;
    G3D_CAMERA_Reset(cam);
    G3X_SetEdgeColorTable(d_021F81C4);
    *(volatile u16 *)REG_DISP3DCNT_ADDR = *(volatile u16 *)REG_DISP3DCNT_ADDR & 0xCFDF;
    *(volatile u16 *)REG_DISP3DCNT_ADDR = (*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 0x10;
    *(volatile u16 *)REG_DISP3DCNT_ADDR = (*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 8;
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    a = d_021F8274;
    b = d_021F8258;
    pb = &b;
    h = BILLBOARD_Create( (unsigned char *)&a, (u32)(*(u16 *)p));
    ((ShotScene *)p)->board = h;
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
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 8, 1, 0, 0xA);
    *(volatile u32 *)REG_DISPCNT_ADDR = (*(volatile u32 *)REG_DISPCNT_ADDR & 0xFFFF1FFF) | 0x8000;
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
  p->actorPool = MUSICAL_MCSS_CreateActorPool((uptr) p->board, 36, p->heap);
  p->sprite = STA_ACT_LIGHT_AddBillboardImage(p->heap, 0, p->renderObj, p->actorPool, p->board);
  for (i = 0; i < 4; i++)
    p->models[i] = 0;

  for (j = 0; j < 4; j++)
  {
    q = STA_ACT_LIGHT_AddPokemonElem(p->sprite, p->objects[j]);
    if (1)
    {
      p->models[j] = q;
      STA_ACT_LIGHT_ResetRenderAnim(p->sprite, q);
      STA_ACT_LIGHT_SetElemValue(p->sprite, p->models[j], 1);
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
    scale.x = MUSICAL_SHOT_SYS_GetActorSlotX(p, i, ((McssMon *)p->objects[i])->species);
    if (p->record->winnerMask & mask)
    {
      temp = base;
      pos.x = MUSICAL_SHOT_SYS_GetActorSlotX(p, i, ((McssMon *)p->objects[i])->species);
      pos.y = 155 << 12;
      pos.z = z[i];
      STA_ACT_LIGHT_SetActorPos(p->sprite, p->models[i], (const u32 *)(&pos));
      STA_ACT_LIGHT_SetActorOffset(p->sprite, p->models[i], (const u32 *)(&temp));
      scale.y = 22 << 14;
    }
    else
    {
      pos.x = MUSICAL_SHOT_SYS_GetActorSlotX(p, i, ((McssMon *)p->objects[i])->species);
      pos.y = 155 << 12;
      pos.z = z[i];
      STA_ACT_LIGHT_SetActorPos(p->sprite, p->models[i], (const u32 *)(&pos));
      scaleY = 2 << 18;
      scale.y = scaleY;
    }
    p->effects[i] = STA_ACT_LIGHT_CreateActor(p->unit, 1);
    STA_ACT_LIGHT_CopyElemA(p->unit, p->effects[i], (const u32 *)(&scale));
  }

}

struct WordSet;

struct Strbuf;

typedef struct { u32 words[4]; } Quad;

struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"



#include "../arm9/strbuf.h"


#include "../arm9/msgdata.h"


#include "../arm9/wordset.h"


#include "../arm9/printsys.h"
#include "../version.h"










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
    f=MSGDATA_CreateFromArchive(0,2,PM_LANG_JA(78,79),((ShotScene *)scene)->heap);
    b=MSGDATA_AllocString(f,0);
    WORDSET_SetSlotNumber(t,0,((ShotScene *)scene)->record->year,2,2,PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(t,1,((ShotScene *)scene)->record->month,2,2,PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(t,2,((ShotScene *)scene)->record->day,2,2,PM_LANG_HALF_WIDTH_DIGITS);
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
