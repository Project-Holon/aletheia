/*
 * function: DWC_GetFriendStatusSC
 * address:  0x02168724
 * packet:   pkt_ov009_02168724
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetFriendStatusSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   DWCi_GetFriendBuddyStatus  0x0216980C  arm  ov009
 *   DWC_GetCommonValueString  0x021684CC  arm  ov009
 *   strtoul        0x02095EAC  arm
 *   strcpy         0x02094798  arm
 *   DWCi_IsLockedBuddyStatus  0x02176984  arm  ov009
 *   gDwcFriendMaxEntryKey     0x021A2004  data
 *   gDwcFriendNumEntryKey     0x021A2008  data
 */

#include "../arm9_sdk/libc/string.h"

typedef unsigned char u8;

typedef struct {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

extern char gDwcFriendMaxEntryKey[];
extern char gDwcFriendNumEntryKey[];
extern int DWCi_GetFriendBuddyStatus(void *friendData, GPBuddyStatus *status);
extern int DWC_GetCommonValueString(char *key, char *value, char *string, char separator);
extern unsigned long strtoul(const char *s, char **end, int base);
extern int DWCi_IsLockedBuddyStatus(GPBuddyStatus *status);

u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString)
{
    u8 state;
    GPBuddyStatus status;
    int len;
    char valueStr[4];

    if (DWCi_GetFriendBuddyStatus(friendData, &status)) {
        if (status.status == 6) {
            if (maxEntry) {
                len = DWC_GetCommonValueString(gDwcFriendMaxEntryKey, valueStr, status.statusString, '/');
                if (len > 0)
                    *maxEntry = strtoul(valueStr, 0, 10);
                else
                    *maxEntry = 0;
            }
            if (numEntry) {
                len = DWC_GetCommonValueString(gDwcFriendNumEntryKey, valueStr, status.statusString, '/');
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
        if (DWCi_IsLockedBuddyStatus(&status))
            state = 2;
        return state;
    }
    if (maxEntry)
        *maxEntry = 0;
    if (numEntry)
        *numEntry = 0;
    return 0;
}
