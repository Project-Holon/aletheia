/*
 * file:     ircbattlemenu.c
 * unit:     yes
 * function: func_02196030, func_02196034, func_0219603C, func_021961A4, func_02196228, func_02196290, func_021962C4, func_021962F4, func_0219630C, func_02196454, func_0219649C, func_021964B0, func_02196538, func_021966B0, func_021966F0, func_02196768, func_021967BC, func_02196804, func_0219686C, func_021968D8, func_021968DC, func_02196944, func_02196974, func_02196A4C, func_02196A60, func_02196ACC, func_02196B24, func_02196B28, func_02196B7C, func_02196B90, func_02196B94, func_02196BF8, func_02196C68, func_02196CD8, func_02196D20, func_02196D24, func_02196D88, func_02196D94, func_02196E04, func_02196E70, func_02196EC8, func_02196ECC, func_02196F44, func_02196FF0, func_02196FFC, func_02197058, func_0219707C, func_02197190, func_0219728C, func_021973A0, func_0219749C, func_021974A0, func_02197534, func_021975D0, func_02197644, func_02197700, func_02197738, func_02197798, func_021977C0, func_02197800, func_021978AC, func_021978D4, func_021978DC, func_02197AAC, func_02197B5C, func_0219728C, func_021973A0, func_0219749C, func_021974A0, func_02197534, func_021975D0, func_02197644, func_02197700, func_02197738, func_02197798, func_021977C0, func_02197800, func_021978AC, func_021978D4, func_021978DC, func_02197AAC, func_02197B5C
 * address:  0x02196030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm  arm9
 *   func_02082D44  0x02082D44  arm  arm9
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_02041300  0x02041300  arm
 *   func_02045374  0x02045374  arm
 *   func_020456F8  0x020456F8  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021D40A0     0x021D40A0  data  ov021  a4
 *   d_021D40C0     0x021D40C0  data  ov021  a4
 *   d_021D40E0     0x021D40E0  data  ov021  a4
 *   d_021D4100     0x021D4100  data  ov021  a4
 *   d_021D4120     0x021D4120  data  ov021  a4
 *   d_021D4140     0x021D4140  data  ov021  a4
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_02021730  0x02021730  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02051C6C  0x02051C6C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049F78  0x02049F78  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   d_021DDAD4     0x021DDAD4  data  ov021  a2
 *   func_02051B84  0x02051B84  arm
 *   d_021D4070     0x021D4070  data  a4
 *   d_021D4014     0x021D4014  data  a4
 *   d_021D4024     0x021D4024  data  a4
 *   d_021D404C     0x021D404C  data  a4
 *   d_021DDB84     0x021DDB84  data  a4
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02040DA8  0x02040DA8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02155A94  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   func_02008428  0x02008428  thumb
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_02051C88  0x02051C88  arm
 *   d_021D3FE0     0x021D3FE0  data  ov021  a4
 *   d_021D3FF4     0x021D3FF4  data  ov021  a4
 *   d_021DDAF4     0x021DDAF4  data  ov021  a4
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   d_021D4080     0x021D4080  data  ov021  a4
 *   d_021D4034     0x021D4034  data  ov021  a4
 *   d_021DDB44     0x021DDB44  data  ov021  a4
 *   d_021D3F9C     0x021D3F9C  data  ov021  a1
 *   d_021D3FD8     0x021D3FD8  data  ov021  a4
 *   d_021D4004     0x021D4004  data  ov021  a4
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   d_021D3FC8     0x021D3FC8  data  ov021  a1
 *   d_021D3FB0     0x021D3FB0  data  ov021  a1
 *   d_021D3FA8     0x021D3FA8  data  ov021  a1
 *   d_021D3FA0     0x021D3FA0  data   a1
 *   d_021D3F8C     0x021D3F8C  data   a1
 *   d_021D3F94     0x021D3F94  data   a1
 *   d_021D3FC0     0x021D3FC0  data   a1
 *   d_021D3FD0     0x021D3FD0  data   a1
 *   d_021D3FB8     0x021D3FB8  data   a1
 *   d_021D3F98     0x021D3F98  data   a1
 *   d_021D3FA4     0x021D3FA4  data   a1
 *   d_021D3F90     0x021D3F90  data   a1
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_02027778  0x02027778  thumb
 *   func_02027CD8  0x02027CD8  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02041570  0x02041570  arm
 *   func_02012DD0  0x02012DD0  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_02027858  0x02027858  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_020433E0  0x020433E0  arm
 *   d_021DDB14     0x021DDB14  data   ov021  a4
 *   d_021D4090     0x021D4090  data   ov021  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   d_020A1448     0x020A1448  data   a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020056A0  0x020056A0  thumb
 *   d_021DDBC4     0x021DDBC4  data   ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_020121CC  0x020121CC  thumb
 *   func_02012204  0x02012204  thumb
 *   func_0202223C  0x0202223C  thumb
 *   func_02155A8C  0x02155A8C  thumb  ov010
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C5D0  0x0219C5D0  thumb  ov021
 *   func_0216D528  0x0216D528  thumb
 *   func_0219D488  0x0219D488  thumb  ov021
 *   func_0216D95C  0x0216D95C  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D8F0  0x0216D8F0  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0     0x021DDBE0  data  a4
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D480  0x0216D480  thumb  ov010
 *   d_021D4A50     0x021D4A50  data  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   d_021D5D6C     0x021D5D6C  data  a4
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D7D4  0x0216D7D4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   d_021D624C     0x021D624C  data  a4
 *   d_021D5F58     0x021D5F58  data  a4
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;

#include "ircbattlemenu_types.h"

/* Init data of one cell actor (CLACT_CreateActor). */
typedef struct ClactActorInit {
    u16 posX;
    u16 posY;
    u16 anim;
    u8 softPri;
    u8 bgPri;
} ClactActorInit;

/* Init data of a task menu (TaskMenuInitWork in app_taskmenu.c). */
typedef struct TaskMenuInit {
    u32 heapId;
    u8 itemNum;
    IrcBattleMenuItem *itemWork;
    u32 posType;
    u8 charPosX;
    u8 charPosY;
    u8 width;
    u8 height;
} TaskMenuInit;

typedef struct { u8 v[5]; } ActorRow5;
typedef struct { u8 v[3]; } ActorRow3;
typedef struct { u32 w[4]; } DispSetup;

/* Partial view: the full type is in ov010 musical_dressup_sys.c. */
typedef struct IrcBattleEntryWork {
    u8 padding0[0x4C];
    void *saveData;                     /* 0x4C */
    u8 padding50[8];
    u32 partyMode;                      /* 0x58 */
} IrcBattleEntryWork;

struct ProcWork;
struct DispVram;
struct DispConfig;
struct ClactSysInit;
struct GameSystem;
struct WifiList;
struct Bmp;
struct TaskNode;

