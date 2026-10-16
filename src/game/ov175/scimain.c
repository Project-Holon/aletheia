/*
 * file:     scimain.c
 * unit:     yes
 * function: scInitialize, scShutdown, scThink, scGetSessionId, scGetConnectionId, scSetSessionId, scCreateSession, scSetReportIntention, scSubmitReport, scCreateReport, scReportBeginGlobalData, scReportBeginPlayerData, scReportBeginTeamData, scReportBeginNewPlayer, scReportEnd, scReportSetPlayerData, scReportAddIntValue, scReportAddByteValue, scDestroyReport, scCleanupServiceUrl
 * address:  0x021DF9D8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Stats and Control client (libdwcgssc, object scimain.o): the public
 * entry points of the client. They check their arguments, then forward to the
 * interface (sciinterface.c), the web services (sciwebservices.c) or the report
 * writer (scireport.c).
 *
 * symbols:
 *   GSMD5Final  0x02184A34  arm ov009
 *   GSMD5Init  0x02184938  arm ov009
 *   GSMD5Update  0x0218497C  arm ov009
 *   sciInterfaceCreate  0x021DF7FC  arm  ov175
 *   sciInterfaceInit  0x021DF884  arm  ov175
 *   sciInterfaceDestroy  0x021DF8D4  arm
 *   sciInterfaceSetSessionId  0x021DF928  arm
 *   sciInterfaceSetConnectionId  0x021DF948  arm
 *   sciCreateReport  0x021DFE2C  arm  ov175
 *   sciReportSetPlayerConnectionId  0x021DFF78  arm  ov175
 *   sciReportSetPlayerTeamIndex  0x021DFFA0  arm  ov175
 *   sciReportSetPlayerGameResult  0x021DFFC8  arm  ov175
 *   sciReportReturnZero  0x021DFFF8  arm  ov175
 *   sciWsCreateSession  0x021E0774  arm  ov175
 *   sciWsSetReportIntention  0x021E0A7C  arm
 *   sciWsSubmitReport  0x021E0DB8  arm  ov175
 *   wsLoginCertIsValid  0x021E26BC  arm  ov175
 *   gsifree  0x0217EAE0  arm ov009
 *   sciGetServiceUrl  0x021DF968  arm
 *   sciDestroyReport  0x021DFF30  arm
 *   sciReportBeginNewPlayer  0x021E0000  arm
 *   sciReportBeginGlobalData  0x021E0040  arm
 *   sciReportBeginPlayerData  0x021E0070  arm
 *   sciReportBeginTeamData  0x021E0080  arm
 *   sciReportEnd  0x021E0098  arm
 *   sciReportAddIntValue  0x021E02F0  arm
 *   sciReportAddByteValue  0x021E03F8  arm
 *   sciWsThink  0x021E0764  arm
 */
#include "sc_types.h"

typedef enum SCITeamResult {
    SCITeamResult_OK = 0,
    SCITeamResult_BAD = 1
} SCITeamResult;

