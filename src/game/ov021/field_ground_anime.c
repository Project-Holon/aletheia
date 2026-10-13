/*
 * file:     field_ground_anime.c
 * unit:     yes
 * function: FIELD_GROUND_ANIME_Create, FIELD_GROUND_ANIME_Delete, FIELD_GROUND_ANIME_Update, FIELD_GROUND_ANIME_GetAnmEntry, FIELD_GROUND_ANIME_BindAnm, FIELD_GROUND_ANIME_UnbindAnm, FIELD_GROUND_ANIME_AnmSetInit, FIELD_GROUND_ANIME_AnmSetFree, FIELD_GROUND_ANIME_AnmSetUpdate, FIELD_GROUND_ANIME_AnmSetGetEntry, FIELD_GROUND_ANIME_AnmEntryInit, FIELD_GROUND_ANIME_AnmEntryFree, FIELD_GROUND_ANIME_AnmEntryBind, FIELD_GROUND_ANIME_AnmEntryUnbind, FIELD_GROUND_ANIME_AnmEntryUpdate, FIELD_GROUND_ANIME_TexAnmSetInit, FIELD_GROUND_ANIME_TexAnmSetFree, FIELD_GROUND_ANIME_TexAnmSetUpdate, FIELD_GROUND_ANIME_TexAnmInit, FIELD_GROUND_ANIME_TexAnmFree, FIELD_GROUND_ANIME_TexAnmUpdate, FIELD_GROUND_ANIME_TexAnmIsActive, FIELD_GROUND_ANIME_GetModelTexVramOffset, FIELD_GROUND_ANIME_GetTexSize, FIELD_GROUND_ANIME_GetTexData, FIELD_GROUND_ANIME_GetTexAnmKeyData, FIELD_GROUND_ANIME_GetTexAnmFile, FIELD_GROUND_ANIME_KeyTableGetKey, FIELD_GROUND_ANIME_KeyTableGetGroupCount, FIELD_GROUND_ANIME_KeyTableGetDuration, FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame, FIELD_GROUND_ANIME_KeyTableUnpack, func_021A7B08, func_021A7B10, func_021A7B20, func_021A7B88, func_021A7CE8, func_021A7E3C, func_021A7EB4, func_021A7F38, func_021A80FC, func_021A810C, func_021A811C, func_021A8140, func_021A8198, func_021A81DC, func_021A81EC, func_021A8200, func_021A8214, func_021A8234, func_021A8244, func_021A8268, func_021A8278, func_021A82A8, func_021A82D8, func_021A8324, func_021A834C
 * address:  0x021A7360
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the B variant of the ground animation, 021A7CE8..021A834C, from the head of field_menu.c (lane FXC3: the 21 functions before the first field_menu.c anchor FIELD_MENU_Create at 021A836C).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   _FieldGroundAnimeFileName     0x021DDF7C  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   NNS_G3dGetAnmByIdx  0x0206E9A4  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetMdlSet  0x0206E954  arm
 *   func_02047250  0x02047250  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   NNS_G3dAnmObjInit  0x02069C74  arm
 *   NNS_G3dRenderObjAddAnmObj  0x02069E88  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   G3D_SYSTEM_InitResourceByFile  0x02046CE0  arm
 *   func_02061CA4  0x02061CA4  arm
 *   NNS_G3dGetResDictIdxByName  0x0206E7EC  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   gTexDimensionTable     0x021D8B08  data  a2
 *   gTexPixelsPerByteTable     0x021D8B00  data  a1
 *   func_021A811C  0x021A811C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_021A80FC  0x021A80FC  thumb  ov021
 *   ENTRANCE_CAMERA_Create  0x021BDC94  thumb  ov021
 *   func_021A810C  0x021A810C  thumb  ov021
 *   func_021A8214  0x021A8214  thumb  ov021
 *   func_021A7CE8  0x021A7CE8  thumb  ov021
 *   func_021A8268  0x021A8268  thumb  ov021
 *   EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange  0x02162370  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   EVENT_MAPCHANGE_SetPlayerVanish  0x02185B88  thumb  ov020
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   ENTRANCE_CAMERA_Setup  0x021BDCC8  thumb  ov021
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   EVENT_FIELD_PROCLINK_StartObjAnim  0x021618E0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   ENTRANCE_CAMERA_IsActive  0x021BDD40  thumb  ov021
 *   ENTRANCE_CAMERA_IsInstant  0x021BDD48  thumb  ov021
 *   ENTRANCE_CAMERA_Start  0x021BDD20  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   ENTRANCE_CAMERA_Restore  0x021BDD34  thumb  ov021
 *   FIELD_CAMERA_ReloadSetting  0x0218E160  thumb  ov021
 *   ENTRANCE_CAMERA_Delete  0x021BDCB8  thumb  ov021
 *   func_021A7B10  0x021A7B10  thumb  ov021
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GetMoveOffsetInDir  0x021A3484  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FIELD_PLAYER_GetNogridLocationByDir  0x021A36C8  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb
 *   FIELD_BUILDMODEL_CreateNodeNearPos  0x0218C7D8  thumb
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb
 *   FIELD_BUILDMODEL_TryOpenNodeCurrentSlot  0x0218C8D8  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb
 *   FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry  0x0218C990  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

/*
 * Ground animation: texture animation of the field ground model.
 * Two independent sets, both driven by one speed value:
 *  - a GroundAnmSet of NNS animation objects bound to render objects, and
 *  - a GroundTexAnmSet of up to 16 texture-swap animations that copy new
 *    texel data into the model's texture VRAM slots as the frame counter
 *    advances.
 * Times are 20.12 fixed point (0x1000 = one frame).
 */

typedef struct GroundAnimeDesc {
    u16 hasAnmSet : 8;
    u16 hasTexAnmSet : 8;
    u16 anmCount;
    u16 anmArcId;
    u16 anmMemberId;
    u16 texAnmArcId;
    u16 texAnmMemberId;
    u16 reserved;
} GroundAnimeDesc;

/* Header of an NNS animation resource (type name is a guess). */
typedef struct NNSG3dResAnm {
    u32 header;
    u16 numFrame;
} NNSG3dResAnm;

typedef struct NNSG3dAnmObj {
    int frame;
    u32 ratio;
    NNSG3dResAnm *pResAnm;
} NNSG3dAnmObj;

typedef union GroundAnmFlags {
    u32 word;
    struct {
        u32 bound : 1;
        u32 rest : 31;
    } bits;
} GroundAnmFlags;

/* One NNS animation object (flags.bits.bound: bound to a render object). */
typedef struct GroundAnmEntry {
    GroundAnmFlags flags;
    NNSG3dAnmObj *anmObj;
    NNSG3dResAnm *pResAnm;
} GroundAnmEntry;

typedef struct GroundAnmSet {
    GroundAnmEntry *entries;
    u32 count;
    void *file;
    u32 frame;
} GroundAnmSet;

/* Texture index and palette index of one key. */
typedef struct GroundTexKey {
    u8 texIndex;
    u8 plttIndex;
} GroundTexKey;

/*
 * Key table unpacked from a key file: per key a frame number, a texture
 * index and a palette index; groupStarts splits the keys in groups (one
 * group per animated texture slot).
 */
