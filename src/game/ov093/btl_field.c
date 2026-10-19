/*
 * file:     btl_field.c
 * unit:     yes
 * function: BTL_FIELD_ResetSlot, BTL_FIELD_ResetStatic, BTL_FIELD_GetCountdownValue, BTL_FIELD_GetCountdownCount, BTL_FIELD_SetCountdown, BTL_FIELD_TickCountdown, BTL_FIELD_RegisterStaticSlot, BTL_FIELD_RemoveStaticSlot, BTL_FIELD_AddStaticSlotHolder, BTL_FIELD_RemoveHolderFromStaticSlots, BTL_FIELD_IsMoveSealedByStaticSlot, BTL_FIELD_TickStaticSlots, BTL_FIELD_IsStaticSlotInUse, BTL_FIELD_Create, BTL_FIELD_Delete, BTL_FIELD_Init, BTL_FIELD_GetCountdownByte, BTL_FIELD_GetCountdownCountIfSet, BTL_FIELD_StoreCountdown, BTL_FIELD_ClearCountdown, BTL_FIELD_StepCountdown, BTL_FIELD_RegisterSlot, BTL_FIELD_RemoveSlot, BTL_FIELD_AddSlotHolder, BTL_FIELD_RemoveHolderFromSlots, BTL_FIELD_IsMoveSealedBySlot, BTL_FIELD_TickSlots, BTL_FIELD_IsSlotInUse
 * address:  0x021EF83C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   HAND_FIELD_AddFactor  0x06898020  thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTLV_SCU_StartMessage  0x021ECEB8  thumb  ov093
 *   BTLV_SCU_UpdateMessage   0x021ECF68  thumb  ov093
 *   FADE_Start  0x0204E720  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BTLV_SCU_IsFadeDone  0x021EB318  thumb  ov093
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BTL_POKEPARAM_ReadStatsFromMon  0x021D590C  thumb  ov093
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gBtlRecFileName  0x021F3ADC  data  a4
 *   GFL_HEAP_Free   0x020307B0  arm arm9
 *   MI_CpuCopy8  0x02082D44  arm
 *   BTL_ACTION_SetRecordError  0x021D8470  thumb
 *   BTL_ACTION_SetRecordReset  0x021D845C  thumb
 *   gBtlAdapterSlots  0x021F6388  data  a4
 *   gBtlAdapterMode  0x021F6384  data  a4
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   gBtlAdapterFileName     0x021F3AE8  data  ov093  a4
 *   BTL_NET_ExpectReplies   0x021D4C58  thumb
 *   BTL_NET_SendServerCmd  0x021D4B58  thumb  ov093
 *   BTL_NET_AreAllRepliesReceived  0x021D4B98  thumb  ov093
 *   BTL_NET_GetClientReply  0x021D4BD4  thumb  ov093
 *   BTL_NET_HasServerCmd  0x021D4C60  thumb  ov093
 *   BTL_NET_GetServerCmd  0x021D4C6C  thumb  ov093
 *   BTL_NET_SendClientReply  0x021D4C84  thumb  ov093
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   gBtlMsgFlags     0x021F63D8  data  ov093  a4
 *   sBtlMsgBankFileIds     0x021F3990  data  ov093  a2
 *   WORDSET_Delete  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 *   BTL_MAIN_GetTrainerType  0x021BA020  thumb  ov093
 *   WORDSET_SetSlotFromMsgBF  0x0201F0F8  thumb
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_MAIN_GetTrainerId  0x021BA004  thumb  ov093
 *   BTL_MAIN_GetTrainerNameAndType  0x021B9FAC  thumb  ov093
 *   BTL_MAIN_GetTrainerHandle  0x021BA064  thumb  ov093
 *   BTL_MAIN_UpdateCommPlayerSupport  0x021BA080  thumb  ov093
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb
 *   d_021F63C8     0x021F63C8  data  a4
 *   BTL_MAIN_IsLocalSide  0x021B8BD0  thumb  ov093
 *   sBtlMsgSidePairIds     0x021F39A0  data  a2
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   sBtlMsgBuilders  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PRINTSYS_GetTagChar  0x0201D5C4  thumb
 *   PRINTSYS_IsWordSlotTag  0x0201D5CC  thumb
 *   PRINTSYS_GetTagParam  0x0201D670  thumb
 *   PRINTSYS_GetTagGroup  0x0201D5F4  thumb
 *   PRINTSYS_GetTagKind  0x0201D658  thumb
 *   PRINTSYS_SkipTag  0x0201D688  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsgC7 0x0201F020 thumb
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsOpposingPos  0x021B8CE8  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_SICKCONT_MakeNone  0x021E8918  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 *   gBtlFieldFileName  0x021F3AF8  data  a4
 *   BTL_SICKCONT_GetPosition  0x021E8A98  thumb  ov093
 *   HAND_FIELD_RemoveFactor  0x06898080  thumb
 *   BTL_SICKCONT_SetPosition 0x021E8AC8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_POKEPARAM_HasMove  0x021D5750  thumb  ov093
 *   BTL_SICKCONT_GetLow  0x021E8AFC  thumb  ov093
 */
