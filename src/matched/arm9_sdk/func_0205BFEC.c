/*
 * function: func_0205BFEC
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
 *   MIi_CpuCopy32  0x02082A90  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 b[0x100];
} USERINFO;

typedef struct {
    USERINFO userInfo[3];
} ACWORK;

extern ACWORK *DWCi_AC_GetMemPtr(int name);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

void func_0205BFEC(int no, const void *info)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    MIi_CpuCopy32(info, &wk->userInfo[no], 0xf0);
}
