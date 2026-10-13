/*
 * file:     unit_021AE948.c
 * unit:     yes
 * function: func_021AE948, func_021AE994, func_021AE9CC, func_021AE9F0, func_021AEA3C, func_021AEA8C, func_021AEABC, func_021AEB3C, func_021AEBB0, func_021AEC1C, func_021AEC40, func_021AEC84, func_021AECC0, func_021AED00, func_021AED24, func_021AEDAC, func_021AEDE0, func_021AEE28, func_021AEE78, func_021AEEC0, func_021AEEE0, func_021AEF00, func_021AEF10, func_021AEF60, func_021AEFA4, func_021AEFD8, func_021AF044, func_021AF0BC, func_021AF0F8, func_021AF130, func_021AF174, func_021AF1B0, func_021AF1D0, func_021AF1E8, func_021AF21C, func_021AF23C, func_021AF26C, func_021AF294, func_021AF2BC, func_021AF2CC, func_021AF2E4, func_021AF2F4, func_021AF324, func_021AF370, func_021AF380, func_021AF3D8, func_021AF430, func_021AF448, func_021AF458, func_021AF484, func_021AF4B0, func_021AF4E8, func_021AF544, func_021AF594, func_021AF5E4, func_021AF634, func_021AF684, func_021AF6C4, func_021AF6E8, func_021AF71C, func_021AF750
 * address:  0x021AE948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021AE948 (lane L135, script command handlers, first one calls the trainer eye creator 021AE454; original unknown).
 *
 * symbols:
 *   func_0215A460  0x0215A460  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021AE454  0x021AE454  thumb  ov021
 *   func_021AE430  0x021AE430  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0216E818  0x0216E818  thumb  ov010
 *   func_0215A4A0  0x0215A4A0  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 *   func_02029E20  0x02029E20  thumb
 *   func_02029AF4  0x02029AF4  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0216EAB0  0x0216EAB0  thumb  ov010
 *   func_02014024  0x02014024  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02029984  0x02029984  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028BA0  0x02028BA0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02029A04  0x02029A04  thumb
 *   func_02029A74  0x02029A74  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02028A58  0x02028A58  thumb
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02028BDC  0x02028BDC  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02158F88  0x02158F88  thumb  ov010
 *   func_020289B8  0x020289B8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A6AC  0x0215A6AC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_02005C64  0x02005C64  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_0215A6B8  0x0215A6B8  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007F68  0x02007F68  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02021288  0x02021288  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 */
#include "../arm9/script_vm_types.h"
#include "../ov010/script_work_types.h"
#include "event_trainer_eye_types.h"

struct ScrcmdWork;
struct GameSystem;
struct GameData;
struct FieldMap;
struct GameEvent;
struct FieldSoundSystem;
struct TrainerRecord;
struct MyItem;
struct IssSystem;
struct IssSwitchSys;

/* One trainer record of a script work (0x1C bytes): the trainer that saw the player, plus the eye event made for it. */
typedef struct ScriptTrainerSlot {
    TrainerEyeHit hit;          /* 0x00 */
    TrainerEyeWork *eyeWork;    /* 0x18: event work made by func_021AE454 */
} ScriptTrainerSlot;

/*
 * Work of the small game events below that change the BGM (event functions
 * with a state counter). The first field is the game system, the third the
 * script work that queues the follow-up event.
 */
typedef struct BgmEventWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    u32 reserved04;                 /* 0x04 */
    ScriptWork *scriptWork;         /* 0x08 */
} BgmEventWork;

/* Work of the Pokemon voice event (0x0C bytes). */
typedef struct PokeVoiceWork {
    u16 species;                    /* 0x00 */
    u16 form;                       /* 0x02 */
    u32 usePerapVoice;              /* 0x04: 1 plays the recorded voice of the voice save */
    struct ScrcmdWork *cmdWork;     /* 0x08: receives the voice handle */
} PokeVoiceWork;

