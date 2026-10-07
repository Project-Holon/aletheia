/*
 * file:     unit_021DFE2C.c
 * unit:     yes
 * function: func_021DFE2C, func_021DFF30, func_021DFF78, func_021DFFA0, func_021DFFC8
 * address:  0x021DFE2C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   memset  0x020923B0  arm
 *   func_021E05AC  0x021E05AC  arm  ov175
 *   func_021E054C  0x021E054C  arm  ov175
 */
#define HTONL(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
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

typedef unsigned short u16;

typedef unsigned int u32;

struct SCIReport {
    char pad[0x124];
    unsigned char *buffer;
};

typedef unsigned char  u8;

extern void *func_0217EAB0(unsigned long size);
extern void func_0217EAE0(void *p);
extern void *memset(void *p, int c, unsigned long n);
extern unsigned char *func_021E05AC(unsigned char *cursor, unsigned char *guid);
extern u8 *func_021E054C(u8 *dst, u32 v);
int func_021DFE2C(int unused, unsigned int theHeaderVersion, unsigned int thePlayerCount, unsigned int theTeamCount, SCIReport **theReportOut);
int func_021DFF30(u32 *p);
int func_021DFF78(struct SCIReport *report, unsigned int index, unsigned char *connectionId);
int func_021DFFA0(struct SCIReport *report, unsigned int index, unsigned int team);
int func_021DFFC8(char *obj, int i, int v);


/*
 * sdk:      sciCreateReport (libdwcgssc.TWL.HYB.a scireport.o)
 */
int func_021DFE2C(int unused, unsigned int theHeaderVersion, unsigned int thePlayerCount, unsigned int theTeamCount, SCIReport **theReportOut)
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


int func_021DFF30(u32 *p)
{
    u32 *q = (u32 *)p[0x124 / 4];

    p[0] = 0;
    *(u16 *)(p + 2) = 0;
    p[1] = 0;
    p[4] = 0;
    p[3] = 0;
    func_0217EAE0(q);
    p[0x124 / 4] = 0;
    p[0x11c / 4] = 0;
    p[0x118 / 4] = 0;
    p[0x120 / 4] = 0;
    func_0217EAE0(p);
    return 0;
}


int func_021DFF78(struct SCIReport *report, unsigned int index, unsigned char *connectionId)
{
    unsigned int off;

    off = 0x44;
    off += index * 20;
    func_021E05AC(report->buffer + off, connectionId);
    return 0;
}


/*
 * sdk:      sciReportSetPlayerTeamIndex (libdwcgssc.TWL.HYB.a(scireport.o))
 *
 * notes:    the offset is built in steps (header size, the roster row, the
 *           16-byte connection id); the one-expression form swaps ip and r3.
 */
int func_021DFFA0(struct SCIReport *report, unsigned int index, unsigned int team)
{
    unsigned int off;

    off = 0x44;
    off += index * 20;
    off += 16;
    func_021E054C(report->buffer + off, team);
    return 0;
}


int func_021DFFC8(char *obj, int i, int v)
{
    char *ip = *(char **)(obj + 0x124);
    int off = *(int *)(ip + 0x2c) + 0x44 + *(int *)(ip + 0x30) + i * 4;

    func_021E054C((u8 *)(ip + off), v);
    return 0;
}