typedef struct GroundKeyTable {
    u16 *keyFrames;
    u8 *texIndices;
    u8 *plttIndices;
    u8 *groupStarts;
    u32 keyCount;
    u32 groupCount;
    u32 duration;
} GroundKeyTable;

/* One animated model: per group the current key, the VRAM target and the time. */
typedef struct GroundTexAnm {
    u32 needsFullUpload;
    GroundTexKey *curKeys;
    s32 *vramOffsets;
    u32 *texSizes;
    s32 *times;
    u32 groupCount;
    void *modelRes;
    u32 *keyData;
    GroundKeyTable keyTable;
    void *animRes;
} GroundTexAnm;

typedef struct GroundTexAnmTableEntry {
    u32 keyDataOfs;
    u32 animResOfs;
} GroundTexAnmTableEntry;

/* Archive member: entry count, then per entry the offsets of its key data and texture file. */
typedef struct GroundTexAnmTable {
    u32 count;
    GroundTexAnmTableEntry entries[1];
} GroundTexAnmTable;

typedef struct GroundTexAnmSet {
    GroundTexAnm anms[16];
    GroundTexAnmTable *table;
} GroundTexAnmSet;

typedef struct FieldGroundAnime {
    u32 playing;
    u32 speed;
    GroundAnmSet anmSet;
    GroundTexAnmSet texAnmSet;
} FieldGroundAnime;

/* NNS model set block: header followed by a dictionary of model offsets. */
typedef struct ModelSetRes {
    u32 magic;
    u32 blockSize;
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} ModelSetRes;

typedef struct Dict {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} Dict;

typedef struct DictEntryHdr {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} DictEntryHdr;

/* NNS texture block (partial): VRAM key, texel data offset and name dictionary. */
typedef struct TexRes {
    u8 header[8];
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u32 flag;
    u32 ofsTex;
    u8 tex4x4PlttInfo[0x3C - 0x18];
    Dict dict;
} TexRes;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

/* Arguments the caller fills before it creates the ground animation task. */
typedef struct GroundAnimeArgs {
    void *reserved00;
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    int exitEntranceParam;      /* used by the "B" task (FIELD_GROUND_ANIME_CreateB) */
    int enterEntranceParam;     /* used by the "A" task */
    u8 reserved18[0x20 - 0x18];
    u16 zoneId;
    u8 reserved22[0x38 - 0x22];
    int exitSelector;
    int enterSelector;
    int useFixedSelector;
    u8 enterWarpFlag;
    u8 bgmReplaceFlag;
    u8 reserved46[0x48 - 0x46];
    int finished;
} GroundAnimeArgs;

#define GROUND_ANIME_STEP_MAX 9

/* Task work (0x3C bytes). steps lists the machine states to run in order, ending with the end state. */
typedef struct GroundAnimeWork {
    GroundAnimeArgs *args;
    void *bgmInfo;
    void *entrance;
    int entranceParam;
    int isEnter;
    int isExit;
    u16 frameCounter;
    u8 playerMoveMode;
    u8 reserved1B;
    VecFx32 entryPos;
    void *buildModel;
    u8 steps[GROUND_ANIME_STEP_MAX];
    u8 reserved35;
    u8 stepIndex;
    u8 reserved37;
    int chainSteps;
} GroundAnimeWork;

/* States of FIELD_GROUND_ANIME_MainA */
#define GROUND_A_LOCK_CAMERA 0
#define GROUND_A_START_ENTRANCE 1
#define GROUND_A_PLAY_MODEL_FORWARD 2
#define GROUND_A_WAIT_MODEL_FORWARD 3
#define GROUND_A_START_PLAYER_ANIM 4
#define GROUND_A_FINISH_ENTRANCE 5
#define GROUND_A_PLAY_MODEL_REVERSE 6
#define GROUND_A_WAIT_MODEL_REVERSE 7
#define GROUND_A_END 8
#define GROUND_A_WAIT_CAMERA 9
#define GROUND_A_DELAY 10

/* States of FIELD_GROUND_ANIME_MainB */
#define GROUND_B_START_ENTRANCE 0
#define GROUND_B_FINISH_ENTRANCE 1
#define GROUND_B_WAIT_FIELD 2
#define GROUND_B_PLAY_MODEL_FORWARD 3
#define GROUND_B_WAIT_MODEL 4
#define GROUND_B_START_PLAYER_ANIM 5
#define GROUND_B_REPLACE_BGM 6
#define GROUND_B_ENTER_EVENT 7
#define GROUND_B_END 8
#define GROUND_B_DELAY 9

#define SE_GROUND_ANIME_DOOR 0x559

extern void *func_02030734(u16 heapId, u32 size, u32 one, char *file, u32 line);
extern u32 func_020307B0(void *p);
extern void *ARC_UTIL_LoadMember(u32 arcId, u32 memberId, u32 zero, u16 heapId);
extern NNSG3dResAnm *NNS_G3dGetAnmByIdx(void *file, u32 idx);
extern void *G3D_SYSTEM_GetResourceFile(void *resource);
extern ModelSetRes *NNS_G3dGetMdlSet(void *file);
extern TexRes *func_02047250(void *resource);
extern void MI_CpuFill8(void *p, u32 value, u32 size);
extern void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, NNSG3dResAnm *pResAnm, u32 pResMdl, u32 pResTex);
extern void NNS_G3dRenderObjAddAnmObj(void *renderObj, NNSG3dAnmObj *anmObj);
extern int G3D_SYSTEM_GetResourceSize(void);
extern void G3D_SYSTEM_InitResourceByFile(void *out, void *file);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern int NNS_G3dGetResDictIdxByName(const Dict *dict, const void *name);
extern u32 func_0209C2B0(u32 a, u32 b);
extern void *FLDMMDL_FreeAcmd(char *p);
extern void *FIELDMAP_GetFieldPlayer(void *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *task);
extern void *func_02012A30(void *gameData);
extern void *ENTRANCE_CAMERA_Create(void *p);
extern int EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(int a);

