/*
 * function: func_02168864
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
 *   func_02168724  0x02168724  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 */

extern unsigned char func_02168724(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusString);
extern unsigned int func_0209477C(char *s);
extern int func_02059CBC(char *src, unsigned long srclen, char *dst, unsigned long dstlen);
unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size)
{
	char statusString[256];
	unsigned char ret;
	ret = func_02168724(friendData, maxEntry, numEntry, statusString);
	if (ret == 0) {
		*size = -1;
		return ret;
	}
	*size = func_02059CBC(statusString, func_0209477C(statusString), 0, 0);
	if (statusData == 0 || *size == -1)
		return ret;
	func_02059CBC(statusString, func_0209477C(statusString), statusData, *size);
	return ret;
}
