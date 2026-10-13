/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F532C, func_021F5340, func_021F5368, func_021F5390, func_021F5400, func_021F542C, func_021F5488, func_021F54CC, func_021F556C
 * address:  0x021F5260
 * region:   ov083
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
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   GPOWER_GetPowerType  0x02010F94  thumb
 *   GPOWER_Activate   0x02010E14  thumb
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   GPOWER_GetPowerCost  0x02010FA0  thumb
 *   func_0201292C  0x0201292C  thumb
 *   MYITEM_SAVEDATA_RemoveItem   0x02007F1C  thumb
 *   func_021652C4  0x021652C4  thumb  ov010
 *   func_021657B0  0x021657B0  thumb  ov010
 *   func_02010F8C  0x02010F8C  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0216D9E4 0x0216D9E4 thumb ov010
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   GPOWER_UseHpRestore  0x0201104C  thumb
 *   GPOWER_UsePpRestore  0x020110CC  thumb
 *   func_02190FA0 0x02190FA0 thumb ov021
 *   func_0219103C 0x0219103C thumb ov021
 *   func_021910C0 0x021910C0 thumb ov021
 *   func_02191008 0x02191008 thumb ov021
 *   func_021907C4 0x021907C4 thumb ov021
 *   func_02190854 0x02190854 thumb ov021
 *   func_0219082C 0x0219082C thumb ov021
 *   func_021F55D4 0x021F55D4 thumb ov083
 *   func_020362DC 0x020362DC arm
 *   func_0201F184  0x0201F184  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190844  0x02190844  thumb  ov021
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

#include "unit_021F5260_types.h"

struct GameEvent;
struct ScriptWork;
struct MyItem;
struct PokeParty;
struct Pokemon;

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GPowerTable *func_02010F7C(u32 heapId);
extern struct GameEvent *func_02158768(struct GameSystem *gameSystem, int scriptId, int param, int heapId);
extern struct ScriptWork *func_021589D0(struct GameEvent *event);
extern unsigned int GPOWER_GetPowerType(struct GPowerTable *table, int powerId);
extern void GPOWER_Activate(int powerId, struct GPowerTable *table, int payWithItems);
extern int func_02159058(struct ScriptWork *scriptWork, u16 powerId, u16 powerType, u16 payWithItems, u16 unused);
extern struct WordSet *func_02158F74(struct ScriptWork *scriptWork);
extern u16   GPOWER_GetPowerCost(struct GPowerTable *table, int powerId);
extern struct MyItem *func_0201292C(const struct GameData *gameData);
extern u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *myItem, u16 itemId, u16 count, u16 heapId);
extern void func_021652C4(int powerId);
extern void  func_021657B0(int powerId);
extern void  func_02010F8C(struct GPowerTable *table);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct FieldMsgBg *func_02188C54(struct FieldMap *fieldMap);
extern struct FldMmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heapId);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0216D9A0(struct FldMmdlSys *mmdlSys);
extern void func_02045808(struct Strbuf *str);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern u32 func_02045C04(struct MsgData *msgData);
extern u32 *func_0216D9E4(struct FldMmdlSys *mmdlSys);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int  func_0204E804(void);
extern void func_020061E4(u32 seId);
extern struct PokeParty *func_02012934(const struct GameData *gameData);
extern u32   func_0201AB08(struct PokeParty *party);
extern struct Pokemon *func_0201AB28(struct PokeParty *party, u32 index);
extern void func_0201EEF4(struct WordSet *wordSet, u32 index, struct Pokemon *pokemon);
extern u32   GPOWER_UseHpRestore(struct PokeParty *party);
extern u32   GPOWER_UsePpRestore(struct PokeParty *party);
extern struct InfoSysWin *func_02190FA0(struct FieldMsgBg *msgBg, struct MsgData *msgData, u32 msgId);
extern void func_0219103C(struct InfoSysWin *win, u32, u32, u32);
extern u32 func_021910C0(struct InfoSysWin *win);
extern int func_02191008(struct InfoSysWin *win);
extern struct InfoMsgWin *func_021907C4(struct FieldMsgBg *msgBg, struct MsgData *msgData, u32 b, u32 c, u16 d, u16 e);
extern void func_02190854(struct InfoMsgWin *win);
extern int func_0219082C(struct InfoMsgWin *win);
extern void func_021F55D4(GPowerListWork *work);
extern u32 func_020362DC(void);
extern void func_0201F184(struct WordSet *wordSet, u32 index, s32 value);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 value, u32 digits, u32 padding, u32 d);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void func_02190844(struct InfoMsgWin *win, int x, int y, struct Strbuf *str);

