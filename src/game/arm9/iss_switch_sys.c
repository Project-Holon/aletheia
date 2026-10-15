/*
 * file:     iss_switch_sys.c
 * unit:     yes
 * function: ISS_SWITCH_SYS_Create, ISS_SWITCH_SYS_Delete, ISS_SWITCH_SYS_Main, ISS_SWITCH_SYS_On, ISS_SWITCH_SYS_Off, ISS_SWITCH_SYS_ZoneChange, ISS_SWITCH_SYS_SwitchOn, ISS_SWITCH_SYS_SwitchOff, ISS_SWITCH_SYS_IsSwitchOn, ISS_SWITCH_SYS_ResetSwitch, ISS_SWITCH_SYS_Init, ISS_SWITCH_SYS_Alloc, ISS_SWITCH_SYS_Free, ISS_SWITCH_SYS_CreateSets, ISS_SWITCH_SYS_DeleteSets, ISS_SWITCH_SYS_UpdateActiveSet, ISS_SWITCH_SYS_TurnOn, ISS_SWITCH_SYS_TurnOff, ISS_SWITCH_SYS_CheckZoneChange, ISS_SWITCH_SYS_GetSetCount, ISS_SWITCH_SYS_GetSet, ISS_SWITCH_SYS_GetActiveSet, ISS_SWITCH_SYS_IsActiveSetZone, ISS_SWITCH_SYS_FindSetByBgm, ISS_SWITCH_SYS_ChangeActiveSet, ISS_SWITCH_SYS_UpdateVolume, ISS_SWITCH_SYS_GetPlayingBgm, ISS_SWITCH_SYS_IsOn, ISS_SWITCH_SYS_ResetActiveSet, ISS_SWITCH_SET_Create, ISS_SWITCH_SET_Delete, ISS_SWITCH_SET_Load, ISS_SWITCH_SET_Main, ISS_SWITCH_SET_SwitchOn, ISS_SWITCH_SET_SwitchOff, ISS_SWITCH_SET_ResetSwitch, ISS_SWITCH_SET_GetBgmNo, ISS_SWITCH_SET_IsValidZone, ISS_SWITCH_SET_IsSwitchOn, ISS_SWITCH_SET_UpdateVolume, ISS_SWITCH_SET_Init, ISS_SWITCH_SET_Alloc, ISS_SWITCH_SET_Free, ISS_SWITCH_SET_CreateSwitches, ISS_SWITCH_SET_DeleteSwitches, ISS_SWITCH_SET_LoadData, ISS_SWITCH_SET_UpdateSwitches, ISS_SWITCH_SET_StartSwitchOn, ISS_SWITCH_SET_StartSwitchOff, ISS_SWITCH_SET_ResetSwitches, ISS_SWITCH_SET_ReadBgmNo, ISS_SWITCH_SET_GetZoneCount, ISS_SWITCH_SET_GetZone, ISS_SWITCH_SET_CheckZone, ISS_SWITCH_SET_CheckSwitchOn, ISS_SWITCH_SET_GetSwitch, ISS_SWITCH_SET_ApplySwitchVolumes, ISS_SWITCH_Create, ISS_SWITCH_Delete, ISS_SWITCH_Setup, ISS_SWITCH_IsOn, ISS_SWITCH_On, ISS_SWITCH_Off, ISS_SWITCH_ForceOn, ISS_SWITCH_ForceOff, ISS_SWITCH_Main, ISS_SWITCH_SetVolume, ISS_SWITCH_Alloc, ISS_SWITCH_Free, ISS_SWITCH_Init, ISS_SWITCH_SetParam, ISS_SWITCH_CountUpFade, ISS_SWITCH_IsFadeEnd, ISS_SWITCH_Update, ISS_SWITCH_UpdateOn, ISS_SWITCH_UpdateOff, ISS_SWITCH_UpdateFadeIn, ISS_SWITCH_UpdateFadeOut, ISS_SWITCH_StartFadeIn, ISS_SWITCH_StartFadeOut, ISS_SWITCH_SetOnState, ISS_SWITCH_SetOffState, ISS_SWITCH_GetState, ISS_SWITCH_SetState, ISS_SWITCH_GetVolume, ISS_SWITCH_ApplyVolume, ISS_SWITCH_IsOnState, ISS_SWITCH_IsOffState, func_0202C794, func_0202C824, func_0202C83C, func_0202C860, func_0202C8B8, func_0202C934, func_0202C970, BGWINFRM_Create, BGWINFRM_Delete, BGWINFRM_AddFrame, BGWINFRM_SetFrameData, BGWINFRM_SetFrameDataArc, BGWINFRM_SetFrameDataArcHandle, BGWINFRM_PutFrame, BGWINFRM_ShowFrame, BGWINFRM_HideFrame, BGWINFRM_StartMove, BGWINFRM_UpdateMoves, BGWINFRM_UpdateMove, BGWINFRM_IsMoving, BGWINFRM_ChangePalette, BGWINFRM_PutBmpWin, BGWINFRM_GetFrameBuffer, BGWINFRM_GetBgFrame, BGWINFRM_GetPos, BGWINFRM_GetSize, BGWINFRM_SetClipArea, func_0202D018, func_0202D01C, func_0202D034, POKEGRA_GetArcID, POKEGRA_GetCgrArcIndex, POKEGRA_GetCbrArcIndex, POKEGRA_GetPalArcIndex, POKEGRA_GetCelArcIndex, POKEGRA_GetAnmArcIndex, POKEGRA_GetMCelArcIndex, POKEGRA_GetMAnmArcIndex, POKEGRA_GetNcecArcIndex, POKEGRA_ConvertCharTo2D, POKEGRA_ConvertCharTo1D, POKEGRA_DrawSpindaSpots, POKEGRA_CalcArcIndex, POKEGRA_GetTrainerArcID, POKEGRA_GetTrainerCgrArcIndex, POKEGRA_GetTrainerCbrArcIndex, POKEGRA_GetTrainerPalArcIndex, POKEGRA_GetTrainerCelArcIndex, POKEGRA_GetTrainerAnmArcIndex, POKEGRA_GetTrainerMCelArcIndex, POKEGRA_GetTrainerMAnmArcIndex, POKEGRA_GetTrainerNcecArcIndex, POKEGRA_LoadCharDataPP, POKEGRA_LoadCharData, POKEGRA_OpenHandle, POKEGRA_RegisterPalette, POKEGRA_RegisterCgr, POKEGRA_RegisterCellAnim, POKEGRA_RegisterPalettePP, POKEGRA_RegisterCgrPP, POKEGRA_RegisterCellAnimPP, POKEGRA_OpenTrainerHandle, POKEGRA_RegisterTrainerPalette, POKEGRA_RegisterTrainerCgr, POKEGRA_RegisterTrainerCellAnim, POKEGRA_LoadTrainerGraphics, PMS_DRAW_Create, PMS_DRAW_Main, PMS_DRAW_Delete, PMS_DRAW_Print, PMS_DRAW_PrintOffset, PMS_DRAW_IsPrintEnd, PMS_DRAW_Clear, PMS_DRAW_SetVisible, PMS_DRAW_IsActive, PMS_DRAW_SetDecoVisible, PMS_DRAW_SetDecoPriority, PMS_DRAW_Copy, PMS_DRAW_SetNullColorPalette, PMS_DRAW_SetPrintColor, PMS_DRAW_SetFollowBgScroll, PMS_DRAW_CalcDecoPos, PMS_DRAW_GetDecoCgrIndex, PMS_DRAW_GetDecoCelIndex, PMS_DRAW_GetDecoAnmIndex, PMS_DRAW_LoadResources, PMS_DRAW_ReleaseResources, PMS_DRAW_CreateDecoActor, PMS_DRAW_PlaceDecoActor, PMS_DRAW_InitElem, PMS_DRAW_DeleteElem, PMS_DRAW_UpdateElem, PMS_DRAW_PrintElem, PMS_DRAW_ClearElem, PMS_DRAW_SetElemVisible, PMS_DRAW_GetFrameSurface, func_0202E43C, func_0202E448, BAG_PARAM_Create
 * address:  0x0202C070
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by hand from the verified parts of tools/restructure.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   IssSwitchSysFileName     0x020A7758  data
 *   func_020307B0  0x020307B0  arm
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   IssSwitchSetFileName     0x020A776C  data
 *   FSi_ConvertStringSjisToUnicode  0x02048F74  arm
 *   IssSwitchFileName      0x020A7780  data
 *   _s32_div_f    0x0209C0A4  arm
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetMusicalWork  0x0201297C  thumb
 *   MOVE_POKEMON_FindEntryByZone  0x0215E6A8  thumb
 *   CALENDER_GetWeatherThunk  0x021647E8  thumb  ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   MOVE_POKEMON_IsAnyEntryActive  0x0215E6F8  thumb ov010
 *   GAME_DATA_GetSubscreenMode  0x02012994  thumb
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   INTRUDE_COMM_GetAreaOwnerVersion  0x0215843C  thumb
 *   gTbl_0209FFF4  0x0209FFF4  data
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   ZONEDATA_IsRawZone176Or17A   0x02014044  thumb
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   func_0202EB60   0x0202EB60  thumb
 *   BgWinFrmFileName  0x020A7790  data
 *   MIi_CpuCopy16  0x02082A60  arm
 *   ARC_UTIL_LoadPaletteDataFromArchive       0x02049EB4  arm
 *   func_02049EF4       0x02049EF4  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BgWinFrmScreenTransFuncs     0x020A0058  data
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BMP_WIN_GetCharOffset  0x02045768  arm
 *   BMP_WIN_GetPalette  0x02045778  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   PokegraFileName    0x020A77AC  data
 *   MIi_CpuCopyFast 0x02082B0C  arm
 *   SpindaSpotTables  0x020A779C  data
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   TrainerGraIndexTable  0x020A023C  data
 *   func_02017E88   0x02017E88  thumb
 *   POKE_TOOL_IsBoxShiny   0x02017EB4  thumb
 *   func_02049E34   0x02049E34  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter   0x0204A6C8  arm
 *   CLACT_TransferCharacter   0x0204A9D0  arm
 *   func_02027710   0x02027710  thumb
 *   func_02027714   0x02027714  thumb
 *   func_020275E4   0x020275E4  thumb
 *   func_020490F4   0x020490F4  arm
 *   CLACT_RegisterCellAnim   0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle   0x02049238  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   func_02049E74  0x02049E74  arm
 *   CLACT_TransferPalette  0x0204ADEC  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   PmsDrawFileName   0x020A77B8  data  a1
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_CopyPixels  0x02043814  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   func_02035630  0x02035630  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   BG_SYS_Get  0x020416D4  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BG_SYS_GetScrollX_1648  0x02041648  arm
 *   BG_SYS_GetScrollY_1664  0x02041664  arm
 *   CLACT_GetActorPos  0x0204B53C  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   PMSI_PARAM_Validate  0x0202465C  thumb
 *   PMSI_PARAM_GetSourceString  0x0202441C  thumb
 *   GF_FONT_CountControlTag  0x0201D478  thumb
 *   PMSI_PARAM_IsDecoWordAt  0x020244F8  thumb
 *   PMSI_PARAM_GetWordId  0x020244D4  thumb
 *   PMSI_PARAM_ToStringWords  0x02024368  thumb
 *   GF_FONT_MeasureText  0x0201D528  thumb
 *   GF_FONT_SearchIndex  0x0201D4BC  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_020409B4  0x020409B4  arm
 *   ItemValueTable  0x020A02A8  data
 *   BagParamFileName  0x020A77C4  data
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 */

struct IssSwitchSys;
struct IssSwitchSet;
struct IssSwitchSet;
struct IssSwitchSet;
struct IssSwitchSet;
struct IssSwitchSet;
struct IssSwitch;
struct IssSwitch;
struct BigObj;
struct Ctx;
struct Descriptor;
struct NNSG2dCharacterData;
struct Sub0204A9D0;
struct ArcFile;
struct NitroFileHeader;
struct PmsDrawRes;
struct Actor;
struct PmsDraw;
struct PmsElem;
struct Cfg;
struct Bmp;
struct PtS;
struct Vec2;
struct PmsPos;
struct PrintSys;
struct Container;
struct PmsPos;
struct Rec8;
struct Struct_0202441C;
struct T;
struct CharBuf;
struct U16Vec;
struct Big;
struct SaveBlock;
struct Sub02008700Obj;
struct Rec44;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

struct IssSwitchSys {
    u32 isOn;
    u8  setCount;
    u8  pad_05[3];
    struct IssSwitchSet **sets;
    struct IssSwitchSet *activeSet;
};

struct IssSwitchSet {
    u32 bgmNo;
    u16 zones[9];
    u8  zoneCount;
    u8  pad_17;
    struct IssSwitch *switches[9];
};

typedef signed int s32;

struct IssSwitch {
    u32 state;
    u16 fadeCount;
    u16 fadeFrames;
    u16 trackBits;
    u8  pad_0A[2];
};





struct Pair {
    u16 a;
    u16 b;
};

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

typedef signed char    s8;

