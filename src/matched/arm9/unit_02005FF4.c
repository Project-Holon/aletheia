/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005FF4
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_UpdateBgmChange, GFL_USE_InitSeSlots, GFL_USE_GetSeHandle
 *
 * symbols:
 *   sub_02005FF4_State  0x020AA260  data
 *   sub_02006118_Table  0x020AA294  data
 *   GFL_USE_GetCurrentBgmId        0x020058D0  thumb
 *   GFL_USE_GetCurrentSndHandle        0x0200590C  thumb
 *   GFL_USE_SaveSeqBankState        0x0200597C  thumb
 *   GFL_USE_FinishBgmLoad        0x020059A0  thumb
 *   GFL_USE_StopBgm        0x02005D14  thumb
 *   GFL_USE_CancelBgmChange        0x02005F90  thumb
 *   GFL_USE_StartLoaderThread        0x02006300  thumb
 *   GFL_USE_IsLoaderDone        0x02006394  thumb
 *   _s32_div_f          0x0209C0A4  arm
 *   NNS_SndArcSetReadChunkSize       0x020746B0  arm
 *   func_020755A8       0x020755A8  arm
 *   NNS_SndHandleInit       0x02072E9C  arm
 *   NNS_SndHandleSetVolume       0x02072F34  arm
 *   OS_Sleep       0x02085A38  arm
 *
 * The three state connection pump, plus the initialiser and the address-of
 * accessor for the five entry table at 0x020AA294.
 *
 * GFL_USE_UpdateBgmChange is where the signal strength bar comes from: `unk24` counts
 * up towards `unk2C` while the current access point matches the one being
 * connected to and back down towards zero when it does not, and the value
 * handed to NNS_SndHandleSetVolume is `unk24 * 0x7F / unk2C` or `unk24 * 0x7F /
 * unk30`.  Both divisions are signed, so they call the compiler's own
 * `_s32_div_f` helper rather than `_u32_div_f`: `unk24` is a `u16` that
 * promotes to `int` and the two limits are `int`.  Getting that wrong is not
 * a codegen difference but a relocation with a different symbol name, and
 * the name is what the harness resolves against.
 *
 * GFL_USE_GetSeHandle carries no label: it is `lsls`, `adds`, `adds`, `bx lr`, the
 * address of one table entry's second word, and it saves nothing, so
 * disasm.py's prologue sweep cannot see it.
 */

#include "../include/G_Sub02006118Entry.h"

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005FF4State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    int unk2C;
    int unk30;
};

extern struct Sub02005FF4State sub_02005FF4_State;
extern struct Sub02006118Entry sub_02006118_Table[];

extern u16  GFL_USE_GetCurrentBgmId(void);
extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern void GFL_USE_SaveSeqBankState(void);
extern int  GFL_USE_FinishBgmLoad(u32 a);
extern void GFL_USE_StopBgm(void);
extern void GFL_USE_CancelBgmChange(void);
extern void GFL_USE_StartLoaderThread(u32 a, int mode);
extern int  GFL_USE_IsLoaderDone(void);
extern void NNS_SndArcSetReadChunkSize(int p0);
extern u32  func_020755A8(u32 req, int a, int b, int c, u32 arg);
extern void NNS_SndHandleInit(void **r0);
extern void NNS_SndHandleSetVolume(u32 *req, int level);
extern void OS_Sleep(u32 msec);

void GFL_USE_UpdateBgmChange(void)
{
    u32 *req = GFL_USE_GetCurrentSndHandle();
    u16 id = GFL_USE_GetCurrentBgmId();

    if (sub_02005FF4_State.unk1C == 0) {
        return;
    }
    switch (sub_02005FF4_State.unk20) {
    case 0:
        if (id != 0) {
            if (id != sub_02005FF4_State.unk28) {
                if (sub_02005FF4_State.unk24 != 0) {
                    sub_02005FF4_State.unk24--;
                    NNS_SndHandleSetVolume(req, sub_02005FF4_State.unk24 * 0x7F /
                                       sub_02005FF4_State.unk30);
                    return;
                }
                NNS_SndHandleSetVolume(req, 0);
            } else {
                if (sub_02005FF4_State.unk24 < sub_02005FF4_State.unk2C) {
                    sub_02005FF4_State.unk24++;
                    NNS_SndHandleSetVolume(req, sub_02005FF4_State.unk24 * 0x7F /
                                       sub_02005FF4_State.unk2C);
                    return;
                }
                GFL_USE_CancelBgmChange();
                return;
            }
        }
        GFL_USE_StopBgm();
        if (sub_02005FF4_State.unk28 == 0) {
            GFL_USE_CancelBgmChange();
            return;
        }
        NNS_SndArcSetReadChunkSize(0x1300);
        GFL_USE_StartLoaderThread(sub_02005FF4_State.unk28, 0);
        sub_02005FF4_State.unk24 = 0;
        sub_02005FF4_State.unk20 = 1;
        return;
    case 1:
        if (GFL_USE_IsLoaderDone() == 1) {
            GFL_USE_SaveSeqBankState();
            GFL_USE_StartLoaderThread(sub_02005FF4_State.unk28, 1);
            sub_02005FF4_State.unk20 = 2;
            return;
        }
        OS_Sleep(1);
        return;
    case 2:
        if (GFL_USE_IsLoaderDone() == 1) {
            NNS_SndArcSetReadChunkSize(0);
            GFL_USE_FinishBgmLoad(sub_02005FF4_State.unk28);
            func_020755A8((u32)GFL_USE_GetCurrentSndHandle(), 0, -1, -1,
                          sub_02005FF4_State.unk28);
            NNS_SndHandleSetVolume(req, 0);
            sub_02005FF4_State.unk20 = 0;
            return;
        }
        OS_Sleep(1);
        return;
    }
}

void GFL_USE_InitSeSlots(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        sub_02006118_Table[i].unk00 = 0;
        NNS_SndHandleInit((void **)(&sub_02006118_Table[i].unk04));
    }
}

u32 *GFL_USE_GetSeHandle(int i)
{
    return &sub_02006118_Table[i].unk04;
}
