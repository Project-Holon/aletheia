/*
 * function: func_021688FC
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
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_02059B40  0x02059B40  arm
 *   func_021690D0  0x021690D0  arm  ov009
 *   g_021AA860  0x021AA860  data
 */

typedef struct FriendCtl {
	unsigned char pad0[0x34];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
} FriendCtl;

typedef struct FriendGlobal {
	int pad0[3];
	FriendCtl *ctl;
} FriendGlobal;

extern FriendGlobal g_021AA860;

extern int func_0216AA70(void);
extern int func_02059B40(char *src, unsigned long srclen, char *dst, unsigned long dstlen);
extern int func_021690D0(int status, char *statusString, char *locationString);

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
