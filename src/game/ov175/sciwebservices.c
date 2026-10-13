/*
 * file:     sciwebservices.c
 * unit:     yes
 * function: sciWsInit, sciWsDestroy, sciWsThink, sciWsCreateSession, sciWsCreateSessionCallback, sciWsSetReportIntention, sciWsSetReportIntentionCallback, sciWsSubmitReportCustom, sciWsSubmitReport, sciWsSubmitReportCallback
 * address:  0x021E06DC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Stats and Control client (libdwcgssc, object sciwebservices.o): the
 * SOAP calls of the competition service (CreateSession, SetReportIntention,
 * SubmitReport) with their response callbacks. One call of each kind can be
 * pending at a time.
 *
 * symbols:
 *   sciInterfaceSetSessionId  0x021DF928  arm  ov175
 *   sciInterfaceSetConnectionId  0x021DF948  arm  ov175
 *   wsLoginCertWriteXML  0x021E2874  arm  ov175
 *   gSciSoapNamespaces  0x021E41B8  data
 *   sSciNamespaceGsc  0x021E41E4  data
 *   sSciTagCreateSession  0x021E41E8  data
 *   sSciTagCertificate  0x021E41F8  data
 *   sSciTagProof  0x021E4204  data
 *   sSciTagGameId  0x021E420C  data
 *   sSciSoapActionCreateSession  0x021E4214  data
 *   sSciTagCreateSessionResponse  0x021E4250  data
 *   sSciTagCreateMatchlessSessionResponse  0x021E4268  data
 *   sSciTagCreateSessionResult  0x021E4288  data
 *   sSciTagCreateMatchlessSessionResult  0x021E429C  data
 *   sSciTagResult  0x021E42BC  data
 *   sSciTagCsid  0x021E42C4  data
 *   sSciTagCcid  0x021E42CC  data
 *   sSciTagSetReportIntention  0x021E42D4  data
 *   sSciTagAuthoritative  0x021E42E8  data
 *   sSciSoapActionSetReportIntention  0x021E42F8  data
 *   sSciTagSetReportIntentionResponse  0x021E4338  data
 *   sSciTagSetReportIntentionResult  0x021E4354  data
 *   sSciReportFileName  0x021E4370  data
 *   sSciReportContentType  0x021E4378  data
 *   sSciTagSubmitReport  0x021E4388  data
 *   sSciSoapActionSubmitReport  0x021E4398  data
 *   sSciTagSubmitReportResponse  0x021E43D4  data
 *   sSciTagSubmitReportResult  0x021E43EC  data
 *   gScStatsServiceUrl  0x021E52B4  data
 *   ghiPostAddFileFromMemory  0x021C24B4  arm ov114
 *   gsCoreIsShutdown  0x0217CE1C  arm ov009
 *   gsCoreThink  0x0217CCCC  arm ov009
 *   gsXmlCloseWriter  0x02181DE8  arm ov009
 *   gsXmlCreateStreamWriter  0x021819B0  arm ov009
 *   gsXmlFreeWriter  0x02181D84  arm ov009
 *   gsXmlMoveToNext  0x021834E8  arm ov009
 *   gsXmlMoveToStart  0x021834D0  arm ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm ov009
 *   gsXmlReadChildAsStringNT  0x0218372C  arm ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm ov009
 *   gsXmlWriteHexBinaryElement  0x02182E90  arm ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm ov009
 *   gsiExecuteSoap  0x0217FD7C  arm ov009
 *   gsiExecuteSoapCustom  0x0217FE68  arm ov009
 */
#include "sc_types.h"

extern int gsCoreIsShutdown(void);
extern void gsCoreThink(unsigned int theMS);
extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlCloseWriter(void *stream);
extern void gsXmlFreeWriter(void *stream);
extern int gsXmlMoveToStart(void *stream);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void *gsiExecuteSoap(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc,
                            void *theUserData);
extern void *gsiExecuteSoapCustom(char *theURL, char *theService, void *theRequestSoap,
                                  GSSoapCallback theCallbackFunc, GSSoapRequestFunc theRequestFunc,
                                  void *theUserData);
extern int ghiPostAddFileFromMemory(struct GHIPost *_post, char *name, char *buffer, int bufferLen,
                                    char *reportFilename, char *contentType);
extern int wsLoginCertWriteXML(GSLoginCertificate *theCertificate, char *theNamespace, void *theWriter);

void sciWsCreateSessionCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData);
void sciWsSetReportIntentionCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData);
void sciWsSubmitReportCustom(struct GHIPost *thePost, void *theUserData);
void sciWsSubmitReportCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData);

