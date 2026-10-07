/*
 * function: DWCi_PostProcessConnectionSYNFinish
 * address:  0x02172510
 * packet:   pkt_ov009_02172510
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_PostProcessConnectionSYNFinish (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                     0x02175F3C arm
 *   DWCi_IsFullMesh                      0x0217695C arm
 *   DWCi_PostProcessConnectionSYNFinishFullmesh 0x021725EC arm
 *   DWCi_PostProcessConnectionSYNFinishHybrid   0x0217253C arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x5f9];
    u8 nnFailureCount;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int DWCi_IsFullMesh(void);
extern void DWCi_PostProcessConnectionSYNFinishFullmesh(void);
extern void DWCi_PostProcessConnectionSYNFinishHybrid(void);

void DWCi_PostProcessConnectionSYNFinish(void)
{
    DWCi_GetMatchCnt()->nnFailureCount = 0;
    if (DWCi_IsFullMesh())
        DWCi_PostProcessConnectionSYNFinishFullmesh();
    else
        DWCi_PostProcessConnectionSYNFinishHybrid();
}
