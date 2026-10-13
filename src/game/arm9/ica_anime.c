/*
 * file:     ica_anime.c
 * unit:     yes
 * function: func_02010D98, func_02010DB4, func_02010DCC, func_02010DF4, func_02010E14, func_02010EA0, sub_02010EB4, func_02010EC0, func_02010EEC, func_02010F18, func_02010F40, func_02010F50, func_02010F7C, func_02010F8C, func_02010F94, func_02010FA0, func_02010FAC, func_02010FB0, func_02010FF4, func_02011014, func_0201102C, func_0201104C, func_020110CC, func_02011168, func_0201119C, func_020111BC, func_020111E8, func_020111EC, func_0201121C, func_02011264, func_0201126C, func_0201127C, func_02011290, func_02011298, func_02011324, func_02011328, func_02011330, func_0201134C, func_0201137C, func_02011398, func_020113B0, func_020113B4, func_020113C4, func_020113D0, func_020113D8, func_020113F0, func_02011400, func_02011410, func_02011428, func_0201147C, func_020114D0, func_02011510, func_02011558, func_02011590, func_020115C0, func_020115EC, func_02011608, func_0201160C, func_02011610, func_02011638, func_02011660, func_02011688, func_020116C0, func_020116E0, func_02011770, func_020117D8, func_0201183C, func_02011B8C, func_02011CF0, func_02011D0C, func_02011D28, func_02011D34, func_02011D40, func_02011D60, func_02011D7C, func_02011D9C, func_02011EAC, func_02011EC0, func_02011EEC, func_02011F24, func_02011F28, func_02011F90, func_02011FB8, func_02011FCC, func_0201205C, func_02012088, func_0201209C, func_020120A4, func_020120B4, func_020120C0, func_020120D8, func_020120F0, func_020120F4, func_020120F8, func_02012104, func_02012108, func_0201210C, func_02012110, func_02012114, func_02012124, func_0201212C, func_02012134, func_02012138, func_0201213C, func_02012144, func_0201214C, func_02012158, func_02012164, func_020121CC, func_02012204, func_02012210, func_02012220, func_02012248, func_02012258, func_02012264, func_020122A4, func_020122B4, func_020122C0, func_02012304, func_02012314, func_0201232C, func_0201235C, func_02012374, func_02012380, func_020123C4, func_020123D8, func_0201240C, func_02012444, func_02012474, func_020124AC, func_020124E4, func_020124E8, func_020124EC, func_020124F0, func_020124F4, func_02012704, func_02012798, func_020127A4, func_020127AC, func_020127B8, func_020127C4, func_020127D0, func_020127E0, func_020127F0, func_02012800, func_0201281C, func_0201283C, func_02012844, func_0201284C, func_02012854, func_02012870, func_02012878, func_02012894, func_0201289C, func_020128B8, func_020128C0, sub_02011292, sub_020113D2
 * address:  0x02010D98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _GPowerState  0x021461E8  data
 *   _u32_div_f   0x0209C2B0  arm
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0201BA34  0x0201BA34  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_0201C158  0x0201C158  thumb
 *   _ll_mul     0x0209C054  arm
 *   _ll_sdiv    0x0209BE5C  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   _VmFileName 0x020A7268  data
 *   func_0203F4CC  0x0203F4CC  arm
 *   _TimeZoneTable  0x0209DF24  data  a1
 *   _TimeZoneLightTable  0x0209DF10  data  a1
 *   func_02030734   0x02030734  arm
 *   func_02011770  0x02011770  thumb
 *   _IcaAnimeFileName  0x020A7270  data
 *   func_02049238     0x02049238  arm
 *   _fgr           0x0209BBB0  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   func_0204944C  0x0204944C  arm
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   _IcaCameraForward  0x0209DF84  data
 *   _IcaCameraUp  0x0209DF90  data
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_020520FC  0x020520FC  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   sub_020056A0   0x020056A0  thumb
 *   _GameSystemGlobal  0x02146248  data
 *   func_0203064C  0x0203064C  arm
 *   func_020306F0  0x020306F0  arm
 *   ov230_id       0x000000E6  data
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   func_0215FA00  0x0215FA00  thumb  ov010
 *   func_02012088     0x02012088  thumb
 *   func_020315D4     0x020315D4  arm
 *   func_02087BCC     0x02087BCC  arm
 *   func_02031324  0x02031324  arm
 *   func_020261E4  0x020261E4  thumb
 *   func_0202B4BC  0x0202B4BC  thumb
 *   func_020139B0  0x020139B0  thumb
 *   func_0202B4F0  0x0202B4F0  thumb
 *   func_02026250  0x02026250  thumb
 *   func_02013A48  0x02013A48  thumb
 *   func_020267BC     0x020267BC  thumb
 *   func_02021438     0x02021438  thumb
 *   func_02012A24  0x02012A24  thumb
 *   func_02035614  0x02035614  arm
 *   func_020129FC  0x020129FC  thumb
 *   func_0201205C  0x0201205C  thumb
 *   func_0202627C  0x0202627C  thumb
 *   func_02031330  0x02031330  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A14  0x02028A14  thumb
 *   func_0202B500  0x0202B500  thumb
 *   func_02021464  0x02021464  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_02188BE8     0x02188BE8  thumb  ov021
 *   func_0203133C  0x0203133C  arm
 *   func_02031348  0x02031348  arm
 *   ov021_id          0x00000015  data
 *   FieldMapProcData  0x021D359C  data  ov021
 *   func_02012BB0  0x02012BB0  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D34  0x02013D34  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02158318  0x02158318  thumb  ov010
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_0203CD98     0x0203CD98  arm
 *   func_02026454     0x02026454  thumb
 *   func_020263D8     0x020263D8  thumb
 *   func_02035138  0x02035138  arm
 *   func_02035064  0x02035064  arm
 *   _GameEventFileName  0x020A727C  data
 *   _GameDataFileName  0x020A728C  data
 *   func_020070A4  0x020070A4  thumb
 *   func_0202E888  0x0202E888  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008844  0x02008844  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200884C  0x0200884C  thumb
 *   func_02006E40  0x02006E40  thumb
 *   func_02012A60  0x02012A60  thumb
 *   func_02008468  0x02008468  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008730  0x02008730  thumb
 *   memcpy         0x02082D44  arm
 *   func_0216237C  0x0216237C  thumb  ov010
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_02012FE4  0x02012FE4  thumb
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_020071CC  0x020071CC  thumb
 *   func_0216CC58  0x0216CC58  thumb  ov010
 *   func_02028844  0x02028844  thumb
 *   func_02014428  0x02014428  thumb
 *   func_02008254  0x02008254  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02007AA4  0x02007AA4  thumb
 *   func_020097C4  0x020097C4  thumb
 *   func_0200BDE4  0x0200BDE4  thumb
 *   func_02161D98  0x02161D98  thumb  ov010
 *   func_0200857C  0x0200857C  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0215E31C  0x0215E31C  thumb  ov010
 *   func_0202E43C  0x0202E43C  thumb
 *   func_02012C18  0x02012C18  thumb
 *   func_0202E770  0x0202E770  thumb
 *   func_0202751C  0x0202751C  thumb
 *   func_021647A0  0x021647A0  thumb  ov010
 *   func_021647D8   0x021647D8  thumb  ov010
 *   func_02027584   0x02027584  thumb
 *   func_0202E794   0x0202E794  thumb
 *   func_0215E334   0x0215E334  thumb  ov010
 *   func_02006E64   0x02006E64  thumb
 *   func_02007AC8   0x02007AC8  thumb
 *   func_0216CCB0   0x0216CCB0  thumb  ov010
 *   func_02159BBC   0x02159BBC  thumb  ov010
 *   func_021623BC   0x021623BC  thumb  ov010
 *   func_02014444   0x02014444  thumb
 *   func_0202889C   0x0202889C  thumb
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_02008850  0x02008850  thumb
 */
#include "btl_setup_types.h"

struct ProcSys;
struct Proc;
struct Pokemon;
struct ScriptVm;
struct IcaAnime;
struct ArcFile;
struct Mtx33;
struct MiscSave;
struct GameSystem;
struct GameData;
struct BgmInfo;
struct GameComm;
struct PlayerWork;
struct WirelessSave;
struct GameEvent;
struct BagCursor;
struct SaveControl;
struct PlayerStatus;
struct Config;
struct Situation;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef enum { GPOWER_TYPE_FIRST = 0, GPOWER_TYPE_MAX = 13 } GPowerType;

typedef unsigned short u16;

/* RTC time as func_0203F4CC fills it. */
struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

/* One record of the pass power table (archive 0x26 member 0, 12 bytes). */
typedef struct GPowerData {
    u16 nameId;
    u16 cost;
    u8  reserved[4];
    u16 value;
    u8  type;
    u8  durationHours;
} GPowerData;

/* Active pass powers, one slot per power type (0x60 bytes at 0x021461E8). */
typedef struct GPowerState {
    u32 secondsLeft[GPOWER_TYPE_MAX];
    u8  activeId[GPOWER_TYPE_MAX];
    u8  pad41;
    u16 value[GPOWER_TYPE_MAX];
    u8  selectedType;
    u8  pad5D[3];
} GPowerState;

#define GPOWER_ID_NONE   0x30
#define GPOWER_TYPE_NONE 0xD

typedef signed int     s32;

typedef signed long long s64;

typedef int (*ScriptCmdFn)(struct ScriptVm *vm, void *user);

typedef int (*ScriptWaitFn)(struct ScriptVm *vm, void *user);

typedef int (*ScriptHookFn)(struct ScriptVm *vm, void *user, void *arg, u32 op);

typedef struct ScriptVmParams {
    u16 stack_cap;
    u16 ring_cap;
    const ScriptCmdFn *cmds;
    u32 cmd_count;
} ScriptVmParams;

typedef struct ScriptVm {
    ScriptVmParams params;
    u8 depth;
    u8 state;
    u8 ring_depth;
    u8 pad_0f;
    ScriptWaitFn wait;
    u8 *pc;
    u32 *stack;
    u32 *ring;
    void *user;
    ScriptHookFn hook;
    void *hook_arg;
    void *data;
} ScriptVm;


struct Vec3 { s32 x; s32 y; s32 z; };

/*
 * ICA camera animation (0x38 bytes): per-frame translate, rotate and scale
 * tracks read from an archive member, buffered bufFrameNum frames at a time
 * starting at bufTopFrame.
 */
struct IcaAnime {
    u16 heapId;
    u16 pad02;
    struct ArcFile *arcHandle;
    u32 dataId;
    u32 frameNum;
    s32 frame;
    s32 bufTopFrame;
    s32 bufFrameNum;
    struct Vec3 *transBuf;
    struct Vec3 *rotBuf;
    struct Vec3 *scaleBuf;
    u32 hasTrans;
    u32 hasRot;
    u32 hasScale;
    u32 bufAllocated;
};


typedef signed char s8;

typedef signed short s16;

/* Game initialisation parameters (0x14 bytes, GAMESYSTEM_SetupInitWork). */
/*
 * Work of the save-screen proc of unit_02010B98.c (0x1A8 bytes at heap 0x5B,
 * func_02010BB8); only the fields func_02010D98 and that constructor touch.
 */
struct SaveScreenWork {
    u32 initParam;
    u32 reserved;
    struct ProcSys *procSys;
};

struct GameInitWork {
    u32 mode;
    struct Vec3 position;
    u16 zoneId;
    u16 direction;
};

/* Statics of gamesystem.c (0x02146248). */
struct GameSystemGlobal {
    struct GameSystem *gameSystem;
    u32 tamperCount;
    struct GameInitWork initWork;
};

struct GameEvent;
typedef int (*GameEventFunc)(struct GameEvent *event, u32 *seq, void *work);
typedef struct GameEvent *(*GameEventCreatorFn)(struct GameSystem *gameSystem, void *arg);

/* Game system proc work (0x34 bytes, GAMESYSTEM_GetWorkSize). */
struct GameSystem {
    u16   heapId;
    u8    pad02[2];
    u32   initParam;
    struct ProcSys *procSys;
    u32   procStatus;
    GameEventCreatorFn eventCreator;
    void *eventCreatorArg;
    struct GameEvent *event;
    struct GameData *gameData;
    void *fieldMap;
    struct GameComm *gameComm;
    u32   reserved;
    void *issSystem;
    u8    fieldMapState;
    u8    eventActive;
    u8    commBlocked;
    u8    netOffBySleep : 1;
    u8    unusedBits : 7;
};

/* One running event of the game system (0x14 bytes, game_event.c). */
struct GameEvent {
    struct GameEvent *parent;
    GameEventFunc func;
    u32   seq;
    void *work;
    struct GameSystem *gameSystem;
};

/* Work of GAME_EVENT_CallProcSeq (GAME_EVENT_CallProc). */
struct ProcCallWork {
    u32   overlayId;
    void *procData;
    void *param;
};

/* Work of GAME_EVENT_OverlaySeq (GAME_EVENT_CreateOverlayEvent, 0x10 bytes). */
struct OverlayEventWork {
    u32   overlayId;
    struct GameEvent *event;
    u32   reserved[2];
};