extern char *gSciSoapNamespaces[1];
extern char sSciNamespaceGsc[];
extern char sSciTagCreateSession[];
extern char sSciTagCertificate[];
extern char sSciTagProof[];
extern char sSciTagGameId[];
extern char gScStatsServiceUrl[];
extern char sSciSoapActionCreateSession[];
extern char sSciTagCreateSessionResponse[];
extern char sSciTagCreateMatchlessSessionResponse[];
extern char sSciTagCreateSessionResult[];
extern char sSciTagCreateMatchlessSessionResult[];
extern char sSciTagResult[];
extern char sSciTagCsid[];
extern char sSciTagCcid[];
extern char sSciTagSetReportIntention[];
extern char sSciTagAuthoritative[];
extern char sSciSoapActionSetReportIntention[];
extern char sSciTagSetReportIntentionResponse[];
extern char sSciTagSetReportIntentionResult[];
extern char sSciReportFileName[];
extern char sSciReportContentType[];
extern char sSciTagSubmitReport[];
extern char sSciSoapActionSubmitReport[];
extern char sSciTagSubmitReportResponse[];
extern char sSciTagSubmitReportResult[];

/* sciWsInit: clears the callbacks and pending flags and marks the web services live. */
int sciWsInit(SCWebServices *theWebServices, SCInterface *theInterface)
{
    if (gsCoreIsShutdown() != 0)
        return SCResult_CORE_NOT_INITIALIZED;
    theWebServices->mInterface = theInterface;
    theWebServices->mCreateSessionCallback = 0;
    theWebServices->mSetReportIntentionCallback = 0;
    theWebServices->mSubmitReportDataCallback = 0;
    theWebServices->mCreateSessionUserData = 0;
    theWebServices->mSetReportIntentionUserData = 0;
    theWebServices->mSubmitReportUserData = 0;
    theWebServices->mCreateSessionPending = 0;
    theWebServices->mSetReportIntentionPending = 0;
    theWebServices->mSubmitReportPending = 0;
    theWebServices->mInit = 1;
    return SCResult_NO_ERROR;
}

/* sciWsDestroy: clears the live flag, the callbacks and the pending flags, in the order the image writes them. */
void sciWsDestroy(SCWebServices *theWebServices)
{
    theWebServices->mInit = 0;
    theWebServices->mCreateSessionCallback = 0;
    theWebServices->mSetReportIntentionCallback = 0;
    theWebServices->mSubmitReportDataCallback = 0;
    theWebServices->mCreateSessionUserData = 0;
    theWebServices->mSetReportIntentionUserData = 0;
    theWebServices->mSubmitReportUserData = 0;
    theWebServices->mCreateSessionPending = 0;
    theWebServices->mSetReportIntentionPending = 0;
    theWebServices->mSubmitReportPending = 0;
    theWebServices->mInterface = 0;
}

/* sciWsThink: lets the GameSpy core run its tasks. */
void sciWsThink(SCWebServices *theWebServices)
{
    gsCoreThink(0);
}

/* sciWsCreateSession: sends the CreateSession SOAP call with the certificate, proof and game id. */
int sciWsCreateSession(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int theTimeoutMs,
                  void *theUserData)
{
    void *aRequest;

    if (theWebServices->mCreateSessionPending)
        return SCResult_CALLBACK_PENDING;
    aRequest = gsXmlCreateStreamWriter((const char **)gSciSoapNamespaces, 1);
    if (!aRequest)
        return SCResult_OUT_OF_MEMORY;
    if (!gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCreateSession) ||
        !gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !wsLoginCertWriteXML(theCertificate, sSciNamespaceGsc, aRequest) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !gsXmlWriteHexBinaryElement(aRequest, sSciNamespaceGsc, sSciTagProof, (unsigned char *)thePrivateData->mKeyHash, 16) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagGameId, theGameId) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCreateSession) ||
        !gsXmlCloseWriter(aRequest)) {
        gsXmlFreeWriter(aRequest);
        return SCResult_HTTP_ERROR;
    }
    theWebServices->mCreateSessionCallback = theCallback;
    theWebServices->mCreateSessionUserData = theUserData;
    theWebServices->mCreateSessionPending = 1;
    gsiExecuteSoap(gScStatsServiceUrl, sSciSoapActionCreateSession, aRequest, sciWsCreateSessionCallback, theWebServices);
    return SCResult_NO_ERROR;
}

