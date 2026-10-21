/*
 * file:     field_saveanime.c
 * unit:     yes
 * function: FIELD_SAVEANIME_Create, FIELD_SAVEANIME_Delete, FIELD_SAVEANIME_Start, FIELD_SAVEANIME_Stop, FIELD_SAVEANIME_LoadResource, FIELD_SAVEANIME_DeleteResource, FIELD_SAVEANIME_CreateWindow, FIELD_SAVEANIME_DeleteWindow, FIELD_SAVEANIME_ShowWindow, FIELD_SAVEANIME_HideWindow, FIELD_SAVEANIME_DrawFrame, FIELD_SAVEANIME_AnimTask
 * address:  0x021D1164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_palace_sys.c at 0x021D1164 (__FILE__ anchor field_saveanime.c at 0x021D1164; 0x021D14C4 starts unrelated grid tile code).
 *
 * symbols:
 *   d_021DE684     0x021DE684  data  ov021  a4
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021DB97C     0x021DB97C  data    ov021  a4
 *   BMP_Delete  0x020437AC  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   d_021DB984     0x021DB984  data  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetCharOffset  0x02045768  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   sFieldSaveAnimeSteps     0x021DB990  data  a2
 */
struct Node;
struct Bmp;
struct GameSystem;
struct GameData;
struct Sub0200852CObj;
struct FieldMap;
struct CharBuf;
struct Light;
#include "../sdk_fx.h"

struct Descriptor;
struct Cfg;
#include "../types.h"
typedef struct VecFx32 V;

/* One frame of the save icon animation: character frame and its length. */
typedef struct FieldSaveAnimeStep {
    u16 frame;
    u16 duration;
} FieldSaveAnimeStep;

/* Save icon shown over the player while the game saves. */
typedef struct FieldSaveAnime {
    void *fieldMap;                 /* 0x00 */
    struct BmpWin *bmpWin;      /* 0x04: 4x4 tile window on BG 3 */
    u16 ofsX;                       /* 0x08: pixel offset inside the tile */
    u16 ofsY;                       /* 0x0A */
    struct TcbTask *tcb;             /* 0x0C: animation task */
    struct Bmp *charData;           /* 0x10: icon frames */
    int frameCount;                 /* 0x14 */
    u32 step;                       /* 0x18: index into sFieldSaveAnimeSteps */
} FieldSaveAnime;

#define _SAVEANIME_BG_FRAME 3
#define _SAVEANIME_STEP_NUM 4

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/bg_sys.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/arc_tool.h"
#include "fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
struct MyStatus;
#include "../arm9/mystatus.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "field_camera.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define ARC_UTIL_UploadPaletteFromHandle ARC_UTIL_UploadPaletteFromHandle_header
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_UploadPaletteFromHandle
extern void ARC_UTIL_UploadPaletteFromHandle(void *, u32, u32, u32, u32, u32, u32);
#endif
struct FieldPlayer;
struct FieldCamera;
struct G3dCamera;
#include "field_player.h"
#include "../arm9/g3d_camera.h"
#include "../arm9/fx_vec.h"
#include "../arm9/nns_g3d_util.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
extern char d_021DE684[];
extern const u32 d_021DB97C[];
extern const V d_021DB984;
extern FieldSaveAnimeStep sFieldSaveAnimeSteps[];
FieldSaveAnime *FIELD_SAVEANIME_Create(u32 heapId, void *fieldMap);
int FIELD_SAVEANIME_Delete(FieldSaveAnime *work);
void FIELD_SAVEANIME_Start(FieldSaveAnime *work);
void FIELD_SAVEANIME_Stop(FieldSaveAnime *work);
void FIELD_SAVEANIME_LoadResource(FieldSaveAnime *work, u32 heapId);
u32 FIELD_SAVEANIME_DeleteResource(FieldSaveAnime *work);
void FIELD_SAVEANIME_CreateWindow(FieldSaveAnime *work);
u32 FIELD_SAVEANIME_DeleteWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_ShowWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_HideWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_DrawFrame(FieldSaveAnime *work, u32 frame);
void FIELD_SAVEANIME_AnimTask(struct TcbTask *tcb, void *arg);

FieldSaveAnime *FIELD_SAVEANIME_Create(u32 heapId, void *fieldMap)
{
    FieldSaveAnime *work = GFL_HEAP_Alloc(heapId, sizeof(FieldSaveAnime), 1, d_021DE684, 0x8f);

    work->fieldMap = fieldMap;
    FIELD_SAVEANIME_LoadResource(work, heapId);
    FIELD_SAVEANIME_CreateWindow(work);
    return work;
}

int FIELD_SAVEANIME_Delete(FieldSaveAnime *work)
{
    FIELD_SAVEANIME_Stop(work);
    FIELD_SAVEANIME_DeleteWindow(work);
    FIELD_SAVEANIME_DeleteResource(work);
    return GFL_HEAP_Free(work);
}

void FIELD_SAVEANIME_Start(FieldSaveAnime *work)
{
    BG_SYS_FreeSlot(_SAVEANIME_BG_FRAME);
    work->frameCount = 0;
    FIELD_SAVEANIME_ShowWindow(work);
    work->tcb = GFL_USE_AddMainTask(FIELD_SAVEANIME_AnimTask, work, 0x80);
}

void FIELD_SAVEANIME_Stop(FieldSaveAnime *work)
{
    if (work->tcb != 0) {
        TCB_DeleteTask(work->tcb);
        work->tcb = 0;
        FIELD_SAVEANIME_HideWindow(work);
    }
}