extern void *FIELDMAP_GetCamera(void *fieldMap);
extern void *FIELDMAP_GetTaskManager(void *fieldMap);
extern u16 FIELDMAP_GetZoneId(void *fieldMap);
extern void EVENT_MAPCHANGE_SetPlayerVanish(void *fieldMap, u32 value);
extern int FIELD_CAMERA_HasDelay(void *camera);
extern void FIELD_CAMERA_EndDelay(void *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(void *camera);
extern void ENTRANCE_CAMERA_Setup(void *entrance, int *param);
extern void FIELD_SOUND_SYSTEM_PostFadeIn(void *bgmInfo, void *gameData);
extern void *EVENT_FIELD_PROCLINK_StartObjAnim(void *gameSystem, void *fieldMap);
extern void GAME_EVENT_CallEvent(void *gameEvent, void *subEvent);
extern int ENTRANCE_CAMERA_IsActive(void *entrance);
extern int ENTRANCE_CAMERA_IsInstant(void *entrance);
extern void ENTRANCE_CAMERA_Start(void *entrance);
extern int FIELD_TASK_MANAGER_IsEmpty(void *fieldProc);
extern void ENTRANCE_CAMERA_Restore(void *entrance);
extern int FIELD_CAMERA_ReloadSetting(void *camera);
extern void ENTRANCE_CAMERA_Delete(void *entrance);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(void *bgmInfo, void *gameData, u16 zoneId, u8 flag);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern u16 FIELD_PLAYER_GetDirDisp(void *player);
extern void FIELD_PLAYER_GetPos(void *player, VecFx32 *out);
extern u32 FIELDMAP_GetMoveKind(void *fieldMap);
extern void FIELD_PLAYER_GetMoveOffsetInDir(void *player, int moveMode, VecFx32 *out);
extern void func_0207CEE4(int scale, VecFx32 *from, VecFx32 *to, VecFx32 *out);
extern void FLDMMDL_MOVE_GetMapHeight(void *map, VecFx32 *pos, int *heightOut);
extern void *FIELDMAP_GetNogridMapper(void *fieldMap);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *fieldMapSub);
extern int FIELD_PLAYER_GetNogridLocationByDir(void *player, u32 moveMode, void *buf);
extern void FIELD_RAIL_GetLocationPos(void *rail, int *in, VecFx32 *out);
extern void *FIELDMAP_GetG3dMapper(void *fieldMap);
extern void *FIELD_G3D_MAPPER_GetBuildModel(void *mapper);
extern void *FIELD_BUILDMODEL_CreateNodeNearPos(void *mapper, int mode, VecFx32 *pos);
extern void FIELD_BUILDMODEL_DeleteNode(void *model);
extern int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(void *model);
extern void FIELD_BUILDMODEL_PlayNodeSlot(void *model, int animIndex, int arg);
extern int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(void *model, u16 *seOut);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, void *fieldMap, int selector, int arg3, int arg4, u8 flagA, u8 flagB);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, void *fieldMap, int selector, int arg3);
int func_021A7CE8(void *task, int *state, GroundAnimeWork *work);
void *func_021A7E3C(GroundAnimeArgs *args);
void func_021A7EB4(GroundAnimeWork *work);
int func_021A7F38(void *task, int *state, GroundAnimeWork *work);
int func_021A80FC(void *fieldMap);
void func_021A810C(void *fieldMap, VecFx32 *out);
void func_021A811C(void *fieldMap, VecFx32 *out);
void func_021A8140(void *fieldMap, VecFx32 *out);
void func_021A8198(void *fieldMap, VecFx32 *out);
u8 func_021A81DC(GroundAnimeWork *work);
u8 func_021A81EC(GroundAnimeWork *work);
void func_021A8200(GroundAnimeWork *work);
void func_021A8214(GroundAnimeWork *work);
void func_021A8234(GroundAnimeWork *work);
int func_021A8244(GroundAnimeWork *work);
int func_021A8268(GroundAnimeWork *work);
void func_021A8278(GroundAnimeWork *work);
void func_021A82A8(GroundAnimeWork *work);
void func_021A82D8(void *task, GroundAnimeWork *work);
void func_021A8324(void *task, GroundAnimeWork *work);
int func_021A834C(GroundAnimeWork *work);
FieldGroundAnime *FIELD_GROUND_ANIME_Create(const GroundAnimeDesc *desc, void *modelRes, u16 heapId);
int FIELD_GROUND_ANIME_Delete(FieldGroundAnime *ground);
void FIELD_GROUND_ANIME_Update(FieldGroundAnime *ground);
GroundAnmEntry *FIELD_GROUND_ANIME_GetAnmEntry(FieldGroundAnime *ground, int index);
int FIELD_GROUND_ANIME_BindAnm(u32 entry, u32 fileRes, u32 texRes, u32 renderObj);
void FIELD_GROUND_ANIME_UnbindAnm(GroundAnmEntry *entry);
void FIELD_GROUND_ANIME_AnmSetInit(GroundAnmSet *set, u32 arcId, u32 memberId, u32 count, u16 heapId);
void FIELD_GROUND_ANIME_AnmSetFree(GroundAnmSet *set);
void FIELD_GROUND_ANIME_AnmSetUpdate(GroundAnmSet *set, u32 dt);
GroundAnmEntry *FIELD_GROUND_ANIME_AnmSetGetEntry(GroundAnmSet *set, int index);
void FIELD_GROUND_ANIME_AnmEntryInit(GroundAnmEntry *entry, NNSG3dResAnm *pResAnm, u16 heapId);
int FIELD_GROUND_ANIME_AnmEntryFree(GroundAnmEntry *entry);
u32 FIELD_GROUND_ANIME_AnmEntryBind(GroundAnmEntry *entry, u32 fileRes, u32 texRes, u32 renderObj);
void FIELD_GROUND_ANIME_AnmEntryUnbind(GroundAnmEntry *entry);
int FIELD_GROUND_ANIME_AnmEntryUpdate(GroundAnmEntry *entry, int frame);
void FIELD_GROUND_ANIME_TexAnmSetInit(GroundTexAnmSet *set, u32 arcId, u32 memberId, void *modelRes, u16 heapId);
void FIELD_GROUND_ANIME_TexAnmSetFree(GroundTexAnmSet *set);
void FIELD_GROUND_ANIME_TexAnmSetUpdate(GroundTexAnmSet *set, int dt);
void FIELD_GROUND_ANIME_TexAnmInit(GroundTexAnm *anm, GroundTexAnmTable *table, u32 index, void *modelRes, u16 heapId);
void FIELD_GROUND_ANIME_TexAnmFree(GroundTexAnm *anm);
void FIELD_GROUND_ANIME_TexAnmUpdate(GroundTexAnm *anm, s32 dt);
int FIELD_GROUND_ANIME_TexAnmIsActive(GroundTexAnm *anm);
int FIELD_GROUND_ANIME_GetModelTexVramOffset(void *modelRes, void *animRes, u32 animTexIdx);
u32 FIELD_GROUND_ANIME_GetTexSize(void *animRes, u32 texIdx);
u8 *FIELD_GROUND_ANIME_GetTexData(void *animRes, u32 texIdx);
u32 FIELD_GROUND_ANIME_GetTexAnmKeyData(GroundTexAnmTable *table, u32 index);
u32 FIELD_GROUND_ANIME_GetTexAnmFile(GroundTexAnmTable *table, u32 index);
GroundTexKey FIELD_GROUND_ANIME_KeyTableGetKey(const GroundKeyTable *table, u32 group, u32 frame);
u32 FIELD_GROUND_ANIME_KeyTableGetGroupCount(GroundKeyTable *table);
u32 FIELD_GROUND_ANIME_KeyTableGetDuration(GroundKeyTable *table);
u16 FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(GroundKeyTable *table, int group);
void FIELD_GROUND_ANIME_KeyTableUnpack(u32 *keyFile, GroundKeyTable *out);
void func_021A7B08(void *fieldMap, VecFx32 *out);
int func_021A7B10(void *a);
void *func_021A7B20(GroundAnimeArgs *args);
void func_021A7B88(GroundAnimeWork *w);
extern char _FieldGroundAnimeFileName;
extern const u16 gTexDimensionTable[];
extern const u8 gTexPixelsPerByteTable[];

/*
 * Addresses are Black-image addresses.
 */
