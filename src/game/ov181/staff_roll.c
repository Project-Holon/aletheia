/*
 * file:     staff_roll.c
 * unit:     yes
 * function: STAFF_ROLL_Init, STAFF_ROLL_Main, STAFF_ROLL_Exit, STAFF_ROLL_RunState, STAFF_ROLL_Setup, STAFF_ROLL_CheckWipeDone, STAFF_ROLL_Teardown, STAFF_ROLL_StateWaitIntro, STAFF_ROLL_RunScript, STAFF_ROLL_SetupVramBanks, STAFF_ROLL_SetupBackgrounds, STAFF_ROLL_TeardownBackgrounds, STAFF_ROLL_LoadGraphics, STAFF_ROLL_ReloadGraphics, STAFF_ROLL_VblankTask, STAFF_ROLL_AddVblankTask, STAFF_ROLL_RemoveVblankTask, STAFF_ROLL_InitText, STAFF_ROLL_DeleteText, STAFF_ROLL_BuildRowList, STAFF_ROLL_DeleteRowList, STAFF_ROLL_PrintRow, STAFF_ROLL_PrintNextRow, STAFF_ROLL_BlitRow, STAFF_ROLL_LoadRows, STAFF_ROLL_FreeRows, STAFF_ROLL_InitWindows, STAFF_ROLL_DeleteWindows, STAFF_ROLL_SetWindowFlags, STAFF_ROLL_FlushWindows, STAFF_ROLL_Init3d, STAFF_ROLL_Exit3d, STAFF_ROLL_Draw3d, STAFF_ROLL_InitLights, STAFF_ROLL_QueueLight, STAFF_ROLL_AdvanceLights, STAFF_ROLL_CalcVelocity, STAFF_ROLL_StepPosition, STAFF_ROLL_UpdateLights, STAFF_ROLL_SetLightMode, STAFF_ROLL_StartWipe, STAFF_ROLL_UpdateBrightness, STAFF_ROLL_UpdateInput, STAFF_ROLL_ShiftRow, STAFF_ROLL_ScrollWindows, STAFF_ROLL_PrintText, STAFF_ROLL_PrintRowText, STAFF_ROLL_PrintEntry, STAFF_ROLL_StepFadeIn, STAFF_ROLL_StepFadeOut, STAFF_ROLL_StepWindowSlide, STAFF_ROLL_CmdPrintEntry, STAFF_ROLL_CmdShowEntry, STAFF_ROLL_CmdSetEntryMode, STAFF_ROLL_CmdStartScroll, STAFF_ROLL_CmdStopScroll, STAFF_ROLL_CmdEnd, STAFF_ROLL_CmdNop, STAFF_ROLL_CmdShowPlane, STAFF_ROLL_CmdHidePlane, STAFF_ROLL_CmdQueueLight, STAFF_ROLL_CmdSetRecord
 * address:  0x021B95A0
 * region:   ov181
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * 30-byte leaf: stride into a record table by its byte-7 selector, hand the
 * record to STAFF_ROLL_PrintRowText, then copy one halfword and set a flag on ctx.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   d_021BAB70 0x021BAB70 data a4
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb
 *   ov067_id       0x00000043  data
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   d_021BABD0 0x021BABD0 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021BABFC     0x021BABFC  data  a4
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   BG_SYS_SetScrollRegs 0x02040860 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BAC74 0x021BAC74 data a4
 *   d_021BACC4 0x021BACC4 data a4
 *   d_021BAC84 0x021BAC84 data a4
 *   d_021BACA4 0x021BACA4 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   BG_SYS_Update 0x020419E4 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Delete 0x020437AC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Blit 0x020439A0 arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   d_021BAB50 0x021BAB50 data a4
 *   d_021BAB38 0x021BAB38 data a4
 *   d_021BAC68 0x021BAC68 data a4
 *   d_021BACE4 0x021BACE4 data a4
 *   d_021BACF0 0x021BACF0 data a4
 *   d_020A1E38 0x020A1E38 data a2
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   d_021BAC2C 0x021BAC2C data a4
 *   _u32_div_f 0x0209C2B0 arm
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetCamTarget 0x02048B30 arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetCamTarget 0x02048B44 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   KEY_GetCont 0x0203630C arm
 *   BMP_GetPixels 0x020437D4 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021BAB40 0x021BAB40 data a2
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BMP_Clear 0x02043B5C arm
 *   BG_SYS_SetScrollRegs 0x02040860 arm
 */

#include "../version.h"
#include "../sdk_ioreg.h"

/* Black fades the credits to black, White to white. */
#if VERSION == VERSION_WHITE
#define FADE_LEVEL 0x10
#define FADE_PALETTE_COLOR 0xFFFF
#define FADE_WIPE_COLOR 0x7FFF
#else
#define FADE_LEVEL (-0x10)
#define FADE_PALETTE_COLOR 0
#define FADE_WIPE_COLOR 0
#endif

#define STATE(p) (((StaffRoll *)(p))->scriptState)
#define ENTRIES(p) (((StaffRollEntry *)(((StaffRoll *)(p))->entryTable)))
#define IDX(p) (((StaffRoll *)(p))->rowIndex)
struct Proc;
struct Proc;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Mtx22;
struct Node;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct G3dUtil;
struct Bmp;
struct Bmp;
struct BmpWin;
struct BmpWin;
struct G3dUtil;
struct Setup;
struct LightSetDesc;
struct LightSlot;
struct G3dCamera;
struct G3dObject;
struct G3dUtil;
struct G3dObjectStatus;
struct Strbuf;
#include "../types.h"
#include "../arm9/g3d_util.h"

typedef int (*Command)(char *,char *);

typedef struct { unsigned words[4]; } Small;
typedef struct { unsigned words[8]; } StaffRollBig;

typedef struct { u32 x,y,z; } StaffRollVec3;
typedef struct { int x, y, z; } StaffRollVec;

typedef struct { u16 index; u16 duration; } StaffRollLightSlot;

typedef struct {
    void *lightSet;
    StaffRollVec currentPos;
    StaffRollVec targetPos;
    StaffRollVec velocity;
    StaffRollVec targetVelocity;
    StaffRollLightSlot queue[16];
    u16 mode;
    u16 activeIndex;
    u16 progress;
    u16 duration;
    u32 lightMode;
} StaffRollLight;

typedef char StaffRollLight_size_check[(sizeof(StaffRollLight) == 0x80) ? 1 : -1];

typedef struct {
    u32 text;
    u16 y;
    u8 opcode;
    u8 mode;
    u8 colorIndex;
    u8 fontIndex;
    u16 align;
    s16 x;
    s16 xOfs;
} StaffRollEntry;

typedef struct {
    void *bmp;
    int index;
} StaffRollRow;