struct BgWinFrame {
    u16 *screen;
    u16 sizeX:6;
    u16 sizeY:6;
    u16 hidden:1;
    u16 moveFlag:3;
    s8 x;
    s8 y;
    s8 moveX;
    s8 moveY;
    u8 bgFrame;
    u8 moveCount;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct BgWinFrmWork {
    struct BgWinFrame *frames;
    u16 frameMax;
    u16 transMode : 15;
    u16 moving : 1;
    u32 heapId;
};

/* NitroSystem character data header (the real NNS layout). */
struct NNSG2dCharacterData {
    u16 H;
    u16 W;
    u32 pixelFmt;
    u32 mapingType;
    u32 characterFmt;
    u32 szByte;
    void *pRawData;
};

typedef enum { POKEGRA_DIR_OFFSET_FRONT } PokegraDirOffset;

struct PmsFlagBits {
    u32 active : 1;
    u32 visible : 1;
    u32 decoVisible : 1;
    u32 rest : 29;
};

union PmsFlags {
    u32 word;
    struct PmsFlagBits bits;
};

struct PmsElem {
    void *bmpWin;
    u8    printing;
    u8    pad05[3];
    struct Actor *decoActor[2];
    s32   scrollX;
    s32   scrollY;
    union PmsFlags flags;
    u32   reserved1C;
    u32   isDeco[2];
};

struct PmsDraw {
    u16   heapId;
    u8    pad02[2];
    u32   font;
    void *printQue;
    struct PmsElem *elems;
    u32   res[5];      /* struct PmsDrawRes, kept as words: DB0C and DF68 index it */
    u16   printColor;
    u8    pad26[2];
    u32   printEnd;
    u32   followBgScroll;
    u8    elemMax;
    u8    nullColorPalette;
};

typedef signed short   s16;

struct PmsPoint { s16 x; s16 y; };

struct PmsPos {
    u32 x;
    u32 y;
};

typedef volatile unsigned int vu32;

struct BagParam {
    void *gameData;
    void *myStatus;
    void *myItem;
    u32   saveWork;
    void *config;
    u8    itemCheck[0x18];
    int   mode;
    int   cycleFlag;
};

struct DecoActorInit { u16 x; u16 y; u16 anmSeq; u16 softPri; };

struct PmsDrawRes {
    u32 clunit;
    u32 drawType;
    u32 plttIndex;
    u32 cgrIndex;
    u32 cellAnmIndex;
};



struct DecoPos  { u16 x; u16 y; };



typedef struct { u16 sentenceType; u16 sentenceId; u16 word[2]; } PmsData;

typedef struct { s32 x; s32 y; } PmsOffset;

struct ItemValueEntry {
    u16 itemId : 10;
    u16 value  : 6;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
extern u16 GFL_USE_GetBgmNo(void);
extern u32 FSi_ConvertStringSjisToUnicode(void *dst, u32 term, void *src,
                                           u32 srcOffset, u32 dstSize);
extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u32 GAME_DATA_GetMusicalWork(const struct BigObj *p);
extern u32 MOVE_POKEMON_FindEntryByZone(void *a, u16 b);
extern u32 CALENDER_GetWeatherThunk(void *arg, unsigned int b);
extern u32 ZONEDATA_GetWeatherId(u32 id);
extern void GAME_DATA_SetSubscreenMode(struct BigObj *p, u8 v);
extern int MOVE_POKEMON_IsAnyEntryActive(int a0);
extern u8 GAME_DATA_GetSubscreenMode(const struct BigObj *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ICA_ANIME_GetField24(const struct Ctx *p);
extern int ZONEDATA_IsZoneGroup118To13C(u32 key);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern s32 INTRUDE_COMM_GetAreaOwnerVersion(u32 a);
extern u32 GPOWER_GetSpecialPowerId(void);
extern u32 ZONEDATA_IsRawZone176Or17A(u32 id);
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern void func_0202EB60(u8 *out1, u8 *out2);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049EF4(void *arc, u32 member, u32 alloc, void **out,
                           u16 heap);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, const u16 *a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);
extern void (*BgWinFrmScreenTransFuncs[])(u32);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);
extern u8 BMP_WIN_GetPalette(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern void  MIi_CpuCopyFast(void *dst, const void *src, u32 size);
extern u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k);
extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern u32 func_02017E88(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_IsBoxShiny(void *mon);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 CLACT_RegisterPaletteEx(void *h, u32 a1, u32 engine, u32 a3, u32 s0, u32 s1, u32 s2);
extern u32 CLACT_RegisterCharacter(void *h, u32 a1, u32 a2, u32 engine, u32 s0);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_02027710(int a);
extern int func_02027714(int a);
extern u32   func_020275E4(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void  ARC_TOOL_DeleteHandle(void *h);
extern int func_02027718(int a);
extern int func_0202771C(int a);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void  CLACT_TransferPalette(void *dst, void *src, u32 flag);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
extern void  MI_CpuFill8(void *p, u32 v, u32 n);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 val);
extern void *BMP_WIN_GetBmp(struct Descriptor *h);
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Actor *p, const struct Vec2 *delta, u32 which);
extern u16 CLACT_GetActorAnimSeq(struct Actor *p);
extern void CLACT_SetActorAnimSeq(struct Actor *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Actor *p, u32 v);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern struct Actor *CLACT_CreateActor(void *a, u32 b, u32 c, u32 d,
                                const void *e, u16 f, u16 g);
extern void CLACT_SetActorAutoAnim(struct Actor *p, u32 v);
extern u8 func_02035630(void);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern u8 BG_SYS_Get(u32 layer);
extern void  CLACT_SetActorBgPriority(void *h, u32 a);
extern void CLACT_DeleteActor(struct Actor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern u32 BG_SYS_GetScrollX_1648(u8 channel);
extern u32 BG_SYS_GetScrollY_1664(u8 channel);
extern void CLACT_GetActorPos(const struct Actor *actor, struct PmsPoint *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct PmsPoint *src);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern u32 PMSI_PARAM_Validate(struct T *p, u32 a1, u32 a2);
extern void *PMSI_PARAM_GetSourceString(const struct Struct_0202441C *obj, u32 heapId);
extern u32   GF_FONT_CountControlTag(void *str);
extern u32 PMSI_PARAM_IsDecoWordAt(struct Container *p, u32 idx);
extern u16 PMSI_PARAM_GetWordId(void *obj, u32 idx);
extern void *PMSI_PARAM_ToStringWords(u16 *slots, u32 heap, int count);
extern u32 GF_FONT_MeasureText(void *s, u8 b, void *c, u32 d);
extern u32   GF_FONT_SearchIndex(void *s, u8 idx);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void  BMP_FillRect(u32 a, u32 b, s16 c, u32 d, u32 e, u8 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 *func_02012944(void *p);
extern unsigned int GAME_DATA_GetMapMatrix(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void  MI_CpuCopy8(void *src, void *dst, int n);
extern void *GAME_DATA_GetField114(struct SaveBlock *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
u8 *ISS_SWITCH_SYS_Create(u16 heapId);
void ISS_SWITCH_SYS_Delete(u8 *sys);
void ISS_SWITCH_SYS_Main(u8 *sys);
void ISS_SWITCH_SYS_On(u8 *sys);
void ISS_SWITCH_SYS_Off(u32 *sys);
void ISS_SWITCH_SYS_ZoneChange(u32 *sys, u32 zoneId);
void ISS_SWITCH_SYS_SwitchOn(u8 *sys, u32 switchIdx);
void ISS_SWITCH_SYS_SwitchOff(u8 *sys, u32 switchIdx);
u32 ISS_SWITCH_SYS_IsSwitchOn(struct IssSwitchSys *sys, u32 switchIdx);
void ISS_SWITCH_SYS_ResetSwitch(void *sys);
void ISS_SWITCH_SYS_Init(void *obj);
void *ISS_SWITCH_SYS_Alloc(u32 heapId);
void ISS_SWITCH_SYS_Free(void *sys);
void ISS_SWITCH_SYS_CreateSets(u8 *p, u16 heapId);
void ISS_SWITCH_SYS_DeleteSets(u8 *p);
u32 ISS_SWITCH_SYS_UpdateActiveSet(struct IssSwitchSys *sys);
void ISS_SWITCH_SYS_TurnOn(u8 *p);
void ISS_SWITCH_SYS_TurnOff(u32 *sys);
void ISS_SWITCH_SYS_CheckZoneChange(u32 *sys, u32 zoneId);
u32 ISS_SWITCH_SYS_GetSetCount(void *sys);
u32 ISS_SWITCH_SYS_GetSet(struct IssSwitchSys *sys, u32 idx);
u32 ISS_SWITCH_SYS_GetActiveSet(struct IssSwitchSys *sys);
u32 ISS_SWITCH_SYS_IsActiveSetZone(u32 *sys, u32 zoneId);
u32 ISS_SWITCH_SYS_FindSetByBgm(u8 *sys, u32 bgmNo);
int ISS_SWITCH_SYS_ChangeActiveSet(u32 *p, u32 bgmNo);
void ISS_SWITCH_SYS_UpdateVolume(void *sys);
u32 ISS_SWITCH_SYS_GetPlayingBgm(u32 unused);
u32 ISS_SWITCH_SYS_IsOn(u32 *sys);
void ISS_SWITCH_SYS_ResetActiveSet(void *sys);
u32 ISS_SWITCH_SET_Create(void *heapId);
void ISS_SWITCH_SET_Delete(void *set);
u32 ISS_SWITCH_SET_Load(void *set, u32 datId, u32 heapId);
u32 ISS_SWITCH_SET_Main(void *set);
u32 ISS_SWITCH_SET_SwitchOn(void *set, u32 switchIdx);
u32 ISS_SWITCH_SET_SwitchOff(void *set, u32 switchIdx);
void ISS_SWITCH_SET_ResetSwitch(void *set);
u32 ISS_SWITCH_SET_GetBgmNo(void *set);
u32 ISS_SWITCH_SET_IsValidZone(void *set, void *zoneId);
u32 ISS_SWITCH_SET_IsSwitchOn(void *set, u32 switchIdx);
void ISS_SWITCH_SET_UpdateVolume(void *set);
void ISS_SWITCH_SET_Init(struct IssSwitchSet *set);
void *ISS_SWITCH_SET_Alloc(void *heapId);
u32 ISS_SWITCH_SET_Free(void *set);
void ISS_SWITCH_SET_CreateSwitches(char *p, int heapId);
void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, void *datId);
u32 ISS_SWITCH_SET_UpdateSwitches(void *set);
u32 ISS_SWITCH_SET_StartSwitchOn(void *set, u32 switchIdx);
u32 ISS_SWITCH_SET_StartSwitchOff(void *set, u32 switchIdx);
void ISS_SWITCH_SET_ResetSwitches(void *set);
u32 ISS_SWITCH_SET_ReadBgmNo(u32 *set);
u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx);
u32 ISS_SWITCH_SET_CheckZone(void *set, u32 zoneId);
u32 ISS_SWITCH_SET_CheckSwitchOn(void *set, u32 switchIdx);
u32 ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx);
void ISS_SWITCH_SET_ApplySwitchVolumes(void *set);
void *ISS_SWITCH_Create(u32 heapId);
u32 ISS_SWITCH_Delete(void *sw);
u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits);
u32 ISS_SWITCH_IsOn(void *sw);
u32 ISS_SWITCH_On(void *sw);
u32 ISS_SWITCH_Off(void *sw);
u32 ISS_SWITCH_ForceOn(void *sw);
u32 ISS_SWITCH_ForceOff(void *sw);
void ISS_SWITCH_Main(void *sw);
void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume);
void *ISS_SWITCH_Alloc(u32 heapId);
u32 ISS_SWITCH_Free(void *sw);
void ISS_SWITCH_Init(struct IssSwitch *sw);
u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits);
void ISS_SWITCH_CountUpFade(struct IssSwitch *sw);
u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw);
void ISS_SWITCH_Update(void *sw);
void ISS_SWITCH_UpdateOn(void *sw);
void ISS_SWITCH_UpdateOff(void *sw);
u32 ISS_SWITCH_UpdateFadeIn(void *sw);
u32 ISS_SWITCH_UpdateFadeOut(void *sw);
u32 ISS_SWITCH_StartFadeIn(void *sw);
u32 ISS_SWITCH_StartFadeOut(void *sw);
u32 ISS_SWITCH_SetOnState(void *sw);
u32 ISS_SWITCH_SetOffState(void *sw);
u32 ISS_SWITCH_GetState(struct IssSwitch *sw);
struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state);
s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw);
void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume);
u32 ISS_SWITCH_IsOnState(void *sw);
u32 ISS_SWITCH_IsOffState(void *sw);
u32 func_0202C794(void *a0, u32 a1);
int func_0202C824(int a0);
void func_0202C83C(struct Ctx *p, u32 a1);
void func_0202C860(u8 *a0, int a1);
s32 func_0202C8B8(void *a0, u32 a1, u32 a2);
s32 func_0202C934(void *a0, u32 a1, u32 a2);
u32 func_0202C970(void *a, void *b, u32 c);
struct BgWinFrmWork *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heapId);
void BGWINFRM_Delete(struct BgWinFrmWork *wk);
void BGWINFRM_AddFrame(struct BgWinFrmWork *wk, u32 idx, u32 bgFrame, u32 sizeX, u32 sizeY);
void BGWINFRM_SetFrameData(struct BgWinFrmWork *wk, u32 idx, const void *src);
void BGWINFRM_SetFrameDataArc(struct BgWinFrmWork *wk, u32 idx, u32 arcId, u32 datId, u32 compressed);
void BGWINFRM_SetFrameDataArcHandle(struct BgWinFrmWork *wk, u32 idx, void *arcHandle, u32 datId, u32 compressed);
void BGWINFRM_PutFrame(struct BgWinFrmWork *wk, u32 idx, s8 x, s8 y);
void BGWINFRM_ShowFrame(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_HideFrame(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_StartMove(struct BgWinFrmWork *wk, u32 idx, s8 moveX, s8 moveY, u8 count);
void BGWINFRM_UpdateMoves(struct BgWinFrmWork *wk);
u32 BGWINFRM_UpdateMove(struct BgWinFrmWork *wk, u32 idx);
u32 BGWINFRM_IsMoving(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_ChangePalette(struct BgWinFrmWork *wk, u32 idx, s32 x, s32 y, u8 sizeX, u8 sizeY, u8 palette);
void BGWINFRM_PutBmpWin(struct BgWinFrmWork *wk, u32 idx, void *bmpWin);
u16 *BGWINFRM_GetFrameBuffer(struct BgWinFrmWork *wk, u32 idx);
u8 BGWINFRM_GetBgFrame(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_GetPos(struct BgWinFrmWork *wk, u32 idx, s8 *x, s8 *y);
void BGWINFRM_GetSize(struct BgWinFrmWork *wk, u32 idx, u16 *sizeX, u16 *sizeY);
void BGWINFRM_SetClipArea(struct BgWinFrmWork *wk, u32 idx, s8 xmin, s8 xmax, s8 ymin, s8 ymax);
void func_0202D018(void);
u8 func_0202D01C(u32 a, u32 b, u32 c);
int func_0202D034(u32 a, u32 b);
int POKEGRA_GetArcID(void);
s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
void POKEGRA_ConvertCharTo2D(void *charData, u32 heapId);
void POKEGRA_ConvertCharTo1D(u32 *charData, u32 heapId);
void POKEGRA_DrawSpindaSpots(struct NNSG2dCharacterData *charData, u32 personality);
void POKEGRA_CalcArcIndex(void *arcId, u32 monsNo, s32 formNo, s32 sex, u32 rare, u32 dir, u32 egg, u32 *outIndex, u32 *outDirOffset, u32 *outSex, u32 *outRare, u32 **outFormPalIndex, u32 isCgr);
u32 POKEGRA_GetTrainerArcID(u32 isBack);
u32 POKEGRA_GetTrainerCgrArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerCbrArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerPalArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerCelArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerAnmArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerMCelArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerMAnmArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerNcecArcIndex(u32 trType, u32 flags);
void *POKEGRA_LoadCharDataPP(u32 *outCharData, void *pp, u32 dir, u16 heapId);
void *POKEGRA_LoadCharData(u32 *outCharData, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg, u32 personality, volatile u16 heapId);
void *POKEGRA_OpenHandle(u32 heapId);
int POKEGRA_RegisterPalette(int handle, int monsNo, int formNo, int sex, int rare, int dir, int egg, int drawType, unsigned short palOffset, unsigned short heapId);
u32 POKEGRA_RegisterCgr(u32 handle, u32 monsNo, u32 formNo, u32 sex, volatile u32 rare, volatile u32 dir, volatile u32 egg, volatile u32 personality, volatile u32 drawType, volatile u16 heapId);
u32 POKEGRA_RegisterCellAnim(u32 monsNo, u32 formNo, u32 sex, u32 rare, volatile u32 dir, volatile u32 egg, volatile u32 mapping, volatile u32 unusedArg, volatile u16 heapId);
int POKEGRA_RegisterPalettePP(int handle, void *pp, int dir, int drawType, unsigned short palOffset, unsigned short heapId);
int POKEGRA_RegisterCgrPP(int handle, void *pp, int dir, int drawType, unsigned short heapId);
u32 POKEGRA_RegisterCellAnimPP(u32 pp, u32 dir, u32 mapping, u32 unusedArg, u16 heapId);
void *POKEGRA_OpenTrainerHandle(u32 heapId);
s32 POKEGRA_RegisterTrainerPalette(u32 handle, u32 trType, u32 drawType, u32 palOffset, u16 heapId);
void POKEGRA_RegisterTrainerCgr(u32 handle, u32 trType, u32 drawType, u32 heapId);
s32 POKEGRA_RegisterTrainerCellAnim(u32 unusedArg, u32 mapping, u32 drawType, u16 heapId);
void POKEGRA_LoadTrainerGraphics(void *handle, u32 trType, void *charDst, void *palDst, volatile u16 heapId);
struct PmsDraw *PMS_DRAW_Create(u32 clunit, u32 drawType, u32 printQue, u32 font, u8 plttOffset, u8 elemMax, u16 heapId);
void PMS_DRAW_Main(struct PmsDraw *wk);
void PMS_DRAW_Delete(struct PmsDraw *wk);
void PMS_DRAW_Print(u32 wk, u32 bmpWin, u32 pms, u32 id);
void PMS_DRAW_PrintOffset(struct PmsDraw *wk, void *bmpWin, void *pms, u32 id, const void *offset);
u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *wk);
void PMS_DRAW_Clear(struct PmsDraw *wk, int id, u32 isTrans);
void PMS_DRAW_SetVisible(struct PmsDraw *wk, int id, u32 visible);
u32 PMS_DRAW_IsActive(const struct PmsDraw *wk, u32 id);
void PMS_DRAW_SetDecoVisible(struct PmsDraw *wk, u32 id, u32 visible);
void PMS_DRAW_SetDecoPriority(struct PmsDraw *wk, u32 id, u32 priority);
void PMS_DRAW_Copy(struct PmsDraw *wk, u32 srcId, u32 dstId);
void PMS_DRAW_SetNullColorPalette(struct PmsDraw *wk, u8 palette);
void PMS_DRAW_SetPrintColor(struct PmsDraw *wk, u16 color);
void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *wk, u32 follow);
void PMS_DRAW_CalcDecoPos(u32 bmpWin, u32 charX, u32 line, const struct PmsPos *offset, struct PmsPos *out);
u32 PMS_DRAW_GetDecoCgrIndex(u32 engine);
u32 PMS_DRAW_GetDecoCelIndex(u32 engine);
u32 PMS_DRAW_GetDecoAnmIndex(u32 engine);
void PMS_DRAW_LoadResources(u32 *res, u32 plttOffset, u32 heapId);
void PMS_DRAW_ReleaseResources(struct PmsDrawRes *res);
void *PMS_DRAW_CreateDecoActor(struct PmsDrawRes *res, u16 heapId);
void PMS_DRAW_PlaceDecoActor(void *actor, struct Descriptor *bmpWin, u32 charX, u32 line, u32 wordId, const struct PmsPos *offset);
void PMS_DRAW_InitElem(struct PmsElem *elem, struct PmsDrawRes *res, u16 heapId);
void PMS_DRAW_DeleteElem(struct PmsElem *elem);
int PMS_DRAW_UpdateElem(struct PmsElem *elem, void *printQue, int followBgScroll);
void PMS_DRAW_PrintElem(struct PmsElem *elem, void *printQue, u32 font, struct Descriptor *bmpWin, const PmsData *param, const PmsOffset *offset, u16 color, u8 nullColorPalette, u16 heapId);
void PMS_DRAW_ClearElem(struct PmsElem *elem, u32 isTrans);
void PMS_DRAW_SetElemVisible(struct PmsElem *elem, u32 visible);
u32 PMS_DRAW_GetFrameSurface(u32 frame);
void func_0202E43C(void *p);
u32 func_0202E448(u32 id);
void *BAG_PARAM_Create(const struct BigObj *gameData, int itemCheck, int mode, int heapId);
extern const char IssSwitchSysFileName[];
extern const char IssSwitchSetFileName[];
extern char IssSwitchFileName[];
extern struct Pair gTbl_0209FFF4[];
extern const char BgWinFrmFileName[];
extern const char PokegraFileName[];
extern const u8 *const SpindaSpotTables[4];
extern const u8 TrainerGraIndexTable[];
extern char  PmsDrawFileName[];
extern const struct ItemValueEntry ItemValueTable[];
extern char BagParamFileName[];

/*
 * Blocked: the THM_CALL at +0012 to ISS_SWITCH_SYS_CreateSets has no manifest entry.
 * 0x0202C148 (76 bytes, pkt_0202C148, still open) is byte-correct except an
 * eight-instruction schedule permutation in its prologue: 15 C spellings were
 * measured and every one emits the same permuted block, so it is a DIFF and
 * cannot be filed - see docs/notes/pkt_0202C148.c.txt.  The other two sites
 * (ISS_SWITCH_SYS_Alloc, ISS_SWITCH_SYS_Init) resolve as `matched`.  Every concrete byte
 * reproduces.
 *
 * Creates a node through ISS_SWITCH_SYS_Alloc, prepares it with ISS_SWITCH_SYS_Init and
 * binds the argument with ISS_SWITCH_SYS_CreateSets.
 */
u8 *ISS_SWITCH_SYS_Create(u16 heapId)
{
    u8 *sys = ISS_SWITCH_SYS_Alloc(heapId);

    ISS_SWITCH_SYS_Init(sys);
    ISS_SWITCH_SYS_CreateSets(sys, heapId);
    return sys;
}

/*
 * closed:   blocker ISS_SYS_DeleteSwitch.c is now a manifest entry (matched class)
 *
 * Runs ISS_SWITCH_SYS_DeleteSets then ISS_SWITCH_SYS_Free over the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Delete.c \
 *       --func ISS_SWITCH_SYS_Delete --addr 0x0202C08C --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_Delete(u8 *sys)
{
    ISS_SWITCH_SYS_DeleteSets(sys);
    ISS_SWITCH_SYS_Free(sys);
}

/*
 * When ISS_SWITCH_SYS_IsOn reports true, runs ISS_SWITCH_SYS_UpdateActiveSet and ISS_SWITCH_SYS_UpdateVolume.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Main.c \
 *       --func ISS_SWITCH_SYS_Main --addr 0x0202C09C --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_Main(u8 *sys)
{
    if (ISS_SWITCH_SYS_IsOn((u32 *)sys) != 0) {
        ISS_SWITCH_SYS_UpdateActiveSet((struct IssSwitchSys *)sys);
        ISS_SWITCH_SYS_UpdateVolume(sys);
    }
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202C1D4, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_On.c \
 *       --func ISS_SWITCH_SYS_On --addr 0x0202C0B8 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_On(u8 *sys)
{
    ISS_SWITCH_SYS_TurnOn(sys);
}

/*
 * An eight-byte tail-call thunk into ISS_SWITCH_SYS_TurnOff, with the callee's ISA
 * carried in the low bit of the pool word (docs/idioms/
 * tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the listing and absent
 * from the worklist; filed from the bytes.  src/pending/ISS_SYS_UpdateSwitch.c is
 * blocked on this address and now has it as a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Off.c \
 *       --func ISS_SWITCH_SYS_Off --addr 0x0202C0C0 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_Off(u32 *sys)
{
    ISS_SWITCH_SYS_TurnOff(sys);
}

/*
 * An eight-byte tail-call thunk into ISS_SWITCH_SYS_CheckZoneChange.  Unlabelled in the listing
 * and absent from the worklist; filed from the bytes.  src/pending/
 * ISS_SYS_OnZoneChangeSwitch.c is blocked on this address and now has it as a `matched`
 * witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_ZoneChange.c \
 *       --func ISS_SWITCH_SYS_ZoneChange --addr 0x0202C0C8 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_ZoneChange(u32 *sys, u32 zoneId)
{
    ISS_SWITCH_SYS_CheckZoneChange(sys, zoneId);
}

/*
 * Resolves the object through ISS_SWITCH_SYS_GetActiveSet and, when found, forwards the
 * argument through ISS_SWITCH_SET_SwitchOn.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_SwitchOn.c \
 *       --func ISS_SWITCH_SYS_SwitchOn --addr 0x0202C0D0 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_SwitchOn(u8 *sys, u32 switchIdx)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet((struct IssSwitchSys *)sys);

    if (set != 0) {
        ISS_SWITCH_SET_SwitchOn((void *)set, switchIdx);
    }
}

/*
 * Resolves the object through ISS_SWITCH_SYS_GetActiveSet and, when found, forwards the
 * argument through ISS_SWITCH_SET_SwitchOff.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_SwitchOff.c \
 *       --func ISS_SWITCH_SYS_SwitchOff --addr 0x0202C0E4 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_SwitchOff(u8 *sys, u32 switchIdx)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet((struct IssSwitchSys *)sys);

    if (set != 0) {
        ISS_SWITCH_SET_SwitchOff((void *)set, switchIdx);
    }
}

u32 ISS_SWITCH_SYS_IsSwitchOn(struct IssSwitchSys *sys, u32 switchIdx)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet(sys);

    if (set != 0) {
        return ISS_SWITCH_SET_IsSwitchOn((void *)set, switchIdx);
    }
    return 0;
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202C2DC, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_ResetSwitch.c \
 *       --func ISS_SWITCH_SYS_ResetSwitch --addr 0x0202C110 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_ResetSwitch(void *sys)
{
    ISS_SWITCH_SYS_ResetActiveSet(sys);
}

void ISS_SWITCH_SYS_Init(void *obj)
{
    struct IssSwitchSys *sys = obj;

    sys->isOn = 0;
    sys->setCount = 0;
    sys->sets = 0;
    sys->activeSet = 0;
}

/*
 * Allocates 16 bytes from heap with tracking file and line.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Alloc.c \
 *       --func ISS_SWITCH_SYS_Alloc --addr 0x0202C124 --cc 1.1p1 --thumb
 */
void *ISS_SWITCH_SYS_Alloc(u32 heapId)
{
    return func_02030734(heapId, 0x10, 0, IssSwitchSysFileName, 0x10A);
}

void ISS_SWITCH_SYS_Free(void *sys)
{
    func_020307B0(sys);
}

/*
 * Build the unit table of a block: n = ARC_TOOL_GetArchiveFileCount(0x93) members, the
 * count stored at +4, an n-word pointer array allocated from heapId at +8
 * (file word 0x020A7758, line 0x13A), then one unit per slot from
 * ISS_SWITCH_SET_Create(heapId), initialised by ISS_SWITCH_SET_Load(unit, i, heapId).
 *
 * What closed it (wave 17, from 17 out): heapId is a u16 PARAMETER.  With
 * a u32 heapId 1.1p1 hoists the heapId reload and the file pool word above
 * the `strb` of the count; narrowed, its home store `str r1, [sp, #4]`
 * sits at the front of the prologue and the image's order falls out
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * The callee prototypes take the same u16 heap id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_CreateSets.c \
 *       --func ISS_SWITCH_SYS_CreateSets --addr 0x0202C148 --cc 1.1p1 --thumb
 */
void ISS_SWITCH_SYS_CreateSets(u8 *p, u16 heapId)
{
    struct IssSwitchSys *sys = (struct IssSwitchSys *)p;
    u32 i;
    int n;

    n = ARC_TOOL_GetArchiveFileCount(0x93);
    sys->setCount = (u8)n;
    sys->sets = func_02030734(heapId, (u32)(n << 2), 0,
                              IssSwitchSysFileName, 0x13a);
    for (i = 0; (int)i < n; i++) {
        struct IssSwitchSet *set = (struct IssSwitchSet *)ISS_SWITCH_SET_Create((void *)heapId);
        ISS_SWITCH_SET_Load(set, i, heapId);
        sys->sets[i] = set;
    }
}

/*
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Teardown for the list node ISS_SWITCH_SYS_CreateSets builds: walk the pointer array and
 * release each element, then free the array and clear all three headers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_SWITCH_SYS_DeleteSets.c \
 *       --func ISS_SWITCH_SYS_DeleteSets --addr 0x0202C198 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_DeleteSets(u8 *p)
{
    struct IssSwitchSys *sys = (struct IssSwitchSys *)p;
    int n = sys->setCount;
    int i;

    for (i = 0; i < n; i++) {
        ISS_SWITCH_SET_Delete(sys->sets[i]);
    }
    func_020307B0(sys->sets);
    sys->setCount = 0;
    sys->sets = 0;
    sys->activeSet = 0;
}

u32 ISS_SWITCH_SYS_UpdateActiveSet(struct IssSwitchSys *sys)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet(sys);

    if (set != 0) {
        return ISS_SWITCH_SET_Main((void *)set);
    }
    return set;
}

void ISS_SWITCH_SYS_TurnOn(u8 *p)
{
    struct IssSwitchSys *sys = (struct IssSwitchSys *)p;

    if (ISS_SWITCH_SYS_IsOn((u32 *)sys) == 1) {
        return;
    }
    sys->isOn = 1;
    if (ISS_SWITCH_SYS_ChangeActiveSet((u32 *)sys, ISS_SWITCH_SYS_GetPlayingBgm(1)) != 1) {
        return;
    }
    ISS_SWITCH_SYS_ResetActiveSet(sys);
    ISS_SWITCH_SYS_UpdateVolume(sys);
}

/*
 * Clears the object's first word when it is non-zero.  Unlabelled in the
 * listing (no lr save) and absent from the worklist; filed from the bytes.
 * It is the tail-call target of the thunk at 0x0202C0C0, which is what
 * src/pending/ISS_SYS_UpdateSwitch.c is blocked on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_TurnOff.c \
 *       --func ISS_SWITCH_SYS_TurnOff --addr 0x0202C204 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_TurnOff(u32 *sys)
{
    if (ISS_SWITCH_SYS_IsOn(sys) != 0) {
        *sys = 0;
    }
}

/*
 * Clears the record through ISS_SWITCH_SYS_TurnOff when the object is live and the
 * lookup fails.  Unlabelled in the listing (no lr save of its own beyond the
 * callee-saved set) and absent from the worklist; filed from the bytes.  It is
 * the tail-call target of the thunk at 0x0202C0C8, which is what
 * src/pending/ISS_SYS_OnZoneChangeSwitch.c is blocked on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_CheckZoneChange.c \
 *       --func ISS_SWITCH_SYS_CheckZoneChange --addr 0x0202C218 --thumb --cc 1.1p1
 */
void ISS_SWITCH_SYS_CheckZoneChange(u32 *sys, u32 zoneId)
{
    if (ISS_SWITCH_SYS_IsOn(sys) == 0) {
        return;
    }
    if (ISS_SWITCH_SYS_IsActiveSetZone(sys, zoneId) != 0) {
        return;
    }
    ISS_SWITCH_SYS_ResetActiveSet(sys);
    ISS_SWITCH_SYS_TurnOff(sys);
}

u32 ISS_SWITCH_SYS_GetSetCount(void *sys)
{
    return ((struct IssSwitchSys *)sys)->setCount;
}

u32 ISS_SWITCH_SYS_GetSet(struct IssSwitchSys *sys, u32 idx)
{
    return (u32)sys->sets[idx];
}

u32 ISS_SWITCH_SYS_GetActiveSet(struct IssSwitchSys *sys)
{
    return (u32)sys->activeSet;
}

/*
 * When the object's +0xc field is set, hands that field (not the object) to
 * sub_0202C348 together with the caller's second argument.  Unlabelled in the
 * listing and absent from the worklist; filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_IsActiveSetZone.c \
 *       --func ISS_SWITCH_SYS_IsActiveSetZone --addr 0x0202C250 --thumb --cc 1.1p1
 */
u32 ISS_SWITCH_SYS_IsActiveSetZone(u32 *sys, u32 zoneId)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet((struct IssSwitchSys *)sys);

    if (set == 0) {
        return 0;
    }
    return ISS_SWITCH_SET_IsValidZone((void *)set, (void *)zoneId);
}

/*
 * Scans the object's count entries (ISS_SWITCH_SYS_GetSetCount is the count) looking for
 * the one whose sub_0202C340 value equals the caller's second argument, and
 * returns the entry's sub_0202C244 value.  The index is truncated to a byte
 * before it is passed, which is what the lsls/lsrs pair says.  Unlabelled in
 * the listing and absent from the worklist; filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_FindSetByBgm.c \
 *       --func ISS_SWITCH_SYS_FindSetByBgm --addr 0x0202C268 --thumb --cc 1.1p1
 */
u32 ISS_SWITCH_SYS_FindSetByBgm(u8 *sys, u32 bgmNo)
{
    int n = ISS_SWITCH_SYS_GetSetCount(sys);
    int i;

    for (i = 0; i < n; i++) {
        u32 set = ISS_SWITCH_SYS_GetSet((struct IssSwitchSys *)sys, (u8)i);

        if (bgmNo == ISS_SWITCH_SET_GetBgmNo((void *)set)) {
            return set;
        }
    }
    return 0;
}

/*
 * Looks the caller's second argument up with ISS_SWITCH_SYS_FindSetByBgm; if the result
 * differs from the object's current +0xc field, installs it there and reports
 * success.  Unlabelled in the listing and absent from the worklist; filed from
 * the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_ChangeActiveSet.c \
 *       --func ISS_SWITCH_SYS_ChangeActiveSet --addr 0x0202C29C --thumb --cc 1.1p1
 */
int ISS_SWITCH_SYS_ChangeActiveSet(u32 *p, u32 bgmNo)
{
    u32 current = ISS_SWITCH_SYS_GetActiveSet((struct IssSwitchSys *)p);
    u32 found = ISS_SWITCH_SYS_FindSetByBgm((u8 *)p, bgmNo);

    if (current == found) {
        return 0;
    }
    ((struct IssSwitchSys *)p)->activeSet = (struct IssSwitchSet *)found;
    return 1;
}

void ISS_SWITCH_SYS_UpdateVolume(void *sys)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet(sys);

    if (set != 0) {
        ISS_SWITCH_SET_UpdateVolume((void *)set);
    }
}

