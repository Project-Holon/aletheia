/*
 * function: DWCi_AC_InsertApInfo
 * address:  0x0205BFEC
 * packet:   pkt_0205BFEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_InsertApInfo (dwc_ac.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   MIi_CpuCopy32                    0x02082a90 arm
 */

typedef struct NCFGApInfo {
    unsigned char data[0xF0];
} NCFGApInfo;

typedef struct NCFGSlotInfo {
    NCFGApInfo ap;
    unsigned char rest[0x10];
} NCFGSlotInfo;

typedef struct tagACWORK {
    NCFGSlotInfo userInfo[3];
} tagACWORK;

extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern void MIi_CpuCopy32(const void *srcp, void *destp, unsigned long size);

void DWCi_AC_InsertApInfo(int no, NCFGApInfo *info)
{
    tagACWORK *wk = (tagACWORK *)DWCi_AC_GetMemPtr(0x10);

    MIi_CpuCopy32(info, &wk->userInfo[no], sizeof(NCFGApInfo));
}