typedef struct StaffRoll {
    void *sys;
    void *vblankTask;
    void *g3dUtil;
    void *camera;
    void *lightSlot;
    u32 reserved14;
    u16 unitId;
    u8 pad01A[2];
    int brightness;
    void *g3dObject;
    u32 animeCount;
    StaffRollLight light;
    void *fontA;
    void *fontB;
    void *msgBank;
    void *textBuf;
    StaffRollRow rows[64];
    u16 rowCount;
    u8 rowIndex;
    u8 scriptRowIndex;
    void *windowA;
    u8 pad2C0[4];
    void *windowB;
    u8 pad2C8[4];
    u8 windowFlags;
    u8 entryMode;
    u8 fadeState;
    u8 planeFlags;
    s8 slideProgress;
    u8 pad2D1;
    u8 fastFlag;
    u8 pad2D3;
    void *entryTable;
    u16 scriptIndex;
    s16 scriptTimer;
    int scrollOffset;
    int scrollActive;
    u32 introCount;
    u32 state;
    int scriptState;
    int wipeDelay;
} StaffRoll;

typedef char StaffRoll_size_check[(sizeof(StaffRoll) == 0x2F4) ? 1 : -1];

#include "../arm9/bmp_shared_types.h"
struct CharBuf { u8 *pixels; u16 width, height, tileSize; };
struct Mtx22 { int m[4]; };

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/bg_sys.h"
#include "../arm9/gx.h"
#include "../arm9/gfl_use.h"
#include "../arm9/wipe.h"
extern int GFL_USE_IsBgmFading(void),GFL_USE_IsBgmPlaying(void);
extern void BG_SYS_SetMainVisiblePlanes(u32),BG_SYS_SetSubVisiblePlanes(u32),GF_OVERLAY_Unload(int);
union MtxFx22;
#include "../arm9/button_man.h"
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned),BG_SYS_FreeLayerBuf(unsigned),BG_SYS_Delete(void);
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
extern void STAFF_ROLL_FlushWindows(char *),BG_SYS_Update(void);
#include "../arm9/tcb_list.h"
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
#include "../arm9/gf_font.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
struct BmpWin;
#include "../arm9/g3d_system.h"
struct G3dObject;
struct LightSetDesc;
struct LightSlot;
struct LightSlot;
struct VecFx32;
#include "../arm9/g3d_camera.h"
struct G3dCamera;
#include "../arm9/g2.h"
struct G3dObjectStatus;
#include "../arm9/key.h"
#include "../arm9/bmp_win.h"
#include "../arm9/g3d_light.h"
/* The DS code was built against a prototype with a halfword x (the header has a word x). The host build uses the header. */
#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColor_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintColor
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
#endif
int STAFF_ROLL_Init(struct Proc *p, int unused, u32 arg);
int STAFF_ROLL_Main(int unused0, int unused1, int unused2, int work);
int STAFF_ROLL_Exit(void *p);
int STAFF_ROLL_RunState(char *p);
int STAFF_ROLL_Setup(u8 *p);
int STAFF_ROLL_CheckWipeDone(char *p);
int STAFF_ROLL_Teardown(char *p);
int STAFF_ROLL_StateWaitIntro(char *p);
int STAFF_ROLL_RunScript(char *p);
void STAFF_ROLL_SetupVramBanks(void);
void STAFF_ROLL_SetupBackgrounds(void);
void STAFF_ROLL_TeardownBackgrounds(void);
void STAFF_ROLL_LoadGraphics(void);
void STAFF_ROLL_ReloadGraphics(void *unused, int mode);
void STAFF_ROLL_VblankTask(struct TcbTask *task, void *p);
void STAFF_ROLL_AddVblankTask(char *p);
void STAFF_ROLL_RemoveVblankTask(char *p);
void STAFF_ROLL_InitText(char *p);
void STAFF_ROLL_DeleteText(char *p);
void STAFF_ROLL_BuildRowList(char *p);
void STAFF_ROLL_DeleteRowList(char *p);
void STAFF_ROLL_PrintRow(char *p, void *s, unsigned rowIndex);
void STAFF_ROLL_PrintNextRow(char *p);
void STAFF_ROLL_BlitRow(char *p);
void STAFF_ROLL_LoadRows(char *p);
void STAFF_ROLL_FreeRows(char *p);
void STAFF_ROLL_InitWindows(char *p);
void STAFF_ROLL_DeleteWindows(char *p);
void STAFF_ROLL_SetWindowFlags(char *p, u32 flags);
void STAFF_ROLL_FlushWindows(char *p);
void STAFF_ROLL_Init3d(char *p);
void STAFF_ROLL_Exit3d(char *p);
void STAFF_ROLL_Draw3d(char *p);
void STAFF_ROLL_InitLights(u8 *p);
void STAFF_ROLL_QueueLight(u8 *p, int index, int duration);
void STAFF_ROLL_AdvanceLights(u8 *p);
void STAFF_ROLL_CalcVelocity(StaffRollVec *out, const StaffRollVec *base, const StaffRollVec *target, unsigned duration);
void STAFF_ROLL_StepPosition(StaffRollVec *out, const StaffRollVec *base, const StaffRollVec *velocity, unsigned step);
void STAFF_ROLL_UpdateLights(char *p);
void STAFF_ROLL_SetLightMode(u8 *p, u32 mode);
int STAFF_ROLL_StartWipe(u8 *p, int delay);
void STAFF_ROLL_UpdateBrightness(char *p);
void STAFF_ROLL_UpdateInput(u8 *p);
void STAFF_ROLL_ShiftRow(u8 *p,u8 *out,u32 n);
void STAFF_ROLL_ScrollWindows(char *p);
void STAFF_ROLL_PrintText(char *p, unsigned char *q, void *s, int y);
void STAFF_ROLL_PrintRowText(char *p,u8 *q);
void STAFF_ROLL_PrintEntry(char *p, unsigned char *q);
int STAFF_ROLL_StepFadeIn(char *p);
int STAFF_ROLL_StepFadeOut(char *p);
int STAFF_ROLL_StepWindowSlide(char *p);
int STAFF_ROLL_CmdPrintEntry(char *p, unsigned char *q);
int STAFF_ROLL_CmdShowEntry(char *p, unsigned char *q);
int STAFF_ROLL_CmdSetEntryMode(char *p, unsigned char *q);
int STAFF_ROLL_CmdStartScroll(char *p);
int STAFF_ROLL_CmdStopScroll(char *p);
int STAFF_ROLL_CmdEnd(char *p);
int STAFF_ROLL_CmdNop(void);
int STAFF_ROLL_CmdShowPlane(void);
int STAFF_ROLL_CmdHidePlane(void);
int STAFF_ROLL_CmdQueueLight(u8 *p,u8 *q);
int STAFF_ROLL_CmdSetRecord(char *ctx, unsigned char *rec);
extern u8 ov067_id[];
extern const Command d_021BABD0[];
extern int  d_021BABFC[];
extern const Small d_021BAC74;
extern const StaffRollBig d_021BACC4, d_021BAC84, d_021BACA4;
extern unsigned SDK_AUTOLOAD_MAIN_TWL_START[];
extern const struct Setup d_021BAB50;
extern const struct LightSetDesc d_021BAB38;
extern const StaffRollVec3 d_021BAC68;
extern StaffRollVec3 d_021BACE4,d_021BACF0;
extern const u8 d_020A1E38[];
extern const unsigned d_021BAC2C[];
extern const unsigned short d_021BAB40[];

