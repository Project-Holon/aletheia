/*
 * file:     event_wificlub.c
 * unit:     yes
 * function: func_021544D4, func_021544F0, func_02154ABC, func_02154B08, func_02154BF8
 * address:  0x021544D4
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005CBC 0x02005CBC thumb
 *   func_02006734 0x02006734 thumb
 *   func_02012138 0x02012138 thumb
 *   func_02026454 0x02026454 thumb
 *   func_020144DC 0x020144DC thumb
 *   func_02012374 0x02012374 thumb
 *   func_02029F6C 0x02029F6C thumb
 *   func_020145CC 0x020145CC thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_020130B4 0x020130B4 thumb
 *   func_02013090 0x02013090 thumb
 *   func_02012444 0x02012444 thumb
 *   func_02012950 0x02012950 thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   func_0203133C 0x0203133C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203A574 0x0203A574 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203D210 0x0203D210 arm
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_0215444C 0x0215444C thumb ov006
 *   func_021544BC 0x021544BC thumb ov006
 *   func_021542C0 0x021542C0 thumb ov006
 *   func_021C2850 0x021C2850 thumb ov099
 *   d_021D6338 0x021D6338 data ov115 a4
 *   d_021D654C 0x021D654C data ov115 a4
 *   d_021C37E8 0x021C37E8 data ov099 a4
 *   d_02154C40 0x02154C40 data ov006 a2
 *   d_021DCCA4 0x021DCCA4 data ov134 a4
 *   d_021F03C4 0x021F03C4 data ov093 a4
 *   d_02154C2C 0x02154C2C data ov006 a1
 *   d_0215513C 0x0215513C data ov008 a4
 *   d_021E75C0 0x021E75C0 data ov119 a4
 *   d_02154C80 0x02154C80 data ov006 a4
 *   d_02208C40 0x02208C40 data ov195 a4
 *   d_021C7240 0x021C7240 data ov172 a4
 *   func_020124E8   0x020124E8  thumb
 *   func_02026400   0x02026400  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_02012EBC   0x02012EBC  thumb
 *   func_02005C44   0x02005C44  thumb
 *   func_0200ADF0   0x0200ADF0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   ov115_id 0x73 data a1
 *   ov099_id 0x63 data a1
 *   ov067_id 0x43 data a1
 *   ov127_id 0x7f data a1
 *   ov134_id 0x86 data a1
 *   ov093_id 0x5d data a1
 *   ov008_id 0x8 data a1
 *   ov119_id 0x77 data a1
 *   ov195_id 0xc3 data a1
 *   ov172_id 0xac data a1
 */
#include "event_wificlub_types.h"

struct Link;
struct NetTask;
struct PlayerStatusRecord;
struct BoxRecord;
struct Reg;
struct GameComm;
struct Party;
typedef int s32;

/* Entry of the menu transition table: the menu result picks the next sequence step. */
typedef struct MenuTransition {
    u8 selection;
    u8 reserved;
    u16 nextSeq;
} MenuTransition;

/* Order in which the two sides are written when this machine is the child. */
typedef struct SideOrder {
    u8 first, second;
} SideOrder;

