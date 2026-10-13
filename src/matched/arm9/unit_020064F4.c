/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020064F4
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_StartSeq, GFL_USE_StopSeqAndUnload, GFL_USE_ClearPreloadedBgmBuffers
 *
 * symbols:
 *   GFL_USE_GetCurrentSndHandle   0x0200590C  thumb
 *   GFL_USE_UnloadBgmData   0x020059C8  thumb
 *   func_02072E7C  0x02072E7C  arm
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNS_SndArcGetBankInfo  0x020743EC  arm
 *   NNS_SndArcSetFileAddress  0x02074694  arm
 *   func_02075560  0x02075560  arm
 *
 * Three short entry points that take the current connection slot's payload
 * from GFL_USE_GetCurrentSndHandle, which is the last function of
 * src/matched/unit_020057DC.c, and hand it to the library.  GFL_USE_ClearPreloadedBgmBuffers is
 * the odd one: it does not use the slot at all but looks the same object up
 * twice, through two different library entry points, with the same constant
 * 0x3F2, and shuts both results down.  0x3F2 is past the range of a Thumb
 * `movs` immediate, so it arrives in r4 through a literal pool word and is
 * used twice from there.
 */

typedef unsigned int u32;

extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern void GFL_USE_UnloadBgmData(void);
extern void func_02072E7C(void **r0, int fadeFrame);
extern u32 *NNS_SndArcGetSeqInfo(u32 a);
extern u32 *NNS_SndArcGetBankInfo(u32 a);
extern void NNS_SndArcSetFileAddress(u32 a, u32 b);
extern u32 func_02075560(u32 a, u32 b);

void GFL_USE_StartSeq(u32 a)
{
    func_02075560((u32)GFL_USE_GetCurrentSndHandle(), a);
}

void GFL_USE_StopSeqAndUnload(void)
{
    func_02072E7C((void **)GFL_USE_GetCurrentSndHandle(), 0);
    GFL_USE_UnloadBgmData();
}

void GFL_USE_ClearPreloadedBgmBuffers(void)
{
    u32 a = *NNS_SndArcGetBankInfo(0x3F2);
    u32 b = *NNS_SndArcGetSeqInfo(0x3F2);

    NNS_SndArcSetFileAddress(a, 0);
    NNS_SndArcSetFileAddress(b, 0);
}
