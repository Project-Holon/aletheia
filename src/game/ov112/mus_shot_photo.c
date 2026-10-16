/*
 * file:     mus_shot_photo.c
 * unit:     yes
 * function: MUSICAL_SHOT_SYS_CreateScene, MUSICAL_SHOT_SYS_DeleteScene, MUSICAL_SHOT_SYS_DrawScene, MUSICAL_SHOT_SYS_Init3D, MUSICAL_SHOT_SYS_LoadBg, MUSICAL_SHOT_SYS_Exit3D, MUSICAL_SHOT_SYS_InitActors, MUSICAL_MCSS_SetObjectValue, MUSICAL_MCSS_DrawLabel, MUSICAL_MCSS_NoOp
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
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3X_SetEdgeColorTable  0x0207DCF8  arm
 *   BILLBOARD_Create  0x0204EBD4  arm
 *   BILLBOARD_SetScale  0x0204ED70  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
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
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_shot_photo_shared_types.h"
#include "musical_shot_types.h"

struct Camera;

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
} Vec;

extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);

extern void G2x_SetBlendAlpha_(void *,int,int,int,int);

extern u32 GFL_HEAP_Free(void *p);

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

extern void G3D_CAMERA_Reset(struct Light *l);

extern void G3X_SetEdgeColorTable(const void *a);

extern void *BILLBOARD_Create(u8 *src, void *heap);

extern void BILLBOARD_SetScale(u8 *dst, struct Blk3 *src);

extern void BG_SYS_FillScrollArea(u32, u32, u32);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern u32 ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void BG_SYS_PushTile(u32 index);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_SetPlaneVisible(u32 which, unsigned char enable);

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

extern const Vec d_021F8240;

extern const Vec d_021F8234;

extern const Vec d_021F824C;

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
    for(i=0;i<4;i++) GFL_HEAP_Free(*(void **)(p+i*4+8));
    GFL_HEAP_Free(p);
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
    BG_SYS_SetLowBit(3);
    G3D_SYSTEM_SetSwapBuffersMode(0, 1);
    cam = G3D_CAMERA_Create(2, 0xC000, 0, 0, 0x10000, 0x1000, 0x3E8000, 0,
                        d_021F81AC, d_021F81B8, d_021F81A0, *(u16 *)p);
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
    BG_SYS_FillScrollArea(2, 3, 0xE0);
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

struct WordSet;

struct Strbuf;

typedef struct { u32 words[4]; } Quad;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BG_SYS_PushTile(u32);

u32 MUSICAL_MCSS_SetObjectValue(void *p,u32 i,u16 c);

void MUSICAL_MCSS_DrawLabel(u8 *p);

void MUSICAL_MCSS_NoOp(u8 *a0);

extern const Quad d_021F8264;

u32 MUSICAL_MCSS_SetObjectValue(void *p,u32 i,u16 c) { Quad q=d_021F8264; return q.words[i]; }

void MUSICAL_MCSS_DrawLabel(u8 *p)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((ShotScene *)p)->winA=(void *)BMP_WIN_Create(1,24,22,8,2,10,1);
    ((ShotScene *)p)->winB=(void *)BMP_WIN_Create(1,1,1,30,2,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((ShotScene *)p)->winA),0);
    BMP_Clear(BMP_WIN_GetBmp(((ShotScene *)p)->winB),0);
    ((ShotScene *)p)->fontA=GF_FONT_Create(23,3,0,0,((ShotScene *)p)->heap);
    ((ShotScene *)p)->fontB=GF_FONT_Create(23,0,0,0,((ShotScene *)p)->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,320,32,((ShotScene *)p)->heap);
    buf=STRBUF_Create(128,((ShotScene *)p)->heap);
    t=WORDSET_CreateDefault(((ShotScene *)p)->heap);
    f=MSGDATA_CreateFromArchive(0,2,78,((ShotScene *)p)->heap);
    b=MSGDATA_AllocString(f,0);
    WORDSET_SetSlotNumber(t,0,((ShotScene *)p)->record->year,2,2,1);
    WORDSET_SetSlotNumber(t,1,((ShotScene *)p)->record->month,2,2,1);
    WORDSET_SetSlotNumber(t,2,((ShotScene *)p)->record->day,2,2,1);
    WORDSET_CopyTaggedText(t,buf,b);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((ShotScene *)p)->winA),0,0,buf,((ShotScene *)p)->fontA,3424);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
    WORDSET_DeleteStrbufED04(t);
    MSGDATA_Delete(f);
    buf=STRBUF_Create(37,((ShotScene *)p)->heap);
    STRBUF_SetString(buf,(const u16 *)(*(u8 * *)&((ShotScene *)p)->record+356));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((ShotScene *)p)->winB),0,0,buf,((ShotScene *)p)->fontB,15424);
    STRBUF_Delete(buf);
    BMP_WIN_TransferChars(((ShotScene *)p)->winA);
    BMP_WIN_MakeScreen(((ShotScene *)p)->winA);
    BMP_WIN_TransferChars(((ShotScene *)p)->winB);
    BMP_WIN_MakeScreen(((ShotScene *)p)->winB);
    BG_SYS_PushTile(1);
}

void MUSICAL_MCSS_NoOp(u8 *a0) { }
