/*
 * file:     battle_examination.c
 * unit:     yes
 * function: BATTLE_EXAMINATION_GetBlockSize, BATTLE_EXAMINATION_ClearBlock, BATTLE_EXAMINATION_IsDeliveryValid, BATTLE_EXAMINATION_IsDeliveryUnused, BATTLE_EXAMINATION_GetDeliveryId, BATTLE_EXAMINATION_GetTrainerSlot, BATTLE_EXAMINATION_LoadDelivery, BATTLE_EXAMINATION_RefreshMarker, BATTLE_EXAMINATION_GetGreetingSize, BATTLE_EXAMINATION_InitGreetings
 * address:  0x0200E588
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   data_020A721C  0x020A721C  data
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   OS_WaitIrq     0x0208459C  arm
 *   SAVE_CONTROL_DeleteExtraSaveBuffered  0x0200734C  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PMSI_PARAM_SetDefaultGreeting  0x02024344  thumb
 *   PMSI_PARAM_SetDefaultSentence  0x020242D8  thumb
 */
#include "misc_savedata_shared_types.h"

/* Struct views of the save objects this file works on, defined here instead of
 * in a match/include/ObjNNNNN.h stand-in. */
struct TrialHouseDelivery;

struct Big;

struct Sub02007324Ctrl;

/* Save block 5, 0x5C8 bytes: the wireless-delivered trainer data read by the
 * battle examination code (ov021 TrialHouseDelivery). */
struct TrialHouseDelivery {
    u8  pad[0x5C2];
    u16 magic;      /* +0x5C2, 0xD68 while the slot holds valid data */
    u16 idAndUsed;  /* +0x5C4, delivery id in bits 0..6, bit 15 marks a used slot */
    u16 checksum;   /* +0x5C6 */
};

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);

extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern int SAVE_CONTROL_LoadExtraSaveWithBuffer(u32 sv, u32 id, u32 heap, void *buf, u32 size);

extern void GAME_DATA_PartSaveStart(u8 *p, u32 id);

extern int GAME_DATA_PartSaveMain(char *p, int partId);

extern void OS_WaitIrq(int clear, u32 mask);

extern void SAVE_CONTROL_DeleteExtraSaveBuffered(struct Sub02007324Ctrl *ctrl, u32 id);

extern u32 GFL_HEAP_Free(void *p);

extern void PMSI_PARAM_SetDefaultGreeting(void *obj);

extern void PMSI_PARAM_SetDefaultSentence(void *slot, u32 idx);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

u32 BATTLE_EXAMINATION_GetBlockSize(void);

void BATTLE_EXAMINATION_ClearBlock(void *p);

int BATTLE_EXAMINATION_IsDeliveryValid(void *delivery);

int BATTLE_EXAMINATION_IsDeliveryUnused(void *p);

u16 BATTLE_EXAMINATION_GetDeliveryId(void *p);

char *BATTLE_EXAMINATION_GetTrainerSlot(char *p, u32 idx);

void BATTLE_EXAMINATION_LoadDelivery(void *sys, void *dst, u32 heap);

void BATTLE_EXAMINATION_RefreshMarker(void *obj);

u32 BATTLE_EXAMINATION_GetGreetingSize(void);

void BATTLE_EXAMINATION_InitGreetings(void *obj);

extern const char data_020A721C[];

/*
 * Unlabelled arm9 leaf returning the constant 0x5C8 (a structure size); filed
 * as the relocation witness for ov021 callers 021D096C, 021D0BE4, 021D10A8
 * (wave A1).
 */
u32 BATTLE_EXAMINATION_GetBlockSize(void)
{
    return 0x5C8;
}

/*
 * Clears the 0x5C8-byte save block (BATTLE_EXAMINATION_GetBlockSize returns its size):
 * a tail call to MI_CpuFill8(p, 0, 0x5C8).
 */
void BATTLE_EXAMINATION_ClearBlock(void *p)
{
    MI_CpuFill8(p, 0, 0x5C8);
}

/*
 * The two tests share one exit, so they have to be one conjunction with the
 * `return 0` written after it; as two separate `if (...) return 0;` statements
 * the compiler emits two copies of the `movs r0, #0; pop` pair and lands 28
 * bytes wrong.  EXACT*: the listing extent runs to the next label at
 * 0x0200E688, over three unlabelled followers.
 */
int BATTLE_EXAMINATION_IsDeliveryValid(void *delivery)
{
    if (((struct TrialHouseDelivery *)delivery)->checksum == GF_STANDARD_SetupCalc(delivery, 0x5c6) &&
        ((struct TrialHouseDelivery *)delivery)->magic == 0xd68)
        return 1;
    return 0;
}

/*
 * Unlabelled arm9 leaf: true when bit 15 of the halfword at +0x5C4 is clear.
 * Filed as the relocation witness for ov021 TRIAL_HOUSE_LoadDeliveryState (wave A1).
 */
