/*
 * function: gpiProcessRecvBuddyStatusInfo
 * address:  0x02187D60
 * packet:   pkt_ov009_02187D60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gpiProcessRecvBuddyStatusInfo (libdwcgsgp.TWL.HYB.a gpibuddy.o)
 *
 * residue:  full body, all 103 relocations resolve, 2204/2264 bytes.  The
 *   60-byte gap is exit sharing: the original branches the
 *   `profile->unk20 != 0 || profile->unk2c != 0` early `return 0` and the four
 *   `gpiSetErrorString; return 1` arms to shared epilogues, while mwcc here
 *   predicated them inline (`addne sp; movne r0; popne`).  The four-`atoi`
 *   IP pack is `(a<<24)|(b<<16)|(c>>24)|((d>>8)<<8)` as the original emits it.
 *
 * symbols:
 *   gsiTimeNitro                  0x02184098 arm ov009
 *   gpiValueForKey                0x02193418 arm ov009
 *   gpiSetError                   0x02193710 arm ov009
 *   gpiCallErrorCallback          0x02189D78 arm ov009
 *   atoi                          0x020964E0 arm
 *   gpiProfileListAdd             0x0218FCD8 arm ov009
 *   gpiSetErrorString             0x02193734 arm ov009
 *   gsimalloc                     0x0217EAB0 arm ov009
 *   memset                        0x020923B0 arm
 *   gpiRemoveBuddyStatus          0x021900BC arm ov009
 *   ArrayNew                      0x02184144 arm ov009
 *   gsifree                       0x0217EAE0 arm ov009
 *   goastrdup                     0x0217F1E0 arm ov009
 *   gpiAddCallback                0x02189DFC arm ov009
 *   g_021A43AC                    0x021A43AC data
 *   g_021A4280                    0x021A4280 data
 *   g_021A42BC                    0x021A42BC data
 *   g_021A43B8                    0x021A43B8 data
 *   g_021A43C0                    0x021A43C0 data
 *   g_021A43C8                    0x021A43C8 data
 *   g_021A43D0                    0x021A43D0 data
 *   g_021A43DC                    0x021A43DC data
 *   g_021A43E8                    0x021A43E8 data
 *   g_021A43F0                    0x021A43F0 data
 *   g_021A43F8                    0x021A43F8 data
 *   g_021A4404                    0x021A4404 data
 *   g_021A4410                    0x021A4410 data
 *   g_021A441C                    0x021A441C data
 *   g_021A4428                    0x021A4428 data
 *   g_021A4434                    0x021A4434 data
 *   g_021A4440                    0x021A4440 data
 */

typedef struct GPIBuddyStatusInfo {
    int unk0;
    int unk4;
    char *unk8;
    char *unkc;
    char *unk10;
    char *unk14;
    int unk18;
    unsigned int unk1c;
    unsigned short unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned short unk2c;
    unsigned short unk2e;
    int unk30;
    int unk34;
    void *unk38;
} GPIBuddyStatusInfo;

typedef struct GPIProfile {
    char pad0[8];
    GPIBuddyStatusInfo *unk8;
    GPIBuddyStatusInfo *unkc;
    char pad10[0x10];
    int unk20;
    char pad24[8];
    int unk2c;
} GPIProfile;

typedef struct GPICallback {
    void (*fn)(void *, void *);
    void *arg;
} GPICallback;

typedef struct GPIConnection {
    char pad0[0x1b8];
    GPICallback callback;
    char pad1[0x5d0 - 0x1c0];
    int numBuddies;
} GPIConnection;

typedef struct GPRecvBuddyStatusArg {
    int profileid;
    long date;
    int buddyIndex;
} GPRecvBuddyStatusArg;

extern long gsiTimeNitro(long *timer);
extern int gpiValueForKey(char *command, char *key, char *value, int len);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int atoi(const char *s);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void *gsimalloc(unsigned long size);
extern void memset(void *dst, int val, unsigned long n);
extern void gpiRemoveBuddyStatus(void *buddyStatus);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg,
                          void *operation, int type);

extern char g_021A43AC[];
extern char g_021A4280[];
extern char g_021A42BC[];
extern char g_021A43B8[];
extern char g_021A43C0[];
extern char g_021A43C8[];
extern char g_021A43D0[];
extern char g_021A43DC[];
extern char g_021A43E8[];
extern char g_021A43F0[];
extern char g_021A43F8[];
extern char g_021A4404[];
extern char g_021A4410[];
extern char g_021A441C[];
extern char g_021A4428[];
extern char g_021A4434[];
extern char g_021A4440[];
extern void gpiStatusInfoKeyFree(void *ptr);

