/*
 * function: DWCi_GetChildInfo
 * address:  0x021D4138
 * packet:   pkt_ov016_021D4138
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetChildInfo (libdwcutil.TWL.HYB.a dwc_moveid.o)
 *
 * symbols:
 *   MB_CommGetChildUser          0x021F1B64  arm
*/

typedef struct MBUserInfo MBUserInfo;

extern MBUserInfo *MB_CommGetChildUser(unsigned short aid);

MBUserInfo *DWCi_GetChildInfo(void)
{
    return MB_CommGetChildUser(1);
}