int BATTLE_EXAMINATION_IsDeliveryUnused(void *delivery)
{
    if (((struct TrialHouseDelivery *)delivery)->idAndUsed & 0x8000) {
        return 0;
    }
    return 1;
}

/*
 * Unlabelled arm9 leaf: the low seven bits of the halfword at +0x5C4. Filed
 * as the relocation witness for ov021 TRIAL_HOUSE_DeliveryTaskMain (wave A1).
 */
u16 BATTLE_EXAMINATION_GetDeliveryId(void *delivery)
{
    return ((struct TrialHouseDelivery *)delivery)->idAndUsed & 0x7F;
}

/*
 * Unlabelled arm9 leaf: element idx of a five-entry array of 0x120 byte
 * records, the base itself when idx is out of range. Filed as the relocation
 * witness for ov021 TRIAL_HOUSE_LoadDeliveredTrainer (wave A1).
 */
char *BATTLE_EXAMINATION_GetTrainerSlot(char *base, u32 index)
{
    if (index < 5) {
        base += index * 0x120;
    }
    return base;
}

/*
 * Unlabelled arm9 function: loads save block 5 into a 0x1000 byte heap buffer,
 * copies its first 0x5C8 bytes to dst, then starts a save of block 5 and spins
 * on OS_WaitIrq until it reports done. Filed as the relocation witness for
 * ov021 TRIAL_HOUSE_DeliveryTaskMain (wave A1).
 */
void BATTLE_EXAMINATION_LoadDelivery(void *gameData, void *dst, u32 heap)
{
    u32 sv = (u32)GAME_DATA_GetSaveControl(gameData);
    void *buf = GFL_HEAP_Alloc(heap, 0x1000, 0, data_020A721C, 0x99);

    SAVE_CONTROL_LoadExtraSaveWithBuffer(sv, 5, heap, buf, 0x1000);
    MI_CpuCopy8(dst, buf, 0x5C8);
    GAME_DATA_PartSaveStart(gameData, 5);
    for (;;) {
        if (GAME_DATA_PartSaveMain(gameData, 5) == 2) {
            break;
        }
        OS_WaitIrq(1, 1);
    }
    SAVE_CONTROL_DeleteExtraSaveBuffered((struct Sub02007324Ctrl *)sv, 5);
    GFL_HEAP_Free(buf);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: BATTLE_EXAMINATION_RefreshMarker toggles one flag half of a caller object's field pair
 * addressed by the constant id 0x5c6: it looks the field up through
 * GF_STANDARD_SetupCalc, and if the stored halfword at +0x5c6 already equals the
 * looked-up value, rewrites the paired halfword at +0x5c2 with the constant
 * 0x7da and refreshes +0x5c6 with a second lookup.  BATTLE_EXAMINATION_GetGreetingSize is an
 * unlabelled getter returning the constant 0x28, sitting in what disasm.py
 * printed as trailing data after BATTLE_EXAMINATION_RefreshMarker because it carries no
 * register-saving prologue; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E684.c \
 *       --addr 0x0200E684 --thumb
 */
void BATTLE_EXAMINATION_RefreshMarker(void *delivery)
{
    u32 fieldId = 0x5c6;
    if (*(u16 *)((u8 *)delivery + fieldId) == GF_STANDARD_SetupCalc(delivery, fieldId)) {
        *(u16 *)((u8 *)delivery + (fieldId - 4)) = 0x7da;
        *(u16 *)((u8 *)delivery + fieldId) = GF_STANDARD_SetupCalc(delivery, fieldId);
    }
}

u32 BATTLE_EXAMINATION_GetGreetingSize(void)
{
    return 0x28;
}

/*
 * Promoted from src/pending/BATTLE_EXAMINATION_InitGreetings.c: every concrete byte was
 * already reproduced, and both callees were unresolved relocations
 * because each is called from exactly this one place in the whole ROM,
 * the case the honesty rule's cut remedy cannot reach (docs/MATCHING.md,
 * "the limit of the remedy"). Both are now EXACT entries in their own
 * right (src/matched/PMSI_PARAM_InitSentence.c's PMSI_PARAM_SetDefaultGreeting, and
 * src/matched/unit_020242D8.c's PMSI_PARAM_SetDefaultSentence), so the `matched` class
 * attests both calls without a second caller, and this file closes to
 * EXACT.
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte
 * slots starting at obj+8, tagging each with its index 0..3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BATTLE_EXAMINATION_InitGreetings.c \
 *       --func BATTLE_EXAMINATION_InitGreetings --addr 0x0200E6B4 --cc 1.1p1 --thumb
 */
void BATTLE_EXAMINATION_InitGreetings(void *greetings)
{
    PMSI_PARAM_SetDefaultGreeting(greetings);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 8, 0);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 0x10, 1);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 0x18, 2);
    greetings = (u8 *)greetings + 0x20;
    PMSI_PARAM_SetDefaultSentence(greetings, 3);
}
