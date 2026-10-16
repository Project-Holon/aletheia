/*
 * file:     iss_switch_sys.c
 * unit:     yes
 * function: ISS_SWITCH_SYS_Create, ISS_SWITCH_SYS_Delete, ISS_SWITCH_SYS_Main, ISS_SWITCH_SYS_On, ISS_SWITCH_SYS_Off, ISS_SWITCH_SYS_ZoneChange, ISS_SWITCH_SYS_SwitchOn, ISS_SWITCH_SYS_SwitchOff, ISS_SWITCH_SYS_IsSwitchOn, ISS_SWITCH_SYS_ResetSwitch, ISS_SWITCH_SYS_Init, ISS_SWITCH_SYS_Alloc, ISS_SWITCH_SYS_Free, ISS_SWITCH_SYS_CreateSets, ISS_SWITCH_SYS_DeleteSets, ISS_SWITCH_SYS_UpdateActiveSet, ISS_SWITCH_SYS_TurnOn, ISS_SWITCH_SYS_TurnOff, ISS_SWITCH_SYS_CheckZoneChange, ISS_SWITCH_SYS_GetSetCount, ISS_SWITCH_SYS_GetSet, ISS_SWITCH_SYS_GetActiveSet, ISS_SWITCH_SYS_IsActiveSetZone, ISS_SWITCH_SYS_FindSetByBgm, ISS_SWITCH_SYS_ChangeActiveSet, ISS_SWITCH_SYS_UpdateVolume, ISS_SWITCH_SYS_GetPlayingBgm, ISS_SWITCH_SYS_IsOn, ISS_SWITCH_SYS_ResetActiveSet, ISS_SWITCH_SET_Create, ISS_SWITCH_SET_Delete, ISS_SWITCH_SET_Load, ISS_SWITCH_SET_Main, ISS_SWITCH_SET_SwitchOn, ISS_SWITCH_SET_SwitchOff, ISS_SWITCH_SET_ResetSwitch, ISS_SWITCH_SET_GetBgmNo, ISS_SWITCH_SET_IsValidZone, ISS_SWITCH_SET_IsSwitchOn, ISS_SWITCH_SET_UpdateVolume, ISS_SWITCH_SET_Init
 * address:  0x0202C070
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   IssSwitchSysFileName     0x020A7758  data
 *   func_020307B0  0x020307B0  arm
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   ISS_SWITCH_SET_Alloc 0x0202C384 thumb arm9
 *   ISS_SWITCH_SET_Free 0x0202C3A0 thumb arm9
 *   ISS_SWITCH_SET_CreateSwitches 0x0202C3A8 thumb arm9
 *   ISS_SWITCH_SET_DeleteSwitches 0x0202C3C4 thumb arm9
 *   ISS_SWITCH_SET_LoadData 0x0202C3E0 thumb arm9
 *   ISS_SWITCH_SET_UpdateSwitches 0x0202C470 thumb arm9
 *   ISS_SWITCH_SET_StartSwitchOn 0x0202C48C thumb arm9
 *   ISS_SWITCH_SET_StartSwitchOff 0x0202C498 thumb arm9
 *   ISS_SWITCH_SET_ResetSwitches 0x0202C4A4 thumb arm9
 *   ISS_SWITCH_SET_ReadBgmNo 0x0202C4C8 thumb arm9
 *   ISS_SWITCH_SET_CheckZone 0x0202C4D8 thumb arm9
 *   ISS_SWITCH_SET_CheckSwitchOn 0x0202C504 thumb arm9
 *   ISS_SWITCH_SET_ApplySwitchVolumes 0x0202C518 thumb arm9
 */
#include "iss_switch_sys_shared_types.h"

struct IssSwitchSys;

struct IssSwitchSys {
    u32 isOn;
    u8  setCount;
    u8  pad_05[3];
    struct IssSwitchSet **sets;
    struct IssSwitchSet *activeSet;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);

extern u16 GFL_USE_GetBgmNo(void);

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

u32 ISS_SWITCH_SET_CheckZone(void *set, u32 zoneId);

u32 ISS_SWITCH_SET_CheckSwitchOn(void *set, u32 switchIdx);

void ISS_SWITCH_SET_ApplySwitchVolumes(void *set);

extern const char IssSwitchSysFileName[];

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