int STAFF_ROLL_Init(struct Proc *p, int unused, u32 arg) { u8 *q; GFL_HEAP_CreateChildHeap(1,142,0x125000); q=PROCSYS_AllocProcWork(p,756,142); MI_CpuFill8(q,0,756); ((StaffRoll *)q)->sys=(void *)arg; return 1; }

int STAFF_ROLL_Main(int unused0, int unused1, int unused2, int work)
{
    return STAFF_ROLL_RunState((char *)work) == 0;
}

int STAFF_ROLL_Exit(void *p)
{
    PROCSYS_FreeProcWork(p);
    GFL_HEAP_DeleteChecked(0x8e);
    return 1;
}

extern int (*const d_021BAB70[])(char *);

int STAFF_ROLL_RunState(char *p){STAFF_ROLL_UpdateInput((unsigned char *)p);((StaffRoll *)p)->state=d_021BAB70[*(unsigned *)(p+0x2e8)](p);if(((StaffRoll *)p)->state==5)return 0;STAFF_ROLL_PrintNextRow(p);STAFF_ROLL_Draw3d(p);return 1;}

int STAFF_ROLL_Setup(u8 *p)
{
    GF_OVERLAY_Load((sptr)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(1);
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR, -0x10);
    GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR, -0x10);
    STAFF_ROLL_SetupVramBanks();
    STAFF_ROLL_SetupBackgrounds();
    STAFF_ROLL_LoadGraphics();
    STAFF_ROLL_InitText((char *)p);
    STAFF_ROLL_InitWindows((char *)p);
    STAFF_ROLL_Init3d((char *)p);
    STAFF_ROLL_LoadRows((char *)p);
    STAFF_ROLL_AddVblankTask((char *)p);
    GFL_USE_PlayFanfare(0x3f8);
    return 3;
}

int STAFF_ROLL_CheckWipeDone(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((StaffRoll *)p)->wipeDelay;
    return 1;
}

int STAFF_ROLL_Teardown(char *p) {
if(GFL_USE_IsBgmFading()==1)return 2;
if(GFL_USE_IsBgmPlaying()==1)GFL_USE_CancelChangeAndStopBgm();
STAFF_ROLL_RemoveVblankTask(p);STAFF_ROLL_FreeRows(p);STAFF_ROLL_Exit3d(p);STAFF_ROLL_DeleteWindows(p);STAFF_ROLL_DeleteText(p);STAFF_ROLL_TeardownBackgrounds();
GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_ADDR,FADE_LEVEL);GXx_SetMasterBrightness_((volatile u16 *)REG_DB_MASTER_BRIGHT_ADDR,FADE_LEVEL);
*(volatile u16 *)0x04000050=0;*(volatile u16 *)0x04001050=0;
BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);GF_OVERLAY_Unload((sptr)ov067_id);return 5;
}

#define COUNT(p) (*(unsigned *)((p) + 0x2E4))

int STAFF_ROLL_StateWaitIntro(char *p)
{
    switch (STATE(p)) {
    case 0:
        if (COUNT(p) >= 41) {
            COUNT(p) = 0;
            STATE(p)++;
        } else if (((StaffRoll *)p)->fastFlag == 1) {
            COUNT(p) += 4;
        } else {
            COUNT(p)++;
        }
        break;
    case 1:
        if (STAFF_ROLL_StepWindowSlide(p) == 0)
            STATE(p)++;
        break;
    case 2:
        COUNT(p) = 0;
        STATE(p) = 0;
        return 4;
    }
    return 3;
}

int STAFF_ROLL_RunScript(char *p) {
    char *row;
    if(((StaffRoll *)p)->scriptState==0) {
        for(;;) {
            row=*(char * *)&((StaffRoll *)p)->entryTable+((StaffRoll *)p)->scriptIndex*16;
            if(((StaffRoll *)p)->scriptIndex==*(u32 *)((uptr)p+((StaffRoll *)p)->scriptRowIndex*8+0xbc)) {
                STAFF_ROLL_BlitRow(p);
                (((StaffRoll *)p)->scriptRowIndex)++;
                *(u16 *)&((StaffRoll *)p)->scriptTimer=((StaffRollEntry *)row)->y;
                ((StaffRoll *)p)->scriptState=1;
                ((StaffRoll *)p)->scriptIndex+=2;
                break;
            }
            if(d_021BABD0[*(u8 *)(row+6)](p,row)==1) {
                (((StaffRoll *)p)->scriptIndex)++;
                break;
            }
            (((StaffRoll *)p)->scriptIndex)++;
        }
    }
    switch(((StaffRoll *)p)->scriptState) {
    case 1:
        if(((StaffRoll *)p)->scriptTimer<=0) {
            ((StaffRoll *)p)->scriptTimer=0; ((StaffRoll *)p)->scriptState=0;
        } else if(((StaffRoll *)p)->fastFlag==1) ((StaffRoll *)p)->scriptTimer-=4;
        else (((StaffRoll *)p)->scriptTimer)--;
        break;
    case 2: if(STAFF_ROLL_StepFadeIn(p)==0) ((StaffRoll *)p)->scriptState=0; break;
    case 3: if(STAFF_ROLL_StepFadeOut(p)==0) ((StaffRoll *)p)->scriptState=0; break;
    case 5:
        if(GFL_USE_IsBgmPlaying()==1) GFL_USE_FadeOutBgm(64);
        return STAFF_ROLL_StartWipe((u8 *)p,2);
    }
    STAFF_ROLL_ScrollWindows(p);
    return 4;
}

void STAFF_ROLL_SetupVramBanks(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BABFC);
}

void STAFF_ROLL_SetupBackgrounds(void)
{
    Small dispCfg;
    StaffRollBig bgTmpl1, bgTmpl3;
    Small mtx;
    StaffRollBig bgTmpl5;
    BG_SYS_Create(0x8E);
    dispCfg = d_021BAC74;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&dispCfg));
    bgTmpl1 = d_021BACC4;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&bgTmpl1), 0);
    bgTmpl3 = d_021BAC84;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&bgTmpl3), 2);
    BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)(&mtx), 0, (s32)0x9000, 0x9000, 0);
    BG_SYS_SetScrollRegs(3, (union MtxFx22 *)(&mtx), 0x80, 0x60);
    bgTmpl5 = d_021BACA4;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&bgTmpl5), 0);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetSubPlaneVisible(2, 1);
}