extern u32 func_0215A460(u32 scriptId);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern ScriptWork *func_0215A5F4(struct ScrcmdWork *cmdWork);
extern struct GameSystem *func_0215A5DC(struct ScrcmdWork *cmdWork);
extern struct GameData *func_0215A5E4(struct ScrcmdWork *cmdWork);
extern u16 func_0215A5CC(struct ScrcmdWork *cmdWork);
extern u16 func_02159B10(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern u16 *func_02159AE8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern ScriptFieldParam *func_02158F58(ScriptWork *scriptWork);
extern u16 func_02158F8C(ScriptWork *scriptWork);
extern ScriptTrainerSlot *func_02159124(ScriptWork *scriptWork, int index);
extern struct GameSystem *func_02158F54(ScriptWork *scriptWork);
extern u8 *func_02158F88(ScriptWork *scriptWork);
extern void func_0215897C(ScriptWork *scriptWork, struct GameEvent *event);
extern void func_02159144(int checkFlag);
extern void func_02159168(int checkFlag);
extern TrainerEyeWork *func_021AE454(u32 heapId, struct FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex);
extern struct GameEvent *func_021AE430(struct GameSystem *gameSystem, TrainerEyeWork *first, TrainerEyeWork *second);
extern u16 func_0216D588(Mmdl *mmdl);
extern int func_0215A4C8(int trainerId);
extern int func_0215A4B4(int trainerId);
extern u32 func_0215A4A0(u32 scriptId);
extern struct GameEvent *func_0216E818(struct GameSystem *gameSystem, void *fieldSystem, int battleKind, int allyTrainerId, int trainerId, int secondTrainerId, int thirdTrainerId);
extern struct GameEvent *func_0216EAB0(struct GameSystem *gameSystem, void *fieldSystem, u32 battleKind, u32 reserved, u32 trainerId, u32 secondTrainerId, u32 thirdTrainerId, u32 fourthTrainerId);
extern u32 func_0202A230(u32 trainerId, u32 index);
extern u16 func_02029E20(u32 trainerClass);
extern struct GameEvent *func_02029AF4(struct GameSystem *gameSystem, u32 bgmNo);
extern struct GameEvent *func_021BE92C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int a, int b, int c, u8 d, u8 e);
extern struct TrainerRecord *func_02012F2C(struct GameData *gameData);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern int func_02014024(u32 zoneId);
extern u32 func_02008DF0(struct TrainerRecord *record, int index);
extern u16 func_02011330(ScriptVm *vm);
extern struct GameEvent *func_02029984(struct GameSystem *gameSystem, u32 bgmNo);
extern struct FieldSoundSystem *func_02012A30(struct GameData *gameData);
extern void func_02028BA0(struct FieldSoundSystem *soundSystem, u32 slotMask);
extern struct GameEvent *func_02029A04(struct GameSystem *gameSystem, u32 bgmNo, u16 fadeFrames);
extern struct GameEvent *func_02029A74(struct GameSystem *gameSystem, u16 bgmNo);
extern int func_02005F38(void);
extern void func_020113D0(ScriptVm *vm, ScriptWaitFn waitFn);
extern void func_02028A58(struct FieldSoundSystem *soundSystem, u8 level, u16 frames);
extern u8 func_02012984(struct GameData *gameData);
extern u32 func_02029DF4(struct GameData *gameData, u32 zoneId, u32 season);
extern struct GameEvent *func_020298A0(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames);
extern void func_02028BDC(struct FieldSoundSystem *soundSystem, u32 slotMask);
extern struct GameEvent *func_02029620(struct GameSystem *gameSystem, u32 a, u32 b);
extern struct GameEvent *func_020295A4(struct GameSystem *gameSystem, u32 bgmNo);
extern struct GameEvent *func_02029830(struct GameSystem *gameSystem, u32 bgmNo);
extern int func_02006224(u32 slot);
extern int func_02006148(u32 seNo);
extern void func_020061F8(int slot);
extern void func_020061E4(u32 seNo);
extern u32 func_020289B8(struct FieldSoundSystem *soundSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *func, unsigned int workSize);
extern void *func_020124E8(struct GameEvent *event);
extern u32 func_02006BD0(u32 handle);
extern u32 func_0215A6AC(struct ScrcmdWork *cmdWork);
extern struct IssSystem *func_02012134(struct GameSystem *gameSystem);
extern struct IssSwitchSys *func_0202B578(struct IssSystem *issSystem);
extern void func_0202C0D0(struct IssSwitchSys *switchSys, u32 switchNo);
extern void func_0202C0E4(struct IssSwitchSys *switchSys, u32 switchNo);
extern int func_0202C0F8(struct IssSwitchSys *switchSys, int switchNo);
extern int func_02005C64(void);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 species, u32 form, u32 pan, u32 a, u32 b, u32 c, u32 d, u32 perapVoice);
extern void func_0215A6B8(struct ScrcmdWork *cmdWork, u32 voiceHandle);
extern struct MyItem *func_0201292C(struct GameData *gameData);
extern u16 func_02007E50(struct MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 func_02007F1C(struct MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 func_02007E3C(struct MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 func_02007F68(struct MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 func_02007FB8(struct MyItem *myItem, u32 itemNo, u32 heapId);
extern u32 func_02020FE4(u32 itemNo, u32 selector, u32 heapId);
extern u32 func_02021288(u32 itemNo);

int func_021AE948(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AE994(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AE9CC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AE9F0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEA3C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEA8C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEABC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEB3C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEBB0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEC1C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEC40(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEC84(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AECC0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AED00(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AED24(ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021AEDAC(struct ScrcmdWork *cmdWork);
int func_021AEDE0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEE28(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEE78(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEEC0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEEE0(ScriptVm *vm, void *user);
int func_021AEF00(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEF10(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEF60(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AEFA4(BgmEventWork *work, u32 *seq);
int func_021AEFD8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF044(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF0BC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF0F8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF130(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF174(BgmEventWork *work, u32 *seq);
int func_021AF1B0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF1D0(BgmEventWork *work, u32 *seq);
void func_021AF1E8(ScriptWork *scriptWork);
void func_021AF21C(ScriptWork *scriptWork, u32 seNo);
int func_021AF23C(ScriptWork *scriptWork);
void func_021AF26C(ScriptWork *scriptWork);
int func_021AF294(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF2BC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF2CC(ScriptVm *vm, void *user);
int func_021AF2E4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF2F4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF324(ScriptVm *vm, void *user);
int func_021AF370(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF380(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF3D8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF430(ScriptVm *vm, void *user);
int func_021AF448(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF458(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF484(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF4B0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF4E8(void *event, u32 *seq, PokeVoiceWork *work);
int func_021AF544(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF594(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF5E4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF634(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF684(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF6C4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF6E8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF71C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF750(u32 itemNo);


/*
 * Script command: create the trainer eye event for trainer slot 0 or 1 and
 * keep it in the slot. The slot index is the first script operand.
 */
int func_021AE948(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 slotIndex;
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    ScriptTrainerSlot *slot;

    scriptWork = func_0215A5F4(cmdWork);
    fieldParam = func_02158F58(scriptWork);
    slotIndex = func_02159B10(vm, cmdWork);
    if (slotIndex == 0) {
        slot = func_02159124(scriptWork, 0);
    } else if (slotIndex == 1) {
        slot = func_02159124(scriptWork, 1);
    }
    slot->eyeWork = func_021AE454(func_0215A5CC(cmdWork), fieldParam->fieldSystem, &slot->hit, slotIndex);
    return 0;
}

/* Script command: run the event that makes both trainers walk up to the player together. */
int func_021AE994(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    ScriptTrainerSlot *firstSlot = func_02159124(scriptWork, 0);
    ScriptTrainerSlot *secondSlot = func_02159124(scriptWork, 1);

    func_0215897C(scriptWork, func_021AE430(func_0215A5DC(cmdWork), firstSlot->eyeWork, secondSlot->eyeWork));
    return 1;
}

/* Script command: store the hit kind of trainer slot 0 in a script variable. */
int func_021AE9CC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ScriptTrainerSlot *slot = func_02159124(func_0215A5F4(cmdWork), 0);

    *func_02159AE8(vm, cmdWork) = slot->hit.hitKind;
    return 0;
}

/* Script command: store the trainer id of slot 0 or 1 (0 when the slot index is invalid). */
int func_021AE9F0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 slotIndex;
    ScriptWork *scriptWork;
    u16 *result;
    ScriptTrainerSlot *slot;

    scriptWork = func_0215A5F4(cmdWork);
    slotIndex = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    slot = 0;
    if (slotIndex == 0) {
        slot = func_02159124(scriptWork, 0);
    } else if (slotIndex == 1) {
        slot = func_02159124(scriptWork, 1);
    }
    *result = slot ? slot->hit.trainerId : 0;
    return 0;
}

/* Script command: store the field object id of the trainer in slot 0 or 1 (0 when invalid). */
int func_021AEA3C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 slotIndex;
    ScriptWork *scriptWork;
    u16 *result;
    ScriptTrainerSlot *slot;

    scriptWork = func_0215A5F4(cmdWork);
    slotIndex = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    slot = 0;
    if (slotIndex == 0) {
        slot = func_02159124(scriptWork, 0);
    } else if (slotIndex == 1) {
        slot = func_02159124(scriptWork, 1);
    }
    *result = slot ? func_0216D588(slot->hit.trainer) : 0;
    return 0;
}

/* Script command: store the trainer id that belongs to the running script id. */
int func_021AEA8C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    u32 scriptId;

    func_02158F58(scriptWork);
    scriptId = func_02158F8C(scriptWork);
    *func_02159AE8(vm, cmdWork) = func_0215A460(scriptId);
    return 0;
}

/*
 * Script command: start a trainer battle. Operands: trainer id, second
 * trainer id, third trainer id. The battle kind comes from the trainer id;
 * a double battle trainer without a second id uses its own id twice.
 * The casts on the func_0215A4C8 call keep the register allocation of the
 * original (without them the first two operands swap registers).
 */
int func_021AEABC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    u32 trainerId, secondTrainerId, thirdTrainerId, battleKind;

    scriptWork = func_0215A5F4(cmdWork);
    func_02158F8C(scriptWork);
    trainerId = func_02159B10(vm, cmdWork);
    secondTrainerId = func_02159B10(vm, cmdWork);
    thirdTrainerId = func_02159B10(vm, cmdWork);
    battleKind = (u32)func_0215A4C8((u32)trainerId);
    if (secondTrainerId == 0 && func_0215A4B4(trainerId) == 1) {
        secondTrainerId = trainerId;
    }
    func_0215897C(scriptWork, func_0216E818(func_02158F54(scriptWork), func_02158F58(scriptWork)->fieldSystem, battleKind, 0, trainerId, secondTrainerId, thirdTrainerId));
    func_021AEDAC(cmdWork);
    return 1;
}

/* Script command: start a multi battle (kind 1) with an ally and three trainer ids read from the script. */
int func_021AEB3C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 allyTrainerId, trainerId, secondTrainerId, thirdTrainerId;
    ScriptWork *scriptWork;

    scriptWork = func_0215A5F4(cmdWork);
    func_02158F8C(scriptWork);
    allyTrainerId = func_02159B10(vm, cmdWork);
    trainerId = func_02159B10(vm, cmdWork);
    secondTrainerId = func_02159B10(vm, cmdWork);
    thirdTrainerId = func_02159B10(vm, cmdWork);
    func_0215897C(scriptWork, func_0216E818(func_02158F54(scriptWork), func_02158F58(scriptWork)->fieldSystem, 1, allyTrainerId, trainerId, secondTrainerId, thirdTrainerId));
    func_021AEDAC(cmdWork);
    return 1;
}

/*
 * Script command: store three message indices of the running trainer script:
 * one set for a single battle trainer, one for a pair when the script id
 * test func_0215A4A0 is 0, one for the other pairs.
 */
int func_021AEBB0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 scriptId;
    u16 *firstResult, *secondResult, *thirdResult;
    u32 firstMsg, secondMsg, thirdMsg;

    scriptId = func_02158F8C(func_0215A5F4(cmdWork));
    firstResult = func_02159AE8(vm, cmdWork);
    secondResult = func_02159AE8(vm, cmdWork);
    thirdResult = func_02159AE8(vm, cmdWork);
    if ((u16)func_0215A4B4(func_0215A460(scriptId)) == 0) {
        firstMsg = 0;
        secondMsg = 2;
        thirdMsg = 24;
    } else if ((u16)func_0215A4A0(scriptId) == 0) {
        firstMsg = 3;
        secondMsg = 5;
        thirdMsg = 6;
    } else {
        firstMsg = 7;
        secondMsg = 9;
        thirdMsg = 10;
    }
    *firstResult = firstMsg;
    *secondResult = secondMsg;
    *thirdResult = thirdMsg;
    return 0;
}

/* Script command: store the battle kind of a trainer id. */
int func_021AEC1C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 trainerId = func_02159B10(vm, cmdWork);

    *func_02159AE8(vm, cmdWork) = func_0215A4C8(trainerId);
    return 0;
}

/*
 * Script command: play the encounter BGM of the trainer class of a trainer
 * id (the BGM change is queued as an event of the script).
 *
 * Compiled 66 of a 68-byte extent: the trailing halfword is an unlabelled
 * follower.
 *
 * Addresses are Black-image addresses.
 */
int func_021AEC40(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    func_0215A5E4(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    func_0215897C(scriptWork, func_02029AF4(gameSystem, func_02029E20(func_0202A230(func_02159B10(vm, cmdWork), 1))));
    return 1;
}

/* Script command: fade the field in again (event of the field map control). */
int func_021AEC84(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);

    func_0215897C(scriptWork, func_021BE92C(gameSystem, func_0201210C(gameSystem), 0, 0, 1, 0, 0));
    return 1;
}

/* Script command: store 1 or 2 when the trainer id has trainer data flag 9 or 11, else 0. */
int func_021AECC0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 trainerId;
    u16 *result;
    u32 kind;

    trainerId = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    if (func_0202A230(trainerId, 9)) {
        kind = 1;
    } else if (func_0202A230(trainerId, 11)) {
        kind = 2;
    } else {
        kind = 0;
    }
    *result = kind;
    return 0;
}

/* Script command: store trainer data field 11 of a trainer id. */
int func_021AED00(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 trainerId = func_02159B10(vm, cmdWork);

    *func_02159AE8(vm, cmdWork) = func_0202A230(trainerId, 0xb);
    return 0;
}

/*
 * Script command: start a battle that also carries a Pokemon (event
 * 0216EAB0). Operands: four values passed on to the event.
 *
 * The four func_02159B10 results are u16 locals (the callee returns u16):
 * with u32 locals the stack-argument stores for func_0216EAB0 schedule
 * after the r1/r2 setup instead of before it.
 * Addresses are Black-image addresses.
 */
int func_021AED24(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 battleKind;
    ScriptWork *scriptWork;
    u16 trainerId, secondTrainerId, thirdTrainerId, fourthTrainerId;

    scriptWork = func_0215A5F4(cmdWork);
    func_02158F8C(scriptWork);
    trainerId = func_02159B10(vm, cmdWork);
    secondTrainerId = func_02159B10(vm, cmdWork);
    thirdTrainerId = func_02159B10(vm, cmdWork);
    fourthTrainerId = func_02159B10(vm, cmdWork);
    battleKind = func_0215A4C8(trainerId);
    if (secondTrainerId == 0 && func_0215A4B4(trainerId) == 1) {
        secondTrainerId = trainerId;
    }
    func_0215897C(scriptWork, func_0216EAB0(func_02158F54(scriptWork), func_02158F58(scriptWork)->fieldSystem, battleKind, 0, trainerId, secondTrainerId, thirdTrainerId, fourthTrainerId));
    return 1;
}

/* Adds one to the trainer record counter 0x20 when the zone is in the zone table of func_02014024. */
void func_021AEDAC(struct ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam = func_02158F58(func_0215A5F4(cmdWork));
    struct TrainerRecord *record = func_02012F2C(func_0215A5E4(cmdWork));

    if (func_02014024(func_02188C9C(fieldParam->fieldSystem)) != 0)
        func_02008DF0(record, 0x20);
}

/* Script command: fade out the BGM and play another one (operand: BGM number). */
int func_021AEDE0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    func_0215897C(scriptWork, func_02029984(gameSystem, func_02011330(vm)));
    func_02028BA0(func_02012A30(func_020120F4(gameSystem)), 2);
    func_02159144(13);
    return 1;
}

/* Script command: as above with a fade length (operands: BGM number, fade frames). */
int func_021AEE28(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    ScriptWork *scriptWork;
    struct GameEvent *event;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    event = func_02029A04(gameSystem, func_02011330(vm), func_02011330(vm));
    func_0215897C(scriptWork, event);
    func_02028BA0(func_02012A30(func_020120F4(gameSystem)), 2);
    func_02159144(13);
    return 1;
}

/* Script command: fade out the BGM and play the fixed BGM (operand: BGM number). */
int func_021AEE78(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameEvent *event;
    struct GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    event = func_02029A74(gameSystem, func_02011330(vm));
    func_0215897C(scriptWork, event);
    func_02028BA0(func_02012A30(func_020120F4(gameSystem)), 2);
    func_02159144(13);
    return 1;
}

/* Script command: store whether a BGM is playing. */
int func_021AEEC0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_02011330(vm);
    *func_02159AE8(vm, cmdWork) = func_02005F38();
    return 0;
}

/* Wait function: done when no BGM plays. */
int func_021AEEE0(ScriptVm *vm, void *user)
{
    struct ScrcmdWork *cmdWork = user;

    func_0215A5DC(cmdWork);
    func_0215A5F4(cmdWork);
    if (func_02005F38() == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait until the BGM stops. */
int func_021AEF00(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021AEEE0);
    return 1;
}

/* Script command: fade the BGM volume to a level over a number of frames, then set check flag 12. */
int func_021AEF10(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 level;
    struct GameData *gameData;
    struct GameSystem *gameSystem;
    struct FieldSoundSystem *soundSystem;

    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    func_0201210C(gameSystem);
    soundSystem = func_02012A30(gameData);
    level = func_02159B10(vm, cmdWork);
    func_02028A58(soundSystem, level, (u8)func_02159B10(vm, cmdWork));
    func_02159144(12);
    return 0;
}

/* Script command: bring the BGM volume back to the maximum (0x7F) over a number of frames, then clear check flag 12. */
int func_021AEF60(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    struct GameSystem *gameSystem;
    struct FieldSoundSystem *soundSystem;

    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    func_0201210C(gameSystem);
    soundSystem = func_02012A30(gameData);
    func_02028A58(soundSystem, 0x7f, (u8)func_02159B10(vm, cmdWork));
    func_02159168(12);
    return 0;
}

/* Event function: restore the BGM volume at once, then finish. */
int func_021AEFA4(BgmEventWork *work, u32 *seq)
{
    struct FieldSoundSystem *soundSystem = func_02012A30(func_020120F4(work->gameSystem));

    switch (*seq) {
    case 0:
        func_02028A58(soundSystem, 0x7f, 0);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

/*
 * Script command: bring back the BGM of the current zone (fade out 90
 * frames, fade in 60 frames).
 *
 * Literal pool word 0x02029EB5 (an arm9 leaf address) has no witness outside this range.
 *
 * Addresses are Black-image addresses.
 */
int func_021AEFD8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 season, zoneBgm;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    struct FieldSoundSystem *soundSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    soundSystem = func_02012A30(gameData);
    scriptWork = func_0215A5F4(cmdWork);
    season = func_02012984(gameData);
    zoneBgm = func_02029DF4(gameData, func_02188C9C(fieldMap), season);
    func_0215897C(scriptWork, func_020298A0(gameSystem, zoneBgm, 0x5a, 0x3c));
    func_02028BDC(soundSystem, 2);
    func_02159168(13);
    return 1;
}

/* Script command: as above with the fade out length read from the script. */
int func_021AF044(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 season, fadeOutFrames, zoneBgm;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    struct FieldSoundSystem *soundSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    soundSystem = func_02012A30(gameData);
    scriptWork = func_0215A5F4(cmdWork);
    fadeOutFrames = func_02011330(vm);
    season = func_02012984(gameData);
    zoneBgm = func_02029DF4(gameData, func_02188C9C(fieldMap), season);
    func_0215897C(scriptWork, func_020298A0(gameSystem, zoneBgm, fadeOutFrames, 0x3c));
    func_02028BDC(soundSystem, 2);
    func_02159168(13);
    return 1;
}

/* Script command: push the current BGM and play another one, then wait (operand: BGM number). */
int func_021AF0BC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    ScriptWork *scriptWork;

    func_020120F4(gameSystem);
    func_0201210C(gameSystem);
    scriptWork = func_0215A5F4(cmdWork);
    func_0215897C(scriptWork, func_02029AF4(gameSystem, func_02159B10(vm, cmdWork)));
    return 1;
}

/* Script command: push the current BGM (operand: BGM number), then set check flag 10. */
int func_021AF0F8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);

    func_0215897C(scriptWork, func_020295A4(gameSystem, func_02159B10(vm, cmdWork)));
    func_02159144(10);
    return 1;
}

/* Script command: pop the pushed BGM, then clear check flag 10. */
int func_021AF130(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 firstOperand;
    struct GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    firstOperand = func_02159B10(vm, cmdWork);
    func_0215897C(scriptWork, func_02029620(gameSystem, firstOperand, func_02159B10(vm, cmdWork)));
    func_02159168(10);
    return 1;
}

/* Event function: queue the pop BGM event on the script, then finish. */
int func_021AF174(BgmEventWork *work, u32 *seq)
{
    ScriptWork *scriptWork = work->scriptWork;

    func_02158F58(scriptWork);
    switch (*seq) {
    case 0:
        func_0215897C(scriptWork, func_02029620(work->gameSystem, 0, 0));
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

/* Script command: resume the BGM slots of mask 2, then clear check flag 13. */
int func_021AF1B0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_02028BDC(func_02012A30(func_020120F4(func_0215A5DC(cmdWork))), 2);
    func_02159168(13);
    return 0;
}

/* Event function: resume the BGM slots of mask 2 and finish. */
int func_021AF1D0(BgmEventWork *work, u32 *seq)
{
    func_02028BDC(func_02012A30(func_020120F4(work->gameSystem)), 2);
    return 1;
}

/* Sound effect slots a script started: one bit per slot (5 slots) in the trainer parameter byte of the script work. */

/* Clears the bits of the sound effect slots that no longer play. */
void func_021AF1E8(ScriptWork *scriptWork)
{
    int slot;
    u8 *seSlotMask;

    seSlotMask = func_02158F88(scriptWork);
    for (slot = 0; slot < 5; slot++) {
        if (*seSlotMask & (1 << slot)) {
            if (func_02006224(slot) == 0)
                *seSlotMask &= ~(1 << slot);
        }
    }
}

/* Sets the bit of the slot that plays a sound effect. */
void func_021AF21C(ScriptWork *scriptWork, u32 seNo)
{
    u8 *seSlotMask = func_02158F88(scriptWork);

    *seSlotMask |= 1 << func_02006148(seNo);
}

/* Returns 1 when a marked slot still plays; otherwise clears the marks and returns 0. */
int func_021AF23C(ScriptWork *scriptWork)
{
    int slot;
    u8 *seSlotMask;

    seSlotMask = func_02158F88(scriptWork);
    for (slot = 0; slot < 5; slot++) {
        if (*seSlotMask & (1 << slot)) {
            if (func_02006224(slot) == 1)
                return 1;
        }
    }
    *seSlotMask = 0;
    return 0;
}

/* Stops every marked slot and clears the marks. */
void func_021AF26C(ScriptWork *scriptWork)
{
    int slot;
    u8 *seSlotMask;

    seSlotMask = func_02158F88(scriptWork);
    for (slot = 0; slot < 5; slot++) {
        if (*seSlotMask & (1 << slot))
            func_020061F8(slot);
    }
    *seSlotMask = 0;
}

/* Script command: play a sound effect (operand: SE number) and remember its slot. */
int func_021AF294(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 seNo = func_02159B10(vm, cmdWork);
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);

    func_021AF1E8(scriptWork);
    func_020061E4(seNo);
    func_021AF21C(scriptWork, seNo);
    return 0;
}

/* Script command: stop the sound effects this script started. */
int func_021AF2BC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_021AF26C(func_0215A5F4(cmdWork));
    return 0;
}

/* Wait function: done when none of the marked sound effect slots plays. */
int func_021AF2CC(ScriptVm *vm, void *user)
{
    struct ScrcmdWork *cmdWork = user;

    if (func_021AF23C(func_0215A5F4(cmdWork)) == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait for the sound effects this script started. */
int func_021AF2E4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021AF2CC);
    return 1;
}

/* Script command: push the current BGM and play another one (operand: BGM number). */
int func_021AF2F4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);

    func_0215897C(scriptWork, func_02029830(gameSystem, func_02011330(vm)));
    return 1;
}

/* Wait function: when the BGM stopped and the sound system is idle, queue the pop BGM event. */
int func_021AF324(ScriptVm *vm, void *user)
{
    struct ScrcmdWork *cmdWork = user;
    struct FieldSoundSystem *soundSystem;
    struct GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    soundSystem = func_02012A30(func_020120F4(gameSystem));
    if (func_02005F38() == 0 && func_020289B8(soundSystem) == 0) {
        func_0215897C(scriptWork, func_02029620(gameSystem, 0, 6));
        return 1;
    }
    return 0;
}

/* Script command: start waiting with func_021AF324. */
int func_021AF370(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021AF324);
    return 1;
}

/* Script command: play the voice of a Pokemon (operands: species, form) from a game event. */
int func_021AF380(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 species, form;
    struct GameEvent *event;
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    PokeVoiceWork *voiceWork;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    event = func_020122C0(gameSystem, 0, func_021AF4E8, 12);
    voiceWork = func_020124E8(event);
    voiceWork->species = species;
    voiceWork->form = form;
    voiceWork->usePerapVoice = 0;
    voiceWork->cmdWork = cmdWork;
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: as above, but plays the recorded voice of the voice save. */
int func_021AF3D8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 species, form;
    struct GameEvent *event;
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    PokeVoiceWork *voiceWork;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    event = func_020122C0(gameSystem, 0, func_021AF4E8, 12);
    voiceWork = func_020124E8(event);
    voiceWork->species = species;
    voiceWork->form = form;
    voiceWork->usePerapVoice = 1;
    voiceWork->cmdWork = cmdWork;
    func_0215897C(scriptWork, event);
    return 1;
}

/*
 * Wait function: done when the Pokemon voice started by the command above
 * stopped (its voice handle sits in the fade parameter of the script command
 * work).
 *
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A6AC (0x0215A6AC) is a matched manifest entry, so the "matched"
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AF430(ScriptVm *vm, void *user)
{
    struct ScrcmdWork *cmdWork = user;

    if (func_02006BD0(func_0215A6AC(cmdWork)) == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait until the Pokemon voice ends. */
int func_021AF448(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021AF430);
    return 1;
}

/* Script command: switch an ISS (area sound) switch on (operand: switch number). */
int func_021AF458(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct IssSwitchSys *switchSys = func_0202B578(func_02012134(func_0215A5DC(cmdWork)));

    func_0202C0D0(switchSys, func_02159B10(vm, cmdWork));
    return 0;
}

/* Script command: switch an ISS switch off (operand: switch number). */
int func_021AF484(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct IssSwitchSys *switchSys = func_0202B578(func_02012134(func_0215A5DC(cmdWork)));

    func_0202C0E4(switchSys, func_02159B10(vm, cmdWork));
    return 0;
}

/* Script command: store whether an ISS switch is on (operand: switch number). */
int func_021AF4B0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct IssSwitchSys *switchSys = func_0202B578(func_02012134(func_0215A5DC(cmdWork)));

    *func_02159AE8(vm, cmdWork) = func_0202C0F8(switchSys, func_02159B10(vm, cmdWork));
    return 0;
}

/* Event function: start the Pokemon voice once the loader is free, and hand the voice handle to the script command work. */
int func_021AF4E8(void *event, u32 *seq, PokeVoiceWork *work)
{
    u32 voiceSave, voiceHandle;

    if (func_02005C64()) {
        return 0;
    }
    if (work->usePerapVoice) {
        u32 species, form;
        form = work->form;
        species = work->species;
        func_02006CAC((void **)(&voiceSave));
        voiceHandle = func_02006984(species, form, 0x40, 0, 0, 0, 0, (u32)(&voiceSave));
    } else {
        voiceHandle = func_02006984(work->species, work->form, 0x40, 0, 0, 0, 0, 0);
    }
    func_0215A6B8(work->cmdWork, voiceHandle);
    return 1;
}

/* Script command: add items to the bag (operands: item, count); stores whether it worked. */
int func_021AF544(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId;
    struct MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    heapId = func_0215A5CC(cmdWork);
    myItem = func_0201292C(func_0215A5E4(cmdWork));
    itemNo = func_02159B10(vm, cmdWork);
    count = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    *result = func_02007E50(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: remove items from the bag (operands: item, count); stores the result. */
int func_021AF594(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId = func_0215A5CC(cmdWork);
    struct MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    myItem = func_0201292C(func_0215A5E4(cmdWork));
    itemNo = func_02159B10(vm, cmdWork);
    count = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    *result = func_02007F1C(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: store whether the bag has room for items (operands: item, count). */
int func_021AF5E4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId = func_0215A5CC(cmdWork);
    struct MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    myItem = func_0201292C(func_0215A5E4(cmdWork));
    itemNo = func_02159B10(vm, cmdWork);
    count = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    *result = func_02007E3C(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: store whether the bag holds at least a number of an item (operands: item, count). */
int func_021AF634(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId = func_0215A5CC(cmdWork);
    struct MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    myItem = func_0201292C(func_0215A5E4(cmdWork));
    itemNo = func_02159B10(vm, cmdWork);
    count = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    *result = func_02007F68(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: store how many of an item the bag holds (operand: item). */
int func_021AF684(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId = func_0215A5CC(cmdWork);
    struct MyItem *myItem;
    u32 itemNo;
    u16 *result;

    myItem = func_0201292C(func_0215A5E4(cmdWork));
    itemNo = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    *result = func_02007FB8(myItem, itemNo, heapId);
    return 0;
}

/* Script command: store the machine flag of an item (operand: item). */
int func_021AF6C4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 itemNo = func_02159B10(vm, cmdWork);

    *func_02159AE8(vm, cmdWork) = func_021AF750(itemNo);
    return 0;
}

/* Script command: store the bag pocket of an item (operand: item). */
int func_021AF6E8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId = func_0215A5CC(cmdWork);
    u32 itemNo = func_02159B10(vm, cmdWork);

    *func_02159AE8(vm, cmdWork) = func_02020FE4(itemNo, 5, heapId);
    return 0;
}

/* Script command: store item parameter 15 (operand: item). */
int func_021AF71C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 heapId = func_0215A5CC(cmdWork);
    u32 itemNo = func_02159B10(vm, cmdWork);

    *func_02159AE8(vm, cmdWork) = func_02020FE4(itemNo, 0xf, heapId);
    return 0;
}

/* Returns the machine flag of an item as a halfword. */
int func_021AF750(u32 itemNo)
{
    return ((func_02021288(itemNo) << 16) >> 16);
}