extern void gsifree(void *ptr);
extern void GSMD5Init(GSMD5_CTX *context);
extern void GSMD5Update(GSMD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void GSMD5Final(unsigned char *digest, GSMD5_CTX *context);
extern int wsLoginCertIsValid(GSLoginCertificate *theCertificate);

/*
 * scInitialize: creates and initialises the interface, stores the game id in
 * it and hands it back.  The result is null on failure.
 */
int scInitialize(unsigned int theGameId, SCInterface **theInterfaceOut)
{
    int theResult;
    SCInterface *theInterface = 0;

    if (theInterfaceOut == 0)
        return SCResult_INVALID_PARAMETERS;
    *theInterfaceOut = 0;
    if ((theResult = sciInterfaceCreate(&theInterface)) != 0)
        return theResult;
    if ((theResult = sciInterfaceInit(theInterface)) != 0)
        return theResult;
    theInterface->mGameId = theGameId;
    *theInterfaceOut = theInterface;
    return SCResult_NO_ERROR;
}

/* scShutdown: if the interface is live, destroys and frees it. */
int scShutdown(SCInterface *theInterface)
{
    if (theInterface == 0)
        return SCResult_INVALID_PARAMETERS;
    if (theInterface->mInit != 0) {
        sciInterfaceDestroy(theInterface);
        gsifree(theInterface);
    }
    return SCResult_NO_ERROR;
}

/*
 * scThink: runs the web services of a live interface.
 *
 * The listing extent (60 bytes) covers the two ARM accessors that follow this
 * 44 byte body; every compiled byte matches.
 */
int scThink(SCInterface *theInterface)
{
    if (theInterface == 0)
        return SCResult_INVALID_PARAMETERS;
    if (theInterface->mInit == 0)
        return SCResult_NOT_INITIALIZED;
    sciWsThink(&theInterface->mWebServices);
    return SCResult_NO_ERROR;
}

/* scGetSessionId (name guessed): the session GUID of the interface. */
unsigned char *scGetSessionId(SCInterface *theInterface)
{
    return theInterface->mSessionId;
}

/* scGetConnectionId (name guessed): the connection GUID of the interface. */
unsigned char *scGetConnectionId(SCInterface *theInterface)
{
    return theInterface->mConnectionId;
}

/* scSetSessionId: sets the session GUID and reports success. */
int scSetSessionId(SCInterface *theInterface, const char *theSessionId)
{
    sciInterfaceSetSessionId(theInterface, theSessionId);
    return SCResult_NO_ERROR;
}

/*
 * scCreateMatchlessSession: checks the login certificate, then starts the
 * CreateSession call for this game.
 */
int scCreateSession(SCInterface *theInterface, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int theTimeoutMs,
                  void *theUserData)
{
    if (wsLoginCertIsValid(theCertificate) == 0)
        return SCResult_INVALID_PARAMETERS;
    return sciWsCreateSession(&theInterface->mWebServices, theInterface->mGameId, theCertificate, thePrivateData,
                         theCallback, theTimeoutMs, theUserData);
}

/*
 * scSetReportIntention: stores the connection id (when one is given) and
 * starts the SetReportIntention call.
 */
int scSetReportIntention(SCInterface *theInterface, const char *theConnectionId, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    if (theInterface == 0)
        return SCResult_INVALID_PARAMETERS;
    if (theCertificate == 0)
        return SCResult_INVALID_PARAMETERS;
    if (thePrivateData == 0)
        return SCResult_INVALID_PARAMETERS;
    if (theInterface->mInit == 0)
        return SCResult_NOT_INITIALIZED;
    sciInterfaceSetConnectionId(theInterface, theConnectionId);
    return sciWsSetReportIntention(&theInterface->mWebServices, theInterface->mGameId, (char *)theInterface->mSessionId,
                         (char *)theInterface->mConnectionId, isAuthoritative, theCertificate, thePrivateData,
                         theCallback, theTimeoutMs, theUserData);
}

/*
 * scSubmitReport: zeroes the checksum field of the report header, computes the
 * MD5 of the whole report into it and starts the SubmitReport call.
 *
 * The checksum zero-fill is a hand-unrolled 4-byte strb loop over an UNSIGNED
 * counter, declared before the cursor: a signed counter folds the exit test into
 * `cmp n,#0` + `bgt` and reverses the two scratch registers.  See
 * docs/idioms/an-unsigned-counter-keeps-the-subs-bne-of-a-countdown-loop.md.
 */
int scSubmitReport(SCInterface *theInterface, SCIReport *theReport, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    unsigned int n;
    unsigned char *p;
    GSMD5_CTX md5;
    SCIReportHeader *header;
    SCIReport *aReport;
    SCInterface *anInterface;

    anInterface = theInterface;
    if (anInterface == 0)
        return SCResult_INVALID_PARAMETERS;
    if (anInterface->mInit == 0)
        return SCResult_NOT_INITIALIZED;
    aReport = theReport;
    header = (SCIReportHeader *)aReport->mBuffer.mData;
    p = header->mChecksum;
    n = 4;
    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    } while (--n);
    GSMD5Init(&md5);
    GSMD5Update(&md5, aReport->mBuffer.mData, aReport->mBuffer.mLength);
    GSMD5Final(header->mChecksum, &md5);
    return sciWsSubmitReport(&anInterface->mWebServices, anInterface->mGameId, (char *)anInterface->mSessionId,
                         (char *)anInterface->mConnectionId, aReport, isAuthoritative, theCertificate,
                         thePrivateData, theCallback, theTimeoutMs, theUserData);
}

