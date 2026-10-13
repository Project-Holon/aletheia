/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020057DC
 * packet:   pkt_02005768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_SetSndStackHeap, GFL_USE_InitSndSlot, GFL_USE_BeginSndSlot, GFL_USE_EndSndSlot,
 *           GFL_USE_InitSndStack, GFL_USE_GetCurrentBgmId, GFL_USE_GetSndStackDepth, GFL_USE_GetCurrentSndHandle,
 *           GFL_USE_LoadBgmData, GFL_USE_SaveSeqBankState, GFL_USE_FinishBgmLoad, GFL_USE_UnloadBgmData,
 *           GFL_USE_PushSndSlot
 *
 * symbols:
 *   _SndStack    0x020AA1AC  data
 *   _SndSlots  0x020AA1B8  data
 *   NNS_SndPlayerSetPlayableSeqCount       0x02072DB0  arm
 *   NNS_SndHandleInit       0x02072E9C  arm
 *   NNS_SndHandleReleaseSeq       0x02072EA8  arm
 *   NNS_SndHeapSaveState       0x02074894  arm
 *   NNS_SndHeapLoadState       0x020748E0  arm
 *   NNS_SndArcLoadSeqEx       0x02074AC4  arm
 *
 * The accessors of a six element table of 0x1C byte connection slots at
 * 0x020AA1B8 and of the one word "which slot is current" record at
 * 0x020AA1AC.  GFL_USE_GetCurrentSndHandle, which returns the address of the current
 * slot's payload, was already matched as a single function in
 * arm9/legacy.json; it is the last function of this range and is absorbed
 * here.  NNS_SndHandleInit is NHTTPi_InitRequestInfo in layout/symbols_sdk.txt,
 * which is what the payload at offset 8 of a slot is.
 *
 * What the range teaches:
 *
 *  - a field of `table[i]` with a run time `i` puts the field offset in the
 *    relocation addend rather than in the instruction.  GFL_USE_InitSndSlot stores
 *    to five different fields of one slot and loads five different pool
 *    words, 0x020AA1B8, 0x020AA1BC, 0x020AA1C4, 0x020AA1C8, 0x020AA1CC and
 *    0x020AA1D0, which are the table's address plus 0, 4, 0xC, 0x10, 0x14
 *    and 0x18.  Thumb's register-offset `str` has no immediate to spare, so
 *    the compiler folds the member offset into the symbol instead.  Reading
 *    those pool words as six separate objects would be the wrong conclusion.
 *  - the constant -1 is never materialised on its own.  GFL_USE_InitSndSlot needs
 *    a 0 for the first store and derives the -1 for the next four from it
 *    with `subs r1, r4, #1`.
 *
 * The near miss this header used to record, the run
 * 0x02005794..0x020057D8, is now closed as far as the evidence allows.  The
 * `veneer` attestation class carries 0x02072788, so the two twelve byte
 * thunks and the function at 0x020057AC that passes both of their addresses
 * to func_0203508C are src/matched/unit_02005794.c and are EXACT.
 *
 * What is left open is 0x020057C4 alone, 20 bytes, and the reason is
 * unchanged and structural: func_02035108 has exactly one caller anywhere in
 * the 3.9 MB image and it is the `blx` at 0x020057C6 inside that very
 * function.  Shrinking the range cannot help, because the witness is the call
 * itself, and the target is ARM library code that cannot be made `local`.
 * The function also needs GFL_USE_MuteSound `local`, for the pool word at
 * 0x020057D8 that holds its address.  It closes the day anything else in the
 * image calls 0x02035108.
 */

#include "../include/G_Sub020057DCCur.h"
#include "../include/G_Sub020057DCSlot.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Sub020057DCCur _SndStack;
extern struct Sub020057DCSlot _SndSlots[];

extern void NNS_SndPlayerSetPlayableSeqCount(int idx, int v);
extern void NNS_SndHandleInit(void **r0);
extern void NNS_SndHandleReleaseSeq(u32 * volatile *pp);
struct S;
extern int   NNS_SndHeapSaveState(struct S *a);
extern void  NNS_SndHeapLoadState(u32 *a, u32 b);
extern u32 NNS_SndArcLoadSeqEx(u32 a, u32 b, u32 c);