u32 ISS_SWITCH_SYS_GetPlayingBgm(u32 unused)
{
    return GFL_USE_GetBgmNo();
}

u32 ISS_SWITCH_SYS_IsOn(u32 *sys)
{
    return ((struct IssSwitchSys *)sys)->isOn;
}

void ISS_SWITCH_SYS_ResetActiveSet(void *sys)
{
    u32 set = ISS_SWITCH_SYS_GetActiveSet(sys);

    if (set != 0) {
        ISS_SWITCH_SET_ResetSwitch((void *)set);
    }
}

/*
 * Closed: ISS_SWITCH_SET_Alloc became an EXACT manifest entry, so the matched class attests the call at 0x0202C2F0.
 */
u32 ISS_SWITCH_SET_Create(void *heapId)
{
    u32 set = (u32)ISS_SWITCH_SET_Alloc(heapId);

    ISS_SWITCH_SET_Init((void *)set);
    ISS_SWITCH_SET_CreateSwitches((char *)set, (int)heapId);
    return set;
}

void ISS_SWITCH_SET_Delete(void *set)
{
    ISS_SWITCH_SET_DeleteSwitches(set);
    ISS_SWITCH_SET_Free(set);
}

u32 ISS_SWITCH_SET_Load(void *set, u32 datId, u32 heapId)
{
    return ISS_SWITCH_SET_LoadData(set, (void *)datId);
}

