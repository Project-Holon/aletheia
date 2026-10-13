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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_020414AC  0x020414AC  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_020490F4  0x020490F4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021DB97C     0x021DB97C  data    ov021  a4
 *   BMP_Delete  0x020437AC  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   d_021DB984     0x021DB984  data  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   func_0206DF3C  0x0206DF3C  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02040588  0x02040588  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02045768  0x02045768  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   func_02040B1C  0x02040B1C  arm
 *   sFieldSaveAnimeSteps     0x021DB990  data  a2
 */
struct Node;
struct Bmp;
struct GameSystem;
struct GameData;
struct Sub0200852CObj;
struct Obj020437AC;
struct Obj00020;
struct CharBuf;
struct Light;
struct VecFx32;
struct Descriptor;
struct Cfg;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V;

/* One frame of the save icon animation: character frame and its length. */
typedef struct FieldSaveAnimeStep {
    u16 frame;
    u16 duration;
} FieldSaveAnimeStep;

/* Save icon shown over the player while the game saves. */
typedef struct FieldSaveAnime {
    void *fieldMap;                 /* 0x00 */
    struct Descriptor *bmpWin;      /* 0x04: 4x4 tile window on BG 3 */
    u16 ofsX;                       /* 0x08: pixel offset inside the tile */
    u16 ofsY;                       /* 0x0A */
    struct Node *tcb;               /* 0x0C: animation task */
    struct Bmp *charData;           /* 0x10: icon frames */
    int frameCount;                 /* 0x14 */
    u32 step;                       /* 0x18: index into sFieldSaveAnimeSteps */
} FieldSaveAnime;

#define _SAVEANIME_BG_FRAME 3
#define _SAVEANIME_STEP_NUM 4

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_020414AC(int a);
extern void *func_020056A0(void *, void *, int);
extern void func_02030EAC(struct Node *n);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *func_020120F4(const struct GameSystem *gameSystem);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void BMP_Delete(struct Obj020437AC *p);
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void func_02048AD0(struct Light *l);
extern void func_02048B30(u32 l, V *out);
extern void func_02048AE8(u32 l, V *out);
extern void func_0207CA00(const V *a, const V *b, V *c);
extern void VEC_Normalize(const V *a, V *b);
extern void func_0207CAE8(const V *a, const V *b, V *c);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void func_0206DF3C(V *a, int *x, int *y);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02040588(u32 which, u32 enable);
extern void func_02041B6C(u32 bit);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u16 func_02045768(struct Descriptor *p);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
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
int FIELD_SAVEANIME_ShowWindow(FieldSaveAnime *work);
int FIELD_SAVEANIME_HideWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_DrawFrame(FieldSaveAnime *work, u32 frame);
void FIELD_SAVEANIME_AnimTask(void *tcb, FieldSaveAnime *work);

FieldSaveAnime *FIELD_SAVEANIME_Create(u32 heapId, void *fieldMap)
{
    FieldSaveAnime *work = func_02030734(heapId, sizeof(FieldSaveAnime), 1, d_021DE684, 0x8f);

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
    return func_020307B0(work);
}

void FIELD_SAVEANIME_Start(FieldSaveAnime *work)
{
    func_020414AC(_SAVEANIME_BG_FRAME);
    work->frameCount = 0;
    FIELD_SAVEANIME_ShowWindow(work);
    work->tcb = func_020056A0(FIELD_SAVEANIME_AnimTask, work, 0x80);
}

void FIELD_SAVEANIME_Stop(FieldSaveAnime *work)
{
    if (work->tcb != 0) {
        func_02030EAC(work->tcb);
        work->tcb = 0;
        FIELD_SAVEANIME_HideWindow(work);
    }
}

/* Loads the icon palette for the player's version and the icon frames. */
void FIELD_SAVEANIME_LoadResource(FieldSaveAnime *work, u32 heapId)
{
    void *arc = func_020490F4(200, heapId);
    u32 version;

    version = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(FIELDMAP_GetGameSystem(work->fieldMap))));
    work->charData = BMP_CreateFromArchive(200, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc, 1, 0, d_021DB97C[version] << 5, 0x120, 0x20, heapId);
    ARC_TOOL_DeleteHandle(arc);
}

u32 FIELD_SAVEANIME_DeleteResource(FieldSaveAnime *work)
{
    BMP_Delete((struct Obj020437AC *)work->charData);
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
    void *player;
    u32 camera;

    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    camera = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera(work->fieldMap));
    func_02048AD0((struct Light *)camera);
    func_02048B30(camera, &eye);
    func_02048AE8(camera, &target);
    func_0207CA00(&eye, &target, &dir);
    flatDir = dir;
    flatDir.y = 0;
    VEC_Normalize(&flatDir, &flatDir);
    func_0207CAE8(&flatDir, &d_021DB984, &side);
    func_0207CAE8(&dir, &side, &up);
    VEC_Normalize(&up, &up);
    FIELD_PLAYER_GetPos(player, (struct VecFx32 *)&pos);
    pos.x += (int)(((long long)up.x * -0x1C000 + 0x800) >> 12);
    pos.y += (int)(((long long)up.y * -0x1C000 + 0x800) >> 12);
    pos.z += (int)(((long long)up.z * -0x1C000 + 0x800) >> 12);
    func_0206DF3C(&pos, &x, &y);
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
    work->bmpWin = (struct Descriptor *)BMP_WIN_Create(_SAVEANIME_BG_FRAME, (u8)x, (u8)y, 5, (u32)5, (u32)9, (u32)1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770(work->bmpWin)), 0);
    BMP_WIN_TransferChars(work->bmpWin);
    FIELD_SAVEANIME_DrawFrame(work, 0);
}

u32 FIELD_SAVEANIME_DeleteWindow(FieldSaveAnime *work)
{
    func_020452E8(work->bmpWin);
    work->bmpWin = 0;
    return 0;
}

int FIELD_SAVEANIME_ShowWindow(FieldSaveAnime *work)
{
    BMP_WIN_MakeScreen((struct Cfg *)work->bmpWin);
    func_02041B6C(_SAVEANIME_BG_FRAME);
    return func_02040588(_SAVEANIME_BG_FRAME, 1);
}

int FIELD_SAVEANIME_HideWindow(FieldSaveAnime *work)
{
    BMP_WIN_ClearScreen(work->bmpWin);
    func_02041B6C(_SAVEANIME_BG_FRAME);
    return func_02040588(_SAVEANIME_BG_FRAME, 0);
}

/* Copies icon frame `frame` into the window and transfers its characters. */
void FIELD_SAVEANIME_DrawFrame(FieldSaveAnime *work, u32 frame)
{
    u32 charBase = func_02045768(work->bmpWin);
    u32 bmp = (u32)func_02045770(work->bmpWin);
    u32 chars;
    u32 size;

    BMP_Blit(work->charData, (struct Bmp *)bmp, 0, frame << 5, work->ofsX, work->ofsY, 0x20, 0x20, 0xFFFF);
    chars = (u32)BMP_GetPixels((const struct Bmp *)bmp);
    size = BMP_GetByteSize((const struct Bmp *)bmp);
    func_02040B1C(_SAVEANIME_BG_FRAME, (const void *)chars, size, charBase);
}

/*
 * Blocked: sFieldSaveAnimeSteps ({u16 frame; u16 duration;} step table, two pool
 * words for +0 and +2) is contested: another overlay in the window starts
 * an object at 0x021DB990 and this function has no overlay_id site.
 */
void FIELD_SAVEANIME_AnimTask(void *tcb, FieldSaveAnime *work)
{
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
