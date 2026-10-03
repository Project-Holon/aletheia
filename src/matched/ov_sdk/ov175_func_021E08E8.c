/*
 * function: func_021E08E8
 * address:  0x021E08E8
 * packet:   pkt_ov175_021E08E8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciWsCreateSessionCallback (sciwebservices.o)
 *
 * symbols:
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_02183A24  0x02183A24  arm  ov009
 *   func_0218372C  0x0218372C  arm  ov009
 *   func_021DF928  0x021DF928  arm  ov175
 *   func_021DF948  0x021DF948  arm  ov175
 *   g_021E4250  0x021E4250  data
 *   g_021E4268  0x021E4268  data
 *   g_021E4288  0x021E4288  data
 *   g_021E429C  0x021E429C  data
 *   g_021E42BC  0x021E42BC  data
 *   g_021E42C4  0x021E42C4  data
 *   g_021E42CC  0x021E42CC  data
 *
 * The DWARF prototype lists three parameters; the object takes the response in r2
 * and the user data in r3, so an unused word sits in r1 (as in sciWsSetReportIntentionCallback).
 */

typedef void (*SCWebCallback)(void *, int, int, void *);
typedef struct {
    void *mInterface;
    SCWebCallback mCreateSessionCallback;
    SCWebCallback mSetReportIntentionCallback;
    SCWebCallback mSubmitReportDataCallback;
    int mSetReportIntentionPending;
    int mCreateSessionPending;
    int mSubmitReportPending;
    int mGetStatsPending;
    int mGetLeaderboardPending;
    int mGetRanksPending;
    void *mSetReportIntentionUserData;
    void *mCreateSessionUserData;
    void *mSubmitReportUserData;
    void *mGetStatsUserData;
    void *mGetLeaderboardUserData;
    void *mGetRanksUserData;
    unsigned char *mSubmitReportData;
    unsigned int mSubmitReportLength;
    int mInit;
} SCWebServices;

extern int func_021834D0(int *p);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_02183A24(void *stream, char *matchtag, int *valueOut);
extern int func_0218372C(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void func_021DF928(void *theInterface, char *theSessionId);
extern void func_021DF948(void *theInterface, char *theConnectionId);
extern char g_021E4250[];
extern char g_021E4268[];
extern char g_021E4288[];
extern char g_021E429C[];
extern char g_021E42BC[];
extern char g_021E42C4[];
extern char g_021E42CC[];

void func_021E08E8(int theHttpResult, int unused, void *theResponseData, void *theUserData)
{
    int aTranslatedResult = 7;
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    char csid[255];
    char ccid[255];
    int createResult;

    if (!aWebServices->mInit)
        return;
    if (theHttpResult == 0) {
        createResult = 0;
        if (!func_021834D0(theResponseData))
            aTranslatedResult = 9;
        else if (!func_021834E8(theResponseData, g_021E4250) && !func_021834E8(theResponseData, g_021E4268))
            aTranslatedResult = 9;
        if (!func_021834E8(theResponseData, g_021E4288) && !func_021834E8(theResponseData, g_021E429C))
            aTranslatedResult = 9;
        if (!func_02183A24(theResponseData, g_021E42BC, &createResult))
            aTranslatedResult = 9;
        else if (aTranslatedResult != 9) {
            if (createResult == 0) {
                if (!func_0218372C(theResponseData, g_021E42C4, csid, 255) ||
                    !func_0218372C(theResponseData, g_021E42CC, ccid, 255)) {
                    aTranslatedResult = 9;
                } else {
                    func_021DF928(aWebServices->mInterface, csid);
                    func_021DF948(aWebServices->mInterface, ccid);
                    aTranslatedResult = 0;
                }
            } else {
                aTranslatedResult = 9;
            }
        }
    }
    aWebServices->mCreateSessionPending = 0;
    if (aWebServices->mCreateSessionCallback) {
        aWebServices->mCreateSessionCallback(aWebServices->mInterface, theHttpResult, aTranslatedResult,
                                             aWebServices->mCreateSessionUserData);
        aWebServices->mCreateSessionUserData = 0;
        aWebServices->mCreateSessionCallback = 0;
    }
}
