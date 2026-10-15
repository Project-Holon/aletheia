/*
 * function: DWC_GetFriendStatusData
 * address:  0x02168848
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls DWC_GetFriendStatusDataSC with two zeroed arguments between the tail arguments.
 *
 * symbols:
 *   DWC_GetFriendStatusDataSC  0x02168864  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

unsigned char DWC_GetFriendStatusData(void *p, int a, int b)
{
    unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
    return DWC_GetFriendStatusDataSC(p, 0, 0, (char *)a, (int *)b);
}