#include "btl_field_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
struct BtlEventFactor;
extern struct BtlEventFactor *HAND_FIELD_AddFactor(s32 effectId, s32 ownerId);
extern BtlFieldSlotKey BTL_SICKCONT_MakeNone(void);
extern u32 BTL_SICKCONT_GetPosition(BtlFieldSlotKey key);
extern void HAND_FIELD_RemoveFactor(struct BtlEventFactor *factor);
union BtlvSlot;
extern void BTL_SICKCONT_SetPosition(union BtlvSlot *slot, u8 pos);
struct BtlPokeParam;
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *pp);
extern int BTL_MAIN_IsPokeSamePair(u8 a, u8 b);
struct BtlSide;
extern struct BtlPokeParam *BTL_SIDE_GetPokeById(struct BtlSide *side, u8 pokeId);
extern int BTL_POKEPARAM_HasMove(struct BtlPokeParam *pp, u16 moveId);
extern u8 BTL_SICKCONT_GetLow(BtlFieldSlotKey key);
void BTL_FIELD_ResetSlot(BtlFieldState *state, u32 slot);
void BTL_FIELD_ResetStatic(int value);
int BTL_FIELD_GetCountdownValue(void);
int BTL_FIELD_GetCountdownCount(void);
int BTL_FIELD_SetCountdown(int value, int count);
u32 BTL_FIELD_TickCountdown(void);
int BTL_FIELD_RegisterStaticSlot(u32 slot, BtlFieldSlotKey key);
int BTL_FIELD_RemoveStaticSlot(int arg);
int BTL_FIELD_AddStaticSlotHolder(int slot, int value);
/* The wrappers below pass their words through unchanged, so they call the slot functions with plain word signatures. */
int BTL_FIELD_RemoveHolderFromStaticSlots(int arg);
void BTL_FIELD_IsMoveSealedByStaticSlot(int line, int color, char *text);
int BTL_FIELD_TickStaticSlots(int onExpire, int arg);
int BTL_FIELD_IsStaticSlotInUse(int arg);
BtlFieldState *BTL_FIELD_Create(u32 heapId);
void BTL_FIELD_Delete(void *state);
void BTL_FIELD_Init(BtlFieldState *state, u32 value);
u8 BTL_FIELD_GetCountdownByte(BtlFieldCountdown *countdown);
int BTL_FIELD_GetCountdownCountIfSet(BtlFieldCountdown *countdown);
int *BTL_FIELD_StoreCountdown(int *countdown, int value, int count);
void BTL_FIELD_ClearCountdown(int *countdown);
u32 BTL_FIELD_StepCountdown(BtlFieldCountdown *countdown);
int BTL_FIELD_RegisterSlot(BtlFieldState *state, u32 slot, BtlFieldSlotKey key, int allocHandle);
int BTL_FIELD_RemoveSlot(BtlFieldState *state, u32 slot);
int BTL_FIELD_AddSlotHolder(BtlFieldState *state, u32 slot, u32 pokeId);
void BTL_FIELD_RemoveHolderFromSlots(BtlFieldState *state, u32 pokeId);
int BTL_FIELD_IsMoveSealedBySlot(BtlFieldState *state, char *side, void *pokeParam, u16 moveId);
void BTL_FIELD_TickSlots(BtlFieldState *state, void (*onExpire)(u32, u32), u32 arg);
void *BTL_FIELD_IsSlotInUse(BtlFieldState *state, int slot);
extern BtlFieldState gBtlFieldCountdown;
extern char gBtlFieldFileName[];



void BTL_FIELD_ResetSlot(BtlFieldState *state, u32 slot)
{
    u32 j;

    state->effectHandle[slot] = 0;
    state->key[slot] = BTL_SICKCONT_MakeNone();
    state->elapsedTurns[slot] = 0;
    state->holderCount[slot] = 0;
    state->inUse[slot] = 0;
    for (j = 0; j < 6; j++)
        state->holderIds[slot][j] = 0x1f;
}



void BTL_FIELD_ResetStatic(int value)
{
    BTL_FIELD_Init(&gBtlFieldCountdown, value);
}



int BTL_FIELD_GetCountdownValue(void)
{
    return BTL_FIELD_GetCountdownByte(&gBtlFieldCountdown.countdown);
}



int BTL_FIELD_GetCountdownCount(void)
{
    return BTL_FIELD_GetCountdownCountIfSet(&gBtlFieldCountdown.countdown);
}