FieldGroundAnime *FIELD_GROUND_ANIME_Create(const GroundAnimeDesc *desc, void *modelRes, u16 heapId)
{
    FieldGroundAnime *ground;
    ground = func_02030734(heapId, 0x41c, 1, &_FieldGroundAnimeFileName, 0xd6);
    if (desc->hasAnmSet != 0) {
        u32 count = desc->anmCount;
        u32 arcId = desc->anmArcId;
        u32 memberId = desc->anmMemberId;
        FIELD_GROUND_ANIME_AnmSetInit(&ground->anmSet, arcId, memberId, count, heapId);
    }
    if (desc->hasTexAnmSet != 0)
        FIELD_GROUND_ANIME_TexAnmSetInit(&ground->texAnmSet, desc->texAnmArcId, desc->texAnmMemberId, modelRes, heapId);
    ground->playing = 1;
    ground->speed = 0x1000;
    return ground;
}

int FIELD_GROUND_ANIME_Delete(FieldGroundAnime *ground)
{
    FIELD_GROUND_ANIME_TexAnmSetFree(&ground->texAnmSet);
    FIELD_GROUND_ANIME_AnmSetFree(&ground->anmSet);
    return func_020307B0(ground);
}

void FIELD_GROUND_ANIME_Update(FieldGroundAnime *ground)
{
    u32 dt;
    if (ground->playing != 0) {
        dt = ground->speed;
    } else {
        dt = 0;
    }
    FIELD_GROUND_ANIME_AnmSetUpdate(&ground->anmSet, dt);
    FIELD_GROUND_ANIME_TexAnmSetUpdate(&ground->texAnmSet, dt);
}

/*
 * Tail-call thunk: forwards the animation set of the ground animation to FIELD_GROUND_ANIME_AnmSetGetEntry.
 *
 * Addresses are Black-image addresses.
 */
GroundAnmEntry *FIELD_GROUND_ANIME_GetAnmEntry(FieldGroundAnime *ground, int index)
{
    return FIELD_GROUND_ANIME_AnmSetGetEntry(&ground->anmSet, index);
}

int FIELD_GROUND_ANIME_BindAnm(u32 entry, u32 fileRes, u32 texRes, u32 renderObj)
{
    return FIELD_GROUND_ANIME_AnmEntryBind((GroundAnmEntry *)entry, fileRes, texRes, renderObj);
}

/*
 * Tail-call thunk: forwards to FIELD_GROUND_ANIME_AnmEntryUnbind with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_GROUND_ANIME_UnbindAnm(GroundAnmEntry *entry)
{
    FIELD_GROUND_ANIME_AnmEntryUnbind(entry);
}

void FIELD_GROUND_ANIME_AnmSetInit(GroundAnmSet *set, u32 arcId, u32 memberId, u32 count, u16 heapId)
{
    u32 i;
    NNSG3dResAnm *pResAnm;
    i = 0;
    set->file = ARC_UTIL_LoadMember(arcId, memberId, 0, heapId);
    pResAnm = NNS_G3dGetAnmByIdx(set->file, 0);
    set->entries = func_02030734(heapId, count * 12, 1, &_FieldGroundAnimeFileName, 0x196);
    set->count = count;
    for (i = 0; i < set->count; i++)
        FIELD_GROUND_ANIME_AnmEntryInit(&set->entries[i], pResAnm, heapId);
}

void FIELD_GROUND_ANIME_AnmSetFree(GroundAnmSet *set)
{
    u32 i;
    if (set->file != 0) {
        for (i = 0; i < set->count; i++) {
            FIELD_GROUND_ANIME_AnmEntryFree(&set->entries[i]);
        }
        func_020307B0(set->entries);
        set->entries = 0;
        func_020307B0(set->file);
        set->file = 0;
    }
}

void FIELD_GROUND_ANIME_AnmSetUpdate(GroundAnmSet *set, u32 dt)
{
    u32 i;
    set->frame += dt;
    if (set->file != 0) {
        for (i = 0; i < set->count; i++)
            set->frame = FIELD_GROUND_ANIME_AnmEntryUpdate(&set->entries[i], set->frame);
    }
}

/*
 * Returns 0 when the animation file is not loaded, else the entry of the set.
 *
 * Addresses are Black-image addresses.
 */
GroundAnmEntry *FIELD_GROUND_ANIME_AnmSetGetEntry(GroundAnmSet *set, int index)
{
    if (set->file != 0)
        return &set->entries[index];
    return 0;
}

void FIELD_GROUND_ANIME_AnmEntryInit(GroundAnmEntry *entry, NNSG3dResAnm *pResAnm, u16 heapId)
{
    entry->anmObj = func_02030734(heapId, 0x80, 1, &_FieldGroundAnimeFileName, 0x206);
    entry->pResAnm = pResAnm;
}

int FIELD_GROUND_ANIME_AnmEntryFree(GroundAnmEntry *entry)
{
    func_020307B0(entry->anmObj);
    entry->anmObj = 0;
    return 0;
}

static inline u32 *ModelSetGetOffsetSlot(ModelSetRes *set, u32 idx)
{
    u8 *dict = (u8 *)set + 8;
    if (dict != 0 && idx < set->numEntry)
        return (u32 *)(dict + set->ofsEntry + 4 + idx * 4);
    return 0;
}

static inline u32 ModelSetGetFirstModel(ModelSetRes *set)
{
    u32 *slot;
    if (set != 0) {
        slot = ModelSetGetOffsetSlot(set, 0);
        if (slot != 0)
            return (u32)set + *slot;
    }
    return 0;
}

/* Binds the entry's animation to a render object: init the animation object from model and texture, add it. */
u32 FIELD_GROUND_ANIME_AnmEntryBind(GroundAnmEntry *entry, u32 fileRes, u32 texRes, u32 renderObj)
{
    u32 pResMdl;
    pResMdl = ModelSetGetFirstModel(NNS_G3dGetMdlSet(G3D_SYSTEM_GetResourceFile((void *)fileRes)));
    if (texRes != 0)
        texRes = (u32)func_02047250((void *)texRes);
    else
        texRes = 0;
    MI_CpuFill8(entry->anmObj, 0, 0x80);
    NNS_G3dAnmObjInit(entry->anmObj, entry->pResAnm, pResMdl, texRes);
    NNS_G3dRenderObjAddAnmObj((void *)renderObj, entry->anmObj);
    entry->flags.word = (entry->flags.word & ~1) | 1;
    return entry->flags.word;
}

/*
 * Unbinds the entry: clears bit 0 of its flags.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_GROUND_ANIME_AnmEntryUnbind(GroundAnmEntry *entry)
{
    entry->flags.word &= ~1;
}

/* Wraps the shared frame counter into the entry's frame range and stores it as the animation frame. */
int FIELD_GROUND_ANIME_AnmEntryUpdate(GroundAnmEntry *entry, int frame)
{
    NNSG3dAnmObj *anmObj;
    if (entry->flags.bits.bound) {
        anmObj = entry->anmObj;
        frame = frame % (anmObj->pResAnm->numFrame << 12);
        anmObj->frame = frame;
    }
    return frame;
}

void FIELD_GROUND_ANIME_TexAnmSetInit(GroundTexAnmSet *set, u32 arcId, u32 memberId, void *modelRes, u16 heapId)
{
    u32 i;
    set->table = ARC_UTIL_LoadMember(arcId, memberId, 0, heapId);
    for (i = 0; i < set->table->count; i++)
        FIELD_GROUND_ANIME_TexAnmInit(&set->anms[i], set->table, i, modelRes, heapId);
}

