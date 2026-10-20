/*
 * Types of the GameSpy Stats and Control client (libdwcgssc) and of the DWC
 * wrapper around it (libdwcsc), shared by dwc_sc.c, sciinterface.c, scimain.c,
 * scireport.c, sciserialize.c and sciwebservices.c.
 *
 * The game builds one match report: a header, a roster of players with their
 * team, the results, then the game, player and team key/value sections.  The
 * report is serialised big endian into one 64 KB buffer (scireport.c) and sent
 * with a SOAP call (sciwebservices.c) after a session has been created.
 *
 * symbols:
 *   sciInterfaceCreate  0x021DF7FC  arm  ov175
 *   sciInterfaceInit  0x021DF884  arm  ov175
 *   sciInterfaceDestroy  0x021DF8D4  arm  ov175
 *   sciInterfaceSetSessionId  0x021DF928  arm  ov175
 *   sciInterfaceSetConnectionId  0x021DF948  arm  ov175
 *   sciGetServiceUrl  0x021DF968  arm  ov175
 *   scInitialize  0x021DF9D8  arm  ov175
 *   scShutdown  0x021DFA3C  arm  ov175
 *   scThink  0x021DFA6C  arm  ov175
 *   scGetSessionId  0x021DFA98  arm  ov175
 *   scSetSessionId  0x021DFAA8  arm  ov175
 *   scCreateSession  0x021DFAB8  arm  ov175
 *   scSetReportIntention  0x021DFB18  arm  ov175
 *   scSubmitReport  0x021DFBB8  arm  ov175
 *   scCreateReport  0x021DFC8C  arm  ov175
 *   scReportBeginGlobalData  0x021DFCE8  arm  ov175
 *   scReportBeginPlayerData  0x021DFCF4  arm  ov175
 *   scReportBeginTeamData  0x021DFD00  arm  ov175
 *   scReportBeginNewPlayer  0x021DFD0C  arm  ov175
 *   scReportEnd  0x021DFD18  arm  ov175
 *   scReportSetPlayerData  0x021DFD24  arm  ov175
 *   scReportAddIntValue  0x021DFDFC  arm  ov175
 *   scReportAddByteValue  0x021DFE08  arm  ov175
 *   scDestroyReport  0x021DFE14  arm  ov175
 *   scCleanupServiceUrl  0x021DFE20  arm  ov175
 *   sciCreateReport  0x021DFE2C  arm  ov175
 *   sciDestroyReport  0x021DFF30  arm  ov175
 *   sciReportSetPlayerConnectionId  0x021DFF78  arm  ov175
 *   sciReportSetPlayerTeamIndex  0x021DFFA0  arm  ov175
 *   sciReportSetPlayerGameResult  0x021DFFC8  arm  ov175
 *   sciReportReturnZero  0x021DFFF8  arm  ov175
 *   sciReportBeginNewPlayer  0x021E0000  arm  ov175
 *   sciReportBeginGlobalData  0x021E0040  arm  ov175
 *   sciReportBeginPlayerData  0x021E0070  arm  ov175
 *   sciReportBeginTeamData  0x021E0080  arm  ov175
 *   sciReportReturnZeroWithArg  0x021E0090  arm  ov175
 *   sciReportEnd  0x021E0098  arm  ov175
 *   sciReportAddIntValue  0x021E02F0  arm  ov175
 *   sciReportAddByteValue  0x021E03F8  arm  ov175
 *   sciSerializeInt8  0x021E04FC  arm  ov175
 *   sciSerializeInt16  0x021E0504  arm  ov175
 *   sciSerializeInt32  0x021E054C  arm  ov175
 *   sciSerializeGUID  0x021E05AC  arm  ov175
 *   sciWsInit  0x021E06DC  arm  ov175
 *   sciWsDestroy  0x021E0730  arm  ov175
 *   sciWsThink  0x021E0764  arm  ov175
 *   sciWsCreateSession  0x021E0774  arm  ov175
 *   sciWsSetReportIntention  0x021E0A7C  arm  ov175
 *   sciWsSubmitReport  0x021E0DB8  arm  ov175
 *   scGetConnectionId  0x021DFAA0  arm  ov175
 */