u32 ISS_SWITCH_SET_Main(void *set)
{
    return ISS_SWITCH_SET_UpdateSwitches(set);
}

u32 ISS_SWITCH_SET_SwitchOn(void *set, u32 switchIdx)
{
    return ISS_SWITCH_SET_StartSwitchOn(set, switchIdx);
}

u32 ISS_SWITCH_SET_SwitchOff(void *set, u32 switchIdx)
{
    return ISS_SWITCH_SET_StartSwitchOff(set, switchIdx);
}

void ISS_SWITCH_SET_ResetSwitch(void *set)
{
    ISS_SWITCH_SET_ResetSwitches(set);
}

u32 ISS_SWITCH_SET_GetBgmNo(void *set)
{
    return ISS_SWITCH_SET_ReadBgmNo(set);
}

u32 ISS_SWITCH_SET_IsValidZone(void *set, void *zoneId)
{
    return ISS_SWITCH_SET_CheckZone(set, (u32)zoneId);
}

u32 ISS_SWITCH_SET_IsSwitchOn(void *set, u32 switchIdx)
{
    return ISS_SWITCH_SET_CheckSwitchOn(set, switchIdx);
}

void ISS_SWITCH_SET_UpdateVolume(void *set)
{
    ISS_SWITCH_SET_ApplySwitchVolumes(set);
}

void ISS_SWITCH_SET_Init(struct IssSwitchSet *set)
{
    int i;

    set->bgmNo = 0;
    set->zoneCount = 0;

    for (i = 0; i < 9; i++) {
        set->zones[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        set->switches[i] = 0;
    }
}

void *ISS_SWITCH_SET_Alloc(void *heapId)
{
    return func_02030734((u32)heapId, 0x3c, 0, IssSwitchSetFileName, 0x12a);
}

u32 ISS_SWITCH_SET_Free(void *set)
{
    return func_020307B0(set);
}

void ISS_SWITCH_SET_CreateSwitches(char *p, int heapId)
{
    struct IssSwitchSet *set = (struct IssSwitchSet *)p;
    int i;
    for (i = 0; i < 9; i++)
        set->switches[i] = ISS_SWITCH_Create(heapId);
}

void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set)
{
    int i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_Delete(set->switches[i]);
        set->switches[i] = 0;
    }
}

u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, void *datId)
{
    u16 trackBits[9];
    u16 fadeFrames;
    int i;
    u32 offset;
    u32 ret;

    i = 0;
    offset = 0;
    FSi_ConvertStringSjisToUnicode(set, 0x93, datId, offset, 4);
    offset += 4;

    for (; i < 9; i++, offset += 2) {
        FSi_ConvertStringSjisToUnicode(&trackBits[i], 0x93, datId, offset, 2);
    }

    FSi_ConvertStringSjisToUnicode(&fadeFrames, 0x93, datId, offset, 2);
    FSi_ConvertStringSjisToUnicode(&set->zoneCount, 0x93, datId, offset + 2, 1);
    FSi_ConvertStringSjisToUnicode(set->zones, 0x93, datId, offset + 3, set->zoneCount * 2);

    i = 0;
    for (; i < 9; i++) {
        ret = ISS_SWITCH_Setup((void *)ISS_SWITCH_SET_GetSwitch(set, i), fadeFrames, trackBits[i]);
    }

    return ret;
}

u32 ISS_SWITCH_SET_UpdateSwitches(void *set)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_Main((void *)ISS_SWITCH_SET_GetSwitch(set, i));
    }
}

u32 ISS_SWITCH_SET_StartSwitchOn(void *set, u32 switchIdx)
{
    return ISS_SWITCH_On((void *)ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

u32 ISS_SWITCH_SET_StartSwitchOff(void *set, u32 switchIdx)
{
    return ISS_SWITCH_Off((void *)ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

void ISS_SWITCH_SET_ResetSwitches(void *set)
{
    s32 i;

    ISS_SWITCH_ForceOn((void *)ISS_SWITCH_SET_GetSwitch(set, 0));
    for (i = 1; i < 9; i++) {
        ISS_SWITCH_ForceOff((void *)ISS_SWITCH_SET_GetSwitch(set, i));
    }
}

/*
 * An unlabelled leaf sitting in the four bytes between sub_0202C4A4's last
 * instruction and ISS_SWITCH_SET_GetZoneCount's first
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): no
 * register-saving prologue, so disasm.py's sweep never marks it. It is a
 * plain read of the object's first word, reached only through
 * sub_0202C340's pool-word-and-bx tail call
 * (src/matched/unit_0202C318.c, parked at MATCH because this address is
 * its only caller anywhere in the image).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C4C8.c \
 *       --func ISS_SWITCH_SET_ReadBgmNo --addr 0x0202C4C8 --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_SET_ReadBgmNo(u32 *set)
{
    return ((struct IssSwitchSet *)set)->bgmNo;
}

u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set)
{
    return set->zoneCount;
}

u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx)
{
    return set->zones[idx];
}

u32 ISS_SWITCH_SET_CheckZone(void *set, u32 zoneId)
{
    int count = ISS_SWITCH_SET_GetZoneCount(set);
    int i;

    for (i = 0; i < count; i++) {
        if (zoneId == ISS_SWITCH_SET_GetZone(set, i)) {
            return 1;
        }
    }
    return 0;
}

u32 ISS_SWITCH_SET_CheckSwitchOn(void *set, u32 switchIdx)
{
    return ISS_SWITCH_IsOn((void *)ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

u32 ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx)
{
    return (u32)set->switches[idx];
}

void ISS_SWITCH_SET_ApplySwitchVolumes(void *set)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_SetVolume((void *)ISS_SWITCH_SET_GetSwitch(set, i), 0x7F);
    }
}

void *ISS_SWITCH_Create(u32 heapId)
{
    void *sw = ISS_SWITCH_Alloc(heapId);

    ISS_SWITCH_Init(sw);
    return sw;
}

u32 ISS_SWITCH_Delete(void *sw)
{
    return ISS_SWITCH_Free(sw);
}

u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits)
{
    return ISS_SWITCH_SetParam(sw, fadeFrames, trackBits);
}

u32 ISS_SWITCH_IsOn(void *sw)
{
    return ISS_SWITCH_IsOnState(sw);
}

u32 ISS_SWITCH_On(void *sw)
{
    return ISS_SWITCH_StartFadeIn(sw);
}

u32 ISS_SWITCH_Off(void *sw)
{
    return ISS_SWITCH_StartFadeOut(sw);
}

u32 ISS_SWITCH_ForceOn(void *sw)
{
    return ISS_SWITCH_SetOnState(sw);
}

u32 ISS_SWITCH_ForceOff(void *sw)
{
    return ISS_SWITCH_SetOffState(sw);
}

void ISS_SWITCH_Main(void *sw)
{
    ISS_SWITCH_Update(sw);
}

void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume)
{
    ISS_SWITCH_ApplyVolume(sw, maxVolume);
}

void *ISS_SWITCH_Alloc(u32 heapId)
{
    return func_02030734(heapId, 0xc, 0, IssSwitchFileName, 0x115);
}

/*
 * An unlabelled leaf sitting inside sub_0202C590's own literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a
 * pool-word-and-bx tail call into the ARM SDK function ENV_SetResourceSet
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md
 * covers the shape, though this is a genuine tail call rather than a
 * linker veneer). Reached only through sub_0202C548's own
 * pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5AC.c \
 *       --func ISS_SWITCH_Free --addr 0x0202C5AC --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_Free(void *sw)
{
    return func_020307B0(sw);
}

void ISS_SWITCH_Init(struct IssSwitch *sw)
{
    sw->state = 1;
    sw->fadeCount = 0;
    sw->fadeFrames = 0;
    sw->trackBits = 0;
}

/*
 * An unlabelled leaf, six bytes padded to eight, sitting between
 * sub_0202C5B4's trailing padding and ISS_SWITCH_CountUpFade's label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a plain
 * two-field setter with no prologue at all, reached only through
 * sub_0202C550's pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5C4.c \
 *       --func ISS_SWITCH_SetParam --addr 0x0202C5C4 --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits)
{
    sw->fadeFrames = fadeFrames;
    sw->trackBits = trackBits;
}

void ISS_SWITCH_CountUpFade(struct IssSwitch *sw)
{
    sw->fadeCount = sw->fadeCount + 1;
    if (sw->fadeFrames < sw->fadeCount) {
        sw->fadeCount = sw->fadeFrames;
    }
}

u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw)
{
    if (sw->fadeFrames > sw->fadeCount) {
        return 0;
    }
    return 1;
}

void ISS_SWITCH_Update(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        ISS_SWITCH_UpdateOn(sw);
        break;
    case 1:
        ISS_SWITCH_UpdateOff(sw);
        break;
    case 2:
        ISS_SWITCH_UpdateFadeIn(sw);
        break;
    case 3:
        ISS_SWITCH_UpdateFadeOut(sw);
        break;
    }
}

void ISS_SWITCH_UpdateOn(void *sw)
{
}

void ISS_SWITCH_UpdateOff(void *sw)
{
}

u32 ISS_SWITCH_UpdateFadeIn(void *sw)
{
    ISS_SWITCH_CountUpFade(sw);
    if (ISS_SWITCH_IsFadeEnd(sw) == 1) {
        ISS_SWITCH_SetState(sw, 0);
    }
}

u32 ISS_SWITCH_UpdateFadeOut(void *sw)
{
    ISS_SWITCH_CountUpFade(sw);
    if (ISS_SWITCH_IsFadeEnd(sw) == 1) {
        ISS_SWITCH_SetState(sw, 1);
    }
}

u32 ISS_SWITCH_StartFadeIn(void *sw)
{
    if (ISS_SWITCH_IsOnState(sw) != 1) {
        ISS_SWITCH_SetState(sw, 2);
    }
}

u32 ISS_SWITCH_StartFadeOut(void *sw)
{
    if (ISS_SWITCH_IsOffState(sw) != 1) {
        ISS_SWITCH_SetState(sw, 3);
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves, back to back
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): each is a
 * three-instruction, six-byte forwarding call with a literal second
 * argument, padded to eight with a `nop` and its own pool word. Reached
 * only through sub_0202C570 and sub_0202C578's pool-word-and-bx tail
 * calls (src/matched/unit_0202C548.c). Neither carries a
 * register-saving prologue, so neither is in the worklist's function
 * list; both sit exactly between ISS_SWITCH_StartFadeOut's last instruction and
 * sub_0202C6B8's label.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6A0.c \
 *       --addr 0x0202C6A0 --thumb
 */
u32 ISS_SWITCH_SetOnState(void *sw)
{
    return (u32)ISS_SWITCH_SetState(sw, 0);
}

u32 ISS_SWITCH_SetOffState(void *sw)
{
    return (u32)ISS_SWITCH_SetState(sw, 1);
}

u32 ISS_SWITCH_GetState(struct IssSwitch *sw)
{
    return sw->state;
}

struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state)
{
    sw->state = state;
    sw->fadeCount = 0;
    return sw;
}

s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw)
{
    s32 volume;

    switch (ISS_SWITCH_GetState((struct IssSwitch *)sw)) {
    case 0:
        return 0x7F;
    case 1:
        return 0;
    case 2:
        volume = sw->fadeCount * 0x7F / sw->fadeFrames;
        break;
    case 3:
        volume = 0x7F - sw->fadeCount * 0x7F / sw->fadeFrames;
        break;
    }
    return volume;
}

void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume)
{
    GFL_USE_SetBgmTrackVolume(sw->trackBits, maxVolume * ISS_SWITCH_GetVolume(sw) / 0x7F);
}

u32 ISS_SWITCH_IsOnState(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    }
    return 0;
}

u32 ISS_SWITCH_IsOffState(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return 0;
}

/*
 * note:     wave 16: promoted.  0x021647E8 is the unlabelled ov010 tail-call
 *           thunk matched in src/matched/CALENDER_GetWeatherThunk.c (`matched, overlay`
 *           under the ov010 hint); 0x0202C8B8 now resolves as `matched`.
 *
 * A chain of four probes, each returning a u8 reason code unless it comes
 * back 0xffff ("nothing to say"); the sentinel is kept in a callee-saved
 * register, which is why it is one pool word and four `cmp r0, r7`.
 */
