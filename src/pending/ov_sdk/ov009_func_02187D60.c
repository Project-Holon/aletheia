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
 * residue: 2260/2264 bytes (-4), one instruction out; every earlier site is now
 *   byte-exact.  Three source shapes were the whole 60-byte gap:
 *   1. the four-atoi pack is a masked-shift chain written in the term order
 *      `(u32)atoi>>24 & 0xff | (u32)atoi>>8 & 0xff00 | (u32)atoi<<8 & 0xff0000 |
 *      (u32)atoi<<24 & 0xff000000`.  The (unsigned int) casts are required (the
 *      image uses lsr) and the term order fixes which atoi result feeds which
 *      register (1st <<24, 2nd <<8, 3rd >>24, 4th >>8).  Three occurrences.
 *   2. the unk20/unk2c guard shares the function's return 0, so it has to be the
 *      inverted `if (unk20 == 0 && unk2c == 0) { ...body... }` plus one trailing
 *      `return 0`; a bare `if (...) return 0;` is predicated, not branched.
 *   3. for the `unk8 == 0` if/else, writing the gpiRemoveBuddyStatus arm first and
 *      the numBuddies++ arm in the else makes 1.1p1 predicate the short arm and
 *      jump over the call arm with one beq - the image's shape.
 *   Remaining: the exit of the callback.fn != 0 arm.  Image `bl gpiAddCallback;
 *   cmp r0,#0; addne sp,#0x14; addne sp,#0x400; popne {...}` falls into the shared
 *   `mov r0,#0; add sp;...; pop`; ours emits `bl gpiAddCallback; add sp,#0x14; add
 *   sp,#0x400; pop`, duplicating the epilogue instead of routing the arm through
 *   the zero exit.
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
    if (profile->unk20 == 0 && profile->unk2c == 0) {

    if (profile->unkc == 0) {
        profile->unkc = (GPIBuddyStatusInfo *)gsimalloc(0x3c);
        if (profile->unkc == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        memset(profile->unkc, 0, 0x3c);
        if (profile->unk8 != 0) {
            profile->unkc->unk0 = *(int *)profile->unk8;
            gpiRemoveBuddyStatus((void *)profile->unk8);
            profile->unk8 = 0;
        } else {
            profile->unkc->unk0 = iconnection->numBuddies++;
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
    buddyStatus->unk1c = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43C8);
    buddyStatus->unk20 = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43D0);
    buddyStatus->unk24 = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43DC);
    buddyStatus->unk28 = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

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
    }
    return 0;
}