void FIELD_GROUND_ANIME_TexAnmSetFree(GroundTexAnmSet *set)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (FIELD_GROUND_ANIME_TexAnmIsActive(&set->anms[i])) {
            FIELD_GROUND_ANIME_TexAnmFree(&set->anms[i]);
        }
    }
    if (set->table != 0) {
        func_020307B0(set->table);
        set->table = 0;
    }
}

void FIELD_GROUND_ANIME_TexAnmSetUpdate(GroundTexAnmSet *set, int dt)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (FIELD_GROUND_ANIME_TexAnmIsActive(&set->anms[i])) {
            FIELD_GROUND_ANIME_TexAnmUpdate(&set->anms[i], dt);
        }
    }
}

/*
 * Initialiser for the texture animation FIELD_GROUND_ANIME_TexAnmUpdate steps: allocates the
 * per-group arrays and seeds each group's current key and VRAM target.
 * The heap id is u16 in both this signature and func_02030734's: with u32
 * the stack-argument load drops from the first instruction to after the
 * register copies (docs/idioms/a-narrow-parameter-pins-its-home-store-to-
 * the-front-of-the-prologue.md, here for a load).
 */
void FIELD_GROUND_ANIME_TexAnmInit(GroundTexAnm *anm, GroundTexAnmTable *table, u32 index, void *modelRes, u16 heapId)
{
    u32 group;
    s32 frame;
    s32 lastKey;
    u8 minTexIndex;
    GroundTexKey key;

    anm->modelRes = modelRes;
    anm->keyData = (u32 *)FIELD_GROUND_ANIME_GetTexAnmKeyData(table, index);
    FIELD_GROUND_ANIME_KeyTableUnpack(anm->keyData, &anm->keyTable);
    anm->animRes = func_02030734(heapId, G3D_SYSTEM_GetResourceSize(), 1, &_FieldGroundAnimeFileName, 0x2c9);
    G3D_SYSTEM_InitResourceByFile(anm->animRes, (void *)FIELD_GROUND_ANIME_GetTexAnmFile(table, index));
    anm->groupCount = FIELD_GROUND_ANIME_KeyTableGetGroupCount(&anm->keyTable);
    anm->curKeys = func_02030734(heapId, anm->groupCount * 2, 1, &_FieldGroundAnimeFileName, 0x2d4);
    anm->vramOffsets = func_02030734(heapId, anm->groupCount * 4, 1, &_FieldGroundAnimeFileName, 0x2d5);
    anm->texSizes = func_02030734(heapId, anm->groupCount * 4, 1, &_FieldGroundAnimeFileName, 0x2d6);
    anm->times = func_02030734(heapId, anm->groupCount * 4, 1, &_FieldGroundAnimeFileName, 0x2d7);
    for (group = 0; group < anm->groupCount; group++) {
        anm->curKeys[group] = FIELD_GROUND_ANIME_KeyTableGetKey(&anm->keyTable, group, 0);
        lastKey = FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(&anm->keyTable, group);
        minTexIndex = anm->curKeys[group].texIndex;
        for (frame = 0; frame < lastKey; frame++) {
            key = FIELD_GROUND_ANIME_KeyTableGetKey(&anm->keyTable, group, frame);
            if (minTexIndex > key.texIndex) {
                minTexIndex = key.texIndex;
            }
        }
        anm->vramOffsets[group] = FIELD_GROUND_ANIME_GetModelTexVramOffset(modelRes, anm->animRes, minTexIndex);
        anm->texSizes[group] = FIELD_GROUND_ANIME_GetTexSize(anm->animRes, minTexIndex);
    }
    anm->needsFullUpload = 1;
}

void FIELD_GROUND_ANIME_TexAnmFree(GroundTexAnm *anm)
{
    if (anm->keyData != 0) {
        func_020307B0(anm->curKeys);
        func_020307B0(anm->vramOffsets);
        func_020307B0(anm->texSizes);
        func_020307B0(anm->times);
        func_020307B0(anm->animRes);
        anm->keyData = 0;
        anm->animRes = 0;
    }
}

/*
 * Addresses are Black-image addresses.
 * FIELD_GROUND_ANIME_KeyTableGetKey returns its two-byte GroundTexKey by value in r0 (see its matched
 * file): the call result is spilled to a compiler temporary at sp+0x14 and
 * copied into key at sp+0x16, and every later use reads key. An inline unpack
 * of a u16 return forwards the copy and reads the temporary instead.
 */
void FIELD_GROUND_ANIME_TexAnmUpdate(GroundTexAnm *anm, s32 dt)
{
    s32 limit;
    u32 group;
    GroundTexKey key;

    if (anm->keyData == 0)
        return;
    limit = FIELD_GROUND_ANIME_KeyTableGetDuration(&anm->keyTable) << 12;
    for (group = 0; group < anm->groupCount; group++) {
        anm->times[group] += dt;
        if (anm->times[group] >= limit) {
            anm->times[group] %= limit;
        } else if (anm->vramOffsets[group] != -1) {
            key = FIELD_GROUND_ANIME_KeyTableGetKey(&anm->keyTable, group, anm->times[group] >> 12);
            if (key.texIndex != anm->curKeys[group].texIndex || anm->needsFullUpload)
                func_02061CA4(0, anm->vramOffsets[group], (u32)FIELD_GROUND_ANIME_GetTexData(anm->animRes, key.texIndex), anm->texSizes[group]);
            anm->curKeys[group] = key;
        }
    }
    anm->needsFullUpload = 0;
}

/*
 * Addresses are Black-image addresses.
 */
int FIELD_GROUND_ANIME_TexAnmIsActive(GroundTexAnm *anm)
{
    if (anm->keyData != 0) {
        return 1;
    }
    return 0;
}

static inline void *DictGetByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHdr *hdr = (const DictEntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)hdr->data + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline void *DictGetNameByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHdr *hdr = (const DictEntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)hdr + hdr->ofsName + idx * 16);
    }
    return 0;
}

/*
 * Finds the model's texture with the same name as texture animTexIdx of the
 * animation file; returns its VRAM offset, or -1 when the model has none.
 */
int FIELD_GROUND_ANIME_GetModelTexVramOffset(void *modelRes, void *animRes, u32 animTexIdx)
{
    TexRes *modelTex;
    TexRes *animTex;
    void *texName;
    int modelTexIdx;
    u32 *texParam;

    modelTex = func_02047250(modelRes);
    animTex = func_02047250(animRes);
    texName = animTex ? DictGetNameByIdx(&animTex->dict, animTexIdx) : 0;
    if (modelTex) {
        modelTexIdx = NNS_G3dGetResDictIdxByName(&modelTex->dict, texName);
    } else {
        modelTexIdx = -1;
    }
    if (modelTexIdx < 0) {
        return -1;
    }
    texParam = modelTex ? DictGetByIdx(&modelTex->dict, modelTexIdx) : 0;
    return ((*texParam << 16) >> 13) + ((modelTex->vramKey << 16) >> 13);
}

/* Byte size of texture texIdx: width * height divided by the pixels per byte of its format. */
u32 FIELD_GROUND_ANIME_GetTexSize(void *animRes, u32 texIdx)
{
    TexRes *tex;
    u32 *texParam;
    u32 param;

    tex = func_02047250(animRes);
    texParam = tex ? DictGetByIdx(&tex->dict, texIdx) : 0;
    param = *texParam;
    return func_0209C2B0(gTexDimensionTable[(param & 0x700000) >> 20] * gTexDimensionTable[(param & 0x3800000) >> 23], gTexPixelsPerByteTable[(param & 0x1C000000) >> 26]);
}

