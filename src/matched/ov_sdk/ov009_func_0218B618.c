/*
 * function: func_0218B618
 * address:  0x0218B618
 * packet:   pkt_ov009_0218B618
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiDisconnectCleanupProfile (libdwcgsgp.TWL.HYB.a gpiconnect.o)
 *
 * symbols:
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_021841B0  0x021841b0  arm   ov009
 *   func_0218FF24  0x0218ff24  arm   ov009
 */

typedef struct {
    int f0;
    int f4;
    char *f8;
    char *fC;
} GPIBuddyStatus;
typedef struct {
    int f0;
    int f4;
    char *f8;
    char *fC;
    char *f10;
    char *f14;
    char pad[0x20];
    void *f38;
} GPIBuddyStatusInfo;
typedef struct {
    int f0;
    int f4;
    GPIBuddyStatus *buddyStatus;
    GPIBuddyStatusInfo *statusInfo;
    int f10;
    char *f14;
    int f18;
    char *f1C;
    int f20;
    int f24;
    int f28;
} GPIProfile;
typedef struct {
    char pad[0x104];
    int state;
} GPIConnection;
extern void func_0217EAE0(void *ptr);
extern void func_021841B0(void *array);
extern void func_0218FF24(const int *p, void *profile);

int func_0218B618(GPIConnection **connection, GPIProfile *profile)
{
    GPIConnection *iconnection;

    iconnection = *connection;
    if (profile->buddyStatus) {
        profile->f28 = 1;
        func_0217EAE0(profile->buddyStatus->f8);
        profile->buddyStatus->f8 = 0;
        func_0217EAE0(profile->buddyStatus->fC);
        profile->buddyStatus->fC = 0;
        func_0217EAE0(profile->buddyStatus);
        profile->buddyStatus = 0;
    }
    if (profile->statusInfo) {
        profile->f28 = 1;
        func_0217EAE0(profile->statusInfo->f8);
        profile->statusInfo->f8 = 0;
        func_0217EAE0(profile->statusInfo->fC);
        profile->statusInfo->fC = 0;
        func_0217EAE0(profile->statusInfo->f10);
        profile->statusInfo->f10 = 0;
        func_0217EAE0(profile->statusInfo->f14);
        profile->statusInfo->f14 = 0;
        if (profile->statusInfo->f38) {
            func_021841B0(profile->statusInfo->f38);
            profile->statusInfo->f38 = 0;
        }
        func_0217EAE0(profile->statusInfo);
        profile->statusInfo = 0;
    }
    if (profile->f20)
        profile->f28 = 1;
    func_0217EAE0(profile->f14);
    profile->f14 = 0;
    func_0217EAE0(profile->f1C);
    profile->f1C = 0;
    profile->f18 = 0;
    if (profile->f10 == 0 || (iconnection->state == 1 && profile->f28 == 0)) {
        func_0218FF24((const int *)connection, profile);
        return 0;
    }
    return 1;
}
