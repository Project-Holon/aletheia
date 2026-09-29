/*
 * function: func_021E0C68
 * address:  0x021E0C68
 * packet:   pkt_ov175_021E0C68
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciWsSetReportIntentionCallback (libdwcgssc.TWL.HYB.a sciwebservices.o)
 *
 * symbols:
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_02183A24  0x02183A24  arm  ov009
 *   func_0218372C  0x0218372C  arm  ov009
 *   func_021DF948  0x021DF948  arm  ov175
 *   g_021E4338  0x021E4338  data
 *   g_021E4354  0x021E4354  data
 *   g_021E42BC  0x021E42BC  data
 *   g_021E42CC  0x021E42CC  data
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

extern int func_021834D0(void *stream);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_02183A24(void *stream, char *matchtag, int *valueOut);
extern int func_0218372C(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void func_021DF948(void *theInterface, char *theConnectionId);
extern char g_021E4338[];
extern char g_021E4354[];
extern char g_021E42BC[];
extern char g_021E42CC[];

void func_021E0C68(int theHttpResult, int unused, void *theResponseData, void *theUserData)
{
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    int aTranslatedResult;
    char ccid[255];
    int intentionResult;

    if (!aWebServices->mInit)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = 0;
        intentionResult = 0;
        if (!func_021834D0(theResponseData) || !func_021834E8(theResponseData, g_021E4338) ||
            !func_021834E8(theResponseData, g_021E4354) ||
            !func_02183A24(theResponseData, g_021E42BC, &intentionResult) ||
            !func_0218372C(theResponseData, g_021E42CC, ccid, 255)) {
            aTranslatedResult = 9;
        } else if (intentionResult != 0) {
            aTranslatedResult = 8;
        } else {
            func_021DF948(aWebServices->mInterface, ccid);
        }
    } else {
        aTranslatedResult = 7;
    }
    aWebServices->mSetReportIntentionPending = 0;
    if (aWebServices->mSetReportIntentionCallback) {
        aWebServices->mSetReportIntentionCallback(aWebServices->mInterface, theHttpResult,
                                                  aTranslatedResult,
                                                  aWebServices->mSetReportIntentionUserData);
        aWebServices->mSetReportIntentionUserData = 0;
        aWebServices->mSetReportIntentionCallback = 0;
    }
}