/* sciWsCreateSessionCallback: reads the session and connection ids from the response and calls back. */
void sciWsCreateSessionCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData)
{
    int aTranslatedResult = SCResult_HTTP_ERROR;
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    char csid[255];
    char ccid[255];
    int createResult;

    if (!aWebServices->mInit)
        return;
    if (theHttpResult == 0) {
        createResult = 0;
        if (!gsXmlMoveToStart(theResponseData))
            aTranslatedResult = SCResult_RESPONSE_INVALID;
        else if (!gsXmlMoveToNext(theResponseData, sSciTagCreateSessionResponse) && !gsXmlMoveToNext(theResponseData, sSciTagCreateMatchlessSessionResponse))
            aTranslatedResult = SCResult_RESPONSE_INVALID;
        if (!gsXmlMoveToNext(theResponseData, sSciTagCreateSessionResult) && !gsXmlMoveToNext(theResponseData, sSciTagCreateMatchlessSessionResult))
            aTranslatedResult = SCResult_RESPONSE_INVALID;
        if (!gsXmlReadChildAsInt(theResponseData, sSciTagResult, &createResult))
            aTranslatedResult = SCResult_RESPONSE_INVALID;
        else if (aTranslatedResult != SCResult_RESPONSE_INVALID) {
            if (createResult == 0) {
                if (!gsXmlReadChildAsStringNT(theResponseData, sSciTagCsid, csid, 255) ||
                    !gsXmlReadChildAsStringNT(theResponseData, sSciTagCcid, ccid, 255)) {
                    aTranslatedResult = SCResult_RESPONSE_INVALID;
                } else {
                    sciInterfaceSetSessionId(aWebServices->mInterface, csid);
                    sciInterfaceSetConnectionId(aWebServices->mInterface, ccid);
                    aTranslatedResult = SCResult_NO_ERROR;
                }
            } else {
                aTranslatedResult = SCResult_RESPONSE_INVALID;
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

/*
 * sciWsSetReportIntention: sends the SetReportIntention SOAP call with the
 * session id, the connection id and the authoritative flag.
 *
 * The DWARF prototype places theUserData at fb+60 after theCallback at fb+52; the
 * object reads the user data one word past the callback, so an unused word parameter
 * (theTimeoutMs here) sits between them.
 */
int sciWsSetReportIntention(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback,
                  unsigned int theTimeoutMs, void *theUserData)
{
    void *aRequest;

    if (theWebServices->mSetReportIntentionPending)
        return SCResult_CALLBACK_PENDING;
    aRequest = gsXmlCreateStreamWriter((const char **)gSciSoapNamespaces, 1);
    if (aRequest == 0)
        return SCResult_OUT_OF_MEMORY;
    if (!gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagSetReportIntention) ||
        !gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !wsLoginCertWriteXML(theCertificate, sSciNamespaceGsc, aRequest) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !gsXmlWriteHexBinaryElement(aRequest, sSciNamespaceGsc, sSciTagProof, (unsigned char *)thePrivateData->mKeyHash, 16) ||
        !gsXmlWriteStringElement(aRequest, sSciNamespaceGsc, sSciTagCsid, theSessionId) ||
        !gsXmlWriteStringElement(aRequest, sSciNamespaceGsc, sSciTagCcid, theConnectionId) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagGameId, theGameId) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagAuthoritative, isAuthoritative ? 1 : 0) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagSetReportIntention) ||
        !gsXmlCloseWriter(aRequest)) {
        gsXmlFreeWriter(aRequest);
        return SCResult_HTTP_ERROR;
    }
    theWebServices->mSetReportIntentionCallback = theCallback;
    theWebServices->mSetReportIntentionUserData = theUserData;
    theWebServices->mSetReportIntentionPending = 1;
    gsiExecuteSoap(gScStatsServiceUrl, sSciSoapActionSetReportIntention, aRequest, sciWsSetReportIntentionCallback, theWebServices);
    return SCResult_NO_ERROR;
}

/* sciWsSetReportIntentionCallback: reads the new connection id from the response and calls back. */
void sciWsSetReportIntentionCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData)
{
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    int aTranslatedResult;
    char ccid[255];
    int intentionResult;

    if (!aWebServices->mInit)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = SCResult_NO_ERROR;
        intentionResult = 0;
        if (!gsXmlMoveToStart(theResponseData) || !gsXmlMoveToNext(theResponseData, sSciTagSetReportIntentionResponse) ||
            !gsXmlMoveToNext(theResponseData, sSciTagSetReportIntentionResult) ||
            !gsXmlReadChildAsInt(theResponseData, sSciTagResult, &intentionResult) ||
            !gsXmlReadChildAsStringNT(theResponseData, sSciTagCcid, ccid, 255)) {
            aTranslatedResult = SCResult_RESPONSE_INVALID;
        } else if (intentionResult != 0) {
            aTranslatedResult = SCResult_UNKNOWN_RESPONSE;
        } else {
            sciInterfaceSetConnectionId(aWebServices->mInterface, ccid);
        }
    } else {
        aTranslatedResult = SCResult_HTTP_ERROR;
    }
    aWebServices->mSetReportIntentionPending = 0;
    if (aWebServices->mSetReportIntentionCallback) {
        aWebServices->mSetReportIntentionCallback(aWebServices->mInterface, theHttpResult, aTranslatedResult,
                                                  aWebServices->mSetReportIntentionUserData);
        aWebServices->mSetReportIntentionUserData = 0;
        aWebServices->mSetReportIntentionCallback = 0;
    }
}