/*
 * Tail: two zero alignment bytes at 0x021B99F6.
 */
void STAFF_ROLL_TeardownBackgrounds(void){BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetSubPlaneVisible(2,0);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(1);BG_SYS_Delete();}

void STAFF_ROLL_LoadGraphics(void)
{
    u8 *p = ARC_TOOL_CreateHandle(0x1a, 0x808e);
    ARC_UTIL_UploadBgCharFromHandle(p, 0, 3, 0, 0, 1, 0x8e);
    ARC_UTIL_UploadBgPaletteFromHandle(p, 1, 3, 0, 0, 1, 0x8e);
    ARC_TOOL_DeleteHandle(p);
    p = ARC_TOOL_CreateHandle(0xdc, 0x808e);
    ARC_UTIL_UploadPaletteFromHandleWhole(p, 0xc, 0, 0x1e0, 0x20, 0x8e);
    ARC_UTIL_UploadPaletteFromHandleWhole(p, 0xc, 4, 0x1e0, 0x20, 0x8e);
    ARC_TOOL_DeleteHandle(p);
    BG_SYS_LoadPlttEntry(1, FADE_PALETTE_COLOR);
    BG_SYS_LoadPlttEntry(5, FADE_PALETTE_COLOR);
}

void STAFF_ROLL_ReloadGraphics(void *unused, int mode)
{
    unsigned char *h;
    if (mode == 1) {
        h = ARC_TOOL_CreateHandle(0x1A, 0x808E);
        ARC_UTIL_UploadPaletteFromHandleWhole(h, 2, 0, 0, 0, 0x8E);
    } else {
        h = ARC_TOOL_CreateHandle(0xDC, 0x808E);
        ARC_UTIL_UploadPaletteFromHandleWhole(h, 0xC, 0, 0x1E0, 0x20, 0x8E);
    }
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_LoadPlttEntry(1, FADE_PALETTE_COLOR);
}

/*
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 0x02FE3FF8.
 */
void STAFF_ROLL_VblankTask(struct TcbTask *task, void *pArg) { char * p = pArg;STAFF_ROLL_FlushWindows(p);BG_SYS_Update();*(volatile unsigned *)((uptr)SDK_AUTOLOAD_MAIN_TWL_START+0x3ff8) |=1;}

void STAFF_ROLL_AddVblankTask(char *p){((StaffRoll *)p)->vblankTask=GFL_USE_AddMainTask(STAFF_ROLL_VblankTask, p,0);}

void STAFF_ROLL_RemoveVblankTask(char *p){TCB_DeleteTask(((StaffRoll *)p)->vblankTask);}

/*
 * Padding: two zero bytes at 0x021B9B6A, then the next function.
 */
void STAFF_ROLL_InitText(char *p)
{
    ((StaffRoll *)p)->msgBank = MSGDATA_CreateFromArchive(0, 2, 0xB1, 0x8E);
    ((StaffRoll *)p)->textBuf = STRBUF_Create(0x80, 0x8E);
    ((StaffRoll *)p)->fontA = GF_FONT_Create(0x17, 0, 1, 0, 0x8E);
    ((StaffRoll *)p)->fontB = GF_FONT_Create(0x17, 2, 1, 0, 0x8E);
}

void STAFF_ROLL_DeleteText(char *p){GF_FONT_Delete(((StaffRoll *)p)->fontB);GF_FONT_Delete(((StaffRoll *)p)->fontA);STRBUF_Delete(((StaffRoll *)p)->textBuf);MSGDATA_Delete(((StaffRoll *)p)->msgBank);}

#undef COUNT

#undef COUNT

#undef COUNT

#undef COUNT
#define COUNT(p) (*(unsigned short *)((p) + 0x2B8))

void STAFF_ROLL_BuildRowList(char *p)
{
    unsigned short i;
    int found = 0;
    for (i = 0; ; i++) {
        StaffRollEntry *e = &ENTRIES(p)[i];
        if (found == 0) {
            if (e->opcode == 7)
                found = 1;
        } else {
            if (e->opcode == 5)
                break;
            if (e->opcode == 0 && e->text != 0xFFFF && ((StaffRollEntry *)((uptr)ENTRIES(p) + (i + 1) * 16))->y == 0 &&
                ((StaffRollEntry *)((uptr)ENTRIES(p) + (i + 1) * 16))->opcode == 0 && ((StaffRollEntry *)((uptr)ENTRIES(p) + (i + 1) * 16))->text != 0xFFFF) {
                *(void **)(p + COUNT(p) * 8 + 0xB8) = BMP_Create(0x20, 2, 0x20, 0x8E);
                *(int *)(p + COUNT(p) * 8 + 0xBC) = i;
                COUNT(p)++;
                if (COUNT(p) == 0x40)
                    break;
                i++;
            }
        }
    }
}

void STAFF_ROLL_DeleteRowList(char *p){unsigned i;for(i=0;i<((StaffRoll *)p)->rowCount;i++)BMP_Delete(((StaffRoll *)p)->rows[i].bmp);}

void STAFF_ROLL_PrintRow(char *p, void *s, unsigned rowIndex){unsigned char *q=*(unsigned char * *)&((StaffRoll *)p)->entryTable+rowIndex*16;if(q[9]==0)STAFF_ROLL_PrintText(p,q,s,0);else STAFF_ROLL_PrintText(p,q,s,2);}

void STAFF_ROLL_PrintNextRow(char *p)
{
    if (IDX(p) < ((StaffRoll *)p)->rowCount) {
        STAFF_ROLL_PrintRow(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC));
        STAFF_ROLL_PrintRow(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC) + 1);
        IDX(p)++;
    }
}

void STAFF_ROLL_BlitRow(char *p){struct Bmp *s=BMP_WIN_GetBmp(((StaffRoll *)p)->windowB);BMP_Blit(*(struct Bmp **)((uptr)p+((StaffRoll *)p)->scriptRowIndex*8+0xb8),s,0,0,0,192,256,16,0);}

void STAFF_ROLL_LoadRows(char *p)
{
    ((StaffRoll *)p)->entryTable = ARC_TOOL_LoadMember(0xdc, 1, 0x8e);
    STAFF_ROLL_BuildRowList(p);
}

void STAFF_ROLL_FreeRows(char *p)
{
    STAFF_ROLL_DeleteRowList(p);
    GFL_HEAP_Free((void *)(((StaffRoll *)p)->entryTable));
}

