/*
 * file:     btl_sickcont.c
 * unit:     yes
 * function: BTL_SICKCONT_MakeNone, BTL_SICKCONT_IsNone, BTL_SICKCONT_MakeKind2Index, BTL_SICKCONT_MakeKind2, BTL_SICKCONT_MakeKind3, BTL_SICKCONT_MakeKind1Empty, BTL_SICKCONT_MakeKind1Value, BTL_SICKCONT_MakeKind1, BTL_SICKCONT_MakeKind4, BTL_SICKCONT_MakeKind1Index15, BTL_SICKCONT_IsKind1Index15, BTL_SICKCONT_GetPosition, BTL_SICKCONT_SetPosition, BTL_SICKCONT_GetLow, BTL_SICKCONT_SetValue, BTL_SICKCONT_GetValue, BTL_SICKCONT_SetFlag, BTL_SICKCONT_GetFlag, BTL_SICKCONT_AddIndex, BTL_SICKCONT_SetIndex
 * address:  0x021E8918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from hand_common.c, btlv_core.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "btlv_core_types.h"
#include "btl_pokeparam_types.h"

union SickCont BTL_SICKCONT_MakeNone(void);

int BTL_SICKCONT_IsNone(union SickCont slot);

union SickCont BTL_SICKCONT_MakeKind2Index(u32 index);

union SickCont BTL_SICKCONT_MakeKind2(u32 index, u32 value);

union SickCont BTL_SICKCONT_MakeKind3(u32 index);

union SickCont BTL_SICKCONT_MakeKind1Empty(void);

union SickCont BTL_SICKCONT_MakeKind1Value(u32 value);

union SickCont BTL_SICKCONT_MakeKind1(u32 index, u32 value);

union SickCont BTL_SICKCONT_MakeKind4(u32 hi, u32 lo);

union SickCont BTL_SICKCONT_MakeKind1Index15(void);

int BTL_SICKCONT_IsKind1Index15(union SickCont slot);

u8 BTL_SICKCONT_GetPosition(union SickCont slot);

void BTL_SICKCONT_SetPosition(union SickCont *slot, u8 pos);

u8 BTL_SICKCONT_GetLow(union SickCont slot);

void BTL_SICKCONT_SetValue(union SickCont *slot, u16 value);

u16 BTL_SICKCONT_GetValue(union SickCont slot);

void BTL_SICKCONT_SetFlag(union SickCont *slot, int flag);

u32 BTL_SICKCONT_GetFlag(union SickCont slot);

void BTL_SICKCONT_AddIndex(union SickCont *slot, u32 delta);

void BTL_SICKCONT_SetIndex(union SickCont *slot, int count);

/*
 * Returns 0 with a 4-byte frame that nothing ever stores to.  Taking the address of a local array forces the slot, and the optimizer then removes both the store and the reload (nothing outside can alias it), so the frame and the register-resident value both survive.  A scalar `u32 v = 0; v &= ~7u;` folds to 4 bytes, which is why O28's residue could not reach this; the address-taken local is the missing form.
 * stand-in: the word is reached through a cast of the byte array; a u32 array, a union or an address-taken u32 each change the bytes.
 */
union SickCont BTL_SICKCONT_MakeNone(void)
{
    union SickCont slot = {0};

    slot.byPart.kind = 0;
    return slot;
}

int BTL_SICKCONT_IsNone(union SickCont slot)
{
    if (slot.byPart.kind == 0)
        return 1;
    return 0;
}

/*
 * 2026-10-03 EXACT (wave B3, lane 21): the second pool word is 0xFE0001FF, not
 * 0x000001FF. It is the value:16 clear mask of the BTL_SICKCONT_MakeKind2 slot, so this is
 * BTL_SICKCONT_MakeKind2 with value = 0 and extra left zero from the initialiser.
 */
union SickCont BTL_SICKCONT_MakeKind2Index(u32 index)
{
    union SickCont slot = {0};

    slot.byValue.kind = 2;
    slot.byValue.index = index & 0x3f;
    slot.byValue.value = 0;
    return slot;
}

union SickCont BTL_SICKCONT_MakeKind2(u32 index, u32 value)
{
    union SickCont slot = {0};

    slot.byValue.kind = 2;
    slot.byValue.index = index & 0x3f;
    slot.byValue.value = value;
    return slot;
}

/*
 * Recursive MATCH unblocker: named callee of the parked ov093 HAND_ITEM_DestinyKnot_Infatuate
 * (+0080, `BTL_SICKCONT_MakeKind3(c)` stored at record +8).  Packs a 3-bit constant
 * (3) with the low six bits of the argument shifted left by three, as a
 * bitfield union read back as a word; the empty frame is the compiler's
 * storage for the union local, and `= {0}` is what emits `movs r2,#0`
 * instead of reading the uninitialised slot back.
 *
 * Addresses are Black-image addresses.
 */
