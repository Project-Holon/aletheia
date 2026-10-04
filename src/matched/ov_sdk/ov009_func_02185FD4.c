/*
 * function: func_02185FD4
 * address:  0x02185FD4
 * packet:   pkt_ov009_02185FD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpGetBuddyStatus (libdwcgsgp.TWL.HYB.a gp.o)
 *
 * symbols:
 *   func_020923B0  0x020923B0  arm
 *   func_02193734  0x02193734  arm   ov009
 *   func_0219008C  0x0219008C  arm   ov009
 *   func_0219327C  0x0219327C  arm   ov009
 *   g_021A40A0     0x021A40A0  data
 *   g_021A40B0     0x021A40B0  data
 */

typedef struct GPIBuddyStatus {
    int f0;
    int status;
    char *statusString;
    char *locationString;
    int ip;
    unsigned short port;
    int quietModeFlags;
} GPIBuddyStatus;

typedef struct GPIProfile {
    int f0;
    int f4;
    GPIBuddyStatus *buddyStatus;
} GPIProfile;

typedef struct GPBuddyStatus {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

typedef struct GPIConnection {
    char pad0[0x108];
    int f108;
    char pad1[0x5d0 - 0x10c];
    int numBuddies;
} GPIConnection;

extern void *func_020923B0(void *dst, int val, unsigned long len);
extern void func_02193734(int *p, int b);
extern GPIProfile *func_0219008C(void **connection, int buddyIndex);
extern void func_0219327C(char *p, int b, int n);
extern char g_021A40A0[];
extern char g_021A40B0[];

int func_02185FD4(void **connection, int index, GPBuddyStatus *status)
{
    GPIConnection *iconnection;
    GPIProfile *profile;
    int num;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (iconnection->f108 != 0) {
        func_020923B0(status, 0, sizeof(GPBuddyStatus));
        return 0;
    }
    if (status == 0) {
        func_02193734((int *)connection, (int)g_021A40A0);
        return 2;
    }
    num = iconnection->numBuddies;
    if (index < 0 || index >= num) {
        func_02193734((int *)connection, (int)g_021A40B0);
        return 2;
    }
    profile = func_0219008C(connection, index);
    if (profile == 0) {
        func_02193734((int *)connection, (int)g_021A40B0);
        return 2;
    }
    status->profile = profile->f0;
    status->status = profile->buddyStatus->status;
    if (profile->buddyStatus->statusString == 0)
        status->statusString[0] = 0;
    else
        func_0219327C(status->statusString, (int)profile->buddyStatus->statusString, 256);
    if (profile->buddyStatus->locationString == 0)
        status->locationString[0] = 0;
    else
        func_0219327C(status->locationString, (int)profile->buddyStatus->locationString, 256);
    status->ip = profile->buddyStatus->ip;
    status->port = profile->buddyStatus->port;
    status->quietModeFlags = profile->buddyStatus->quietModeFlags;
    return 0;
}
