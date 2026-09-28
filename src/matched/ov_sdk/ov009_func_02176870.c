/*
 * function: DWCi_ClearMeshMakingTempInfo
 * address:  0x02176870
 * packet:   pkt_ov009_02176870
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ClearMeshMakingTempInfo (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt  0x02175F3C arm
 *   MI_CpuFill8       0x02082BCC arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x5a8];
    int lastStateBeforeStopMeshMaking;         /* +0x5a8 */
    u8  tempNodeInfoBeforeStopMeshMaking[0x28];/* +0x5ac */
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void DWCi_ClearMeshMakingTempInfo(void)
{
    DWCi_GetMatchCnt()->lastStateBeforeStopMeshMaking = 0;
    MI_CpuFill8(&DWCi_GetMatchCnt()->tempNodeInfoBeforeStopMeshMaking, 0, 0x28);
}