#ifndef SC_TYPES_H
#define SC_TYPES_H

#include "../ov175/auth_types.h"

/* Result codes of the stats library (SCResult). */
typedef enum SCResult {
    SCResult_NO_ERROR = 0,
    SCResult_NO_AVAILABILITY_CHECK = 1,
    SCResult_INVALID_PARAMETERS = 2,
    SCResult_NOT_INITIALIZED = 3,
    SCResult_CORE_NOT_INITIALIZED = 4,
    SCResult_OUT_OF_MEMORY = 5,
    SCResult_CALLBACK_PENDING = 6,
    SCResult_HTTP_ERROR = 7,
    SCResult_UNKNOWN_RESPONSE = 8,
    SCResult_RESPONSE_INVALID = 9,
    SCResult_REPORT_INVALID = 12
} SCResult;

/* Section that the report writer is filling (SCIReport.mReportState). */
typedef enum SCIReportState {
    SCIReportState_NONE = 0,
    SCIReportState_INIT = 1,
    SCIReportState_GLOBAL_DATA = 2,
    SCIReportState_PLAYER_DATA = 3,
    SCIReportState_TEAM_DATA = 4
} SCIReportState;

/* Value type tag stored with each key of a report. */
typedef enum SCIValueType {
    SCIValueType_INT = 0,
    SCIValueType_BYTE = 2
} SCIValueType;

#define SC_MAX_NUM_TEAMS 64
#define SCI_REPORT_HEADER_SIZE 0x44
#define SCI_REPORT_BUFFER_SIZE 0x10000
#define SC_GUID_SIZE 40

/* Header at the start of the report buffer (0x44 bytes, big endian when sent). */
typedef struct SCIReportHeader {
    unsigned int mProtocolVersion;
    unsigned int mDeveloperVersion;
    unsigned char mChecksum[16];
    unsigned int mGameStatus;
    unsigned int mFlags;
    unsigned short mPlayerCount;
    unsigned short mTeamCount;
    unsigned short mGameKeyCount;
    unsigned short mPlayerKeyCount;
    unsigned short mTeamKeyCount;
    unsigned short mReserved;
    unsigned int mRosterSectionLength;
    unsigned int mAuthSectionLength;
    unsigned int mResultsSectionLength;
    unsigned int mGameSectionLength;
    unsigned int mPlayerSectionLength;
    unsigned int mTeamSectionLength;
} SCIReportHeader;

/* The serialised report: header followed by the sections. */
typedef struct SCIReportBuffer {
    int mStart;
    int mReserved;
    int mCapacity;
    unsigned int mLength;
    unsigned char *mData;
} SCIReportBuffer;

/* A match report being built (0x128 bytes). */
typedef struct SCIReport {
    int mReportState;
    int mCurEntityStartPos;
    unsigned short mCurEntityKeyCount;
    unsigned int mNumResultsReported;
    unsigned int mNumTeamsReported;
    unsigned int mTeamIds[SC_MAX_NUM_TEAMS];
    SCIReportBuffer mBuffer;
} SCIReport;

struct SCInterface;

typedef void (*SCWebCallback)(struct SCInterface *theInterface, int theHttpResult, int theResult,
                              void *theUserData);

