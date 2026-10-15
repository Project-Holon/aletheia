/*
 * function: DWC_SetOwnStatusData
 * address:  0x021688FC
 * packet:   pkt_ov009_021688FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      DWC_SetOwnStatusData (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   DWCi_CheckLogin  0x0216AA70  arm  ov009
 *   DWC_Base64Encode  0x02059B40  arm
 *   DWCi_SetGPStatus  0x021690D0  arm  ov009
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

typedef struct FriendCtl {
	unsigned char pad0[0x34];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

extern struct FriendGlobal g_021AA860;

extern int DWCi_CheckLogin(void);
typedef unsigned int   u32;
extern int DWC_Base64Encode(const char *src, u32 srclen, char *dst, u32 dstlen);
extern int DWCi_SetGPStatus(int status, const char *statusString, const char *locString);

int DWC_SetOwnStatusData(char *statusData, unsigned long size)
{
	char statusString[256];
	int len;
	int ret;

	if (g_021AA860.ctl == 0 || !DWCi_CheckLogin())
		return 0;
	len = DWC_Base64Encode(statusData, size, statusString, 255);
	if (len == -1)
		return 0;
	statusString[len] = 0;
	ret = DWCi_SetGPStatus(-1, 0, statusString);
	if (ret == 0)
		return 1;
	return 0;
}