extern struct ClactActor *func_0204B294(struct ClactUnit *unit, u32 charRes, u32 plttRes, u32 cellRes, const ClactActorInit *init, u16 drawArea, u16 heapId);
extern void func_0204B92C(struct ClactActor *actor, u32 flag);
extern void func_0204B3DC(struct ClactActor *actor, u32 flag);
extern void func_0204B688(struct ClactActor *actor, u32 mode);
extern void func_0204B3B4(struct ClactActor *actor);
extern void func_0204ADA4(u32 res);
extern void func_0204A8D4(u32 res);
extern void func_0204AFD8(u32 res);
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgData *msgData, u32 strId, struct StrBuf *dest);
extern struct TaskMenuWork *func_02027778(TaskMenuInit *init, struct TaskMenuRes *res);
extern int func_02027CD8(struct TaskMenuWork *menu, int pos);
extern void func_02045808(struct StrBuf *str);
extern void func_020286C4(struct AppKeyCursor *cursor, struct PrintStream *stream, struct BmpWin *win);
extern u32 func_0201CE30(struct PrintStream *stream);
extern void func_0201CE48(struct PrintStream *stream);
extern void func_0201CE38(struct PrintStream *stream);
extern void func_0201CE5C(struct PrintStream *stream, s32 wait);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4();
extern struct BmpWin *func_020450F0(u32 bgFrame, u32 posX, u32 posY, u32 width, u8 height, u8 palNo, u8 dir);
extern struct Bmp *func_02045770(struct BmpWin *win);
extern void func_02043B5C(struct Bmp *bmp, u8 color);
extern void func_0201DD78(u32 letter, u32 shadow, u32 back);
extern signed char func_02012FFC(void);
extern struct PrintStream *func_0201CCE4(struct BmpWin *win, u32 x, u32 y, struct StrBuf *str, struct GfFont *font, u32 wait, struct Tcbl *tcbl, u32 pri, u32 heapId, u32 back);
extern void func_0201C7A4(struct Bmp *bmp, s16 x, s16 y, struct StrBuf *str, struct GfFont *font);
extern void func_0201F73C(struct BmpWin *win, int transfer, int frameChar, int palNo);
extern void func_02045334(struct BmpWin *win);
extern void func_02045374(struct BmpWin *win);
extern void func_02041B6C(u32 frame);
extern void func_02041570(int frame, u16 value);
extern int func_02012DD0(struct GameData *gameData);
extern void func_0201F7A8(struct BmpWin *win, u32 transfer);
extern void func_020456F8(struct BmpWin *win);
extern int func_02012DAC(struct GameData *gameData);
extern void func_020414EC(u32 frame);
extern u32 func_020279E8(struct TaskMenuWork *menu);
extern u8 func_02027A04(const struct TaskMenuWork *menu);
extern void *func_02012EBC(struct GameData *gameData);
extern u32 func_020071F0(void);
extern void func_02027858(struct TaskMenuWork *menu);
extern void func_0204A648(void);
extern void func_0203064C(u32 parentHeap, u32 heapId, u32 size);
extern void *func_0203159C(struct ProcWork *proc, u32 size, u32 heapId);
extern void func_02082BCC(void *dest, u32 value, u32 size);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *vram);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204A48C(const struct ClactSysInit *init, const struct DispVram *vram, u32 heapId);
extern struct ClactUnit *func_0204B100(int actorMax, u8 pri, u32 heapId);
extern u32 func_020056A0(void (*task)(void), void *work, u32 pri);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern struct Tcbl *func_0203101C(u16 heapId, u16 tcbHeapId, u32 count, u32 workSize);
extern struct AppKeyCursor *func_02028590(u32 palNo, u32 isWin, u32 isFrame, u32 heapId);
extern struct PrintQue *func_0201C440(u32 heapId);
extern struct TaskMenuRes *func_02027F60(u16 bgFrame, u16 palNo, struct GfFont *font, struct PrintQue *printQue, u16 heapId);
extern void func_0202208C(u32 pattern0, u32 pattern1, u32 pattern2, u32 color, u32 div, u32 sync, u32 heapId);
extern struct GameSystem *func_02155A90(IrcBattleEntryWork *entry);
extern struct GameData *func_020120F4(const struct GameSystem *gameSys);
extern void func_0207D63C(u32 reg, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
extern void func_0203D34C(u32 type, u32 heapId);
extern struct WifiList *func_0201283C(const struct GameData *gameData);
extern u32 func_0201058C(struct WifiList *wifiList);
extern void func_02027974(struct TaskMenuWork *menu);
extern void func_02028178(struct TaskMenuWin *win);
extern void func_02040618(u32 frame, u32 op, u32 value);
extern void func_020310C4(struct Tcbl *tcbl);
extern u32 func_0201C4E4(struct PrintQue *printQue);
extern void func_0204A600(void);
extern u32 func_020121CC(struct GameSystem *gameSys);
extern u32 func_020221A4(void);
extern u32 func_02012204(const struct GameSystem *gameSys);
extern void func_0202223C(u32 screen, u32 value);
extern void func_02155A8C(IrcBattleEntryWork *entry, u32 mode);
extern void func_0202F038(struct TimeIcon *icon);
extern u32 func_020307B0(void *ptr);
extern int func_02028604(struct AppKeyCursor *cursor);
extern void func_02031140(struct Tcbl *tcbl);
extern void func_020403F4(u32 frame);
extern void func_0201C6EC(struct PrintQue *printQue);
extern void func_0201C4C0(struct PrintQue *printQue);
extern u32 func_020452E8(struct BmpWin *win);
extern void func_02028148(struct TaskMenuWin *win);
extern u32 func_02027FD8(struct TaskMenuRes *res);
extern void func_02030EAC(struct TaskNode *task);
extern u32 func_0204B1CC(struct ClactUnit *unit);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct ProcWork *proc);
extern void func_020306F0(u32 heapId);


extern const ActorRow5 d_021D3FC0;
extern const ActorRow5 d_021D3FD0;
extern const ActorRow5 d_021D3FB8;
extern const ActorRow3 d_021D3F98;
extern const ActorRow3 d_021D3FA4;
extern const ActorRow3 d_021D3F90;
extern u8 d_021DDB14[];
extern const DispSetup d_021D4090;
extern u8 d_020A1448[];
extern u8 d_021DDBC4[];

/* Window description of a button window (position and size in characters). */
typedef struct IrcBattleWinDesc {
    u32 posX;
    u32 posY;
    u32 width;
    u32 height;
} IrcBattleWinDesc;

/* BG layer template (eight settings words, not read here). */
typedef struct BgTemplate {
    u32 settings[8];
} BgTemplate;

/* Message ids of the buttons of a menu. */
typedef struct MsgIdRow2 { u32 id[2]; } MsgIdRow2;
typedef struct MsgIdRow4 { u32 id[4]; } MsgIdRow4;

/* Request passed to the cell actor animation: runs callback(work) when the animation ends. */
typedef struct ClactAnimEndHook {
    u16 type;
    IrcBattleMenuWork *work;
    void (*callback)(IrcBattleMenuWork *work);
} ClactAnimEndHook;

/* Palette resource data (rawData at +0xC). */
struct PaletteData {
    u32 format;
    u32 isExtended;
    u32 size;
    void *rawData;
};

struct PlttFade;
struct ArcHandle;
struct CommSys;
struct PartyInfo;

