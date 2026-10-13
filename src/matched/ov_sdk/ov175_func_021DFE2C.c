/*
 * function: sciCreateReport
 * address:  0x021DFE2C
 * packet:   pkt_ov175_021DFE2C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciCreateReport (libdwcgssc.TWL.HYB.a scireport.o)
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   memset  0x020923B0  arm
 */

extern void *func_0217EAB0(unsigned long size);
extern void func_0217EAE0(void *p);
extern void *memset(void *p, int c, unsigned long n);

typedef struct {
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

typedef struct {
    int mPos;
    int mCapacity0;
    int mCapacity;
    int mLen;
    unsigned char *mData;
} SCIReportBuffer;

typedef struct {
    int mReportState;
    int mCurEntityStartPos;
    unsigned short mCurEntityKeyCount;
    unsigned int mNumResultsReported;
    unsigned int mNumTeamsReported;
    unsigned int mTeamIds[64];
    SCIReportBuffer mBuffer;
} SCIReport;

#define HTONL(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

int sciCreateReport(int unused, unsigned int theHeaderVersion, unsigned int thePlayerCount, unsigned int theTeamCount, SCIReport **theReportOut)
{
    SCIReport *theNewReport;
    SCIReportHeader *theReportHeader;
    unsigned char *theReportData;
    unsigned int theRosterSize;

    theRosterSize = (thePlayerCount << 4) + (thePlayerCount << 2);
    theNewReport = (SCIReport *)func_0217EAB0(sizeof(SCIReport));
    if (!theNewReport)
        return 5;
    memset(theNewReport, 0, sizeof(SCIReport));
    theReportData = (unsigned char *)func_0217EAB0(0x10000);
    if (!theReportData) {
        func_0217EAE0(theNewReport);
        return 5;
    }
    memset(theReportData, 0, 0x10000);
    theNewReport->mBuffer.mPos = 0;
    theNewReport->mBuffer.mCapacity = 0x10000;
    theReportHeader = (SCIReportHeader *)theReportData;
    memset(theReportHeader, 0, sizeof(SCIReportHeader));
    theReportHeader->mProtocolVersion = HTONL(2u);
    theReportHeader->mDeveloperVersion = HTONL(theHeaderVersion);
    theReportHeader->mRosterSectionLength = theRosterSize;
    theReportHeader->mAuthSectionLength = thePlayerCount << 4;
    theReportHeader->mResultsSectionLength = (thePlayerCount + theTeamCount) << 2;
    theReportHeader->mPlayerCount = thePlayerCount;
    theReportHeader->mTeamCount = theTeamCount;
    theNewReport->mReportState = 1;
    theNewReport->mBuffer.mData = theReportData;
    theNewReport->mCurEntityStartPos = -1;
    theNewReport->mNumTeamsReported = 0;
    *theReportOut = theNewReport;
    return 0;
}