/* Texel data of texture texIdx. */
u8 *FIELD_GROUND_ANIME_GetTexData(void *animRes, u32 texIdx)
{
    TexRes *tex;
    u32 *texParam;

    tex = func_02047250(animRes);
    texParam = tex ? DictGetByIdx(&tex->dict, texIdx) : 0;
    return (u8 *)tex + tex->ofsTex + ((*texParam & 0xFFFF) << 3);
}

/* Key data of table entry index. */
u32 FIELD_GROUND_ANIME_GetTexAnmKeyData(GroundTexAnmTable *table, u32 index)
{
    return (u32)table + table->entries[index].keyDataOfs;
}

/* Texture animation file of table entry index. */
u32 FIELD_GROUND_ANIME_GetTexAnmFile(GroundTexAnmTable *table, u32 index)
{
    return (u32)table + table->entries[index].animResOfs;
}

/*
 * Key of the group at the given frame: the last key whose frame is not after it.
 * Levers: the 2-byte struct returned by value (stack stores, reload of byte 0),
 * *(starts + group + 1) for the (starts + group)[1] address, and a const
 * GroundKeyTable pointer so the plttIndices load schedules above the first store.
 */
GroundTexKey FIELD_GROUND_ANIME_KeyTableGetKey(const GroundKeyTable *table, u32 group, u32 frame)
{
    GroundTexKey key;
    u8 *starts;
    u32 groupCount;
    u32 i;
    u32 end;

    starts = table->groupStarts;
    groupCount = table->groupCount;
    i = starts[group];
    if (group + 1 < groupCount)
        end = *(starts + group + 1);
    else
        end = table->keyCount;
    end = end - 1;
    for (; i < end; i++) {
        if (table->keyFrames[i + 1] > frame)
            break;
    }
    key.texIndex = table->texIndices[i];
    key.plttIndex = table->plttIndices[i];
    return key;
}

/* Number of groups (animated texture slots) in the table. */
u32 FIELD_GROUND_ANIME_KeyTableGetGroupCount(GroundKeyTable *table)
{
    return table->groupCount;
}

/* Duration of the animation in frames. */
u32 FIELD_GROUND_ANIME_KeyTableGetDuration(GroundKeyTable *table)
{
    return table->duration;
}

/* Frame number of the last key of the group. */
u16 FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(GroundKeyTable *table, int group)
{
    int end;
    if (group + 1 < table->groupCount) {
        end = *(table->groupStarts + group + 1);
    } else {
        end = table->keyCount;
    }
    return *(table->keyFrames + end - 1);
}

/*
 * Unpacks a key file: key count, frame numbers (u16), texture indices (u8),
 * palette indices (u8), group count, group start keys (u8), duration. Each
 * array is padded to 4 bytes.
 */
void FIELD_GROUND_ANIME_KeyTableUnpack(u32 *keyFile, GroundKeyTable *out)
{
    u32 count;
    u32 p;
    u32 pad;

    count = *keyFile;
    p = (u32)(keyFile + 1);
    out->keyCount = count;
    out->keyFrames = (u16 *)p;
    p += count * 2;
    pad = (count * 2) & 3;
    if (pad != 0) p += 4 - pad;
    out->texIndices = (u8 *)p;
    p += out->keyCount;
    pad = out->keyCount & 3;
    if (pad != 0) p += 4 - pad;
    out->plttIndices = (u8 *)p;
    p += out->keyCount;
    pad = out->keyCount & 3;
    if (pad != 0) p += 4 - pad;
    count = *(u32 *)p;
    p += 4;
    out->groupStarts = (u8 *)p;
    out->groupCount = count;
    p += count;
    pad = count & 3;
    if (pad != 0) p += 4 - pad;
    out->duration = *(u32 *)p;
}

/*
 * Tail-call thunk: forwards to func_021A811C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A7B08(void *fieldMap, VecFx32 *out)
{
    func_021A811C(fieldMap, out);
}

int func_021A7B10(void *a)
{
    return (int)FLDMMDL_FreeAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(a)));
}

void *func_021A7B20(GroundAnimeArgs *args)
{
    void *task;
    GroundAnimeWork *w;

    task = func_020122C0(args->gameSystem, 0, func_021A7CE8, 0x3C);
    w = func_020124E8(task);
    w->args = args;
    w->bgmInfo = (void *)func_02012A30(args->gameData);
    w->buildModel = 0;
    w->frameCounter = 0;
    w->playerMoveMode = func_021A80FC(args->fieldMap);
    w->stepIndex = 0;
    w->entrance = ENTRANCE_CAMERA_Create(args->fieldMap);
    w->entranceParam = args->enterEntranceParam;
    w->isEnter = 1;
    w->isExit = 0;
    func_021A810C(args->fieldMap, &w->entryPos);
    func_021A8214(w);
    func_021A7B88(w);
    return task;
}

/*
 * Fills the work's step table (bytes 0x2C..) from the mode the args' fieldMap
 * reports.
 */
void func_021A7B88(GroundAnimeWork *w)
{
    GroundAnimeArgs *args;
    void *fieldMap;

    args = w->args;
    fieldMap = args->fieldMap;
    if (func_021A8268(w) != 0) {
        switch (func_021A80FC(fieldMap)) {
        case 0:
        case 1:
        default:
            w->steps[0] = 0;
            w->steps[1] = 1;
            w->steps[2] = 5;
            w->steps[3] = 2;
            w->steps[4] = 3;
            w->steps[5] = 4;
            w->steps[6] = 6;
            w->steps[7] = 7;
            w->steps[8] = 8;
            return;
        case 2:
        case 3:
            w->steps[0] = 0;
            w->steps[1] = 1;
            w->steps[2] = 2;
            w->steps[3] = 3;
            w->steps[4] = 4;
            w->steps[5] = 5;
            w->steps[6] = 6;
            w->steps[7] = 7;
            w->steps[8] = 8;
            return;
        }
    } else if (EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(args->enterEntranceParam) != 0) {
        w->steps[0] = 0;
        w->steps[1] = 1;
        w->steps[2] = 4;
        w->steps[3] = 5;
        w->steps[4] = 8;
        return;
    } else {
        switch (func_021A80FC(fieldMap)) {
        case 0:
        case 1:
        default:
            w->steps[0] = 0;
            w->steps[1] = 1;
            w->steps[2] = 5;
            w->steps[3] = 4;
            w->steps[4] = 8;
            return;
        case 2:
        case 3:
            w->steps[0] = 0;
            w->steps[1] = 1;
            w->steps[2] = 4;
            w->steps[3] = 5;
            w->steps[4] = 8;
            return;
        }
    }
}

/*
 * Step machine "A" over work->steps: each state either stays or loads the
 * next step (GetNextStep) and advances the index (AdvanceStep). Returns 1
 * once the current step is GROUND_A_END and the field proc reports ready.
 */
