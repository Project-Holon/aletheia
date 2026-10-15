/*
 * function: sciWsSetReportIntentionCallback
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
 *   gsXmlMoveToStart  0x021834D0  arm  ov009
 *   gsXmlMoveToNext  0x021834E8  arm  ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm  ov009
 *   gsXmlReadChildAsStringNT  0x0218372C  arm  ov009
 *   sciInterfaceSetConnectionId  0x021DF948  arm  ov175
 *   sSciTagSetReportIntentionResponse  0x021E4338  data
 *   sSciTagSetReportIntentionResult  0x021E4354  data
 *   sSciTagResult  0x021E42BC  data
 *   sSciTagCcid  0x021E42CC  data
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

extern int gsXmlMoveToStart(int *p);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void sciInterfaceSetConnectionId(char *obj, int v);
extern char sSciTagSetReportIntentionResponse[];
extern char sSciTagSetReportIntentionResult[];
extern char sSciTagResult[];
extern char sSciTagCcid[];

void sciWsSetReportIntentionCallback(int theHttpResult, int unused, void *theResponseData, void *theUserData)
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
        if (!gsXmlMoveToStart(theResponseData) || !gsXmlMoveToNext(theResponseData, sSciTagSetReportIntentionResponse) ||
            !gsXmlMoveToNext(theResponseData, sSciTagSetReportIntentionResult) ||
            !gsXmlReadChildAsInt(theResponseData, sSciTagResult, &intentionResult) ||
            !gsXmlReadChildAsStringNT(theResponseData, sSciTagCcid, ccid, 255)) {
            aTranslatedResult = 9;
        } else if (intentionResult != 0) {
            aTranslatedResult = 8;
        } else {
            sciInterfaceSetConnectionId(aWebServices->mInterface, (int)ccid);
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
