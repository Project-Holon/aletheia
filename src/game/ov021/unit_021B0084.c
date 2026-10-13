/*
 * file:     unit_021B0084.c
 * unit:     yes
 * function: func_021B0084, func_021B010C, func_021B0130, func_021B015C, func_021B01B8, func_021B01DC, func_021B024C, func_021B02C8, func_021B0344, func_021B0394, func_021B03BC, func_021B03E4, func_021B0480, func_021B04C0, func_021B04D8, func_021B0530, func_021B05AC, func_021B0624, func_021B0630, func_021B063C, func_021B0730, func_021B07E0, func_021B0808, func_021B090C, func_021B0960, func_021B09D8, func_021B09EC, func_021B0A40, func_021B0A60, func_021B0A88, func_021B0AB0, func_021B0ADC, func_021B0B08, func_021B0BAC, func_021B0CEC, func_021B0D14, func_021B0D74, func_021B0DF0, func_021B0E74, func_021B0EDC, func_021B0EE8, func_021B0EF4, func_021B0FF0, func_021B1008, func_021B10A4, func_021B10D0, func_021B10DC, func_021B10E8, func_021B10F4, func_021B1100, func_021B11D8, func_021B120C, func_021B1234, func_021B1240, func_021B1268, func_021B12B0, func_021B1334, func_021B13E0, func_021B13EC, func_021B13F8, func_021B1424, func_021B143C, func_021B14DC, func_021B14E8, func_021B14F4, func_021B1550, func_021B15B8, func_021B15C8, func_021B1604, func_021B162C
 * address:  0x021B0084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B0084 (lane L135, message window and menu command handlers (calls field_msgbg.c); original unknown).
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159168  0x02159168  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_0215A864  0x0215A864  thumb  ov010
 *   func_0215A990  0x0215A990  thumb  ov010
 *   func_0215A954  0x0215A954  thumb  ov010
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_0215A77C  0x0215A77C  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_0215A654  0x0215A654  thumb  ov010
 *   func_02190FA0  0x02190FA0  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02191008  0x02191008  thumb  ov021
 *   func_0215A630  0x0215A630  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   func_021910C0  0x021910C0  thumb  ov021
 *   func_02191084  0x02191084  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02191184  0x02191184  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021911B4  0x021911B4  thumb  ov021
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02188D48  0x02188D48  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02188D4C  0x02188D4C  thumb  ov021
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D9390     0x021D9390  data
 *   d_021D939C     0x021D939C  data
 *   func_02048B0C  0x02048B0C  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_0219131C  0x0219131C  thumb  ov021
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0215A66C  0x0215A66C  thumb  ov010
 *   func_02191348  0x02191348  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215A678  0x0215A678  thumb  ov010
 *   func_02191388  0x02191388  thumb
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_02008550  0x02008550  thumb
 *   func_0202A310  0x0202A310  thumb
 *   func_021916E0  0x021916E0  thumb  ov021
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_02191830  0x02191830  thumb  ov021
 *   func_021918DC  0x021918DC  thumb  ov021
 *   func_0219196C  0x0219196C  thumb  ov021
 *   func_021919AC  0x021919AC  thumb  ov021
 *   func_02191978  0x02191978  thumb  ov021
 *   func_02191BE8  0x02191BE8  thumb  ov021
 *   func_02191B14  0x02191B14  thumb  ov021
 *   func_02158F84  0x02158F84  thumb  ov010
 *   func_02158F80  0x02158F80  thumb  ov010
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02191A04  0x02191A04  thumb  ov021
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02191A10  0x02191A10  thumb  ov021
 *   func_02192628  0x02192628  thumb  ov021
 *   func_021926D8  0x021926D8  thumb  ov021
 *   func_0219270C  0x0219270C  thumb  ov021
 *   func_0219272C  0x0219272C  thumb  ov021
 *   func_02192570  0x02192570  thumb  ov021
 *   func_0219269C  0x0219269C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02191134  0x02191134  thumb  ov021
 *   func_02191794  0x02191794  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_021904DC  0x021904DC  thumb  ov021
 */

#include "../arm9/script_vm_types.h"
#include "field_msgbg_types.h"

struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldCamera;
struct FieldPlayer;
struct G3dCamera;
struct GameEvent;
struct ScriptWork;
struct ScrcmdWork;
struct WordSet;
struct MsgData;
struct Strbuf;
struct TimeIcon;
struct Mmdl;
struct MmdlSys;
struct MoneyData;
struct MainTaskList;

typedef struct ScrcmdWork ScrcmdWork;
typedef struct ScriptWork ScriptWork;
typedef struct GameEvent GameEvent;

typedef struct MtxFx33 {
    s32 m[9];
} MtxFx33;

typedef struct MtxFx43 {
    s32 m[12];
} MtxFx43;

/* Script command that waits: returns 1 when the command is done. */
typedef int (*ScrcmdWaitFn)(ScriptVm *vm, ScrcmdWork *cmdWork);

/* Game event procedure: (event, step counter, work block of the event). */
typedef int (*GameEventProc)(GameEvent *event, int *seq, void *work);

/* Message window kinds, the check flags of the script work. */
enum {
    SCRIPT_FLAG_INFO_SYS_WIN = 1,
    SCRIPT_FLAG_TALK_WIN = 2,    /* talk balloon */
    SCRIPT_FLAG_PLAIN_WIN = 3,
    SCRIPT_FLAG_BG_WIN = 4,
    SCRIPT_FLAG_SUB_WIN = 5,
    SCRIPT_FLAG_SP_WIN = 6,
    SCRIPT_FLAG_AUTO_MODE = 9
};

/* Message system and field map of the running script (SCRIPT_WORK_ResetFieldParam). */
typedef struct ScriptFieldParam {
    FieldMsgBg *msgBg;              /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
} ScriptFieldParam;

/* Work of the yes/no event (0xC bytes). */
typedef struct YesNoEventWork {
    ScrcmdWork *cmdWork;            /* 0x00 */
    u16 *result;                    /* 0x04, script variable that receives 0 (yes) or 1 (no) */
    FieldMenuFunc *menu;            /* 0x08 */
} YesNoEventWork;

/* Work of the list menu event (8 bytes). */
typedef struct MenuEventWork {
    ScrcmdWork *cmdWork;            /* 0x00 */
    int allowCancel;                /* 0x04 */
} MenuEventWork;

/* Argument of the window cleanup callbacks: the work sits in the second word. */
typedef struct ScrcmdWorkRef {
    void *reserved;                 /* 0x00 */
    ScrcmdWork *cmdWork;            /* 0x04 */
} ScrcmdWorkRef;

/* Argument of the auto mode cleanup callback: the script work sits in the third word. */
typedef struct ScriptWorkRef {
    void *reserved[2];              /* 0x00 */
    ScriptWork *scriptWork;         /* 0x08 */
} ScriptWorkRef;