u32 func_0202C794(void *a0, u32 a1)
{
    u32 ctx = (u32)ICA_ANIME_GetField1C(a0);
    u32 saved = GAME_DATA_GetMusicalWork((const struct BigObj *)ctx);
    u32 r;

    r = MOVE_POKEMON_FindEntryByZone((void *)ctx, (u16)a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C8B8(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C934(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C970(a0, (void *)ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    if (func_0202C824(ctx) != 0) {
        return (u8)CALENDER_GetWeatherThunk((void *)saved, (u16)a1);
    }
    return (u8)ZONEDATA_GetWeatherId((u16)a1);
}

int func_0202C824(int a0){ int t0, t1; t0 = GAME_DATA_GetSeason(a0); t1 = func_0202E888((int)t0); if ((unsigned int)((t0 + 0)) == (unsigned int)(t1)) {  return 1; } else {  return 0; } }

void func_0202C83C(struct Ctx *p, u32 a1)
{
    struct BigObj *obj = ICA_ANIME_GetField1C(p);
    u32 r = func_0202C794(p, a1);

    GAME_DATA_SetSubscreenMode(obj, (u8)r);
}

/*
 * note:     2026-09-23 (wave 15): EXACT with no C change; the ov010 call
 *           at +0x34 now resolves sole-ref/code.  The MATCH text below is history.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 82 concrete bytes
 * are correct (88-byte extent, the last 6 bytes being the pool word 0xffff),
 * but the PC-relative call at +0x0034 to MOVE_POKEMON_IsAnyEntryActive in ov010 has no
 * witness: 0x0215E6F8 has exactly one branch reference image-wide and it is
 * that call, so no cut frees it, and the address is inside BOTH ov009's and
 * ov010's windows, so the `label` class refuses it even with the ov010 hint
 * on the symbols: line.  The unblock is a `matched` entry at 0x0215E6F8
 * (or any additional caller of it anywhere in the image).
 *
 * The range check must wrap in 32 bits: `(u32)(r - 6) > 1`, `(r - 6) > 1u`
 * and `(unsigned)(r - 6) > 1` all give the original's bare
 * `subs r0, r1, #6; cmp r0, #1; bhi`.  The u16-cast spelling
 * `(u16)(r - 6) > 1` is wrong by two instructions: it re-truncates the
 * difference with `lsls r0, r0, #0x10; lsrs r0, r0, #0x10` first.
 *
 * The first call takes the actor pointer as well as the truncated id,
 * `MOVE_POKEMON_FindEntryByZone(a0, (u16)a1)`: r0 is still r0 at the call and the id is
 * built in r1.  Declaring it as a one-argument call puts the id in r0 and
 * shifts the whole prologue.
 */
void func_0202C860(u8 *a0, int a1)
{
    u32 v;
    u16 r;

    v = MOVE_POKEMON_FindEntryByZone(a0, (u16)a1);
    r = (u16)(u32)GAME_DATA_GetSubscreenMode((const struct BigObj *)a0);
    if (v != 0xffff) {
        GAME_DATA_SetSubscreenMode((struct BigObj *)a0, (u8)v);
        return;
    }
    if ((u32)(r - 6) > 1) {
        return;
    }
    if (MOVE_POKEMON_IsAnyEntryActive((int)a0) != 1) {
        return;
    }
    GAME_DATA_SetSubscreenMode((struct BigObj *)a0, (u8)ZONEDATA_GetWeatherId((u16)a1));
}

/*
 * The two ABS32 pool words holding 0x0209FFF4 / 0x0209FFF6 are both inside
 * this function; grep over asm/ finds no third pool word anywhere in the
 * image, so the data table has no witness outside the compared range and
 * both relocation sites stay wildcarded. Unstuck by any other function that
 * also points at gTbl_0209FFF4, or by a data-symbol table entry.
 */
s32 func_0202C8B8(void *a0, u32 a1, u32 a2)
{
    u32 r6;
    u32 r4;
    u32 i;

    r6 = GAME_DATA_GetEventWork((const struct BigObj *)a1);
    r4 = ICA_ANIME_GetField24(a0);
    if (ZONEDATA_IsZoneGroup118To13C((u16)a2) == 0 || r4 == 0) {
        goto done;
    }
    for (i = 0; i < 0x19; i++) {
        if (a2 == gTbl_0209FFF4[i].a) {
            if (ZONEDATA_CheckEventFlag((void *)r6, gTbl_0209FFF4[i].b) == 0) {
                if (INTRUDE_COMM_GetAreaOwnerVersion(r4) == 0x14) return 0xd;
                return 0xe;
            }
            if (INTRUDE_COMM_GetAreaOwnerVersion(r4) == 0x14) return 0xa;
            return 0xb;
        }
    }
done:
    return 0xffff;
}

s32 func_0202C934(void *a0, u32 a1, u32 a2)
{
    u32 r = GAME_DATA_GetEventWork((const struct BigObj *)a1);

    if (a2 == 0x151) {
        if (ZONEDATA_CheckEventFlag((void *)r, 0x96f) != 0) {
            if (GPOWER_GetSpecialPowerId() == 0x15) return 7;
            return 6;
        }
    }
    return 0xffff;
}

u32 func_0202C970(void *a, void *b, u32 c)
{
    u8 buf[2];
    struct RtcDate date;

    if (!ZONEDATA_IsRawZone176Or17A((u16)c)) {
        goto fail;
    }
    GF_STANDARD_SetField00_F4E4(&date);
    func_0202EB60(&buf[1], &buf[0]);
    if (date.month != buf[1]) {
        goto fail;
    }
    if (date.day != buf[0]) {
        goto fail;
    }
    return 0;

fail:
    return 0xFFFF;
}

/*
 * TU: bgwinfrm.c (__FILE__ 0x020A7790, lines 0x56 and 0x5d).
 */
struct BgWinFrmWork *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heapId)
{
    struct BgWinFrmWork *wk;

    wk = func_02030734(heapId, sizeof(struct BgWinFrmWork), 0, BgWinFrmFileName, 0x56);
    wk->frameMax = frameMax;
    wk->heapId = heapId;
    wk->transMode = transMode;
    wk->moving = 0;
    wk->frames = func_02030734(heapId, frameMax << 4, 1, BgWinFrmFileName, 0x5d);

    return wk;
}

void BGWINFRM_Delete(struct BgWinFrmWork *wk)
{
    u32 i;

    for (i = 0; i < wk->frameMax; i++) {
        if (wk->frames[i].screen != 0) {
            func_020307B0(wk->frames[i].screen);
        }
    }
    func_020307B0(wk->frames);
    func_020307B0(wk);
}

/*
 * Initialises one 16-byte window record: allocates w*h*2 bytes of tile
 * storage from the debug allocator on the manager's own heap id, then
 * writes the two 6-bit size bitfields, the bg index, the scroll pair, the
 * dirty bit and the default clip box (0, 0x20, 0, 0x18).  Same struct BgWinFrame
 * as src/matched/sub_0202CAC4.c and src/matched/BGWINFRM_UpdateMove.c.
 *
 * The __FILE__ pool word 0x020A7790 spells "bgwinfrm.c"
 * (layout/file_anchors.txt line 119), which names this unit's source file.
 */
void BGWINFRM_AddFrame(struct BgWinFrmWork *wk, u32 idx, u32 bgFrame, u32 sizeX, u32 sizeY)
{
    struct BgWinFrame *frame = &wk->frames[idx];

    frame->screen = func_02030734((u16)wk->heapId, sizeX * sizeY * 2, 1,
                                    BgWinFrmFileName, 0x8a);
    frame->sizeX = (u16)sizeX;
    frame->sizeY = (u16)sizeY;
    frame->bgFrame = (u8)bgFrame;
    frame->x = 0;
    frame->y = 0;
    frame->moveFlag = 0;
    frame->hidden = 1;
    frame->xmin = 0;
    frame->xmax = 0x20;
    frame->ymin = 0;
    frame->ymax = 0x18;
}

void BGWINFRM_SetFrameData(struct BgWinFrmWork *wk, u32 idx, const void *src)
{
    MIi_CpuCopy16(src, (void *)wk->frames[idx].screen,
                  wk->frames[idx].sizeX * wk->frames[idx].sizeY * 2);
}

void BGWINFRM_SetFrameDataArc(struct BgWinFrmWork *wk, u32 idx, u32 arcId, u32 datId, u32 compressed)
{
    void *data;
    void *file;

    file = ARC_UTIL_LoadPaletteDataFromArchive(arcId, datId, compressed, (u32)(&data), wk->heapId);
    BGWINFRM_SetFrameData(wk, idx, (char *)data + 0xc);
    func_020307B0(file);
}

void BGWINFRM_SetFrameDataArcHandle(struct BgWinFrmWork *wk, u32 idx, void *arcHandle, u32 datId, u32 compressed)
{
    void *data;
    void *file;

    file = func_02049EF4(arcHandle, datId, compressed, &data, wk->heapId);
    BGWINFRM_SetFrameData(wk, idx, (char *)data + 0xc);
    func_020307B0(file);
}

void BGWINFRM_PutFrame(struct BgWinFrmWork *wk, u32 idx, s8 x, s8 y)
{
    struct BgWinFrame *frame = &wk->frames[idx];
    u8 putX, putSizeX, srcX;
    u8 putY, putSizeY, srcY;
    s32 right, bottom;

    frame->x = x;
    frame->y = y;
    if (x >= frame->xmax) {
        return;
    }
    if (y >= frame->ymax) {
        return;
    }
    right = x + frame->sizeX;
    if (right < frame->xmin) {
        return;
    }
    bottom = y + frame->sizeY;
    if (bottom < frame->ymin) {
        return;
    }

    putX = x;
    putSizeX = frame->sizeX;
    srcX = 0;
    if (x < frame->xmin) {
        putX = frame->xmin;
        srcX = frame->xmin - x;
        putSizeX = putSizeX - srcX;
    }
    if (right >= frame->xmax) {
        putSizeX = putSizeX - (u8)(right - frame->xmax);
    }

    putY = y;
    putSizeY = frame->sizeY;
    srcY = 0;
    if (y < frame->ymin) {
        putY = frame->ymin;
        srcY = frame->ymin - y;
        putSizeY = putSizeY - srcY;
    }
    if (bottom >= frame->ymax) {
        putSizeY = putSizeY - (u8)(bottom - frame->ymax);
    }

    BG_SYS_DrawTileEx(frame->bgFrame, putX, putY, putSizeX, putSizeY, frame->screen, srcX, srcY, frame->sizeX, frame->sizeY);
    BgWinFrmScreenTransFuncs[wk->transMode](frame->bgFrame);
    frame->hidden = 0;
}

void BGWINFRM_ShowFrame(struct BgWinFrmWork *wk, u32 idx)
{
    BGWINFRM_PutFrame(wk, idx, wk->frames[idx].x, wk->frames[idx].y);
}

/*
 * bgwinfrm.c.  Marks a window record dirty, rejects it when it lies wholly
 * outside its clip box (xmin..xmax, ymin..ymax), clips the origin and the
 * size against the box, then blits it through BG_SYS_SetTileEntry and runs the
 * manager's mode callback.  Same struct BgWinFrame as src/matched/BGWINFRM_StartMove.c.
 *
 * What closed it (wave 19): four spelling choices, all required.
 *  - xmax is a named local; the first guard and the right-edge clip read it.
 *  - sx = win->x is written before ow = w, so the sx spill store lands
 *    ahead of ow's sign extension.
 *  - sy is s8: it only ever holds win->y or win->ymin, both s8 fields, so
 *    the narrow type is value-preserving.  With s32 sy the clip copies ymin
 *    between registers; with s8 sy it reloads ymin from its spill slot, as
 *    the image does, and the call's argument stores fall into order.
 *  - Declarations with oh first and sy last.  mwcc numbers spill slots from
 *    the last declared local upward, so sx, h, y, sy must keep that relative
 *    order (slots 0x20, 0x1c, 0x18, 0x14).
 * The callee prototype is the one BG_SYS_SetTileEntry's own body declares.
 */
void BGWINFRM_HideFrame(struct BgWinFrmWork *wk, u32 idx)
{
    struct BgWinFrame *frame = &wk->frames[idx];
    s8 clearSizeY, clearSizeX;
    s32 clearX;
    s32 sizeX, sizeY;
    s32 right, clipRight;
    s32 top, bottom;
    s8 clearY;

    frame->hidden = 1;
    clipRight = frame->xmax;
    if (frame->x >= clipRight) {
        return;
    }
    if (frame->y >= frame->ymax) {
        return;
    }
    sizeX = frame->sizeX;
    right = frame->x + sizeX;
    if (right < frame->xmin) {
        return;
    }
    sizeY = frame->sizeY;
    clearY = frame->y;
    top = clearY;
    bottom = top + sizeY;
    if (bottom < frame->ymin) {
        return;
    }

    clearX = frame->x;
    clearSizeX = sizeX;
    if (frame->x < frame->xmin) {
        clearX = frame->xmin;
        clearSizeX = clearSizeX - (s8)(frame->xmin - frame->x);
    }
    if (right >= clipRight) {
        clearSizeX = clearSizeX - (s8)(right - clipRight);
    }

    clearSizeY = sizeY;
    if (clearY < frame->ymin) {
        clearY = frame->ymin;
        clearSizeY = clearSizeY - (s8)(frame->ymin - top);
    }
    if (bottom >= frame->ymax) {
        clearSizeY = clearSizeY - (s8)(bottom - frame->ymax);
    }

    BG_SYS_SetTileEntry(frame->bgFrame, 0, (u8)clearX, (u8)clearY, (u8)clearSizeX, (u8)clearSizeY, 0x10);
    BgWinFrmScreenTransFuncs[wk->transMode](frame->bgFrame);
}

/*
 * bgwinfrm.c.  Arms the scroll animation on one window record: stores the
 * per-frame delta pair and the frame count, sets the 3-bit unk04_13 field
 * to 1, and raises the manager's top bit at offset 6.  Same struct BgWinFrame as
 * src/matched/BGWINFRM_UpdateMove.c, same struct BgWinFrmWork as
 * src/matched/sub_0202CB4C.c.
 */
void BGWINFRM_StartMove(struct BgWinFrmWork *wk, u32 idx, s8 moveX, s8 moveY, u8 count)
{
    struct BgWinFrame *frame = &wk->frames[idx];

    frame->moveX = moveX;
    frame->moveY = moveY;
    frame->moveCount = count;
    frame->moveFlag = 1;
    wk->moving = 1;
}

void BGWINFRM_UpdateMoves(struct BgWinFrmWork *wk)
{
    u32 i;

    if (!wk->moving) return;
    wk->moving = 0;
    for (i = 0; i < wk->frameMax; i++) {
        if (BGWINFRM_UpdateMove(wk, i) == 1) wk->moving = 1;
    }
}

u32 BGWINFRM_UpdateMove(struct BgWinFrmWork *wk, u32 idx)
{
    if (wk->frames[idx].moveFlag == 0) {
        return 0;
    }

    BGWINFRM_HideFrame(wk, idx);
    wk->frames[idx].x = wk->frames[idx].x + wk->frames[idx].moveX;
    wk->frames[idx].y = wk->frames[idx].y + wk->frames[idx].moveY;
    BGWINFRM_ShowFrame(wk, idx);
    wk->frames[idx].moveCount = wk->frames[idx].moveCount - 1;
    if (wk->frames[idx].moveCount == 0) {
        wk->frames[idx].moveFlag = 0;
        return 0;
    }
    return 1;
}

u32 BGWINFRM_IsMoving(struct BgWinFrmWork *wk, u32 idx)
{
    return wk->frames[idx].moveFlag;
}

void BGWINFRM_ChangePalette(struct BgWinFrmWork *wk, u32 idx, s32 x, s32 y,
                   u8 sizeX, u8 sizeY, u8 palette)
{
    u16 *screen = wk->frames[idx].screen;
    u32 rowSize = wk->frames[idx].sizeX;
    s32 bottom = y + sizeY;
    s32 column;

    if (y < bottom) {
        u32 palBits = palette << 12;
        s32 right = x + sizeX;

        do {
            for (column = x; column < right; column = (u16)(column + 1)) {
                screen[y * rowSize + column] = (screen[y * rowSize + column] & 0x0fff)
                                      | palBits;
            }
            y = (u16)(y + 1);
        } while (y < bottom);
    }
}

void BGWINFRM_PutBmpWin(struct BgWinFrmWork *wk, u32 idx, void *bmpWin)
{
    u16 *screen = wk->frames[idx].screen;
    u32 rowSize = wk->frames[idx].sizeX;
    u32 charRow;
    u32 charY;
    u32 charX;
    u32 palBits;
    u16 *dstStart;
    s32 charSizeY;
    u32 charNo;
    s32 charSizeX;

    charNo = BMP_WIN_GetCharOffset(bmpWin);
    palBits = ((u32)BMP_WIN_GetPalette(bmpWin) << 0x1c) >> 0x10;
    charSizeX = BMP_WIN_GetWidth(bmpWin);
    charSizeY = BMP_WIN_GetHeight(bmpWin);
    charX = BMP_WIN_GetPosX(bmpWin);
    charY = BMP_WIN_GetPosY(bmpWin);
    charRow = 0;

    if (charSizeY > 0) {
        dstStart = screen + charX;

        do {
            s32 y = charY + charRow;
            s32 charCol;

            if (y >= wk->frames[idx].sizeY) {
                break;
            }
            charCol = 0;
            if (charSizeX > 0) {
                u16 *dstLine = dstStart + rowSize * y;

                do {
                    if ((s32)(charX + charCol) >= (s32)wk->frames[idx].sizeX) {
                        break;
                    }
                    dstLine[charCol] = palBits + (charNo + charCol);
                    charCol = (u16)(charCol + 1);
                } while (charCol < charSizeX);
            }
            charNo = (u16)(charNo + charSizeX);
            charRow = (u16)(charRow + 1);
        } while ((s32)charRow < charSizeY);
    }
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct BgWinFrame as
 * src/matched/BGWINFRM_UpdateMove.c.  All leaves; the unit calls nothing.
 */
u16 *BGWINFRM_GetFrameBuffer(struct BgWinFrmWork *wk, u32 idx)
{
    return wk->frames[idx].screen;
}

u8 BGWINFRM_GetBgFrame(struct BgWinFrmWork *wk, u32 idx)
{
    return wk->frames[idx].bgFrame;
}

void BGWINFRM_GetPos(struct BgWinFrmWork *wk, u32 idx, s8 *x, s8 *y)
{
    if (x != 0) {
        *x = wk->frames[idx].x;
    }
    if (y != 0) {
        *y = wk->frames[idx].y;
    }
}

void BGWINFRM_GetSize(struct BgWinFrmWork *wk, u32 idx, u16 *sizeX, u16 *sizeY)
{
    if (sizeX != 0) {
        *sizeX = wk->frames[idx].sizeX;
    }
    if (sizeY != 0) {
        *sizeY = wk->frames[idx].sizeY;
    }
}

void BGWINFRM_SetClipArea(struct BgWinFrmWork *wk, u32 idx, s8 xmin, s8 xmax,
                   s8 ymin, s8 ymax)
{
    wk->frames[idx].xmin = xmin;
    wk->frames[idx].xmax = xmax;
    wk->frames[idx].ymin = ymin;
    wk->frames[idx].ymax = ymax;
}

void func_0202D018(void)
{
}

u8 func_0202D01C(u32 a, u32 b, u32 c)
{
    u8 res = (a * c) / b;

    if (res != 0 || a == 0) {
        return res;
    }
    return 1;
}

int func_0202D034(u32 a, u32 b)
{
    a <<= 8;
    b <<= 8;

    if (a > b / 2) {
        return 0;
    }
    if (a > b / 5) {
        return 1;
    }
    if (a != 0) {
        return 2;
    }
    return 3;
}

int POKEGRA_GetArcID(void){ return 4; }

/*
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;
    s32 sexOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), (u32 *)(&sexOffset), 0, 0, 1);
    return sexOffset + (index + dirOffset);
}

s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;
    s32 sexOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), (u32 *)(&sexOffset), 0, 0, 0);
    return sexOffset + (index + dirOffset + 2);
}

/*
 * One of a family of thin wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8: it forwards its own three stack
 * arguments, hands the callee out-pointers for two width accumulators and
 * a status word, and folds the results into a single returned extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKEGRA_GetPalArcIndex.c \
 *       --func POKEGRA_GetPalArcIndex --addr 0x0202D0D4 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 rareOffset;
    s32 palIndex;

    palIndex = 0;
    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), 0, 0, (u32 *)(&rareOffset), (u32 **)(&palIndex), 0);
    if (palIndex == 0) {
        palIndex = index + 0x12 + rareOffset;
    }
    return palIndex;
}

/*
 * The three consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (4, 5, 6).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D110.c \
 *       --addr 0x0202D110 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 4;
}

s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 5;
}

s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 6;
}

/*
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 7;
}

s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 8;
}

void POKEGRA_ConvertCharTo2D(void *charData, u32 heapId)
{
    u8 *raw = ((struct NNSG2dCharacterData *)charData)->pRawData;
    u8 *work;
    u32 rowBytes;
    int i;
    u32 offset;

    work = func_02030734((u16)((heapId & 0x7fff) | 0x8000), 0x1200, 1, PokegraFileName, 0x100);
    MIi_CpuCopyFast(raw, work, 0x1200);

    rowBytes = 0x180;
    offset = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + offset, raw + i * rowBytes, 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + offset, raw + (i * 12 + 8) * 32, 0x80);
        offset += 0x80;
    }

    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + offset, raw + (i * rowBytes + 0xc00), 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + offset, raw + (i * 12 + 0x68) * 32, 0x80);
        offset += 0x80;
    }
    func_020307B0(work);
}

void POKEGRA_ConvertCharTo1D(u32 *charData, u32 heapId)
{
    u8 *raw;
    u8 *work;
    s32 i;
    s32 offset;

    raw = ((struct NNSG2dCharacterData *)charData)->pRawData;
    work = (u8 *)func_02030734((u16)((heapId & 0x7fff) | 0x8000), 0x1200,
                              1, PokegraFileName, 313);
    MIi_CpuCopyFast(raw, work, 0x1200);

    offset = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + i * 0x180, raw + offset, 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + (i * 12 + 8) * 32, raw + offset, 0x80);
        offset += 0x80;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + (0xc00 + i * 0x180), raw + offset, 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + (i * 12 + 0x68) * 32, raw + offset, 0x80);
        offset += 0x80;
    }
    func_020307B0(work);
}

/*
 * pokegra.c (wave 13): stamp four shape tables into a 4bpp tile image.  For
 * each of the four 0xff-terminated (x, y) pair tables at 0x020A779C, offset
 * by the low nibble pair of a1 (minus 8 each, a1 then shifted down a byte per
 * table), locate the pixel's byte in a 12-tile-wide 8x8 tile layout and, when
 * its nibble is colour 1..3, move it to 6..8 (+5 low, +0x50 high).
 *
 * WHAT CLOSED IT (docs/notes/POKEGRA_DrawSpindaSpots.c.txt: 216 against 216, 29 to 39
 * bytes out, "idx in r0 / v in r2" allocation never reached by sixteen
 * spellings, permuter flat): there is NO hoisted byte local.  Each arm reads
 * the pixel byte itself and updates it with a compound assignment,
 * `n = blob[idx] & 0xf0; if (...) blob[idx] += 0x50;`.  The compiler hoists
 * the common load itself, after the `x & 1` test, and that is the register
 * assignment the image has.  The note's "v read inside each arm" attempt
 * (212 bytes) wrote `v = blob[idx]` per arm; the compound `+=` is what makes
 * the two arms' loads identical expressions the compiler can merge.  The
 * quotient locals cx/cy (second pass) and `j = 0` above the terminator test
 * (first pass) stand.
 */
void POKEGRA_DrawSpindaSpots(struct NNSG2dCharacterData *charData, u32 personality)
{
    u8 *raw = charData->pRawData;
    int i;
    int point;
    const u8 *spotTable;
    s32 x, y, tileX, tileY, byteIdx, nibble;

    for (i = 0; i < 4; i++) {
        spotTable = SpindaSpotTables[i];
        point = 0;
        if (spotTable[0] != 0xff) {
            s32 offsetX = (s32)(personality & 0xf) - 8;
            s32 offsetY = (s32)((personality & 0xf0) >> 4) - 8;
            do {
                x = offsetX + (spotTable[point * 2] + 0x16);
                y = offsetY + (spotTable[point * 2 + 1] + 0x10);
                tileX = x / 8;
                tileY = y / 8;
                byteIdx = ((x % 8) + (y % 8) * 8 + (tileX + tileY * 12) * 64) / 2;
                if (x & 1) {
                    nibble = raw[byteIdx] & 0xf0;
                    if (nibble >= 0x10 && nibble <= 0x30)
                        raw[byteIdx] += 0x50;
                } else {
                    nibble = raw[byteIdx] & 0xf;
                    if (nibble >= 1 && nibble <= 3)
                        raw[byteIdx] += 5;
                }
                point++;
            } while (spotTable[point * 2] != 0xff);
        }
        personality >>= 8;
    }
}

/*
 * pokegra.c: resolve a species/form/egg to its graphics archive index, the
 * shiny palette flag (0 or 9), the draw mode and base, checking the
 * narc for the gendered palette variant when mode 1 asks.
 *
 * The 4-byte residue that held through five lanes and 2320 permuter
 * compiles (docs/notes/POKEGRA_CalcArcIndex.c.txt: the two spilled values got
 * sp+4/sp+8 the wrong way round) is a declaration: the 2-way shiny value
 * written to *out_pal is an enum, which changes where the frame allocator
 * puts its spill slot (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md;
 * the permuter's `type` mutation only cycles integer types).  `case 1`
 * is written before `case 2`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKEGRA_CalcArcIndex.c  *       --func POKEGRA_CalcArcIndex --addr 0x0202D4A8 --thumb --cc 1.1p1
 */
void POKEGRA_CalcArcIndex(void *arcId, u32 monsNo, s32 formNo, s32 sex,
                   u32 rare, u32 dir, u32 egg,
                   u32 *outIndex, u32 *outDirOffset, u32 *outSex, u32 *outRare,
                   u32 **outFormPalIndex, u32 isCgr)
{
    s32 index;
    s32 formCount;
    s32 formStart;
    s32 palOnlyForms;
    PokegraDirOffset dirOffset;
    s32 sexFileOffset;

    index = monsNo * 0x14;

    if (dir == 0) {
        dirOffset = 0;
    } else {
        dirOffset = 9;
    }

    if (isCgr != 0) {
        if (dir == 0) {
            sexFileOffset = 0;
        } else {
            sexFileOffset = 9;
        }
    } else {
        if (dir == 0) {
            sexFileOffset = 2;
        } else {
            sexFileOffset = 0xb;
        }
    }

    if (egg != 0) {
        s32 isManaphy;

        if (monsNo == 0x1ea) {
            isManaphy = 1;
        } else {
            isManaphy = 0;
        }
        index = (isManaphy + 0x28a) * 0x14;
    } else if (formNo != 0) {
        formStart = (s32)POKE_TOOL_GetPersonalParam((u16)monsNo, 0, 0x1f);
        palOnlyForms = (s32)POKE_TOOL_GetPersonalParam((u16)monsNo, 0, 0x23);
        formCount = (s32)POKE_TOOL_GetPersonalParam((u16)monsNo, 0, 0x20);
        if (formNo >= formCount) {
            formNo = 0;
        }
        if (palOnlyForms != 0) {
            if (outFormPalIndex != 0 && formNo != 0) {
                *outFormPalIndex = (u32 *)(rare + (u32)((formStart + formNo - 1) * 2 + 0x37ad));
            }
        } else if (formNo != 0) {
            index = (formStart + formNo - 1) * 0x14 + 0x32f0;
        }
    }

    switch (sex) {
    case 0:
        break;
    case 1:
        formCount = ARC_TOOL_GetMemberSize((u32)arcId, (u32)(index + sexFileOffset + 1));
        sex = 1;
        if (formCount == 0) {
            sex = 0;
        }
        break;
    case 2:
        sex = 0;
        break;
    default:
        break;
    }

    if (outIndex != 0) {
        *outIndex = (u32)index;
    }
    if (outDirOffset != 0) {
        *outDirOffset = (u32)dirOffset;
    }
    if (outSex != 0) {
        *outSex = (u32)sex;
    }
    if (outRare != 0) {
        *outRare = rare;
    }
}

u32 POKEGRA_GetTrainerArcID(u32 isBack)
{
    if (isBack != 0) {
        return 0x49;
    }
    return 0x48;
}

u32 POKEGRA_GetTrainerCgrArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8;
}

u32 POKEGRA_GetTrainerCbrArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 1;
}

u32 POKEGRA_GetTrainerPalArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 7;
}

u32 POKEGRA_GetTrainerCelArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 2;
}

