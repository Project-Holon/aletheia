/*
 * file:     unit_0216870C_p01.c
 * unit:     yes
 * function: func_0216870C, func_02168724, func_02168848, func_02168864, func_021688FC, func_02168994
 * address:  0x0216870C
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
 *   func_0216980C  0x0216980C  arm  ov009
 *   func_021684CC  0x021684CC  arm  ov009
 *   strtoul        0x02095EAC  arm
 *   strcpy         0x02094798  arm
 *   func_02176984  0x02176984  arm  ov009
 *   g_021A2004     0x021A2004  data
 *   g_021A2008     0x021A2008  data
 *   func_0209477C  0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_02059B40  0x02059B40  arm
 *   func_021690D0  0x021690D0  arm  ov009
 *   g_021AA860  0x021AA860  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_FriendGlobal.h"

typedef unsigned char  u8;

typedef struct {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct FriendCtl {
	unsigned char pad0[0x34];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

extern int func_0216980C(void *friendData, GPBuddyStatus *status);
extern int func_021684CC(char *key, char *value, char *string, char separator);
extern unsigned long strtoul(const char *s, char **end, int base);
extern int func_02176984(GPBuddyStatus *status);
extern int func_0209477C(const u8 *s);
extern int func_02059CBC(const char *src, u32 srclen, char *dst, u32 dstlen);
extern int func_0216AA70(void);
extern int func_02059B40(const char *src, u32 srclen, char *dst, u32 dstlen);
extern int func_021690D0(int status, const char *statusString, const char *locString);
u8 func_0216870C(int a, int b);
u8 func_02168724(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);
/* * Calls func_02168864 with two zeroed arguments between the tail arguments. */ unsigned char func_02168848(void *p, int a, int b);
/* * sdk: DWC_GetFriendStatusDataSC (libdwcmatch.TWL.HYB.a(dwc_friend.o)) */ unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
/* * sdk: DWC_SetOwnStatusData (libdwcmatch.TWL.HYB.a(dwc_friend.o)) */ int func_021688FC(char *statusData, unsigned long size);
/* * sdk: DWC_SetBuddyFriendCallback (dwc_friend.o) */ int func_02168994(void (*callback)(int, void *), void *param);
extern char g_021A2004[];
extern char g_021A2008[];
extern struct FriendGlobal g_021AA860;




/*
 * Tail call with the last argument moved to the fourth slot.
 */
u8 func_0216870C(int a, int b)
{
    return func_02168724((void *)a, 0, 0, (char *)b);
}




/*
 * sdk:      DWC_GetFriendStatusSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
u8 func_02168724(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString)
{
    u8 state;
    GPBuddyStatus status;
    int len;
    char valueStr[4];

    if (func_0216980C(friendData, &status)) {
        if (status.status == 6) {
            if (maxEntry) {
                len = func_021684CC(g_021A2004, valueStr, status.statusString, '/');
                if (len > 0)
                    *maxEntry = strtoul(valueStr, 0, 10);
                else
                    *maxEntry = 0;
            }
            if (numEntry) {
                len = func_021684CC(g_021A2008, valueStr, status.statusString, '/');
                if (len > 0)
                    *numEntry = strtoul(valueStr, 0, 10);
                else
                    *numEntry = 0;
            }
        } else {
            if (maxEntry)
                *maxEntry = 0;
            if (numEntry)
                *numEntry = 0;
        }
        if (statusString)
            strcpy(statusString, status.locationString);
        state = status.status;
        if (func_02176984(&status))
            state = 2;
        return state;
    }
    if (maxEntry)
        *maxEntry = 0;
    if (numEntry)
        *numEntry = 0;
    return 0;
}




/*
 * Calls func_02168864 with two zeroed arguments between the tail arguments.
 */
unsigned char func_02168848(void *p, int a, int b)
{
    unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
    return func_02168864(p, 0, 0, (char *)a, (int *)b);
}



/*
 * sdk:      DWC_GetFriendStatusDataSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size)
{
	char statusString[256];
	unsigned char ret;
	ret = func_02168724(friendData, maxEntry, numEntry, statusString);
	if (ret == 0) {
		*size = -1;
		return ret;
	}
	*size = func_02059CBC(statusString, func_0209477C((const u8 *)statusString), 0, 0);
	if (statusData == 0 || *size == -1)
		return ret;
	func_02059CBC(statusString, func_0209477C((const u8 *)statusString), statusData, *size);
	return ret;
}



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