/*
 * Padding: two zero bytes at 0x021B9DAE, then the next function.
 */
void STAFF_ROLL_InitWindows(char *p)
{
    void *h;
    BMP_WIN_Init(0x8E);
    ((StaffRoll *)p)->windowA = (void *)BMP_WIN_Create(1, 0, 0, 0x20, 0x19, 0xF, 1);
    ((StaffRoll *)p)->windowB = (void *)BMP_WIN_Create(5, 0, 0, 0x20, 0x1C, 0xF, 1);
    h = ((StaffRoll *)p)->windowA;
    BMP_WIN_TransferChars((struct BmpWin *)h);
    BMP_WIN_MakeScreen((struct BmpWin *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    h = ((StaffRoll *)p)->windowB;
    BMP_WIN_TransferChars((struct BmpWin *)h);
    BMP_WIN_MakeScreen((struct BmpWin *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
}

void STAFF_ROLL_DeleteWindows(char *p){BMP_WIN_Delete(*(struct BmpWin * *)&((StaffRoll *)p)->windowA);BMP_WIN_Delete(*(struct BmpWin * *)&((StaffRoll *)p)->windowB);BMP_WIN_Exit();}

void STAFF_ROLL_SetWindowFlags(char *p, u32 flags)
{
    ((StaffRoll *)p)->windowFlags |= (u8)flags;
}

/*
 * Tail: two zero alignment bytes at 0x021B9E12.
 */
void STAFF_ROLL_FlushWindows(char *p){if(((StaffRoll *)p)->windowFlags&1)BMP_WIN_TransferChars((struct BmpWin *)((StaffRoll *)p)->windowA);if(((StaffRoll *)p)->windowFlags&2)BMP_WIN_TransferChars((struct BmpWin *)((StaffRoll *)p)->windowB);((StaffRoll *)p)->windowFlags=0;}

static inline void AntiAlias(int enable) {
    u32 tmp=*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000;
    if(enable) tmp|=0x10;
    else tmp&=~0x10;
    *(volatile u16 *)0x04000060=(u16)tmp;
}

void STAFF_ROLL_Init3d(char *p) {
    StaffRollVec3 v;
    u32 i;
    G3D_SYSTEM_Init(0,2,0,2,4096,142,0);
    *(struct G3dUtil **)(p+8)=G3D_UTIL_Create(3,1,142);
    *(u16 *)(p+0x18)=G3D_UTIL_AddUnit((G3dUtil *)(*(struct G3dUtil **)(p+8)),(const G3dUtilSetup *)&d_021BAB50);
    *(u32 *)(p+0x20)=G3D_UTIL_GetObject((G3dUtil *)(*(u8 **)(p+8)),*(u16 *)(p+0x18));
    *(u32 *)(p+0x24)=G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)(*(int **)(p+0x20)));
    for(i=0;i<*(u32 *)(p+0x24);i++) G3D_SYSTEM_EnableObjectAnime(*(struct G3dObject **)(p+0x20),(u16)i);
    *(struct LightSlot **)(p+0x10)=(struct LightSlot *)G3D_LIGHT_CreateSlots((struct LightSetDesc *)(&d_021BAB38),142);
    G3D_LIGHT_ApplySlots(*(struct LightSlot **)(p+0x10));
    v=d_021BAC68;
    *(u32 **)(p+0xc)=(u32 *)G3D_CAMERA_Create(0,*(s16 *)(d_020A1E38+0x8c),*(s16 *)(d_020A1E38+0x8e),0x1555,
        0,4096,0x400000,0,(struct VecFx32 *)(&d_021BACE4),(struct VecFx32 *)(&v),(struct VecFx32 *)(&d_021BACF0),142);
    G3D_CAMERA_Reset(*(struct G3dCamera **)(p+0xc));
    AntiAlias(1);
    BG_SYS_EnableBg0WithPriority(2);
    STAFF_ROLL_InitLights((u8 *)(p+0x28));
    BG_SYS_SetMainPlaneVisible(1,0);
    G2x_SetBlendBrightness_(REG_BLDCNT_ADDR,1,FADE_LEVEL);
}

/*
 * Verified scratch blocker.c with one --arm (no --region), fixed flags: EXACT, 12 bytes.
 * extern void GFL_HEAP_Free(void *);
 * void G3D_LIGHT_DeleteSlots((void *)(void *p)) { GFL_HEAP_Free((void *)p); }
 * Blocker symbols: GFL_HEAP_Free 0x020307B0 arm.
 */
void STAFF_ROLL_Exit3d(char *p){G3D_CAMERA_Delete(*(void **)(p+12));G3D_LIGHT_DeleteSlots(*(void **)(p+16));G3D_UTIL_RemoveUnit(*(struct G3dUtil **)(p+8),*(unsigned short *)(p+24));G3D_UTIL_Delete(*(struct G3dUtil **)(p+8));G3D_SYSTEM_Exit();}

void STAFF_ROLL_Draw3d(char *p)
{
    unsigned i;
    if (**(int * *)&((StaffRoll *)p)->sys != 1 && (BG_SYS_GetMainVisiblePlanes() & 1)) {
        STAFF_ROLL_UpdateBrightness(p);
        STAFF_ROLL_UpdateLights(p);
        for (i = 0; i < ((StaffRoll *)p)->animeCount; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(((StaffRoll *)p)->g3dObject, (unsigned short)i, 0x1000);
        G3D_SYSTEM_DrawStart();
        G3D_SYSTEM_ApplyLookAt();
        G3D_SYSTEM_DrawObject(((StaffRoll *)p)->g3dObject, (struct G3dObjectStatus *)d_021BAC2C);
        G3D_SYSTEM_DrawEnd();
    }
}

void STAFF_ROLL_InitLights(u8 *p){u32 i;*(const void * *)&((StaffRollLight *)p)->lightSet=&d_021BACE4;((StaffRollLight *)p)->mode=7;((StaffRollLight *)p)->progress=0;((StaffRollLight *)p)->activeIndex=0;((StaffRollLight *)p)->lightMode=0;for(i=0;i<16;i++){u8 *q=p+i*4;((StaffRollLight *)q)->queue[0].index=65535;((StaffRollLight *)q)->queue[0].duration=0;}}

void STAFF_ROLL_QueueLight(u8 *p, int index, int duration){u32 i;for(i=0;i<16;i++){u8 *q=p+i*4;if(((StaffRollLight *)q)->queue[0].index==65535){((StaffRollLight *)q)->queue[0].index=index;((StaffRollLight *)q)->queue[0].duration=duration;return;}}}

void STAFF_ROLL_AdvanceLights(u8 *p){u32 i;for(i=0;i<15;i++){u8 *q=p+i*4;((StaffRollLight *)q)->queue[0].index=((StaffRollLight *)q)->queue[1].index;((StaffRollLight *)q)->queue[0].duration=((StaffRollLight *)q)->queue[1].duration;}((StaffRollLight *)p)->queue[15].index=65535;((StaffRollLight *)p)->queue[15].duration=0;}

void STAFF_ROLL_CalcVelocity(StaffRollVec *out, const StaffRollVec *base, const StaffRollVec *target, unsigned duration)
{
    StaffRollVec v;
    int b, a, diff;
    b = target->x;
    a = base->x;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.x = ((unsigned)diff << 8) / duration;
    if (a > b) v.x *= -1;
    b = target->y;
    a = base->y;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.y = ((unsigned)diff << 8) / duration;
    if (a > b) v.y *= -1;
    b = target->z;
    a = base->z;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.z = ((unsigned)diff << 8) / duration;
    if (a > b) v.z *= -1;
    *out = v;
}

void STAFF_ROLL_StepPosition(StaffRollVec *out, const StaffRollVec *base, const StaffRollVec *velocity, unsigned step)
{
    StaffRollVec v = *base;
    unsigned n;
    n = ((unsigned)(velocity->x < 0 ? -velocity->x : velocity->x) * step) >> 8;
    if (velocity->x > 0) v.x += n; else v.x -= n;
    n = ((unsigned)(velocity->y < 0 ? -velocity->y : velocity->y) * step) >> 8;
    if (velocity->y > 0) v.y += n; else v.y -= n;
    n = ((unsigned)(velocity->z < 0 ? -velocity->z : velocity->z) * step) >> 8;
    if (velocity->z > 0) v.z += n; else v.z -= n;
    *out = v;
}

void STAFF_ROLL_UpdateLights(char *p)
{
    StaffRollVec a, b, c, d, e;
    char *q;
    q = p + 0x28;
    if (*(int *)(q + 0x7c) == 0) return;
    if (*(u16 *)(q + 0x78) == 0) {
        *(u16 *)(q + 0x7a) = *(u16 *)(q + 0x36);
        G3D_CAMERA_GetEye(*(struct G3dCamera **)(p + 0xc), (struct VecFx32 *)(&a));
        STAFF_ROLL_CalcVelocity(&b, &a, (StaffRollVec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24), *(u16 *)(q + 0x7a));
        *(StaffRollVec *)(q + 0x1c) = b;
        G3D_CAMERA_GetCamTarget(*(struct G3dCamera **)(p + 0xc), (struct VecFx32 *)(&a));
        STAFF_ROLL_CalcVelocity(&c, &a, (StaffRollVec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12), *(u16 *)(q + 0x7a));
        *(StaffRollVec *)(q + 0x28) = c;
    }
    if (*(u16 *)(q + 0x78) >= *(u16 *)(q + 0x7a)) {
        *(StaffRollVec *)(q + 4) = *(StaffRollVec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24);
        *(StaffRollVec *)(q + 0x10) = *(StaffRollVec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12);
        *(u16 *)(q + 0x76) = *(u16 *)(q + 0x34);
        *(u16 *)(q + 0x78) = 0;
        STAFF_ROLL_AdvanceLights((u8 *)q);
        if (*(u16 *)(q + 0x34) == 0xffff) STAFF_ROLL_SetLightMode((u8 *)q, 0);
    } else {
        STAFF_ROLL_StepPosition(&d, (StaffRollVec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24), (StaffRollVec *)(q + 0x1c), *(u16 *)(q + 0x78));
        *(StaffRollVec *)(q + 4) = d;
        STAFF_ROLL_StepPosition(&e, (StaffRollVec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24 + 12), (StaffRollVec *)(q + 0x28), *(u16 *)(q + 0x78));
        *(StaffRollVec *)(q + 0x10) = e;
        if (*(unsigned char *)(p + 0x2d2) == 1) *(u16 *)(q + 0x78) += 4;
        else ++*(u16 *)(q + 0x78);
    }
    G3D_CAMERA_SetEye(*(struct G3dCamera **)(p + 0xc), (struct VecFx32 *)(q + 4));
    G3D_CAMERA_SetCamTarget(*(struct G3dCamera **)(p + 0xc), (struct VecFx32 *)(q + 0x10));
    G3D_CAMERA_Reset(*(struct G3dCamera **)(p + 0xc));
}

void STAFF_ROLL_SetLightMode(u8 *p, u32 mode){((StaffRollLight *)p)->lightMode=mode;}

int STAFF_ROLL_StartWipe(u8 *p, int delay){WIPE_SYS_Start(0,0,0,FADE_WIPE_COLOR,6,1,142);((StaffRoll *)p)->wipeDelay=delay;return 1;}

void STAFF_ROLL_UpdateBrightness(char *p)
{
    int v = ((StaffRoll *)p)->brightness;
    if (v <= 0x10000) {
        ((StaffRoll *)p)->brightness = v + (((StaffRoll *)p)->fastFlag == 1 ? 0x400 : 0x100);
#if VERSION == VERSION_WHITE
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 1, 0x10 - *(volatile int *)&((StaffRoll *)p)->brightness / 0x1000);
#else
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 1, *(volatile int *)&((StaffRoll *)p)->brightness / 0x1000 - 0x10);
#endif
    }
}

void STAFF_ROLL_UpdateInput(u8 *p){if(**(int **)p){enum {K=0x2d1} k=K;if(p[k]==0)p[k+1]=(KEY_GetCont()&3)?1:0;p[0x2d1]=(p[0x2d1]+1)&3;}}

void STAFF_ROLL_ShiftRow(u8 *p,u8 *out,u32 n){u32 i;if(out){for(i=0;i<n;i++)*(u32 *)(out+(8-n)*4+i*4)=*(u32 *)(p+i*4);}for(i=0;i<8-n;i++)*(u32 *)(p+i*4)=*(u32 *)(p+n*4+i*4);}

/*
 * extent: two zero alignment bytes at 021BA4AA, then labelled 021BA4AC.
 */
void STAFF_ROLL_ScrollWindows(char *p)
{
    char *a, *b;
    unsigned n;
    u16 i, j, k, l, m, o;
    unsigned x, y;
    if (((StaffRoll *)p)->scrollActive == 0) return;
    ((StaffRoll *)p)->scrollOffset += 0x1000;
    if (((StaffRoll *)p)->scrollOffset < 0x1000) return;
    ((StaffRoll *)p)->scrollOffset -= 0x1000;
    n = 1;
    if (((StaffRoll *)p)->fastFlag) n = 4;
    a = BMP_GetPixels(BMP_WIN_GetBmp(((StaffRoll *)p)->windowA));
    b = BMP_GetPixels(BMP_WIN_GetBmp(((StaffRoll *)p)->windowB));
    x = 0;
    for (i = 0; i < 32; i++, x += 32) STAFF_ROLL_ShiftRow((u8 *)(a + x), 0, n);
    for (j = 1; j < 25; j++) {
        x = j * 1024;
        y = (j - 1) * 1024;
        for (k = 0; k < 32; k++, x += 32, y += 32) STAFF_ROLL_ShiftRow((u8 *)(a + x), (u8 *)(a + y), n);
    }
    x = 0;
    y = 0x6000;
    for (l = 0; l < 32; l++, x += 32, y += 32) STAFF_ROLL_ShiftRow((u8 *)(b + x), (u8 *)(a + y), n);
    for (m = 1; m < 28; m++) {
        x = m * 1024;
        y = (m - 1) * 1024;
        for (o = 0; o < 32; o++, x += 32, y += 32) STAFF_ROLL_ShiftRow((u8 *)(b + x), (u8 *)(b + y), n);
    }
    STAFF_ROLL_SetWindowFlags(p, 3);
}

void STAFF_ROLL_PrintText(char *p, unsigned char *q, void *s, int y)
{
    int x;
    unsigned w;
    MSGDATA_ReadString(((StaffRoll *)p)->msgBank, ((StaffRollEntry *)q)->text, ((StaffRoll *)p)->textBuf);
    if (((StaffRollEntry *)q)->align == 0) {
        x = ((StaffRollEntry *)q)->x + ((StaffRollEntry *)q)->xOfs;
    } else if (((StaffRollEntry *)q)->align == 1) {
        w = PRINTSYS_MeasureWidestLine(((StaffRoll *)p)->textBuf, (*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((StaffRollEntry *)q)->x + ((StaffRollEntry *)q)->xOfs - w;
    } else if (((StaffRollEntry *)q)->align == 2) {
        w = PRINTSYS_MeasureWidestLine(((StaffRoll *)p)->textBuf, (*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((StaffRollEntry *)q)->x + ((StaffRollEntry *)q)->xOfs - w / 2;
    }
    PRINTSYS_PrintColor(s, x, y, ((StaffRoll *)p)->textBuf, *(void **)(p + q[9] * 4 + 0xa8), d_021BAB40[q[8]]);
}

void STAFF_ROLL_PrintRowText(char *p,u8 *q){if(q[9]==0)STAFF_ROLL_PrintText(p,q,BMP_WIN_GetBmp(*(struct BmpWin * *)&((StaffRoll *)p)->windowB),192);else STAFF_ROLL_PrintText(p,q,BMP_WIN_GetBmp(*(struct BmpWin * *)&((StaffRoll *)p)->windowB),194);}

void STAFF_ROLL_PrintEntry(char *p, unsigned char *q)
{
    void *s;
    int y;
    if (((StaffRollEntry *)q)->y < 0x100) {
        s = BMP_WIN_GetBmp(((StaffRoll *)p)->windowA);
        y = ((StaffRollEntry *)q)->y;
        ((StaffRoll *)p)->planeFlags |= 1;
    } else {
        s = BMP_WIN_GetBmp(((StaffRoll *)p)->windowB);
        y = ((StaffRollEntry *)q)->y - 0x100;
        ((StaffRoll *)p)->planeFlags |= 2;
    }
    STAFF_ROLL_PrintText(p, q, s, y);
}

/*
 * volatile: display registers 04000052 and 04001052 are hardware.
 */
int STAFF_ROLL_StepFadeIn(char *p)
{
    int a, b;
    switch (((StaffRoll *)p)->fadeState) {
    case 0:
        if (((StaffRoll *)p)->planeFlags & 1) G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 2, 0x21, 0, 16);
        if (((StaffRoll *)p)->planeFlags & 2) G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 2, 0x21, 0, 16);
        ((StaffRoll *)p)->windowFlags = ((StaffRoll *)p)->planeFlags;
        ++((StaffRoll *)p)->fadeState;
        break;
    case 1:
        if (((StaffRoll *)p)->fastFlag == 1) ((StaffRoll *)p)->slideProgress += 16;
        else ((StaffRoll *)p)->slideProgress += 4;
        a = ((StaffRoll *)p)->slideProgress;
        if (a > 16) { a = 16; b = 0; }
        else b = 16 - a;
        if (((StaffRoll *)p)->planeFlags & 1) *(volatile u16 *)REG_BLDALPHA_ADDR = a | (b << 8);
        if (((StaffRoll *)p)->planeFlags & 2) *(volatile u16 *)REG_DB_BLDALPHA_ADDR = a | (b << 8);
        if (((StaffRoll *)p)->slideProgress >= 16) {
            if (((StaffRoll *)p)->planeFlags & 1) *(volatile u16 *)REG_BLDCNT_ADDR = 0;
            if (((StaffRoll *)p)->planeFlags & 2) *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
            *(u8 *)&((StaffRoll *)p)->slideProgress = 0;
            ((StaffRoll *)p)->fadeState = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int STAFF_ROLL_StepFadeOut(char *p)
{
    int a, b;
    switch (((StaffRoll *)p)->fadeState) {
    case 0:
        if (((StaffRoll *)p)->planeFlags & 1) G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 2, 0x21, 16, 0);
        if (((StaffRoll *)p)->planeFlags & 2) G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 2, 0x21, 16, 0);
        ++((StaffRoll *)p)->fadeState;
    case 1:
        if (((StaffRoll *)p)->fastFlag == 1) ((StaffRoll *)p)->slideProgress += 16;
        else ((StaffRoll *)p)->slideProgress += 4;
        b = ((StaffRoll *)p)->slideProgress;
        if (b > 16) { a = 0; b = 16; }
        else a = 16 - b;
        if (((StaffRoll *)p)->planeFlags & 1) *(volatile u16 *)REG_BLDALPHA_ADDR = a | (b << 8);
        if (((StaffRoll *)p)->planeFlags & 2) *(volatile u16 *)REG_DB_BLDALPHA_ADDR = a | (b << 8);
        if (((StaffRoll *)p)->slideProgress >= 16) {
            if (((StaffRoll *)p)->planeFlags & 1) BMP_Clear(BMP_WIN_GetBmp(((StaffRoll *)p)->windowA), 0);
            if (((StaffRoll *)p)->planeFlags & 2) BMP_Clear(BMP_WIN_GetBmp(((StaffRoll *)p)->windowB), 0);
            ((StaffRoll *)p)->windowFlags = ((StaffRoll *)p)->planeFlags;
            *(u8 *)&((StaffRoll *)p)->slideProgress = 0;
            ++((StaffRoll *)p)->fadeState;
        }
        break;
    case 2:
        if (((StaffRoll *)p)->planeFlags & 1) *(volatile u16 *)REG_BLDCNT_ADDR = 0;
        if (((StaffRoll *)p)->planeFlags & 2) *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
        ((StaffRoll *)p)->planeFlags = 0;
        ((StaffRoll *)p)->fadeState = 0;
        return 0;
    }
    return 1;
}

/*
 * volatile: display register stores at 04000050 and 04000052.
 */
int STAFF_ROLL_StepWindowSlide(char *p)
{
    struct Mtx22 matrix;
    int v;
    unsigned scale;
    switch (((StaffRoll *)p)->fadeState) {
    case 0:
        STAFF_ROLL_ReloadGraphics(p, 1);
        G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 8, 0x20, 0, 16);
        BG_SYS_SetMainPlaneVisible(8, 1);
        GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR, 0);
        GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR, 0);
        *(u8 *)&((StaffRoll *)p)->slideProgress = 0;
        ++((StaffRoll *)p)->fadeState;
        break;
    case 1:
        if (((StaffRoll *)p)->fastFlag == 1) ((StaffRoll *)p)->slideProgress += 8;
        else ((StaffRoll *)p)->slideProgress += 2;
        v = ((StaffRoll *)p)->slideProgress;
        if (v >= 16) {
            *(volatile u16 *)0x04000052 = 16;
            BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)(&matrix), 0, (s32)0x1000, 0x1000, 0);
            BG_SYS_SetScrollRegs(3, (union MtxFx22 *)(&matrix), 0x80, 0x60);
            *(u8 *)&((StaffRoll *)p)->slideProgress = 0;
            *(u16 *)&((StaffRoll *)p)->scriptTimer = 0xa6;
            ++((StaffRoll *)p)->fadeState;
        } else {
            *(volatile u16 *)0x04000052 = v | ((16 - v) << 8);
            scale = 8 - ((StaffRoll *)p)->slideProgress / 2;
            BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)(&matrix), 0, (s32)((scale << 12)), (scale << 12), 0);
            BG_SYS_SetScrollRegs(3, (union MtxFx22 *)(&matrix), 0x80, 0x60);
        }
        break;
    case 2:
        if (((StaffRoll *)p)->fastFlag == 1) ((StaffRoll *)p)->scriptTimer -= 4;
        else --((StaffRoll *)p)->scriptTimer;
        if (((StaffRoll *)p)->scriptTimer <= 0) {
            ((StaffRoll *)p)->scriptTimer = 0;
            ++((StaffRoll *)p)->fadeState;
        }
        break;
    case 3:
        if (((StaffRoll *)p)->fastFlag == 1) ((StaffRoll *)p)->slideProgress += 8;
        else ((StaffRoll *)p)->slideProgress += 2;
        v = ((StaffRoll *)p)->slideProgress;
        if (v >= 16) {
            *(volatile u16 *)0x04000050 = 0;
            BG_SYS_SetMainPlaneVisible(8, 0);
            BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)(&matrix), 0, (s32)0x1000, 0x1000, 0);
            BG_SYS_SetScrollRegs(3, (union MtxFx22 *)(&matrix), 0x80, 0x60);
            STAFF_ROLL_ReloadGraphics(p, 0);
            *(u8 *)&((StaffRoll *)p)->slideProgress = 0;
            ((StaffRoll *)p)->fadeState = 0;
            return 0;
        } else {
            *(volatile u16 *)0x04000052 = (16 - v) | (v << 8);
            scale = ((StaffRoll *)p)->slideProgress / 2 + 1;
            BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)(&matrix), 0, (s32)((scale << 12)), (scale << 12), 0);
            BG_SYS_SetScrollRegs(3, (union MtxFx22 *)(&matrix), 0x80, 0x60);
        }
        break;
    }
    return 1;
}

