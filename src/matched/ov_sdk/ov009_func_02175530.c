/*
 * function: DWCi_CreateGroupID
 * address:  0x02175530
 * packet:   pkt_ov009_02175530
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CreateGroupID (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt     0x02175F3C arm
 *   DWCi_GetMathRand32   0x021685CC arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[0x678];
    int profileID;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern unsigned long DWCi_GetMathRand32(unsigned long max);

unsigned long DWCi_CreateGroupID(void)
{
    return DWCi_GetMatchCnt()->profileID + DWCi_GetMathRand32(10000000) + 100000000;
}
