/*
 * function: gpiSendLogin
 * address:  0x0218A830
 * packet:   pkt_ov009_0218A830
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendLogin (gpiconnect.o)
 *
 * symbols:
 *   randomString  0x0218A1D0  arm   ov009
 *   strlen  0x0209477C  arm
 *   GSMD5Digest  0x021858A8  arm   ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_0218FF98  0x0218FF98  arm   ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
 *   g_021A483C     0x021A483C  data
 *   g_021A4840     0x021A4840  data
 *   g_021A4848     0x021A4848  data
 *   g_021A4850     0x021A4850  data
 *   g_021A4860     0x021A4860  data
 *   g_021A4894     0x021A4894  data
 *   g_021A489C     0x021A489C  data
 *   g_021A48A8     0x021A48A8  data
 *   g_021A48B4     0x021A48B4  data
 *   g_021A48C4     0x021A48C4  data
 *   g_021A48CC     0x021A48CC  data
 *   g_021A48D0     0x021A48D0  data
 *   g_021A48DC     0x021A48DC  data
 *   g_021A48E8     0x021A48E8  data
 *   g_021A48F4     0x021A48F4  data
 *   g_021A4900     0x021A4900  data
 *   g_021A490C     0x021A490C  data
 *   g_021A4914     0x021A4914  data
 *   g_021A4920     0x021A4920  data
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   g_021A492C     0x021A492C  data
 *   g_021A493C     0x021A493C  data
 *   g_021A494C     0x021A494C  data
 *   g_021A4954     0x021A4954  data
 *   g_021A495C     0x021A495C  data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIConnectData {
    char serverChallenge[128];
    char userChallenge[33];
    char passwordHash[33];
    char authtoken[256];
    char partnerchallenge[256];
    char cdkey[65];
} GPIConnectData;

typedef struct GPIProfile {
    int profileId;
    int userId;
} GPIProfile;

typedef struct GPIConnection {
    char pad0[0x100];
    int infoCaching;
    char pad104[0x10c - 0x104];
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    char pad1a8[0x210 - 0x1a8];
    GPIBuffer outputBuffer;
    char pad220[0x230 - 0x220];
    unsigned short peerPort;
    char pad232[0x60c - 0x232];
    int productID;
    int namespaceID;
    char pad614[0x630 - 0x614];
    int quietModeFlags;
} GPIConnection;

extern void randomString(char *buffer, int numChars);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern void GSMD5Digest(unsigned char *input, unsigned int len, char *output);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int func_0218FF98(void **connection, char *nick, char *email, GPIProfile **profile);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern char g_021A483C[];
extern char g_021A4840[];
extern char g_021A4848[];
extern char g_021A4850[];
extern char g_021A4860[];
extern char g_021A4894[];
extern char g_021A489C[];
extern char g_021A48A8[];
extern char g_021A48B4[];
extern char g_021A48C4[];
extern char g_021A48CC[];
extern char g_021A48D0[];
extern char g_021A48DC[];
extern char g_021A48E8[];
extern char g_021A48F4[];
extern char g_021A4900[];
extern char g_021A490C[];
extern char g_021A4914[];
extern char g_021A4920[];
extern char gGsAvailabilityGameName[];
extern char g_021A492C[];
extern char g_021A493C[];
extern char g_021A494C[];
extern char g_021A4954[];
extern char g_021A495C[];

int gpiSendLogin(void **connection, GPIConnectData *data)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char buffer[512];
    char response[33];
    GPIProfile *profile;
    char *passphrase;
    char userBuffer[82];
    char partnerBuffer[11];
    char *user;

    randomString(data->userChallenge, sizeof(data->userChallenge) - 1);

    if (data->partnerchallenge[0])
        passphrase = data->partnerchallenge;
    else
        passphrase = iconnection->password;
    GSMD5Digest((unsigned char *)passphrase, strlen((const u8 *)passphrase), data->passwordHash);

    if (iconnection->partnerID != 0)
        OS_SPrintf(partnerBuffer, g_021A483C, iconnection->partnerID);
    else
        partnerBuffer[0] = '\0';

    if (data->authtoken[0]) {
        user = data->authtoken;
    } else if (iconnection->uniquenick[0]) {
        OS_SPrintf(userBuffer, g_021A4840, partnerBuffer, iconnection->uniquenick);
        user = userBuffer;
    } else {
        OS_SPrintf(userBuffer, g_021A4848, partnerBuffer, iconnection->nick, iconnection->email);
        user = userBuffer;
    }

    OS_SPrintf(buffer, g_021A4850, data->passwordHash, g_021A4860, user,
                  data->userChallenge, data->serverChallenge, data->passwordHash);
    GSMD5Digest((unsigned char *)buffer, strlen((const u8 *)buffer), response);

    if (iconnection->infoCaching) {
        func_0218FF98(connection, iconnection->nick, iconnection->email, &profile);
        if (profile != 0) {
            iconnection->userid = profile->userId;
            iconnection->profileid = profile->profileId;
        }
    }

    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4894);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A489C);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), data->userChallenge);
    if (data->authtoken[0]) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48A8);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), data->authtoken);
    } else if (iconnection->uniquenick[0]) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48B4);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->uniquenick);
    } else {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48C4);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->nick);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48CC);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->email);
    }
    if (iconnection->userid != 0) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48D0);
        gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->userid);
    }
    if (iconnection->profileid != 0) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48DC);
        gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->profileid);
    }
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48E8);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->partnerID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A48F4);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), response);
    if (iconnection->firewall == 1)
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4900);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A490C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->peerPort);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4914);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->productID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4920);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGsAvailabilityGameName);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A492C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->namespaceID);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A493C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), 0x3b);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A494C);
    gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->quietModeFlags);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4954);
    gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
    return 0;
}