void GFL_USE_InitSndSlot(u32 i);
void GFL_USE_BeginSndSlot(u32 v);

void GFL_USE_SetSndStackHeap(u32 **a)
{
    _SndStack.unk08 = a;
}

void GFL_USE_InitSndSlot(u32 i)
{
    _SndSlots[i].unk00 = 0;
    _SndSlots[i].unk04 = 0xFFFF;
    NNS_SndHandleReleaseSeq((u32 * volatile*)(&_SndSlots[i].unk08));
    _SndSlots[i].unk0C = -1;
    _SndSlots[i].unk10 = -1;
    _SndSlots[i].unk14 = -1;
    _SndSlots[i].unk18 = -1;
}

void GFL_USE_BeginSndSlot(u32 v)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];

    slot->unk0C = v;
    slot->unk10 = v;
    slot->unk14 = v;
    slot->unk18 = v;
    slot->unk00 = 1;
}

void GFL_USE_EndSndSlot(void)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];

    NNS_SndHandleReleaseSeq((u32 * volatile*)(&slot->unk08));
    NNS_SndHeapLoadState(*_SndStack.unk08, slot->unk0C);
    GFL_USE_InitSndSlot(_SndStack.index);
}

void GFL_USE_InitSndStack(u16 a)
{
    int i;

    _SndStack.unk00 = a;
    _SndStack.index = 0;
    for (i = 0; i < 6; i++) {
        GFL_USE_InitSndSlot(i);
        NNS_SndHandleInit((void **)(&_SndSlots[i].unk08));
    }
    NNS_SndPlayerSetPlayableSeqCount(_SndStack.unk00, 6);
    GFL_USE_BeginSndSlot(NNS_SndHeapSaveState((struct S *)*_SndStack.unk08));
}

u16 GFL_USE_GetCurrentBgmId(void)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];
    u16 v;

    if (slot->unk00 == 0) {
        return 0;
    }
    v = slot->unk04;
    if (v == 0xFFFF) {
        v = 0;
    }
    return v;
}

u32 GFL_USE_GetSndStackDepth(void)
{
    return _SndStack.index;
}

u32 *GFL_USE_GetCurrentSndHandle(void)
{
    return &_SndSlots[_SndStack.index].unk08;
}

int GFL_USE_LoadBgmData(u32 a)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];
    int r;

    if (NNS_SndArcLoadSeqEx(a, 3, (u32)(*_SndStack.unk08)) == 0) {
        return 0;
    }
    slot->unk14 = NNS_SndHeapSaveState((struct S *)*_SndStack.unk08);
    r = NNS_SndArcLoadSeqEx(a, 4, (u32)(*_SndStack.unk08));
    if (r == 0) {
        return 0;
    }
    slot->unk18 = NNS_SndHeapSaveState((struct S *)*_SndStack.unk08);
    slot->unk04 = a;
    return r;
}

void GFL_USE_SaveSeqBankState(void)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];

    slot->unk14 = NNS_SndHeapSaveState((struct S *)*_SndStack.unk08);
}

int GFL_USE_FinishBgmLoad(u32 a)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];

    slot->unk18 = NNS_SndHeapSaveState((struct S *)*_SndStack.unk08);
    slot->unk04 = a;
    return 1;
}

void GFL_USE_UnloadBgmData(void)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];

    if (slot->unk00 == 0) {
        return;
    }
    slot->unk04 = 0xFFFF;
    NNS_SndHeapLoadState(*_SndStack.unk08, slot->unk10);
    slot->unk14 = slot->unk10;
    slot->unk18 = slot->unk10;
}

int GFL_USE_PushSndSlot(void)
{
    struct Sub020057DCSlot *slot =
        &_SndSlots[_SndStack.index];
    u32 v;

    if (_SndStack.index >= 5) {
        return 0;
    }
    if (slot->unk14 != -1) {
        NNS_SndHeapLoadState(*_SndStack.unk08, slot->unk14);
        slot->unk18 = -1;
        v = slot->unk14;
    } else {
        v = slot->unk10;
    }
    _SndStack.index++;
    GFL_USE_BeginSndSlot(v);
    return 1;
}