/* Loads the icon palette for the player's version and the icon frames. */
void FIELD_SAVEANIME_LoadResource(FieldSaveAnime *work, u32 heapId)
{
    void *arc = ARC_TOOL_CreateHandle(200, heapId);
    u32 version;

    version = MYSTATUS_GetSex((struct MyStatus *)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap))));
    work->charData = BMP_CreateFromArchive(200, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc, 1, 0, d_021DB97C[version] << 5, 0x120, 0x20, heapId);
    ARC_TOOL_DeleteHandle(arc);
}

u32 FIELD_SAVEANIME_DeleteResource(FieldSaveAnime *work)
{
    BMP_Delete((struct Bmp *)work->charData);
    work->charData = 0;
    return 0;
}

/*
 * Places the 4x4 tile window 0x1C units above the player along the camera
 * up vector, at the player's screen position.
 */
void FIELD_SAVEANIME_CreateWindow(FieldSaveAnime *work)
{
    V pos;
    V dir;
    V flatDir;
    V side;
    V up;
    V target;
    V eye;
    int x;
    int y;
    struct FieldPlayer *player;
    struct G3dCamera *camera;

    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    camera = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera(work->fieldMap));
    G3D_CAMERA_Reset(camera);
    G3D_CAMERA_GetCamTarget(camera, &eye);
    G3D_CAMERA_GetEye(camera, &target);
    VEC_Subtract(&eye, &target, &dir);
    flatDir = dir;
    flatDir.y = 0;
    VEC_Normalize(&flatDir, &flatDir);
    VEC_CrossProduct(&flatDir, &d_021DB984, &side);
    VEC_CrossProduct(&dir, &side, &up);
    VEC_Normalize(&up, &up);
    FIELD_PLAYER_GetPos(player, &pos);
    pos.x += (int)(((long long)up.x * -0x1C000 + 0x800) >> 12);
    pos.y += (int)(((long long)up.y * -0x1C000 + 0x800) >> 12);
    pos.z += (int)(((long long)up.z * -0x1C000 + 0x800) >> 12);
    NNS_G3dWorldPosToScrPos(&pos, &x, &y);
    x -= 0x10;
    y -= 0x18;
    work->ofsX = x % 8;
    work->ofsY = y % 8;
    x /= 8;
    y /= 8;
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x > 0x1F) {
        x = 0x1F;
    }
    if (y > 0x18) {
        y = 0x18;
    }
    work->bmpWin = BMP_WIN_Create(_SAVEANIME_BG_FRAME, (u8)x, (u8)y, 5, (u32)5, (u32)9, (u32)1);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)work->bmpWin)), 0);
    BMP_WIN_TransferChars((struct BmpWin *)work->bmpWin);
    FIELD_SAVEANIME_DrawFrame(work, 0);
}

u32 FIELD_SAVEANIME_DeleteWindow(FieldSaveAnime *work)
{
    BMP_WIN_Delete((struct BmpWin *)work->bmpWin);
    work->bmpWin = 0;
    return 0;
}

void FIELD_SAVEANIME_ShowWindow(FieldSaveAnime *work)
{
    BMP_WIN_MakeScreen(work->bmpWin);
    BG_SYS_MarkTileDirty(_SAVEANIME_BG_FRAME);
    BG_SYS_SetPlaneVisible(_SAVEANIME_BG_FRAME, 1);
}

void FIELD_SAVEANIME_HideWindow(FieldSaveAnime *work)
{
    BMP_WIN_ClearScreen(work->bmpWin);
    BG_SYS_MarkTileDirty(_SAVEANIME_BG_FRAME);
    BG_SYS_SetPlaneVisible(_SAVEANIME_BG_FRAME, 0);
}

/* Copies icon frame `frame` into the window and transfers its characters. */
void FIELD_SAVEANIME_DrawFrame(FieldSaveAnime *work, u32 frame)
{
    u32 charBase = BMP_WIN_GetCharOffset((struct BmpWin *)work->bmpWin);
    u32 bmp = (uptr)BMP_WIN_GetBmp((struct BmpWin *)work->bmpWin);
    uptr chars;
    u32 size;

    BMP_Blit(work->charData, (struct Bmp *)bmp, 0, frame << 5, work->ofsX, work->ofsY, 0x20, 0x20, 0xFFFF);
    chars = (uptr)BMP_GetPixels((const struct Bmp *)bmp);
    size = BMP_GetByteSize((const struct Bmp *)bmp);
    BG_SYS_LoadTileData(_SAVEANIME_BG_FRAME, (const void *)chars, size, charBase);
}

/*
 * Blocked: sFieldSaveAnimeSteps ({u16 frame; u16 duration;} step table, two pool
 * words for +0 and +2) is contested: another overlay in the window starts
 * an object at 0x021DB990 and this function has no overlay_id site.
 */
void FIELD_SAVEANIME_AnimTask(struct TcbTask *tcb, void *arg)
{
    FieldSaveAnime *work = arg;
    int count = work->frameCount + 1;
    u16 duration = sFieldSaveAnimeSteps[work->step].duration;

    work->frameCount = count;
    if (duration <= count) {
        work->step++;
        if (work->step >= _SAVEANIME_STEP_NUM) {
            work->step = 0;
            work->frameCount = 0;
        }
        FIELD_SAVEANIME_DrawFrame(work, sFieldSaveAnimeSteps[work->step].frame);
    }
}