/* Pending SOAP calls of the stats client and their callbacks (0x4C bytes). */
typedef struct SCWebServices {
    struct SCInterface *mInterface;
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

/* Stats client state (0xAC bytes), allocated by scInitialize. */
typedef struct SCInterface {
    SCWebServices mWebServices;
    unsigned int mGameId;
    int mInit;
    char mReserved[8];
    unsigned char mSessionId[SC_GUID_SIZE];
    unsigned char mConnectionId[SC_GUID_SIZE];
} SCInterface;

/* Callback of the DWC wrapper: result code and the caller's data. */
typedef void (*DWCScCallback)(int theResult, void *theUserData);

/* sciserialize.c */
char *sciSerializeInt8(char *dst, int value);
unsigned char *sciSerializeInt16(unsigned char *dst, unsigned int value);
unsigned char *sciSerializeInt32(unsigned char *dst, unsigned int value);
unsigned char *sciSerializeGUID(unsigned char *theCursor, unsigned char *theGUID);

/* scireport.c */
int sciCreateReport(unsigned char *theSessionId, unsigned int theHeaderVersion, unsigned int thePlayerCount,
                  unsigned int theTeamCount, SCIReport **theReportOut);
int sciDestroyReport(SCIReport *theReport);
int sciReportSetPlayerConnectionId(SCIReport *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId);
int sciReportSetPlayerTeamIndex(SCIReport *theReport, unsigned int thePlayerIndex, unsigned int thePlayerTeamIndex);
int sciReportSetPlayerGameResult(SCIReport *theReport, int thePlayerIndex, int thePlayerResult);
int sciReportReturnZero(SCIReport *theReport, unsigned int thePlayerIndex, void *theCertificate,
                  unsigned char *theAuthHash);
int sciReportBeginNewPlayer(SCIReport *theReport);
int sciReportBeginGlobalData(SCIReport *theReport);
int sciReportBeginPlayerData(SCIReport *theReport);
int sciReportBeginTeamData(SCIReport *theReport);
int sciReportReturnZeroWithArg(SCIReport *theReport);
int sciReportEnd(SCIReport *theReport, int isAuthoritative, unsigned int theGameStatus);
int sciReportAddIntValue(SCIReport *theReport, int theKey, int theValue);
int sciReportAddByteValue(SCIReport *theReport, int theKey, int theValue);

/* sciinterface.c */
int sciInterfaceCreate(SCInterface **theInterfaceOut);
int sciInterfaceInit(SCInterface *theInterface);
void sciInterfaceDestroy(SCInterface *theInterface);
void sciInterfaceSetSessionId(SCInterface *theInterface, const char *theSessionId);
void sciInterfaceSetConnectionId(SCInterface *theInterface, const char *theConnectionId);
char *sciGetServiceUrl(void);

/* sciwebservices.c */
int sciWsInit(SCWebServices *theWebServices, SCInterface *theInterface);
void sciWsDestroy(SCWebServices *theWebServices);
void sciWsThink(SCWebServices *theWebServices);
int sciWsCreateSession(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int theTimeoutMs,
                  void *theUserData);
int sciWsSetReportIntention(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback,
                  unsigned int theTimeoutMs, void *theUserData);
int sciWsSubmitReport(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, SCIReport *theReport, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);

/* scimain.c */
int scInitialize(unsigned int theGameId, SCInterface **theInterfaceOut);
int scShutdown(SCInterface *theInterface);
int scThink(SCInterface *theInterface);
unsigned char *scGetSessionId(SCInterface *theInterface);
unsigned char *scGetConnectionId(SCInterface *theInterface);
int scSetSessionId(SCInterface *theInterface, const char *theSessionId);
int scCreateSession(SCInterface *theInterface, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int theTimeoutMs,
                  void *theUserData);
int scSetReportIntention(SCInterface *theInterface, const char *theConnectionId, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
int scSubmitReport(SCInterface *theInterface, SCIReport *theReport, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
int scCreateReport(SCInterface *theInterface, unsigned int theHeaderVersion, unsigned int thePlayerCount,
                  unsigned int theTeamCount, SCIReport **theReportOut);
int scReportBeginGlobalData(SCIReport *theReport);
int scReportBeginPlayerData(SCIReport *theReport);
int scReportBeginTeamData(SCIReport *theReport);
int scReportBeginNewPlayer(SCIReport *theReport);
int scReportEnd(SCIReport *theReport, int isAuthoritative, unsigned int theGameStatus);
int scReportSetPlayerData(SCIReport *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId,
                  unsigned int thePlayerTeamIndex, int thePlayerResult, int theUnused,
                  GSLoginCertificate *theCertificate, unsigned char *theAuthHash);
int scReportAddIntValue(SCIReport *theReport, int theKey, int theValue);
int scReportAddByteValue(SCIReport *theReport, int theKey, int theValue);
int scDestroyReport(SCIReport *theReport);
char *scCleanupServiceUrl(void);

#endif