int func_021A7CE8(void *task, int *state, GroundAnimeWork *work)
{
    GroundAnimeArgs *args;
    void *gameSystem;
    void *fieldMap;
    void *gameData;
    void *bgmInfo;
    void *camera;
    void *fieldProc;

    args = work->args;
    gameSystem = args->gameSystem;
    fieldMap = args->fieldMap;
    gameData = args->gameData;
    bgmInfo = work->bgmInfo;
    camera = FIELDMAP_GetCamera(fieldMap);
    fieldProc = FIELDMAP_GetTaskManager(fieldMap);
    FIELDMAP_GetZoneId(fieldMap);

    switch (*state) {
    case GROUND_A_LOCK_CAMERA:
        EVENT_MAPCHANGE_SetPlayerVanish(fieldMap, 1);
        if (FIELD_CAMERA_HasDelay(camera) == 0) {
            *state = func_021A81EC(work);
            func_021A8200(work);
        } else {
            FIELD_CAMERA_EndDelay(camera);
            *state = GROUND_A_WAIT_CAMERA;
        }
        break;
    case GROUND_A_WAIT_CAMERA:
        if (FIELD_CAMERA_IsDelayEnabled(camera) == 0) {
            *state = func_021A81EC(work);
            func_021A8200(work);
        }
        break;
    case GROUND_A_START_ENTRANCE:
        ENTRANCE_CAMERA_Setup(work->entrance, &work->entranceParam);
        FIELD_SOUND_SYSTEM_PostFadeIn(bgmInfo, gameData);
        func_021A82D8(task, work);
        *state = func_021A81EC(work);
        func_021A8200(work);
        break;
    case GROUND_A_PLAY_MODEL_FORWARD:
        func_021A8278(work);
        *state = func_021A81EC(work);
        func_021A8200(work);
        break;
    case GROUND_A_WAIT_MODEL_FORWARD:
        if (func_021A8244(work) == 1) {
            *state = func_021A81EC(work);
            func_021A8200(work);
        }
        break;
    case GROUND_A_START_PLAYER_ANIM:
        EVENT_MAPCHANGE_SetPlayerVanish(fieldMap, 0);
        GAME_EVENT_CallEvent(task, EVENT_FIELD_PROCLINK_StartObjAnim(gameSystem, fieldMap));
        if (ENTRANCE_CAMERA_IsActive(work->entrance) != 0 && ENTRANCE_CAMERA_IsInstant(work->entrance) != 0) {
            *state = GROUND_A_DELAY;
        } else {
            *state = func_021A81EC(work);
            func_021A8200(work);
        }
        break;
    case GROUND_A_PLAY_MODEL_REVERSE:
        func_021A82A8(work);
        *state = func_021A81EC(work);
        func_021A8200(work);
        break;
    case GROUND_A_DELAY:
        if (work->frameCounter++ > 15) {
            *state = func_021A81EC(work);
            func_021A8200(work);
        }
        break;
    case GROUND_A_FINISH_ENTRANCE:
        ENTRANCE_CAMERA_Start(work->entrance);
        *state = func_021A81EC(work);
        func_021A8200(work);
        break;
    case GROUND_A_WAIT_MODEL_REVERSE:
        if (func_021A8244(work) == 1) {
            *state = func_021A81EC(work);
            func_021A8200(work);
        }
        break;
    case GROUND_A_END:
        break;
    }

    if (func_021A81DC(work) == GROUND_A_END && FIELD_TASK_MANAGER_IsEmpty(fieldProc) != 0) {
        ENTRANCE_CAMERA_Restore(work->entrance);
        FIELD_CAMERA_ReloadSetting(camera);
        ENTRANCE_CAMERA_Delete(work->entrance);
        func_021A8234(work);
        return 1;
    }
    return 0;
}

/* Creates task "B" (callback FIELD_GROUND_ANIME_MainB) and fills its work. */
void *func_021A7E3C(GroundAnimeArgs *args)
{
    void *task;
    GroundAnimeWork *work;

    task = func_020122C0(args->gameSystem, 0, func_021A7F38, 0x3C);
    work = func_020124E8(task);
    work->args = args;
    work->bgmInfo = func_02012A30(args->gameData);
    work->buildModel = 0;
    work->frameCounter = 0;
    work->playerMoveMode = func_021A80FC(args->fieldMap);
    work->stepIndex = 0;
    work->entrance = ENTRANCE_CAMERA_Create(args->fieldMap);
    work->entranceParam = args->exitEntranceParam;
    work->isEnter = 0;
    work->isExit = 1;
    func_021A811C(args->fieldMap, &work->entryPos);
    func_021A8214(work);
    func_021A7EB4(work);
    if (EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(args->exitEntranceParam) != 0) {
        work->chainSteps = 1;
    } else {
        work->chainSteps = 0;
    }
    return task;
}

/* Fills the step list of task "B"; a build model adds the forward-anim step. */
void func_021A7EB4(GroundAnimeWork *work)
{
    if (func_021A8268(work) != 0) {
        work->steps[0] = 0;
        work->steps[1] = 3;
        work->steps[2] = 1;
        work->steps[3] = 2;
        work->steps[4] = 5;
        work->steps[5] = 6;
        work->steps[6] = 7;
        work->steps[7] = 8;
    } else {
        work->steps[0] = 0;
        work->steps[1] = 1;
        work->steps[2] = 2;
        work->steps[3] = 5;
        work->steps[4] = 6;
        work->steps[5] = 7;
        work->steps[6] = 8;
    }
}

/*
 * Task callback installed by FIELD_GROUND_ANIME_CreateB: steps through
 * work->steps like MainA, returning 0x21 to run again in the same frame when
 * work->chainSteps is set, 1 when the last step finishes, 0 otherwise.
 */
int func_021A7F38(void *task, int *state, GroundAnimeWork *work)
{
    GroundAnimeArgs *args;
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    void *bgmInfo;
    void *fieldProc;

    args = work->args;
    gameSystem = args->gameSystem;
    gameData = args->gameData;
    fieldMap = args->fieldMap;
    bgmInfo = work->bgmInfo;
    fieldProc = FIELDMAP_GetTaskManager(fieldMap);

    switch (*state) {
    case GROUND_B_START_ENTRANCE:
        ENTRANCE_CAMERA_Setup(work->entrance, &work->entranceParam);
        *state = func_021A81EC(work);
        func_021A8200(work);
        if (work->chainSteps != 0) {
            return 0x21;
        }
        break;
    case GROUND_B_FINISH_ENTRANCE:
        ENTRANCE_CAMERA_Start(work->entrance);
        *state = func_021A81EC(work);
        func_021A8200(work);
        if (work->chainSteps != 0) {
            return 0x21;
        }
        break;
    case GROUND_B_PLAY_MODEL_FORWARD:
        func_021A8278(work);
        *state = func_021A81EC(work);
        func_021A8200(work);
        if (work->chainSteps != 0) {
            return 0x21;
        }
        break;
    case GROUND_B_WAIT_FIELD:
        if (FIELD_TASK_MANAGER_IsEmpty(fieldProc) == 0) {
            break;
        }
        if (ENTRANCE_CAMERA_IsActive(work->entrance) != 0 && ENTRANCE_CAMERA_IsInstant(work->entrance) != 0) {
            *state = GROUND_B_DELAY;
        } else {
            *state = func_021A81EC(work);
            func_021A8200(work);
        }
        if (work->chainSteps != 0) {
            return 0x21;
        }
        break;
    case GROUND_B_WAIT_MODEL:
        if (func_021A8244(work) == 1) {
            *state = func_021A81EC(work);
            func_021A8200(work);
            if (work->chainSteps != 0) {
                return 0x21;
            }
        }
        break;
    case GROUND_B_DELAY:
        if (work->frameCounter++ > 15) {
            *state = func_021A81EC(work);
            func_021A8200(work);
            if (work->chainSteps != 0) {
                return 0x21;
            }
        }
        break;
    case GROUND_B_START_PLAYER_ANIM:
        func_021A7B10(fieldMap);
        GAME_EVENT_CallEvent(task, EVENT_FIELD_PROCLINK_StartObjAnim(gameSystem, fieldMap));
        *state = func_021A81EC(work);
        func_021A8200(work);
        if (work->chainSteps != 0) {
            return 0x21;
        }
        break;
    case GROUND_B_REPLACE_BGM:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(bgmInfo, gameData, args->zoneId, args->bgmReplaceFlag);
        args->finished = 1;
        *state = func_021A81EC(work);
        func_021A8200(work);
        break;
    case GROUND_B_ENTER_EVENT:
        if (func_021A834C(work) != 0) {
            GFL_USE_PlaySeDefaultVolume(SE_GROUND_ANIME_DOOR);
        }
        func_021A8324(task, work);
        *state = func_021A81EC(work);
        func_021A8200(work);
        break;
    case GROUND_B_END:
        ENTRANCE_CAMERA_Restore(work->entrance);
        ENTRANCE_CAMERA_Delete(work->entrance);
        func_021A8234(work);
        return 1;
    }
    return 0;
}