int STAFF_ROLL_CmdPrintEntry(char *p, unsigned char *q)
{
    if (((StaffRollEntry *)q)->text == 0xffff) {
        ((StaffRoll *)p)->scriptTimer = ((StaffRollEntry *)q)->y;
        ((StaffRoll *)p)->scriptState = 1;
        return 1;
    }
    if (((StaffRoll *)p)->scriptTimer == 0)
        ((StaffRoll *)p)->scriptTimer = ((StaffRollEntry *)q)->y;
    STAFF_ROLL_PrintRowText(p, q);
    if (((StaffRollEntry *)((char *)q + 0x10))->opcode != 0 || ((StaffRollEntry *)((char *)q + 0x10))->y != 0) {
        ((StaffRoll *)p)->scriptState = 1;
        return 1;
    }
    return 0;
}

int STAFF_ROLL_CmdShowEntry(char *p, unsigned char *q)
{
    if (((StaffRoll *)p)->scriptState == 0) {
        ((StaffRoll *)p)->entryMode = q[7];
        ((StaffRoll *)p)->scriptState = 2;
    }
    STAFF_ROLL_PrintEntry(p, q);
    if (((StaffRollEntry *)((char *)q + 0x10))->opcode != 1)
        return 1;
    return 0;
}

int STAFF_ROLL_CmdSetEntryMode(char *p, unsigned char *q)
{
    ((StaffRoll *)p)->entryMode = q[7];
    ((StaffRoll *)p)->scriptState = 3;
    return 1;
}