u32 POKEGRA_GetTrainerAnmArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 3;
}

u32 POKEGRA_GetTrainerMCelArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 4;
}

u32 POKEGRA_GetTrainerMAnmArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 5;
}

u32 POKEGRA_GetTrainerNcecArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 6;
}

/*
 * Unpacks a party mon into the nine-argument sprite request of
 * POKEGRA_LoadCharData: species (5), form (0x6F), gender (0x6E), the shiny
 * predicate POKE_TOOL_IsBoxShiny, isEgg (0x4C) and the personality word (id 0)
 * are read in that order, then forwarded along with the caller's own
 * a2/a3 pass-throughs.
 */
void *POKEGRA_LoadCharDataPP(u32 *outCharData, void *pp, u32 dir, u16 heapId)
{
    u32 monsNo;
    u32 formNo;
    u32 sex;
    u32 rare;
    u32 egg;

    monsNo = func_02017E88(pp, 5, 0);
    formNo = func_02017E88(pp, 0x6F, 0);
    sex = func_02017E88(pp, 0x6E, 0);
    rare = POKE_TOOL_IsBoxShiny(pp);
    egg = func_02017E88(pp, 0x4C, 0);
    return POKEGRA_LoadCharData(outCharData, monsNo, formNo, sex, rare, dir, egg,
                         func_02017E88(pp, 0, 0), heapId);
}

/*
 * Builds a sprite/resource request: POKEGRA_GetCgrArcIndex turns the mon
 * descriptor (species/form/gender plus the three stack words) into a
 * resource id, which func_02049E34 instantiates with the caller's
 * out-slot `a0` as its a3 payload.  When the species word a1 is the
 * sentinel 0x147 the freshly filled *a0 is additionally run through the
 * POKEGRA_ConvertCharTo2D / POKEGRA_DrawSpindaSpots / POKEGRA_ConvertCharTo1D triple, which is why
 * `*a0` is re-read before each of them (POKEGRA_DrawSpindaSpots may store through
 * it, so the load cannot be cached).  This answers the open question in
 * docs/notes/POKEGRA_RegisterCgr.c.txt: a0 is a genuine out-parameter, written
 * by func_02049E34 via its a3, not read-only.
 *
 * Blocked at MATCH: every concrete byte is identical.  2026-09-21, unblock
 * lane: ONE OF THE TWO BLOCKING SITES IS NOW CLEARED.  POKEGRA_ConvertCharTo1D was
 * filed EXACT (src/matched/POKEGRA_ConvertCharTo1D.c, shard arm9/pkt_0202D2EC.json),
 * so the +0x58 THM_CALL resolves `matched`.  Only +0x50, the call to
 * POKEGRA_DrawSpindaSpots, is still wildcarded: this function is that address's only
 * caller image-wide, so no evidence class (label/matched) can attest it and
 * nothing but an EXACT at 0x0202D3D0 will promote this file.  That function
 * is a documented near miss, now at 29 concrete mismatches (down from 41)
 * and stuck on one register-assignment decision -- see
 * docs/notes/POKEGRA_DrawSpindaSpots.c.txt, which records the lever that halved it
 * and the twelve spellings that do not move it further.
 */
void *POKEGRA_LoadCharData(u32 *outCharData, u32 monsNo, u32 formNo, u32 sex,
                    u32 rare, u32 dir, u32 egg, u32 personality, volatile u16 heapId)
{
    u32 arcIndex;
    void *file;

    arcIndex = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), monsNo, formNo, sex, rare, dir, egg);
    file = func_02049E34(POKEGRA_GetArcID(), arcIndex, 1, (u32)outCharData, heapId);
    if (monsNo == 0x147) {
        POKEGRA_ConvertCharTo2D((void *)(*outCharData), heapId);
        POKEGRA_DrawSpindaSpots((struct NNSG2dCharacterData *)(*outCharData), personality);
        POKEGRA_ConvertCharTo1D((u32 *)(*outCharData), heapId);
    }
    return file;
}

void *POKEGRA_OpenHandle(u32 heapId)
{
    return func_020490F4(POKEGRA_GetArcID(), heapId);
}

int POKEGRA_RegisterPalette(int handle, int monsNo, int formNo, int sex, int rare, int dir, int egg, int drawType,
                   unsigned short palOffset, unsigned short heapId)
{
    int arcId = POKEGRA_GetArcID();
    int palIndex = POKEGRA_GetPalArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg);
    return CLACT_RegisterPaletteEx((void *)handle, palIndex, drawType, palOffset, 0, 1, heapId);
}

/*
 * Issues a request through CLACT_RegisterCharacter built from a by-value tail struct
 * in the caller's frame (five words plus a u16 key at +0x14) and the
 * context POKEGRA_GetArcID()/POKEGRA_GetCgrArcIndex() pair; when a1 is the sentinel
 * 0x147 it additionally runs the same tail through POKEGRA_LoadCharData with the
 * address of a local out-slot, hands that slot's word to CLACT_TransferCharacter
 * alongside the request handle, and releases POKEGRA_LoadCharData's result through
 * func_020307B0. The request handle is returned either way.
 *
 * Three things the C has to say exactly, all found this session (the
 * earlier DIFF is docs/notes/POKEGRA_RegisterCgr.c.txt):
 *   - the tail parameter must be `volatile`. Without it the front end
 *     re-homes the register arguments into the frame, grows `sub sp` from
 *     0x18 to 0x28 and 89 bytes differ.
 *   - the key sits at +0x14 of the tail, not +0x10: the struct carries five
 *     u32 words (s0..s4) ahead of it, and s4 is CLACT_RegisterCharacter's own stack
 *     argument read from [sp,#0x40].
 *   - `k` and `v` must be separate named locals read in that order just
 *     before the CLACT_RegisterCharacter call. Passing `t.key`/`t.s4` inline (in
 *     either order, with or without a cast away from volatile, and with the
 *     stack arg typed u16) schedules `ldr r3,[sp,#0x40]` after the
 *     `movs r2,#1`/`str r0,[sp]` pair instead of before it: the last 6 bytes
 *     of the DIFF, and the only thing that moves them.
 *
 * The out-slot at sp+0x14 is real: POKEGRA_LoadCharData reads `*a0` three times and
 * never stores through it, so the `ldr r1,[sp,#0x14]` after the call reads
 * back an uninitialised local. That is what the original does; the note's
 * open question about a hidden write inside POKEGRA_LoadCharData is resolved as
 * "there is none, and the C does not need one".
 */
u32 POKEGRA_RegisterCgr(u32 handle, u32 monsNo, u32 formNo, u32 sex, volatile u32 rare, volatile u32 dir,
                  volatile u32 egg, volatile u32 personality, volatile u32 drawType, volatile u16 heapId)
{
    u32 charFile;
    u32 cgrIndex;
    u32 cgrArcIndex;
    u32 heap;
    u32 vramType;
    void *charData;

    cgrArcIndex = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), monsNo, formNo, sex, rare, dir, egg);
    heap = heapId;
    vramType = drawType;
    cgrIndex = CLACT_RegisterCharacter((void *)handle, cgrArcIndex, 1, vramType, heap);
    if (monsNo == 0x147) {
        charFile = (u32)POKEGRA_LoadCharData((u32 *)(&charData), monsNo, formNo, sex, rare, dir, egg, personality, heapId);
        CLACT_TransferCharacter(cgrIndex, (struct Sub0204A9D0 *)((u32)charData));
        func_020307B0((void *)charFile);
    }
    return cgrIndex;
}

/*
 * Builds a record out of an argument struct passed by value in the caller's
 * frame: both cursors come from func_02027710/func_02027714 on the same +8
 * word, the handle from func_020490F4 keyed on the +0x10 halfword with the
 * mode word from func_020275E4, and CLACT_RegisterCellAnim assembles the pair into
 * it; the handle is released before the assembled record is returned.
 *
 * The `volatile` on the by-value struct parameter is load-bearing, not
 * decoration: without it this front end proves the two callees cannot touch
 * the caller's frame, keeps args.w2 live in r5 across the first call and
 * drops the second `ldr r0,[sp,#0x20]`, and it also hoists the `ldrh` of
 * args.key above the inline func_020275E4() call. Qualifying the whole
 * parameter (rather than aliasing it through a volatile pointer, which
 * turns the two w2 loads into `[r5,#8]` and loses the `add r7,sp,#0x18`)
 * reproduces the reload, the argument scheduling and both `ldrh`s exactly.
 * See docs/notes/POKEGRA_RegisterCellAnim.c.txt for the DIFF this replaces.
 *
 * EXACT* only: the follower at 0x0202D8D0 is unlabelled, so the inferred
 * extent runs 2 bytes long over the alignment halfword. Never a byte
 * difference.
 */
