/*
 * file:     unit_021858FC_p03.c
 * unit:     yes
 * function: func_02185FA4, func_02185FD4, func_02186108
 * address:  0x02185FA4
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
 *   func_020923B0  0x020923B0  arm
 *   func_02193734  0x02193734  arm   ov009
 *   func_0219008C  0x0219008C  arm   ov009
 *   func_0219327C  0x0219327C  arm   ov009
 *   g_021A40A0     0x021A40A0  data
 *   g_021A40B0     0x021A40B0  data
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 */
typedef struct GPIConnection_02185FA4 GPIConnection_02185FA4;

typedef struct GPIBuddyStatus {
    int f0;
    int status;
    char *statusString;
    char *locationString;
    int ip;
    unsigned short port;
    int quietModeFlags;
} GPIBuddyStatus;

typedef struct GPIProfile_02185FD4 {
    int f0;
    int f4;
    GPIBuddyStatus *buddyStatus;
} GPIProfile_02185FD4;

typedef struct GPBuddyStatus {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

typedef struct GPIConnection_02185FD4 {
    char pad0[0x108];
    int f108;
    char pad1[0x5d0 - 0x10c];
    int numBuddies;
} GPIConnection_02185FD4;

typedef struct GPIProfile_02186108 {
    int f0;
    int f4;
    int *f8;
    int *fC;
} GPIProfile_02186108;

typedef struct GPIConnection_02186108 {
    unsigned char pad[0x108];
    int f108;
} GPIConnection_02186108;

extern void *func_020923B0(void *dst, int val, unsigned long len);
extern void func_02193734(int *p, int b);
extern GPIProfile_02185FD4 *func_0219008C(void **connection, int buddyIndex);
extern void func_0219327C(char *p, int b, int n);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile_02186108 **pProfile);
int gpGetNumBuddies(void **connection, int *numBuddies);
int func_02185FD4(void **connection, int index, GPBuddyStatus *status);
int func_02186108(void **connection, int profile, int *index);
extern char g_021A40A0[];
extern char g_021A40B0[];


int gpGetNumBuddies(void **connection, int *numBuddies)
{
    GPIConnection_02185FA4 *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185FA4 *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0) {
        *numBuddies = 0;
        return 0;
    }
    *numBuddies = *(int *)((char *)iconnection + 0x5d0);
    return 0;
}


/*
 * sdk:      gpGetBuddyStatus (libdwcgsgp.TWL.HYB.a gp.o)
 */
int func_02185FD4(void **connection, int index, GPBuddyStatus *status)
{
    GPIConnection_02185FD4 *iconnection;
    GPIProfile_02185FD4 *profile;
    int num;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection_02185FD4 *)*connection;
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


/*
 * sdk:      gpGetBuddyIndex (gp.o)
 */
int func_02186108(void **connection, int profile, int *index)
{
    GPIProfile_02186108 *pProfile;

    if (connection == 0 || *connection == 0)
        return 2;
    if (((GPIConnection_02186108 *)*connection)->f108 != 0) {
        *index = 0;
        return 0;
    }
    if (func_0218FD9C(connection, profile, &pProfile) && pProfile->f8 != 0)
        *index = *pProfile->f8;
    else if (func_0218FD9C(connection, profile, &pProfile) && pProfile->fC != 0)
        *index = *pProfile->fC;
    else
        *index = -1;
    return 0;
}