struct GameEvent *func_021F5260(struct GameSystem *gameSystem, GPowerActivateParam *param);
struct GameEvent *func_021F532C(struct GameSystem *gameSystem);
struct GameEvent *func_021F5340(struct GameSystem *gameSystem);
struct GameEvent *func_021F5368(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
void func_021F5390(GPowerListWork *work, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
void func_021F5400(GPowerListWork *work);
int func_021F542C(struct GameEvent *event, int *seq, void *work);
void func_021F5488(struct GameSystem *gameSystem, struct WordSet *wordSet, int powerType);
int func_021F54CC(struct GameEvent *event, int *seq, GPowerListWork *work);
void func_021F556C(GPowerListWork *work, struct Strbuf *templateStr, u32 powerId, int minutes, u8 row);

struct GameEvent *func_021F5260(struct GameSystem *gameSystem, GPowerActivateParam *param)
{
    struct GameEvent *event;
    struct ScriptWork *scriptWork;
    struct GameData *gameData;
    struct GPowerTable *table;
    int powerId;
    int powerType;
    u16 cost;

    gameData = func_020120F4(gameSystem);
    table = func_02010F7C(GPOWER_EVENT_HEAP_ID_BACK);
    powerId = param->powerId;
    event = func_02158768(gameSystem, 0x28B9, 0, GPOWER_EVENT_HEAP_ID);
    scriptWork = func_021589D0(event);
    if (powerId == GPOWER_ID_NONE || powerId > GPOWER_ID_LAST) {
        powerId = 0;
    }
    powerType = GPOWER_GetPowerType(table, powerId);
    GPOWER_Activate(powerId, table, param->payWithItems);
    /* Power 0x27 tells the script type 0xB whatever its table type is. */
    if (powerId == 0x27) {
        func_02159058(scriptWork, powerId, 0xB, param->payWithItems, 0);
    } else {
        func_02159058(scriptWork, powerId, powerType, param->payWithItems, 0);
    }
    func_021F5488(gameSystem, func_02158F74(scriptWork), powerType);
    if (param->payWithItems != 0) {
        cost = GPOWER_GetPowerCost(table, powerId);
        MYITEM_SAVEDATA_RemoveItem(func_0201292C(gameData), GPOWER_COST_ITEM_ID, cost, GPOWER_EVENT_HEAP_ID_BACK);
        func_021652C4(powerId);
    } else {
        func_021657B0(powerId);
    }
    func_02010F8C(table);
    return event;
}

struct GameEvent *func_021F532C(struct GameSystem *gameSystem)
{
    return func_02158768(gameSystem, 0x28BA, 0, GPOWER_EVENT_HEAP_ID);
}

struct GameEvent *func_021F5340(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    GPowerFlashWork *work;

    event = func_020122C0(gameSystem, 0, func_021F542C, sizeof(GPowerFlashWork));
    work = func_020124E8(event);
    work->gameData = func_020120F4(gameSystem);
    work->gameSystem = gameSystem;
    return event;
}

struct GameEvent *func_021F5368(struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, (GameEventFunc)func_021F54CC, sizeof(GPowerListWork));
    func_021F5390(func_020124E8(event), gameSystem, fieldMap);
    return event;
}

void func_021F5390(GPowerListWork *work, struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    work->heapId = GPOWER_EVENT_HEAP_ID;
    work->heapIdBack = (work->heapId & 0x7FFF) | 0x8000;
    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->msgBg = func_02188C54(work->fieldMap);
    work->mmdlSys = func_02188C7C(work->fieldMap);
    work->powerTable = func_02010F7C(work->heapId);
    work->msgData = func_02045B38(0, 3, 0x108, work->heapId);
    work->wordSet = func_0201EC64(work->heapId);
    work->templateStr = func_020457B0(0x81, work->heapId);
    work->lineStr = func_020457B0(0x81, work->heapId);
    func_0216D9A0(work->mmdlSys);
}

void func_021F5400(GPowerListWork *work)
{
    func_02045808(work->lineStr);
    func_02045808(work->templateStr);
    func_0201ED04(work->wordSet);
    func_02045C04(work->msgData);
    func_02010F8C(work->powerTable);
    func_0216D9E4(work->mmdlSys);
}

int func_021F542C(struct GameEvent *event, int *seq, void *work)
{
    switch (*seq) {
    case 0:
        func_0204E720(4, 10, 16, 4);
        func_020061E4(0x5E0);
        (*seq)++;
        break;
    case 1:
        if (func_0204E804() != 0)
            break;
        func_0204E720(4, 16, 0, 8);
        (*seq)++;
    case 2:
        if (func_0204E804() != 0)
            break;
    default:
        return 1;
    }
    return 0;
}

void func_021F5488(struct GameSystem *gameSystem, struct WordSet *wordSet, int powerType)
{
    struct PokeParty *party = func_02012934(func_020120F4(gameSystem));
    u8 firstReady;

    firstReady = func_0201AB08(party);
    func_0201EEF4(wordSet, 1, func_0201AB28(party, firstReady));
    switch (powerType) {
    case 5:
        GPOWER_UseHpRestore(party);
        break;
    case 6:
        GPOWER_UsePpRestore(party);
        break;
    }
}

int func_021F54CC(struct GameEvent *event, int *seq, GPowerListWork *work)
{
    struct InfoSysWin *openWin;
    switch (*seq) {
    case 0:
        openWin = func_02190FA0(work->msgBg, work->msgData, 19);
        work->infoSysWin = openWin;
        func_0219103C(openWin, 0, 0, 3);
        *seq += 1;
        break;
    case 1:
        if (func_021910C0(work->infoSysWin)) {
            func_02191008(work->infoSysWin);
            *seq += 1;
        }
        break;
    case 2:
        work->infoMsgWin = func_021907C4(work->msgBg, work->msgData, 4, 1, 24, 22);
        func_02190854(work->infoMsgWin);
        func_021F55D4(work);
        *seq += 1;
        break;
    case 3:
        if (func_020362DC() & 3) *seq += 1;
        break;
    default:
        func_02190854(work->infoMsgWin);
        func_0219082C(work->infoMsgWin);
        func_021F5400(work);
        return 1;
    }
    return 0;
}

void func_021F556C(GPowerListWork *work, struct Strbuf *templateStr, u32 powerId, int minutes, u8 row)
{
    func_0201F184(work->wordSet, 0, powerId);
    func_0201EFA4(work->wordSet, 1, minutes / 60, 2, 1, 1);
    func_0201EFA4(work->wordSet, 2, minutes % 60, 2, 2, 1);
    func_0201F250(work->wordSet, work->lineStr, templateStr);
    func_02190844(work->infoMsgWin, 8, (u16)(row << 4), work->lineStr);
}
