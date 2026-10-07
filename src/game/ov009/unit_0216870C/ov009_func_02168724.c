/*
 * function: func_02168724
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
 *   func_0216980C  0x0216980C  arm  ov009
 *   func_021684CC  0x021684CC  arm  ov009
 *   strtoul        0x02095EAC  arm
 *   strcpy         0x02094798  arm
 *   func_02176984  0x02176984  arm  ov009
 *   g_021A2004     0x021A2004  data
 *   g_021A2008     0x021A2008  data
 */

#include "../../../matched/arm9_sdk/libc/string.h"

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

extern char g_021A2004[];
extern char g_021A2008[];
extern int func_0216980C(void *friendData, GPBuddyStatus *status);
extern int func_021684CC(char *key, char *value, char *string, char separator);
extern unsigned long strtoul(const char *s, char **end, int base);
extern int func_02176984(GPBuddyStatus *status);

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
