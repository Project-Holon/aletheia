/*
 * function: DWC_GetFriendStatusDataSC
 * address:  0x02168864
 * packet:   pkt_ov009_02168864
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetFriendStatusDataSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   DWC_GetFriendStatusSC  0x02168724  arm  ov009
 *   strlen  0x0209477C  arm
 *   DWC_Base64Decode  0x02059CBC  arm
 */

extern unsigned char DWC_GetFriendStatusSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusString);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
typedef unsigned int   u32;
extern int DWC_Base64Decode(const char *src, u32 srclen, char *dst, u32 dstlen);
unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size)
{
	char statusString[256];
	unsigned char ret;
	ret = DWC_GetFriendStatusSC(friendData, maxEntry, numEntry, statusString);
	if (ret == 0) {
		*size = -1;
		return ret;
	}
	*size = DWC_Base64Decode(statusString, strlen((const u8 *)statusString), 0, 0);
	if (statusData == 0 || *size == -1)
		return ret;
	DWC_Base64Decode(statusString, strlen((const u8 *)statusString), statusData, *size);
	return ret;
}