u32 POKEGRA_RegisterCellAnim(u32 monsNo, u32 formNo, u32 sex, u32 rare, volatile u32 dir, volatile u32 egg,
                  volatile u32 mapping, volatile u32 unusedArg, volatile u16 heapId)
{
    u32 cellDatId;
    u32 anmDatId;
    void *handle;
    u32 cellIndex;

    cellDatId = func_02027710(mapping);
    anmDatId = func_02027714(mapping);
    handle = func_020490F4(func_020275E4(), heapId);
    cellIndex = CLACT_RegisterCellAnim(handle, cellDatId, anmDatId, heapId);
    ARC_TOOL_DeleteHandle(handle);
    return cellIndex;
}

int POKEGRA_RegisterPalettePP(int handle, void *pp, int dir, int drawType, unsigned short palOffset, unsigned short heapId)
{
    int monsNo = func_02017E88(pp, 5, 0);
    int formNo = func_02017E88(pp, 0x6f, 0);
    int sex = func_02017E88(pp, 0x6e, 0);
    int rare = POKE_TOOL_IsBoxShiny(pp);
    int egg = func_02017E88(pp, 0x4c, 0);

    return POKEGRA_RegisterPalette(handle, monsNo, formNo, sex, rare, dir, egg, drawType, palOffset, heapId);
}

int POKEGRA_RegisterCgrPP(int handle, void *pp, int dir, int drawType, unsigned short heapId)
{
    int monsNo = func_02017E88(pp, 5, 0);
    int formNo = func_02017E88(pp, 0x6f, 0);
    int sex = func_02017E88(pp, 0x6e, 0);
    int rare = POKE_TOOL_IsBoxShiny(pp);
    int egg = func_02017E88(pp, 0x4c, 0);
    int personality = func_02017E88(pp, 0, 0);

    return POKEGRA_RegisterCgr(handle, monsNo, formNo, sex, rare, dir, egg, personality, drawType, heapId);
}

/*
 * Collects five properties off the handle (func_02017E88 with selectors 5,
 * 0x6f, 0x6e and 0x4c, plus POKE_TOOL_IsBoxShiny) and forwards them into
 * POKEGRA_RegisterCellAnim together with this function's own three trailing words and
 * its u16 key, tail-position, returning what POKEGRA_RegisterCellAnim returns.
 *
 * Arity note (this is what the earlier note was blocked on): POKEGRA_RegisterCellAnim
 * itself is written with a by-value `volatile struct Args` trailing
 * parameter, because that is the only shape that reproduces ITS body -- but
 * the caller must NOT be written that way. Declaring the extern with the
 * aggregate, and building it in a named local (volatile or not), makes the
 * front end materialise the struct in the frame and copy it out with
 * ldm/stm: `sub sp` grows 0x24 -> 0x38 and 49 bytes differ. A C99 compound
 * literal at the call site is worse still (zero-fills first, 77 bytes).
 * Spelling the same five trailing words as plain scalars in this
 * translation unit's own prototype writes them straight into the outgoing
 * block and is EXACT. The two spellings agree on the ABI, so both files are
 * correct about the boundary; only the callee's side needs the aggregate.
 *
 * EXACT* only: the follower at 0x0202DA04 is unlabelled, so the inferred
 * extent runs over the trailing alignment halfword. Never a byte difference.
 */
u32 POKEGRA_RegisterCellAnimPP(u32 pp, u32 dir, u32 mapping, u32 unusedArg, u16 heapId)
{
    u32 monsNo;
    u32 formNo;
    u32 sex;
    u32 rare;

    monsNo = func_02017E88((void *)pp, 5, 0);
    formNo = func_02017E88((void *)pp, 0x6f, 0);
    sex = func_02017E88((void *)pp, 0x6e, 0);
    rare = POKE_TOOL_IsBoxShiny((void *)pp);

    return POKEGRA_RegisterCellAnim(monsNo, formNo, sex, rare,
                         dir, func_02017E88((void *)pp, 0x4c, 0), mapping, unusedArg, heapId);
}

void *POKEGRA_OpenTrainerHandle(u32 heapId)
{
    return func_020490F4(POKEGRA_GetTrainerArcID(0), heapId);
}

s32 POKEGRA_RegisterTrainerPalette(u32 handle, u32 trType, u32 drawType, u32 palOffset, u16 heapId)
{
    return CLACT_RegisterPaletteEx((void *)handle, POKEGRA_GetTrainerPalArcIndex(trType, 0), drawType, palOffset, 0, 1, heapId);
}

void POKEGRA_RegisterTrainerCgr(u32 handle, u32 trType, u32 drawType, u32 heapId)
{
    CLACT_RegisterCharacter((void *)handle, POKEGRA_GetTrainerCgrArcIndex(trType, 0), 1, drawType, heapId);
}

s32 POKEGRA_RegisterTrainerCellAnim(u32 unusedArg, u32 mapping, u32 drawType, u16 heapId)
{
    u32 cellDatId;
    u32 anmDatId;
    void *handle;
    s32 cellIndex;

    cellDatId = func_02027718(mapping);
    anmDatId = func_0202771C(mapping);
    handle = func_020490F4(func_020275E4(), heapId);
    cellIndex = CLACT_RegisterCellAnim(handle, cellDatId, anmDatId, heapId);
    ARC_TOOL_DeleteHandle(handle);
    return cellIndex;
}

/*
 * Loads two archived resources into a pair of consumers.  Each half
 * turns the caller's id into an archive entry index (POKEGRA_GetTrainerPalArcIndex for
 * the first, POKEGRA_GetTrainerCgrArcIndex for the second), pulls the entry out of the
 * archive set named by the fifth, stack-passed u16 argument, hands the
 * unpacked payload to its consumer and then frees the container with
 * the common finalizer func_020307B0.
 *
 * The u16 fifth argument is re-read from the incoming argument area for
 * the second call rather than cached, so it is spelled as a `volatile
 * u16' stack parameter.
 */
void POKEGRA_LoadTrainerGraphics(void *handle, u32 trType, void *charDst, void *palDst, volatile u16 heapId)
{
    void *file;
    void *palData;
    void *charData;

    file = ARC_TOOL_LoadHandleMember(handle, POKEGRA_GetTrainerPalArcIndex(trType, 0), heapId);
    NNS_G2dGetUnpackedPaletteData(file, &palData);
    CLACT_TransferPalette(palDst, palData, 1);
    func_020307B0(file);

    file = func_02049E74(handle, POKEGRA_GetTrainerCgrArcIndex(trType, 0), 1, (u32)(&charData), heapId);
    CLACT_TransferCharacter((int)charDst, charData);
    func_020307B0(file);
}

/*
 * The PmsDraw constructor.  Closed 2026-09-23 from the 68-byte near miss
 * in docs/notes/pkt_0202DB0C.c.txt by two changes:
 *   - the second allocator's heap is a named u16 local read back from
 *     p->heap IMMEDIATELY after the store (`h = p->heap;`), so it is the
 *     same value as the strh operand and stays in r0 across the three
 *     field stores; `p->heap` written at the call re-reads it, the `heap`
 *     parameter makes it a callee-saved copy from the prologue;
 *   - the fifth parameter is u8 after all (`ldrb` at the PMS_DRAW_LoadResources
 *     site); it only looked like it cost four bytes while the heap value
 *     was wrong.
 * The allocator result still has to go through a named local before p.
 */
struct PmsDraw *PMS_DRAW_Create(u32 clunit, u32 drawType, u32 printQue, u32 font, u8 plttOffset, u8 elemMax, u16 heapId)
{
    struct PmsDraw *wk;
    u32 size;
    u16 heap;
    int i;
    struct PmsDraw *alloc = func_02030734(heapId, 0x34, 1, PmsDrawFileName, 0x81);

    wk = alloc;
    MI_CpuFill8(wk, 0, 0x34);
    wk->heapId = heapId;
    heap = wk->heapId;
    wk->printQue = (void *)printQue;
    wk->font = font;
    wk->elemMax = elemMax;
    wk->nullColorPalette = 0xf;
    wk->followBgScroll = 0;
    size = elemMax * 0x28;
    wk->elems = func_02030734(heap, size, 1, PmsDrawFileName, 0x8c);
    MI_CpuFill8(wk->elems, 0, size);
    wk->res[0] = clunit;
    wk->res[1] = drawType;
    wk->printColor = 0x11 << 6;
    PMS_DRAW_LoadResources(wk->res, plttOffset, wk->heapId);
    for (i = 0; i < wk->elemMax; i++) {
        PMS_DRAW_InitElem(&wk->elems[i], (struct PmsDrawRes *)wk->res, wk->heapId);
    }
    return wk;
}

/*
 * Picks the selected entry of the 0x28-byte element array hung off +0xc:
 * the selection at +0x28 is primed to 1, then every element whose +0x18
 * bit 0 is set is offered to PMS_DRAW_UpdateElem along with the two cursor
 * words at +8 and +0x2c; the first one that answers non-zero resets the
 * selection to 0.  The count at +0x30 is a signed char and is re-read at
 * the top of every iteration (the call may change it), which is what
 * keeps the `adds r0, r5, #0x30; ldrb` pair inside the loop -- 0x30 is
 * past the Thumb `ldrb` immediate reach of +31.
 */
void PMS_DRAW_Main(struct PmsDraw *wk)
{
    s32 i;

    wk->printEnd = 1;
    for (i = 0; i < (s32)wk->elemMax; i++) {
        struct PmsElem *elem = wk->elems + i;
        if (elem->flags.bits.active != 0) {
            if (PMS_DRAW_UpdateElem(elem, wk->printQue, wk->followBgScroll) != 0) {
                wk->printEnd = 0;
            }
        }
    }
}

void PMS_DRAW_Delete(struct PmsDraw *wk)
{
    int i;

    for (i = 0; i < wk->elemMax; i++) {
        PMS_DRAW_DeleteElem(wk->elems + i);
    }

    func_020307B0(wk->elems);
    PMS_DRAW_ReleaseResources((struct PmsDrawRes *)wk->res);
    func_020307B0(wk);
}

void PMS_DRAW_Print(u32 wk, u32 bmpWin, u32 pms, u32 id)
{
    u32 offset[2] = { 0, 0 };

    PMS_DRAW_PrintOffset((struct PmsDraw *)wk, (void *)bmpWin, (void *)pms, id, offset);
}

/*
 * The forwarding shim in front of PMS_DRAW_PrintElem: it copies four of the
 * object's own fields into the callee's five stack arguments and clears
 * the selection word at +0x28 afterwards.
 *
 * The ARGUMENT ORDER is what this function pins, and it corrects the
 * reading in docs/notes/pkt_0202E1F0.anmSeq.txt: r1 is the object pointer at
 * +8, r2 the word at +4 and r3 the caller's own `a`, which the prologue
 * parks in r4 (`adds r4, r1, #0`) precisely because it is consumed LAST.
 * Spelling the call (e, a, p->plttIndex, p->drawType, ...) instead leaves `a` in r1
 * and loses the r4 copy, four bytes short.
 *
 * The five stack words are four plain u32 arguments behind `w`, not a
 * 16-byte struct passed by value: a by-value struct makes the compiler
 * build a local and ldm/stm it into the outgoing area (18 bytes more),
 * whereas the original stores each field straight to its slot. The
 * halfword fields at +0x24, +0x31 and +0x00 are widened to words at the
 * call, so the parameters are u32.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_PrintOffset.anmSeq \
 *       --func PMS_DRAW_PrintOffset --addr 0x0202DC60 --cc 1.1p1 --thumb
 */
void PMS_DRAW_PrintOffset(struct PmsDraw *wk, void *bmpWin, void *pms, u32 id, const void *offset)
{
    PMS_DRAW_PrintElem(wk->elems + id, wk->printQue, wk->font, bmpWin, pms,
                  offset, wk->printColor, wk->nullColorPalette, wk->heapId);
    wk->printEnd = 0;
}

/*
 * Three leaves before PMS_DRAW_IsActive over an object with a count at +0x28 and
 * an array of 0x28-byte elements at +0xc: the count getter, and two
 * forwarders that pass element i and one argument to PMS_DRAW_ClearElem and
 * PMS_DRAW_SetElemVisible.  Seeded from ov031 0x021F069A, ov110 0x021C0CC6, ov111
 * 0x021C61D2, ov216 0x021BD12A.
 *
 * Addresses are Black-image addresses.
 */
u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *wk)
{
    return wk->printEnd;
}

void PMS_DRAW_Clear(struct PmsDraw *wk, int id, u32 isTrans)
{
    PMS_DRAW_ClearElem(&wk->elems[id], isTrans);
}

void PMS_DRAW_SetVisible(struct PmsDraw *wk, int id, u32 visible)
{
    PMS_DRAW_SetElemVisible(&wk->elems[id], visible);
}

u32 PMS_DRAW_IsActive(const struct PmsDraw *wk, u32 id)
{
    return wk->elems[id].flags.bits.active;
}

void PMS_DRAW_SetDecoVisible(struct PmsDraw *wk, u32 id, u32 visible)
{
    if (PMS_DRAW_IsActive(wk, id) != 0) {
        wk->elems[id].flags.bits.decoVisible = visible;
    }
}

void PMS_DRAW_SetDecoPriority(struct PmsDraw *wk, u32 id, u32 priority)
{
    int i;

    for (i = 0; i < 2; i++) {
        CLACT_SetActorObjMode(wk->elems[id].decoActor[i], priority);
    }
}

/*
 * Copies element i onto element j of the pms_draw owner, sprite state
 * included (docs/families/pms_draw.h). EXACT* only because the listing
 * extent runs on over the three unlabelled setters at 0x0202DE5C
 * (src/matched/unit_0202DE5C.anmSeq); the function itself is 310 bytes.
 *
 * Closed in wave 14 from the wave-12 note (8 bytes, dst/dy spill slots):
 *   - the handles are read through the element pointers, src->bmpWin and
 *     dst->bmpWin, not e[i]/e[j]; the compiler still folds them to the
 *     image's `ldr r0,[r6,r7]` / `ldr r0,[r6,dj]`, but dst now stays a
 *     named value and takes the image's slot sp+8;
 *   - no `e` local: src = &p->elems[i]; dst = &p->elems[j];
 *   - dx declared before dy (dx at sp+4, dy at sp+0);
 *   - the loop counter k declared FIRST: with src declared ahead of it,
 *     src takes r4 and the call temporaries/k take r5, the mirror image.
 */
void PMS_DRAW_Copy(struct PmsDraw *wk, u32 srcId, u32 dstId)
{
    int i;
    struct PmsElem *src;
    struct PmsElem *dst;
    s32 dx;
    s32 dy;
    u32 surface;
    struct PmsPoint pt;
    void *bmpWin;

    src = &wk->elems[srcId];
    dst = &wk->elems[dstId];
    dx = BMP_WIN_GetPosX(dst->bmpWin) - BMP_WIN_GetPosX(src->bmpWin);
    dy = BMP_WIN_GetPosY(dst->bmpWin) - BMP_WIN_GetPosY(src->bmpWin);
    BMP_CopyPixels((struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)src->bmpWin)), (const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)dst->bmpWin)));
    bmpWin = dst->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    func_02041B6C(BMP_WIN_GetBgLayer(bmpWin));

    for (i = 0; i < 2; i++) {
        surface = PMS_DRAW_GetFrameSurface(BMP_WIN_GetBgLayer(src->bmpWin));
        CLACT_GetActorSurfacePos(src->decoActor[i], (struct PtS *)&pt, (u16)surface);
        pt.x += dx * 8;
        pt.y += dy * 8;
        CLACT_AddActorSurfacePos(dst->decoActor[i], (const struct Vec2 *)(&pt), (u16)surface);
        CLACT_SetActorAnimSeq(dst->decoActor[i], CLACT_GetActorAnimSeq(src->decoActor[i]));
        CLACT_SetActorDrawEnable(dst->decoActor[i], src->isDeco[i]);
    }
    dst->printing = src->printing;
    dst->flags.bits.active = src->flags.bits.active;
    dst->flags.bits.visible = src->flags.bits.visible;
    for (i = 0; i < 2; i++) {
        dst->isDeco[i] = src->isDeco[i];
    }
}

void PMS_DRAW_SetNullColorPalette(struct PmsDraw *wk, u8 palette)
{
    wk->nullColorPalette = palette;
}

void PMS_DRAW_SetPrintColor(struct PmsDraw *wk, u16 color)
{
    wk->printColor = color;
}