/*
 * sciWsSubmitReportCustom: request function of the SubmitReport call; attaches
 * the report buffer to the HTTP post as the file "report" (application/bin).
 */
void sciWsSubmitReportCustom(struct GHIPost *thePost, void *theUserData)
{
    SCWebServices *theWebServices = (SCWebServices *)theUserData;

    ghiPostAddFileFromMemory(thePost, sSciReportFileName, (char *)theWebServices->mSubmitReportData,
                             theWebServices->mSubmitReportLength, sSciReportFileName, sSciReportContentType);
}

/*
 * sciWsSubmitReport: sends the SubmitReport SOAP call; the report buffer itself
 * goes in the same post as a binary file.
 *
 * The DWARF prototype places theUserData at fb+72 after theCallback at fb+64; the
 * object reads the user data one word past the callback, so an unused word parameter
 * (theTimeoutMs here) sits between them.
 */
int sciWsSubmitReport(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, SCIReport *theReport, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    void *aRequest;

    if (theWebServices->mSubmitReportPending)
        return SCResult_CALLBACK_PENDING;
    if (theReport->mBuffer.mLength < SCI_REPORT_HEADER_SIZE)
        return SCResult_REPORT_INVALID;
    aRequest = gsXmlCreateStreamWriter((const char **)gSciSoapNamespaces, 1);
    if (aRequest == 0)
        return SCResult_OUT_OF_MEMORY;
    if (!gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagSubmitReport) ||
        !gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !wsLoginCertWriteXML(theCertificate, sSciNamespaceGsc, aRequest) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !gsXmlWriteHexBinaryElement(aRequest, sSciNamespaceGsc, sSciTagProof, (unsigned char *)thePrivateData->mKeyHash, 16) ||
        !gsXmlWriteStringElement(aRequest, sSciNamespaceGsc, sSciTagCsid, theSessionId) ||
        !gsXmlWriteStringElement(aRequest, sSciNamespaceGsc, sSciTagCcid, theConnectionId) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagGameId, theGameId) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagAuthoritative, isAuthoritative ? 1 : 0) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagSubmitReport) ||
        !gsXmlCloseWriter(aRequest)) {
        gsXmlFreeWriter(aRequest);
        return SCResult_OUT_OF_MEMORY;
    }
    theWebServices->mSubmitReportData = theReport->mBuffer.mData;
    theWebServices->mSubmitReportLength = theReport->mBuffer.mLength;
    theWebServices->mSubmitReportDataCallback = theCallback;
    theWebServices->mSubmitReportUserData = theUserData;
    theWebServices->mSubmitReportPending = 1;
    gsiExecuteSoapCustom(gScStatsServiceUrl, sSciSoapActionSubmitReport, aRequest, sciWsSubmitReportCallback, sciWsSubmitReportCustom, theWebServices);
    return SCResult_NO_ERROR;
}

/* sciWsSubmitReportCallback: translates the SubmitReport response and calls back. */
void sciWsSubmitReportCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData)
{
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    int submitResult;
    int aTranslatedResult;

    if (aWebServices->mInit == 0)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = SCResult_NO_ERROR;
        submitResult = 0;
        if (!gsXmlMoveToStart(theResponseData)
            || !gsXmlMoveToNext(theResponseData, sSciTagSubmitReportResponse)
            || !gsXmlMoveToNext(theResponseData, sSciTagSubmitReportResult)
            || !gsXmlReadChildAsInt(theResponseData, sSciTagResult, &submitResult)) {
            aTranslatedResult = SCResult_RESPONSE_INVALID;
        } else if (submitResult != 0) {
            if (submitResult == 7)
                aTranslatedResult = SCResult_REPORT_INVALID;
            else
                aTranslatedResult = SCResult_UNKNOWN_RESPONSE;
        }
    } else {
        aTranslatedResult = SCResult_HTTP_ERROR;
    }
    aWebServices->mSubmitReportPending = 0;
    if (aWebServices->mSubmitReportDataCallback != 0) {
        aWebServices->mSubmitReportDataCallback(aWebServices->mInterface, theHttpResult, aTranslatedResult,
                                                aWebServices->mSubmitReportUserData);
        aWebServices->mSubmitReportUserData = 0;
        aWebServices->mSubmitReportDataCallback = 0;
    }
}
