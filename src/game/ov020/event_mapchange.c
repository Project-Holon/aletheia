/*
 * file:     event_mapchange.c
 * unit:     yes
 * function: func_02183B60, func_02183B6C, func_02183B90, func_02183C34, func_02183C58, func_02183C9C, func_02183D68, func_02183DD4, func_02183DE4, func_02183F5C, func_0218403C, func_0218409C, func_02184120, func_021841C0, func_02184360, func_02184388, func_02184410, func_02184504, func_02184584, func_0218466C, func_02184730, func_021847CC, func_02184894, func_0218495C, func_02184A14, func_02184AB4, func_02184B54, func_02184BF8, func_02184C78, func_02184CEC, func_02184D38, func_02184D90, func_02184DE8, func_02184E40, func_02184E94, func_02184EEC, func_02184F40, func_02184F88, func_02184FD4, func_02185050, func_021850A8, func_021850FC, func_02185140, func_02185214, func_021852F0, func_02185360, func_02185410, func_02185458, func_021854B0, func_021854CC, func_02185534, func_02185588, func_0218562C, func_02185694, func_0218571C, func_02185758, func_02185788, func_021857C0, func_021858E4, func_02185928, func_021859F0, func_021859FC, func_02185A34, func_02185A68, func_02185B70, func_02185B88, func_02185B9C, func_02185BFC, func_02185C4C, func_02185C8C, func_02185D38, func_02185EB0, func_02185F18, func_02185F48, func_02185F6C, func_0218601C, func_0218604C, func_0218606C, func_0218608C
 * address:  0x02183B60
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0202E888  0x0202E888  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02187808  0x02187808  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_021860D4  0x021860D4  thumb  ov020
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02161F14  0x02161F14  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02158A10  0x02158A10  thumb  ov010
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 *   func_02014264  0x02014264  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_02008B20  0x02008B20  thumb
 *   func_02021444  0x02021444  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201445C  0x0201445C  thumb
 *   func_02012894  0x02012894  thumb
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_02164474  0x02164474  thumb  ov010
 *   func_0202C860  0x0202C860  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_0201AD0C  0x0201AD0C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B4C  0x02008B4C  thumb
 *   func_02008B78  0x02008B78  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C00  0x02008C00  thumb
 *   func_0216A390  0x0216A390  thumb  ov010
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0202E848  0x0202E848  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_020140B4  0x020140B4  thumb
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   ov230_id       0x000000E6  data
 *   func_02012138  0x02012138  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02013D34  0x02013D34  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188318  0x02188318  arm  ov230d
 *   func_021883CC  0x021883CC  arm  ov230d
 *   func_0202E8CC  0x0202E8CC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0216A358  0x0216A358  thumb  ov010
 *   func_02164454  0x02164454  thumb  ov010
 *   func_0216445C  0x0216445C  thumb  ov010
 *   func_02164464  0x02164464  thumb  ov010
 *   func_0215874C  0x0215874C  thumb  ov010
 *   func_02029C64  0x02029C64  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021BD648  0x021BD648  thumb  ov021
 *   func_021BD9BC  0x021BD9BC  thumb  ov021
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_021746AC  0x021746AC  thumb  ov011
 *   func_02158428  0x02158428  thumb  ov010
 *   func_02012A30  0x02012A30  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BF58C  0x021BF58C  thumb  ov021
 *   func_021BFD34  0x021BFD34  thumb  ov021
 *   func_021BF5B4  0x021BF5B4  thumb  ov021
 *   func_021BFD70  0x021BFD70  thumb  ov021
 *   func_021BF5E8  0x021BF5E8  thumb  ov021
 *   func_021BFDA0  0x021BFDA0  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_021BF61C  0x021BF61C  thumb  ov021
 *   func_021BFDD0  0x021BFDD0  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_021BF644  0x021BF644  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 *   func_02173744  0x02173744  thumb  ov012
 *   func_021BF66C  0x021BF66C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAAF0  0x021AAAF0  thumb  ov021
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_020141A8  0x020141A8  thumb
 *   func_020128B8  0x020128B8  thumb
 *   func_02012914  0x02012914  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02159F94  0x02159F94  thumb  ov010
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_020128E4  0x020128E4  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02176230  0x02176230  thumb  ov011
 *   func_020128DC  0x020128DC  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026484  0x02026484  thumb
 *   func_02012B78  0x02012B78  thumb
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02012870  0x02012870  thumb
 *   func_02013E7C  0x02013E7C  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02162694  0x02162694  thumb  ov010
 *   func_021625E8  0x021625E8  thumb  ov010
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02159FA8  0x02159FA8  thumb  ov010
 *   func_0216446C  0x0216446C  thumb  ov010
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C110  0x0202C110  thumb
 *   func_021625FC 0x021625FC thumb ov010
 *   func_02014454  0x02014454  thumb
 *   func_02012AC4  0x02012AC4  thumb
 *   func_02012ACC  0x02012ACC  thumb
 *   func_020141DC  0x020141DC  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0202B544  0x0202B544  thumb
 *   func_02012854  0x02012854  thumb
 *   func_02012900  0x02012900  thumb
 *   func_0202C83C  0x0202C83C  thumb
 *   func_02159FE0  0x02159FE0  thumb  ov010
 *   func_021643E8  0x021643E8  thumb  ov010
 *   func_0215A014  0x0215A014  thumb  ov010
 *   func_02158AE0  0x02158AE0  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 *   func_0201444C  0x0201444C  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02186538  0x02186538  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02186854  0x02186854  thumb  ov020
 *   func_021868B8  0x021868B8  thumb  ov020
 *   func_0216CF6C  0x0216CF6C  thumb
 *   func_02186470 0x02186470 thumb ov020
 *   func_021864DC 0x021864DC thumb ov020
 *   func_02013F6C 0x02013F6C thumb
 *   func_02014468 0x02014468 thumb
 *   func_0201446C 0x0201446C thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02014450  0x02014450  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013DF0  0x02013DF0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_020129AC  0x020129AC  thumb
 *   func_020129B8  0x020129B8  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02013B44  0x02013B44  thumb
 *   func_02162408  0x02162408  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B37C  0x0200B37C  thumb
 *   func_0200B394  0x0200B394  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_02049238  0x02049238  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021BE9F0  0x021BE9F0  thumb  ov021
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_02158630  0x02158630  thumb  ov010
 *   func_021D2750  0x021D2750  thumb  ov021
 *   func_0217574C  0x0217574C  thumb  ov011
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02175B4C  0x02175B4C  thumb  ov011
 *   func_02039338  0x02039338  arm
 *   func_0201284C  0x0201284C  thumb
 *   func_02014068  0x02014068  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_02013FEC 0x02013FEC thumb
 *   func_02012B28 0x02012B28 thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02008FA0  0x02008FA0  thumb
 *   func_02008FA8  0x02008FA8  thumb
 *   func_02008FB4  0x02008FB4  thumb
 *   func_02008FBC  0x02008FBC  thumb
 *   func_02008FD8  0x02008FD8  thumb
 *   func_02008FC4  0x02008FC4  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 *   func_02030734 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   _u32_div_f     0x0209C2B0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef signed int     s32;
typedef unsigned long long u64;

#include "event_mapchange_types.h"


struct GameSystem;
struct GameEvent;
struct GameData;
struct FieldMap;
struct GameComm;
struct EventWork;
struct SaveControl;
struct MiscSave;
struct AreaData;
struct FieldSoundSystem;
struct PlaceNameSys;
struct ConsoleInfo;
struct ConsoleInfoSession;

/* How the game starts (GameInitWork.mode). */
enum {
    GAMEINIT_MODE_FIRST = 0,    /* first start: season setup, opening, then the new game start */
    GAMEINIT_MODE_CONTINUE = 1, /* load a save */
    GAMEINIT_MODE_DEBUG = 2     /* straight to the new game start location */
};

/* Start request handed in by the boot code (also kept in the game system global). */
typedef struct GameInitWork {
    int mode;
    u32 position[3];
    u16 zoneId;
    u16 direction;
} GameInitWork;

/* Work of the first start event. */
typedef struct FirstStartWork {
    struct GameSystem *gameSystem;
    GameInitWork *initWork;
} FirstStartWork;

/* Work of the new game start event (0x24 bytes). */
typedef struct NewGameStartWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    Location startLocation;
} NewGameStartWork;

/* Work of the continue event (0x10 bytes). */
typedef struct ContinueWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u16 zoneId;
    u8 pad0A[2];
    int useSpecialLocation;     /* event flag 0x966 was set when the save was written */
} ContinueWork;

/* Work of the change field event: only points back at the map change work. */
typedef struct ChangeFieldWork {
    MapChangeWork *mapChange;
} ChangeFieldWork;

/* Opaque record of the arc 0x65 table (entry: zone id, save slot). */
typedef struct {
    int zoneId;
    u16 value;
    u16 unused06;
} ZoneTableEntry;

struct MsgData;
struct Strbuf;
struct Mail;


extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
extern int func_0202E888(void);
extern u8 func_0202E8CC(struct GameData *gameData, s32 season);
extern u8 func_02012984(struct GameData *gameData);
extern struct GameEvent *func_02187808(struct GameSystem *gameSystem, int fromSeason, int toSeason);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *func_02161B90(struct GameSystem *gameSystem, struct GameEvent *parent, int kind, int sub, int flag);
extern void func_0201235C(struct GameEvent *event, struct GameEvent *newEvent);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, void *callback, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
u16 *func_020127C4(GameData *gameData);
extern void *func_02012944(struct GameData *gameData);
extern void func_021860D4(void *unionInfo, void *myStatus, int flag);
extern int func_02161D64(void *unionInfo);
extern void *func_020127F0(struct GameData *gameData);
extern void func_02161F14(void *out, void *unionInfo, int flag);
extern struct EventWork *func_0201296C(struct GameData *gameData);
extern void func_02158A10(struct GameSystem *gameSystem, int scriptKind);
void func_02185A68(GameSystem *gameSystem, int zoneId);
void func_021857C0(GameSystem *gameSystem, Location *warpLocation);
extern unsigned int func_02029DF4(struct GameData *gameData, unsigned int zoneId, unsigned int season);
extern struct GameEvent *func_020298A0(struct GameSystem *gameSystem, u32 bgmId, u32 b, u32 frames);
extern struct GameEvent *func_020145FC(struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern struct GameEvent *func_021BE92C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int d, int e, u8 fromSeason, u8 toSeason);
extern struct PlaceNameSys *func_02188D20(struct FieldMap *fieldMap);
extern void func_021BC578(struct PlaceNameSys *placeName, int zoneId);
extern void func_02014264(Location *location);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct ConsoleInfo *func_02008B08(struct SaveControl *saveControl);
extern void func_02008B20(struct ConsoleInfo *consoleInfo);
extern void func_02021444(void);
void func_02185F6C(GameData *gameData);
extern FieldStatus *func_02012B38(GameData *gameData);
extern void func_0201445C(void *fieldStatus, u8 v);
extern Location *func_02012894(struct GameData *gameData);
void func_02185B70(GameSystem *gameSystem);
void func_0218601C(GameData *gameData);
extern void func_0202735C(u32 zoneId, struct GameData *gameData);
extern void func_02168EEC(struct GameData *gameData);
extern void func_02164474(struct GameData *gameData, int zoneId);
extern void func_0202C860(struct GameData *gameData, int zoneId);
extern u8 func_0201405C(u32 zoneId);
extern MmdlSys *func_02012964(GameData *gameData);
extern void func_0216E29C(MmdlSys *mmdlSys, int objCodeSet);
extern void func_0216CCCC(MmdlSys *mmdlSys);
extern u16 *func_020143CC(struct EventWork *eventWork, u32 workId);
extern int func_02158780(struct GameEvent *event, u16 scriptId, int c, int d, u16 e);
extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern void func_0201433C(struct EventWork *eventWork, int flagId);
extern void *func_0201AD0C(struct SaveControl *saveControl);
extern struct MiscSave *func_02012F08(struct GameData *gameData);
extern int func_02008B4C(struct ConsoleInfo *consoleInfo);
extern int func_02008B78(struct ConsoleInfo *consoleInfo);
extern struct ConsoleInfoSession *func_02008B14(struct SaveControl *saveControl);
extern void func_02008C00(struct ConsoleInfoSession *session);
extern void func_0216A390(struct GameData *gameData, void *party);
extern u64 func_0203F524();
extern void func_0200C384(struct MiscSave *miscSave, u32 lo, u32 hi);
extern void func_0216AAE4(struct GameData *gameData, void *party, int season);
extern int func_0202E848(struct GameData *gameData, u16 *outA, u16 *outB);
extern u32 func_02013B38(u32 zoneId);
u16 func_02188C84(FieldMap *fieldMap);
extern struct AreaData *func_0201407C(int heapId, int areaId, int c);
extern u8 func_020140D8(struct AreaData *areaData);
extern u32 func_020140B4(struct AreaData *areaData);
extern int func_021BE89C(int fromZone, u32 toZone);
extern int func_021BE8B8(int fromZone, int toZone);
extern u8 sub_0202E8A4(u8 a);
extern EventData *func_02012844(GameData *gameData);
extern void *func_021625CC(EventData *eventData, u16 exitId);
extern u8 func_021626E8(void *connectData);
extern struct GameComm *func_02012138(struct GameSystem *gameSystem);
extern u8 func_0201447C(FieldStatus *fieldStatus, u8 value);
extern struct GameEvent *func_02014554(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern int func_02034AC4(int id);
extern void func_02034A5C(int handle);
extern u32 func_02013D34(u32 zoneId);
extern u32 func_02026454(struct GameComm *gameComm);
extern void func_02026400(struct GameComm *gameComm);
void *func_0218604C(void);
void *func_0218606C(void);
void func_0218608C(void);
extern u32 func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188318(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_021883CC(void (*a)(void), void (*b)(void), u32 c);
extern void *func_02012934(struct GameData *gameData);
extern int func_0216A358(struct GameData *gameData, void *party, u32 *p, int season);
extern int func_02164454(struct GameData *gameData, int zoneId);
extern int func_0216445C(struct GameData *gameData, int zoneId);
extern int func_02164464(struct GameData *gameData, int zoneId);
extern void func_0215874C(struct GameComm *gameComm);
extern struct GameEvent *func_02029C64(struct GameSystem *gameSystem);
extern void *func_02188C7C(struct FieldMap *fieldMap);
extern void func_0216D9A0(void *mmdlSys);
extern struct GameEvent *func_021BD648(EntranceParam *param);
extern struct GameEvent *func_021BD9BC(EntranceParam *param);
extern IntrudeComm *func_02158344(GameComm *gameComm);
extern unsigned int *func_0216D9E4(void *mmdlSys);
extern int func_02013DD0(int zoneId);
extern u8 func_0215841C(struct GameData *gameData);
extern int func_021746AC(void *commHandle, int a);
extern u8 func_02158428(void *commHandle);
extern struct FieldSoundSystem *func_02012A30(struct GameData *gameData);
extern struct GameEvent *func_02161824(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void func_02029D44(struct FieldSoundSystem *fieldSound, struct GameData *gameData, u16 zoneId, u8 season);
extern void func_02029D7C(struct FieldSoundSystem *fieldSound, struct GameData *gameData);
extern struct GameEvent *func_021BE8D4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int d);
extern void func_021BC550(struct PlaceNameSys *placeName, int zoneId);
extern struct GameEvent *func_021BF58C(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *func_021BFD34(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, const VecFx32 *targetPos);
void func_02185F48(GameData *gameData);
extern struct GameEvent *func_021BF5B4(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int seasonChanged, int fromSeason, int toSeason);
extern struct GameEvent *func_021BFD70(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int seasonChanged);
extern struct GameEvent *func_021BF5E8(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 seasonChanged, u32 fromSeason, u32 toSeason);
extern struct GameEvent *func_021BFDA0(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int seasonChanged);
extern void *func_020127A4(struct GameData *gameData);
extern void func_02012B2C(void *playerWork, u32 objectCode);
extern struct GameEvent *func_021BF61C(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *func_021BFDD0(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int arg);
extern u32 func_02188D38(struct FieldMap *fieldMap);
extern int func_021C6E48(int a);
extern struct GameEvent *func_021BFE00(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *func_021BF644(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);

struct GameEvent *func_02183C34(struct GameSystem *gameSystem, GameInitWork *initWork);
struct GameEvent *func_02183F5C(struct GameSystem *gameSystem, GameInitWork *initWork);
extern struct GameEvent *func_02183D68();
struct GameEvent *func_02184360(MapChangeWork *work, int changeKind);
void func_02173744(GameSystem *gameSystem);
GameEvent *func_021BF66C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
u16 func_02188C9C(FieldMap *fieldMap);
u32 func_02188CE8(FieldMap *fieldMap);
void func_021AAAF0(int value, int flag);
u32 func_020142A4(u32 dir);
void func_02014184(Location *location, int zoneId, s16 dir, int x, int y, int z);
void func_020141A8(Location *location, int zoneId, int dir, u16 railIndex, u16 lineGrid, s16 widthGrid);
Location *func_020128B8(const GameData *gameData);
void func_02185F18(GameData *gameData, Location *out);
u16 func_02012914(const GameData *gameData);
u16 func_02159F94(int warpId);
void func_02014204(Location *location, int zoneId);
void *func_02012AA0(PlayerWork *playerWork);
u16 func_02012AC8(const PlayerWork *playerWork);
u32 func_02012AE4(const PlayerWork *playerWork);
void func_0201289C(GameData *gameData, const Location *location);
void func_020128E4(GameData *gameData, const Location *location);
u16 *func_0200BE48(void *saveControl);
void *func_02012FCC(GameData *gameData);
u64 func_0200BFA4(u16 *record, void *playTime, u32 mode);
u8 func_02012B58(const GameData *gameData);
int func_02158590(GameData *gameData);
u8 func_02176230(IntrudeComm *comm, u8 *requestInfo);
Location *func_020128DC(GameData *gameData);
u32 func_0202648C(GameComm *gameComm);
void func_02026484(GameComm *gameComm);
GameData *func_02012B78(GameData *gameData, u8 value);
void func_02012B64(GameData *gameData, int value);
void func_02012B8C(GameData *gameData, u32 value);
void func_02012B4C(GameData *gameData, u8 value);
void *func_02188CB4(FieldMap *fieldMap);
int func_021A3238(void *fieldPlayer);
void func_0217BCDC(u8 *a, void *b, int c, u8 d, u8 e);
u32 func_02188CFC(FieldMap *fieldMap);
void *func_021A3074(void *fieldPlayer);
void func_021A36BC(void *fieldPlayer, RailLocation *rail);
VecFx32 *func_0216D888(void *mmdl);
Location *func_02012870(const GameData *gameData);
u32 func_02013E7C(u32 zoneId);
void func_020128C0(GameData *gameData, const Location *location);
int func_021625E8(void *connectData);
int func_02162694(void *connectData, Location *location, int exitDir);
void func_02185EB0(GameData *gameData, const Location *destination);
extern u32 func_02013D5C(u32 zoneId);
void func_02159FA8(int warpId, Location *location);
int func_0216446C(GameData *gameData, int zoneId);
void *func_02012134(const GameSystem *gameSystem);
void *func_0202B578(void *issSystem);
void func_0202C110(void *issSwitchSys);
extern int func_021625FC(const EventData *eventData, Location *location, int exitId, int exitOffset);
void func_02014454(FieldStatus *fieldStatus, u8 value);
PlayerWork *func_02012AC4(PlayerWork *playerWork, u16 zoneId);
void func_02012ACC(PlayerWork *playerWork, int dir);
int func_020141DC(const Location *location);
void func_02012A90(PlayerWork *playerWork, const VecFx32 *pos);
void func_02012AA4(PlayerWork *playerWork, const RailLocation *rail);
void func_02012ABC(PlayerWork *playerWork, u8 isRail);
void func_0202B544(void *issSystem, u16 zoneId);
void func_02012854(GameData *gameData, const Location *location);
void func_02012900(const GameData *gameData, u16 warpId);
int func_0202C83C(int gameSystem, int zoneId);
int func_02159FE0(int zoneId);
void func_021643E8(GameData *gameData, u16 zoneId);
void func_0215A014(GameData *gameData, int zoneId);
void func_02158AE0(GameSystem *gameSystem, void *flags);
u16 func_02162744(EventData *eventData);
u32 func_02162740(EventData *eventData);
void func_0216CEAC(MmdlSys *mmdlSys, u8 *headers, u32 zoneId, u32 count, u32 eventWork);
u32 func_0201444C(FieldStatus *fieldStatus);
u16 *func_020127D0(GameData *gameData, u32 index);
u16 *func_020127E0(GameData *gameData);
u32 func_020307B0(void *memory);
int func_02186538(unsigned short *wfbcData, int mapMode, int flag);
int func_02186278(char *wfbcData, int mapMode);
int func_02186854(u16 *itemSlots);
int func_021868B8(u16 *itemSlots, int mapMode, int index, int flag);
void func_0216CF6C(MmdlSys *mmdlSys);
extern void func_02186470(GameData *gameData);
extern void func_021864DC(u16 *wfbcData);
extern unsigned int func_02013F6C(unsigned int zoneId);
extern u8 func_02014468(FieldStatus *fieldStatus);
extern void func_0201446C(FieldStatus *fieldStatus, unsigned int mask);
int func_02012B70(const GameData *gameData);
void func_02014450(FieldStatus *fieldStatus, u32 mapMode);
u32 func_02013CC8(u32 zoneId);
u32 func_02013CE0(u32 zoneId);
u32 func_02013DF0(u32 zoneId);
u32 func_02013D20(u32 zoneId);
u8 func_020129AC(const GameData *gameData);
void func_020129B8(GameData *gameData, u32 subscreenType);
u32 func_02012974(const GameData *gameData);
u32 func_02013B44(u32 zoneId);
int func_02162408(int eventData, int zoneId, int season);
int func_02159B94(int fieldWork, int matrixId, int zoneId, int heapId);
void func_02159CC4(u32 *fieldWork, int gameSystem, int heapId);
extern void func_0216DAC8(unsigned int *mmdl, unsigned int vanish);
u8 *func_02012EC4(GameData *gameData);
void func_0200B37C(void *fieldSave);
s32 *func_0200B394(void *fieldSave, s32 value);
void *func_020490F4(unsigned int arcId, unsigned int heapId);
void *func_02049250(void *arcHandle, u32 member, u32 heapId);
u32 func_020493D4(void *arcHandle, u32 member);
void func_02049238(void *arcHandle);
void func_020061E4(u32 seId);
void *func_02189A08(FieldMap *fieldMap);
void func_021CF498(void *playerObj, GameEvent *event, int frames);
void *func_021BE9F0(GameSystem *gameSystem, FieldMap *fieldMap, int a, int b, int c);
extern int func_0217C070(IntrudeComm *comm);
extern int func_02158630(GameComm *gameComm);
extern int func_021D2750(GameSystem *gameSystem);
extern void func_0217574C(IntrudeComm *comm, u32 suspended);
extern void func_02175710(IntrudeComm *comm, u32 intrudeId);
extern void func_02175B4C(IntrudeComm *comm, u8 *requestInfo);
extern int func_02039338(int aidSource);
int func_02184388(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184410(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184504(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184584(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_0218466C(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184730(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_021847CC(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184894(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_0218495C(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184A14(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184AB4(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184B54(struct GameEvent *event, int *seq, MapChangeWork *work);
int func_02184BF8(struct GameEvent *event, int *seq, MapChangeWork *work);

int func_02184C78(GameEvent *event, int *state, MapChangeWork *work);
void func_02184CEC(MapChangeWork *work, GameSystem *gameSystem);
GameEvent *func_02184D38(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed);
GameEvent *func_02184D90(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
GameEvent *func_02184DE8(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
GameEvent *func_02184E40(GameSystem *gameSystem, int unused, const VecFx32 *targetPos, s16 zoneId, const VecFx32 *pos);
GameEvent *func_02184E94(int unused, GameSystem *gameSystem);
GameEvent *func_02184EEC(GameSystem *gameSystem);
GameEvent *func_02184F40(GameSystem *gameSystem);
GameEvent *func_02184F88(GameSystem *gameSystem);
GameEvent *func_02184FD4(GameSystem *gameSystem, u16 zoneId);
GameEvent *func_02185050(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir);
GameEvent *func_021850A8(GameSystem *gameSystem);
GameEvent *func_021850FC(GameSystem *gameSystem, u8 *unusedPos);
GameEvent *func_02185140(GameSystem *gameSystem, int zoneId, VecFx32 *pos, int requestSession);
GameEvent *func_02185214(GameSystem *gameSystem);
void func_021852F0(Location *location, FieldMap *fieldMap);
GameEvent *func_02185360(GameSystem *gameSystem, int unused, void *connectData, int exitDir);
GameEvent *func_02185410(GameSystem *gameSystem, int unused, void *connectData, int exitDir);
GameEvent *func_02185458(GameSystem *gameSystem, int unused, int transitionType, s16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *func_021854B0(GameSystem *gameSystem, int unused, s16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *func_021854CC(GameSystem *gameSystem, int unused, int unused2, const Location *location, u16 dir);
GameEvent *func_02185534(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, short dir);
GameEvent *func_02185588(GameSystem *gameSystem, u16 zoneId, const VecFx32 *pos);
void func_0218562C(GameSystem *gameSystem);
int func_02185694(GameEvent *event, int *state, WarpIdArrivalWork *work);
GameEvent *func_0218571C(GameSystem *gameSystem);
int func_02185758(int dir);
void func_02185788(EventData *eventData, Location *source, Location *dest);
void func_021858E4(GameData *gameData, const Location *location);
void func_02185928(GameData *gameData, const Location *location);
void func_021859F0(GameData *gameData);
void func_021859FC(GameData *gameData, const Location *location);
void func_02185A34(GameData *gameData, unsigned int zoneId);
void func_02185B88(FieldMap *fieldMap, unsigned int vanish);
void func_02185B9C(GameData *gameData, int zoneId);
GameEvent *func_02185BFC(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, int requestSession, int intrudeId);
GameEvent *func_02185C4C(GameSystem *gameSystem, FieldMap *fieldMap, Location *location);
int func_02185C8C(GameEvent *event, int *state, MapChangeIntrudeWork *work);
int func_02185D38(GameEvent *event, int *state, MapChangeIntrudeWork *work);

u32 func_02014068(u16 zoneId);
u32 func_02013C50(u16 zoneId);
u32 func_02013FEC(u16 zoneId);
Location *func_0201284C(const GameData *gameData);
u32 func_02012B28(const PlayerWork *playerWork);
struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 index);
void func_02045A38(struct Strbuf *strbuf, u16 *dest, u32 length);
struct Mail *func_02008F08(int heapId);
void func_02008F88(struct Mail *mail, const u16 *writerName);
void func_02008FA0(struct Mail *mail, u8 gender);
void func_02008FA8(struct Mail *mail, u32 design);
void func_02008FB4(struct Mail *mail, u8 language);
void func_02008FBC(struct Mail *mail, u8 version);
void func_02008FD8(struct Mail *mail, const void *message, u32 index);
void func_02008FC4(struct Mail *mail, u16 messageId);
struct Mail *func_02008FEC(void *saveControl);
void func_0200903C(struct Mail *box, u32 unused, int slot, const struct Mail *src);
void func_02045808(struct Strbuf *strbuf);
u32 func_02045C04(struct MsgData *msgData);
void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u8 ov230_id[];
extern char ov011_id[];
extern char ov012_id[];
extern char d_02187DA4[];
extern char d_02187DAC[];
extern char d_02187DB4[];
extern char d_02187EA0[];

/* Overlay entry hook: runs the callback when one is set. */
int func_02183B60(void (*hook)(void))
{
    if (hook)
        hook();
    return ~(int)hook;
}

/* Starts the game according to the init work mode. */
void func_02183B6C(struct GameSystem *gameSystem, GameInitWork *initWork)
{
    switch (initWork->mode) {
    case GAMEINIT_MODE_FIRST:
        func_02183C34(gameSystem, initWork);
        break;
    case GAMEINIT_MODE_CONTINUE:
        func_02183F5C(gameSystem, initWork);
        break;
    case GAMEINIT_MODE_DEBUG:
        func_02183D68(gameSystem);
        break;
    }
}

/* First start: set the season, run the opening events, then hand over to the new game start event. */
int func_02183B90(struct GameEvent *event, int *seq, FirstStartWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *child;
    int season;

    switch (*seq) {
    case 0:
        func_0208068C(0x1ff);
        func_02082AC0(0, 0x1a << 22, 0x29 << 14);
        func_02080B98();
        (*seq)++;
        break;
    case 1:
        func_0202E8CC(gameData, (u16)func_0202E888());
        season = func_02012984(gameData);
        child = func_02187808(gameSystem, season, season);
        func_02012374(event, child);
        (*seq)++;
        break;
    case 2:
        child = func_02161B90(gameSystem, event, 5, 0, 1);
        func_02012374(event, child);
        (*seq)++;
        break;
    case 3:
        func_0201235C(event, func_02183D68(gameSystem, work->initWork));
        break;
    }
    return 0;
}

struct GameEvent *func_02183C34(struct GameSystem *gameSystem, GameInitWork *initWork)
{
    struct GameEvent *event;
    FirstStartWork *work;

    event = func_020122C0(gameSystem, 0, func_02183B90, sizeof(FirstStartWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->initWork = initWork;
    return event;
}

/* Fills the player's union room info from the own status. */
void func_02183C58(struct GameSystem *gameSystem)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    void *unionInfo = func_020127C4(gameData);
    void *recvInfo;

    func_021860D4(unionInfo, func_02012944(gameData), 1);
    func_02161D64(func_020127C4(gameData));
    recvInfo = func_020127F0(gameData);
    func_02161F14(recvInfo, func_020127C4(gameData), 1);
}

/* New game start event: plays the start BGM, fades in and shows the place name. */
int func_02183C9C(struct GameEvent *event, int *seq, NewGameStartWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = func_020120F4(gameSystem);
    struct FieldMap *fieldMap;

    func_0201296C(gameData);
    switch (*seq) {
    case 0:
        func_02158A10(gameSystem, 1);
        func_02185A68(gameSystem, (u16)work->startLocation.zoneId);
        func_021857C0(gameSystem, &work->startLocation);
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_020298A0(gameSystem, func_02029DF4(gameData, (s16)work->startLocation.zoneId, func_02012984(gameData)), 0, 0x3c));
        (*seq)++;
        break;
    case 2:
        func_02012374(event, func_020145FC(gameSystem));
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_021BE92C(gameSystem, func_0201210C(gameSystem), 1, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 4:
        fieldMap = func_0201210C(gameSystem);
        if (func_02188D20(fieldMap) != 0)
            func_021BC578(func_02188D20(fieldMap), (s16)work->startLocation.zoneId);
        return 1;
    }
    return 0;
}

struct GameEvent *func_02183D68(struct GameSystem *gameSystem)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, func_02183C9C, sizeof(NewGameStartWork));
    NewGameStartWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    func_02014264(&work->startLocation);
    func_02183C58(gameSystem);
    func_02008B20(func_02008B08(func_02012EBC(work->gameData)));
    func_02021444();
    func_02185F6C(work->gameData);
    func_0208068C(0x1ff);
    func_02082AC0(0, 0x1a << 22, 0x29 << 14);
    func_02080B98();
    return event;
}

/* interface: 020127C4 forwards 020127D0's returned pointer in r0. */
void func_02183DD4(struct GameSystem *gameSystem)
{
    func_02161D64(func_020127C4(func_020120F4(gameSystem)));
}

/* Continue event: restores the field state from the save and enters the saved map. */
int func_02183DE4(struct GameEvent *event, int *seq, ContinueWork *work)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct EventWork *eventWork;
    Location *specialLocation;
    struct FieldMap *fieldMap;
    void *mmdlSys;
    int mapSubType;

    gameSystem = work->gameSystem;
    gameData = func_020120F4(gameSystem);
    eventWork = func_0201296C(gameData);

    switch (*seq) {
    case 0:
        func_0201445C(func_02012B38(gameData), 1);
        if (work->useSpecialLocation != 0) {
            specialLocation = func_02012894(gameData);
            *(s16 *)&work->zoneId = *(s16 *)&specialLocation->zoneId;
            func_02185B70(gameSystem);
            func_02185A68(gameSystem, work->zoneId);
            func_0218601C(gameData);
            func_021857C0(gameSystem, specialLocation);
            func_0202735C(specialLocation->zoneId, gameData);
        } else {
            func_02185A68(gameSystem, work->zoneId);
            func_0218601C(gameData);
            func_02168EEC(gameData);
            func_02164474(gameData, work->zoneId);
            func_0202C860(gameData, work->zoneId);
            mapSubType = func_0201405C(work->zoneId);
            mmdlSys = func_02012964(gameData);
            if (mapSubType < 16) {
                func_0216E29C(mmdlSys, mapSubType);
            } else {
                func_0216CCCC(mmdlSys);
            }
        }
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_020298A0(gameSystem, func_02029DF4(gameData, work->zoneId, func_02012984(gameData)), 0, 0x3c));
        (*seq)++;
        break;
    case 2:
        func_02012374(event, func_020145FC(gameSystem));
        (*seq)++;
        break;
    case 3:
        if (work->useSpecialLocation != 0 && *func_020143CC(eventWork, 0x4041) != 0) {
            func_02158780(event, 0x83b, 0, 0, 0x15);
        } else {
            u8 season = func_02012984(gameData);
            func_02012374(event, func_021BE92C(gameSystem, func_0201210C(gameSystem), 3, 0, 0, season, season));
        }
        (*seq)++;
        break;
    case 4:
        fieldMap = func_0201210C(gameSystem);
        if (func_02188D20(fieldMap) != 0) {
            func_021BC578(func_02188D20(fieldMap), work->zoneId);
        }
        return 1;
    }
    return 0;
}

struct GameEvent *func_02183F5C(struct GameSystem *gameSystem, GameInitWork *initWork)
{
    struct GameEvent *event;
    ContinueWork *work;
    struct EventWork *eventWork;
    struct SaveControl *saveControl;
    struct ConsoleInfo *consoleInfo;
    void *partySave;
    struct MiscSave *miscSave;
    u64 nowSeconds;

    event = func_020122C0(gameSystem, 0, func_02183DE4, sizeof(ContinueWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->zoneId = initWork->zoneId;
    eventWork = func_0201296C(work->gameData);
    work->useSpecialLocation = func_020142E8(eventWork, 0x966);
    func_0201433C(eventWork, 0x966);
    saveControl = func_02012EBC(work->gameData);
    consoleInfo = func_02008B08(saveControl);
    partySave = func_0201AD0C(saveControl);
    miscSave = func_02012F08(work->gameData);
    /* the save was written on another console or with another clock offset */
    if (!func_02008B4C(consoleInfo) || !func_02008B78(consoleInfo)) {
        func_02008C00(func_02008B14(saveControl));
        func_0216A390(work->gameData, partySave);
        nowSeconds = func_0203F524();
        func_0200C384(miscSave, (u32)nowSeconds, (u32)(nowSeconds >> 32));
    }
    func_02008B20(consoleInfo);
    func_0216AAE4(work->gameData, partySave, func_02012984(work->gameData));
    func_02183DD4(gameSystem);
    func_02021444();
    func_0208068C(0x1FF);
    func_02082AC0(0, 0x06800000, 0xA4000);
    func_02080B98();
    return event;
}

/* Reads the season pair for the destination: when the season changed and the destination is
 * outdoors, marks the change in the work. */
void func_0218403C(MapChangeWork *work)
{
    u16 seasons[2];
    struct AreaData *areaData;
    int outdoors;
    u16 fromSeason;

    func_0202E848(work->gameData, &seasons[1], &seasons[0]);
    areaData = func_0201407C(func_02188C84(work->fieldMap), func_02013B38(work->destination.zoneId), 0);
    outdoors = 0;
    if (func_020140D8(areaData) != 0)
        outdoors = 1;
    func_020140B4(areaData);
    fromSeason = seasons[1];
    if (seasons[0] != fromSeason && outdoors) {
        work->seasonChanged = 1;
        work->fromSeason = fromSeason;
        work->toSeason = seasons[0];
    }
}

/* Fills the entrance parameters of the exit effect. */
void func_0218409C(MapChangeWork *work, struct GameEvent *event)
{
    EntranceParam *entrance = &work->entrance;

    entrance->gameSystem = work->gameSystem;
    entrance->gameData = work->gameData;
    entrance->fieldMap = work->fieldMap;
    entrance->exitType = work->exitType;
    work->entrance.event = event;
    entrance->currentZoneId = work->currentZoneId;
    entrance->destination = work->destination;
    entrance->exitEffectId = func_021BE89C(work->currentZoneId, work->destination.zoneId);
    entrance->entranceEffectId = func_021BE8B8(work->currentZoneId, work->destination.zoneId);
    entrance->seasonChanged = (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) ? 1 : 0;
    entrance->fromSeasonIndex = sub_0202E8A4(work->fromSeason);
    entrance->toSeason = work->toSeason;
    entrance->bgmReplaced = 0;
    entrance->bgmFadeStarted = 0;
}

/* Fills the entrance parameters of the entrance effect. */
void func_02184120(MapChangeWork *work, struct GameEvent *event)
{
    EntranceParam *entrance = &work->entrance;

    entrance->gameSystem = work->gameSystem;
    entrance->gameData = work->gameData;
    entrance->fieldMap = work->fieldMap;
    entrance->exitType = work->exitType;
    work->entrance.event = event;
    entrance->currentZoneId = work->currentZoneId;
    entrance->destination = work->destination;
    entrance->exitEffectId = func_021BE89C(work->currentZoneId, work->destination.zoneId);
    entrance->entranceEffectId = func_021BE8B8(work->currentZoneId, work->destination.zoneId);
    entrance->seasonChanged = (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) ? 1 : 0;
    entrance->fromSeasonIndex = sub_0202E8A4(work->fromSeason);
    entrance->toSeason = work->toSeason;
    if (work->destination.type == 1) {
        entrance->destExitType = 0;
        return;
    }
    entrance->destExitType = func_021626E8(func_021625CC(func_02012844(work->gameData), work->destination.exitId));
}

/* Change field event: unloads the old field, loads the new one and starts the arrival events.
 * Two spellings are load-bearing.  The u8 range check on func_02026454's
 * result is `adds r0, #0xff; lsls/lsrs #0x18; cmp #1; bhi`: written
 * `(u8)(v - 1) <= 1` it compiles to `subs r0, r0, #1` (one byte out), and as
 * `switch (v) { case 1: case 2: }` it grows by 4 bytes with two compares;
 * only `(u8)(v + 0xff) <= 1` gives the add.  The dead `str r2, [sp, #0xc]`
 * after `adds r2, #0x14` is `a += 0x14;` on the spilled local before the
 * func_0216A358 call.  func_021882A0/02188318/021883CC are ov230's decrypted
 * code (ov230d token); each gets the range func_02183B60 to one of this
 * overlay's end markers. */
int func_021841C0(struct GameEvent *event, int *seq, ChangeFieldWork *changeField)
{
    MapChangeWork *work;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    struct GameComm *gameComm;
    void *party;
    int season;
    int sessionPtr;

    work = changeField->mapChange;
    fieldMap = work->fieldMap;
    gameSystem = work->gameSystem;
    gameData = work->gameData;
    gameComm = func_02012138(gameSystem);

    switch (*seq) {
    case 0:
        func_0201447C(func_02012B38(gameData), 2);
        func_02012374(event, func_02014554(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02034AC4((int)ov230_id);
        if (func_02013D34(work->destination.zoneId) == 1 && (u8)(func_02026454(gameComm) + 0xff) <= 1) {
            func_02026400(gameComm);
            *seq = 2;
        } else {
            *seq = 3;
        }
        break;
    case 2:
        if (func_02026454(gameComm) == 0) {
            *seq = 3;
        }
        break;
    case 3:
        func_021882A0((void (*)(void))func_02183B60, (void (*)(void))func_0218604C, 0);
        func_02185B70(gameSystem);
        if (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) {
            func_0202E8CC(gameData, work->toSeason);
            sessionPtr = (int)func_02008B14(func_02012EBC(gameData));
            season = func_02012984(gameData);
            party = func_02012934(gameData);
            func_0216AAE4(gameData, party, season);
            sessionPtr += 0x14;
            func_0216A358(gameData, party, (u32 *)sessionPtr, season);
        }
        func_02188318((void (*)(void))func_02183B60, (void (*)(void))func_0218606C, 0);
        func_02185A68(gameSystem, work->destination.zoneId);
        func_021857C0(gameSystem, &work->destination);
        if (work->changeKind != 4) {
            func_0202735C(work->destination.zoneId, gameData);
        }
        func_021883CC((void (*)(void))func_02183B60, func_0218608C, 0);
        switch (work->changeKind) {
        case 1:
            func_02164454(gameData, work->destination.zoneId);
            break;
        case 2:
            func_02164464(gameData, work->destination.zoneId);
            break;
        case 3:
            func_0216445C(gameData, work->destination.zoneId);
            break;
        }
        func_02034A5C((int)ov230_id);
        func_0215874C(gameComm);
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_020145FC(gameSystem));
        (*seq)++;
        break;
    case 5:
        func_02012374(event, func_02029C64(gameSystem));
        (*seq)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}

/* Starts the change field event as a child of the work's game system. */
struct GameEvent *func_02184360(MapChangeWork *work, int changeKind)
{
    struct GameEvent *event;
    ChangeFieldWork *changeField;

    event = func_020122C0(work->gameSystem, 0, func_021841C0, sizeof(ChangeFieldWork));
    changeField = func_020124E8(event);
    changeField->mapChange = work;
    work->changeKind = changeKind;
    return event;
}

/* Map change with the entrance effects. */
int func_02184388(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case 0:
        func_0218403C(work);
        func_0216D9A0(func_02188C7C(fieldMap));
        func_0218409C(work, event);
        func_02012374(event, func_021BD648(&work->entrance));
        (*seq)++;
        return 0x21;
    case 1:
        func_02012374(event, func_02184360(work, 0));
        (*seq)++;
        break;
    case 2:
        func_02184120(work, event);
        func_02012374(event, func_021BD9BC(&work->entrance));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Map change with the entrance effects for zones in the table at 0209DFC0: waits for the
 * communication partner first.
 * The leaf func_02013DD0 is `sub_02013B10(v, tbl_0209DFC0, 4)`. */
int func_02184410(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    void *commHandle;

    fieldMap = work->fieldMap;
    gameData = work->gameData;
    commHandle = func_02158344(func_02012138(work->gameSystem));

    switch (*seq) {
    case 0:
        func_0216D9A0(func_02188C7C(fieldMap));
        if (func_02013DD0(work->destination.zoneId) == 1) {
            *seq = 5;
        } else {
            *seq = 1;
        }
        break;
    case 1:
        func_0218409C(work, event);
        func_02012374(event, func_021BD648(&work->entrance));
        (*seq)++;
        return 0x21;
    case 2:
        func_02012374(event, func_02184360(work, 0));
        (*seq)++;
        break;
    case 3:
        func_02184120(work, event);
        func_02012374(event, func_021BD9BC(&work->entrance));
        (*seq)++;
        break;
    case 4:
        return 1;
    case 5:
        if (commHandle == 0) {
            *seq = 7;
            break;
        }
        if (func_021746AC(commHandle, func_0215841C(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (commHandle == 0) {
            *seq = 7;
            break;
        }
        if (func_02158428(commHandle) == 1) {
            *seq = 1;
        }
        break;
    case 7:
        func_0216D9E4(func_02188C7C(fieldMap));
        return 1;
    }
    return 0;
}

/* Tail of the detached map change: sound, then the change field event. */
int func_02184504(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameEvent *child;
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    fieldMap = work->fieldMap;
    gameData = work->gameData;
    fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        child = func_02161824(gameSystem, fieldMap);
        func_02012374(event, child);
        (*seq)++;
        break;
    case 1:
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        (*seq)++;
        break;
    case 2:
        child = func_02184360(work, work->changeKind);
        func_02012374(event, child);
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Map change with a fade, the fade picked from the season change or the zone pair. */
int func_02184584(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = work->gameSystem;
    fieldMap = work->fieldMap;

    switch (*seq) {
    case 0:
        func_0218403C(work);
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        if (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) {
            func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 0, 0));
        } else {
            func_02012374(event, func_021BE8D4(gameSystem, fieldMap, func_021BE89C(work->currentZoneId, work->destination.zoneId), 0));
        }
        (*seq)++;
        break;
    case 2:
        func_02012374(event, func_02184360(work, work->changeKind));
        (*seq)++;
        break;
    case 3:
        if (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) {
            func_02012374(event, func_021BE92C(gameSystem, fieldMap, 3, 0, 0, (u8)work->fromSeason, (u8)work->toSeason));
        } else {
            func_02012374(event, func_021BE92C(gameSystem, fieldMap, func_021BE8B8(work->currentZoneId, work->destination.zoneId), 0, 1, 0, 0));
        }
        (*seq)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/* Map change with fade effect 2; the default case waits seven frames between steps 0 and 8. */
int func_0218466C(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 8:
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 2, 0));
        (*seq)++;
        break;
    case 9:
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        (*seq)++;
        break;
    case 10:
        func_02012374(event, func_02184360(work, work->changeKind));
        (*seq)++;
        break;
    case 11:
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 2, 0, 0, 0, 0));
        (*seq)++;
        break;
    case 12:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    default:
        (*seq)++;
        break;
    }
    return 0;
}

/* Map change that moves the player to the target position. */
int func_02184730(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BFD34(event, gameSystem, fieldMap, &work->targetPos));
        (*seq)++;
        break;
    case 2:
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_02184360(work, 0));
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_021BF58C(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}

/* Map change of kind 2 with the season passed to the effect events. */
int func_021847CC(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        func_0218403C(work);
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BFD70(event, gameSystem, fieldMap, work->seasonChanged));
        (*seq)++;
        break;
    case 2:
        func_02185F48(gameData);
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_02184360(work, 2));
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_021BF5B4(event, gameSystem, fieldMap, work->seasonChanged,
                                           work->fromSeason, work->toSeason));
        (*seq)++;
        break;
    case 5:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Same steps as the previous one with the second pair of effect events. */
int func_02184894(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = work->gameData;
    struct FieldMap *fieldMap = work->fieldMap;
    struct FieldSoundSystem *fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        func_0218403C(work);
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BFDA0(event, gameSystem, fieldMap, work->seasonChanged));
        (*seq)++;
        break;
    case 2:
        func_02185F48(gameData);
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_02184360(work, 2));
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_021BF5E8(event, gameSystem, fieldMap, work->seasonChanged, work->fromSeason, work->toSeason));
        (*seq)++;
        break;
    case 5:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change of kind 3: resets the player's object code. */
int func_0218495C(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BFDD0(event, gameSystem, fieldMap, 1));
        (*seq)++;
        break;
    case 2:
        func_02012B2C(func_020127A4(gameData), 0);
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_02184360(work, 3));
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_021BF61C(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 5:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change with fade effect 1; waits for the field map transition before the animation. */
int func_02184A14(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct FieldMap *fieldMap = work->fieldMap;
    int transition = func_02188D38(fieldMap);

    switch (*seq) {
    case 0:
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 1, 0));
        (*seq)++;
        break;
    case 1:
        if (func_021C6E48(transition)) {
            func_02012374(event, func_02161824(gameSystem, fieldMap));
            (*seq)++;
        }
        break;
    case 2:
        func_02012374(event, func_02184360(work, 0));
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 1, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 4:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change with fade effect 0: fades out, then continues in a detached copy of the work. */
int func_02184AB4(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct FieldMap *fieldMap = work->fieldMap;
    struct GameEvent *tailEvent;
    MapChangeWork *tailWork;

    switch (*seq) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 2:
        tailEvent = func_020122C0(gameSystem, 0, func_02184504, sizeof(MapChangeWork));
        tailWork = func_020124E8(tailEvent);
        *tailWork = *work;
        func_02012374(event, tailEvent);
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 4:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change of kind 0 with the third pair of effect events. */
int func_02184B54(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = func_02012A30(gameData);

    switch (*seq) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BFE00(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 2:
        func_02029D44(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        func_02029D7C(fieldSound, gameData);
        func_02012374(event, func_02184360(work, 0));
        (*seq)++;
        break;
    case 3:
        func_02012374(event, func_021BF644(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 4:
        func_021BC550(func_02188D20(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change that swaps the communication overlay (ov012 out, ov011 in) and calls script 0x83A. */
int func_02184BF8(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct FieldMap *fieldMap = work->fieldMap;
    struct GameEvent *child;

    switch (*seq) {
    case 0:
        child = func_021BFDD0(event, gameSystem, fieldMap, 0);
    join:
        func_02012374(event, child);
        (*seq)++;
        break;
    case 1:
        child = func_02184360(work, 0);
        goto join;
    case 2:
        func_02034A5C((int)ov012_id);
        func_02034AC4((int)ov011_id);
        func_02158780(event, 0x83A, 0, 0, 0x15);
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Event callback: plays the animation, swaps overlays 11 and 12, runs the fade. */
int func_02184C78(GameEvent *event, int *state, MapChangeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    switch (*state) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*state)++;
        break;
    case 1:
        func_02034A5C((int)ov011_id);
        func_02034AC4((int)ov012_id);
        func_02012374(event, func_02184360(work, 4));
        (*state)++;
        break;
    case 2:
        func_02173744(gameSystem);
        (*state)++;
        break;
    case 3:
        func_02012374(event, func_021BF66C(event, gameSystem, fieldMap));
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/* Fills the common part of a map change work area. */
void func_02184CEC(MapChangeWork *work, GameSystem *gameSystem)
{
    GameData *gameData = func_020120F4(gameSystem);
    FieldMap *fieldMap = func_0201210C(gameSystem);
    u16 season = func_02012984(gameData);

    work->gameSystem = gameSystem;
    work->gameData = gameData;
    work->fieldMap = fieldMap;
    work->currentZoneId = func_02188C9C(fieldMap);
    work->seasonFadeAllowed = 0;
    work->seasonChanged = 0;
    work->fromSeason = season;
    work->toSeason = season;
    func_021AAAF0(func_02188CE8(work->fieldMap), 1);
}

/*
 * The leaf func_02014184 is resolved by its matched shard.
 *
 * What made it byte-correct: `const VecFx32 *pos` (see the EXACT twins
 * func_02184D90 and func_02184DE8).
 */
GameEvent *func_02184D38(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184388, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    dir = func_020142A4(dir);
    func_02014184(&work->destination, zoneId, (s16)dir, pos->x, pos->y, pos->z);
    work->exitType = 0;
    work->seasonFadeAllowed = seasonFadeAllowed;
    return event;
}

/*
 * Rail variant of the warp event: the 0x1C-byte location at +0x10 is
 * filled by func_020141A8 from the rail position.
 * What closed it: `const RailLocation *rail`. Without const the field loads
 * are kept below the outgoing stack-argument stores and `adds r1,r7` is
 * scheduled first; const lets them hoist. The u16 stack parameter dir fixes
 * the frame.
 */
GameEvent *func_02184D90(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184388, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    dir = func_020142A4(dir);
    func_020141A8(&work->destination, zoneId, (s16)dir, rail->railIndex, rail->lineGrid, rail->widthGrid);
    work->exitType = 0;
    work->seasonFadeAllowed = seasonFadeAllowed;
    return event;
}

GameEvent *func_02184DE8(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184504, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    dir = func_020142A4(dir);
    func_020141A8(&work->destination, zoneId, (s16)dir, rail->railIndex, rail->lineGrid, rail->widthGrid);
    work->exitType = 0;
    work->seasonFadeAllowed = seasonFadeAllowed;
    return event;
}

static inline void EVENT_MAPCHANGE_SetVec(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

GameEvent *func_02184E40(GameSystem *gameSystem, int unused, const VecFx32 *targetPos, s16 zoneId, const VecFx32 *pos)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184730, 0x9c);
    MapChangeWork *work = func_020124E8(event);
    func_02184CEC(work, gameSystem);
    func_02014184(&work->destination, zoneId, 1, pos->x, pos->y, pos->z);
    EVENT_MAPCHANGE_SetVec(&work->targetPos, targetPos->x, targetPos->y, targetPos->z);
    work->exitType = 0;
    return event;
}

/* Escape event: warps to the stored escape location. */
GameEvent *func_02184E94(int unused, GameSystem *gameSystem)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021847CC, 0x9c);
    MapChangeWork *work = func_020124E8(event);
    Location *escapeLocation;

    func_02184CEC(work, gameSystem);
    escapeLocation = func_020128B8(work->gameData);
    work->destination = *escapeLocation;
    func_02185F18(work->gameData, &work->destination);
    work->destination.type = 1;
    work->exitType = 0;
    work->seasonFadeAllowed = 1;
    return event;
}

GameEvent *func_02184EEC(GameSystem *gameSystem)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184894, 0x9c);
    MapChangeWork *work = func_020124E8(event);
    Location *escapeLocation;

    func_02184CEC(work, gameSystem);
    escapeLocation = func_020128B8(work->gameData);
    work->destination = *escapeLocation;
    func_02185F18(work->gameData, &work->destination);
    work->destination.type = 1;
    work->exitType = 0;
    work->seasonFadeAllowed = 1;
    return event;
}

/* Warp to the start location of the situation warp id. */
GameEvent *func_02184F40(GameSystem *gameSystem)
{
    int warpId = func_02012914(func_020120F4(gameSystem));
    GameEvent *event = func_020122C0(gameSystem, 0, func_0218495C, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    func_02014204(&work->destination, func_02159F94(warpId));
    work->destination.type = 1;
    work->exitType = 0;
    return event;
}

/* Warp to the stored special location, facing dir 2. */
GameEvent *func_02184F88(GameSystem *gameSystem)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184A14, 0x9c);
    MapChangeWork *work = func_020124E8(event);
    Location *specialLocation;

    func_02184CEC(work, gameSystem);
    specialLocation = func_02012894(work->gameData);
    work->destination = *specialLocation;
    work->destination.type = 1;
    work->destination.dir = 2;
    work->exitType = 0;
    return event;
}

/*
 * Warp to the start location of a zone. The current player position is
 * stored as the special location first.
 */
GameEvent *func_02184FD4(GameSystem *gameSystem, u16 zoneId)
{
    Location playerLocation;
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184AB4, 0x9c);
    MapChangeWork *work = func_020124E8(event);
    PlayerWork *playerWork;
    int playerZoneId, playerDir;
    VecFx32 *playerPos;

    func_02184CEC(work, gameSystem);
    func_02014204(&work->destination, zoneId);
    work->exitType = 0;
    work->destination.dir = 1;
    playerWork = func_020127A4(work->gameData);
    playerPos = func_02012AA0(playerWork);
    playerZoneId = func_02012AC8(playerWork);
    func_02014184(&playerLocation, playerZoneId, (s16)func_02012AE4(playerWork), playerPos->x, playerPos->y, playerPos->z);
    func_0201289C(work->gameData, &playerLocation);
    return event;
}

GameEvent *func_02185050(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184B54, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    dir = func_020142A4(dir);
    func_02014184(&work->destination, zoneId, dir, pos->x, pos->y, pos->z);
    work->exitType = 5;
    work->seasonFadeAllowed = 0;
    return event;
}

/* Fixed destination: zone 0x1A6 at a hard-coded position. */
GameEvent *func_021850A8(GameSystem *gameSystem)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184C78, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    func_02014184(&work->destination, 0x1A6, func_020142A4(0), 0x2E << 14, 0, 0x3E << 14);
    work->exitType = 0;
    return event;
}

/* Allocator with callback, then the special location copied to +0x10. */
GameEvent *func_021850FC(GameSystem *gameSystem, u8 *unusedPos)
{
    Location *specialLocation = func_02012894(func_020120F4(gameSystem));
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184BF8, 0x9C);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    work->destination = *specialLocation;
    return event;
}

/*
 * Starts an intrude warp: builds the current location, shifts the x
 * position by the intrude slot and creates the arrival event.
 */
GameEvent *func_02185140(GameSystem *gameSystem, int zoneId, VecFx32 *pos, int requestSession)
{
    FieldMap *fieldMap;
    GameData *gameData;
    VecFx32 shiftedPos;
    Location currentLocation;
    Location eventLocation;
    int xFlag;
    int intrudeId;
    int slotOffset;
    void *saveRecord;
    IntrudeComm *comm;

    fieldMap = func_0201210C(gameSystem);
    gameData = func_020120F4(gameSystem);
    shiftedPos = *pos;
    xFlag = 0;
    func_021852F0(&currentLocation, fieldMap);
    func_020128E4(gameData, &currentLocation);
    saveRecord = func_0200BE48(func_02012EBC(gameData));
    func_0200BFA4(saveRecord, func_02012FCC(gameData), 0);
    comm = func_02158344(func_02012138(gameSystem));
    if (comm == 0 || func_02158590(gameData) == 0) {
        intrudeId = 0;
        slotOffset = 0;
    } else {
        intrudeId = func_02176230(comm, comm->requestInfo);
        slotOffset = intrudeId - func_02012B58(gameData);
        if (slotOffset < 0)
            slotOffset += comm->slotCount;
        xFlag = 0x10000;
    }
    shiftedPos.x += xFlag + (slotOffset << 22);
    func_02014184(&eventLocation, zoneId, func_020142A4(0), shiftedPos.x, shiftedPos.y, shiftedPos.z);
    return func_02185BFC(gameSystem, fieldMap, &eventLocation, requestSession, intrudeId);
}

static inline void EVENT_MAPCHANGE_CreateArriveEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, GameEvent **out)
{
    *out = func_02185C4C(gameSystem, fieldMap, location);
}

static inline GameEvent *EVENT_MAPCHANGE_FinishIntrudeWarp(GameSystem *gameSystem, GameData *gameData, FieldMap *fieldMap, GameEvent *event)
{
    u16 *saveRecord;
    GameComm *gameComm;

    saveRecord = func_0200BE48(func_02012EBC(gameData));
    func_0200BFA4(saveRecord, func_02012FCC(gameData), 1);
    gameComm = func_02012138(gameSystem);
    func_0202648C(gameComm);
    if (func_02026454(gameComm) == 0)
        func_02026484(gameComm);
    if (func_021A3238(func_02188CB4(fieldMap)) == 0)
        func_0217BCDC(0, gameSystem, 0, 0, 0);
    func_02012B78(gameData, 0);
    if (func_02158344(func_02012138(gameSystem)) == 0) {
        func_02012B64(gameData, 0);
        func_02012B8C(gameData, 0);
        func_02012B4C(gameData, 1);
    }
    return event;
}

/*
 * Lever: func_0202648C reads its pointer argument in the matched ARM9
 * unit_02026454.c. The original forwards func_02012138(gameSystem) in r0
 * with no intervening argument setup. Explicitly passing gameComm restores
 * the return-value spill and all frame/register choices.
 */
GameEvent *func_02185214(GameSystem *gameSystem)
{
    GameData *gameData;
    FieldMap *fieldMap;
    Location warpLocation;
    GameEvent *event;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    warpLocation = *func_020128DC(gameData);
    if (func_02013DD0(warpLocation.zoneId) == 1)
        func_02014204(&warpLocation, warpLocation.zoneId);
    EVENT_MAPCHANGE_CreateArriveEvent(gameSystem, fieldMap, &warpLocation, &event);
    return EVENT_MAPCHANGE_FinishIntrudeWarp(gameSystem, gameData, fieldMap, event);
}

/* Builds the location of the player on the current map (direct or rail). */
void func_021852F0(Location *location, FieldMap *fieldMap)
{
    RailLocation rail;
    void *fieldPlayer = func_02188CB4(fieldMap);

    if (func_02188CFC(fieldMap) == 0) {
        VecFx32 *playerPos;

        playerPos = func_0216D888(func_021A3074(fieldPlayer));
        func_02014184(location, func_02188C9C(fieldMap), 1, playerPos->x, playerPos->y, playerPos->z);
        return;
    }
    func_021A36BC(fieldPlayer, &rail);
    func_020141A8(location, func_02188C9C(fieldMap), 2, rail.railIndex, rail.lineGrid, rail.widthGrid);
}

/* Warp through a map exit (door, stairs, connection). */
GameEvent *func_02185360(GameSystem *gameSystem, int unused, void *connectData, int exitDir)
{
    MapChangeWork *work;
    GameData *gameData = func_020120F4(gameSystem);
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184388, 0x9c);
    Location *entranceLocation;

    work = func_020124E8(event);
    func_02184CEC(work, gameSystem);
    work->seasonFadeAllowed = 1;
    if (func_021625E8(connectData) != 0) {
        work->destination = *func_02012894(gameData);
    } else {
        func_02162694(connectData, &work->destination, exitDir);
    }
    work->exitType = func_021626E8(connectData);
    entranceLocation = func_02012870(gameData);
    if (func_02013E7C(entranceLocation->zoneId) == 1 && func_02013E7C(work->destination.zoneId) == 0) {
        func_020128C0(gameData, entranceLocation);
    }
    func_02185EB0(gameData, &work->destination);
    func_0201447C(func_02012B38(gameData), 2);
    return event;
}

GameEvent *func_02185410(GameSystem *gameSystem, int unused, void *connectData, int exitDir)
{
    GameEvent *event;
    MapChangeWork *work;

    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_02184410, 0x9c);
    work = func_020124E8(event);
    func_02184CEC(work, gameSystem);
    work->seasonFadeAllowed = 1;
    func_02162694(connectData, &work->destination, exitDir);
    work->exitType = func_021626E8(connectData);
    return event;
}

GameEvent *func_02185458(GameSystem *gameSystem, int unused, int transitionType, s16 zoneId, const VecFx32 *pos, u16 dir)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184504, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    dir = func_020142A4(dir);
    func_02014184(&work->destination, zoneId, dir, pos->x, pos->y, pos->z);
    work->exitType = 0;
    work->changeKind = transitionType;
    return event;
}

GameEvent *func_021854B0(GameSystem *gameSystem, int unused, s16 zoneId, const VecFx32 *pos, u16 dir)
{
    return func_02185458(gameSystem, unused, 0, zoneId, pos, dir);
}

/* Warp to a ready-made location, facing dir. */
GameEvent *func_021854CC(GameSystem *gameSystem, int unused, int unused2, const Location *location, u16 dir)
{
    GameData *gameData = func_020120F4(gameSystem);
    GameEvent *event;
    MapChangeWork *work;

    func_02012B2C(func_020127A4(gameData), 0);
    event = func_020122C0(gameSystem, 0, func_02184504, 0x9c);
    work = func_020124E8(event);
    func_02184CEC(work, gameSystem);
    work->destination = *location;
    work->destination.dir = dir;
    work->exitType = 0;
    work->changeKind = 1;
    func_02185EB0(gameData, &work->destination);
    return event;
}

/*
 * Lever: `const VecFx32 *pos` (as in func_02184E40) and the callee's third
 * parameter declared short.
 */
GameEvent *func_02185534(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, short dir)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02184584, 0x9c);
    MapChangeWork *work = func_020124E8(event);

    func_02184CEC(work, gameSystem);
    *(u16 *)&dir = func_020142A4(*(u16 *)&dir);
    func_02014184(&work->destination, zoneId, dir, pos->x, pos->y, pos->z);
    work->exitType = 0;
    return event;
}

/*
 * Two source facts closed the last 18 bytes: (1) zoneId is a u16 parameter,
 * and func_02014184 takes a u16 id (its matched definition in
 * src/matched/arm9/func_02014184.c); (2) the bit field slot is read into its
 * own block local (`int slot = comm->slot; offset = slot - exitMode;`), the
 * same shape as func_02185140.
 */
GameEvent *func_02185588(GameSystem *gameSystem, u16 zoneId, const VecFx32 *pos)
{
    VecFx32 warpPos = *pos;
    GameData *gameData = func_020120F4(gameSystem);
    GameEvent *event = func_020122C0(gameSystem, 0, func_0218466C, 0x9C);
    MapChangeWork *work = func_020124E8(event);
    int slotOffset = 0;

    if (func_02013D5C(zoneId) == 1) {
        IntrudeComm *comm = func_02158344(func_02012138(gameSystem));
        if (comm != 0) {
            int slot = comm->slot;
            slotOffset = slot - func_02012B58(gameData);
            if (slotOffset < 0)
                slotOffset += comm->slotCount;
        }
        warpPos.x += (u32)slotOffset << 22;
    }
    func_02184CEC(work, gameSystem);
    func_02014184(&work->destination, zoneId, (s16)func_020142A4(0), warpPos.x, warpPos.y, warpPos.z);
    work->exitType = 0;
    work->seasonFadeAllowed = 0;
    return event;
}

/* Sets up the game state for the warp id of the situation block. */
void func_0218562C(GameSystem *gameSystem)
{
    GameData *gameData = func_020120F4(gameSystem);
    struct {
        Location startLocation;
        Location arrivalLocation;
    } locations;

    func_02159FA8(func_02012914(gameData), &locations.arrivalLocation);
    func_02014204(&locations.startLocation, func_02159F94(func_02012914(gameData)));
    func_020128C0(gameData, &locations.startLocation);
    func_02185B70(gameSystem);
    func_02185A68(gameSystem, locations.arrivalLocation.zoneId);
    func_021857C0(gameSystem, &locations.arrivalLocation);
    func_0202735C(locations.arrivalLocation.zoneId, gameData);
    func_02168EEC(gameData);
    func_0216446C(gameData, locations.arrivalLocation.zoneId);
}

/*
 * The leaves func_0202B578 (`return p[8]`) and func_02029DF4 (a thumb
 * tail-call stub to func_02029EB4) are unlabelled ARM9 code resolved by
 * their matched shards.
 */
int func_02185694(GameEvent *event, int *state, WarpIdArrivalWork *work)
{
    GameEvent *child;
    unsigned int bgmId;

    switch (state[0]) {
    case 0:
        func_0218562C(work->gameSystem);
        state[0]++;
        break;
    case 1:
        func_02012B2C(func_020127A4(func_020120F4(work->gameSystem)), 0);
        func_0202C110(func_0202B578(func_02012134(work->gameSystem)));
        bgmId = func_02029DF4(work->gameData, (s16)work->location.zoneId, func_02012984(work->gameData));
        child = func_020298A0(work->gameSystem, bgmId, 0, 0x3c);
        func_02012374(event, child);
        state[0]++;
        break;
    case 2:
        child = func_020145FC(work->gameSystem);
        func_02012374(event, child);
        state[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

GameEvent *func_0218571C(GameSystem *gameSystem)
{
    GameEvent *event;
    WarpIdArrivalWork *work;

    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_02185694, sizeof(WarpIdArrivalWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    func_02159FA8(func_02012914(work->gameData), &work->location);
    return event;
}

/* Maps a direction code to a rotation angle. */
int func_02185758(int dir)
{
    switch (dir) {
    case 0:
    case 1:
    default: return 0;
    case 3: return 0x4000;
    case 2: return 0x8000;
    case 4: return 0xc000;
    }
}

/* Resolves a location: copies direct ones, looks up exits, else zone start. */
void func_02185788(EventData *eventData, Location *source, Location *dest)
{
    if (source->type == 1) {
        *dest = *source;
    } else {
        if (func_021625FC(eventData, dest, (u16)source->exitId, source->exitOffset) == 0) {
            func_02014204(dest, source->zoneId);
        }
    }
}

/* Applies a new location to the player, the map objects and the field state. */
void func_021857C0(GameSystem *gameSystem, Location *warpLocation)
{
    GameData *gameData;
    PlayerWork *playerWork;
    EventData *eventData;
    Location location;
    u16 warpId;
    int mapSubType;
    MmdlSys *mmdlSys;

    gameData = func_020120F4(gameSystem);
    playerWork = func_020127A4(gameData);
    eventData = (EventData *)func_02012844(gameData);
    func_02014454(func_02012B38(gameData), 1);
    func_02185788(eventData, warpLocation, &location);
    if (location.type == 3)
        func_0201289C(gameData, func_02012870(gameData));
    func_02012AC4(playerWork, location.zoneId);
    func_02012ACC(playerWork, func_02185758(location.dir));
    if (func_020141DC(&location) == 0) {
        func_02012A90(playerWork, &location.pos.vec);
        func_02012ABC(playerWork, 0);
    } else {
        func_02012AA4(playerWork, &location.pos.rail);
        func_02012ABC(playerWork, 1);
    }
    func_0202B544(func_02012134(gameSystem), location.zoneId);
    func_02012854(gameData, &location);
    warpId = func_02159FE0((s16)location.zoneId);
    if (warpId != 0)
        func_02012900(gameData, warpId);
    func_02185B9C(gameData, (s16)location.zoneId);
    func_02168EEC(gameData);
    func_021643E8(gameData, location.zoneId);
    func_0215A014(gameData, (s16)location.zoneId);
    func_02158AE0(gameSystem, (void *)4);
    func_021858E4(gameData, warpLocation);
    func_02185A34(gameData, location.zoneId);
    func_021859FC(gameData, &location);
    func_0202C83C((int)gameSystem, (s16)location.zoneId);
    mapSubType = func_0201405C(location.zoneId);
    mmdlSys = func_02012964(gameData);
    if (mapSubType < 16)
        func_0216E29C(mmdlSys, mapSubType);
    else
        func_0216CCCC(mmdlSys);
}

/* Adds the map objects (NPC headers) of the event data of a zone. */
void func_021858E4(GameData *gameData, const Location *location)
{
    EventData *eventData = (EventData *)func_02012844(gameData);
    int npcCount = func_02162744(eventData);

    if (npcCount != 0) {
        int eventWork = (int)func_0201296C(gameData);
        MmdlSys *mmdlSys = func_02012964(gameData);
        int npcHeaders = func_02162740(eventData);
        int zoneId = (s16)location->zoneId;
        func_0216CEAC(mmdlSys, (u8 *)npcHeaders, zoneId, npcCount, eventWork);
    }
}

/*
 * Adds the map objects of the White Forest / Black City (WFBC) data of a
 * zone: the people, then the items.
 * The leaf func_02013DD0 returns whether the zone is in a fixed table
 * (`return func_02013B10(zoneId, table, 4)`).
 */
void func_02185928(GameData *gameData, const Location *location)
{
    int mapMode;
    int headers;
    int itemCount;
    int headerCount;
    int mmdlSys;
    int eventWork;
    unsigned short *wfbcData;
    int itemSlots;

    if (func_02013DD0((unsigned short)location->zoneId) == 0)
        return;

    mapMode = (int)func_0201444C(func_02012B38(gameData));
    mmdlSys = (int)func_02012964(gameData);
    eventWork = (int)func_0201296C(gameData);
    if (mapMode == 0)
        wfbcData = func_020127C4(gameData);
    else
        wfbcData = func_020127D0(gameData, (int)0);

    headers = func_02186538(wfbcData, mapMode, 1);
    headerCount = func_02186278((char *)wfbcData, mapMode);
    if (headers != 0 && headerCount != 0)
        func_0216CEAC((MmdlSys *)mmdlSys, (u8 *)headers, (s16)location->zoneId, (int)headerCount, (int)eventWork);
    if (headers != 0)
        func_020307B0((void *)headers);

    itemSlots = (int)func_020127E0(gameData);
    itemCount = func_02186854((u16 *)itemSlots);
    headers = func_021868B8((u16 *)itemSlots, mapMode, wfbcData[1], 1);
    if (headers != 0 && itemCount != 0)
        func_0216CEAC((MmdlSys *)mmdlSys, (u8 *)headers, (s16)location->zoneId, (int)itemCount, (int)eventWork);
    if (headers != 0)
        func_020307B0((void *)headers);
}

void func_021859F0(GameData *gameData)
{
    func_0216CF6C(func_02012964(gameData));
}

/* Reloads the map objects of a zone (people, WFBC people and items). */
void func_021859FC(GameData *gameData, const Location *location)
{
    func_02186470(gameData);
    if (func_02013DD0(location->zoneId) != 0) {
        func_02185928(gameData, location);
        if (func_0201444C(func_02012B38(gameData)) == 0) {
            func_021864DC(func_020127C4(gameData));
        }
    }
}

/*
 * Interface: func_0201446C takes the full-word mask (the absent call-site
 * truncation matches).
 */
void func_02185A34(GameData *gameData, unsigned int zoneId)
{
    FieldStatus *fieldStatus;
    unsigned int effectMask;

    fieldStatus = func_02012B38(gameData);
    effectMask = func_02013F6C(zoneId);
    if ((effectMask & 1) && func_02014468(fieldStatus)) {
        effectMask &= ~1;
        effectMask |= 2;
    }
    func_0201446C(fieldStatus, effectMask);
}

/* Updates map mode, subscreen type, matrix and field work for a zone. */
void func_02185A68(GameSystem *gameSystem, int zoneId)
{
    GameData *gameData;
    EventData *eventData;
    void *fieldWork;
    int subscreenType;

    gameData = func_020120F4(gameSystem);
    eventData = (EventData *)func_02012844(gameData);
    func_0201210C(gameSystem);
    if (func_02012B70(gameData) == 1 && func_02013D5C(zoneId) == 0)
        func_02014450(func_02012B38(gameData), 1);
    else
        func_02014450(func_02012B38(gameData), 0);

    if (func_02013CC8(zoneId) != 0) {
        func_020129B8(gameData, 2);
    } else if (func_02013CE0(zoneId) != 0 || func_02013DF0(zoneId) != 0 || func_02013D20(zoneId) != 0) {
        func_020129B8(gameData, 5);
    } else {
        if (func_02012B70(gameData) == 1 && func_020129AC(gameData) != 3)
            func_020129B8(gameData, 3);
        else if (func_02012B70(gameData) == 0 && func_020129AC(gameData) == 3)
            func_020129B8(gameData, 0);
        subscreenType = func_020129AC(gameData);
        if (subscreenType != 3 && subscreenType != 4 && subscreenType != 6)
            func_020129B8(gameData, 0);
    }

    func_02162408((int)eventData, zoneId, func_02012984(gameData));
    fieldWork = (void *)func_02012974(gameData);
    func_02159B94((int)fieldWork, func_02013B44(zoneId), zoneId, 0x8001);
    func_02159CC4(fieldWork, (int)gameSystem, 0x8001);
    func_02185A34(gameData, zoneId);
}

/*
 * Interface: func_021859F0 forwards the incoming r0 to func_02012964.
 */
void func_02185B70(GameSystem *gameSystem)
{
    GameData *gameData = func_020120F4(gameSystem);
    func_0201210C(gameSystem);
    func_021859F0(gameData);
}

void func_02185B88(FieldMap *fieldMap, unsigned int vanish)
{
    func_0216DAC8(func_021A3074(func_02188CB4(fieldMap)), vanish);
}

/* Looks up a zone in the arc 0x65 table and applies its entry to the field save. */
void func_02185B9C(GameData *gameData, int zoneId)
{
    unsigned count, i;
    void *fieldSave = func_02012EC4(gameData);
    void *arcHandle;
    int heapId = 0x8001;
    ZoneTableEntry *entries;

    func_0200B37C(fieldSave);
    arcHandle = func_020490F4(0x65, heapId);
    entries = func_02049250(arcHandle, 0, heapId);
    count = func_020493D4(arcHandle, 0) >> 3;
    for (i = 0; i < count; i++) {
        if (zoneId == entries[i].zoneId) {
            func_0200B394(fieldSave, entries[i].value);
            break;
        }
    }
    func_020307B0(entries);
    func_02049238(arcHandle);
}

/* Allocator with callback, copies the location and fills the link fields. */
GameEvent *func_02185BFC(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, int requestSession, int intrudeId)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02185D38, 0x30);
    MapChangeIntrudeWork *work = func_020124E8(event);

    work->location = *location;
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->fieldMap = fieldMap;
    work->requestSession = requestSession;
    work->intrudeId = intrudeId;
    return event;
}

/* Allocator with callback, copies the location and two link fields. */
GameEvent *func_02185C4C(GameSystem *gameSystem, FieldMap *fieldMap, Location *location)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_02185C8C, 0x30);
    MapChangeIntrudeWork *work = func_020124E8(event);

    work->location = *location;
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->fieldMap = fieldMap;
    return event;
}

int func_02185C8C(GameEvent *event, int *state, MapChangeIntrudeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    GameEvent *child;
    MapChangeWork *childWork;

    switch (state[0]) {
    case 0:
        func_020061E4(0x773);
        func_021CF498(func_02189A08(fieldMap), event, 0x24);
        state[0]++;
        break;
    case 1:
        child = func_020122C0(gameSystem, 0, func_02184504, 0x9c);
        childWork = func_020124E8(child);
        func_02184CEC(childWork, gameSystem);
        childWork->destination = work->location;
        childWork->exitType = 0;
        childWork->seasonFadeAllowed = 0;
        func_02012374(event, child);
        state[0]++;
        break;
    case 2:
        func_02012374(event, func_021BE9F0(gameSystem, fieldMap, 0, 0, 2));
        state[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Intrude warp event: starts the session, sets the intrude id, runs the arrival. */
int func_02185D38(GameEvent *event, int *state, MapChangeIntrudeWork *work)
{
    int busy;
    GameComm *gameComm;
    int isHost;
    int scriptId;
    IntrudeComm *comm;

    gameComm = func_02012138(work->gameSystem);
    switch (*state) {
    case 0:
        comm = func_02158344(gameComm);
        isHost = 0;
        busy = 0;
        if (comm != 0) {
            busy = func_0217C070(comm);
            if (func_02158630(gameComm) == 3)
                isHost = 1;
        }
        if (busy == 0 && func_021D2750(work->gameSystem) != 0) {
            scriptId = !isHost ? 0x279A : 0x279B;
            func_02158780(event, scriptId, 0, 0, func_02188C84(work->fieldMap));
            if (func_02158590(work->gameData) == 0)
                func_02026400(gameComm);
            *state = 1;
        } else {
            scriptId = !busy ? 0x279C : 0x279D;
            func_02158780(event, scriptId, 0, 0, func_02188C84(work->fieldMap));
            *state = 3;
        }
        break;
    case 1:
        if (func_02158590(work->gameData) == 0) {
            if (func_02026454(gameComm) != 0)
                break;
            func_02026484(gameComm);
        }
        if (work->requestSession == 1 && func_02158630(gameComm) != 3) {
            func_02158780(event, 0x279F, 0, 0, func_02188C84(work->fieldMap));
            *state = 3;
            break;
        }
        comm = func_02158344(gameComm);
        if (comm != 0) {
            func_0217574C(comm, 1);
            func_02175710(comm, work->intrudeId);
            if (work->requestSession == 1)
                func_02175B4C(comm, comm->requestInfo);
        }
        func_02012B64(work->gameData, func_02039338((int)func_02012B78(work->gameData, 1)));
        func_02012374(event, func_02185C4C(work->gameSystem, work->fieldMap, &work->location));
        *state = 2;
        break;
    case 2:
        comm = func_02158344(gameComm);
        if (comm != 0)
            func_0217574C(comm, 0);
        *state = 3;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Sets the escape location for a warp into a zone that keeps one. */
void func_02185EB0(GameData *gameData, const Location *destination)
{
    Location *entranceLocation = func_02012870(gameData);
    Location *startLocation = func_0201284C(gameData);
    Location escapeLocation;

    if (func_02014068(destination->zoneId)) {
        if ((s16)startLocation->zoneId == 0x88) {
            func_020128C0(gameData, entranceLocation);
        } else if (!func_02014068((s16)startLocation->zoneId)) {
            func_02014204(&escapeLocation, 0xd6);
            func_020128C0(gameData, &escapeLocation);
        }
    }
    if ((s16)startLocation->zoneId == 0x9e) {
        if (func_02013C50(destination->zoneId))
            func_020128C0(gameData, entranceLocation);
    }
}

/* Copies the special location into *out when the start zone allows it. */
void func_02185F18(GameData *gameData, Location *out)
{
    if (func_02013FEC(func_0201284C(gameData)->zoneId))
        *out = *func_02012894(gameData);
}

/* Object code 3 becomes 2, every other code becomes 0. */
void func_02185F48(GameData *gameData)
{
    PlayerWork *playerWork = func_020127A4(gameData);

    if (func_02012B28(playerWork) != 3)
        func_02012B2C(playerWork, 0);
    else
        func_02012B2C(playerWork, 2);
}

/* Puts the preset mail (writer name from message 0x3b of file 0xbe) into mail box slot 0. */
void func_02185F6C(GameData *gameData)
{
    struct MsgData *msgData = func_02045B38(0, 2, 0xbe, 1);
    struct Strbuf *writerName = func_02045EC0(msgData, 0x3b);
    struct Mail *mail;
    u16 writerChars[0x10];

    func_02045A38(writerName, writerChars, 0x10);
    mail = func_02008F08(1);
    func_02008F88(mail, writerChars);
    func_02008FA0(mail, 1);
    func_02008FA8(mail, 3);
    func_02008FB4(mail, 2);
    func_02008FBC(mail, 0x15);
    func_02008FD8(mail, d_02187DA4, 0);
    func_02008FD8(mail, d_02187DAC, 1);
    func_02008FD8(mail, d_02187DB4, 2);
    func_02008FC4(mail, 0x58F);
    func_0200903C(func_02008FEC(gameData), 0, 0, mail);
    func_020307B0(mail);
    func_02045808(writerName);
    func_02045C04(msgData);
}

void func_0218601C(GameData *gameData)
{
    void *saveControl = func_02012EBC(gameData);
    void *partySave = func_0201AD0C(saveControl);
    int season = func_02012984(gameData);

    func_0216A358(gameData, partySave, (u32 *)((u8 *)func_02008B14(saveControl) + 0x14), season);
}

void *func_0218604C(void)
{
    return func_02030734(0x8004, 0x1000, 0, d_02187EA0, 0xe35);
}

void *func_0218606C(void)
{
    return func_02030734(0x8004, 0x1000, 0, d_02187EA0, 0xe3a);
}

/*
 * An empty function (`bx lr` plus two bytes of padding) at the end of the
 * file.  func_021841C0 passes its address as the end of the range handed to
 * the ov230 routine func_021883CC, the same way it passes func_0218604C and
 * func_0218606C to func_021882A0 and func_02188318.
 */
void func_0218608C(void)
{
}
