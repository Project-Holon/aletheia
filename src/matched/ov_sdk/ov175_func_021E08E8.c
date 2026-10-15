/*
 * function: sciWsCreateSessionCallback
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
 *   gsXmlMoveToStart  0x021834D0  arm  ov009
 *   gsXmlMoveToNext  0x021834E8  arm  ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm  ov009
 *   gsXmlReadChildAsStringNT  0x0218372C  arm  ov009
 *   sciInterfaceSetSessionId  0x021DF928  arm  ov175
 *   sciInterfaceSetConnectionId  0x021DF948  arm  ov175
 *   sSciTagCreateSessionResponse  0x021E4250  data
 *   sSciTagCreateMatchlessSessionResponse  0x021E4268  data
 *   sSciTagCreateSessionResult  0x021E4288  data
 *   sSciTagCreateMatchlessSessionResult  0x021E429C  data
 *   sSciTagResult  0x021E42BC  data
 *   sSciTagCsid  0x021E42C4  data
 *   sSciTagCcid  0x021E42CC  data
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

extern int gsXmlMoveToStart(int *p);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void sciInterfaceSetSessionId(char *obj, int v);
extern void sciInterfaceSetConnectionId(char *obj, int v);
extern char sSciTagCreateSessionResponse[];
extern char sSciTagCreateMatchlessSessionResponse[];
extern char sSciTagCreateSessionResult[];
extern char sSciTagCreateMatchlessSessionResult[];
extern char sSciTagResult[];
extern char sSciTagCsid[];
extern char sSciTagCcid[];

void sciWsCreateSessionCallback(int theHttpResult, int unused, void *theResponseData, void *theUserData)
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
        if (!gsXmlMoveToStart(theResponseData))
            aTranslatedResult = 9;
        else if (!gsXmlMoveToNext(theResponseData, sSciTagCreateSessionResponse) && !gsXmlMoveToNext(theResponseData, sSciTagCreateMatchlessSessionResponse))
            aTranslatedResult = 9;
        if (!gsXmlMoveToNext(theResponseData, sSciTagCreateSessionResult) && !gsXmlMoveToNext(theResponseData, sSciTagCreateMatchlessSessionResult))
            aTranslatedResult = 9;
        if (!gsXmlReadChildAsInt(theResponseData, sSciTagResult, &createResult))
            aTranslatedResult = 9;
        else if (aTranslatedResult != 9) {
            if (createResult == 0) {
                if (!gsXmlReadChildAsStringNT(theResponseData, sSciTagCsid, csid, 255) ||
                    !gsXmlReadChildAsStringNT(theResponseData, sSciTagCcid, ccid, 255)) {
                    aTranslatedResult = 9;
                } else {
                    sciInterfaceSetSessionId(aWebServices->mInterface, (int)csid);
                    sciInterfaceSetConnectionId(aWebServices->mInterface, (int)ccid);
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
