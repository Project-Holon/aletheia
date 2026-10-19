/*
 * function: GFL_USE_SetBgmPaused
 * address:  0x02005DE4
 * packet:   pkt_02005DE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_FlushBgmChange  0x02005FBC  thumb
 *   GFL_USE_GetCurrentSndHandle   0x0200590C  thumb
 *   NNS_SndHandlePauseSeq  0x02072E8C  arm
 * blocker:  +000E THM_CALL NNS_SndHandlePauseSeq       -> unresolved: 02072E8C (arm, from name) has no witness outside 02005DE4..02005DF8
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */

typedef unsigned int u32;

extern void GFL_USE_FlushBgmChange(void);
extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern void NNS_SndHandlePauseSeq(u32 a, void *p);

void GFL_USE_SetBgmPaused(void *p)
{
    GFL_USE_FlushBgmChange();
    NNS_SndHandlePauseSeq((u32)GFL_USE_GetCurrentSndHandle(), p);
}