union SickCont BTL_SICKCONT_MakeKind3(u32 index)
{
    union SickCont slot = {0};

    slot.indexOnly.kind = 3;
    slot.indexOnly.index = index & 0x3f;
    return slot;
}

union SickCont BTL_SICKCONT_MakeKind1Empty(void)
{
    union SickCont slot = {0};

    slot.indexOnly.kind = 1;
    return slot;
}

union SickCont BTL_SICKCONT_MakeKind1Value(u32 value)
{
    union SickCont slot = {0};
    slot.byValue.kind = 1;
    slot.byValue.value = value;
    return slot;
}

/*
 * Unlabelled leaf, the only blocker of BTL_CALC_MakeSickContFromSpec's MATCH (case 1 of its
 * kind switch).  Sibling of BTL_SICKCONT_MakeKind3: packs kind 1, a 6-bit field and a
 * 16-bit field into a one-word bitfield.
 */
union SickCont BTL_SICKCONT_MakeKind1(u32 index, u32 value)
{
    union SickCont slot = {0};
    slot.byValue.kind = 1;
    slot.byValue.index = index & 0x3f;
    slot.byValue.value = value;
    return slot;
}

union SickCont BTL_SICKCONT_MakeKind4(u32 hi, u32 lo)
{
    union SickCont slot = {0};

    slot.byPart.kind = 4;
    slot.byPart.paramLow = lo & 0x3f;
    slot.byPart.paramHigh = hi & 0x3f;
    return slot;
}

union SickCont BTL_SICKCONT_MakeKind1Index15(void)
{
    union SickCont slot = {0};

    slot.indexOnly.kind = 1;
    slot.indexOnly.index = 0xf;
    return slot;
}

int BTL_SICKCONT_IsKind1Index15(union SickCont slot)
{
    if (slot.byPart.kind == 1 && slot.byPart.paramLow == 0xf)
        return 1;
    return 0;
}

u8 BTL_SICKCONT_GetPosition(union SickCont slot)
{
    if (slot.byPart.kind == 3)
        return slot.byPart.paramLow;
    if (slot.byPart.kind == 4)
        return slot.byPart.paramHigh;
    return 0x1f;
}

void BTL_SICKCONT_SetPosition(union SickCont *slot, u8 pos)
{
    if (slot->byPart.kind == 3)
        slot->byPart.paramLow = pos;
    else if (slot->byPart.kind == 4)
        slot->byPart.paramHigh = pos;
}

u8 BTL_SICKCONT_GetLow(union SickCont slot)
{
    if (slot.byPart.kind == 2) return slot.byPart.paramLow;
    if (slot.byPart.kind == 4) return slot.byPart.paramLow;
    return 0;
}

void BTL_SICKCONT_SetValue(union SickCont *slot, u16 value)
{
    if (slot->byValue.kind == 1) slot->byValue.value = value;
    else if (slot->byValue.kind == 3) slot->byValue.value = value;
    else if (slot->byValue.kind == 4) slot->wideParam.value = value;
    else if (slot->byValue.kind == 2) slot->byValue.value = value;
}

u16 BTL_SICKCONT_GetValue(union SickCont slot)
{
    if (slot.byValue.kind == 1) return slot.byValue.value;
    if (slot.byValue.kind == 3) return slot.byValue.value;
    if (slot.byValue.kind == 4) return slot.wideParam.value;
    if (slot.byValue.kind == 2) return slot.byValue.value;
    return 0;
}

void BTL_SICKCONT_SetFlag(union SickCont *slot, int flag)
{
    if (slot->flagMid.kind == 1) slot->flagMid.flag = flag;
    else if (slot->flagMid.kind == 3) slot->flagMid.flag = flag;
    else if (slot->flagMid.kind == 4) slot->flagHigh.flag = flag;
    else if (slot->flagMid.kind == 2) slot->flagMid.flag = flag;
}

u32 BTL_SICKCONT_GetFlag(union SickCont slot)
{
    if (slot.flagMid.kind == 1) return slot.flagMid.flag;
    if (slot.flagMid.kind == 3) return slot.flagMid.flag;
    if (slot.flagMid.kind == 4) return slot.flagHigh.flag;
    if (slot.flagMid.kind == 2) return slot.flagMid.flag;
    return 0;
}

void BTL_SICKCONT_AddIndex(union SickCont *slot, u32 delta)
{
    if (slot->indexOnly.kind == 2 && slot->indexOnly.index < 8) slot->indexOnly.index = slot->indexOnly.index + delta;
    if (slot->indexOnly.kind == 4 && slot->indexOnly.index < 8) slot->indexOnly.index = slot->indexOnly.index + delta;
}

void BTL_SICKCONT_SetIndex(union SickCont *slot, int count)
{
    if (slot->indexOnly.kind == 2 && slot->indexOnly.index < 8) slot->indexOnly.index = count;
    if (slot->indexOnly.kind == 4 && slot->indexOnly.index < 8) slot->indexOnly.index = count;
}