extern struct ArcHandle *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049238(struct ArcHandle *arc);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern u32 func_020409B4(u32 bgId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void DC_FlushRange(void *p, u32 size);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void func_0203FCA0(unsigned int bgId, const BgTemplate *tmpl, unsigned int type);
extern void func_020414AC(int bgId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern struct PlttFade *func_02021518(u32 heapId);
extern void func_0202155C(struct PlttFade *fade, u32 bank, u32 size, u32 heapId);
extern void func_020216D4(struct PlttFade *fade, u32 bank, u32 offset, u32 size);
extern void func_02021FD8(struct PlttFade *fade, u32 bank, u32 start, u32 count, u8 weight, u16 color);
extern u16 *func_02021730(struct PlttFade *fade, int bank);
extern void func_020215A0(struct PlttFade *fade, u32 bank);
extern u32 func_02021540(struct PlttFade *fade);
extern void func_0207E5D0(void *dst, u32 value, u32 size);
extern void func_0207E468(void *dst, u32 value, u32 size);
extern struct TimeIcon *func_0202EE8C(struct Tcbl *tcbl, struct BmpWin *win, u8 a, u8 b, u16 heapId);
extern u32 func_0201D304(struct StrBuf *str, struct GfFont *font, u32 a);
extern u32 func_0201D42C(struct StrBuf *str, struct GfFont *font);
extern void func_02051C6C(struct TouchSwitch *touchSw);
extern struct GfFont *func_0201D7EC(int a, int b, int c, int d, u32 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B68(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern u32 func_02049740(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern u32 func_02049990(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void *func_02049F78(struct ArcHandle *arc, u32 id, struct PaletteData **out, u32 heapId);
extern u32 func_0201F5DC(u32 a, u32 b, u32 c, u32 heapId);
extern struct TouchSwitch *func_02051B84(const u8 *table, void (*callback)(u32 index, int event, IrcBattleMenuWork *work), IrcBattleMenuWork *work, int heapId);
extern s32 func_02051C88(struct TouchSwitch *touchSw);
extern void func_0201DD68(void);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32 a, u32 b, u32 c);
extern u32 func_02045C04(struct MsgData *msgData);
extern u32 func_0201D83C(struct GfFont *font);
extern struct CommSys *func_02012138(const struct GameSystem *gameSys);
extern u32 func_02026454(struct CommSys *comm);
extern void func_02026400(struct CommSys *comm);
extern void *func_02155A94(IrcBattleEntryWork *entry);
extern struct PartyInfo *func_0200873C(void *sys);
extern int func_02008428(struct PartyInfo *info);
extern void *func_02012934(const struct GameData *gameData);
extern u32 func_0201AA1C(void *party);
extern void *func_0200BAC8(void *saveData);
extern u32 func_0200BBA8(void *data);
extern s32 func_0204A6C8(struct ArcHandle *arc, u32 a, u32 b, u32 c, u16 heapId);
extern s32 func_0204AC18(struct ArcHandle *arc, u32 a, u32 b, u32 c, u16 d, u16 e, u16 heapId);
extern s32 func_0204AF28(struct ArcHandle *arc, u32 a, u32 b, u32 heapId);
extern void func_0204BA00(struct ClactActor *actor, const ClactAnimEndHook *hook);
extern void func_0204B9A0(struct ClactActor *actor);
extern const BgTemplate d_021D40A0;
extern const BgTemplate d_021D40C0;
extern const BgTemplate d_021D40E0;
extern const BgTemplate d_021D4100;
extern const BgTemplate d_021D4120;
extern const BgTemplate d_021D4140;
extern const u16 d_021DDAD4[];
extern const MsgIdRow4 d_021D4070;
extern int d_021D4014[];
extern int d_021D4024[];
extern const u8 d_021D404C[];
extern IrcBattleWinDesc d_021DDB84[];
extern const MsgIdRow2 d_021D3FE0;
extern const u8 d_021D3FF4[];
extern IrcBattleWinDesc d_021DDAF4[];
extern const MsgIdRow4 d_021D4080;
extern const u8 d_021D4034[];
extern IrcBattleWinDesc d_021DDB44[];
extern const ActorRow3 d_021D3F9C;
extern const MsgIdRow2 d_021D3FD8;
extern const u8 d_021D4004[];
extern const ActorRow5 d_021D3FC8;
extern const ActorRow5 d_021D3FB0;
extern const ActorRow5 d_021D3FA8;
extern const ActorRow3 d_021D3FA0;
extern const ActorRow3 d_021D3F8C;
extern const ActorRow3 d_021D3F94;

void func_02196030(IrcBattleMenuSeqFunc *dest, IrcBattleMenuSeqFunc seq);
void func_02196034(IrcBattleMenuWork *work, IrcBattleMenuSeqFunc seq, u32 line);
void func_0219603C(IrcBattleMenuWork *work);
void func_021961A4(IrcBattleMenuWork *work, u32 bank, u32 rows);
void func_02196228(IrcBattleMenuWork *work, int isActive);
void func_02196290(IrcBattleMenuWork *work);
void func_021962C4(IrcBattleMenuWork *work);
void func_021962F4(IrcBattleMenuWork *work);
void func_0219630C(int count, u32 *msgIds, IrcBattleMenuWork *work, IrcBattleWinDesc *descs, int *centerX, int *centerY);
void func_02196454(IrcBattleMenuWork *work);
void func_0219649C(u32 index, int event, IrcBattleMenuWork *work);
void func_021964B0(u16 (*pltt)[16], const u16 *rowOffsets, int rows);
void func_02196538(IrcBattleMenuWork *work);
void func_021966B0(IrcBattleMenuWork *work, u32 screenId);
void func_021966F0(IrcBattleMenuWork *work);
void func_02196768(IrcBattleMenuWork *work);
void func_021967BC(IrcBattleMenuWork *work);
void func_02196804(IrcBattleMenuWork *work);
void func_0219686C(IrcBattleMenuWork *work);
void func_021968D8(IrcBattleMenuWork *work);
void func_021968DC(IrcBattleMenuWork *work);
void func_02196944(IrcBattleMenuWork *work);
int func_02196974(u32 index, IrcBattleMenuWork *work);
void func_02196A4C(IrcBattleMenuWork *work);
void func_02196A60(IrcBattleMenuWork *work);
void func_02196ACC(IrcBattleMenuWork *work);
void func_02196B24(IrcBattleMenuWork *work);
void func_02196B28(IrcBattleMenuWork *work);
void func_02196B7C(IrcBattleMenuWork *work);
void func_02196B90(IrcBattleMenuWork *work);
void func_02196B94(IrcBattleMenuWork *work);
int func_02196BF8(u32 index, IrcBattleMenuWork *work);
void func_02196C68(IrcBattleMenuWork *work);
void func_02196CD8(IrcBattleMenuWork *work);
void func_02196D20(IrcBattleMenuWork *work);
void func_02196D24(IrcBattleMenuWork *work);
void func_02196D88(IrcBattleMenuWork *work);
int func_02196D94(u32 index, IrcBattleMenuWork *work);
void func_02196E04(IrcBattleMenuWork *work);
void func_02196E70(IrcBattleMenuWork *work);
void func_02196EC8(IrcBattleMenuWork *work);
void func_02196ECC(IrcBattleMenuWork *work);
int func_02196F44(u32 index, IrcBattleMenuWork *work);
void func_02196FF0(IrcBattleMenuWork *work);
void func_02196FFC(IrcBattleMenuWork *work);
void func_02197058(IrcBattleMenuWork *work);
void func_0219707C(IrcBattleMenuWork *work);
void func_02197190(IrcBattleMenuWork *work);
void func_0219728C(IrcBattleMenuWork *work);
void func_021973A0(IrcBattleMenuWork *work);
void func_0219749C(IrcBattleMenuWork *work, u32 posX, u32 posY, u32 index, u32 anim);
void func_021974A0(IrcBattleMenuWork *work);
void func_02197534(IrcBattleMenuWork *work);
int func_021975D0(IrcBattleMenuWork *work);
void func_02197644(IrcBattleMenuWork *work, u32 isInstant);
void func_02197700(IrcBattleMenuWork *work);
void func_02197738(IrcBattleMenuWork *work);
void func_02197798(IrcBattleMenuWork *work);
void func_021977C0(IrcBattleMenuWork *work);
void func_02197800(IrcBattleMenuWork *work);
void func_021978AC(IrcBattleMenuWork *work);
void func_021978D4(void);
int func_021978DC(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param);
u32 func_02197AAC(u32 proc, u32 seq, u32 param, IrcBattleMenuWork *work);
int func_02197B5C(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param, IrcBattleMenuWork *work);

/* Stores the current sequence function; SetSeq passes work->seqFunc and the new function. */
void func_02196030(IrcBattleMenuSeqFunc *dest, IrcBattleMenuSeqFunc seq)
{
    *dest = seq;
}

/* Sets the next sequence function. The line argument is the call site's source line and is not used. */
void func_02196034(IrcBattleMenuWork *work, IrcBattleMenuSeqFunc seq, u32 line)
{
    func_02196030(&work->seqFunc, seq);
}

/* Sets up the six BG layers of the menu (main 0, 1 and sub 4 to 7) from their templates. */
void func_0219603C(IrcBattleMenuWork *work)
{
    BgTemplate mainBg0;
    BgTemplate mainBg1;
    BgTemplate subBg0;
    BgTemplate subBg1;
    BgTemplate subBg2;
    BgTemplate subBg3;

    mainBg0 = d_021D40A0;
    func_0203FCA0(0, &mainBg0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 1);
    mainBg1 = d_021D40C0;
    func_0203FCA0(1, &mainBg1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 1);
    subBg0 = d_021D40E0;
    func_0203FCA0(4, &subBg0, 0);
    func_02040588(4, 1);
    func_020409B4(4);
    subBg1 = d_021D4100;
    func_0203FCA0(5, &subBg1, 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);
    subBg2 = d_021D4120;
    func_0203FCA0(6, &subBg2, 0);
    func_02040588(6, 1);
    func_020409B4(6);
    subBg3 = d_021D4140;
    func_0203FCA0(7, &subBg3, 0);
    func_02040588(7, 1);
    func_020409B4(7);
}

/* Loads palette bank "bank" (1: BG, 3: OBJ) through the palette fade system, dimmed over "rows" rows of 16 colors. */
void func_021961A4(IrcBattleMenuWork *work, u32 bank, u32 rows)
{
    struct PlttFade *fade;
    u32 size;
    u16 *buf;

    fade = func_02021518(work->heapId);
    func_0202155C(fade, bank, 0x200, work->heapId);
    size = rows << 5;
    func_020216D4(fade, bank, 0, size);
    func_02021FD8(fade, bank, 0, (rows << 20) >> 16, 6, 0);
    buf = func_02021730(fade, bank);
    DC_FlushRange(buf, size);
    if (bank != 1) {
        if (bank == 3)
            func_0207E5D0(buf, 0, size);
    } else {
        func_0207E468(buf, 0, size);
    }
    func_020215A0(fade, bank);
    func_02021540(fade);
}

/* isActive 1: copies the saved palettes to 0x05000600 and 0x05000400 and fades both banks; 0: clears the saved copies. */
void func_02196228(IrcBattleMenuWork *work, int isActive)
{
    if (isActive) {
        func_02082D44((void *)0x05000600, work->subObjPlttCopy, 0x200);
        func_02082D44((void *)0x05000400, work->subBgPlttCopy, 0x200);
        func_021961A4(work, 3, 0xE);
        func_021961A4(work, 1, 9);
    } else {
        func_0207E5D0(work->subObjPlttCopy, 0, 0x1C0);
        func_0207E468(work->subBgPlttCopy, 0, 0x120);
    }
}

/* Deletes the time icon if present and creates a new one on the message window. */
void func_02196290(IrcBattleMenuWork *work)
{
    if (work->timeIcon != 0) {
        func_0202F038(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = func_0202EE8C(work->tcbl, work->msgWin, 15, 16, work->heapId);
}

/* Deletes the time icon and clears the message window. */
void func_021962C4(IrcBattleMenuWork *work)
{
    if (work->timeIcon != 0) {
        func_0202F038(work->timeIcon);
        work->timeIcon = 0;
    }
    func_0201F7A8(work->msgWin, 2);
    func_020456F8(work->msgWin);
    func_02041B6C(5);
}

/* Closes the message window. */
void func_021962F4(IrcBattleMenuWork *work)
{
    func_021962C4(work);
    func_020452E8(work->msgWin);
    work->msgWin = 0;
}

/*
 * Creates "count" button windows on BG 7, each holding the text msgIds[i]
 * centered on (centerX[i], centerY[i]) when those arrays are given.
 */
void func_0219630C(int count, u32 *msgIds, IrcBattleMenuWork *work, IrcBattleWinDesc *descs, int *centerX, int *centerY)
{
    int i;
    int x;
    int y;

    func_020414EC(7);
    work->menuWinCount = count;
    func_02049B40(0x17, 5, 4, 0x100, 0x20, work->heapId);
    for (i = 0; i < 4; i++) {
        if (work->menuWins[i] != 0) {
            func_020456F8(work->menuWins[i]);
            func_0201F7A8(work->menuWins[i], 2);
            func_020452E8(work->menuWins[i]);
        }
        work->menuWins[i] = 0;
    }
    for (i = 0; i < count; i++) {
        func_0201DD78(15, 2, 0);
        work->menuWins[i] = func_020450F0(7, (u8)descs[i].posX, (u8)descs[i].posY, (u8)descs[i].width, (u8)descs[i].height, 8, 0);
        func_02043B5C(func_02045770(work->menuWins[i]), 0);
        func_02045CAC(work->msgData, msgIds[i], work->message);
        if (centerX != 0) {
            x = centerX[i] - (func_0201D304(work->message, work->font, 0) >> 1);
        } else {
            x = 0;
        }
        if (centerY != 0) {
            y = centerY[i] - (func_0201D42C(work->message, work->font) >> 1);
        } else {
            y = 0;
        }
        func_0201C7A4(func_02045770(work->menuWins[i]), x, y, work->message, work->font);
        func_02045334(work->menuWins[i]);
        func_02045374(work->menuWins[i]);
    }
    if (work->touchSw != 0) {
        func_02051C6C(work->touchSw);
    }
    work->touchSw = 0;
    func_02041B6C(7);
    func_02040588(7, 1);
}

/* Deletes the touch switch and the button windows. */
void func_02196454(IrcBattleMenuWork *work)
{
    int i;

    if (work->touchSw != 0)
        func_02051C6C(work->touchSw);
    work->touchSw = 0;
    for (i = 0; i < 4; i++) {
        if (work->menuWins[i] != 0) {
            func_020456F8(work->menuWins[i]);
            func_02041B6C(5);
            func_0201F7A8(work->menuWins[i], 2);
            func_020452E8(work->menuWins[i]);
        }
        work->menuWins[i] = 0;
    }
    work->menuWinCount = 0;
}

/* Touch switch callback: for event 0 forwards the button index to work->touchFunc. */
void func_0219649C(u32 index, int event, IrcBattleMenuWork *work)
{
    if (event == 0 && work->touchFunc != 0 && work->touchFunc(index, work) != 0) {
        return;
    }
}

/* Adds rowOffsets[j] to the r, g and b value of color j of each of "rows" palette rows, clamped to 31. */
void func_021964B0(u16 (*pltt)[16], const u16 *rowOffsets, int rows)
{
    int i;
    int j;
    u16 color;
    u16 red;
    u16 green;
    u16 blue;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < 16; j++) {
            color = pltt[i][j];
            red = color & 0x1F;
            green = (color & 0x3E0) >> 5;
            blue = (color & 0x7C00) >> 10;
            red += rowOffsets[j];
            green += rowOffsets[j];
            blue += rowOffsets[j];
            if (red > 31) {
                red = 31;
            }
            if (green > 31) {
                green = 31;
            }
            if (blue > 31) {
                blue = 31;
            }
            pltt[i][j] = (blue << 10) + (red + (green << 5));
        }
    }
}

/* Loads the message data, font, menu graphics and palettes; the counterpart of func_02196768. */
void func_02196538(IrcBattleMenuWork *work)
{
    struct ArcHandle *arc;
    void *plttRes;
    struct PaletteData *plttData;

    work->isSaveDone = 0;
    work->message = func_020457B0(0x12C, work->heapId);
    work->font = func_0201D7EC(0x17, 0, 0, 0, work->heapId);
    work->msgData = func_02045B38(0, 2, 0x2E, work->heapId);
    arc = func_020490F4(0x1C, work->heapId);
    func_02049B68(arc, 1, 0, 0, 0, work->heapId);
    work->mainBgChar = func_02049740(arc, 6, 0, 0, 0, work->heapId);
    func_02049990(arc, 0xD, 0, 0, (u16)work->mainBgChar, 0, 0, work->heapId);
    func_02049238(arc);
    arc = func_020490F4(0x1D, work->heapId);
    func_02049B68(arc, 2, 4, 0, 0, work->heapId);
    plttRes = func_02049F78(arc, 2, &plttData, work->heapId);
    func_02082D44(plttData->rawData, work->menuPltt, 0x100);
    func_02082D44(plttData->rawData, work->menuPlttBright, 0x100);
    func_021964B0(work->menuPlttBright, d_021DDAD4, 8);
    func_020307B0(plttRes);
    func_02049B68(arc, 0, 0, 0, 0, work->heapId);
    work->subBgChar = func_02049740(arc, 4, 4, 0, 0, work->heapId);
    func_02049990(arc, 9, 4, 0, (u16)work->subBgChar, 0, 0, work->heapId);
    func_02049990(arc, 0xB, 6, 0, (u16)work->subBgChar, 0, 0, work->heapId);
    func_02049238(arc);
    work->winFrameChar = func_0201F5DC(5, 0xC, 0, work->heapId);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, work->heapId);
}

/* Loads sub BG 6 screen "screenId" from the menu graphics archive. */
void func_021966B0(IrcBattleMenuWork *work, u32 screenId)
{
    struct ArcHandle *arc;

    arc = func_020490F4(0x1D, work->heapId);
    func_02049990(arc, screenId, 6, 0, (u16)work->subBgChar, 0, 0, work->heapId);
    func_02049238(arc);
    func_02040588(6, 1);
}

/* Sequence: builds the top menu (four buttons, five actors). */
void func_021966F0(IrcBattleMenuWork *work)
{
    MsgIdRow4 msgIds = d_021D4070;

    func_021966B0(work, 0xB);
    func_0219707C(work);
    func_0219630C(4, msgIds.id, work, d_021DDB84, d_021D4014, d_021D4024);
    work->touchSw = func_02051B84(d_021D404C, func_0219649C, work, work->heapId);
    work->touchFunc = func_02196974;
    func_02196034(work, func_02196A4C, 0x340);
}

/* Frees what func_02196538 loaded and resets the BG layers. */
void func_02196768(IrcBattleMenuWork *work)
{
    u32 frameChar;

    func_0201DD68();
    func_02196454(work);
    func_02040DA8(5, 1, 0);
    frameChar = work->winFrameChar;
    func_0203FB44(5, (u16)frameChar, (u16)(frameChar >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(work->msgData);
    func_0201D83C(work->font);
    func_02045808(work->message);
    func_02040588(5, 0);
}

/* Sequence: once the screen fade is done, ends the sequences. */
void func_021967BC(IrcBattleMenuWork *work)
{
    if (func_020221A4()) {
        if (work->mode != 0xC) {
            if (func_02026454(func_02012138(func_02155A90(work->param))) == 0)
                func_02196034(work, 0, 0x361);
        } else {
            func_02196034(work, 0, 0x365);
        }
    }
}

/* Sequence: disables auto comm, starts the screen fade and closes the connection unless the user went back. */
void func_02196804(IrcBattleMenuWork *work)
{
    work->noAutoComm = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, work->heapId);
    if (work->mode != 0xC) {
        if (func_02026454(func_02012138(func_02155A90(work->param))) != 0) {
            func_02026400(func_02012138(func_02155A90(work->param)));
        }
    }
    func_02196034(work, func_021967BC, 0x37C);
}

/* Animation end hook of the top menu: picks the next sequence from the chosen mode. */
void func_0219686C(IrcBattleMenuWork *work)
{
    if (work->mode == 0xC) {
        func_02196034(work, func_02196804, 0x38C);
        return;
    }
    if (func_02008428(func_0200873C(func_02155A94(work->param))) == 1) {
        func_02196034(work, func_02197700, 0x38F);
        return;
    }
    if (work->mode - 6 <= 2) {
        func_02196034(work, func_02196804, 0x394);
        return;
    }
    func_02196034(work, func_02196A60, 0x397);
}

/* Sequence: waits for the actor animation. */
void func_021968D8(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the touched top menu button, then runs func_0219686C. */
void func_021968DC(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;
    u32 i;

    i = work->touchIndex;
    hook.type = 0;
    hook.work = work;
    hook.callback = func_0219686C;
    if (i == 5) {
        i = 0;
    } else if (i == 6) {
        i = 1;
    } else if (i == 7) {
        i = 3;
    }
    func_0204B92C(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    func_0204B9A0(work->menuActors[i]);
    func_02196034(work, func_021968D8, 0x3BF);
}

/* Sequence: after the "not enough Pokemon" message, closes it and returns to touch input. */
void func_02196944(IrcBattleMenuWork *work)
{
    if (func_021975D0(work) != 0 && func_02035C60() != 0) {
        func_021962F4(work);
        func_02196034(work, func_02196A4C, 0x3CB);
    }
}

/* Touch handler of the top menu: sets the mode from the pressed button. */
int func_02196974(u32 index, IrcBattleMenuWork *work)
{
    int taken = 0;

    work->touchIndex = index;
    switch (index) {
    case 0:
    case 5:
        func_020061E4(0x73B);
        func_02196034(work, func_021968DC, 0x3DE);
        taken = 1;
        work->mode = 1;
        break;
    case 1:
    case 6:
        if ((int)func_0201AA1C(func_02012934(work->gameData)) < 2) {
            func_02045CAC(work->msgData, 0x2C, work->message);
            func_02197644(work, 0);
            func_02196034(work, func_02196944, 0x3EA);
        } else {
            func_020061E4(0x73B);
            work->mode = 6;
            func_02196034(work, func_021968DC, 0x3F0);
            taken = 1;
        }
        break;
    case 2:
        func_020061E4(0x73B);
        work->mode = 8;
        func_02196034(work, func_021968DC, 0x3F6);
        taken = 1;
        break;
    case 3:
    case 7:
        func_020061E4(0x73B);
        work->mode = 7;
        func_02196034(work, func_021968DC, 0x3FD);
        taken = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        work->mode = 0xC;
        func_02196034(work, func_021968DC, 0x404);
        break;
    }
    return taken;
}

/* Sequence: updates the touch switch each frame once the screen fade is done. */
void func_02196A4C(IrcBattleMenuWork *work)
{
    if (func_020221A4() != 0) {
        func_02051C88(work->touchSw);
    }
}

/* Sequence: builds the kind menu (two buttons, three actors). */
void func_02196A60(IrcBattleMenuWork *work)
{
    MsgIdRow2 msgIds = d_021D3FE0;

    func_02197190(work);
    func_021966B0(work, 0xC);
    func_0219630C(2, msgIds.id, work, d_021DDAF4, 0, 0);
    work->touchSw = func_02051B84(d_021D3FF4, func_0219649C, work, work->heapId);
    work->touchFunc = func_02196BF8;
    func_02196034(work, func_02196FF0, 0x432);
}

/* Animation end hook of the kind menu: picks the next menu from the mode and the party check. */
void func_02196ACC(IrcBattleMenuWork *work)
{
    if (work->mode == 5) {
        if (func_0200BBA8(func_0200BAC8(work->param->saveData)) != 0) {
            func_02196034(work, func_02196E04, 0x443);
        } else {
            func_02196034(work, func_02196804, 0x446);
        }
    } else {
        func_02196034(work, func_02196C68, 0x44D);
    }
}

/* Sequence: waits for the actor animation. */
void func_02196B24(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the kind menu button, then runs func_02196ACC. */
void func_02196B28(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;
    int i;

    i = 0;
    if (work->mode == 5) {
        i = 1;
    }
    hook.type = 0;
    hook.work = work;
    hook.callback = func_02196ACC;
    func_0204B92C(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    func_0204B9A0(work->menuActors[i]);
    func_02196034(work, func_02196B24, 0x471);
}

/* Animation end hook of the kind menu back button: returns to the top menu. */
void func_02196B7C(IrcBattleMenuWork *work)
{
    func_02196034(work, func_021966F0, 0x47A);
}

/* Sequence: waits for the actor animation. */
void func_02196B90(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the pressed button, then runs func_02196B7C. */
void func_02196B94(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;

    hook.type = 0;
    hook.work = work;
    hook.callback = func_02196B7C;
    func_0204B92C(work->menuActors[work->touchIndex], 1);
    func_0204BA00(work->menuActors[work->touchIndex], &hook);
    func_0204B9A0(work->menuActors[work->touchIndex]);
    func_02196034(work, func_02196B90, 0x492);
}

/* Touch handler of the kind menu. */
int func_02196BF8(u32 index, IrcBattleMenuWork *work)
{
    int taken = 1;

    work->touchIndex = index;
    switch (index) {
    case 0:
        func_020061E4(0x73B);
        func_02196034(work, func_02196B28, 0x4A3);
        break;
    case 1:
        func_020061E4(0x73B);
        work->mode = 5;
        func_02196034(work, func_02196B28, 0x4A9);
        break;
    case 2:
        func_020061E4(0x73C);
        work->mode = 0xC;
        func_02196034(work, func_02196B94, 0x4AF);
        break;
    default:
        taken = 1;
        break;
    }
    return taken;
}

/* Sequence: builds the rule menu (four buttons, five actors). */
void func_02196C68(IrcBattleMenuWork *work)
{
    MsgIdRow4 msgIds = d_021D4080;

    func_0219728C(work);
    func_021966B0(work, 0xD);
    func_0219630C(4, msgIds.id, work, d_021DDB44, 0, 0);
    work->touchSw = func_02051B84(d_021D4034, func_0219649C, work, work->heapId);
    work->touchFunc = func_02196F44;
    func_02196034(work, func_02196FF0, 0x4CC);
}

/* Animation end hook of the party menu: picks the next menu from the party mode. */
void func_02196CD8(IrcBattleMenuWork *work)
{
    if (work->partyMode == 2) {
        if (work->mode == 5) {
            work->mode = 1;
            func_02196034(work, func_02196A60, 0x4DD);
        } else {
            func_02196034(work, func_02196C68, 0x4E1);
        }
    } else {
        func_02196034(work, func_02196804, 0x4E5);
    }
}

/* Sequence: waits for the actor animation. */
void func_02196D20(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the party menu button, then runs func_02196CD8. */
void func_02196D24(IrcBattleMenuWork *work)
{
    ActorRow3 actorIndex = d_021D3F9C;
    ClactAnimEndHook hook;
    int i;

    i = actorIndex.v[work->partyMode];
    hook.type = 0;
    hook.work = work;
    hook.callback = func_02196CD8;
    func_0204B92C(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    func_0204B9A0(work->menuActors[i]);
    func_02196034(work, func_02196D20, 0x504);
}

/* Sequence: updates the touch switch each frame. */
void func_02196D88(IrcBattleMenuWork *work)
{
    func_02051C88(work->touchSw);
}

/* Touch handler of the party menu: sets the party mode from the pressed button. */
int func_02196D94(u32 index, IrcBattleMenuWork *work)
{
    int taken = 0;

    work->touchIndex = index;
    switch (index) {
    case 1:
        func_020061E4(0x73B);
        work->partyMode = 0;
        func_02196034(work, func_02196D24, 0x524);
        taken = 1;
        break;
    case 0:
        func_020061E4(0x73B);
        taken = 1;
        work->partyMode = 1;
        func_02196034(work, func_02196D24, 0x52A);
        break;
    case 2:
        func_020061E4(0x73C);
        work->partyMode = 2;
        func_02196034(work, func_02196D24, 0x530);
        break;
    }
    return taken;
}

/* Sequence: builds the party menu (two buttons, three actors). */
void func_02196E04(IrcBattleMenuWork *work)
{
    MsgIdRow2 msgIds = d_021D3FD8;

    func_021973A0(work);
    func_021966B0(work, 0xD);
    func_0219630C(2, msgIds.id, work, d_021DDAF4, 0, 0);
    work->touchSw = func_02051B84(d_021D4004, func_0219649C, work, work->heapId);
    work->touchFunc = func_02196D94;
    func_02196034(work, func_02196D88, 0x54D);
}

/* Animation end hook of the rule menu: picks the next menu from the mode and the party check. */
void func_02196E70(IrcBattleMenuWork *work)
{
    if (work->mode == 0xC) {
        func_02196034(work, func_02196A60, 0x558);
    } else {
        if (func_0200BBA8(func_0200BAC8(work->param->saveData)) != 0) {
            func_02196034(work, func_02196E04, 0x55D);
        } else {
            func_02196034(work, func_02196804, 0x560);
        }
    }
}

/* Sequence: waits for the actor animation. */
void func_02196EC8(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the rule menu button for the chosen mode, then runs func_02196E70. */
void func_02196ECC(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;
    int i;

    switch (work->mode) {
    case 1:
        i = 0;
        break;
    case 2:
        i = 1;
        break;
    case 3:
        i = 2;
        break;
    case 4:
        i = 3;
        break;
    default:
        i = 4;
        break;
    }
    hook.type = 0;
    hook.work = work;
    hook.callback = func_02196E70;
    func_0204B92C(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    func_0204B9A0(work->menuActors[i]);
    func_02196034(work, func_02196EC8, 0x58F);
}

/* Touch handler of the rule menu: sets the mode (1 to 4, or 12 for back) from the pressed button. */
int func_02196F44(u32 index, IrcBattleMenuWork *work)
{
    int taken = 0;

    work->touchIndex = index;
    switch (index) {
    case 0:
        func_020061E4(0x73B);
        taken = 1;
        work->mode = 1;
        func_02196034(work, func_02196ECC, 0x5B1);
        break;
    case 1:
        func_020061E4(0x73B);
        work->mode = 2;
        func_02196034(work, func_02196ECC, 0x5B7);
        taken = 1;
        break;
    case 2:
        func_020061E4(0x73B);
        work->mode = 3;
        func_02196034(work, func_02196ECC, 0x5BD);
        taken = 1;
        break;
    case 3:
        func_020061E4(0x73B);
        work->mode = 4;
        func_02196034(work, func_02196ECC, 0x5C3);
        taken = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        work->mode = 0xC;
        func_02196034(work, func_02196ECC, 0x5C9);
        break;
    }
    return taken;
}

/* Sequence: updates the touch switch each frame. */
void func_02196FF0(IrcBattleMenuWork *work)
{
    func_02051C88(work->touchSw);
}

/* Loads the actor resources: character, palette and cell animation (stored in res[3], res[1], res[5]). */
void func_02196FFC(IrcBattleMenuWork *work)
{
    struct ArcHandle *arc;

    arc = func_020490F4(0x1D, work->heapId);
    work->res[3] = func_0204A6C8(arc, 5, 0, 1, work->heapId);
    work->res[1] = func_0204AC18(arc, 3, 1, 0, 0, 0xA, work->heapId);
    work->res[5] = func_0204AF28(arc, 7, 0x10, work->heapId);
    func_02049238(arc);
}

/* Deletes the menu actors. */
void func_02197058(IrcBattleMenuWork *work)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (work->menuActors[i] != 0) {
            func_0204B3B4(work->menuActors[i]);
            work->menuActors[i] = 0;
        }
    }
}

/* Creates the five actors of the top menu. */
void func_0219707C(IrcBattleMenuWork *work)
{
    ActorRow5 posX = d_021D3FC8;
    ActorRow5 posY = d_021D3FB0;
    ActorRow5 anim = d_021D3FA8;
    ClactActorInit init;
    int i;

    func_02197058(work);
    for (i = 0; i < 5; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = func_0204B294(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        func_0204B92C(work->menuActors[i], 0);
        func_0204B3DC(work->menuActors[i], 1);
        func_0204B688(work->menuActors[i], 1);
    }
}

/* Creates the three actors of the kind menu. */
void func_02197190(IrcBattleMenuWork *work)
{
    ActorRow3 posX = d_021D3FA0;
    ActorRow3 posY = d_021D3F8C;
    ActorRow3 anim = d_021D3F94;
    ClactActorInit init;
    int i;

    func_02197058(work);
    for (i = 0; i < 3; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = func_0204B294(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        func_0204B92C(work->menuActors[i], 0);
        func_0204B3DC(work->menuActors[i], 1);
        func_0204B688(work->menuActors[i], 1);
    }
}

/*
 * Creates the five actors of the main menu screen from the position and
 * animation rows d_021D3FC0 (x), d_021D3FD0 (y) and d_021D3FB8 (animation).
 */
void func_0219728C(IrcBattleMenuWork *work)
{
    ActorRow5 posX = d_021D3FC0;
    ActorRow5 posY = d_021D3FD0;
    ActorRow5 anim = d_021D3FB8;
    ClactActorInit init;
    int i;

    func_02197058(work);
    for (i = 0; i < 5; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = func_0204B294(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        func_0204B92C(work->menuActors[i], 0);
        func_0204B3DC(work->menuActors[i], 1);
        func_0204B688(work->menuActors[i], 1);
    }
}

/* Same as func_0219728C for the three actors of the second menu screen. */
void func_021973A0(IrcBattleMenuWork *work)
{
    ActorRow3 posX = d_021D3F98;
    ActorRow3 posY = d_021D3FA4;
    ActorRow3 anim = d_021D3F90;
    ClactActorInit init;
    int i;

    func_02197058(work);
    for (i = 0; i < 3; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = func_0204B294(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        func_0204B92C(work->menuActors[i], 0);
        func_0204B3DC(work->menuActors[i], 1);
        func_0204B688(work->menuActors[i], 1);
    }
}

/* An empty function: the decoration it would create was left out. */
void func_0219749C(IrcBattleMenuWork *work, u32 posX, u32 posY, u32 index, u32 anim)
{
}

/* Deletes all actors and releases the six cell resources (palette, character, cell animation). */
void func_021974A0(IrcBattleMenuWork *work)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (work->menuActors[i] != 0) {
            func_0204B3B4(work->menuActors[i]);
            work->menuActors[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (work->extraActors[i] != 0) {
            func_0204B3B4(work->extraActors[i]);
            work->extraActors[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (work->res[i] != 0) {
            func_0204ADA4(work->res[i]);
        }
    }
    for (; i < 4; i++) {
        if (work->res[i] != 0) {
            func_0204A8D4(work->res[i]);
        }
    }
    for (; i < 6; i++) {
        if (work->res[i] != 0) {
            func_0204AFD8(work->res[i]);
        }
    }
}

/* Opens the yes/no task menu (strings 26 and 27). */
void func_02197534(IrcBattleMenuWork *work)
{
    TaskMenuInit init;

    init.heapId = work->heapId;
    init.itemNum = 2;
    init.itemWork = work->yesNoItems;
    init.posType = 1;
    init.charPosX = 0x20;
    init.charPosY = 0xE;
    init.width = 0xD;
    init.height = 3;
    work->yesNoItems[0].str = func_020457B0(100, work->heapId);
    func_02045CAC(work->msgData, 26, work->yesNoItems[0].str);
    work->yesNoItems[0].msgColor = 0x39E3;
    work->yesNoItems[1].str = func_020457B0(100, work->heapId);
    func_02045CAC(work->msgData, 27, work->yesNoItems[1].str);
    work->yesNoItems[1].msgColor = 0x39E3;
    work->yesNoItems[0].type = 0;
    work->yesNoItems[1].type = 0;
    work->yesNoMenu = func_02027778(&init, work->taskMenuRes);
    func_02027CD8(work->yesNoMenu, 1);
    func_02045808(work->yesNoItems[0].str);
    func_02045808(work->yesNoItems[1].str);
}

/*
 * Runs the message print stream; returns 1 when no stream is active.
 */
int func_021975D0(IrcBattleMenuWork *work)
{
    if (work->printStream != 0) {
        if (work->msgWin != 0)
            func_020286C4(work->keyCursor, work->printStream, work->msgWin);
        switch (func_0201CE30(work->printStream)) {
        case 2:
            func_0201CE48(work->printStream);
            work->printStream = 0;
            break;
        case 1:
            if (func_02035C60() != 0) {
                func_020061E4(0x547);
                func_0201CE38(work->printStream);
            }
            break;
        case 0:
            if (func_02035C38() != 0)
                func_0201CE5C(work->printStream, 0);
            break;
        }
        return 0;
    }
    return 1;
}

/* Prints work->message in the message window, streamed or at once. */
void func_02197644(IrcBattleMenuWork *work, u32 isInstant)
{
    struct BmpWin *win;

    if (work->msgWin == 0) {
        work->msgWin = func_020450F0(5, 1, 3, 30, 4, 11, 1);
    }
    win = work->msgWin;
    func_02043B5C(func_02045770(win), 15);
    func_0201DD78(1, 2, 15);
    if (isInstant == 0) {
        work->printStream = func_0201CCE4(win, 0, 0, work->message, work->font, func_02012FFC(), work->tcbl, 2, work->heapId, 15);
    } else {
        func_0201C7A4(func_02045770(win), 0, 0, work->message, work->font);
        work->printStream = 0;
    }
    func_0201F73C(win, 1, (u16)work->winFrameChar, 12);
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(5);
}

/* Shows the save question (string 25). */
void func_02197700(IrcBattleMenuWork *work)
{
    func_02196228(work, 1);
    func_02041570(5, 0);
    func_02045CAC(work->msgData, 25, work->message);
    func_02197644(work, 0);
    func_02196034(work, func_021978AC, 0x761);
}

/* Runs the save; when it ends, goes on to the chosen battle mode. */
void func_02197738(IrcBattleMenuWork *work)
{
    if (func_02012DD0(work->gameData) == 2) {
        func_02196228(work, 0);
        func_0201F7A8(work->msgWin, 2);
        func_020456F8(work->msgWin);
        func_02041B6C(5);
        if (work->mode == 1) {
            func_02196034(work, func_02196A60, 0x776);
        } else {
            func_02196034(work, func_02196804, 0x779);
        }
        work->isSaveDone = 1;
    }
}

/* Waits for the "saving" message, then starts the save. */
void func_02197798(IrcBattleMenuWork *work)
{
    if (func_021975D0(work) != 0) {
        func_02012DAC(work->gameData);
        func_02196034(work, func_02197738, 0x78E);
    }
}

/* Waits for the message and a touch, then leaves the menu (mode 12). */
void func_021977C0(IrcBattleMenuWork *work)
{
    if (func_021975D0(work) != 0 && func_02035C60() != 0) {
        func_02196228(work, 0);
        func_020414EC(3);
        func_021962F4(work);
        work->mode = 12;
        func_02196034(work, func_02196A4C, 0x7a2);
    }
}

/* Handles the yes/no answer to the save question. */
void func_02197800(IrcBattleMenuWork *work)
{
    if (func_020279E8(work->yesNoMenu) != 0) {
        if (func_02027A04(work->yesNoMenu) == 0) {
            func_02012EBC(work->gameData);
            if (func_020071F0() != 0) {
                func_02045CAC(work->msgData, 0x2d, work->message);
                func_02197644(work, 0);
                func_02196034(work, func_021977C0, 0x7b9);
            } else {
                func_02045CAC(work->msgData, 0x1c, work->message);
                func_02197644(work, 1);
                func_02196290(work);
                func_02196034(work, func_02197798, 0x7bf);
            }
        } else {
            func_02196228(work, 0);
            func_020414EC(3);
            func_021962F4(work);
            work->mode = 12;
            func_02196034(work, func_02196A4C, 0x7c7);
        }
        func_02027858(work->yesNoMenu);
        work->yesNoMenu = 0;
    }
}

/* Waits for the save question, then opens the yes/no menu. */
void func_021978AC(IrcBattleMenuWork *work)
{
    if (func_021975D0(work) != 0) {
        func_02197534(work);
        func_02196034(work, func_02197800, 0x7DC);
    }
}

/* VBlank task: tail call into the ARM9 cell actor system. */
void func_021978D4(void)
{
    func_0204A648();
}

/* Proc init: heap, display, cell actors, print system, first sequence. */
int func_021978DC(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param)
{
    IrcBattleMenuWork *work;

    func_0203064C(1, 0x1f, 0x18000);
    work = func_0203159C(proc, 0x308, 0x1f);
    func_02082BCC(work, 0, 0x308);
    work->heapId = 0x1f;
    func_0203F8F4(work->heapId);
    func_02045088(work->heapId);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021DDB14);
    {
        DispSetup setup = d_021D4090;
        func_0203FC28((struct DispConfig *)(&setup));
    }
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct ClactSysInit *)d_020A1448, (const struct DispVram *)d_021DDB14, work->heapId);
    work->clactUnit = func_0204B100(0x28, 0, work->heapId);
    work->vblankTask = func_020056A0(func_021978D4, work, 0);
    func_0219603C(work);
    func_02196538(work);
    work->subObjPlttCopy = func_02030734(work->heapId, 0x200, 0, (const char *)d_021DDBC4, 0x829);
    work->subBgPlttCopy = func_02030734(work->heapId, 0x200, 0, (const char *)d_021DDBC4, 0x82A);
    work->tcbl = func_0203101C(work->heapId, work->heapId, 2, 0);
    work->keyCursor = func_02028590(0xf, 0, 1, work->heapId);
    work->printQue = func_0201C440(work->heapId);
    work->taskMenuRes = func_02027F60(5, 9, work->font, work->printQue, work->heapId);
    func_02196FFC(work);
    func_0219749C(work, 0x39, 0x9a, 0, 10);
    func_0219749C(work, 0xc8, 0x26, 1, 11);
    func_0202208C(0, 1, 1, 0, 6, 1, work->heapId);
    func_02196034(work, func_021966F0, 0x83B);
    work->param = (struct IrcBattleEntryWork *)param;
    work->gameData = func_020120F4(func_02155A90((IrcBattleEntryWork *)work->param));
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    func_0203D34C(0, work->heapId);
    func_02043534(0x13);
    func_020435F4(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}

/* Proc main: runs the current sequence until it clears seqFunc. */
u32 func_02197AAC(u32 proc, u32 seq, u32 param, IrcBattleMenuWork *work)
{
    u32 ret;
    IrcBattleMenuSeqFunc seqFunc;

    seqFunc = work->seqFunc;
    ret = 1;
    func_0201058C(func_0201283C(work->gameData));
    if (seqFunc != 0) {
        seqFunc(work);
        ret = 0;
    }
    if (work->yesNoMenu != 0) {
        func_02027974(work->yesNoMenu);
    }
    if (work->taskMenuWin != 0) {
        func_02028178(work->taskMenuWin);
    }
    func_02040618(4, 3, work->bgAnimCount);
    work->bgAnimCount = work->bgAnimCount - 1;
    func_020310C4(work->tcbl);
    func_0201C4E4(work->printQue);
    func_0204A600();
    if (work->noAutoComm == 0) {
        func_020121CC(func_02155A90((IrcBattleEntryWork *)work->param));
    }
    if (func_020221A4() != 0) {
        if (func_02012204(func_02155A90((IrcBattleEntryWork *)work->param)) != 0) {
            work->mode = 12;
            ret = 1;
            func_0202223C(0, 0);
            func_0202223C(1, 0);
        }
    }
    return ret;
}

/* Proc exit: hands the result to the entry event and frees everything. */
int func_02197B5C(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param, IrcBattleMenuWork *work)
{
    if (!func_020221A4()) {
        return 0;
    }
    func_02196768(work);
    func_02155A8C(param, work->mode);
    param->partyMode = work->partyMode;
    if (work->timeIcon != 0) {
        func_0202F038(work->timeIcon);
        work->timeIcon = 0;
    }
    func_020307B0(work->subObjPlttCopy);
    func_020307B0(work->subBgPlttCopy);
    func_021974A0(work);
    if (work->printStream != 0) {
        func_0201CE48(work->printStream);
    }
    func_02028604(work->keyCursor);
    func_02031140(work->tcbl);
    func_020403F4(7);
    func_0201C6EC(work->printQue);
    func_0201C4C0(work->printQue);
    if (work->msgWin != 0) {
        func_020452E8(work->msgWin);
    }
    if (work->yesNoMenu != 0) {
        func_02027858(work->yesNoMenu);
        work->yesNoMenu = 0;
    }
    if (work->taskMenuWin != 0) {
        func_02028148(work->taskMenuWin);
    }
    func_02027FD8(work->taskMenuRes);
    func_02030EAC((struct TaskNode *)work->vblankTask);
    func_0204B1CC(work->clactUnit);
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
    func_020315D4(proc);
    func_020306F0(0x1f);
    return 1;
}