extern void func_0203133C(struct ProcSys *procSys);
extern void func_020315D4(struct Proc *proc);
extern u32 _u32_div_f(u32 dividend, u32 divisor);
extern void *func_02048F60(u32 arcId, u32 dataId, u32 heapId);
extern u32 func_020307B0(void *memory);
extern void func_0201BA34(void *party);
extern u32 func_0201AB08(void *party);
extern void *func_0201AB28(void *party, u32 slot);
extern u32 func_02017D30(struct Pokemon *pokemon);
extern u32 func_02017E1C(void *pokemon, u32 param, u32 arg);
extern void func_02017E40(void *pokemon, u32 param, u32 value);
extern u32 func_02017D70(struct Pokemon *pokemon, u32 fastMode);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void func_0203F4CC(struct RtcTime *time);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02049238(struct ArcFile *arc);
extern struct ArcFile *sub_020490F4(unsigned int arcId, unsigned int heapId);
extern void  func_0204944C(struct ArcFile *arc, u32 dataId, u32 offset, u32 size, void *dst);
extern void func_02048AFC(void *camera, struct Vec3 *position);
extern void func_02048B20(void *camera, struct Vec3 *up);
extern void func_02048B44(void *camera, struct Vec3 *target);
extern void func_020520FC(int angleX, int angleY, int angleZ, struct Mtx33 *out);
extern void func_0207B51C(struct Vec3 *vec, struct Vec3 *mtx, struct Vec3 *out);
extern void func_0207C9D0(struct Vec3 *lhs, struct Vec3 *rhs, struct Vec3 *out);
extern u32 func_0203F0A8(void);
extern void *sub_020056A0(u32 task, u32 work, u32 priority);
extern void func_0203064C(unsigned int parentHeapId, unsigned int heapId, unsigned int size);
extern void func_020306F0(unsigned int heapId);
extern int func_02034AC4(int overlayId);
extern u32   func_021882A0(void (*caller)(void), void (*target)(void), u32 arg);
extern u32   func_02188354(void (*caller)(void), void (*target)(void), u32 arg);
extern u32   func_02188390(void (*caller)(void), void (*target)(void), u32 arg);
//P
extern void  func_02034A5C(s32 overlayId);
extern void *func_0203159C(struct Proc *proc, u32 size, u32 heapId);
extern struct GameEvent *func_0215FA00(struct GameSystem *gameSystem, u32 initParam);
extern struct MiscSave *func_02012F08(struct GameData *gameData);
extern u32 func_0200C258(struct MiscSave *miscSave);
extern void func_02012088(struct GameSystem *gameSystem);
extern void func_02087BCC(u32 mode);
extern struct ProcSys *func_02031324(int heapId);
extern struct GameComm *func_020261E4(unsigned int heapId, struct GameData *gameData);
extern void *func_0202B4BC(struct GameData *gameData, unsigned int heapId);
extern void func_020139B0(u32 heapId);
extern void func_0202B4F0(void *issSystem);
extern void func_02026250(struct GameComm *gameComm);
extern void func_02013A48(void);
extern void func_020267BC(struct GameData *gameData);
extern void func_02021438(void);
extern u8 func_02012A24(const struct GameData *gameData);
extern void func_02035614(int frames);
extern u8 func_020129FC(struct GameData *gameData);
extern void func_0201205C(struct GameSystem *gameSystem);
extern void func_0202627C(struct GameComm *gameComm);
extern unsigned int func_02031330(struct ProcSys *procSys);
extern struct BgmInfo *func_02012A30(const struct GameData *gameData);
extern void func_02028A14(struct BgmInfo *bgmInfo);
extern void func_0202B500(void *issSystem);
extern void func_02021464(struct GameData *gameData);
extern u32 func_0200F7B8(u32 mode);
extern void func_02031348(struct ProcSys *procSys, u32 overlayId, void *procData, void *param);
extern u32 func_02012BB0(const struct GameData *gameData);
extern void func_02012BC8(struct GameData *gameData, int on);
extern u16   func_02012AC8(const struct PlayerWork *player);
extern u32 func_02013D34(u32 zoneId);
extern u32   func_0200FB24(void);
extern int func_02158318(struct GameSystem *gameSystem);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern struct WirelessSave *func_0200921C(struct GameData *gameData);
extern u8 func_020090E0(const struct WirelessSave *wirelessSave);
extern int func_0203CD98(void);
extern u32 func_02026454(struct GameComm *gameComm);
extern void func_020263D8(struct GameComm *gameComm, u32 mode, struct GameSystem *gameSystem);
extern void func_02035138(void (*callback)(struct GameSystem *), struct GameSystem *gameSystem);
extern void func_02035064(int (*callback)(struct GameSystem *), struct GameSystem *gameSystem);
extern struct SaveControl *func_020070A4(void);
extern u8    func_0202E888(void);
extern struct Situation *func_02008854(struct SaveControl *saveControl);
extern struct Location *func_02008844(u32 situation);
extern struct Location *func_02008848(struct Situation *situation);
extern struct Location *func_0200884C(struct Situation *situation);
extern struct BagCursor *func_02006E40(u32 heapId);
extern void func_02012A60(struct PlayerWork *player);
extern int func_02008468(void);
extern struct PlayerStatus *func_02012944(struct GameData *gameData);
extern struct PlayerStatus *func_02008730(struct SaveControl *saveControl);
extern void *memcpy(void *dst, const void *src, u32 size);
extern int func_0216237C(int heapId);
extern void func_021623DC(void *eventData);
extern void *func_02012FE4(struct SaveControl *saveControl);
extern u16 *func_02159B48(int heapId);
extern void *func_020071CC(struct SaveControl *saveControl, u32 blockId);
extern void *func_0216CC58(int heapId, int count, int saveBlock);
extern struct BgmInfo *func_02028844(struct GameData *gameData, u32 heapId);
extern u32   func_02014428(int heapId);
extern void *func_02008254(u32 heapId);
extern struct Config *func_0200873C(struct SaveControl *saveControl);
extern u32 *func_02007AA4(u32 heapId, u32 saveControl);
extern void *func_020097C4(int heapId);
extern void func_0200BDE4(void *slot);
extern void  func_02161D98(void *unionInfo);
extern void *func_0200857C(u32 heapId);
extern u8 func_020071E4(const struct SaveControl *saveControl);
extern void *func_0215E31C(u32 heapId);
extern void  func_0202E43C(void *rtcWork);
extern void func_02012C18(struct GameData *gameData);
extern void *func_0202E770(void *heapId);
extern u32   func_0202751C(int heapId, u32 flags);
extern u8 *func_021647A0(struct GameData *gameData, u32 heapId);
extern int func_021647D8(int musicalWork);
extern void func_02027584(u32 itemUseWork);
extern void func_0202E794(void *pmsWork);
extern void func_0215E334(void *fieldGimmick);
extern void func_02006E64(struct BagCursor *bagCursor);
extern void func_02007AC8(void *boxManager);
extern int func_0216CCB0(int occupyInfo);
extern void func_02159BBC(void *fieldWork);
extern int func_021623BC(int eventData);
extern void func_02014444(u32 moveModelSys);
extern void func_0202889C(struct BgmInfo *bgmInfo);
extern struct MusicalShot *func_0200A864(struct SaveControl *saveControl);
extern u16 *func_0200A890(struct MusicalShot *shot);
extern u8 *func_0200A898(struct MusicalShot *shot);
extern void func_02082D44(void *dst, const void *src, u32 size);
extern int func_02161D64(int unionInfo);
extern u16 *func_02008850(struct Situation *situation);
int func_02010D98(struct Proc *proc, u32 *seq, void *param, struct SaveScreenWork *work);
void func_02010DB4(void);
void func_02010DCC(void);
void func_02010DF4(void);
void sub_02010E14(int powerId, const GPowerData *table, int select);
u8 sub_02010EA0(int powerId, const GPowerData *table);
u8 sub_02010EB4(int type);
u32 func_02010EC0(u32 type);
int func_02010EEC(void);
u8 func_02010F18(void);
void func_02010F40(int powerId, const GPowerData *table);
void func_02010F50(int type);
GPowerData *func_02010F7C(u32 heapId);
void func_02010F8C(GPowerData *table);
unsigned int func_02010F94(const GPowerData *table, int powerId);
unsigned int func_02010FA0(const GPowerData *table, int powerId);
void sub_02010FAC(void);
u32 func_02010FB0(u32 rate);
u32 func_02010FF4(u32 steps);
int func_02011014(int friendship);
u32 func_0201102C(u32 price);
u32 func_0201104C(void *party);
u32 func_020110CC(void *party);
u32 func_02011168(u32 exp);
u32 func_0201119C(u32 money);
s32 func_020111BC(s32 rate);
u32 func_020111E8(void);
void func_020111EC(ScriptVm *vm);
ScriptVm *func_0201121C(u32 heapId, const ScriptVmParams *params);
void func_02011264(ScriptVm *vm);
void func_0201126C(ScriptVm *vm, void *user);
void func_0201127C(ScriptVm *vm, u8 *pc);
ScriptVm *sub_02011290(ScriptVm *vm);
int func_02011298(ScriptVm *vm);
void *sub_02011324(ScriptVm *vm);
void sub_02011328(ScriptVm *vm, ScriptHookFn hook, void *arg);
u16 func_02011330(ScriptVm *vm);
u32 func_0201134C(ScriptVm *vm);
void func_0201137C(ScriptVm *vm, u32 value);
u32 func_02011398(ScriptVm *vm);
void func_020113B0(ScriptVm *vm, u8 *pc);
void func_020113B4(ScriptVm *vm, u8 *pc);
u8 *func_020113C4(ScriptVm *vm);
void func_020113D0(ScriptVm *vm, ScriptWaitFn wait);
u32 func_020113D8(u32 season);
int func_020113F0(int season, int hour);
u8 func_02011400(int season, int timeZone);
u32 func_02011410(u32 season);
struct IcaAnime *func_02011428(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize);
struct IcaAnime *func_0201147C(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize);
struct IcaAnime *func_020114D0(u32 heapId, u32 arcId, u32 dataId);
struct IcaAnime *func_02011510(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);
void func_02011558(struct IcaAnime *anime);
u32 func_02011590(struct IcaAnime *anime, s32 step);
u32 func_020115C0(struct IcaAnime *anime, s32 step);
void func_020115EC(struct IcaAnime *anime, s32 frame);
u32 func_02011608(struct IcaAnime *anime);
u32 func_0201160C(struct IcaAnime *anime);
u32 func_02011610(struct IcaAnime *anime, struct Vec3 *trans);
u32 func_02011638(struct IcaAnime *anime, struct Vec3 *rot);
u32 func_02011660(struct IcaAnime *anime, struct Vec3 *scale);
u32 func_02011688(struct IcaAnime *anime, struct Vec3 *trans, u32 frame);
void func_020116C0(struct IcaAnime *anime);
void func_020116E0(struct IcaAnime *anime, u32 arcId, u32 dataId, u32 heapId);
void func_02011770(struct IcaAnime *anime, int bufFrameNum);
int func_020117D8(struct IcaAnime *anime, int bufFrameNum, u8 *buffer, int bufferSize);
void func_0201183C(struct IcaAnime *anime, s32 frame);
void func_02011B8C(void *camera, struct IcaAnime *anime);
void func_02011CF0(void *camera, struct IcaAnime *anime);
void func_02011D0C(void *camera, struct IcaAnime *anime);
u32 func_02011D28(u32 (*func)(void));
void func_02011D34(void);
void func_02011D40(void);
void func_02011D60(void);
void func_02011D7C(void);
u32 func_02011D9C(struct Proc *proc, u32 *seq, u32 initParam);
u32 func_02011EAC(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem);
u32 func_02011EC0(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem);
struct GameInitWork *func_02011EEC(u32 mode, u16 zoneId, struct Vec3 *position, int direction);
u32 func_02011F24(void);
void func_02011F28(struct GameSystem *gameSystem, u16 heapId, u32 initParam);
void func_02011F90(struct GameSystem *gameSystem);
void func_02011FB8(struct GameSystem *gameSystem, u16 heapId, u32 initParam);
int func_02011FCC(struct GameSystem *gameSystem);
void sub_0201209C(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);
void func_020120A4(struct GameSystem *gameSystem);
void func_020120B4(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
void func_020120C0(struct GameSystem *gameSystem);
int func_020120D8(struct GameSystem *gameSystem);
u32 func_020120F0(const struct GameSystem *gameSystem);
struct GameData *func_020120F4(const struct GameSystem *gameSystem);
struct PlayerWork *func_020120F8(const struct GameSystem *gameSystem);
struct GameEvent *func_02012104(const struct GameSystem *gameSystem);
void func_02012108(struct GameSystem *gameSystem, struct GameEvent *event);
void *func_0201210C(const struct GameSystem *gameSystem);
void func_02012110(struct GameSystem *gameSystem, void *fieldMap);
u32 func_02012114(const struct GameSystem *gameSystem);
void func_02012124(struct GameSystem *gameSystem, u32 state);
u8 func_0201212C(const struct GameSystem *gameSystem);
void *func_02012134(const struct GameSystem *gameSystem);
struct GameComm *func_02012138(const struct GameSystem *gameSystem);
void func_0201213C(struct GameSystem *gameSystem, u32 blocked);
u8 func_02012144(const struct GameSystem *gameSystem);
u32 func_0201214C(const struct GameSystem *gameSystem);
void func_02012158(struct GameSystem *gameSystem, unsigned int on);
u32 func_02012164(struct GameSystem *gameSystem);
u32 func_020121CC(struct GameSystem *gameSystem);
u32 func_02012204(const struct GameSystem *gameSystem);
void func_02012210(struct GameSystem *gameSystem);
void func_02012220(struct GameSystem *gameSystem);
void func_02012248(struct GameSystem *gameSystem);
void func_02012258(struct GameSystem *gameSystem);
int func_02012264(struct GameSystem *gameSystem);
void func_020122A4(struct GameSystem *gameSystem);
void func_020122B4(struct GameSystem *gameSystem);
struct GameEvent *sub_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
int func_02012304(struct GameEvent *event);
void func_02012314(struct GameEvent *event);
void func_0201232C(struct GameEvent *event, GameEventFunc func, u32 workSize);
void func_0201235C(struct GameEvent *now, struct GameEvent *next);
void func_02012374(struct GameEvent *parent, struct GameEvent *child);
int func_02012380(struct GameSystem *gameSystem);
int func_020123C4(struct GameSystem *gameSystem);
int func_020123D8(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);
int func_0201240C(struct GameEvent *event, u32 *seq, void *work);
void func_02012444(struct GameEvent *parent, u32 overlayId, void *procData, void *param);
int func_02012474(struct GameEvent *event, u32 *seq, void *work);
struct GameEvent *func_020124AC(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg);
struct GameSystem *sub_020124E4(struct GameEvent *event);
void *sub_020124E8(struct GameEvent *event);
u32 *sub_020124EC(struct GameEvent *event);
struct GameEvent *sub_020124F0(struct GameEvent *event);
struct GameData *func_020124F4(u16 heapId);
void func_02012704(struct GameData *gameData);
struct PlayerWork *func_02012798(struct GameData *gameData, int index);
struct PlayerWork *func_020127A4(struct GameData *gameData);
void *func_020127AC(struct GameData *gameData, u32 index);
void *func_020127B8(struct GameData *gameData);
u8 *func_020127C4(struct GameData *gameData);
u8 *sub_020127D0(struct GameData *gameData, u32 index);
u16 *func_020127E0(struct GameData *gameData);
u8 *func_020127F0(struct GameData *gameData);
void func_02012800(struct GameData *gameData, void *dst);
void func_0201281C(struct GameData *gameData);
u32 func_0201283C(const struct GameData *gameData);
void *func_02012844(const struct GameData *gameData);
struct Location *func_0201284C(const struct GameData *gameData);
void func_02012854(struct GameData *gameData, const struct Location *location);
struct Location *func_02012870(const struct GameData *gameData);
void func_02012878(struct GameData *gameData, const struct Location *location);
struct Location *func_02012894(const struct GameData *gameData);
void func_0201289C(struct GameData *gameData, const struct Location *location);
struct Location *func_020128B8(const struct GameData *gameData);
void func_020128C0(struct GameData *gameData, const struct Location *location);
struct Location *func_020128DC(struct GameData *gameData);
void func_020128E4(struct GameData *gameData, const struct Location *location);
void func_02012900(const struct GameData *gameData, u16 warpId);
extern GPowerState _GPowerState;
extern const char _VmFileName[];
extern const u8 _TimeZoneTable[][0x18];
extern const u8 _TimeZoneLightTable[][5];
extern const char _IcaAnimeFileName[];
extern struct Vec3 _IcaCameraForward;
extern struct Vec3 _IcaCameraUp;
extern struct GameSystemGlobal _GameSystemGlobal;
extern u8 ov230_id[];
extern u8 ov021_id[];
extern u8 FieldMapProcData;
extern const char _GameEventFileName[];
extern const char _GameDataFileName[];


int func_02010D98(struct Proc *proc, u32 *seq, void *param, struct SaveScreenWork *work)
{
    func_0203133C(work->procSys);
    func_020315D4(proc);
    func_020306F0(0x5b);
    return 1;
}


/*
 * Zeroes the 0x60-byte array and reinitialises it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DB4.c \
 *       --func func_02010DB4 --addr 0x02010DB4 --thumb --cc 1.1p1
 */
void func_02010DB4(void)
{
    MI_CpuFill8(&_GPowerState, 0, sizeof(GPowerState));
    func_02010DF4();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DCC.c \
 *       --func func_02010DCC --addr 0x02010DCC --cc 1.1p1 --thumb
 *
 * net_save.c: decrement every counter above 1, then tail-call the empty
 * placeholder sub_02010FAC (pool word 0x02010FAD, `matched`).  The counter
 * is an enum, which keeps the unfolded pre-loop guard with a plain
 * increment; see func_02010DF4.c and docs/notes/pkt_02010DCC.c.txt.
 */
void func_02010DCC(void)
{
    GPowerType type;

    for (type = 0; type < GPOWER_TYPE_MAX; type++) {
        if (_GPowerState.secondsLeft[type] > 1) {
            _GPowerState.secondsLeft[type]--;
        }
    }
    sub_02010FAC();
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DF4.c \
 *       --func func_02010DF4 --addr 0x02010DF4 --cc 1.1p1 --thumb
 *
 * net_save.c: clear all thirteen counter slots, then deselect (+0x1c = 0xd,
 * the "none" slot).  Wave 14 closed the residue of
 * docs/notes/pkt_02010DCC.c.txt (unfolded pre-loop guard plus a plain
 * increment, "no C type gives both"): the counter is an ENUM.  With
 * -enum int an enum counter keeps the `cmp r4, #0xd; bge` entry guard
 * (mwcc does not fold the first test for an enum-typed induction variable)
 * and increments without a truncation pair.  The slot count is an enum
 * constant; 13 is a content constant (docs/families/net_save.h).
 */
void func_02010DF4(void)
{
    GPowerType type;

    for (type = 0; type < GPOWER_TYPE_MAX; type++) {
        func_02010F50(type);
    }
    _GPowerState.selectedType = GPOWER_TYPE_MAX;
}



/*
 * Records one play-time entry.  `rec` is an array of 0xc-byte records; the
 * record's +0xa byte is the SLOT (0..0xc) and +0xb is a count of hours, which
 * is stored as SECONDS in _GPowerState.secondsLeft[type] (0xe10 = 3600).  The +8 halfword
 * goes into the parallel halfword table at _GPowerState.value, and the selected-slot
 * byte _GPowerState.selectedType is cleared to 0xd when it named this slot and set to
 * this slot when `select` is 1.
 *
 * The four-case switch is emitted as a comparison TREE, not a table, because
 * the cases (0, 1, 7, 8) are not dense; the pairs are each other's partner
 * (slot 0 clears slot 1 and vice versa, slot 7 clears slot 8 and vice versa).
 *
 * EXACT* : the listing's extent runs to 0x02010EC0 because the two leaf
 * accessors that follow at 0x02010EA0 and 0x02010EB4 save no lr and so carry
 * no label (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Both should be seeded into layout/function_starts.txt.
 *
 * Addresses are Black-image addresses; 0x30 (the record-count bound) and 0xd
 * (the slot count) are content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010E14.c \
 *       --func sub_02010E14 --addr 0x02010E14 --cc 1.1p1 --thumb
 */
void sub_02010E14(int powerId, const GPowerData *table, int select)
{
    int type;

    if (powerId >= GPOWER_ID_NONE) {
        return;
    }
    table = table + powerId;
    type = table->type;
    _GPowerState.activeId[type] = (u8)powerId;
    _GPowerState.secondsLeft[type] = table->durationHours * 3600;
    _GPowerState.value[type] = table->value;
    if (_GPowerState.selectedType == type) {
        _GPowerState.selectedType = GPOWER_TYPE_NONE;
    }
    if (select == 1) {
        _GPowerState.selectedType = (u8)type;
    }
    switch (type) {
    case 0:
        func_02010F50(1);
        break;
    case 1:
        func_02010F50(0);
        break;
    case 7:
        func_02010F50(8);
        break;
    case 8:
        func_02010F50(7);
        break;
    }
}



/*
 * The second unlabelled leaf after sub_02010E14 (it saves no lr, so
 * disasm.py never labels it; see docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md).  It reads the state byte for the record `rec[slot]`
 * names, using the same 0xc-byte record stride and +0xa slot field that
 * sub_02010E14 writes with.
 *
 * The pointer must be ADVANCED into its own value first: writing the whole
 * thing as one subscript, `_GPowerState.activeId[rec[slot * 0xc + 0xa]]`, folds the
 * +0xa into the scaled index and gives `adds r2, #0xa; ldrb r1, [r1, r2]`
 * where the original has `adds r0, r1, r2; ldrb r1, [r0, #0xa]` - four bytes
 * in the same place, same size, and the only difference in the function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010EA0.c \
 *       --func sub_02010EA0 --addr 0x02010EA0 --cc 1.1p1 --thumb
 */
u8 sub_02010EA0(int powerId, const GPowerData *table)
{
    table = table + powerId;
    return _GPowerState.activeId[table->type];
}


/*
 * One of the two leaf accessors that follow sub_02010E14 and carry no label
 * because they save no lr (docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).  It reads the state byte of one slot straight out of the
 * thirteen-entry byte table; see docs/families/net_save.h section 4.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010EB4.c \
 *       --func sub_02010EB4 --addr 0x02010EB4 --cc 1.1p1 --thumb
 */
u8 sub_02010EB4(int type)
{
    return _GPowerState.activeId[type];
}


/*
 * Returns 0 for a 0x30 entry, otherwise the counter divided by 0x3c (or 1).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010EC0.c \
 *       --func func_02010EC0 --addr 0x02010EC0 --thumb --cc 1.1p1
 */
u32 func_02010EC0(u32 type)
{
    u32 minutes;

    if (_GPowerState.activeId[type] == GPOWER_ID_NONE) {
        return 0;
    }
    minutes = _GPowerState.secondsLeft[type] / 60;
    return minutes != 0 ? minutes : 1;
}


/*
 * Index _GPowerState.selectedType selects one of thirteen u32 counters in _GPowerState.secondsLeft;
 * 0xd means "none" and answers 0, otherwise the counter is divided by 60 and
 * a zero quotient is lifted to 1.  The divide is unsigned (`_u32_div_f`), so the
 * counter is read as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010EEC.c \
 *       --func func_02010EEC --addr 0x02010EEC --cc 1.1p1 --thumb
 */
int func_02010EEC(void)
{
    u8 type = _GPowerState.selectedType;
    u32 minutes;

    if (type == GPOWER_TYPE_NONE) {
        return 0;
    }
    minutes = _GPowerState.secondsLeft[type] / 60;
    if (minutes == 0) {
        minutes = 1;
    }
    return minutes;
}



/*
 * Returns the byte-table entry _GPowerState.activeId of the first of the thirteen counter slots whose value is 1,
 * or 0x30 when none is. The loop index is the Slot enum (as in func_02010DF4): an int index lets
 * mwcc fold the constant entry guard away.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02010F18(void)
{
    GPowerType type;

    for (type = 0; type < GPOWER_TYPE_MAX; type++) {
        if (_GPowerState.secondsLeft[type] == 1)
            return _GPowerState.activeId[type];
    }
    return GPOWER_ID_NONE;
}



/*
 * Clears the counter slot named by byte 0xA of entry idx in a 12-byte-entry table.
 *
 * Addresses are Black-image addresses.
 */
void func_02010F40(int powerId, const GPowerData *table)
{
    func_02010F50(table[powerId].type);
}



/*
 * Clears slot `idx` of the same thirteen-entry counter table and marks the byte
 * table _GPowerState.activeId; if the slot was the selected one (_GPowerState.selectedType) the
 * selection is reset to 0xd.  The bound test is SIGNED (`bge`, not `bhs`): the
 * index is an int.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010F50.c \
 *       --func func_02010F50 --addr 0x02010F50 --cc 1.1p1 --thumb
 */
void func_02010F50(int type)
{
    if (type >= GPOWER_TYPE_NONE) {
        return;
    }
    _GPowerState.activeId[type] = GPOWER_ID_NONE;
    _GPowerState.secondsLeft[type] = 0;
    if (_GPowerState.selectedType == type) {
        _GPowerState.selectedType = GPOWER_TYPE_NONE;
    }
}



/*
 * Loads archive 0x26 member 0 on the given heap.
 *
 * Addresses are Black-image addresses.
 */
GPowerData *func_02010F7C(u32 heapId)
{
    return func_02048F60(0x26, 0, heapId);
}



/*
 * Frees a buffer from func_02010F7C.
 *
 * Addresses are Black-image addresses.
 */
void func_02010F8C(GPowerData *table)
{
    func_020307B0(table);
}



/*
 * Unlabelled Thumb leaf: byte at +0xa of the 12-byte record idx.
 */
unsigned int func_02010F94(const GPowerData *table, int powerId)
{
    return table[powerId].type;
}



/*
 * Unlabelled Thumb leaf: halfword at +0x2 of the 12-byte record idx.
 */
unsigned int func_02010FA0(const GPowerData *table, int powerId)
{
    return table[powerId].cost;
}




/*
 * An empty function: a pool word in the image holds 0x02010FAD (Thumb), so
 * this two-byte `bx lr` is a real entry point, a placeholder callback that
 * disasm.py could not label because it saves nothing.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010FAC.c \
 *       --func sub_02010FAC --addr 0x02010FAC --cc 1.1p1 --thumb
 */
void sub_02010FAC(void)
{
}



/*
 * Two mode bytes (+0x14, +0x15) and two scales (+2, +4), each arm clamped to 100
 * (`if (v > 100) v = 100;`) after the unsigned scale divide.  The two arms end
 * at one shared `pop`, which is why the compiler tail-merged them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010FB0.c \
 *       --func func_02010FB0 --addr 0x02010FB0 --cc 1.1p1 --thumb
 */
u32 func_02010FB0(u32 rate)
{
    if (_GPowerState.activeId[0] != GPOWER_ID_NONE) {
        rate = _GPowerState.value[0] * rate / 100;
        if (rate > 100) rate = 100;
        return rate;
    }
    if (_GPowerState.activeId[1] != GPOWER_ID_NONE) {
        rate = _GPowerState.value[1] * rate / 100;
        if (rate > 100) rate = 100;
    }
    return rate;
}



/*
 * Scale by _GPowerState.value[2] unless _GPowerState.activeId[2]
 * is 0x30.  The divide is unsigned (`_u32_div_f`, which the runtime
 * table at 0x0209C2B0 calls `_div_by_zero_check`: mwcc's own symbol name for
 * the site is the `_u32_div_f` one, see docs/notes/pkt_0202EC44.c.txt), and the
 * multiply is spelled table-value-first: `x * v`, not `v * x`, or the result
 * register comes out r1 and the function is four bytes too long.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010FF4.c \
 *       --func func_02010FF4 --addr 0x02010FF4 --cc 1.1p1 --thumb
 */
u32 func_02010FF4(u32 steps)
{
    if (_GPowerState.activeId[2] != GPOWER_ID_NONE)
        steps = _GPowerState.value[2] * steps / 100;
    return steps;
}


int func_02011014(int friendship)
{
    if (_GPowerState.activeId[3] != GPOWER_ID_NONE)
        friendship += _GPowerState.value[3];
    return friendship;
}



/*
 * Same shape as func_02010FF4, mode byte +0x18, scale +0xa.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201102C.c \
 *       --func func_0201102C --addr 0x0201102C --cc 1.1p1 --thumb
 */
u32 func_0201102C(u32 price)
{
    if (_GPowerState.activeId[4] != GPOWER_ID_NONE)
        price = _GPowerState.value[4] * price / 100;
    return price;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201104C.c  *       --func func_0201104C --addr 0x0201104C --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x19 (slot 5): unless the +0xc factor
 * is 999, pick the record func_0201AB08(box) names inside the box
 * (func_0201AB28: box + 8 + idx * 0xdc), and add the +0xc factor to its
 * field 0xa0 clamped to field 0xa1, inside the func_02017D30 /
 * func_02017D70 access bracket; then clear slot 5.  Returns the index, or
 * 0xff when the mode byte is '0'.
 *
 * Wave 14 closed the entry residue shared with func_020110CC and
 * func_020111BC (pool word loaded into r1 before the parameter copy):
 * it was ARITY, not order.  func_0201BA34, func_0201AB08 (a tail-call
 * forwarder that passes r0 through) and func_02017D30 all take the box
 * or record pointer, so r0 stays live across the guards.  The record is
 * a separate local from the box parameter (reassigning the parameter
 * swaps r4/r5).
 */
u32 func_0201104C(void *party)
{
    void *pokemon;
    u32 slot;
    u32 fastMode;
    int maxHp;
    int hp;

    if (_GPowerState.activeId[5] != GPOWER_ID_NONE) {
        if (_GPowerState.value[5] == 999) {
            func_0201BA34(party);
            slot = 0;
        } else {
            slot = func_0201AB08(party);
            pokemon = func_0201AB28(party, slot);
            fastMode = func_02017D30(pokemon);
            maxHp = func_02017E1C(pokemon, 0xa1, 0);
            hp = func_02017E1C(pokemon, 0xa0, 0);
            hp = hp + _GPowerState.value[5];
            if (hp > maxHp) {
                hp = maxHp;
            }
            func_02017E40(pokemon, 0xa0, hp);
            func_02017D70(pokemon, fastMode);
        }
        func_02010F50(5);
        return slot;
    }
    return 0xff;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020110CC.c  *       --func func_020110CC --addr 0x020110CC --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x1a (slot 6): for each of the record's
 * four slots whose field 0x36+i is set, add the +0xe factor to field
 * 0x3a+i, clamped to func_0201C158(field 0x36+i, field 0x3e+i); inside the
 * func_02017D30 / func_02017D70 access bracket; then clear slot 6.  Same
 * declarations as func_0201104C.c (the callees take the box / record
 * pointer, the record is its own local), which is what closed the
 * entry-order residue of docs/notes/pkt_0201104C.sub_020110CC.c.txt.
 */
u32 func_020110CC(void *party)
{
    void *pokemon;
    u32 slot;
    u32 fastMode;
    u32 i;
    u32 move;
    u32 maxPp;
    u32 pp;

    if (_GPowerState.activeId[6] != GPOWER_ID_NONE) {
        slot = func_0201AB08(party);
        pokemon = func_0201AB28(party, slot);
        fastMode = func_02017D30(pokemon);
        for (i = 0; i < 4; i++) {
            move = func_02017E1C(pokemon, (int)(0x36 + i), (int)0);
            if (move != 0) {
                maxPp = (u32)func_0201C158(move, (u8)func_02017E1C(pokemon, (int)(0x3e + i), (int)0));
                pp = func_02017E1C(pokemon, (int)(0x3a + i), (int)0);
                pp += _GPowerState.value[6];
                if (pp > maxPp) {
                    pp = maxPp;
                }
                func_02017E40(pokemon, (int)(0x3a + i), pp);
            }
        }
        func_02017D70(pokemon, fastMode);
        func_02010F50(6);
        return slot;
    }
    return 0xff;
}



/*
 * Two mode bytes (+0x1b, +0x1c) and two scales (+0x10, +0x12) on the same two
 * tables; the first arm returns early, the second falls into the shared exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011168.c \
 *       --func func_02011168 --addr 0x02011168 --cc 1.1p1 --thumb
 */
u32 func_02011168(u32 exp)
{
    if (_GPowerState.activeId[7] != GPOWER_ID_NONE)
        return _GPowerState.value[7] * exp / 100;
    if (_GPowerState.activeId[8] != GPOWER_ID_NONE)
        exp = _GPowerState.value[8] * exp / 100;
    return exp;
}



/*
 * Same shape as func_02010FF4, mode byte +0x1d, scale +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201119C.c \
 *       --func func_0201119C --addr 0x0201119C --cc 1.1p1 --thumb
 */
u32 func_0201119C(u32 money)
{
    if (_GPowerState.activeId[9] != GPOWER_ID_NONE)
        money = _GPowerState.value[9] * money / 100;
    return money;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020111BC.c
 *       --func func_020111BC --addr 0x020111BC --cc 1.1p1
 *
 * Scales v by the rate at +0x16 of the second record (v * rate / 100 in
 * 64 bits) unless the mode byte at +0x1e of the first is 0x30.  The 0x30
 * path has no return statement: the original falls off the end and hands
 * back v, still in r0.  Any written `return v;` makes the compiler join
 * the two paths through a copy (48 bytes); an s64 return type keeps the
 * size but colours the mode load in r3 (r1 is the high half of the
 * result).  See docs/idioms/a-missing-return-hands-back-the-parameter.md.
 */
s32 func_020111BC(s32 rate)
{
    if (_GPowerState.activeId[10] != GPOWER_ID_NONE) {
        return (s64)_GPowerState.value[10] * rate / 100;
    }
}



/*
 * Four bytes, `movs r0, #0x15; bx lr`: a constant getter, isolated between
 * two large unmatched functions, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020111E8.c \
 *       --func func_020111E8 --addr 0x020111E8 --cc 1.1p1
 */
u32 func_020111E8(void)
{
    return 0x15;
}



/*
 * The bottom two functions of the game's script virtual machine ("vm.c", the
 * __FILE__ string this unit's allocation site passes, at 0x020A7268, fixed by
 * the terminator of "net_save.c" at 0x020A725C).
 *
 * func_0201121C is the constructor: it takes a heap id and a 12-byte
 * descriptor { u16 stack_cap; u16 ring_cap; const ScriptCmdFn *cmds;
 * u32 cmd_count; }, allocates the 0x30-byte context plus both arrays behind
 * it in one block, copies the descriptor into the head of the context (12
 * bytes, so the copy is an inlined ldm/stm triple,
 * docs/idioms/aggregate-assignment-is-ldm-stm.md), and points +0x1c at the
 * first array and +0x18 one ring_cap past it.  Both capacities are read back
 * out of the caller's descriptor, not out of the context that was just
 * written, which is why the second ldrh addresses r5 and not r7.
 *
 * func_020111EC is the reset: program counter, both stack depths, the state
 * byte, the wait callback and the pre-dispatch hook all cleared, and both
 * arrays filled with zero at their declared capacities.  It is the shared
 * prologue of the two entry points in the next unit (func_0201126C and
 * func_0201127C, 0x0201126C and 0x0201127C).
 *
 * The 0x30-byte context is:
 *   +0x00 u16 stack_cap      (0x100 for the field script system)
 *   +0x02 u16 ring_cap       (0x40)
 *   +0x04 const ScriptCmdFn *cmds
 *   +0x08 u32 cmd_count
 *   +0x0c u8  stack depth
 *   +0x0d u8  state (0 stopped, 1 running, 2 waiting on the callback)
 *   +0x0e u8  ring depth
 *   +0x10 wait callback
 *   +0x14 u8 *pc
 *   +0x18 u32 *stack
 *   +0x1c u32 *ring
 *   +0x20 user object
 *   +0x24 pre-dispatch hook, +0x28 its argument
 *   +0x2c owner-defined word (the loaded script file, for the field system)
 *
 * The unit stops one word short of the Thumb-to-ARM veneer at 0x02011264
 * (`ldr r3,[pc,#0]; bx r3; .word 0x020307B0`), which no tu range may span
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020111EC.c \
 *       --addr 0x020111EC --thumb --cc 1.1p1
 */
void func_020111EC(ScriptVm *vm)
{
    vm->pc = 0;
    vm->ring_depth = 0;
    vm->state = 0;
    vm->wait = 0;
    vm->depth = 0;
    MI_CpuFill8(vm->stack, 0, vm->params.stack_cap * 4);
    MI_CpuFill8(vm->ring, 0, vm->params.ring_cap * 4);
    vm->hook = 0;
    vm->hook_arg = 0;
}



ScriptVm *func_0201121C(u32 heapId, const ScriptVmParams *params)
{
    u32 size;
    ScriptVm *vm;

    size = params->ring_cap * 4 + sizeof(ScriptVm) + params->stack_cap * 4;
    vm = (ScriptVm *)func_02030734(heapId, size, 0, _VmFileName, 96);
    MI_CpuFill8(vm, 0, size);
    vm->params = *params;
    vm->ring = (u32 *)(vm + 1);
    vm->stack = vm->ring + params->ring_cap;
    return vm;
}



void func_02011264(ScriptVm *vm)
{
    func_020307B0(vm);
}



/*
 *           sub_02011324, sub_02011328
 *
 * The step function of the game's script virtual machine ("vm.c"), plus the
 * four small entry points around it.  The context layout and the
 * constructor are in src/matched/unit_020111EC.c.
 *
 * func_02011298 is the interpreter core, called once per frame by the owner
 * of the context:
 *
 *   state 0  stopped, nothing to do
 *   state 1  running: fetch a u16 opcode with func_02011330 (the cursor read
 *            that advances +0x14 by two), bounds-check it against +0x08, run
 *            the optional pre-dispatch hook at +0x24, then call
 *            cmds[opcode](vm, user).  A handler returning 1 yields for this
 *            frame; returning 0 continues straight into the next opcode, so
 *            the whole loop is one frame's worth of script.
 *   state 2  waiting: call the callback at +0x10 with (vm, user) every frame
 *            until it returns 1, then clear it and go back to running.  A
 *            null callback in this state is treated as "done waiting".
 *
 * Every abnormal exit (null pc, opcode past the table, hook veto) stops the
 * machine by writing 0 to +0x0d and returning 0, and every yield returns 1;
 * the default arm's `state = 0; return 1` and the handler's `return 1` share
 * one tail (docs/idioms/switch-arms-tail-merge.md).
 *
 * Two shapes in the switch are load-bearing and neither is optional.  The
 * arms are written in the order 0, 2, 1, default: state 2 falls through into
 * state 1 once its callback is gone, which is what puts the wait block
 * physically before the loop and lets the fall-through reach the loop head
 * with no branch.  And the interpreter loop leaves through `break` twice
 * over (out of the `for`, then out of the switch) rather than by returning
 * in place, so that the yield and the default arm's stop share one
 * `movs r0, #1; pop` tail; writing `return 1` at either site splits that
 * tail and costs four bytes
 * (docs/idioms/switch-arms-tail-merge.md,
 * docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *
 * The wait callback has to be bound to a local: the original loads +0x10
 * once and both tests and calls that register, which a re-read of the field
 * across the call would not reproduce.
 *
 * sub_02011290, sub_02011324 and sub_02011328 carry no label in the
 * generated listing: none of the three saves `lr`, so disasm.py's prologue
 * sweep never fires and their bytes print as a `.word` run
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The field script system instantiates this VM in overlay 10 at
 * func_02158BFC with a 609-entry command table at 0x0217062C; see the
 * "Script virtual machine" section of docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201126C.c \
 *       --addr 0x0201126C --thumb --cc 1.1p1
 */
void func_0201126C(ScriptVm *vm, void *user)
{
    func_020111EC(vm);
    vm->user = user;
}



void func_0201127C(ScriptVm *vm, u8 *pc)
{
    func_020111EC(vm);
    vm->pc = pc;
    vm->state = 1;
}



ScriptVm *sub_02011290(ScriptVm *vm)
{
    vm->state = 0;
    vm->pc = 0;
    return vm;
}

/*
 * Alternate entry: sub_02011292() enters sub_02011290 two bytes in, after the
 * `movs r1, #0`, so the caller's r1 is stored to vm->state and vm->pc.
 */



int func_02011298(ScriptVm *vm)
{
    u32 op;
    ScriptWaitFn wait;

    switch (vm->state) {
    case 0:
        return 0;
    case 2:
        wait = vm->wait;
        if (wait != 0) {
            if (wait(vm, vm->user) == 1) {
                vm->wait = 0;
                vm->state = 1;
            }
            return 1;
        }
        vm->state = 1;
        /* fall through */
    case 1:
        for (;;) {
            if (vm->pc == 0) {
                vm->state = 0;
                return 0;
            }
            op = func_02011330(vm);
            if (op >= vm->params.cmd_count) {
                vm->state = 0;
                return 0;
            }
            if (vm->hook != 0) {
                if (vm->hook(vm, vm->user, vm->hook_arg, op) == 0) {
                    vm->state = 0;
                    return 0;
                }
            }
            if (vm->params.cmds[op](vm, vm->user) == 1) {
                break;
            }
        }
        break;
    default:
        vm->state = 0;
        break;
    }

    return 1;
}



void *sub_02011324(ScriptVm *vm)
{
    return vm->user;
}



void sub_02011328(ScriptVm *vm, ScriptHookFn hook, void *arg)
{
    vm->hook = hook;
    vm->hook_arg = arg;
}



/*
 *           func_020113B0, func_020113B4, func_020113C4
 *
 * Seven functions, no external calls at all, over two small structs read and
 * written by cursor.  Two of the seven carry no label in the generated
 * listing at all: func_0201134C and func_020113B0, both leaves whose
 * prologue (or total absence of one) saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * func_020113B0 is four bytes, `str r1, [r0, #0x14]; bx lr`: the plain
 * setter of the +0x14 field that func_020113B4 and func_020113C4 reach only
 * through a history ring.
 *
 * func_02011330 and func_0201134C are a matched pair, a little-endian u16
 * and u32 read off a byte cursor at +0x14, advancing it by 2 and by 4.
 * func_0201134C carries no label in the generated listing: it opens with
 * `push {r4, r5}`, which saves no `lr`, so disasm.py's prologue sweep never
 * fires on it and its 48 bytes print as a `.word` run between func_02011330
 * and func_0201137C (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Its four byte reads are built MSB-first through a Horner chain
 * (((0 + b3) << 8 + b2) << 8 + b1) << 8 + b0, which is what the register
 * allocator does with a `for` loop counting down; the two-byte version is
 * small enough that the same loop unrolls into the flat expression used
 * below.
 *
 * func_0201137C and func_02011398 are a fixed-capacity ring: a byte count at
 * +0xC bounded by a halfword capacity at +0x0, backed by a `u32` array
 * pointed to by +0x18.  func_0201137C pushes if there is room and returns
 * whether it did; func_02011398 pops the oldest entry, or 0 if the ring is
 * empty (and leaves the count at 0 rather than going negative).
 *
 * func_020113B4 and func_020113C4 are a different struct's accessors for a
 * plain u32 field at +0x14, the same offset func_020113B0 sets directly:
 * func_020113B4 pushes the field's old value onto a func_0201137C ring
 * before overwriting it with the new one, and func_020113C4 pops a
 * func_02011398 ring back into the field.  Both take the ring struct
 * pointer as the same first argument as the field's owner, so the two
 * structs are declared distinctly here (Ring and Cur) even though nothing
 * in this file proves they are not the same struct in the original; only
 * the offsets that are read are declared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011330.c \
 *       --addr 0x02011330 --thumb
 */
u16 func_02011330(ScriptVm *vm)
{
    u8  lo, hi;
    u16 high;

    lo = *vm->pc;
    vm->pc = vm->pc + 1;
    hi = *vm->pc;
    vm->pc = vm->pc + 1;
    high = (u16)(hi << 8);
    return lo + high;
}


u32 func_0201134C(ScriptVm *vm)
{
    u8  b0, b1, b2, b3;
    u32 value;

    b0 = *vm->pc;
    vm->pc = vm->pc + 1;
    b1 = *vm->pc;
    vm->pc = vm->pc + 1;
    b2 = *vm->pc;
    vm->pc = vm->pc + 1;
    b3 = *vm->pc;
    vm->pc = vm->pc + 1;

    value = 0;
    value = value + b3;
    value = value << 8;
    value = value + b2;
    value = value << 8;
    value = value + b1;
    value = value << 8;
    value = value + b0;
    return value;
}



void func_0201137C(ScriptVm *vm, u32 value)
{
    if (vm->depth + 1 < vm->params.stack_cap) {
        vm->stack[vm->depth] = value;
        vm->depth = vm->depth + 1;
    }
}


u32 func_02011398(ScriptVm *vm)
{
    if (vm->depth == 0) {
        return 0;
    }
    vm->depth = vm->depth - 1;
    return vm->stack[vm->depth];
}



void func_020113B0(ScriptVm *vm, u8 *pc)
{
    vm->pc = pc;
}


void func_020113B4(ScriptVm *vm, u8 *pc)
{
    u8 *ret = vm->pc;
    func_0201137C(vm, (u32)ret);
    vm->pc = pc;
}


u8 *func_020113C4(ScriptVm *vm)
{
    vm->pc = (u8 *)func_02011398(vm);
    return vm->pc;
}



void func_020113D0(ScriptVm *vm, ScriptWaitFn wait)
{
    vm->state = 2;
    vm->wait = wait;
}

/*
 * Alternate entry: sub_020113D2() enters func_020113D0 two bytes in, after the
 * `movs r2, #2`, so the caller's r2 is stored at +0x0d.
 */



/*
 * Fills a 12-byte buffer through func_0203F4CC and tail-hands its own
 * argument and the buffer's first word to func_020113F0, a table lookup
 * that is a documented near miss (src/matched/sub_02011410.c's header has
 * the details) and so is declared here only, not defined.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020113D8.c \
 *       --func func_020113D8 --addr 0x020113D8 --cc 1.1p1 --lang c99 --thumb
 */
u32 func_020113D8(u32 season)
{
    struct RtcTime time;

    func_0203F4CC(&time);
    return func_020113F0(season, time.hour);
}



/*
 * vm.c, 0x020113F0..0x02011410: two byte lookups in constant 2D tables,
 * rows of 0x18 and 5 bytes.  Plain subscripts `tbl[row][col]` give the
 * image's `base + row * stride` then `ldrb [col, base]`; the old pending
 * park (byte-offset arithmetic, docs/notes/pkt_020113F0.c.txt) was capped on
 * the two single-pool rodata tables, which sole-ref/self now carries.
 */
int func_020113F0(int season, int hour)
{
    return _TimeZoneTable[season][hour];
}



u8 func_02011400(int season, int timeZone)
{
    return _TimeZoneLightTable[season][timeZone];
}



/*
 * ica_anime.c: is the animation in one of the two "finished" states.  Both
 * arms return the same 1, which is why the original reaches one epilogue
 * from both compares - it is a single disjunction, not two ifs.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011410.c \
 *       --addr 0x02011410 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */
u32 func_02011410(u32 season)
{
    switch (func_020113D8(season)) {
    case 3:
    case 4:
        return 1;
    default:
        return 0;
    }
}




/*
 * ica_anime.c's 0x38-byte-object constructor: allocate, shared init, the
 * class-specific initialiser, then the load call.  Only the load call's
 * result is tested, so the failure path is the plain `return 0` and the
 * success path stores through the sibling and returns the object.  The
 * +0x0c field is re-read after func_020116E0 because the callee sets it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011428.c \
 *       --func func_02011428 --addr 0x02011428 --cc 1.1p1 --thumb
 */
struct IcaAnime *func_02011428(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize)
{
    struct IcaAnime *anime = func_02030734(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0x54);

    func_020116C0(anime);
    func_020116E0(anime, arcId, dataId, heapId);
    if (func_020117D8(anime, anime->frameNum, buffer, bufferSize) == 0) {
        return 0;
    }
    func_0201183C(anime, 0);
    return anime;
}




/*
 * The 0x74-byte sibling of func_02011428 in the same original file: same
 * allocation, shared init and class initialiser, but the load call forwards
 * the two stacked arguments rather than a field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201147C.c \
 *       --func func_0201147C --addr 0x0201147C --cc 1.1p1 --thumb
 */
struct IcaAnime *func_0201147C(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize)
{
    struct IcaAnime *anime = func_02030734(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0x74);

    func_020116C0(anime);
    func_020116E0(anime, arcId, dataId, heapId);
    if (func_020117D8(anime, bufFrameNum, buffer, bufferSize) == 0) {
        return 0;
    }
    func_0201183C(anime, 0);
    return anime;
}


/*
 * ica_anime.c: the third constructor (line 0x90 of "ica_anime.c").  The
 * object is 0x38 bytes and the four-argument initialiser gets the heap back
 * as its last argument, which is where r3 = r5 comes from.  func_020116C0 gets
 * the object straight from the allocator, which is why no move precedes it.
 *
 * The tail is the pair every one of these constructors ends with -
 * func_02011770(anime, anime->frameNum) and func_0201183C(anime, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020114D0.c \
 *       --func func_020114D0 --addr 0x020114D0 --cc 1.1p1 --thumb
 */
struct IcaAnime *func_020114D0(u32 heapId, u32 arcId, u32 dataId)
{
    struct IcaAnime *anime;

    anime = func_02030734(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0x90);
    func_020116C0(anime);
    func_020116E0(anime, arcId, dataId, heapId);
    func_02011770(anime, anime->frameNum);
    func_0201183C(anime, 0);
    return anime;
}



/*
 * ica_anime.c, the third constructor of the group: same prologue, same
 * 0x38-byte allocation (a different source line), but the class
 * initialiser is func_02011770 and the result is not tested - it always
 * runs the shared teardown initialiser and returns the object.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011510.c \
 *       --func func_02011510 --addr 0x02011510 --cc 1.1p1 --thumb
 */
struct IcaAnime *func_02011510(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum)
{
    struct IcaAnime *anime = func_02030734(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0xae);

    func_020116C0(anime);
    func_020116E0(anime, arcId, dataId, heapId);
    func_02011770(anime, bufFrameNum);
    func_0201183C(anime, 0);
    return anime;
}



/*
 * ica_anime.c: destroy.  The one field that is a plain pointer (+0x04) goes
 * through the archive/handle call first, and the three heap buffers at
 * +0x1C, +0x20 and +0x24 are released only when the 0x34 flag says they were
 * allocated - all four calls are the same free function, including the last
 * one on the object itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011558.c \
 *       --addr 0x02011558 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */
void func_02011558(struct IcaAnime *anime)
{
    func_02049238(anime->arcHandle);
    if (anime->bufAllocated != 0) {
        if (anime->transBuf != 0)
            func_020307B0(anime->transBuf);
        if (anime->rotBuf != 0)
            func_020307B0(anime->rotBuf);
        if (anime->scaleBuf != 0)
            func_020307B0(anime->scaleBuf);
    }
    func_020307B0(anime);
}



/*
 * ica_anime.c, 0x02011590..0x02011610: the frame-clock advance and its two
 * neighbours, plus the two four-byte getters that sit between them (they
 * carry no label because they have no prologue, so they are written here as
 * what they are).
 *
 *   func_02011590   advance the clock, reset it if the frame count is
 *                   reached, and poke the animation when the new frame falls
 *                   outside [f14, f14 + f18)
 *   func_020115C0   the same advance but returning "already finished" when
 *                   the frame at entry is past the count
 *   func_020115EC   set the clock outright
 *   (0x02011608)    getter: +0x0C
 *   (0x0201160C)    getter: +0x10
 *
 * The range check is one disjunction in every case: the original reaches the
 * single `bl func_0201183C` from both compares.
 *
 * Signedness: the frame is `f10 >> 12` with an arithmetic shift (asrs), but
 * the compare against f0c is unsigned (bhi/bhs), so f0c is a u32 field while
 * the clock and the frame bounds are s32.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011590.c \
 *       --addr 0x02011590 --thumb
 */
u32 func_02011590(struct IcaAnime *anime, s32 step)
{
    s32 frameIndex;
    u32 looped = 0;

    anime->frame = anime->frame + step;
    frameIndex = anime->frame >> 12;
    if (anime->frameNum <= (u32)frameIndex) {
        anime->frame = 0;
        frameIndex = 0;
        looped = 1;
    }
    if (frameIndex < anime->bufTopFrame || (anime->bufTopFrame + anime->bufFrameNum) <= frameIndex)
        func_0201183C(anime, anime->frame);
    return looped;
}


u32 func_020115C0(struct IcaAnime *anime, s32 step)
{
    s32 frameIndex = anime->frame >> 12;

    if ((u32)frameIndex < anime->frameNum) {
        anime->frame = anime->frame + step;
        frameIndex = anime->frame >> 12;
        if (frameIndex < anime->bufTopFrame || (anime->bufTopFrame + anime->bufFrameNum) <= frameIndex)
            func_0201183C(anime, anime->frame);
        return 0;
    }
    return 1;
}


void func_020115EC(struct IcaAnime *anime, s32 frame)
{
    s32 frameIndex = frame >> 12;

    anime->frame = frame;
    if (frameIndex < anime->bufTopFrame || (anime->bufTopFrame + anime->bufFrameNum) <= frameIndex)
        func_0201183C(anime, frame);
}



u32 func_02011608(struct IcaAnime *anime)
{
    return anime->frameNum;
}



u32 func_0201160C(struct IcaAnime *anime)
{
    return anime->frame;
}



/*
 * ica_anime.c, 0x02011610..0x02011688: three copies of one accessor on three
 * parallel field pairs, each of which copies a twelve-byte record out of a
 * table indexed by the current frame.
 *
 *   func_02011610   guard +0x28, table +0x1C
 *   func_02011638   guard +0x2C, table +0x20
 *   (0x02011660)    guard +0x30, table +0x24 - unlabelled in the listing
 *                   (no prologue: the function saves nothing), written here
 *                   as the third copy
 *
 * The index is `(f10 >> 12) - f14`, which is why the original does an asrs
 * by twelve and then a subtract before the multiply by twelve, and the copy
 * itself is one twelve-byte struct assignment (ldm/stm pair plus the third
 * word).  Returning 0 when the table pointer is null is what makes the two
 * epilogues.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011610.c \
 *       --addr 0x02011610 --thumb
 */
u32 func_02011610(struct IcaAnime *anime, struct Vec3 *trans)
{
    if (anime->hasTrans != 0) {
        *trans = anime->transBuf[(anime->frame >> 12) - anime->bufTopFrame];
        return 1;
    }
    return 0;
}


u32 func_02011638(struct IcaAnime *anime, struct Vec3 *rot)
{
    if (anime->hasRot != 0) {
        *rot = anime->rotBuf[(anime->frame >> 12) - anime->bufTopFrame];
        return 1;
    }
    return 0;
}


u32 func_02011660(struct IcaAnime *anime, struct Vec3 *scale)
{
    if (anime->hasScale != 0) {
        *scale = anime->scaleBuf[(anime->frame >> 12) - anime->bufTopFrame];
        return 1;
    }
    return 0;
}



/*
 * Copy frame `idx % count` of the f1c Vec3 table out to dst when the table
 * length at +0x18 equals the count at +0x0C; returns 1, else 0.  EXACT* because
 * the listing extent (56) includes the 2-byte `movs r0, r0` pad after the
 * second epilogue; the 54 code bytes are exact.
 *
 * Load-bearing (wave 20, after five waves at 14 to 26 out):
 *  - `idx %= n;` writes the remainder back into the PARAMETER, which homes it
 *    in r2 (`adds r2, r1, #0` before the compare).  A named local coalesces
 *    with the helper's r1 return instead.
 *  - the table base as an integer: `u32 src = (u32)anime->transBuf;` with a u32 byte
 *    offset `off = idx * 12`, the first field read at base + off and the
 *    cursor advanced in place (`base += off`) for +4 and +8.  With the base as
 *    an integer the multiply goes into a copy of idx (`adds r3, r2, #0;
 *    muls r3, r0, r3`) and the base is loaded after 12, as in the image;
 *    every pointer spelling (&transBuf[frame], t[frame], a struct cursor) multiplies
 *    idx in place.  Same family as
 *    docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md.
 *  - the two-return shape `if (==) { ...; return 1; } return 0;` gives the
 *    image's fall-through body and its two epilogues.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011688.c \
 *       --func func_02011688 --addr 0x02011688 --cc 1.1p1 --thumb
 */
u32 func_02011688(struct IcaAnime *anime, struct Vec3 *trans, u32 frame)
{
    u32 frameNum = anime->frameNum;

    frame %= frameNum;
    if (anime->bufFrameNum == frameNum) {
        /* stand-in: the image adds the byte offset after the first load;
           transBuf[frame].x/.y/.z is 4 bytes longer, a Vec3 pointer 4 bytes shorter */
        u32 offset = frame * sizeof(struct Vec3);
        u32 src = (u32)anime->transBuf;

        trans->x = *(s32 *)(src + offset);
        src += offset;
        trans->y = ((struct Vec3 *)src)->y;
        trans->z = ((struct Vec3 *)src)->z;
        return 1;
    }
    return 0;
}



void func_020116C0(struct IcaAnime *anime)
{
    anime->heapId = 0;
    anime->arcHandle = 0;
    anime->dataId = 0;
    anime->frameNum = 0;
    anime->frame = 0;
    anime->bufTopFrame = 0;
    anime->bufFrameNum = 0;
    anime->transBuf = 0;
    anime->rotBuf = 0;
    anime->scaleBuf = 0;
    anime->hasTrans = 0;
    anime->hasRot = 0;
    anime->hasScale = 0;
    anime->bufAllocated = 0;
}



/*
 * Open four channels: a halfword tag at +0, a handset object at +4, a peer
 * object at +8, and then func_0204944C(arcHandle, dataId, offset, len, dest) for
 * ids 0, 4, 5 and 6 -- the last three writing one byte each into buf[2],
 * buf[1] and buf[0], i.e. backwards from the end of the four-byte buffer.
 *
 * `v = 1;` is a SEPARATE statement after the four calls, not the
 * declaration initialiser.  As `u32 v = 1;` at the top of the body the
 * assignment is hoisted to the function entry (r6 = 1 before the first
 * call, the zero constant landing in r4), and the result is a diff of two
 * instructions at the end: the original keeps 1 in r4 (the register the
 * dead a2 parameter was homed to) and the 0 in r6, and the guard stores
 * `r4 = r6` on the equal arm instead of `r6 = r4`.  Sinking the assignment
 * to its own statement after the last call reproduces the original
 * allocation exactly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020116E0.c \
 *       --func func_020116E0 --addr 0x020116E0 --cc 1.1p1 --thumb
 */
void func_020116E0(struct IcaAnime *anime, u32 arcId, u32 dataId, u32 heapId)
{
    u8 channelFlags[4];
    u32 hasScale;

    anime->heapId = (u16)heapId;
    anime->arcHandle = sub_020490F4(arcId, heapId);
    anime->dataId = dataId;
    func_0204944C(anime->arcHandle, dataId, 0, 4, &anime->frameNum);
    func_0204944C(anime->arcHandle, anime->dataId, 4, 1, channelFlags + 2);
    func_0204944C(anime->arcHandle, anime->dataId, 5, 1, channelFlags + 1);
    func_0204944C(anime->arcHandle, anime->dataId, 6, 1, channelFlags);
    hasScale = 1;
    if (channelFlags[2] == 0) {
        hasScale = 0;
    }
    anime->hasScale = hasScale;
    anime->hasRot = (channelFlags[1] != 0);
    anime->hasTrans = (channelFlags[0] != 0);
}



void func_02011770(struct IcaAnime *anime, int bufFrameNum)
{
    anime->bufFrameNum = bufFrameNum;
    if (anime->hasTrans != 0) {
        anime->transBuf = func_02030734(anime->heapId, bufFrameNum * sizeof(struct Vec3),
                                        0, _IcaAnimeFileName, 0x25c);
    }
    if (anime->hasRot != 0) {
        anime->rotBuf = func_02030734(anime->heapId, bufFrameNum * sizeof(struct Vec3),
                                      0, _IcaAnimeFileName, 0x260);
    }
    if (anime->hasScale != 0) {
        anime->scaleBuf = func_02030734(anime->heapId, bufFrameNum * sizeof(struct Vec3),
                                        0, _IcaAnimeFileName, 0x264);
    }
    anime->bufAllocated = 1;
}



/*
 * Carve the caller's buffer into the translate, rotate and scale tracks
 * (bufFrameNum Vec3 each), only for the tracks the header enables.
 * bufferSize is the caller's byte budget: if it is smaller than
 * bufFrameNum * 12 times the number of enabled tracks nothing is written and
 * the call answers 0.  bufFrameNum is recorded in the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020117D8.c \
 *       --func func_020117D8 --addr 0x020117D8 --cc 1.1p1 --thumb
 */
int func_020117D8(struct IcaAnime *anime, int bufFrameNum, u8 *buffer, int bufferSize)
{
    int needSize;
    int trackSize;
    int track;

    needSize = 0;
    trackSize = bufFrameNum * sizeof(struct Vec3);
    track = 0;
    if (anime->hasTrans != 0) {
        needSize += trackSize;
    }
    if (anime->hasRot != 0) {
        needSize += trackSize;
    }
    if (anime->hasScale != 0) {
        needSize += trackSize;
    }
    if (bufferSize < needSize) {
        return 0;
    }
    if (anime->hasTrans != 0) {
        anime->transBuf = (struct Vec3 *)buffer;
        track++;
    }
    if (anime->hasRot != 0) {
        anime->rotBuf = (struct Vec3 *)(buffer + trackSize * track);
        track++;
    }
    if (anime->hasScale != 0) {
        anime->scaleBuf = (struct Vec3 *)(buffer + trackSize * track);
        track++;
    }
    anime->bufFrameNum = bufFrameNum;
    return 1;
}



#define FX_F32_TO_FX32(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))



/*
 * Load a window of an ICA animation: the frame index is (frame >> 12) modulo
 * anime->frameNum; the file offset is 8 + 12 * index per enabled track and
 * the read size 12 * anime->bufFrameNum per enabled track.  The floats are
 * read into a scratch buffer (func_0204944C, fifth argument = destination),
 * converted with the TwlSDK FX_F32_TO_FX32 macro into the three Vec3 tables
 * (hasScale gates scaleBuf, hasRot rotBuf, hasTrans transBuf), then freed;
 * anime->bufTopFrame = frame >> 12.
 *
 * Levers (wave 10), each measured; together 631 bytes out -> EXACT:
 *  - 0x0209C95C is _fadd and 0x0209CB8C is _fsub (layout/runtime_arm9.txt
 *    had them swapped until 2026-09-28).  With them declared that way the
 *    plain SDK macro `x > 0 ? x*4096.0f + .5f : x*4096.0f - .5f` reproduces
 *    both arms, including the (0.5, prod) / (prod, 0.5) argument orders.
 *  - the conversion is a MACRO over `floats[value + j]`, not an inline
 *    function, and the buffer is `volatile float *` (stand-in: plain RAM, but
 *    without volatile the element is loaded once; the image loads it for the
 *    compare and again in the taken arm, off a byte offset that gets its own
 *    stack slot per site, the nine slots sp+0x18..0x38).
 *  - func_0204944C takes five arguments; the fifth is the buffer ([sp]).
 *  - `frame >> 12` is written twice (the modulo and the final store) and
 *    never named: its CSE temporary takes the lowest spill slot (sp+4).  A
 *    named index local lands above the i*12 temporaries (14 bytes out).
 *  - `i = 0` sits between the alloc and the fill call (the image stores it
 *    there, sharing the alloc's zero), and the loop is `for (; i < ...)`.
 *  - declaration order frameIdx, value, floats, size, offset, index.
 */
void func_0201183C(struct IcaAnime *anime, s32 frame)
{
    s32 frameIdx;
    s32 value;
    volatile float *floats;
    u32 size;
    u32 offset;
    u32 index;

    index = (frame >> 12) % anime->frameNum;

    offset = 8;
    size = 0;
    if (anime->hasScale != 0) offset += index * 0xc;
    if (anime->hasRot != 0) offset += index * 0xc;
    if (anime->hasTrans != 0) offset += index * 0xc;
    if (anime->hasScale != 0) size += anime->bufFrameNum * 0xc;
    if (anime->hasRot != 0) size += anime->bufFrameNum * 0xc;
    if (anime->hasTrans != 0) size += anime->bufFrameNum * 0xc;

    floats = (volatile float *)func_02030734((u16)((anime->heapId & 0x7fff) | 0x8000), size, 0, _IcaAnimeFileName, 0x2bd);
    frameIdx = 0;
    func_0204944C(anime->arcHandle, anime->dataId, offset, size, (void *)floats);

    value = 0;
    for (; frameIdx < anime->bufFrameNum; frameIdx++) {
        if (anime->hasScale != 0) {
            anime->scaleBuf[frameIdx].x = FX_F32_TO_FX32(floats[value]);
            anime->scaleBuf[frameIdx].y = FX_F32_TO_FX32(floats[value + 1]);
            anime->scaleBuf[frameIdx].z = FX_F32_TO_FX32(floats[value + 2]);
            value += 3;
        }
        if (anime->hasRot != 0) {
            anime->rotBuf[frameIdx].x = FX_F32_TO_FX32(floats[value]);
            anime->rotBuf[frameIdx].y = FX_F32_TO_FX32(floats[value + 1]);
            anime->rotBuf[frameIdx].z = FX_F32_TO_FX32(floats[value + 2]);
            value += 3;
        }
        if (anime->hasTrans != 0) {
            anime->transBuf[frameIdx].x = FX_F32_TO_FX32(floats[value]);
            anime->transBuf[frameIdx].y = FX_F32_TO_FX32(floats[value + 1]);
            anime->transBuf[frameIdx].z = FX_F32_TO_FX32(floats[value + 2]);
            value += 3;
        }
    }
    func_020307B0((void *)floats);
    anime->bufTopFrame = frame >> 12;
}



/*
 * Sets a camera from the current ICA frame: the rotate track gives three
 * angles in degrees (fx 4.12); each is converted to float, wrapped into
 * 0..360 by repeated addition, rescaled to the 0..65535 angle units
 * func_020520FC wants, and turned into a rotation matrix.  The two constant
 * vectors _IcaCameraForward and _IcaCameraUp (copied in as whole 12-byte
 * aggregates, ldm/stm) are rotated by it; the translate track gives the
 * camera position, position + rotated forward the target, and the rotated
 * up vector the camera up.
 *
 * Shape notes that cost real time and are worth keeping:
 *   - the three angle values must be bound to named `u16' locals
 *     before the func_020520FC call.  Written inline as
 *     `(u16)(u32)(65535.0f * (h / 360.0f))' the lsls/lsrs #0x10 pair
 *     after each _ffixu disappears (about 10 bytes short).
 *   - the scratch the two func_0207B51C calls share is 36 bytes, not
 *     12: `struct Vec3 rotMtx[3]'.  With a plain `struct Vec3' the whole
 *     frame comes out `sub sp, #0x68' instead of `sub sp, #0x80' and
 *     nothing else differs, so the 24 extra bytes are real declared
 *     storage above 0x5c that this function never reads back.
 *   - the wrap-around is `h += 360.0f': 0x0209C95C is the soft-float
 *     add.  `h = h + 360.0f' puts the constant first (see docs/idioms/
 *     a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-
 *     assignment.md) and no longer matches.
 *   - declaration order is stack order: rotMtx highest, then rotDeg,
 *     forward, up, position, target, rotForward, rotUp.  Any other order shifts every sp offset.
 */
void func_02011B8C(void *camera, struct IcaAnime *anime)
{
    struct Vec3 rotMtx[3];
    struct Vec3 rotDeg;
    struct Vec3 forward;
    struct Vec3 up;
    struct Vec3 position;
    struct Vec3 target;
    struct Vec3 rotForward;
    struct Vec3 rotUp;
    u16 angleX;
    u16 angleY;
    u16 angleZ;
    float degX;
    float degY;
    float degZ;

    forward = _IcaCameraForward;
    up = _IcaCameraUp;

    func_02011638(anime, &rotDeg);

    degX = rotDeg.x / 4096.0f;
    degY = rotDeg.y / 4096.0f;
    degZ = rotDeg.z / 4096.0f;

    while (degX < 0.0f) {
        degX += 360.0f;
    }
    while (degY < 0.0f) {
        degY += 360.0f;
    }
    while (degZ < 0.0f) {
        degZ += 360.0f;
    }

    angleX = (u16)(u32)(65535.0f * (degX / 360.0f));
    angleY = (u16)(u32)(65535.0f * (degY / 360.0f));
    angleZ = (u16)(u32)(65535.0f * (degZ / 360.0f));
    func_020520FC(angleX, angleY, angleZ, (struct Mtx33 *)rotMtx);

    func_0207B51C(&forward, rotMtx, &rotForward);
    func_0207B51C(&up, rotMtx, &rotUp);

    func_02011610(anime, &position);
    func_0207C9D0(&position, &rotForward, &target);

    func_02048AFC(camera, &position);
    func_02048B44(camera, &target);
    func_02048B20(camera, &rotUp);
}



/*
 * Twelve bytes of stack filled by func_02011610 from the *second* argument
 * (the first word handed to it is r1, not r0), then the buffer goes to the ARM
 * function func_02048AFC together with the original first argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011CF0.c \
 *       --func func_02011CF0 --addr 0x02011CF0 --cc 1.1p1 --thumb
 */
void func_02011CF0(void *camera, struct IcaAnime *anime)
{
    struct Vec3 position;

    func_02011610(anime, &position);
    func_02048AFC(camera, &position);
}



/*
 * Identical to func_02011CF0 except for the second callee, func_02048B44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011D0C.c \
 *       --func func_02011D0C --addr 0x02011D0C --cc 1.1p1 --thumb
 */
void func_02011D0C(void *camera, struct IcaAnime *anime)
{
    struct Vec3 target;

    func_02011610(anime, &target);
    func_02048B44(camera, &target);
}



/*
 * func_02011D28 calls its argument, if not null, purely for effect: the
 * call falls straight through into `mvns r0, r4` with no branch around it,
 * so the return value is always the bitwise complement of the function
 * pointer itself, never whatever the call returned.
 *
 * func_02011D34 calls func_0203F0A8 twice and returns nothing, a debug
 * marker pair (begin/end) around nothing in between.
 *
 * func_02011D40 and func_02011D7C, on either side of the function between
 * this pair, were a documented register-swap near miss on their single
 * `_GameSystemGlobal.tamperCount += 1`; now EXACT (src/matched/func_02011D40.c and
 * src/matched/func_02011D7C.c). The fix was declaring the global as a
 * real struct and using field syntax (`_GameSystemGlobal.tamperCount += 1`) instead
 * of raw pointer-plus-offset arithmetic; not merged into this unit
 * because func_02011D60 between them stays out of the manifest (see
 * below).
 *
 * The function between them, func_02011D60, reproduces every byte the
 * comparison covers, but is left out of the manifest: the listing's extent
 * runs two bytes long across the `00 00` alignment pad in front of
 * func_02011D7C, an `EXACT*` this territory's policy does not accept
 * because the follower carries a real label rather than being the
 * unlabelled-follower case `EXACT*` is meant for.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011D28.c \
 *       --addr 0x02011D28 --thumb
 */
u32 func_02011D28(u32 (*func)(void))
{
    if (func != 0) {
        func();
    }
    return ~(u32)func;
}



void func_02011D34(void)
{
    func_0203F0A8();
    func_0203F0A8();
}



/*
 * Allocates 0x7F bytes off heap 0 through sub_020056A0.c's allocator
 * wrapper, tagged with func_02011D34's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * _GameSystemGlobal.tamperCount. See unit_02011D28.c's header for the sibling
 * func_02011D7C and the documented near miss on this increment.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011D40.c \
 *       --func func_02011D40 --addr 0x02011D40 --cc 1.1p1 --thumb
 */
void func_02011D40(void)
{
    sub_020056A0((u32)func_02011D34, 0, 0x7f);
    _GameSystemGlobal.tamperCount += 1;
}


void func_02011D60(void)
{
    func_0203064C(9, 5, 5 << 10);
    func_02011F24();
    func_020306F0(5);
}


/*
 * Allocates 0x7F bytes off heap 0 through sub_020056A0.c's allocator
 * wrapper, tagged with func_02011D34's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * _GameSystemGlobal.tamperCount. See unit_02011D28.c's header for the sibling
 * func_02011D40 (src/matched/func_02011D40.c, converted to EXACT
 * alongside this one) and the formerly-documented near miss on this
 * increment: the `_GameSystemGlobal.tamperCount += 1` register swap resolves when the
 * global is declared as a real struct (`_GameSystemGlobal.tamperCount += 1`) rather
 * than accessed through raw pointer-plus-offset arithmetic.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011D7C.c \
 *       --func func_02011D7C --addr 0x02011D7C --cc 1.1p1 --thumb
 */
void func_02011D7C(void)
{
    sub_020056A0((u32)func_02011D34, 0, 0x7f);
    _GameSystemGlobal.tamperCount += 1;
}


/*
 * promoted: wave 21 lane T, EXACT (match.py one, 25 of 25 relocations)
 *           once the ov230d token let the probe targets resolve
 *
 * ica_anime.c: scene bring-up.  Loads overlay 230, runs three checksum
 * probes over this family's own code (func_02011D28 to func_02011D40,
 * func_02011D60, func_02011D7C; each result compared with the complement of
 * the end address), creates three heaps through func_0203064C, allocates
 * the work block and publishes it to _GameSystemGlobal, then, when the probe
 * results do not add up to a multiple of 0x12AF, runs a func_0200C258-counted
 * loop of func_02011D40.
 *
 * Byte-correct: 272 of 272 bytes, 0 concrete bytes out (match.py one,
 * dsi/1.1p1, 2026-09-24 wave 21 lane H).  The lever that closed it after
 * eight waves at 8 out: the probes' shared start address is held in a u32
 * local (`start = (u32)func_02011D28;`) and cast back at each call
 * (docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md).
 * The local's web spans the second heap call, so the argument 4 there is
 * rematerialised (`movs r2,#4 ... movs r1,#4; lsls r2,r2,#14`) instead of
 * being common-subexpression-eliminated into r1, which is what the image
 * does; the single-call shape `off = 0; if (flag == 0) off = 0x191;` is the
 * right control flow once that holds.
 *
 * Probe targets (wave 21 lanes H2 and T): 0x021882A0, 0x02188354 and
 * 0x02188390 are slots 0, 3 and 4 of the six ARM thunk slots ov230's first
 * static initialiser (func_02188408) decrypts in place when this function
 * loads the overlay.  The ROM bytes there are ciphertext, so ov230's ROM
 * listing never labels them; tools/ovcrypt.py replays ov230's own
 * decryptor (every range checked to be a clean ARM function ending in a
 * return) and asm/ov230d/ov230d.s lists the result.  With the `ov230d`
 * token on the three symbols: lines they resolve as sole-ref/code against
 * that listing: 25 of 25 sites (ov230_id as overlay_id, func_0215FA00
 * sole-ref/code with the ov010 hint).
 */
u32 func_02011D9C(struct Proc *proc, u32 *seq, u32 initParam)
{
    u32 workSize;
    u32 checkSum;
    u32 intact;
    u32 checkPenalty;
    struct GameSystem *gameSystem;
    s32 penaltyCount;
    s32 i;
    u32 checkCaller;

    workSize = func_02011F24();
    checkCaller = (u32)func_02011D28;
    checkSum = 0xc35ffb;
    func_02034AC4((int)ov230_id);
    intact = 0;
    if (func_021882A0((void (*)(void))checkCaller, func_02011D40, 0) == ~(u32)func_02011D40)
        intact = 1;
    checkSum += intact * 0x47;
    func_0203064C(1, 3, 0xa << 12);
    intact = 1;
    if (func_02188354((void (*)(void))checkCaller, func_02011D60, 0) != ~(u32)func_02011D60)
        intact = 0;
    checkPenalty = 0;
    if (intact == 0)
        checkPenalty = 0x191;
    func_0203064C(1, 4, 4 << 14);
    func_02188390((void (*)(void))checkCaller, func_02011D7C, 0);
    func_0203064C(9, 5, 5 << 10);
    func_02034A5C((s32)ov230_id);
    gameSystem = func_0203159C(proc, workSize, 3);
    MI_CpuFill8(gameSystem, 0, workSize);
    _GameSystemGlobal.gameSystem = gameSystem;
    func_02011FB8(gameSystem, 3, initParam);
    func_02012108(gameSystem, func_0215FA00(gameSystem, initParam));
    if ((checkSum + checkPenalty) % 0x12af != 0) {
        penaltyCount = func_0200C258(func_02012F08(func_020120F4(gameSystem)));
        for (i = 0; i < penaltyCount; i++)
            func_02011D40();
    }
    return 1;
}



/*
 * Only the fourth parameter is used, and it is moved straight out of r3 into
 * r0 at entry - a one-argument wrapper whose first three arguments are the
 * caller's leftovers (r0..r2 are untouched, which is what the prologue's
 * `adds r0, r3, #0` says).
 *
 *           call inside this function (checked: `label` finds no outside
 *           branch, and no EXACT manifest entry covers 0x02011FCC, so
 *           `matched` does not reach it either).  No cut helps - shrinking
 *           the range to this function keeps the call inside it.  Writing
 *           0x02011FCC (144 bytes, packet pkt_02011F28) as an EXACT entry
 *           would close this one; nothing else will.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011EAC.c \
 *       --func func_02011EAC --addr 0x02011EAC --cc 1.1p1 --thumb
 */
u32 func_02011EAC(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem)
{
    if (func_02011FCC(gameSystem) != 0)
        return 1;
    return 0;
}



/*
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * was parked there on the call to 0x02012088 only; func_02012088 now has an
 * EXACT entry of its own, so the site resolves through the `matched` class and
 * the file needs no change.  The fourth parameter is moved out of r3 at entry
 * and passed first; then the first parameter; the three func_020306F0 calls
 * with consecutive ids 3, 4, 5 and a final func_02087BCC(0).  Returns 1.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011EC0.c \
 *       --func func_02011EC0 --addr 0x02011EC0 --cc 1.1p1 --thumb
 */
u32 func_02011EC0(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem)
{
    func_02012088(gameSystem);
    func_020315D4(proc);
    func_020306F0(3);
    func_020306F0(4);
    func_020306F0(5);
    func_02087BCC(0);
    return 1;
}



/*
 * The object at 0x02146248, seen through its +0x08 field: the pool words are
 * 0x02146250 (the address of +0x08, used both for the 0x14-byte clear and
 * for the return value), 0x02146248 and 0x02146254 (= +0x0C, the destination
 * of the twelve-byte record copy).  So the struct is
 * `{ pad[8]; u32 f8; Vec3 rec; u16 f18; u16 f1a; }` and the function
 * clears +0x08..+0x1C, stores two scalars, copies the record in and stores
 * one more scalar.
 *
 * The scalar store to +0x08 goes through the +0x08 pointer, the two
 * halfwords go through the +0x00 base, and the copy is one twelve-byte
 * aggregate assignment (the ldm/stm pair plus the third word).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011EEC.c \
 *       --func func_02011EEC --addr 0x02011EEC --cc 1.1p1 --thumb
 */
struct GameInitWork *func_02011EEC(u32 mode, u16 zoneId, struct Vec3 *position, int direction)
{
    MI_CpuFill8(&_GameSystemGlobal.initWork, 0, sizeof(struct GameInitWork));
    _GameSystemGlobal.initWork.mode = mode;
    _GameSystemGlobal.initWork.zoneId = zoneId;
    _GameSystemGlobal.initWork.position = *position;
    _GameSystemGlobal.initWork.direction = direction;
    return &_GameSystemGlobal.initWork;
}



/*
 * Four bytes, `movs r0, #0x34; bx lr`: the sizeof getter of the context record
 * whose accessors are src/matched/unit_020120F0.c and
 * src/matched/unit_02012204.c.  It is what pins that struct's size, and the
 * declaration here is the same one those two files carry, so the three check
 * each other.  It is a file of its own because the functions on either side of
 * it are not matched yet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011F24.c  *       --addr 0x02011F24 --thumb
 */
u32 func_02011F24(void)
{
    return sizeof(struct GameSystem);
}



/*
 * Initialise an ica_anime record (struct IcaAnime, docs/families/ica_anime.h)
 * for resource id `id`: open the handle (+0x08), clear the clock words,
 * load the table (+0x1c) and build its companion (+0x24) and the +0x2c
 * object from it, clear +0x32 and bit 0 of +0x33, then reset and start.
 *
 * The note's 8-byte r0/r1 "tie" (docs/notes/pkt_02011F28.c.txt) was a
 * misread arity: func_020261E4 takes TWO arguments (its own matched file
 * reads r1), and the second is the table just stored at +0x1c, passed as
 * `p->f1c` -- which the compiler forwards from the register, hence the
 * `adds r1, r0, #0` the image has before the id reload.  Written as a
 * struct, not raw pointer casts.  EXACT* only because the 2-byte pad at
 * 0x02011F8E runs the extent to 0x02011F90.
 */
void func_02011F28(struct GameSystem *gameSystem, u16 heapId, u32 initParam)
{
    gameSystem->heapId = heapId;
    gameSystem->initParam = initParam;
    gameSystem->procSys = func_02031324(gameSystem->heapId);
    gameSystem->procStatus = 0;
    gameSystem->eventCreator = 0;
    gameSystem->eventCreatorArg = 0;
    gameSystem->event = 0;
    gameSystem->gameData = func_020124F4(gameSystem->heapId);
    gameSystem->fieldMap = 0;
    gameSystem->gameComm = func_020261E4(gameSystem->heapId, gameSystem->gameData);
    gameSystem->reserved = 0;
    gameSystem->issSystem = func_0202B4BC(gameSystem->gameData, heapId);
    gameSystem->commBlocked = 0;
    gameSystem->netOffBySleep = 0;
    func_02012248(gameSystem);
    func_020122A4(gameSystem);
    func_020139B0(heapId);
}



/*
 * Teardown: two calls on the object itself, then three on its words at +0x2c,
 * +0x1c and +0x24, then a final no-argument call.  Every callee resolves on its
 * own manifest entry or on a label outside the range, so the file is EXACT up to
 * the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011F90.c \
 *       --func func_02011F90 --addr 0x02011F90 --cc 1.1p1 --thumb
 */
void func_02011F90(struct GameSystem *gameSystem)
{
    func_020122B4(gameSystem);
    func_02012258(gameSystem);
    func_0202B4F0(gameSystem->issSystem);
    func_02012704(gameSystem->gameData);
    func_02026250(gameSystem->gameComm);
    func_02013A48();
}



/*
 * The object goes through func_02011F28 with r0-r2 untouched, then one field
 * destructor and a global call.
 *
 *           (its only caller in the image is this function) and 0x020267BC at
 *           +0x0A.  Both are byte-correct here; the range cannot be cut to
 *           free them because the call is inside the only function that makes
 *           it.  Folding 0x02011F28 into the same unit would take the packet
 *           to 0x02011F28.. and is possible - see the note in
 *           docs/notes/pkt_02011F28.c.txt.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011FB8.c \
 *       --func func_02011FB8 --addr 0x02011FB8 --cc 1.1p1 --thumb
 */
void func_02011FB8(struct GameSystem *gameSystem, u16 heapId, u32 initParam)
{
    func_02011F28(gameSystem, heapId, initParam);
    func_020267BC(gameSystem->gameData);
    func_02021438();
}



/*
 * Byte-correct, MATCH-capped: all 144 concrete bytes reproduce, the four
 * remaining wildcards are call sites whose targets live in OTHER PACKETS and
 * have no witness outside this range:
 *
 *   +0034  bl func_02012380   -> pkt_02012380
 *   +003A  bl func_0202627C   -> pkt_0202627C
 *   +0052  bl func_0202B500   -> pkt_0202B500
 *   +0058  bl func_02021464   -> pkt_02021464
 *
 * Each reports `no witness outside 02011FCC..02012060`, i.e. the only branch
 * anywhere in the image reaching them is the call in this function, so the
 * `label` class cannot attest them and no cut frees them.  Blocking class:
 * label.  Nothing in this C changes when those packets are filed -- the file
 * graduates for free.
 *
 * Two spellings this function pinned down:
 *
 *  - The last guard is ONE conjunction, `a == 0 && b == 0 -> return 1`.  The
 *    equivalent disjunction (`a != 0 || b != 0 -> return 0`) makes mwcc pick
 *    the other arm as the fall-through and comes out four bytes of wrong
 *    layout: `bne #0x2012054` + `beq` + the two `movs r0` swapped, where the
 *    original branches BOTH tests to a shared out-of-line `movs r0,#0; pop`
 *    and falls through to `movs r0,#1`.
 *  - The state word at +0x0c is re-read from memory at each use rather than
 *    cached in a register, so it is spelled as the field every time.
 */
int func_02011FCC(struct GameSystem *gameSystem)
{
    func_020120A4(gameSystem);
    if (func_02012A24(gameSystem->gameData) != 0)
        func_02035614(0x1e);
    if (func_020129FC(gameSystem->gameData) == 0) {
        func_020123D8(gameSystem, gameSystem->eventCreator, gameSystem->eventCreatorArg);
        func_0201205C(gameSystem);
        func_02012380(gameSystem);
        func_0202627C(gameSystem->gameComm);
    }
    gameSystem->procStatus = func_02031330(gameSystem->procSys);
    func_02028A14(func_02012A30(gameSystem->gameData));
    func_0202B500(gameSystem->issSystem);
    func_02021464(gameSystem->gameData);
    if (func_02012A24(gameSystem->gameData) != 0)
        func_02035614(0x3c);
    if (gameSystem->procStatus == 2 || gameSystem->procStatus == 0)
        func_0200F7B8(0);
    if (gameSystem->procStatus == 0 && gameSystem->event == 0)
        return 1;
    return 0;
}


extern int func_02188BE8(void *fieldMap);   /* overlay-resident */

/*
 * Three nested tests sharing one epilogue: the object is driven through
 * func_020121CC only when func_020120D8 returns 0, func_02012114 returns 1
 * and the overlay call returns 1 as well.  That last call's argument is
 * func_0201210C(p)'s result - r0 is not reloaded in between, which is what
 * the source's nesting says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201205C.c \
 *       --func func_0201205C --addr 0x0201205C --cc 1.1p1 --thumb
 */
void func_0201205C(struct GameSystem *gameSystem)
{
    if (func_020120D8(gameSystem) == 0) {
        if (func_02012114(gameSystem) == 1) {
            if (func_02188BE8(func_0201210C(gameSystem)) == 1)
                func_020121CC(gameSystem);
        }
    }
}


/*
 * The tail of the packet's small table walkers: two loads off the
 * _GPowerState tables and one store, 18 bytes, every relocation a label outside
 * the range.  It re-verified EXACT after func_02010F50 and func_02010EEC were
 * filed in pkt_02010EEC (the same two tables), so the entry is a chain payoff.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012088.c \
 *       --func func_02012088 --addr 0x02012088 --cc 1.1p1 --thumb
 */
void func_02012088(struct GameSystem *gameSystem)
{
    func_0203133C(gameSystem->procSys);
    func_02011F90(gameSystem);
}




/*
 * The word pair setter that follows func_02012088's epilogue at 0x0201209A:
 * two words at +0x10 and +0x14, no prologue, no label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201209C.c \
 *       --func sub_0201209C --addr 0x0201209C --cc 1.1p1 --thumb
 */
void sub_0201209C(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg)
{
    gameSystem->eventCreator = creator;
    gameSystem->eventCreatorArg = arg;
}


void func_020120A4(struct GameSystem *gameSystem)
{
    gameSystem->eventActive = (u8)func_020123C4(gameSystem);
}



/*
 * ica_anime.c.  Forwards the +0x08 handle and the caller's other three
 * arguments to the ARM routine at 0x02031348.  The frame
 * (push {r3,lr} / blx / pop {r3,pc}) where every one-argument spelling gets
 * a pool-word-and-bx sibling call (26 spellings in
 * docs/notes/pkt_020120B4.c.txt) is the tail-call-cannot-pass-a-fourth-
 * argument idiom: r1-r3 are passed through untouched, so they cost no
 * instruction, and r3 being live blocks the sibling call.  The arity is
 * independently evidenced by the only caller, func_020120C0, which sets up
 * r1, r2 and r3 (r3 = r0) before the bl.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020120B4.c \
 *       --func func_020120B4 --addr 0x020120B4 --cc 1.1p1 --thumb
 */
void func_020120B4(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param)
{
    func_02031348(gameSystem->procSys, overlayId, procData, param);
}



/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           ov021_id (21) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 * evidence: FieldMapProcData lies in the windows of ov021 (data) and ov114 (bss),
 *           so the ov021 hint needs outside support.  The same call passes
 *           ov021_id (0x15, attested `overlay_id`) and this pointer to the
 *           proc system: func_020120B4 -> func_02031348 -> func_020314F4 ->
 *           func_02031538 stores the id at Proc+4 and the pointer at Proc+0
 *           (ProcData), and func_020315F0 loads overlay Proc+4
 *           (func_02034AC4) before it calls any ProcData callback.  So ov021
 *           is resident whenever the pointer is dereferenced.  Independently,
 *           ov021's bytes at 0x021D359C are three Thumb pointers
 *           0x02187F01/0x02187FD1/0x02187FE9, each a func_ label in
 *           ov021's own listing (init/main/end), while ov114 holds bss there.
 *           With the hint the site attests as `data_table` from ov021's bytes.
 *
 * Four arguments, and the first is the same object twice: the pool words are
 * a small constant 0x15 (an absolute linker symbol, not a literal - see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md, 21 is
 * an overlay id) and the overlay-space address 0x021D359C.  func_020120B4
 * itself only reads r0, which is why its ten-byte body says nothing about
 * this call's arity.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020120C0.c \
 *       --func func_020120C0 --addr 0x020120C0 --cc 1.1p1 --thumb
 */
void func_020120C0(struct GameSystem *gameSystem)
{
    func_020120B4(gameSystem, (u32)ov021_id, &FieldMapProcData, gameSystem);
}


int func_020120D8(struct GameSystem *gameSystem)
{
    if (func_020123C4(gameSystem))
        return 1;
    return gameSystem->eventActive;
}



/*
 *           func_02012108, func_0201210C, func_02012110, func_02012114,
 *           func_02012124, func_0201212C, func_02012134, func_02012138,
 *           func_0201213C, func_02012144, func_0201214C
 *
 * 104 bytes, 0x020120F0..0x02012158, 15 functions, none of which carries a
 * label: every one of them is a two- or three-instruction accessor on a
 * 0x34-byte context record, and the whole run arrives in the listing as .word
 * data between two literal pools.
 *
 * The size of the record is not a guess: func_02011F24 is
 * `movs r0, #0x34; bx lr`, its sizeof getter, and it is matched in
 * src/matched/unit_02011F24.c against the same declaration.  The two byte
 * fields at +0x30 and +0x32 cost an `adds r0, #0x30` each because the Thumb
 * `strb` immediate only reaches +31, which is
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md and not a pointer in the
 * source.
 *
 * func_020120F8 and func_0201214C are tail calls through pool words: the
 * first hands +0x1C to func_020127A4 and the second to func_02012BB0, and
 * both are ABS32 against a Thumb target, so the pool word is odd.
 *
 * 0x02012158, 12 bytes, is a third tail call of the same shape and is a near
 * miss.  Its pool word holds 0x02012BC9, and func_02012BC8 has no label in the
 * listing (it has no register-saving prologue) and no other reference anywhere
 * in the image, so neither the `label` nor the `literal` class has a witness
 * outside the twelve bytes under test.  Every concrete byte reproduces from
 *
 *     void func_02012158(struct GameSystem *gameSystem, unsigned int on)
 *     {
 *         func_02012BC8(gameSystem->gameData, on);
 *     }
 *
 * that closes 0x02012BC8 itself; see src/matched/unit_02012AE4.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020120F0.c \
 *       --addr 0x020120F0 --thumb
 */
u32 func_020120F0(const struct GameSystem *gameSystem)
{
    return gameSystem->procStatus;
}


struct GameData *func_020120F4(const struct GameSystem *gameSystem)
{
    return gameSystem->gameData;
}


struct PlayerWork *func_020120F8(const struct GameSystem *gameSystem)
{
    return func_020127A4(gameSystem->gameData);
}


struct GameEvent *func_02012104(const struct GameSystem *gameSystem)
{
    return gameSystem->event;
}


void func_02012108(struct GameSystem *gameSystem, struct GameEvent *event)
{
    gameSystem->event = event;
}


void *func_0201210C(const struct GameSystem *gameSystem)
{
    return gameSystem->fieldMap;
}


void func_02012110(struct GameSystem *gameSystem, void *fieldMap)
{
    gameSystem->fieldMap = fieldMap;
}


u32 func_02012114(const struct GameSystem *gameSystem)
{
    if (gameSystem->fieldMap != 0) {
        return 1;
    }
    return 0;
}


void func_02012124(struct GameSystem *gameSystem, u32 state)
{
    gameSystem->fieldMapState = state;
}


u8 func_0201212C(const struct GameSystem *gameSystem)
{
    return gameSystem->fieldMapState;
}


void *func_02012134(const struct GameSystem *gameSystem)
{
    return gameSystem->issSystem;
}


struct GameComm *func_02012138(const struct GameSystem *gameSystem)
{
    return gameSystem->gameComm;
}


void func_0201213C(struct GameSystem *gameSystem, u32 blocked)
{
    gameSystem->commBlocked = blocked;
}


u8 func_02012144(const struct GameSystem *gameSystem)
{
    return gameSystem->commBlocked;
}


u32 func_0201214C(const struct GameSystem *gameSystem)
{
    return func_02012BB0(gameSystem->gameData);
}


void func_02012158(struct GameSystem *gameSystem, unsigned int on)
{
    func_02012BC8(gameSystem->gameData, on);
}


/*
 *           listing but its only caller in the whole image is the bl at
 *           +0x38 inside this range, so `label` has no outside witness and
 *           sole-ref/code does not consider overlay starts.  Every concrete
 *           byte is right (MATCH*: the extent runs over the 2-byte pad).
 *
 * The note's 4-byte r0/r1 "tie" (docs/notes/pkt_02012164.c.txt) was a
 * misread arity: func_02012AC8 is `ldrh r0, [r0]; bx lr`, a getter taking
 * the pointer func_020120F8 returns, and func_02013D34 takes that u16 in
 * r0 -- so the image keeps it in r0 across the p->f32 test and reads the
 * byte through r1.  `id = func_02012AC8(func_020120F8(p))` then
 * `func_02013D34(id)` closes it.
 */
u32 func_02012164(struct GameSystem *gameSystem)
{
    u16 zoneId;

    func_02012138(gameSystem);
    zoneId = func_02012AC8(func_020120F8(gameSystem));
    if (gameSystem->commBlocked == 0
     && func_02013D34(zoneId) == 0
     && func_0200FB24() == 0
     && func_0201214C(gameSystem) == 1
     && func_02158318(gameSystem) == 1
     && !(func_02035390() == 1 && func_020353B0() == 1)) {
        if (func_020090E0(func_0200921C(gameSystem->gameData)) != 0) {
            return 1;
        }
    }
    return 0;
}



/*
 * Three tests, one epilogue: the handle returned by func_02012138(p) is
 * checked with two externals (both called with it - r0 is not reloaded), then
 * the object is driven through func_02012164 and only a result of exactly 1
 * reaches func_020263D8(handle, 1, p).  The nested ifs are what give all
 * three the same `return 0` at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020121CC.c \
 *       --func func_020121CC --addr 0x020121CC --cc 1.1p1 --thumb
 */
u32 func_020121CC(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm = func_02012138(gameSystem);

    if (func_0203CD98() == 0) {
        if (func_02026454(gameComm) == 0) {
            if (func_02012164(gameSystem) == 1) {
                func_020263D8(gameComm, 1, gameSystem);
                return 1;
            }
        }
    }
    return 0;
}



/*
 * The getter and the clearer of bit 0 of the byte at +0x33 of the same
 * 0x34-byte context record src/matched/unit_020120F0.c describes.  The
 * `lsls #0x1f` / `lsrs #0x1f` pair is a one bit field, not a cast: 32 - 31 is
 * not an integer width, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md, and the
 * clearer's `movs r1, #1` / `bics` is what `p->unk33_0 = 0;` compiles to
 * because Thumb has no immediate bic.  Neither function has a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012204.c  *       --addr 0x02012204 --thumb
 */
u32 func_02012204(const struct GameSystem *gameSystem)
{
    return gameSystem->netOffBySleep;
}


void func_02012210(struct GameSystem *gameSystem)
{
    gameSystem->netOffBySleep = 0;
}



/*
 * ica_anime.c: when func_0201214C(p) says yes, stop the playback
 * (func_02012158(p, 0), which is the tail call in the pending file
 * src/pending/func_02012158.c) and set bit 0 of the byte at +0x33.
 *
 * The bit update is one expression, `(f & ~1) | 1`: the original loads the
 * byte once, clears with `bics` and sets with `orrs` - two statements would
 * be two loads and two stores (see
 * docs/idioms/an-and-not-is-what-emits-bic.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012220.c \
 *       --func func_02012220 --addr 0x02012220 --cc 1.1p1 --thumb
 */
void func_02012220(struct GameSystem *gameSystem)
{
    if (func_0201214C(gameSystem) != 0) {
        func_02012158(gameSystem, 0);
        gameSystem->netOffBySleep = 1;
    }
}



/*
 * Promoted from src/pending/func_02012248.c.  The C never changed; the ISA
 * on the second symbols line did.  The tail call goes through the pool word
 * 0x02035138, i.e. an ARM target with no Thumb bit - the parked copy
 * declared it `thumb`, so the word match.py looked for was 0x02035139 and
 * the second pool holding 0x02035138 (at 0x02012260, in the next function,
 * outside this range) could not be seen.  Declared `arm`, the `literal`
 * class resolves the site and the entry is EXACT.  A `bx r3` tail call
 * always has a pool word, and the pool word's low bit is the only place the
 * callee's ISA shows up - a wrong declaration hides the witness silently.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012248.c \
 *       --func func_02012248 --addr 0x02012248 --cc 1.1p1 --thumb
 */
void func_02012248(struct GameSystem *gameSystem)
{
    func_02035138(func_02012220, gameSystem);
}


void func_02012258(struct GameSystem *gameSystem)
{
    func_02035138(0, 0);
}



int func_02012264(struct GameSystem *gameSystem)
{
    if (func_02026454(func_02012138(gameSystem)) != 0) {
        return 1;
    }
    if (func_0203DA4C() != 0) {
        return 1;
    }
    if (func_020353B0() != 0) {
        return 0;
    }
    if (func_0201214C(gameSystem) != 0) {
        return 1;
    }
    return 0;
}



/*
 * Two instructions and a two word pool: the first argument is the address of
 * func_02012264 tagged as a Thumb function pointer (the pool word is 0x02012265,
 * odd), the second is the caller's own argument, and the tail call is
 * `func_02035064(fn, arg)` with func_02035064 an ARM function.  Declaring the
 * pointer as `func_02012264` rather than writing the literal 0x02012265 is what
 * gets the odd word out of the compiler; func_02012264's own manifest entry is
 * what attests it (`matched x1`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020122A4.c \
 *       --func func_020122A4 --addr 0x020122A4 --cc 1.1p1 --thumb
 */
void func_020122A4(struct GameSystem *gameSystem)
{
    func_02035064(func_02012264, gameSystem);
}


void func_020122B4(struct GameSystem *gameSystem)
{
    func_02035064(0, 0);
}



/*
 * Constructor for a five-word descriptor: allocate the 0x14-byte header off
 * heap 4, fill it with the caller's two handles and a zeroed counter,
 * allocate the caller-sized payload off the same heap and hang it at +0xc,
 * and record the owner at +0x10.
 *
 * Both allocations go through func_02030734, whose last two arguments are
 * the file/line debug site pair (see src/matched/func_02030734.c).  The file
 * pointer is one pool word loaded twice, so it is a single ABS32 into the
 * packed string area and has to be declared as an extern pinned by address
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), never as a
 * literal __FILE__.  The two line numbers, 55 and 59, are four apart but
 * each is its own `movs`: they are not consecutive arguments of one call,
 * so the add-chain form does not apply
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The owner pointer and the payload size arrive in r0 and r3 and are both
 * live across the first call, so r5 takes the owner and the size is spilled
 * to [sp,#4] rather than costing a sixth callee-saved register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020122C0.c \
 *       --func sub_020122C0 --addr 0x020122C0 --cc 1.1p1 --thumb
 */
struct GameEvent *sub_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize)
{
    struct GameEvent *event;

    event = func_02030734(4, sizeof(struct GameEvent), 1, _GameEventFileName, 55);
    event->parent = parent;
    event->func = func;
    event->seq = 0;
    event->work = func_02030734(4, workSize, 1, _GameEventFileName, 59);
    event->gameSystem = gameSystem;
    return event;
}



/*
 * Virtual call: the target is the object's own word at +4, the first argument is
 * the object, the second is the object + 8, the third is the object's word at
 * +0xc.  The call is a register `blx r3`, so there is no relocation to attest
 * and the file is EXACT up to the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012304.c \
 *       --func func_02012304 --addr 0x02012304 --cc 1.1p1 --thumb
 */
int func_02012304(struct GameEvent *event)
{
    return event->func(event, &event->seq, event->work);
}


void func_02012314(struct GameEvent *event)
{
    void *work = event->work;
    if (work) func_020307B0(work);
    func_020307B0(event);
}


void func_0201232C(struct GameEvent *event, GameEventFunc func, u32 workSize)
{
    void *work;
    event->seq = 0;
    work = event->work;
    event->func = func;
    if (work)
        func_020307B0(work);
    event->work = func_02030734(4, workSize, 1, _GameEventFileName, 0x60);
}



/*
 * Reads the object's +0x10 word into a register first, then copies its +0 word
 * out through the caller's pointer and hands that same value to
 * func_02012314, then passes the +0x10 word and the pointer to func_02012108.
 * Order matters: the +0x10 load is hoisted above the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201235C.c \
 *       --func func_0201235C --addr 0x0201235C --cc 1.1p1 --thumb
 */
void func_0201235C(struct GameEvent *now, struct GameEvent *next)
{
    struct GameSystem *gameSystem = now->gameSystem;
    struct GameEvent *parent = now->parent;

    next->parent = parent;
    func_02012314(now);
    func_02012108(gameSystem, next);
}



/*
 * Publish the object through the caller's out parameter and tail-call the
 * setter on its +0x10 member, which stores `out` (still in r1) as that
 * context's current event at +0x18.  Eight bytes of code and the pool word the
 * tail call needs (docs/idioms/tail-call-is-a-pool-word-and-bx.md); the
 * pool word carries the Thumb bit, so the target is Thumb code and the
 * transfer is a plain `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012374.c \
 *       --func func_02012374 --addr 0x02012374 --cc 1.1p1 --thumb
 */
void func_02012374(struct GameEvent *parent, struct GameEvent *child)
{
    child->parent = parent;
    func_02012108(parent->gameSystem, child);
}



/*
 * game_event.c: run the event queue until it drains, stalls or finishes.
 * The dangling `cmp r0, #0x21` followed by an unconditional branch back to
 * the loop head is a SWITCH whose case 0x21 lands where the default does:
 * the compare chain keeps the compare and drops the branch.  An if chain
 * (docs/notes/pkt_02012380.c.txt, 38 out) never emits it.
 */
int func_02012380(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    struct GameEvent *parent;

    for (;;) {
        event = func_02012104(gameSystem);
        if (event == 0)
            return 0;
        switch (func_02012304(event)) {
        case 0:
            return 0;
        case 1:
            parent = sub_020124F0(event);
            func_02012314(event);
            func_02012108(gameSystem, parent);
            if (parent == 0)
                return 1;
            break;
        case 0x21:
            break;
        }
    }
}



int func_020123C4(struct GameSystem *gameSystem)
{
    if (func_02012104(gameSystem) != 0) {
        return 1;
    }
    return 0;
}



/*
 * The packet's driver: reject when func_02012104 says the object is busy,
 * reject a null callback, run the callback with the object and the second
 * argument, reject a zero result, hand a non-zero result to func_02012108 and
 * report 1.
 *
 * The two spellings differ by four bytes of layout.  Written with the
 * "invert the guard" shape
 *
 *     if (func_02012104(o) != 0) return 0;
 *     if (fn == 0) return 0;
 *     r = fn(o, a2);
 *     if (r != 0) { func_02012108(o, r); return 1; }
 *     return 0;
 *
 * mwccarm lays the two `movs r0, #0; pop` arms inline and falls through into
 * the success arm, which is what the original does.  Swapping the last pair to
 * `if (r == 0) return 0; else { ... return 1; }` makes it test `bne` and move
 * the success arm out of line (+0x24 onward), and a `goto fail` spelling
 * reproduces only 44 of the 52 bytes: the goto drops the `adds r1, r0, #0`
 * copy that keeps the callback result live for func_02012108 and reorders the
 * callback call.  The reachable spelling is the plain one.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020123D8.c \
 *       --func func_020123D8 --addr 0x020123D8 --cc 1.1p1 --thumb
 */
int func_020123D8(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg)
{
    struct GameEvent *event;

    if (func_02012104(gameSystem) != 0)
        return 0;
    if (creator == 0)
        return 0;
    event = creator(gameSystem, arg);
    if (event != 0) {
        func_02012108(gameSystem, event);
        return 1;
    }
    return 0;
}



/*
 * A three-state driver.  sub_020124E4's result is bound before the switch and
 * is still live in r0 at the case-0 call, which is why the two loads of the
 * state go to r1 (not r0) and the callee's argument registers are r1, r2, r3
 * with r0 carrying the earlier call's result.  Both arms leave through the
 * shared `return 0` tail, so neither may be written as a `return`: writing
 * `return 0` in case 0 makes mwccarm duplicate `movs r0, #0` inline instead of
 * branching to +0x34, and the function comes out six bytes long with the last
 * two arms shifted.  `!= 0` / `== 0` in case 1 makes no difference.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201240C.c \
 *       --func func_0201240C --addr 0x0201240C --cc 1.1p1 --thumb
 */
int func_0201240C(struct GameEvent *event, u32 *seq, void *work)
{
    struct ProcCallWork *call = work;
    struct GameSystem *gameSystem = sub_020124E4(event);

    switch (*seq) {
    case 0:
        func_020120B4(gameSystem, call->overlayId, call->procData, call->param);
        *seq = *seq + 1;
        break;
    case 1:
        if (func_020120F0(gameSystem) == 0)
            return 1;
        break;
    }
    return 0;
}



/*
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * sat at MATCH on the pool word at +0x2C, which holds 0x0201240D - the state
 * machine at 0x0201240C with its Thumb bit, handed to sub_020122C0 as a
 * callback.  That word is the only one in the image naming 0x0201240D, and no
 * branch reaches 0x0201240C from outside this range either, so the site needed
 * 0x0201240C to be an EXACT entry of its own; now that it is, the site
 * resolves through the `matched` class and this file needs no change.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012444.c \
 *       --func func_02012444 --addr 0x02012444 --cc 1.1p1 --thumb
 */
void func_02012444(struct GameEvent *parent, u32 overlayId, void *procData, void *param)
{
    struct GameEvent *event;
    struct ProcCallWork *call;

    event = sub_020122C0(parent->gameSystem, 0, func_0201240C, sizeof(struct ProcCallWork));
    call = sub_020124E8(event);
    call->overlayId = overlayId;
    call->procData = procData;
    call->param = param;
    func_02012374(parent, event);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012474.c \
 *       --func func_02012474 --addr 0x02012474 --cc 1.1p1 --thumb
 */
int func_02012474(struct GameEvent *event, u32 *seq, void *work)
{
    struct OverlayEventWork *overlay = work;

    sub_020124E4(event);
    switch (*seq) {
    case 0:
        func_02012374(event, overlay->event);
        (*seq)++;
        break;
    case 1:
        func_02034A5C((int)overlay->overlayId);
        return 1;
    }
    return 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020124AC.c \
 *       --func func_020124AC --addr 0x020124AC --cc 1.1p1 --thumb
 */
struct GameEvent *func_020124AC(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg)
{
    struct GameEvent *event;
    struct OverlayEventWork *overlay;

    event = sub_020122C0(gameSystem, 0, func_02012474, sizeof(struct OverlayEventWork));
    overlay = sub_020124E8(event);
    overlay->overlayId = overlayId;
    func_02034AC4(overlayId);
    overlay->event = creator(gameSystem, arg);
    return event;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Four two-byte leaf accessors in a row on the same object.  None of them
 * saves lr, so disasm.py labels none of them and the whole run prints as a
 * `.byte` blob between two pools; they are only reachable by sweeping
 * addresses.  sub_020124EC returns the address of the embedded sub-object
 * at +8 rather than a stored pointer.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020124E4.c \
 *       --addr 0x020124E4 --thumb
 */
struct GameSystem *sub_020124E4(struct GameEvent *event)
{
    return event->gameSystem;
}


void *sub_020124E8(struct GameEvent *event)
{
    return event->work;
}


u32 *sub_020124EC(struct GameEvent *event)
{
    return &event->seq;
}


struct GameEvent *sub_020124F0(struct GameEvent *event)
{
    return event->parent;
}



/*
 *           have exactly ONE branch anywhere in the image and it is the `bl`
 *           inside this function (0x020125AA, 0x020125E0, 0x02012698,
 *           0x020126DC), so the `label` class has no outside witness.  Two
 *           overlays (ov009, ov010) hold each address, so even with the
 *           `ov010` region hint on the symbols: line the witness condition
 *           still fails.  `sole-ref/code` cannot carry them either: it reads
 *           `evidence().labels`, which is the ARM9 listing only, so an
 *           overlay-resident function start is outside its index.
 *           `tu --suggest-split` confirms no cut helps ("best partition:
 *           0 piece(s), 1 function(s) left out") -- the only witnesses are
 *           the calls that need them.  Same wall as src/pending/func_02012704.c
 *           (the matching destructor), which is blocked on five siblings of
 *           these same overlay addresses.
 *           Every one of the 528 concrete bytes is correct; only the four
 *           relocation FIELDS stay wildcarded.
 * The constructor of the big game_data object destroyed by func_02012704.
 * 0x6B0 bytes from func_02030734(heap, 0x6B0, 1, "game_data.c", 0xAD); the
 * field offsets are the destructor's, read through a u8 * so the compiler
 * derives them all from the two pooled/scaled bases 0x1C4 (= 0x71 << 2),
 * 0x158 (= 0x56 << 2) and 0x6AC.
 *
 * THE TWO LEVERS (both found this wave; 528 bytes size-exact on the first
 * write, then 176 concrete-byte mismatches down to 0 in two changes):
 *
 * 1. THE HEAP PARAMETER IS `u16`, NOT `int`.  With `int` the seven prologue
 *    instructions are the right seven in the wrong order: mwcc emits the
 *    `str r0, [sp, #4]` spill LAST, after `movs r1,#0xad / str r1,[sp] /
 *    movs r1,#0x6b / ldr r3,pool / lsls r1,r1,#4 / movs r2,#1`, while the
 *    original emits it FIRST.  A `u16` parameter has a narrowed stack home
 *    the marshaller must establish before it builds the other arguments,
 *    which is exactly the original's order.  No spelling of the body moves
 *    it: `int heap = a0;` as the first local, as the last local, hoisting
 *    0x6B0 into a named `size`, and 300 single mutations of the permuter in
 *    --mode hill ("no single mutation improves") all leave the same seven.
 *    The permuter's --mode anneal found it as `type:p(a0:int->u16)` in 286
 *    compiles; the sibling caller src/matched/func_020082EC.c independently
 *    corroborates it, passing `(unsigned short)a0` to the same allocator.
 *
 * 2. THE memcpy ARGUMENTS ARE EVALUATED THROUGH TWO NAMED LOCALS, in the
 *    original's order: `n = func_02008468(); src = func_02012944(p);` and
 *    only then `memcpy(func_02008730(*(u32 *)p), src, n)`.  Written as one
 *    nested expression mwcc schedules func_02008730 first and the whole
 *    tail of the function reallocates: that alone was 169 of the 176
 *    mismatches.  (docs/idioms/an-inline-call-argument-is-scheduled-per-site-
 *    a-local-is-not.md)
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_020124F4.c \
 *       --func func_020124F4 --addr 0x020124F4 --cc 1.1p1 --thumb
 */
struct GameData *func_020124F4(u16 heapId)
{
    struct GameData *gameData;
    int i;
    u32 statusSize;
    struct PlayerStatus *status;
    void *eventData;

    gameData = func_02030734(heapId, sizeof(struct GameData), 1, _GameDataFileName, 0xAD);
    gameData->saveControl = func_020070A4();
    gameData->season = func_0202E888();
    gameData->subscreenType = 0;

    gameData->situation = (u32)func_02008854(gameData->saveControl);
    gameData->startLocation = func_02008844(gameData->situation);
    gameData->entranceLocation = func_02008844(gameData->situation);
    gameData->specialLocation = func_02008848((struct Situation *)gameData->situation);
    gameData->escapeLocation = func_0200884C((struct Situation *)gameData->situation);

    gameData->bagCursor = (u32)func_02006E40(heapId);

    for (i = 0; i < 5; i++) {
        func_02012A60(&gameData->playerWork[i]);
    }

    statusSize = func_02008468();
    status = func_02012944(gameData);
    memcpy(func_02008730(gameData->saveControl), status, statusSize);

    gameData->eventData = eventData = (void *)func_0216237C(heapId);
    func_021623DC(eventData);
    gameData->eventWork = func_02012FE4(gameData->saveControl);
    gameData->fieldWork = (u32)func_02159B48(heapId);
    gameData->occupyInfo = func_0216CC58(heapId, 0x40, (u32)func_020071CC(gameData->saveControl, 0x33));
    gameData->bgmInfo = (u32)func_02028844(gameData, heapId);
    gameData->moveModelSys = (void *)func_02014428(heapId);
    gameData->mapMatrix = (u32)func_02008254(heapId);
    gameData->myItem = func_020071CC(gameData->saveControl, 0x19);
    gameData->myParty = func_020071CC(gameData->saveControl, 0x1A);
    gameData->config = func_0200873C(gameData->saveControl);
    gameData->boxManager = (u32)func_02007AA4(heapId, (u32)gameData->saveControl);
    gameData->wifiList = (u32)func_020097C4(heapId);

    for (i = 0; i < 4; i++) {
        func_0200BDE4(gameData->battleRecSlot[i]);
    }

    for (i = 0; i < 2; i++) {
        func_02161D98(gameData->unionInfo[i]);
    }

    gameData->playTime = func_0200857C(heapId);
    gameData->saveStatus = 0;
    func_020071E4(gameData->saveControl);

    gameData->fieldGimmick = (u32)func_0215E31C(heapId);
    func_0202E43C(gameData->rtcWork);
    func_02012C18(gameData);
    gameData->eventState = 0;
    gameData->currentEvent = 0;
    gameData->pmsWork = (int)func_0202E770((void *)heapId);
    gameData->itemUseWork = func_0202751C(heapId, 0x8001);
    gameData->musicalWork = (u32)func_021647A0(gameData, heapId);
    gameData->listCursor = 0;
    gameData->externalWork = 0;

    return gameData;
}



/*
 * note:     wave 16: promoted.  0x0215E334 and 0x02159BBC are unlabelled ov010
 *           ENV_SetResourceSet thunks matched in src/matched/func_0215E334.c and
 *           func_02159BBC.c (`matched, overlay`); 0x021647D8, 0x0216CCB0 and
 *           0x021623BC resolve as sole-ref/code (overlay).
 * A destructor: fifteen pointer fields of one big object handed to fifteen
 * different release functions, then the object itself to the base deleter
 * 0x020307B0 (the ARM `blx` target, called three times).
 *
 * The literal 0x6AC is pooled once and every other offset is derived from it
 * with `adds`/`subs` (0x690, 0x68C, 0x684, 0x5E4), which is why the second
 * group starts from 0x69 << 2: the offsets are the source's array indices
 * scaled by four, and the field reads are `p[0x1AB]`, `p[0x1A4]`, ... in a
 * `u32 *`.  Writing the fields as byte offsets through a `u8 *` reproduces
 * the same derived-constant chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012704.c \
 *       --func func_02012704 --addr 0x02012704 --cc 1.1p1 --thumb
 */
void func_02012704(struct GameData *gameData)
{
    func_020307B0(gameData->playTime);
    func_021647D8(gameData->musicalWork);
    func_02027584(gameData->itemUseWork);
    func_0202E794((void *)gameData->pmsWork);
    func_0215E334((void *)gameData->fieldGimmick);
    func_02006E64((struct BagCursor *)gameData->bagCursor);
    func_020307B0((void *)gameData->wifiList);
    func_02007AC8((void *)gameData->boxManager);
    func_020307B0((void *)gameData->mapMatrix);
    func_0216CCB0((int)gameData->occupyInfo);
    func_02159BBC((void *)gameData->fieldWork);
    func_021623BC((int)gameData->eventData);
    func_02014444((u32)gameData->moveModelSys);
    func_0202889C((struct BgmInfo *)gameData->bgmInfo);
    func_020307B0(gameData);
}



struct PlayerWork *func_02012798(struct GameData *gameData, int index)
{
    return &gameData->playerWork[index];
}



/*
 * Two address-of-member accessors on the same save-data block, neither of
 * which saves lr, so neither carries a label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) and the pair
 * has to be worked as one unit.
 *
 * Both offsets are out of Thumb immediate range and are built as
 * `movs #n / lsls #2`, which is why 0x114 appears as 0x45 and 0x1d4 as 0x75.
 * The second takes an index into a 16-byte array that starts at +0x1d4.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020127A4.c \
 *       --addr 0x020127A4 --thumb
 */
struct PlayerWork *func_020127A4(struct GameData *gameData)
{
    return &gameData->playerWork[4];
}


void *func_020127AC(struct GameData *gameData, u32 index)
{
    return gameData->battleRecSlot[index];
}



/*
 * Promoted from src/pending/func_020127B8.c (was MATCH, blocker 0x020127AC,
 * declared by the naming convention, which defaults to ARM).  The pool word
 * is 0x020127AD, so the target is Thumb; declared `thumb` the `matched`
 * class fires on the EXACT unit entry for 0x020127AC
 * (src/matched/unit_020127A4.c, which names it as a member function) and
 * the site resolves with no change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020127B8.c \
 *       --func func_020127B8 --addr 0x020127B8 --cc 1.1p1 --thumb
 */
void *func_020127B8(struct GameData *gameData)
{
    return func_020127AC(gameData, 3);
}



/*
 * Promoted from src/pending/func_020127C4.c (was MATCH, blocker 0x020127D0,
 * declared by the naming convention, i.e. ARM).  Two things had to happen:
 * the pool word is 0x020127D1 so the target is Thumb, and
 * src/matched/sub_020127D0.c has to exist as an EXACT entry for the
 * `matched` class to reach it - both done, and the C never changed.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020127C4.c \
 *       --func func_020127C4 --addr 0x020127C4 --cc 1.1p1 --thumb
 */
u8 *func_020127C4(struct GameData *gameData)
{
    return sub_020127D0(gameData, 1);
}




/*
 * Address-of-element on a 0x1E8-byte record array at +0x214: the pair of
 * constants 0x214 and 0x1E8 differ by 0x2c, so the compiler materialises the
 * larger one from a pool-free `movs`/`lsls` pair and derives the stride with
 * a `subs` (see docs/idioms/a-constant-pair-...).  Entry attested by the
 * pool word 0x020127D1 that func_020127C4 loads.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020127D0.c \
 *       --func sub_020127D0 --addr 0x020127D0 --cc 1.1p1 --thumb
 */
u8 *sub_020127D0(struct GameData *gameData, u32 index)
{
    return gameData->unionInfo[index];
}



u16 *func_020127E0(struct GameData *gameData)
{
    return func_0200A890(func_0200A864(gameData->saveControl));
}



u8 *func_020127F0(struct GameData *gameData)
{
    return func_0200A898(func_0200A864(gameData->saveControl));
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012800.c \
 *       --func func_02012800 --addr 0x02012800 --cc 1.1p1 --thumb
 */
void func_02012800(struct GameData *gameData, void *dst)
{
    func_02082D44(dst, gameData->unionInfo[0], sizeof(gameData->unionInfo[0]));
    func_02161D64((int)gameData->unionInfo[0]);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201281C.c \
 *       --func func_0201281C --addr 0x0201281C --cc 1.1p1 --thumb
 */
void func_0201281C(struct GameData *gameData)
{
    MI_CpuFill8(gameData->unionInfo[0], 0, sizeof(gameData->unionInfo[0]));
    func_02161D64((int)gameData->unionInfo[1]);
}



/*
 *           func_02012870, func_02012878, func_02012894, func_0201289C,
 *           func_020128B8, func_020128C0, func_020128DC, func_020128E4,
 *           func_02012900
 *
 * 214 bytes, 0x0201283C..0x02012914, 13 functions, five of them labelled.  It
 * abuts src/matched/unit_02012924.c at the far end, across the one function
 * the cut below moved out.
 *
 * Four pointer fields at +0x160, +0x164, +0x168 and +0x16C and one inline
 * record at +0x170 all hold the same 28-byte thing, and each has a getter and
 * a setter.  28 bytes is three `ldm`/`stm` pairs plus a trailing `ldr`/`str`,
 * which is docs/idioms/aggregate-assignment-is-ldm-stm.md; the record has to
 * be declared four-aligned (struct Location, u32 words[7], not u8 [28]) or the copy becomes a
 * byte loop.  The four pointer setters write through the pointer
 * (`*gameData->startLocation = *location`) and the fifth writes the inline record
 * (`gameData->warpLocation = *location`), which is the difference between the `ldr r2, [r0, r1]`
 * and the `adds r2, r0, r1` that opens each.
 *
 * The file is cut at 0x02012914 rather than at 0x02012924, which is where the
 * next file starts, because func_02012900 and func_02012914 are the only two
 * callers of func_02008850 in the image: one range holding both leaves the
 * `label` class no witness and the whole unit reads MATCH with every concrete
 * byte right.  Split, each is the other's outside witness and both are EXACT.
 * That is docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, and
 * the other half is src/matched/unit_02012914.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201283C.c \
 *       --addr 0x0201283C --thumb
 */
u32 func_0201283C(const struct GameData *gameData)
{
    return gameData->wifiList;
}


void *func_02012844(const struct GameData *gameData)
{
    return gameData->eventData;
}


struct Location *func_0201284C(const struct GameData *gameData)
{
    return gameData->startLocation;
}


void func_02012854(struct GameData *gameData, const struct Location *location)
{
    *gameData->startLocation = *location;
}


struct Location *func_02012870(const struct GameData *gameData)
{
    return gameData->entranceLocation;
}


void func_02012878(struct GameData *gameData, const struct Location *location)
{
    *gameData->entranceLocation = *location;
}


struct Location *func_02012894(const struct GameData *gameData)
{
    return gameData->specialLocation;
}


void func_0201289C(struct GameData *gameData, const struct Location *location)
{
    *gameData->specialLocation = *location;
}


struct Location *func_020128B8(const struct GameData *gameData)
{
    return gameData->escapeLocation;
}


void func_020128C0(struct GameData *gameData, const struct Location *location)
{
    *gameData->escapeLocation = *location;
}


struct Location *func_020128DC(struct GameData *gameData)
{
    return &gameData->warpLocation;
}


void func_020128E4(struct GameData *gameData, const struct Location *location)
{
    gameData->warpLocation = *location;
}


void func_02012900(const struct GameData *gameData, u16 warpId)
{
    *func_02008850((struct Situation *)gameData->situation) = warpId;
}