/* scCreateReport: creates a report for the interface's session and hands it back on success. */
int scCreateReport(SCInterface *theInterface, unsigned int theHeaderVersion, unsigned int thePlayerCount,
                  unsigned int theTeamCount, SCIReport **theReportOut)
{
    SCIReport *theReport = 0;
    int theResult;

    if (theInterface == 0)
        return SCResult_INVALID_PARAMETERS;
    if (theReportOut == 0)
        return SCResult_INVALID_PARAMETERS;
    theResult = sciCreateReport(theInterface->mSessionId, theHeaderVersion, thePlayerCount, theTeamCount,
                              &theReport);
    if (theResult == 0)
        *theReportOut = theReport;
    return theResult;
}

/* scReportBeginGlobalData (name guessed): tail call to sciReportBeginGlobalData. */
int scReportBeginGlobalData(SCIReport *theReport)
{
    return sciReportBeginGlobalData(theReport);
}

/* scReportBeginPlayerData (name guessed): tail call to sciReportBeginPlayerData. */
int scReportBeginPlayerData(SCIReport *theReport)
{
    return sciReportBeginPlayerData(theReport);
}

/* scReportBeginTeamData (name guessed): tail call to sciReportBeginTeamData. */
int scReportBeginTeamData(SCIReport *theReport)
{
    return sciReportBeginTeamData(theReport);
}

/* scReportBeginNewPlayer (name guessed): tail call to sciReportBeginNewPlayer. */
int scReportBeginNewPlayer(SCIReport *theReport)
{
    return sciReportBeginNewPlayer(theReport);
}

/* scReportEnd (name guessed): tail call to sciReportEnd. */
int scReportEnd(SCIReport *theReport, int isAuthoritative, unsigned int theGameStatus)
{
    return sciReportEnd(theReport, isAuthoritative, theGameStatus);
}

/*
 * scReportSetPlayerData: records a player's connection id, team and result in
 * the roster.  A team seen for the first time is added to the team id list
 * (at most 64 teams).
 */
int scReportSetPlayerData(SCIReport *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId,
                  unsigned int thePlayerTeamId, int thePlayerResult, int thePlayerProfileId,
                  GSLoginCertificate *theCertificate, unsigned char *theAuthHash)
{
    SCIReport *aReport;
    SCITeamResult aResult;
    unsigned int i;
    int isNewTeam;
    unsigned int n;

    aReport = theReport;
    aResult = SCITeamResult_OK;
    isNewTeam = 1;
    for (i = 0; i < aReport->mNumTeamsReported; i++) {
        if (thePlayerTeamId == aReport->mTeamIds[i]) {
            isNewTeam = 0;
            break;
        }
    }
    if (isNewTeam) {
        n = ++aReport->mNumTeamsReported;
        if (n > SC_MAX_NUM_TEAMS)
            return SCResult_OUT_OF_MEMORY;
        aReport->mTeamIds[n - 1] = thePlayerTeamId;
    }
    if (aResult == SCITeamResult_OK)
        aResult = sciReportSetPlayerConnectionId(aReport, thePlayerIndex, thePlayerConnectionId);
    if (aResult == SCITeamResult_OK)
        aResult = sciReportSetPlayerTeamIndex(aReport, thePlayerIndex, thePlayerTeamId);
    if (aResult == SCITeamResult_OK)
        aResult = sciReportSetPlayerGameResult(aReport, thePlayerIndex, thePlayerResult);
    if (aResult != SCITeamResult_OK)
        return aResult;
    return sciReportReturnZero(aReport, thePlayerIndex, theCertificate, theAuthHash);
}

/* scReportAddIntValue (name guessed): tail call to sciReportAddIntValue. */
int scReportAddIntValue(SCIReport *theReport, int theKey, int theValue)
{
    return sciReportAddIntValue(theReport, theKey, theValue);
}

/* scReportAddByteValue (name guessed): tail call to sciReportAddByteValue. */
int scReportAddByteValue(SCIReport *theReport, int theKey, int theValue)
{
    return sciReportAddByteValue(theReport, theKey, theValue);
}

/* scDestroyReport (name guessed): tail call to sciDestroyReport. */
int scDestroyReport(SCIReport *theReport)
{
    return sciDestroyReport(theReport);
}

/* scCleanupServiceUrl (name guessed): tail call to sciGetServiceUrl. */
char *scCleanupServiceUrl(void)
{
    return sciGetServiceUrl();
}