void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *wk, u32 follow)
{
    wk->followBgScroll = follow;
}

void PMS_DRAW_CalcDecoPos(u32 bmpWin, u32 charX, u32 line, const struct PmsPos *offset,
                  struct PmsPos *out)
{
    out->x = offset->x + (charX + BMP_WIN_GetPosX((struct Descriptor *)bmpWin) * 8);
    out->y = offset->y + ((line << 4) + BMP_WIN_GetPosY((struct Descriptor *)bmpWin) * 8);
}

u32 PMS_DRAW_GetDecoCgrIndex(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x21;
    case 0x00100010:
        return 0x22;
    case 0x00200010:
        return 0x20;
    }
    return 0x20;
}

u32 PMS_DRAW_GetDecoCelIndex(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x27;
    case 0x00100010:
        return 0x28;
    case 0x00200010:
        return 0x26;
    }
    return 0x26;
}

u32 PMS_DRAW_GetDecoAnmIndex(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x2D;
    case 0x00100010:
        return 0x2E;
    case 0x00200010:
        return 0x2C;
    }
    return 0x26;
}

/*
 * Builds the four handles of the pms_draw sub-object at +0x10 of its
 * owner: the three VRAM-bank queries of unit_0202DE9C are taken first
 * (off the engine word at +4), a 0x2b resource set is opened on the
 * caller's heap, and ENV_SetResourceSet / CLACT_RegisterCharacter / CLACT_RegisterCellAnim
 * fill +8, +0xc and +0x10 before the set is closed again.
 *
 * The screen-size argument to ENV_SetResourceSet is `(u16)(a1 << 5)`, the
 * unequal shift pair lsls #0x15 / lsrs #0x10 -- a narrowing cast folded
 * with the shift, not an 11-bit bitfield.
 */
void PMS_DRAW_LoadResources(u32 *res, u32 plttOffset, u32 heapId)
{
    u32 cgrDatId;
    u32 celDatId;
    u32 anmDatId;
    void *handle;

    cgrDatId = PMS_DRAW_GetDecoCgrIndex(res[1]);
    celDatId = PMS_DRAW_GetDecoCelIndex(res[1]);
    anmDatId = PMS_DRAW_GetDecoAnmIndex(res[1]);
    handle = func_020490F4(0x2b, heapId);
    res[2] = CLACT_RegisterPaletteEx(handle, 1, res[1], (u16)(plttOffset << 5), 0, 5, heapId);
    res[3] = CLACT_RegisterCharacter(handle, anmDatId, 0, res[1], heapId);
    res[4] = CLACT_RegisterCellAnim(handle, cgrDatId, celDatId, heapId);
    ARC_TOOL_DeleteHandle(handle);
}

void PMS_DRAW_ReleaseResources(struct PmsDrawRes *res)
{
    CLACT_ReleasePalette(res->plttIndex);
    CLACT_ReleaseCharacter(res->cgrIndex);
    CLACT_ReleaseCellAnim(res->cellAnmIndex);
}

/*
 * Creates one actor out of the five-word resource record the owner keeps
 * at +0x10 (PMS_DRAW_LoadResources is what fills it), disables it, enables its
 * second flag, and adds the 0x2000 bit only for language 0x1e.
 *
 * The four zero halfwords at sp+0xc must be written as a BRACE
 * INITIALISER, `struct DecoActorInit z = { 0, 0, 0, 0 };`.  Assigning the four
 * fields as statements -- with or without the address bound to a named
 * pointer local -- swaps r0 and r2 throughout the block (the compiler
 * materialises the zero first and the frame address second, and then
 * re-materialises `add r0, sp, #0xc` for the outgoing slot), which is
 * seventy concrete bytes out and is the whole residue this function had.
 * The permuter (hill and anneal, 3800 compiles, --types) could not reach
 * it from the statement form: no body mutation moves an initialiser's
 * definition order.
 *
 * `one` exists because the original materialises 1 twice, once as the
 * r1 argument to CLACT_SetActorAutoAnim and once into r4 to survive the
 * func_02035630 call and become `lsls r1, r4, #0xd`; writing the shift
 * as a bare `0x2000` costs a pool word instead.
 *
 * The follower at 0x0202E040 is reached across two bytes of linker fill
 * at 0x0202E03E, which is the 82-against-84 the star records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_CreateDecoActor.anmSeq \
 *       --func PMS_DRAW_CreateDecoActor --addr 0x0202DFEC --cc 1.1p1 --thumb
 */
void *PMS_DRAW_CreateDecoActor(struct PmsDrawRes *res, u16 heapId)
{
    struct DecoActorInit init = { 0, 0, 0, 0 };
    void *actor;
    u32 one;

    actor = CLACT_CreateActor((void *)res->clunit, res->cgrIndex, res->plttIndex, res->cellAnmIndex, &init, (u16)res->drawType, heapId);
    CLACT_SetActorDrawEnable(actor, 0);
    one = 1;
    CLACT_SetActorAutoAnim(actor, 1);
    if (func_02035630() == 0x1e) {
        CLACT_SetActorAutoAnimSpeed(actor, one << 0xd);
    }
    return actor;
}

/*
 * Places one element sprite: sub_0202DE6C resolves the cell offset into a
 * pair of u32s, which are narrowed into the adjacent u16 pair the
 * CLACT_AddActorSurfacePos setter wants, then the cell's own id decides the priority
 * word through sub_0202E430 and the last stack argument (a 1-based index)
 * is passed on as `(u16)(n - 1)`.
 */
void PMS_DRAW_PlaceDecoActor(void *actor, struct Descriptor *bmpWin, u32 charX, u32 line,
                   u32 wordId, const struct PmsPos *offset)
{
    struct PmsPos pos;
    struct DecoPos pt;
    u32 frame;

    PMS_DRAW_CalcDecoPos((u32)bmpWin, charX, line, (const struct PmsPos *)offset, (struct PmsPos *)(&pos));
    pt.x = (u16)pos.x;
    pt.y = (u16)pos.y;
    frame = BMP_WIN_GetBgLayer(bmpWin);
    CLACT_AddActorSurfacePos(actor, (const struct Vec2 *)(&pt), (u16)PMS_DRAW_GetFrameSurface(frame));
    CLACT_SetActorBgPriority(actor, BG_SYS_Get(frame));
    CLACT_SetActorAnimSeq(actor, (u16)(wordId - 1));
}

/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): the loop counter is signed,
 *           the image compares with blt; u32 gave blo (1 byte)
 */
void PMS_DRAW_InitElem(struct PmsElem *elem, struct PmsDrawRes *res, u16 heapId)
{
    int i;

    for (i = 0; i < 2; i++) {
        elem->decoActor[i] = PMS_DRAW_CreateDecoActor(res, heapId);
    }
    elem->flags.word = (elem->flags.word & ~1) | 4;
}

void PMS_DRAW_DeleteElem(struct PmsElem *elem)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor(elem->decoActor[i]);
    }
}

int PMS_DRAW_UpdateElem(struct PmsElem *elem, void *printQue, int followBgScroll)
{
    int ret;
    s32 i;

    if (elem->printing != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(elem->bmpWin)) == 0) {
            BMP_WIN_TransferChars(elem->bmpWin);
            elem->printing = 0;
        }
    }

    ret = (elem->printing != 0) ? 1 : 0;
    if (ret == 0) {
        if (elem->flags.bits.visible) {
            for (i = 0; i < 2; i++) {
                if (elem->isDeco[i] != 0 && elem->flags.bits.decoVisible) {
                    CLACT_SetActorDrawEnable(elem->decoActor[i], 1);
                } else {
                    CLACT_SetActorDrawEnable(elem->decoActor[i], 0);
                }
            }
        }
    }

    if (followBgScroll != 0) {
        s32 frame = (s32)BMP_WIN_GetBgLayer(elem->bmpWin);
        struct PmsPoint diff = { 0, 0 };
        struct PmsPoint pos;
        s32 scrollX;
        s32 scrollY;
        scrollX = BG_SYS_GetScrollX_1648((u8)frame);
        scrollY = BG_SYS_GetScrollY_1664((u8)frame);

        if (scrollX != elem->scrollX) {
            diff.x = elem->scrollX - scrollX;
            elem->scrollX = scrollX;
        }

        if (scrollY != elem->scrollY) {
            diff.y = elem->scrollY - scrollY;
            elem->scrollY = scrollY;
        }

        if (diff.x != 0 || diff.y != 0) {
            for (i = 0; i < 2; i++) {
                CLACT_GetActorPos(elem->decoActor[i], &pos);
                pos.x += diff.x;
                pos.y += diff.y;
                CLACT_SetActorPos(elem->decoActor[i], &pos);
            }
        }
    }

    return ret;
}

/*
 * blink_palanm: set up a message's blink palette animation.  Copy the
 * caller's PmsData into a local, build the string, mark which characters
 * blink (wk->blink[i]) or are blank (mark[i]), draw the window, then start
 * a palette animation (PMS_DRAW_PlaceDecoActor) on every blinking character and clear
 * every blank one.  Only caller: PMS_DRAW_PrintOffset, which passes the five stack
 * words (param, pos, pri, pal, heap).
 *
 * Closed 2026-09-24 (wave 21, lane E12) from DIFF 2
 * (docs/notes/pkt_0202E1F0.anmSeq.txt, waves 5-21).  Two things together,
 * neither enough on its own:
 *   - the parameter `param` is reused as `param = &mp` after the copy, and
 *     every later call, including PMSI_PARAM_ToStringWords after loop 1, takes
 *     `param` (with `&mp` there the image's `adds r0, r7, #0` at +0x8E is
 *     rematerialised as `add r0, sp, #0x38`, 2 out);
 *   - the two stores after PMSI_PARAM_Validate are written msg first, then
 *     active.  In the other order the compile puts wk in r7 and param in r6
 *     (21 out).  The scheduler emits the strb before the str in both
 *     orders, so the listing only shows the order through the allocation.
 * The lane-E7 draft (callee widths read from the callees' matched bodies)
 * is the starting point; only those two lines differ from it.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_PrintElem.anmSeq \
 *       --func PMS_DRAW_PrintElem --addr 0x0202E1F0 --cc 1.1p1 --thumb
 */
void PMS_DRAW_PrintElem(struct PmsElem *elem, void *printQue, u32 font, struct Descriptor *bmpWin,
                   const PmsData *param, const PmsOffset *offset,
                   u16 color, u8 nullColorPalette, u16 heapId)
{
    u32 isBlank[2] = {0, 0};
    PmsData pmsCopy;
    void *str;
    void *word;
    int i;
    u16 heapID;
    int wordCount;

    PMSI_PARAM_Copy((struct Rec8 *)(&pmsCopy), (const struct Rec8 *)param);
    param = &pmsCopy;
    PMSI_PARAM_Validate((struct T *)(&pmsCopy), 1, heapId);
    elem->bmpWin = bmpWin;
    elem->printing = 0;
    heapID = *(u16 *)&heapId;
    str = PMSI_PARAM_GetSourceString((const struct Struct_0202441C *)param, heapID);
    wordCount = (u8)GF_FONT_CountControlTag(str);
    for (i = 0; i < wordCount; i++) {
        if (PMSI_PARAM_IsDecoWordAt((struct Container *)param, i)) {
            elem->isDeco[i] = 1;
        } else if (PMSI_PARAM_GetWordId((void *)param, i) == 0xffff) {
            isBlank[i] = 1;
        }
    }
    word = PMSI_PARAM_ToStringWords((u16 *)param, heapID, wordCount);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)elem->bmpWin)), nullColorPalette);
    PRINTSYS_PrintQueColor(printQue, (u32)BMP_WIN_GetBmp((struct Descriptor *)elem->bmpWin), (s16)offset->x, (s16)offset->y, (u32)word, font, color);
    elem->printing = 1;
    for (i = 0; i < wordCount; i++) {
        if (elem->isDeco[i] == 1) {
            u32 x = GF_FONT_MeasureText(word, i, (void *)font, 0);
            u32 y = GF_FONT_SearchIndex(word, i);
            PMS_DRAW_PlaceDecoActor(elem->decoActor[i], bmpWin, x, y, PMSI_PARAM_GetWordId((void *)param, i), (const struct PmsPos *)offset);
        } else if (isBlank[i] == 1) {
            u32 x = GF_FONT_MeasureText(word, i, (void *)font, 0);
            u32 y = GF_FONT_SearchIndex(word, i);
            BMP_FillRect((u32)BMP_WIN_GetBmp((struct Descriptor *)bmpWin), x, y << 4, 0x54, 0x10, nullColorPalette);
        }
    }
    STRBUF_Delete(word);
    STRBUF_Delete(str);
    BMP_WIN_MakeScreen((struct Cfg *)elem->bmpWin);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)elem->bmpWin));
    elem->flags.bits.active = 1;
    elem->flags.bits.visible = 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_ClearElem.anmSeq \
 *       --func PMS_DRAW_ClearElem --addr 0x0202E38C --cc 1.1p1 --thumb
 */
void PMS_DRAW_ClearElem(struct PmsElem *elem, u32 isTrans)
{
    void *h;
    int i;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)elem->bmpWin)), 0);
    if (isTrans != 0) {
        BMP_WIN_TransferChars((struct Descriptor *)elem->bmpWin);
        h = elem->bmpWin;
        BMP_WIN_ClearScreen((struct Descriptor *)h);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    }
    for (i = 0; i < 2; i++) {
        CLACT_SetActorDrawEnable(elem->decoActor[i], 0);
        elem->isDeco[i] = 0;
    }
    elem->scrollX = 0;
    elem->scrollY = 0;
    elem->flags.word &= ~1;
    elem->flags.word &= ~2;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_SetElemVisible.anmSeq \
 *       --func PMS_DRAW_SetElemVisible --addr 0x0202E3E4 --cc 1.1p1 --thumb
 */
void PMS_DRAW_SetElemVisible(struct PmsElem *elem, u32 visible)
{
    int i;

    elem->flags.word = (elem->flags.word & ~2) | ((visible & 1) << 1);
    if (visible != 0)
        BMP_WIN_MakeScreen((struct Cfg *)elem->bmpWin);
    else
        BMP_WIN_ClearScreen((struct Descriptor *)elem->bmpWin);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)elem->bmpWin));
    for (i = 0; i < 2; i++) {
        if (elem->isDeco[i] != 0)
            CLACT_SetActorDrawEnable(elem->decoActor[i], visible);
    }
}

u32 PMS_DRAW_GetFrameSurface(u32 frame)
{
    if (frame >= 4) {
        return 1;
    }
    return 0;
}

void func_0202E43C(void *p)
{
    MI_CpuFill8(p, 0, 4);
}

u32 func_0202E448(u32 id)
{
    u32 i;

    for (i = 0; i < 7; i++) {
        if (id == ItemValueTable[i].itemId) {
            return ItemValueTable[i].value;
        }
    }
    return 0x19;
}

/*
 * Allocates and fills one record of a per-something description list,
 * followed by eight "read the sub-object" calls.  The fifth argument to
 * func_02030734 is the pool-relative caller tag (0x37 here, the same 0x3c/
 * 0x3d/0x83/0x84 tags in the neighbours are the same convention).
 *
 * Argument order of MI_CpuCopy8 is (src, dst, n): the original loads r1
 * with `p + 0x14` *before* r0 with a1, so r1 - the second slot - is the
 * destination.  Writing the copy as `MI_CpuCopy8(dst, src, n)` reverses the
 * two registers and costs seven bytes.
 *
 * The pool word 0x020A77C4 is a `string` site: it is the `__FILE__`-style
 * name run whose start is pinned by the terminator of the string before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BAG_PARAM_Create.c \
 *       --func BAG_PARAM_Create --addr 0x0202E474 --cc 1.1p1 --thumb
 */
void *BAG_PARAM_Create(const struct BigObj *gameData, int itemCheck, int mode, int heapId)
{
    int   saveControl = (int)GAME_DATA_GetSaveControl((struct Big *)gameData);
    struct BagParam *param = func_02030734(heapId, 0x3c, 1, BagParamFileName, 0x37);

    param->gameData = (void *)gameData;
    param->myStatus = func_0200873C((void *)saveControl);
    param->myItem = func_02012944((void *)gameData);
    param->saveWork = GAME_DATA_GetMapMatrix(gameData);
    param->config = GAME_DATA_GetMyItem((const struct BigObj *)gameData);
    if (itemCheck != 0) {
        MI_CpuCopy8((void *)itemCheck, param->itemCheck, 0x18);
    }
    param->mode = mode;
    param->cycleFlag = GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetField114((struct SaveBlock *)gameData)) == 1;
    return param;
}