extern void func_02005CBC(u32 value, u32 mask);
extern void func_02006734(u8 volume);
extern u16 func_02005C44(void);
extern void func_02005E30(u32 frames);
extern void *func_02012138(const struct GameSystem *gameSystem);
extern u32 func_02026454(void *gameComm);
extern int func_020144DC(int gameSystem, int fieldMap);
extern void *func_020145CC(void *gameSystem);
extern void func_02012374(struct GameEvent *event, struct GameEvent **newEvent);
extern void func_020057AC(void);
extern int func_0203CDBC(void);
extern void func_02029F6C(void);
extern int func_021BE92C(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);
extern void func_02082BCC(void *dst, int value, int size);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern void func_02006740(void);
extern void func_02005D90(u32 bgmNo, u16 fadeTarget);
extern void func_02005DF8(u32 frames);
extern void *func_02031324(int heapId);
extern void func_02031348(void *task, u32 overlayId, u32 procData, u32 param);
extern u32 func_02031330(void *task);
extern void func_0203133C(void *task);
extern u32 func_0200F7B8(u32 a0);
extern u32 func_0201283C(const struct GameData *gameData);
extern u32 func_02009A34(void *battleRecord);
extern int func_02034AC4(int overlayId);
extern void func_02034A5C(int overlayId);
extern void func_021C2850(char *scratchBuffer);
extern int func_020130B4(int battleSetup);
extern void func_02012444(struct GameEvent *event, u32 overlayId, u32 procData, u32 param);
extern void func_0215444C(WifiClubEventWork *work, u32 gameData, int seq);
extern void *func_02013090(u32 heapId);
extern void func_021542C0(WifiClubEventWork *work, int menuIndex);
extern void func_021544BC(WifiClubEventWork *work, u32 gameData, int seq);
extern void *func_020399A8(void);
extern void func_0203A574(u32, u32, u32, u32);
extern void func_02039C68(struct Link *handle, u32 rangeStart, u32 rangeEnd);
extern u32 func_02039CB4(struct Link *handle, u32 rangeStart, u32 rangeEnd);
extern int func_0203CD98(void);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
extern u32 func_0203D1A4(struct Link *handle);
extern void *func_02012950(void *gameData, u32 index);
extern void *func_02012F2C(struct GameData *gameData);
extern void func_02009BB8(void *battleRecord, int ruleIndex, int win, int lose, int draw);
extern void func_0203A5E4(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 func_020307B0(void *p);
extern int func_0203CEAC(int);
extern u32 func_0203D210(void);
void *func_020124E8(struct GameEvent *event);
void func_02026400(struct GameComm *gameComm);
void *func_0201A920(u32 heapId);
void *func_02012EBC(struct GameData *gameData);
void *func_0200ADF0(u32 heapId);
void *func_020122C0(void *gameSystem, void *a, void *callback, u32 workSize);
void func_021544D4(WifiClubEventWork *work);
int func_021544F0(struct GameEvent *event, u32 *seq, WifiClubEventWork *work);
void func_02154ABC(WifiClubEventWork *work);
void func_02154B08(void *event, void *gameSystem, int fieldMap, int hideFieldObjects);
int func_02154BF8(int gameSystem, int fieldMap, int hideFieldObjects);
extern const char d_021D6338[],d_021D654C[],d_021DCCA4[],d_021F03C4[],d_021C37E8[];
extern const char d_0215513C[],d_021E75C0[],d_02154C80[],d_02208C40[],d_021C7240[];
extern char ov008_id[],ov067_id[],ov127_id[],ov115_id[],ov099_id[];
extern char ov134_id[],ov093_id[],ov119_id[],ov195_id[],ov172_id[];
extern const SideOrder d_02154C2C;
extern const MenuTransition d_02154C40[];
extern const char d_02154C80[];


/*
 * Extent ends with two bytes of alignment padding at 0x021544EE.
 * Error exit: puts the sound volume back and flags the session as failed.
 */
void func_021544D4(WifiClubEventWork *work)
{
    func_02005CBC(127, 63);
    func_02006734(127);
    work->login.useSaveData = 1;
}



/*
 * blockers: code-start witnesses for ov006 func_021544BC and ov099
 * func_021C2850; overlay-ID consumer evidence for func_02012444:r1
 * (IDs 127,134,8,119,195,172). All concrete bytes match.
 * Matching levers: typed Sel table folds the u16 field offset into its
 * pool word; Pair struct copies to SP; char-pointer field addressing
 * avoids loop spills; repeated cleanup tails preserve cross-jumped hops.
 * checks: 1 callees and PC-relative IDs rederived; 2 no matching twin;
 * 3 const 02031330 and unsigned counter worsened; 4 repeated cleanup
 * tails closed branch residue; 5 idioms relisted and neighbours reread.
 * TU --suggest-split: one section, no viable cut; tool consumer correction
 * needed before filing the two overlay leaves. No ARM9 blocker remains.
 * Prototype evidence: 02031324 and 02031348 forward all registers to
 * 02031354(int) and 020314F4(obj,u32,u32,u32); 0200F7B8 receives the
 * explicitly loaded zero despite its legacy void declaration.
 * 2026-10-04 note (wave D2 lane 15): still MATCH, bytes identical. Unresolved after re-run:
 * THM_CALL func_021C2850 (ov099 hint present, but 021C2850 is a Thumb veneer in ov099, 64 bytes
 * incl. data, no matched witness exists) and six single-use overlay-id words (ov008 0x8,
 * ov119 0x77, ov127 0x7f, ov134 0x86, ov172 0xac, ov195 0xc3) with no witness outside this
 * function. Nothing left to change in the C.
 * 2026-10-05 note (D4-14): re-run, still MATCH (1484 bytes, 111 of 112 relocations resolve; the open one is func_021C2850, a Thumb veneer in ov099). No change possible in C.
 */
int func_021544F0(struct GameEvent *event, u32 *seq, WifiClubEventWork *work)
{
    struct GameSystem *gameSystem;
    u32 step;
    int i, offset;
    SideOrder order;
    EvolutionRequest *request;
    WifiClubSession *session;

    gameSystem = work->gameSystem;
    step = *seq;
    switch (step) {
    case 0:
        work->savedBgmNo = func_02005C44();
        func_02005E30(6);
        ++*seq;
        break;
    case 1:
        if (!func_02026454(func_02012138(gameSystem))) {
            work->reserved10 = 0;
            func_02012374(event, (void *)func_020144DC((int)gameSystem, work->fieldMap));
            ++*seq;
        }
        break;
    case 2:
        func_020057AC();
        *seq = 8;
        break;
    case 3: break;
    case 4:
        if (func_0203CDBC()) {
            ++*seq;
            func_02154ABC(work);
            func_02006740();
            func_02005D90(work->savedBgmNo, 0xffff);
            func_02005DF8(60);
        }
        break;
    case 5:
        func_02029F6C();
        func_02012374(event, func_020145CC(gameSystem));
        ++*seq;
        break;
    case 6:
        if (work->hideFieldObjects)
            func_02012374(event, (void *)func_021BE92C(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        ++*seq;
        break;
    case 7: return 1;
    case 8:
        func_02082BCC(&work->login, 0, 0x28);
        *seq = 9;
        work->login.useSaveData = 0;
        break;
    case 9:
        work->login.gameData = func_020120F4(gameSystem);
        work->login.loginOption = 1;
        work->login.loginType = 0;
        work->login.messageId = 10;
        work->login.allowCancel = 1;
        func_02005D90(0x481, 0xffff);
        work->loginTask = func_02031324(4);
        func_02031348(work->loginTask, (u32)ov115_id, (u32)d_021D6338, (u32)&work->login);
        work->session->menuChoice = 0;
        *seq = 10;
        break;
    case 10:
        if (func_02031330(work->loginTask)) { func_0200F7B8(0); return 0; }
        func_0203133C(work->loginTask);
        if (!work->login.result) {
            if (!func_02009A34((void *)func_0201283C(work->paramGameData))) *seq = 30;
            else { *seq = 11; func_02005E30(6); }
        } else { func_02005E30(6); *seq = 25; }
        break;
    case 30:
        work->confirm.gameData = func_020120F4(gameSystem);
        work->confirm.loginOption = 1;
        work->confirm.loginType = 0;
        work->confirm.messageId = 1;
        work->confirm.saveData = 0;
        work->confirm.useSaveData = 0;
        work->confirm.allowCancel = 0;
        work->loginTask = func_02031324(4);
        func_02031348(work->loginTask, (u32)ov115_id, (u32)d_021D654C, (u32)&work->confirm);
        ++*seq;
        break;
    case 31:
        if (func_02031330(work->loginTask)) { func_0200F7B8(0); return 0; }
        func_0203133C(work->loginTask);
        func_02005E30(6);
        *seq = 4;
        break;
    case 11:
        func_02034AC4((int)ov099_id);
        func_02034AC4((int)ov067_id);
        func_021C2850((char *)work->session->scratchBuffer);
        if (work->battleSetup) { func_020130B4((int)work->battleSetup); work->battleSetup = 0; }
        func_02012444(work->event, (u32)ov127_id, (u32)d_021C37E8, (u32)work->session);
        ++*seq;
        break;
    case 12:
        *seq = d_02154C40[work->session->menuChoice].nextSeq;
        if (work->session->menuChoice == 1) work->login.useSaveData = 1;
        work->menuSelection = d_02154C40[work->session->menuChoice].selection;
        func_02034A5C((int)ov067_id);
        func_02034A5C((int)ov099_id);
        break;
    case 13:
        func_0215444C(work, (u32)func_020120F4(gameSystem), step);
        work->battleSetup = func_02013090(4);
        func_021542C0(work, work->session->menuChoice);
        func_02012444(work->event, (u32)ov134_id, (u32)d_021DCCA4, (u32)&work->battleEntry);
        ++*seq;
        break;
    case 14:
        if (work->battleResult == 1) {
            if (func_0203CD98()) {
                work->session->rematch = 0;
                *seq = 11;
            } else {
                func_021544D4(work);
                *seq = 9;
            }
        } else {
            func_021544BC(work, (u32)func_020120F4(gameSystem), step);
            func_02034AC4((int)ov093_id);
            func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
            func_02039C68(func_020399A8(), 100, 10);
            ++*seq;
        }
        break;
    case 15:
        if (!func_0203CD98() || func_0200FB24()) {
            func_0200FBB0(); func_0200F83C(); goto cleanup;
        }
        if (func_02039CB4(func_020399A8(), 100, 10)) ++*seq;
        break;
    case 16:
        func_02005D90(0x490, 0xffff);
        work->matchActive = 1;
        /* (work + offset) then the member offset, as in the original; indexing sides[] changes the bytes */
        if (!func_0203D1A4(func_020399A8())) {
            for (i = 0; i < 2; i++) {
                offset = i << 4;
                ((WifiClubEventWork *)((u32)work + offset))->sides[0].playerStatus = func_02012950(func_020120F4(gameSystem), i);
                ((WifiClubEventWork *)((u32)work + offset))->sides[0].party = work->session->party[i];
            }
        } else {
            order = d_02154C2C;
            for (i = 0; i < 2; i++) {
                offset = ((u8 *)&order)[i] << 4;
                ((WifiClubEventWork *)((u32)work + offset))->sides[0].playerStatus = func_02012950(func_020120F4(gameSystem), i);
                ((WifiClubEventWork *)((u32)work + offset))->sides[0].party = work->session->party[i];
            }
        }
        work->startParam.gameData = func_020120F4(work->gameSystem);
        work->startParam.battleSetup = work->battleSetup;
        work->startParam.sides = work->sides;
        work->startParam.enabled = 1;
        work->trainerRecord = func_02012F2C(func_020120F4(work->gameSystem));
        func_02034A5C((int)ov093_id);
        func_02012444(work->event, (u32)ov008_id, (u32)d_0215513C, (u32)&work->startParam);
        ++*seq;
        break;
    case 17:
        if (!func_0203CD98()) goto cleanup;
        if (work->matchOutcome == 0)
            func_02009BB8((void *)func_0201283C(func_020120F4(work->gameSystem)), work->session->ruleId - 1, 1, 0, 0);
        else if (work->matchOutcome == 1)
            func_02009BB8((void *)func_0201283C(func_020120F4(work->gameSystem)), work->session->ruleId - 1, 0, 1, 0);
        func_0203A5E4(0x100);
        *seq = 11;
        break;
    case 18:
        work->tradeParam.result = 0;
        work->tradeParam.ruleId = work->session->ruleId;
        ++*seq;
        break;
    case 19:
        work->tradeParam.gameData = func_020120F4(gameSystem);
        func_02012444(work->event, (u32)ov119_id, (u32)d_021E75C0, (u32)&work->tradeParam);
        ++*seq;
        break;
    case 20:
        switch (work->tradeParam.result) {
        case 1: *seq = 21; break;
        case 2: work->session->menuChoice = 1; *seq = 11; break;
        default: *seq = 11; break;
        }
        if (!func_0203CD98()) {
            func_021544D4(work);
            *seq = 9;
        }
        break;
    case 21:
        request = func_02030734(4, 0x14, 0, d_02154C80, 0x24b);
        request->gameData = func_020120F4(work->gameSystem);
        request->party = work->tradeParam.party;
        request->partyIndex = work->tradeParam.partyIndex;
        request->reserved = 0;
        request->evolveCondition = work->tradeParam.evolveCondition;
        request->fromTrade = 1;
        request->reserved2 = 0;
        work->tradeParam.evolutionRequest = request;
        func_02012444(work->event, (u32)ov195_id, (u32)d_02208C40, (u32)request);
        *seq = 22;
        break;
    case 22:
        func_020307B0(work->tradeParam.evolutionRequest);
        work->tradeParam.result = 1;
        *seq = 19;
        if (!func_0203CD98()) {
            func_021544D4(work);
            *seq = 9;
        }
        break;
    case 23:
        work->viewParam.gameData = func_020120F4(gameSystem);
        work->viewParam.mode = 3;
        func_02012444(work->event, (u32)ov172_id, (u32)d_021C7240, (u32)&work->viewParam);
        ++*seq;
        break;
    case 24:
        if (func_0203CD98()) goto menu;
cleanup:
        func_021544D4(work);
        *seq = 9;
        break;
menu:
        *seq = 11;
        break;
    case 28: func_0203CEAC(0); *seq = 29; break;
    case 29: if (func_0203D210()) *seq = 4; break;
    case 25: case 26: case 27: *seq = 4; break;
    }
    return 0;
}



/*
 * Cleanup helper. The battle setup is freed and cleared only when non-NULL;
 * the six blx sites are ARM func_020307B0. The 0x5A<<2 (0x168) field is a
 * Thumb encoding artefact, not evidence of a second pointer.
 */
void func_02154ABC(WifiClubEventWork *work)
{
    s32 battleSetup = (s32)work->battleSetup;
    if (battleSetup != 0) {
        func_020130B4(battleSetup);
        work->battleSetup = 0;
    }
    func_020307B0(work->session->party[0]);
    func_020307B0(work->session->party[1]);
    func_020307B0(work->session->regulation);
    func_020307B0(work->battleParty);
    func_020307B0(work->session->scratchBuffer);
    func_020307B0(work->session);
}



void func_02154B08(void *event, void *gameSystem, int fieldMap, int hideFieldObjects)
{
    WifiClubEventWork *work;
    WifiClubSession *session;

    if (func_02026454(func_02012138(gameSystem)))
        func_02026400(func_02012138(gameSystem));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->event = event;
    work->hideFieldObjects = hideFieldObjects;
    work->session = func_02030734(0x8004, 0x4c, 1, d_02154C80, 0x2b0);
    work->session->scratchBuffer = func_02030734(0x8004, 0x20, 1, d_02154C80, 0x2b1);
    work->session->gameData = func_020120F4(work->gameSystem);
    work->session->saveControl = func_02012EBC(work->session->gameData);
    work->session->rulesLoaded = 1;
    work->session->rematch = 0;
    work->paramGameData = work->session->gameData;
    work->battleRecord = func_0201283C(work->paramGameData);
    work->session->menuChoice = 0;
    work->tradeParam.party = work->battleParty = func_0201A920(0x8004);
    work->self = work;
    work->savedBgmNo = func_02005C44();
    work->session->party[0] = func_0201A920(0x8001);
    work->session->party[1] = func_0201A920(0x8001);
    work->session->regulation = func_0200ADF0(0x8001);
    work->session->isActive = 1;
}



int func_02154BF8(int gameSystem, int fieldMap, int hideFieldObjects)
{
    int event;

    event = (int)func_020122C0((void *)gameSystem, 0, func_021544F0, 0x174);
    func_02154B08((void *)event, (void *)gameSystem, fieldMap, hideFieldObjects);
    return event;
}
