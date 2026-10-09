/*
 * file:     unit_0216C858_p08.c
 * unit:     yes
 * function: DWCi_MakeGT2ConnectString
 * address:  0x0216E808
 * packet:   pkt_ov009_0216E808
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MakeGT2ConnectString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt  0x02175F3C arm
 *   OS_SNPrintf       0x02084F80 arm
 *   g_021A207C        0x021A207C data
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x678];
    int profileID;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern char g_021A207C[];

void DWCi_MakeGT2ConnectString(char *buf, int bufLen)
{
    OS_SNPrintf(buf, bufLen, g_021A207C, DWCi_GetMatchCnt()->profileID);
}
