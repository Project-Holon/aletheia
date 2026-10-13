/*
 * function: DPW_TR_GetUploadResultAsync
 * address: 0x021C8770
 * packet: pkt_ov114_021C8770
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * closed 2026-10-05 (integrator): the pair copy is memcpy(gDpwTrRequestPacket, gDpwTrKeyHeader, 8), the form that closed the sibling ov114 021C8D14 (lane G2L9).
 * residual: 8 concrete bytes, first copy/store scheduling; original best restored.
 * retry: wave24 R1, 3 targeted changes (bound object, const global pointer,
 *   typed destination Pair) did not shrink 8; one --budget 300 --types
 *   permuter compiled 300 candidates and found no improvement. Do not rerun.
 * stale-note 2026-10-05: ov_sdk DWCi_EncSessionGetAsync now returns int (calls DWCi_EncSessionGetPrivateAsync), so the void-return blocker below no longer holds.
 * owner-blocker (stale): the integrator SDK ov114 0x021CA470; matched ov_sdk definition
 *   void DWCi_EncSessionGetAsync(int,int,int,int,int) conflicts with caller return use.
 *   021C87B8: bl 021CA470; 021C87BC: cmp r0,#0.
 *   021CA488: bl 021CA240; 021CA48C: add sp,sp,#8; 021CA490: pop {r3,pc}
 *   preserve r0 from SDK 021CA240's int return. Definition remains untouched.
 *   The C below is the historically compiled recovery sketch, not eligible
 *   for a new caller retry until the owner's prototype is corrected.
 * renewed-pass: wave77 R11; signed copy, own Initialize ABI and inline copy all retained 140/8; consumed prior permuter retained.
 * checks: 1 own SDK definitions audited 2/5/0, void-return discrepancy above stops matching; 2 live 87FC/8C68/8DA0 twins reread, their declarations also predate SDK definitions; 3 signed copy and integer server ABI unchanged 8; further checks stopped at SDK owner blocker; 4 scheduling/global-base/aggregate-copy idioms read; 5 unfiltered idiom directory refreshed and neighbours reread, no stack aggregate in best C.
 * recoup 2026-10-05 (P17L1, 21 compiles): residue unchanged at 8 B: original loads r0=[d28], pool r1 BEFORE the two stores of the pair copy; ours stores r3 first.
 *   Tried, all 8 B or worse: Pair struct copy via cast (8), Pair with address-of (21, pool order moves), u64 copy (98, ldm/stm), early srv local (8),
 *   srv local + struct copy (8), const pointer var and const pointee on d28 (8), const source d38 (8), int/char* prototypes as in matched 87FC/8C68 (8),
 *   named dst/src pointer locals (8), loads into locals then stores with srv read between (8), six per-function pragmas (all 8).
 *   Idioms: an-eight-byte-pair-copy-loads-both-words-first, a-two-word-copy-between-different-bases-is-a-struct-assignment,
 *   a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer, a-const-source-pointer-hoists-the-last-load-of-a-struct-copy (no change).
 * symbols:
 * gDpwTrServerIndex 0x021D3D28 data a4
 * gDpwTrWork 0x021D3D2C data a4
 * gDpwTrBaseUrl 0x021CF538 data a4
 * gDpwTrRequestPacket 0x021D3D40 data a4
 * DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 * DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 * DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 * gDpwTrKeyHeader 0x021D3D38 data a4
 * gDpwTrPathGetUploadResult 0x021CF594 data a4
 */
extern unsigned int *gDpwTrServerIndex;
extern unsigned int gDpwTrWork[], gDpwTrBaseUrl[], gDpwTrRequestPacket[];
extern void DWCi_EncSessionInitialize(void *, void *);
extern int DWCi_EncSessionGetAsync(void *, unsigned int, void *, unsigned int, unsigned int);
extern void DWCi_EncSessionShutdown(void);
#include "../../matched/arm9_sdk/libc/string.h"
extern const unsigned int gDpwTrKeyHeader[];
extern unsigned int gDpwTrPathGetUploadResult[];
void DPW_TR_GetUploadResultAsync(void)
{
    memcpy(gDpwTrRequestPacket, gDpwTrKeyHeader, 8);
    DWCi_EncSessionInitialize(gDpwTrServerIndex, gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathGetUploadResult, gDpwTrWork[2], gDpwTrRequestPacket, 8, 0) == 0) {
        gDpwTrWork[0] = 4;
        return;
    }
    gDpwTrWork[0] = 24;
    gDpwTrWork[1] = -13;
    DWCi_EncSessionShutdown();
}