/* Talk balloon placement kept in the command work (0x28 bytes). */
typedef struct BalloonWinWork {
    u16 objId;                      /* 0x00, map object the balloon follows (0xFF: player) */
    u16 talkIndex;                  /* 0x02, balloon slot passed to FIELD_MSGBG_AddTalkWin */
    VecFx32 pos;                    /* 0x04, mmdlPos + offset: the point the tail aims at */
    VecFx32 mmdlPos;                /* 0x10, last position of the map object */
    VecFx32 offset;                 /* 0x1C, offset from the object to the balloon */
} BalloonWinWork;

typedef struct MyStatus {
    u8 data[0x20];
} MyStatus;

typedef struct PlayerWork {
    u8 reserved[0x20];
    MyStatus myStatus;              /* 0x20 */
} PlayerWork;

extern struct Mmdl *func_021A3074(struct FieldPlayer *fieldPlayer);
extern u16 func_0216D5F8(struct Mmdl *mmdl);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern ScriptWork *func_0215A5F4(ScrcmdWork *cmdWork);
extern ScriptFieldParam *func_02158F58(ScriptWork *scriptWork);
extern u16 func_02159B10(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 func_0215A5CC(ScrcmdWork *cmdWork);
extern struct GameSystem *func_0215A5DC(ScrcmdWork *cmdWork);
extern void func_0215897C(ScriptWork *scriptWork, GameEvent *event);
extern u16 *func_02159AE8(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 func_0216D588(struct Mmdl *mmdl);
extern struct GameData *func_0215A5E4(ScrcmdWork *cmdWork);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern u16 func_02011330(ScriptVm *vm);
extern void func_02159144(int flag);
extern void func_020113D0(ScriptVm *vm, ScrcmdWaitFn waitFn);
extern void func_02159168(int flag);
extern void func_020061E4(u32 seNo);
extern GameEvent *func_020122C0(struct GameSystem *gameSystem, GameEvent *parent, GameEventProc proc, unsigned int workSize);
extern void *func_020124E8(GameEvent *event);
extern struct WordSet *func_02158F74(ScriptWork *scriptWork);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 dispType, u32 codeType);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern void func_0215A684(ScrcmdWork *cmdWork, unsigned short count);
extern int func_0215A690(ScrcmdWork *cmdWork);
extern FieldMsgBg *func_02188C54(struct FieldMap *fieldMap);
extern FieldMenuFunc *func_02190BE4(FieldMsgBg *msgBg, u32 cursorPos);
extern int func_02190C78(FieldMenuFunc *menu);
extern int func_021909BC(FieldMenuFunc *menu);
extern void func_0215A864(ScrcmdWork *cmdWork);
extern int func_0215A990(ScrcmdWork *cmdWork);
extern int func_0215A954(ScrcmdWork *cmdWork);
extern u16 *func_02158FE0(ScriptWork *scriptWork, struct GameData *gameData, unsigned int varId);
extern u32 func_0215A77C(ScrcmdWork *cmdWork, u32 x, u32 y, u32 cursorPos, u32 cancelable, u32 alignRight, u16 *result, struct WordSet *wordSet, struct MsgData *msgData);
extern struct MsgData *func_0215A60C(ScrcmdWork *cmdWork);
extern struct Strbuf *func_02158F78(ScriptWork *scriptWork);
extern struct Strbuf *func_02158F7C(ScriptWork *scriptWork);
extern void func_0215A7F0(ScrcmdWork *cmdWork, int msgId, int helpMsgId, int param, struct Strbuf *str, struct Strbuf *tmp);
extern int func_02159190(int flag);
extern void *func_0215A61C(ScrcmdWork *cmdWork);
extern void func_02191164(FieldSysWin *sysWin);
extern u32 func_0215A654(ScrcmdWork *cmdWork);
extern FieldSysWin *func_02190FA0(FieldMsgBg *msgBg, struct MsgData *msgData, u32 y);
extern void func_0215A660(ScrcmdWork *cmdWork, u32 windowState);
extern u32 func_0215A614(ScrcmdWork *cmdWork, void *msgWin);
extern int func_02191008(FieldSysWin *sysWin);
extern struct TimeIcon *func_0215A630(ScrcmdWork *cmdWork);
extern void func_0202F038(struct TimeIcon *timeIcon);
extern void func_0215A624(ScrcmdWork *cmdWork, struct TimeIcon *timeIcon);
extern u32 func_021910C0(FieldSysWin *sysWin);
extern void func_02191084(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
extern void func_02045CAC(struct MsgData *msgData, u32 msgId, struct Strbuf *dest);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dest, struct Strbuf *src);
extern void func_02191184(FieldSysWin *sysWin, u32 x, int y, struct Strbuf *str);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern struct BmpWin *func_021911B4(FieldSysWin *sysWin);
extern struct MainTaskList *func_020056BC(void);
extern struct TimeIcon *func_0202EE30(struct MainTaskList *taskList, struct BmpWin *bmpWin, u32 x, u32 y, u32 heapId);
extern PlayerWork *func_020127A4(struct GameData *gameData);
extern FieldMsgWin *func_02188D48(struct FieldMap *fieldMap);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern struct MoneyData *func_02012F08(struct GameData *gameData);
extern u32 func_0200C274(struct MoneyData *moneyData);
extern int func_02190728(FieldMsgWin *msgWin);
extern FieldMsgWin *func_02190708(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
extern void func_02188D4C(struct FieldMap *fieldMap, FieldMsgWin *msgWin);
extern void func_02190758(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
extern void func_02045808(struct Strbuf *str);
extern u32 func_02045C04(struct MsgData *msgData);
extern void func_02190788(FieldMsgWin *msgWin);
extern void func_02048AD0(struct G3dCamera *camera);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *out);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0207CCA4(const VecFx32 *vec, VecFx32 *out);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0206DF3C(VecFx32 *pos, u32 *x, u32 *z);
extern void func_02048B0C(struct G3dCamera *camera, VecFx32 *out);
extern void func_0207BCA0(VecFx32 *eye, VecFx32 *up, VecFx32 *target, MtxFx43 *out);
extern void func_02082B60(MtxFx43 *src, MtxFx33 *dest);
extern void func_0207B0A4(MtxFx33 *src, MtxFx33 *dest);
extern void func_0207B51C(VecFx32 *vec, MtxFx33 *mtx, VecFx32 *out);
extern void func_0216D88C(const struct Mmdl *mmdl, VecFx32 *out);
extern u32 func_021912F8(FieldTalkWin *talkWin);
extern int func_021912D8(FieldTalkWin *talkWin);
extern int func_0219131C(FieldTalkWin *talkWin);
extern FieldTalkWin *func_0219129C(FieldMsgBg *msgBg, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
extern struct MmdlSys *func_0215A5EC(ScrcmdWork *cmdWork);
extern BalloonWinWork *func_0215A63C(ScrcmdWork *cmdWork);
extern struct Mmdl *func_0216DE94(struct MmdlSys *mmdlSys, u32 objId);
extern struct FieldCamera *func_02188C58(struct FieldMap *fieldMap);
extern struct G3dCamera *func_0218EC2C(struct FieldCamera *fieldCamera);
extern u8 func_0215A66C(ScrcmdWork *cmdWork);
extern u32 func_02191348(FieldTalkWin *talkWin, struct Strbuf *str);
extern void func_02082BCC(void *dest, int value, int size);
extern void func_0215A678(ScrcmdWork *cmdWork, u8 windowKind);
extern u32 func_02191388(FieldTalkWin *talkWin);
extern struct Mmdl *func_02158F90(ScriptWork *scriptWork);
extern u8 func_02008550(const MyStatus *myStatus);
extern void func_0202A310(int key1, int key2, struct Strbuf *dest, u32 heapId);
extern u32 func_021916E0(FieldPlainWin *plainWin);
extern void func_021915EC(FieldPlainWin *plainWin);
extern FieldPlainWin *func_02191558(FieldMsgBg *msgBg, struct MsgData *msgData, u32 winType, u16 x, u16 y, u16 width, u16 height);
extern void func_021916A8(FieldPlainWin *plainWin, u32 x, u16 y, struct Strbuf *str);
extern int func_021915B4(FieldPlainWin *plainWin);
extern void func_02191830(FieldMsgBg *msgBg, struct Strbuf *str, u8 *width, u8 *height);
extern void func_021918DC(FieldMsgBg *msgBg, struct Strbuf *str, u32 id, u8 x, u8 y, u8 width, u8 height);
extern void func_0219196C(FieldMsgBg *msgBg, u32 id);
extern int func_021919AC(FieldMsgBg *msgBg);
extern void func_02191978(FieldMsgBg *msgBg);
extern u32 func_02191BE8(FieldBgWin *bgWin, struct Strbuf *str);
extern void func_02191B14(FieldBgWin *bgWin);
extern struct GfFont *func_02158F84(ScriptWork *scriptWork);
extern void func_02158F80(ScriptWork *scriptWork, struct GfFont *font);
extern u32 func_0201D83C(struct GfFont *font);
extern FieldBgWin *func_02191A04(FieldMsgBg *msgBg, int winType);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern FieldBgWin *func_02191A10(FieldMsgBg *msgBg, u32 winType, struct GfFont *font);
extern void func_02192628(FieldSpWin *spWin);
extern int func_021926D8(FieldSpWin *spWin);
extern u32 func_0219270C(FieldMsgBg *msgBg, struct Strbuf *str, int margin);
extern u32 func_0219272C(FieldMsgBg *msgBg, struct Strbuf *str, u32 margin);
extern FieldSpWin *func_02192570(FieldMsgBg *msgBg, u32 frameType, u32 x, u16 y, u16 width, u16 height);
extern void func_0219269C(FieldSpWin *spWin, u16 x, u16 y, struct Strbuf *str);
u32 func_020362DC(void);
void func_02191134(FieldSysWin *sysWin);
void func_02191794(FieldPlainWin *plainWin);
void func_021914CC(FieldTalkWin *talkWin);
extern void func_021904DC(FieldMsgBg *msgBg, u8 autoMode);
int func_021B0084(GameEvent *event, int *seq, void *work);
GameEvent *func_021B010C(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result);
int func_021B0130(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B015C(GameEvent *event, int *seq, void *work);
GameEvent *func_021B01B8(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, int allowCancel);
int func_021B01DC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B024C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B02C8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0344(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0394(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B03BC(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B03E4(ScrcmdWork *cmdWork, u32 windowKind);
void func_021B0480(ScrcmdWork *cmdWork);
int func_021B04C0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B04D8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0530(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B05AC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0624(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0630(ScrcmdWorkRef *ref);
int func_021B063C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0730(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B07E0(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B0808(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera);
void func_021B090C(VecFx32 *offset, struct G3dCamera *camera);
void func_021B0960(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind);
void func_021B09D8(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind);
void func_021B09EC(int windowState, int *talkIndex, int *tailType);
int func_021B0A40(struct Mmdl *playerMmdl, const VecFx32 *targetPos);
int func_021B0A60(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B0A88(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B0AB0(ScrcmdWork *cmdWork);
void func_021B0ADC(ScrcmdWork *cmdWork, FieldMsgBg *msgBg, int talkIndex, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
void func_021B0B08(ScrcmdWork *cmdWork, int forceUpdate);
int func_021B0BAC(ScrcmdWork *cmdWork, u16 objId, u16 msgFileId, u16 msgId, u16 windowKind, int winType);
int func_021B0CEC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0D14(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0D74(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0DF0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0E74(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0EDC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0EE8(ScrcmdWorkRef *ref);
int func_021B0EF4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B0FF0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1008(ScriptVm *vm, ScrcmdWork *cmdWork, int winType);
void func_021B10A4(ScrcmdWork *cmdWork);
int func_021B10D0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B10DC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B10E8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B10F4(ScrcmdWorkRef *ref);
int func_021B1100(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B11D8(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B120C(ScrcmdWork *cmdWork);
int func_021B1234(ScrcmdWorkRef *ref);
int func_021B1240(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B1268(ScrcmdWork *cmdWork);
int func_021B12B0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1334(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B13E0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B13EC(ScrcmdWorkRef *ref);
void func_021B13F8(ScrcmdWork *cmdWork);
int func_021B1424(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B143C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B14DC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B14E8(ScrcmdWorkRef *ref);
int func_021B14F4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1550(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B15B8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B15C8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1604(ScriptWorkRef *ref);
struct Strbuf *func_021B162C(ScrcmdWork *cmdWork, ScriptWork *scriptWork, u32 msgId);
extern const VecFx32 d_021D9390;
extern const VecFx32 d_021D939C[2][4];


/*
 * State 2 is a nested switch on func_02190C78's result (case 0, case 2
 * empty, default) with the flag store and the state increment written out
 * in each arm: the compiler cross-jumps the default arm into case 0's
 * tail, which is why `movs r1,#1; b` sits after the shared increment.
 * An if/else chain puts that arm inline. The listing extent includes two
 * bytes of padding.
 * Addresses are Black-image addresses.
 */
int func_021B0084(GameEvent *event, int *seq, void *work)
{
    YesNoEventWork *yesNo = work;

    func_0215A5F4(yesNo->cmdWork);
    switch (*seq) {
    case 0:
        func_0215A684(yesNo->cmdWork, 8);
        (*seq)++;
    case 1:
        if (func_0215A690(yesNo->cmdWork) == 1) {
            yesNo->menu = func_02190BE4(func_02188C54(func_0201210C(func_0215A5DC(yesNo->cmdWork))), 0);
            (*seq)++;
        }
        break;
    case 2:
        switch (func_02190C78(yesNo->menu)) {
        case 0:
            *yesNo->result = 0;
            (*seq)++;
            break;
        case 2:
            break;
        default:
            *yesNo->result = 1;
            (*seq)++;
            break;
        }
        break;
    case 3:
        func_021909BC(yesNo->menu);
        return 1;
    }
    return 0;
}


GameEvent *func_021B010C(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result)
{
    GameEvent *event;
    YesNoEventWork *yesNo;

    event = func_020122C0(gameSystem, 0, func_021B0084, 0xc);
    yesNo = func_020124E8(event);
    yesNo->cmdWork = cmdWork;
    yesNo->result = result;
    return event;
}


int func_021B0130(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *result = func_02159AE8(vm, cmdWork);
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);

    func_0215897C(scriptWork, func_021B010C(func_0215A5DC(cmdWork), cmdWork, result));
    return 1;
}


int func_021B015C(GameEvent *event, int *seq, void *work)
{
    MenuEventWork *menu = work;
    int done;

    switch (*seq) {
    case 0:
        func_0215A684(menu->cmdWork, 8);
        (*seq)++;
    case 1:
        if (func_0215A690(menu->cmdWork) == 1) {
            func_0215A864(menu->cmdWork);
            (*seq)++;
        }
        break;
    case 2:
        if (menu->allowCancel != 0)
            done = func_0215A990(menu->cmdWork);
        else
            done = func_0215A954(menu->cmdWork);
        if (done == 1)
            return 1;
        break;
    }
    return 0;
}


GameEvent *func_021B01B8(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, int allowCancel)
{
    GameEvent *event;
    MenuEventWork *menu;

    event = func_020122C0(gameSystem, 0, func_021B015C, 8);
    menu = func_020124E8(event);
    menu->cmdWork = cmdWork;
    menu->allowCancel = allowCancel;
    return event;
}


int func_021B01DC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 x, y, cursorPos, cancelable;
    u16 *result;
    ScriptWork *scriptWork;
    struct GameData *gameData;

    scriptWork = func_0215A5F4(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    x = *vm->pc;
    vm->pc = vm->pc + 1;
    y = *vm->pc;
    vm->pc = vm->pc + 1;
    cursorPos = func_02159B10(vm, cmdWork);
    pc = vm->pc;
    cancelable = pc[0];
    vm->pc = pc + 1;
    result = func_02158FE0(scriptWork, gameData, func_02011330(vm));
    func_0215A77C(cmdWork, x, y, cursorPos, cancelable, 0, result, func_02158F74(scriptWork), 0);
    return 1;
}


int func_021B024C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 cursorPos;
    u16 *result;
    ScriptWork *scriptWork;
    struct GameData *gameData;
    u8 x, y, cancelable;

    scriptWork = func_0215A5F4(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    x = *vm->pc;
    vm->pc = vm->pc + 1;
    y = *vm->pc;
    vm->pc = vm->pc + 1;
    cursorPos = func_02159B10(vm, cmdWork);
    pc = vm->pc;
    cancelable = pc[0];
    vm->pc = pc + 1;
    result = func_02158FE0(scriptWork, gameData, func_02011330(vm));
    func_0215A77C(cmdWork, x, y, cursorPos, cancelable, 0, result, func_02158F74(scriptWork), func_0215A60C(cmdWork));
    return 1;
}


int func_021B02C8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 cursorPos;
    u16 *result;
    ScriptWork *scriptWork;
    struct GameData *gameData;
    u8 x, y, cancelable;

    scriptWork = func_0215A5F4(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    x = *vm->pc;
    vm->pc = vm->pc + 1;
    y = *vm->pc;
    vm->pc = vm->pc + 1;
    cursorPos = func_02159B10(vm, cmdWork);
    pc = vm->pc;
    cancelable = pc[0];
    vm->pc = pc + 1;
    result = func_02158FE0(scriptWork, gameData, func_02011330(vm));
    func_0215A77C(cmdWork, x, y, cursorPos, cancelable, 1, result, func_02158F74(scriptWork), func_0215A60C(cmdWork));
    return 1;
}


int func_021B0344(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId, helpMsgId, param;
    ScriptWork *scriptWork;

    scriptWork = func_0215A5F4(cmdWork);
    msgId = func_02011330(vm);
    helpMsgId = func_02011330(vm);
    param = func_02159B10(vm, cmdWork);
    func_0215A7F0(cmdWork, msgId, helpMsgId, param, func_02158F78(scriptWork), func_02158F7C(scriptWork));
    return 0;
}


int func_021B0394(ScriptVm *vm, ScrcmdWork *cmdWork)
{
func_0215897C(func_0215A5F4(cmdWork), func_021B01B8(func_0215A5DC(cmdWork), cmdWork, 0));
return 1;
}


int func_021B03BC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
func_0215897C(func_0215A5F4(cmdWork), func_021B01B8(func_0215A5DC(cmdWork), cmdWork, 0));
return 1;
}


void func_021B03E4(ScrcmdWork *cmdWork, u32 windowKind)
{
    struct MsgData *msgData;
    u32 windowState, winY;
    ScriptFieldParam *param;
    FieldSysWin *sysWin;

    winY = 1;
    if (func_02159190(SCRIPT_FLAG_INFO_SYS_WIN)) {
        func_02191164(func_0215A61C(cmdWork));
        return;
    }
    param = func_02158F58(func_0215A5F4(cmdWork));
    msgData = func_0215A60C(cmdWork);
    windowState = windowKind;
    if (windowKind == 1) {
    } else if (windowKind == 2) {
        winY = 0x13;
    } else if (windowKind == 0) {
        switch (func_0215A654(cmdWork)) {
        case 1:
        case 3:
        case 5:
            windowState = winY;
            break;
        case 2:
        case 4:
        case 6:
            winY = 0x13;
            windowState = 2;
            break;
        case 7:
            winY = 0x13;
            windowState = 2;
            break;
        default:
            winY = 0x13;
            windowState = 2;
            break;
        }
    } else {
        winY = 0x13;
        windowState = 2;
    }
    sysWin = func_02190FA0(param->msgBg, msgData, winY);
    func_0215A660(cmdWork, windowState);
    func_0215A614(cmdWork, sysWin);
    func_02159144(SCRIPT_FLAG_INFO_SYS_WIN);
}


void func_021B0480(ScrcmdWork *cmdWork)
{
    struct TimeIcon *timeIcon;

    if (func_02159190(SCRIPT_FLAG_INFO_SYS_WIN)) {
        func_02191008(func_0215A61C(cmdWork));
        timeIcon = func_0215A630(cmdWork);
        if (timeIcon) {
            func_0202F038(timeIcon);
            func_0215A624(cmdWork, 0);
        }
        func_0215A614(cmdWork, 0);
        func_02159168(SCRIPT_FLAG_INFO_SYS_WIN);
    }
}


int func_021B04C0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (func_021910C0(func_0215A61C(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int func_021B04D8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId;
    struct Strbuf *str;
    ScriptWork *scriptWork;

    scriptWork = func_0215A5F4(cmdWork);
    msgId = func_02159B10(vm, cmdWork);
    func_021B03E4(cmdWork, (u8)func_02011330(vm));
    str = func_021B162C(cmdWork, scriptWork, msgId);
    func_02191084(func_0215A61C(cmdWork), 0, 0, str);
    func_020113D0(vm, func_021B04C0);
    return 1;
}


int func_021B0530(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId;
    struct Strbuf *str;
    struct MsgData *msgData;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    ScriptWork *scriptWork;
    FieldSysWin *sysWin;

    scriptWork = func_0215A5F4(cmdWork);
    str = func_02158F78(scriptWork);
    msgId = func_02159B10(vm, cmdWork);
    func_021B03E4(cmdWork, (u8)func_02011330(vm));
    msgData = func_0215A60C(cmdWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    sysWin = func_0215A61C(cmdWork);
    func_02191164(sysWin);
    func_02191184(sysWin, 0, 0, str);
    return 0;
}


int func_021B05AC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId, noTimeIcon;
    struct TimeIcon *timeIcon;

    heapId = func_02188C84(func_0201210C(func_0215A5DC(cmdWork)));
    noTimeIcon = func_02159B10(vm, cmdWork);
    if (!func_02159190(SCRIPT_FLAG_INFO_SYS_WIN)) {
        return 0;
    }
    timeIcon = func_0215A630(cmdWork);
    if (timeIcon) {
        func_0202F038(timeIcon);
        func_0215A624(cmdWork, 0);
    }
    if (noTimeIcon == 0) {
        struct BmpWin *bmpWin = func_021911B4(func_0215A61C(cmdWork));
        func_0215A624(cmdWork, func_0202EE30(func_020056BC(), bmpWin, 0xf, 0x10, heapId));
    }
    return 0;
}


int func_021B0624(ScriptVm *vm, ScrcmdWork *cmdWork)
{
func_021B0480(cmdWork);
return 0;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0630(ScrcmdWorkRef *ref)
{
    func_021B0480(ref->cmdWork);
    return 1;
}


int func_021B063C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 x, y;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    FieldMsgBg *msgBg;
    FieldMsgWin *oldWin;
    ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    u32 heapId;
    struct MsgData *msgData;
    FieldMsgWin *moneyWin;
    struct Strbuf *str;
    u32 money;

    x = func_02159B10(vm, cmdWork);
    y = func_02159B10(vm, cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    func_020127A4(gameData);
    fieldMap = func_0201210C(gameSystem);
    msgBg = func_02188C54(fieldMap);
    oldWin = func_02188D48(fieldMap);
    scriptWork = func_0215A5F4(cmdWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    heapId = func_02188C84(fieldMap);
    msgData = func_02045B38(0, 3, 0x9e, heapId);
    str = func_020457B0(0x80, heapId);
    money = func_0200C274(func_02012F08(gameData));
    if (oldWin != 0)
        func_02190728(oldWin);
    moneyWin = func_02190708(msgBg, msgData, (u16)(x - 9), (u16)y, 9, 2);
    func_02188D4C(fieldMap, moneyWin);
    func_0201EFA4(wordSet, 2, money, 7, 1, 1);
    func_02045CAC(msgData, 1, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    func_02190758(moneyWin, 0, 0, str);
    func_02045808(str);
    func_02045C04(msgData);
    return 0;
}


int func_021B0730(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    FieldMsgWin *moneyWin;
    ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    u32 heapId;
    struct MsgData *msgData;
    struct Strbuf *str;

    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    func_020127A4(gameData);
    fieldMap = func_0201210C(gameSystem);
    moneyWin = func_02188D48(fieldMap);
    scriptWork = func_0215A5F4(cmdWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    heapId = func_02188C84(fieldMap);
    msgData = func_02045B38(0, 3, 0x9e, heapId);
    str = func_020457B0(0x80, heapId);
    func_0201EFA4(wordSet, 2, func_0200C274(func_02012F08(gameData)), 7, 1, 1);
    func_02045CAC(msgData, 1, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    func_02190788(moneyWin);
    func_02190758(moneyWin, 0, 0, str);
    func_02045808(str);
    func_02045C04(msgData);
    return 0;
}


int func_021B07E0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    FieldMsgWin *moneyWin = func_02188D48(fieldMap);

    if (moneyWin != 0) {
        func_02190728(moneyWin);
        func_02188D4C(fieldMap, 0);
    }
    return 0;
}


/*
 * The quotient is written back into tileZ (the address-taken output local)
 * rather than a fresh row: with a separate local the divisor 12 and the
 * table stride 12 pool into r6 across the _u32_div_f call.
 */
void func_021B0808(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera)
{
    VecFx32 pos;
    VecFx32 forward;
    VecFx32 forwardFlat;
    VecFx32 right;
    VecFx32 shift;
    VecFx32 eye;
    VecFx32 target;
    u32 tileX;
    u32 tileZ;
    u32 chunkX;
    u32 column;

    pos = *mmdlPos;
    func_02048AD0(camera);
    func_02048B30(camera, &target);
    func_02048AE8(camera, &eye);
    func_0207CA00(&target, &eye, &forward);
    forwardFlat = forward;
    forwardFlat.y = column = 0;
    func_0207CCA4(&forwardFlat, &forwardFlat);
    func_0207CAE8(&forwardFlat, &d_021D9390, &right);
    func_0207CAE8(&forward, &right, &shift);
    func_0207CCA4(&shift, &shift);
    pos.x += shift.x;
    pos.y += shift.y;
    pos.z += shift.z;
    func_0206DF3C(&pos, &tileX, &tileZ);
    chunkX = tileX >> 3;
    if (chunkX < 10) {
        column = 0;
    } else if (chunkX >= 10 && chunkX <= 15) {
        column = 1;
    } else if (chunkX >= 16 && chunkX < 22) {
        column = 2;
    } else {
        column = 3;
    }
    tileZ = (tileZ >> 3) / 12;
    if (column < 4 && tileZ < 2) {
        *out = d_021D939C[tileZ][column];
    } else {
        VecFx32 zero = {0, 0, 0};
        *out = zero;
    }
}


void func_021B090C(VecFx32 *offset, struct G3dCamera *camera)
{
    VecFx32 eye, up, target;
    MtxFx43 viewMtx;
    MtxFx33 invRotation;

    func_02048AE8(camera, &eye);
    func_02048B0C(camera, &up);
    func_02048B30(camera, &target);
    func_0207BCA0(&eye, &up, &target, &viewMtx);
    func_02082B60(&viewMtx, &invRotation);
    func_0207B0A4(&invRotation, &invRotation);
    func_0207B51C(offset, &invRotation, offset);
}


void func_021B0960(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind)
{
    int column = 0;
    int row = 0;

    switch (windowKind) {
    case 3:
        column = 1;
        break;
    case 4:
        column = 1;
        row = 1;
        break;
    case 5:
        column = 2;
        break;
    case 6:
        column = 2;
        row = 1;
        break;
    case 0:
    case 1:
    case 2:
        func_021B0808(mmdlPos, out, camera, fieldCamera);
        func_021B090C(out, camera);
        return;
    }
    *out = d_021D939C[row][column];
    func_021B090C(out, camera);
}


void func_021B09D8(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind)
{
    func_021B0960(mmdlPos, out, camera, fieldCamera, windowKind);
}


void func_021B09EC(int windowState, int *talkIndex, int *tailType)
{
    *talkIndex = 0;
    *tailType = 0;
    switch (windowState) {
    case 3:
        *tailType = 7;
        break;
    case 4:
        *talkIndex = 1;
        *tailType = 5;
        break;
    case 5:
        *tailType = 8;
        break;
    case 6:
        *talkIndex = 1;
        *tailType = 6;
        break;
    case 2:
        *talkIndex = 1;
        break;
    case 1:
        break;
    case 0:
        *talkIndex = 1;
        *tailType = 2;
        break;
    }
}


int func_021B0A40(struct Mmdl *playerMmdl, const VecFx32 *targetPos)
{
    VecFx32 playerPos;
    int placement = 2;

    func_0216D88C(playerMmdl, &playerPos);
    if (targetPos->z < playerPos.z)
        placement = 1;
    return placement;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A614 (0x0215A614) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0A60(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (func_021912F8(func_0215A61C(cmdWork)) == 1) {
    func_0215A614(cmdWork, 0);
    func_02159168(SCRIPT_FLAG_TALK_WIN);
    return 1;
}
return 0;
}


void func_021B0A88(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (func_02159190(SCRIPT_FLAG_TALK_WIN) != 0) {
        func_021912D8(func_0215A61C(cmdWork));
        func_020113D0(vm, func_021B0A60);
    }
}


void func_021B0AB0(ScrcmdWork *cmdWork)
{
    u32 flag = SCRIPT_FLAG_TALK_WIN;

    if (func_02159190(flag)) {
        func_0219131C(func_0215A61C(cmdWork));
        func_0215A614(cmdWork, 0);
        func_02159168(flag);
    }
}


void func_021B0ADC(ScrcmdWork *cmdWork, FieldMsgBg *msgBg, int talkIndex, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType)
{
    func_0215A614(cmdWork, func_0219129C(msgBg, talkIndex, pos, str, winType, tailType));
    func_02159144(SCRIPT_FLAG_TALK_WIN);
}


void func_021B0B08(ScrcmdWork *cmdWork, int forceUpdate)
{
    struct MmdlSys *mmdlSys = func_0215A5EC(cmdWork);
    BalloonWinWork *balloon = func_0215A63C(cmdWork);
    struct Mmdl *mmdl = func_0216DE94(mmdlSys, balloon->objId);
    VecFx32 mmdlPos;
    if (mmdl != 0) {
        func_0216D5F8(mmdl);
        func_0216D88C(mmdl, &mmdlPos);
        if (forceUpdate == 1 || mmdlPos.x != balloon->mmdlPos.x || mmdlPos.y != balloon->mmdlPos.y || mmdlPos.z != balloon->mmdlPos.z) {
            struct FieldCamera *fieldCamera;
            struct G3dCamera *g3dCamera;
            balloon->mmdlPos = mmdlPos;
            fieldCamera = func_02188C58(func_0201210C(func_0215A5DC(cmdWork)));
            g3dCamera = func_0218EC2C(fieldCamera);
            func_021B0960(&balloon->mmdlPos, &balloon->offset, g3dCamera, fieldCamera, func_0215A66C(cmdWork));
        }
        balloon->pos.x = balloon->mmdlPos.x + balloon->offset.x;
        balloon->pos.y = balloon->mmdlPos.y + balloon->offset.y;
        balloon->pos.z = balloon->mmdlPos.z + balloon->offset.z;
    }
}


int func_021B0BAC(ScrcmdWork *cmdWork, u16 objId, u16 msgFileId, u16 msgId, u16 windowKind, int winType)
{
    struct MsgData *scriptMsgData;
    ScriptWork *scriptWork;
    ScriptFieldParam *param;
    struct MmdlSys *mmdlSys;
    struct Mmdl *playerMmdl, *targetMmdl;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    struct MsgData *fileMsgData;
    int windowState;
    BalloonWinWork *balloon;
    VecFx32 targetPos;
    int talkIndex, tailType;

    windowState = windowKind;
    scriptWork = func_0215A5F4(cmdWork);
    scriptMsgData = func_0215A60C(cmdWork);
    param = func_02158F58(scriptWork);
    mmdlSys = func_0215A5EC(cmdWork);
    playerMmdl = func_0216DE94(mmdlSys, 0xff);
    targetMmdl = func_0216DE94(mmdlSys, objId);
    if (targetMmdl == 0) {
        return 0;
    }
    msgBuffer = func_02158F78(scriptWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    if (msgFileId == 0x400) {
        func_02045CAC(scriptMsgData, msgId, tempBuffer);
    } else {
        fileMsgData = func_02045B38(0, 3, msgFileId, func_0215A5CC(cmdWork));
        func_02045CAC(fileMsgData, msgId, tempBuffer);
        func_02045C04(fileMsgData);
    }
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    balloon = func_0215A63C(cmdWork);
    if (func_02159190(SCRIPT_FLAG_TALK_WIN) != 0) {
        func_02191348(func_0215A61C(cmdWork), msgBuffer);
    } else {
        func_02082BCC(balloon, 0, 0x28);
        balloon->objId = objId;
        if (windowKind == 0) {
            func_0215A654(cmdWork);
            func_0216D88C(targetMmdl, &targetPos);
            windowState = func_021B0A40(playerMmdl, &targetPos);
        }
        func_021B09EC(windowState, &talkIndex, &tailType);
        balloon->talkIndex = talkIndex;
        func_0215A660(cmdWork, (u8)windowState);
        func_0215A678(cmdWork, windowKind);
        func_021B0B08(cmdWork, 1);
        func_021B0ADC(cmdWork, param->msgBg, talkIndex, &balloon->pos, msgBuffer, winType, tailType);
    }
    return 1;
}


int func_021B0CEC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldTalkWin *talkWin;
    int done;

    talkWin = func_0215A61C(cmdWork);
    func_021B0B08(cmdWork, 0);
    done = 0;
    if (func_02191388(talkWin) == 1) {
        done = 1;
    }
    return done;
}


int func_021B0D14(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 msgFileId, msgId, objId, windowKind, winType;
    msgFileId = func_02159B10(vm, cmdWork);
    msgId = func_02159B10(vm, cmdWork);
    objId = func_02159B10(vm, cmdWork);
    windowKind = func_02159B10(vm, cmdWork);
    winType = func_02159B10(vm, cmdWork);
    if (func_021B0BAC(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        func_020113D0(vm, func_021B0CEC);
        return 1;
    }
    return 0;
}


int func_021B0D74(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct Mmdl *targetMmdl;
    u16 msgFileId, msgId, windowKind, winType;
    unsigned char objId;
    targetMmdl = func_02158F90(func_0215A5F4(cmdWork));
    msgFileId = func_02159B10(vm, cmdWork);
    msgId = func_02159B10(vm, cmdWork);
    windowKind = func_02159B10(vm, cmdWork);
    winType = func_02159B10(vm, cmdWork);
    if (targetMmdl == 0) {
        return 1;
    }
    objId = func_0216D588(targetMmdl);
    if (func_021B0BAC(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        func_020113D0(vm, func_021B0CEC);
        return 1;
    }
    return 0;
}


int func_021B0DF0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 msgFileId, msgId, outfitMsgId, objId, windowKind, winType;
    msgFileId = func_02159B10(vm, cmdWork);
    msgId = func_02159B10(vm, cmdWork);
    outfitMsgId = func_02159B10(vm, cmdWork);
    objId = func_02159B10(vm, cmdWork);
    windowKind = func_02159B10(vm, cmdWork);
    winType = func_02159B10(vm, cmdWork);
    if (func_02008550(&func_020127A4(func_0215A5E4(cmdWork))->myStatus)) {
        msgId = outfitMsgId;
    }
    if (func_021B0BAC(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        func_020113D0(vm, func_021B0CEC);
        return 1;
    }
    return 0;
}


int func_021B0E74(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 msgFileId, msgId, objId, windowKind, winType;
    msgFileId = func_02159B10(vm, cmdWork);
    func_02159B10(vm, cmdWork);
    msgId = func_02159B10(vm, cmdWork);
    objId = func_02159B10(vm, cmdWork);
    windowKind = func_02159B10(vm, cmdWork);
    winType = func_02159B10(vm, cmdWork);
    if (func_021B0BAC(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        func_020113D0(vm, func_021B0CEC);
        return 1;
    }
    return 0;
}


/*
 * Calls func_021B0A88(a, b) and returns 0x1.
 */
/*
 * Calls func_021B0A88() and returns 0x1.
 */
int func_021B0EDC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    func_021B0A88(vm, cmdWork);

    return 0x1;
}


int func_021B0EE8(ScrcmdWorkRef *ref)
{
    func_021B0AB0(ref->cmdWork);
    return 1;
}


int func_021B0EF4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *param;
    int key1, key2, objId;
    struct Strbuf *msgBuffer;
    int placement, talkIndex;
    struct MmdlSys *mmdlSys;
    struct FieldPlayer *fieldPlayer;
    struct Mmdl *playerMmdl;
    BalloonWinWork *balloon;
    VecFx32 targetPos;

    scriptWork = func_0215A5F4(cmdWork);
    param = func_02158F58(scriptWork);
    key1 = func_02159B10(vm, cmdWork);
    key2 = func_02159B10(vm, cmdWork);
    objId = func_02159B10(vm, cmdWork);
    msgBuffer = func_02158F78(scriptWork);
    if (func_02159190(SCRIPT_FLAG_TALK_WIN) != 0) {
        return 1;
    }
    func_0202A310(key1, key2, msgBuffer, func_0215A5CC(cmdWork));
    if (func_0216DE94(func_0215A5EC(cmdWork), objId) == 0) {
        objId = 0xff;
    }
    balloon = func_0215A63C(cmdWork);
    talkIndex = 0;
    func_02082BCC(balloon, 0, 0x28);
    balloon->objId = objId;
    fieldPlayer = func_02188CB4(param->fieldMap);
    mmdlSys = func_0215A5EC(cmdWork);
    playerMmdl = func_021A3074(fieldPlayer);
    func_0216D88C(func_0216DE94(mmdlSys, balloon->objId), &targetPos);
    placement = func_021B0A40(playerMmdl, &targetPos);
    if (placement != 1) {
        talkIndex = 1;
    }
    balloon->talkIndex = talkIndex;
    func_021B0B08(cmdWork, 1);
    func_021B0ADC(cmdWork, param->msgBg, talkIndex, &balloon->pos, msgBuffer, 0, 0);
    func_0215A660(cmdWork, placement);
    func_020113D0(vm, func_021B0CEC);
    return 1;
}


int func_021B0FF0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (func_021916E0(func_0215A61C(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int func_021B1008(ScriptVm *vm, ScrcmdWork *cmdWork, int winType)
{
    ScriptWork *scriptWork;
    int posKind;
    u16 winY;
    int msgId;
    struct Strbuf *str;
    ScriptFieldParam *param;
    u8 *pc;
    FieldPlainWin *plainWin;

    scriptWork = func_0215A5F4(cmdWork);
    param = func_02158F58(scriptWork);
    msgId = func_02159B10(vm, cmdWork);
    pc = vm->pc;
    posKind = *pc;
    vm->pc = pc + 1;
    winY = 1;
    str = func_021B162C(cmdWork, scriptWork, msgId);
    if (posKind != 1) {
        winY = 0x13;
    }
    if (func_02159190(SCRIPT_FLAG_PLAIN_WIN) != 0) {
        plainWin = func_0215A61C(cmdWork);
        func_021915EC(plainWin);
    } else {
        plainWin = func_02191558(param->msgBg, 0, winType, 1, winY, 0x1e, 4);
        func_0215A614(cmdWork, plainWin);
    }
    func_021916A8(plainWin, 8, 0, str);
    func_02159144(SCRIPT_FLAG_PLAIN_WIN);
    func_020113D0(vm, func_021B0FF0);
    return 1;
}


void func_021B10A4(ScrcmdWork *cmdWork)
{
    int flag = SCRIPT_FLAG_PLAIN_WIN;
    if (func_02159190(SCRIPT_FLAG_PLAIN_WIN) != 0) {
        func_021915B4(func_0215A61C(cmdWork));
        func_0215A614(cmdWork, 0);
        func_02159168(flag);
    }
}


int func_021B10D0(ScriptVm *vm, ScrcmdWork *cmdWork) { return func_021B1008(vm, cmdWork, 0); }


int func_021B10DC(ScriptVm *vm, ScrcmdWork *cmdWork) { return func_021B1008(vm, cmdWork, 1); }


int func_021B10E8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
func_021B10A4(cmdWork);
return 0;
}


int func_021B10F4(ScrcmdWorkRef *ref)
{
    func_021B10A4(ref->cmdWork);
    return 1;
}


int func_021B1100(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct Strbuf *str;
    struct MsgData *msgData;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    ScriptWork *scriptWork;
    u16 msgId, id;
    ScriptFieldParam *param;
    int x, y;
    u8 width;
    u8 height;
    u8 textWidth;

    scriptWork = func_0215A5F4(cmdWork);
    param = func_02158F58(scriptWork);
    msgId = func_02011330(vm);
    x = func_02159B10(vm, cmdWork);
    y = func_02159B10(vm, cmdWork);
    id = func_02011330(vm);
    height = 2;
    str = func_020457B0(0x40, func_0215A5CC(cmdWork));
    msgData = func_0215A60C(cmdWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    func_02191830(param->msgBg, str, &width, &height);
    textWidth = width;
    if (x + textWidth > 0x1f) {
        x = (u16)(0x1f - textWidth);
    }
    if (y + height > 0x18) {
        y = 4;
        height = y;
    }
    func_021918DC(param->msgBg, str, id, x, y, textWidth, height);
    func_02045808(str);
    func_02159144(SCRIPT_FLAG_SUB_WIN);
    return 0;
}


int func_021B11D8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *param = func_02158F58(func_0215A5F4(cmdWork));

    func_0219196C(param->msgBg, func_02011330(vm));
    if (func_021919AC(param->msgBg) == 0) {
        func_02159168(SCRIPT_FLAG_SUB_WIN);
    }
    return 0;
}


void func_021B120C(ScrcmdWork *cmdWork)
{
    u32 flag = SCRIPT_FLAG_SUB_WIN;

    if (func_02159190(flag)) {
        func_02191978(func_02158F58(func_0215A5F4(cmdWork))->msgBg);
        func_02159168(flag);
    }
}


int func_021B1234(ScrcmdWorkRef *ref)
{
    func_021B120C(ref->cmdWork);
    return 1;
}


int func_021B1240(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct Strbuf *tempBuffer = func_02158F78(func_0215A5F4(cmdWork));

    if (func_02191BE8(func_0215A61C(cmdWork), tempBuffer) == 1) {
        return 1;
    }
    return 0;
}


void func_021B1268(ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct GfFont *font;
    if (func_02159190(SCRIPT_FLAG_BG_WIN) != 0) {
        func_02191B14(func_0215A61C(cmdWork));
        font = func_02158F84(scriptWork);
        func_02158F80(scriptWork, 0);
        if (font != 0) {
            func_0201D83C(font);
        }
        func_0215A614(cmdWork, 0);
        func_02159168(SCRIPT_FLAG_BG_WIN);
    }
}


int func_021B12B0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int msgId, winType;
    ScriptFieldParam *param;
    struct MsgData *msgData;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    scriptWork = func_0215A5F4(cmdWork);
    msgId = func_02011330(vm);
    winType = func_02011330(vm);
    param = func_02158F58(scriptWork);
    msgData = func_0215A60C(cmdWork);
    func_0215A614(cmdWork, func_02191A04(param->msgBg, winType));
    msgBuffer = func_02158F78(scriptWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    func_020113D0(vm, func_021B1240);
    func_02159144(SCRIPT_FLAG_BG_WIN);
    return 1;
}


int func_021B1334(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *param, *fontParam;
    int msgId, winType, heapId;
    struct MsgData *msgData;
    struct GfFont *font;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    scriptWork = func_0215A5F4(cmdWork);
    param = func_02158F58(scriptWork);
    msgId = func_02011330(vm);
    winType = func_02011330(vm);
    heapId = func_02188C84(param->fieldMap);
    fontParam = func_02158F58(scriptWork);
    msgData = func_0215A60C(cmdWork);
    font = func_0201D7EC(0x17, 4, 0, 0, heapId);
    func_02158F80(scriptWork, font);
    func_0215A614(cmdWork, func_02191A10(fontParam->msgBg, winType, font));
    msgBuffer = func_02158F78(scriptWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    func_020113D0(vm, func_021B1240);
    func_02159144(SCRIPT_FLAG_BG_WIN);
    return 1;
}


int func_021B13E0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
func_021B1268(cmdWork);
return 0;
}


int func_021B13EC(ScrcmdWorkRef *ref)
{
    func_021B1268(ref->cmdWork);
    return 1;
}


void func_021B13F8(ScrcmdWork *cmdWork)
{
    u32 flag = SCRIPT_FLAG_SP_WIN;

    if (func_02159190(flag)) {
        func_02192628(func_0215A61C(cmdWork));
        func_0215A614(cmdWork, 0);
        func_02159168(flag);
    }
}


int func_021B1424(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (func_021926D8(func_0215A61C(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int func_021B143C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int msgId, frameType;
    struct Strbuf *str;
    u8 x, y;
    ScriptFieldParam *param;
    u16 width, height;
    u8 **pcPtr = &vm->pc;
    scriptWork = func_0215A5F4(cmdWork);
    msgId = func_02011330(vm);
    x = **pcPtr;
    (*pcPtr)++;
    y = **pcPtr;
    (*pcPtr)++;
    frameType = func_02011330(vm);
    str = func_021B162C(cmdWork, scriptWork, msgId);
    param = func_02158F58(scriptWork);
    width = func_0219270C(param->msgBg, str, 4);
    height = func_0219272C(param->msgBg, str, 4);
    {
        FieldSpWin *spWin = func_02192570(param->msgBg, frameType, x, y, width, height);
        func_0215A614(cmdWork, spWin);
        func_0219269C(spWin, 4, 4, str);
    }
    func_020113D0(vm, func_021B1424);
    func_02159144(SCRIPT_FLAG_SP_WIN);
    return 1;
}


int func_021B14DC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
func_021B13F8(cmdWork);
return 0;
}


int func_021B14E8(ScrcmdWorkRef *ref)
{
    func_021B13F8(ref->cmdWork);
    return 1;
}


int func_021B14F4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (func_02159190(SCRIPT_FLAG_INFO_SYS_WIN)) {
        func_021B0480(cmdWork);
    }
    if (func_02159190(SCRIPT_FLAG_PLAIN_WIN)) {
        func_021B10A4(cmdWork);
    }
    if (func_02159190(SCRIPT_FLAG_BG_WIN)) {
        func_021B1268(cmdWork);
    }
    if (func_02159190(SCRIPT_FLAG_SP_WIN)) {
        func_021B13F8(cmdWork);
    }
    if (func_02159190(SCRIPT_FLAG_TALK_WIN)) {
        func_021B0A88(vm, cmdWork);
    }
    return 1;
}


int func_021B1550(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 keys;
    void *msgWin;

    keys = func_020362DC();
    msgWin = func_0215A61C(cmdWork);
    if (keys & 3) {
        func_020061E4(0x547);
        return 1;
    }
    if (func_02159190(SCRIPT_FLAG_INFO_SYS_WIN)) {
        func_02191134(msgWin);
    } else if (func_02159190(SCRIPT_FLAG_PLAIN_WIN)) {
        func_02191794(msgWin);
    } else if (func_02159190(SCRIPT_FLAG_TALK_WIN)) {
        func_021914CC(msgWin);
    } else {
        return 1;
    }
    return 0;
}


int func_021B15B8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021B1550);
    return 1;
}


int func_021B15C8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *param = func_02158F58(func_0215A5F4(cmdWork));

    if (func_02011330(vm)) {
        func_021904DC(param->msgBg, 1);
        func_02159144(SCRIPT_FLAG_AUTO_MODE);
    } else {
        func_021904DC(param->msgBg, 0);
        func_02159168(SCRIPT_FLAG_AUTO_MODE);
    }
    return 0;
}


int func_021B1604(ScriptWorkRef *ref)
{
    ScriptFieldParam *param = func_02158F58(ref->scriptWork);
    u32 flag = SCRIPT_FLAG_AUTO_MODE;

    if (func_02159190(flag)) {
        func_021904DC(param->msgBg, 0);
        func_02159168(flag);
    }
    return 1;
}


struct Strbuf *func_021B162C(ScrcmdWork *cmdWork, ScriptWork *scriptWork, u32 msgId)
{
    struct MsgData *msgData;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;

    msgData = func_0215A60C(cmdWork);
    msgBuffer = func_02158F78(scriptWork);
    wordSet = func_02158F74(scriptWork);
    tempBuffer = func_02158F7C(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    return msgBuffer;
}