int STAFF_ROLL_CmdStartScroll(char *p)
{
    ((StaffRoll *)p)->scrollActive = 1;
    return 0;
}

int STAFF_ROLL_CmdStopScroll(char *p)
{
    ((StaffRoll *)p)->scrollActive = 0;
    return 0;
}

int STAFF_ROLL_CmdEnd(char *p)
{
    ((StaffRoll *)p)->scriptState = 5;
    return 1;
}

int STAFF_ROLL_CmdNop(void)
{
    return 1;
}

int STAFF_ROLL_CmdShowPlane(void)
{
    BG_SYS_SetMainPlaneVisible(1, 1);
    return 1;
}

int STAFF_ROLL_CmdHidePlane(void)
{
    BG_SYS_SetMainPlaneVisible(1, 0);
    return 1;
}

int STAFF_ROLL_CmdQueueLight(u8 *p,u8 *q){u8 *s=(u8 *)((uptr)p+0x28);STAFF_ROLL_QueueLight(s,q[7],((StaffRollEntry *)q)->y);STAFF_ROLL_SetLightMode(s,1);return 1;}

int STAFF_ROLL_CmdSetRecord(char *ctx, unsigned char *rec)
{
#if VERSION == VERSION_WHITE
    rec = rec + ((rec[7] + 1) << 4);       /* White's record table has one more leading record */
#else
    rec = rec + (rec[7] << 4);
#endif
    STAFF_ROLL_PrintRowText(ctx, rec);
    ((StaffRoll *)ctx)->scriptTimer = ((StaffRollEntry *)rec)->y;
    ((StaffRoll *)ctx)->scriptState = 1;
    return 1;
}