int BTL_FIELD_SetCountdown(int value, int count)
{
    return (int)BTL_FIELD_StoreCountdown((int *)&gBtlFieldCountdown.countdown, value, count);
}



/*
 * Tail call into the countdown step with the static state.
 */
u32 BTL_FIELD_TickCountdown(void)
{
    return BTL_FIELD_StepCountdown(&gBtlFieldCountdown.countdown);
}



int BTL_FIELD_RegisterStaticSlot(u32 slot, BtlFieldSlotKey key)
{
    return BTL_FIELD_RegisterSlot(&gBtlFieldCountdown, slot, key, 1);
}



int BTL_FIELD_RemoveStaticSlot(int arg)
{
    return BTL_FIELD_RemoveSlot(&gBtlFieldCountdown, arg);
}



int BTL_FIELD_AddStaticSlotHolder(int slot, int value)
{
    return BTL_FIELD_AddSlotHolder(&gBtlFieldCountdown, slot, value);
}



int BTL_FIELD_RemoveHolderFromStaticSlots(int arg)
{
    return ((int (*)(BtlFieldState *, int))BTL_FIELD_RemoveHolderFromSlots)(&gBtlFieldCountdown, arg);
}



void BTL_FIELD_IsMoveSealedByStaticSlot(int line, int color, char *text)
{
    ((int (*)(BtlFieldState *, int, int, char *))BTL_FIELD_IsMoveSealedBySlot)(&gBtlFieldCountdown, line, color, text);
}



int BTL_FIELD_TickStaticSlots(int onExpire, int arg)
{
    return ((int (*)(BtlFieldState *, int, int))BTL_FIELD_TickSlots)(&gBtlFieldCountdown, onExpire, arg);
}



int BTL_FIELD_IsStaticSlotInUse(int arg)
{
    return (int)BTL_FIELD_IsSlotInUse(&gBtlFieldCountdown, arg);
}



BtlFieldState *BTL_FIELD_Create(u32 heapId)
{
    BtlFieldState *state = GFL_HEAP_Alloc(heapId, 0x168, 1, gBtlFieldFileName, 0x10c);

    BTL_FIELD_Init(state, 0);
    return state;
}



void BTL_FIELD_Delete(void *state) { GFL_HEAP_Free(state); }



void BTL_FIELD_Init(BtlFieldState *state, u32 value)
{
    u32 i;

    for (i = 0; i < 8; i++)
        BTL_FIELD_ResetSlot(state, i);
    state->countdown.value = value;
    state->countdown.count = 0xff;
}



u8 BTL_FIELD_GetCountdownByte(BtlFieldCountdown *countdown) { return (u8)countdown->value; }



int BTL_FIELD_GetCountdownCountIfSet(BtlFieldCountdown *countdown)
{
    if (countdown->value != 0)
        return countdown->count;
    return 0;
}



int *BTL_FIELD_StoreCountdown(int *countdown, int value, int count)
{
    countdown[0] = value;
    countdown[1] = count;
    return countdown;
}



void BTL_FIELD_ClearCountdown(int *countdown)
{
    countdown[0] = 0;
    countdown[1] = 0;
}



/*
 * Countdown timer: when the value is set and the counter is not 0xff,
 * decrement the counter; when it reaches zero, clear the value and return
 * its low byte.
 */
u32 BTL_FIELD_StepCountdown(BtlFieldCountdown *countdown)
{
    u32 v = countdown->value;
    if (v != 0 && countdown->count != 0xff && --countdown->count == 0) {
        v = (u8)v;
        countdown->value = 0;
        return v;
    }
    return 0;
}



int BTL_FIELD_RegisterSlot(BtlFieldState *state, u32 slot, BtlFieldSlotKey key, int allocHandle)
{
    u32 i;
    u32 stat;

    if (state->inUse[slot] == 0) {
        if (allocHandle != 0) {
            state->effectHandle[slot] = (u32)HAND_FIELD_AddFactor(slot, 0);
            if (state->effectHandle[slot] == 0)
                return 0;
        }
        state->inUse[slot] = 1;
        state->key[slot] = key;
        state->elapsedTurns[slot] = 0;
        state->holderCount[slot] = 0;
        for (i = 0; i < 6; i++)
            state->holderIds[slot][i] = 0x1f;
        stat = BTL_SICKCONT_GetPosition(key);
        if (stat != 0x1f)
            BTL_FIELD_AddSlotHolder(state, slot, stat);
        return 1;
    }
    return 0;
}


int BTL_FIELD_RemoveSlot(BtlFieldState *state, u32 slot)
{
    if (BTL_FIELD_IsSlotInUse(state, slot) != 0) {
        if (state->effectHandle[slot] != 0) {
            HAND_FIELD_RemoveFactor((struct BtlEventFactor *)state->effectHandle[slot]);
            state->effectHandle[slot] = 0;
        }
        BTL_FIELD_ResetSlot(state, slot);
        return 1;
    }
    return 0;
}