/* Movement mode of the player object (grid or rail), as a byte. */
int func_021A80FC(void *fieldMap)
{
    return (u8)FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer(fieldMap));
}

/* Position of the player object. */
void func_021A810C(void *fieldMap, VecFx32 *out)
{
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), out);
}

/* Position where the ground animation plays: rail maps and grid maps differ. */
void func_021A811C(void *fieldMap, VecFx32 *out)
{
    if (FIELDMAP_GetMoveKind(fieldMap) == 1) {
        func_021A8198(fieldMap, out);
        return;
    }
    func_021A8140(fieldMap, out);
}

/* Grid map: the tile in front of the player, with its map height. */
void func_021A8140(void *fieldMap, VecFx32 *out)
{
    void *player;
    int moveMode;
    VecFx32 playerPos;
    VecFx32 frontPos;
    VecFx32 entryPos;
    int height;

    player = FIELDMAP_GetFieldPlayer(fieldMap);
    moveMode = FIELD_PLAYER_GetDirDisp(player);
    FIELD_PLAYER_GetPos(player, &playerPos);
    FIELD_PLAYER_GetMoveOffsetInDir(player, moveMode, &frontPos);
    func_0207CEE4(0x10000, &frontPos, &playerPos, &entryPos);
    FLDMMDL_MOVE_GetMapHeight(FIELD_PLAYER_GetMmdl(player), &entryPos, &height);
    entryPos.y = height;
    *out = entryPos;
}

/* Rail map: the rail position in front of the player converted to world coordinates. */
void func_021A8198(void *fieldMap, VecFx32 *out)
{
    void *player;
    int moveMode;
    void *rail;
    VecFx32 worldPos;
    int railPos[2];

    player = FIELDMAP_GetFieldPlayer(fieldMap);
    moveMode = FIELD_PLAYER_GetDirDisp(player);
    rail = FIELD_NOGRID_MAPPER_GetRailMan(FIELDMAP_GetNogridMapper(fieldMap));
    FIELD_PLAYER_GetNogridLocationByDir(player, moveMode, railPos);
    FIELD_RAIL_GetLocationPos(rail, railPos, &worldPos);
    *out = worldPos;
}

/* Step id the machine is running now. */
u8 func_021A81DC(GroundAnimeWork *work)
{
    return work->steps[work->stepIndex];
}

/* Step id after the current one (steps[stepIndex + 1]). */
u8 func_021A81EC(GroundAnimeWork *work)
{
    return work->steps[(u8)(work->stepIndex + 1)];
}

/* Moves to the next step and clears the frame counter. */
void func_021A8200(GroundAnimeWork *work)
{
    work->stepIndex++;
    work->frameCounter = 0;
}

/* Creates the build model (door or ground object) at the entry position. */
void func_021A8214(GroundAnimeWork *work)
{
    work->buildModel = FIELD_BUILDMODEL_CreateNodeNearPos(FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(work->args->fieldMap)), 1, &work->entryPos);
}

void func_021A8234(GroundAnimeWork *work)
{
    if (work->buildModel != 0) {
        FIELD_BUILDMODEL_DeleteNode(work->buildModel);
    }
}

/* 1 when there is no build model, or its animation has ended. */
int func_021A8244(GroundAnimeWork *work)
{
    if (func_021A8268(work) == 0) {
        return 1;
    }
    if (FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(work->buildModel) != 0) {
        return 1;
    }
    return 0;
}

int func_021A8268(GroundAnimeWork *work)
{
    if (work->buildModel != 0) {
        return 1;
    }
    return 0;
}

/* Starts the build model animation forward and plays its sound. */
void func_021A8278(GroundAnimeWork *work)
{
    u16 seId;
    if (func_021A8268(work)) {
        FIELD_BUILDMODEL_PlayNodeSlot(work->buildModel, 0, 0);
        if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(work->buildModel, &seId)) {
            GFL_USE_PlaySeDefaultVolume(seId);
        }
    }
}

/* Starts the build model animation in reverse and plays its sound. */
void func_021A82A8(GroundAnimeWork *work)
{
    u16 seId;
    if (func_021A8268(work)) {
        FIELD_BUILDMODEL_PlayNodeSlot(work->buildModel, 1, 0);
        if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(work->buildModel, &seId)) {
            GFL_USE_PlaySeDefaultVolume(seId);
        }
    }
}

/* Calls the enter event; a fixed selector overrides the caller's one. */
void func_021A82D8(void *task, GroundAnimeWork *work)
{
    GroundAnimeArgs *args;
    void *event;

    args = work->args;
    if (args->useFixedSelector != 0) {
        event = EVENT_FIELDMAP_CONTROL_StartFadeIn(args->gameSystem, args->fieldMap, 3, 0, 0, args->enterWarpFlag, args->bgmReplaceFlag);
    } else {
        event = EVENT_FIELDMAP_CONTROL_StartFadeIn(args->gameSystem, args->fieldMap, args->enterSelector, 0, 1, 0, 0);
    }
    GAME_EVENT_CallEvent(task, event);
}

/* Calls the exit event; a fixed selector overrides the caller's one. */
void func_021A8324(void *task, GroundAnimeWork *work)
{
    GroundAnimeArgs *args = work->args;
    void *event;
    if (args->useFixedSelector != 0) {
        event = EVENT_FIELDMAP_CONTROL_StartFadeOut(args->gameSystem, args->fieldMap, 0, 0);
    } else {
        event = EVENT_FIELDMAP_CONTROL_StartFadeOut(args->gameSystem, args->fieldMap, args->exitSelector, 0);
    }
    GAME_EVENT_CallEvent(task, event);
}

/* 1 when the door sound still has to be played: no build model, selector is not 2. */
int func_021A834C(GroundAnimeWork *work)
{
    GroundAnimeArgs *args = work->args;
    if (func_021A8268(work)) {
        return 0;
    }
    if (args->exitSelector != 2) {
        return 1;
    }
    return 0;
}
