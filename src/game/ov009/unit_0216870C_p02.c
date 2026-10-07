/*
 * file:     unit_0216870C_p02.c
 * unit:     yes
 * function: func_021688FC, func_02168994
 * address:  0x021688FC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_02059B40  0x02059B40  arm
 *   func_021690D0  0x021690D0  arm  ov009
 *   g_021AA860  0x021AA860  data
 */
#include "../../matched/include/G_FriendGlobal.h"

typedef struct FriendCtl {
	unsigned char pad0[0x34];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

typedef unsigned int   u32;

extern int func_0216AA70(void);
extern int func_02059B40(const char *src, u32 srclen, char *dst, u32 dstlen);
extern int func_021690D0(int status, const char *statusString, const char *locString);
int func_021688FC(char *statusData, unsigned long size);
int func_02168994(void (*callback)(int, void *), void *param);
extern struct FriendGlobal g_021AA860;


/*
 * sdk:      DWC_SetOwnStatusData (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_021688FC(char *statusData, unsigned long size)
{
	char statusString[256];
	int len;
	int ret;

	if (g_021AA860.ctl == 0 || !func_0216AA70())
		return 0;
	len = func_02059B40(statusData, size, statusString, 255);
	if (len == -1)
		return 0;
	statusString[len] = 0;
	ret = func_021690D0(-1, 0, statusString);
	if (ret == 0)
		return 1;
	return 0;
}


/*
 * sdk:      DWC_SetBuddyFriendCallback (dwc_friend.o)
 */
int func_02168994(void (*callback)(int, void *), void *param)
{
    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0) return 0;
    *(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x44) = (void *)callback;
    *(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x48) = param;
    return 1;
}