/*
 * Lever: the append store is written through the row base
 * (`holderIds[slot][count] = pokeId`); a single `!= 0` guard with one trailing
 * `return 0` shares the exit.
 */
int BTL_FIELD_AddSlotHolder(BtlFieldState *state, u32 slot, u32 pokeId)
{
    u32 count;
    u32 i;

    if (BTL_FIELD_IsSlotInUse(state, slot) != 0) {
        count = state->holderCount[slot];
        if (count < BTL_FIELD_HOLDER_MAX) {
            for (i = 0; i < count; i++) {
                if (pokeId == state->holderIds[slot][i])
                    return 0;
            }
            state->holderIds[slot][count] = pokeId;
            state->holderCount[slot] = count + 1;
            return 1;
        }
    }
    return 0;
}


/*
 * lever: unsigned long outer index closes register rotation and missing base spill.
 */
void BTL_FIELD_RemoveHolderFromSlots(BtlFieldState *state, u32 pokeId)
{
    unsigned long slot;
    u32 j;
    int found;
    for (slot = 0; slot < BTL_FIELD_SLOT_COUNT; slot++) {
        if (BTL_FIELD_IsSlotInUse(state, slot) && state->holderCount[slot]) {
            found = 0;
            for (j = 0; j < state->holderCount[slot]; j++) {
                if (pokeId == state->holderIds[slot][j]) { found = 1; break; }
            }
            if (found) {
                for (; j < BTL_FIELD_HOLDER_MAX - 1; j++) state->holderIds[slot][j] = state->holderIds[slot][j + 1];
                state->holderIds[slot][j] = BTL_FIELD_EMPTY_HOLDER;
                state->holderCount[slot] = state->holderCount[slot] - 1;
                if (state->holderCount[slot] == 0) {
                    if (state->effectHandle[slot]) { HAND_FIELD_RemoveFactor((struct BtlEventFactor *)state->effectHandle[slot]); state->effectHandle[slot] = 0; }
                    BTL_FIELD_ResetSlot(state, slot);
                } else {
                    if (pokeId == BTL_SICKCONT_GetPosition(state->key[slot])) BTL_SICKCONT_SetPosition((union BtlvSlot *)(&state->key[slot]), state->holderIds[slot][0]);
                }
            }
        }
    }
}


/* Effect slot whose holders are checked for sealed moves (Imprison, guess). */
#define BTL_FIELD_SLOT_MOVE_SEAL 3



int BTL_FIELD_IsMoveSealedBySlot(BtlFieldState *state, char *side, void *pokeParam, u16 moveId)
{
    u8 selfId;
    u8 holderId;
    u32 i;
    u32 count;

    selfId = BTL_POKEPARAM_GetPokeId(pokeParam);
    count = state->holderCount[BTL_FIELD_SLOT_MOVE_SEAL];
    for (i = 0; i < count; i++) {
        holderId = state->holderIds[BTL_FIELD_SLOT_MOVE_SEAL][i];
        if (BTL_MAIN_IsPokeSamePair(selfId, holderId) == 0) {
            if (BTL_POKEPARAM_HasMove(BTL_SIDE_GetPokeById((struct BtlSide *)side, holderId), moveId) != 0)
                return 1;
        }
    }
    return 0;
}



/*
 * Lever: BTL_SICKCONT_GetLow takes a one-word struct by value (its own file spells
 * it as a union); the `adds r0,r5,#0 ; adds r0,#0x28 ; ldr r0,[r0]` argument
 * setup is that struct copy, not a plain u32 load.
 */
void BTL_FIELD_TickSlots(BtlFieldState *state, void (*onExpire)(u32, u32), u32 arg)
{
    u32 slot;

    for (slot = 1; slot < BTL_FIELD_SLOT_COUNT; slot++) {
        u32 duration;

        if (BTL_FIELD_IsSlotInUse(state, slot) == 0)
            continue;
        duration = BTL_SICKCONT_GetLow(state->key[slot]);
        if (duration == 0)
            continue;
        state->elapsedTurns[slot] += 1;
        if (state->elapsedTurns[slot] < duration)
            continue;
        if (state->effectHandle[slot] != 0) {
            HAND_FIELD_RemoveFactor((struct BtlEventFactor *)state->effectHandle[slot]);
            state->effectHandle[slot] = 0;
        }
        BTL_FIELD_ResetSlot(state, slot);
        if (onExpire != 0)
            onExpire(slot, arg);
    }
}


void *BTL_FIELD_IsSlotInUse(BtlFieldState *state, int slot)
{
    return (void *)state->inUse[slot];
}