#define PARSE_KEY(k) do { \
    if (!gpiValueForKey(input, (k), buffer, 0x400)) { \
        gpiSetError(connection, 1, g_021A4280); \
        gpiCallErrorCallback(connection, 3, 1); \
        return 3; \
    } \
} while (0)

static int gpiProcessRecvBuddyStatusInfo(void **connection, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char buffer[1024];
    int flag = 0;
    int profileid;
    long date;
    GPIProfile *profile;
    GPIBuddyStatusInfo *buddyStatus;
    GPICallback callback;
    GPRecvBuddyStatusArg *anArg;

    date = gsiTimeNitro(0);

    PARSE_KEY(g_021A43AC);
    profileid = atoi(buffer);
    profile = gpiProfileListAdd(connection, profileid);
    if (profile == 0) {
        gpiSetErrorString(connection, g_021A42BC);
        return 1;
    }
    if (profile->unk20 != 0 || profile->unk2c != 0)
        return 0;

    if (profile->unkc == 0) {
        profile->unkc = (GPIBuddyStatusInfo *)gsimalloc(0x3c);
        if (profile->unkc == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        memset(profile->unkc, 0, 0x3c);
        if (profile->unk8 == 0) {
            profile->unkc->unk0 = iconnection->numBuddies++;
        } else {
            profile->unkc->unk0 = *(int *)profile->unk8;
            gpiRemoveBuddyStatus((void *)profile->unk8);
            profile->unk8 = 0;
        }
        flag = 1;
        profile->unkc->unk38 = ArrayNew(8, 1, gpiStatusInfoKeyFree);
        if (profile->unkc->unk38 == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return flag;
        }
    }

    buddyStatus = profile->unkc;

    PARSE_KEY(g_021A43B8);
    buddyStatus->unk4 = atoi(buffer);

    PARSE_KEY(g_021A43C0);
    buddyStatus->unk1c = (atoi(buffer) << 24) | (atoi(buffer) << 16) |
                         (atoi(buffer) >> 24) | ((atoi(buffer) >> 8) << 8);

    PARSE_KEY(g_021A43C8);
    buddyStatus->unk20 = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43D0);
    buddyStatus->unk24 = (atoi(buffer) << 24) | (atoi(buffer) << 16) |
                         (atoi(buffer) >> 24) | ((atoi(buffer) >> 8) << 8);

    PARSE_KEY(g_021A43DC);
    buddyStatus->unk28 = (atoi(buffer) << 24) | (atoi(buffer) << 16) |
                         (atoi(buffer) >> 24) | ((atoi(buffer) >> 8) << 8);

    PARSE_KEY(g_021A43E8);
    buddyStatus->unk2c = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43F0);
    buddyStatus->unk2e = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43F8);
    buddyStatus->unk18 = atoi(buffer);
    gsifree(buddyStatus->unk8);
    buddyStatus->unk8 = 0;

    PARSE_KEY(g_021A4404);
    buddyStatus->unk8 = goastrdup(buffer);
    gsifree(buddyStatus->unkc);
    buddyStatus->unkc = 0;

    PARSE_KEY(g_021A4410);
    buddyStatus->unkc = goastrdup(buffer);
    gsifree(buddyStatus->unk10);
    buddyStatus->unk10 = 0;

    PARSE_KEY(g_021A441C);
    buddyStatus->unk10 = goastrdup(buffer);
    gsifree(buddyStatus->unk14);
    buddyStatus->unk14 = 0;

    PARSE_KEY(g_021A4428);
    buddyStatus->unk14 = goastrdup(buffer);

    PARSE_KEY(g_021A4434);
    buddyStatus->unk34 = atoi(buffer);

    PARSE_KEY(g_021A4440);
    buddyStatus->unk30 = atoi(buffer);

    callback = iconnection->callback;
    if (callback.fn != 0) {
        anArg = (GPRecvBuddyStatusArg *)gsimalloc(0xc);
        if (anArg == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        anArg->date = date;
        anArg->buddyIndex = buddyStatus->unk0;
        anArg->profileid = profileid;
        return gpiAddCallback(connection, callback, anArg, 0, 0);
    }
    return 0;
}
