/*
 * file:     scireport.c
 * unit:     yes
 * function: sciCreateReport, sciDestroyReport, sciReportSetPlayerConnectionId, sciReportSetPlayerTeamIndex, sciReportSetPlayerGameResult, sciReportReturnZero, sciReportBeginNewPlayer, sciReportBeginGlobalData, sciReportBeginPlayerData, sciReportBeginTeamData, sciReportReturnZeroWithArg, sciReportEnd, sciReportAddIntValue, sciReportAddByteValue
 * address:  0x021DFE2C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Stats and Control client (libdwcgssc, object scireport.o): builds the
 * match report. sciCreateReport allocates the 64 KB buffer and fills the header;
 * the Begin and Add functions append the roster, results and key/value sections;
 * sciReportEnd converts the header to network byte order.
 *
 * symbols:
 *   sciSerializeInt8  0x021E04FC  arm  ov175
 *   sciSerializeInt16  0x021E0504  arm  ov175
 *   sciSerializeInt32  0x021E054C  arm  ov175
 *   sciSerializeGUID  0x021E05AC  arm  ov175
 *   gsifree  0x0217EAE0  arm ov009
 *   gsimalloc  0x0217EAB0  arm ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "sc_types.h"
#include "../arm9/msl_string_mem.h"

#define SCI_ROSTER_ROW_SIZE 20 /* connection id (16 bytes) and team index */
#define SCI_ROSTER_TEAM_OFFSET 16

#define HTONL(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
#define BS32(x) ((unsigned int)((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                                (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000)))
#define BS16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))

#include "../ov009/gsmemory.h"

/*
 * sciCreateReport: allocates the report and its buffer and writes the start of
 * the header.  The roster holds one 20 byte row per player, the auth section
 * 16 bytes per player and the results section one word per player and team.
 */
int sciCreateReport(unsigned char *theSessionId, unsigned int theHeaderVersion, unsigned int thePlayerCount,
                  unsigned int theTeamCount, SCIReport **theReportOut)
{
    SCIReport *theNewReport;
    SCIReportHeader *theReportHeader;
    unsigned char *theReportData;
    unsigned int theRosterSize;

    theRosterSize = (thePlayerCount << 4) + (thePlayerCount << 2);
    theNewReport = (SCIReport *)gsimalloc(sizeof(SCIReport));
    if (!theNewReport)
        return SCResult_OUT_OF_MEMORY;
    MSL_C_LIB_MemsetPtr(theNewReport, 0, sizeof(SCIReport));
    theReportData = (unsigned char *)gsimalloc(SCI_REPORT_BUFFER_SIZE);
    if (!theReportData) {
        gsifree(theNewReport);
        return SCResult_OUT_OF_MEMORY;
    }
    MSL_C_LIB_MemsetPtr(theReportData, 0, SCI_REPORT_BUFFER_SIZE);
    theNewReport->mBuffer.mStart = 0;
    theNewReport->mBuffer.mCapacity = SCI_REPORT_BUFFER_SIZE;
    theReportHeader = (SCIReportHeader *)theReportData;
    MSL_C_LIB_MemsetPtr(theReportHeader, 0, sizeof(SCIReportHeader));
    theReportHeader->mProtocolVersion = HTONL(2u);
    theReportHeader->mDeveloperVersion = HTONL(theHeaderVersion);
    theReportHeader->mRosterSectionLength = theRosterSize;
    theReportHeader->mAuthSectionLength = thePlayerCount << 4;
    theReportHeader->mResultsSectionLength = (thePlayerCount + theTeamCount) << 2;
    theReportHeader->mPlayerCount = thePlayerCount;
    theReportHeader->mTeamCount = theTeamCount;
    theNewReport->mReportState = SCIReportState_INIT;
    theNewReport->mBuffer.mData = theReportData;
    theNewReport->mCurEntityStartPos = -1;
    theNewReport->mNumTeamsReported = 0;
    *theReportOut = theNewReport;
    return SCResult_NO_ERROR;
}

/* sciDestroyReport: clears the report, frees the buffer and the report. */
int sciDestroyReport(SCIReport *theReport)
{
    unsigned char *theData = theReport->mBuffer.mData;

    theReport->mReportState = SCIReportState_NONE;
    theReport->mCurEntityKeyCount = 0;
    theReport->mCurEntityStartPos = 0;
    theReport->mNumTeamsReported = 0;
    theReport->mNumResultsReported = 0;
    gsifree(theData);
    theReport->mBuffer.mData = 0;
    theReport->mBuffer.mCapacity = 0;
    theReport->mBuffer.mReserved = 0;
    theReport->mBuffer.mLength = 0;
    gsifree(theReport);
    return SCResult_NO_ERROR;
}

/* sciReportSetPlayerConnectionId: serialises the connection GUID into the player's roster row. */
int sciReportSetPlayerConnectionId(SCIReport *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId)
{
    unsigned int theOffset;

    theOffset = SCI_REPORT_HEADER_SIZE;
    theOffset += thePlayerIndex * SCI_ROSTER_ROW_SIZE;
    sciSerializeGUID(theReport->mBuffer.mData + theOffset, thePlayerConnectionId);
    return SCResult_NO_ERROR;
}

/*
 * sciReportSetPlayerTeamIndex: writes the team index after the connection id
 * of the player's roster row.  The offset is built in steps (header size, the
 * row, the 16 byte connection id); the one-expression form swaps two registers.
 */
int sciReportSetPlayerTeamIndex(SCIReport *theReport, unsigned int thePlayerIndex, unsigned int thePlayerTeamIndex)
{
    unsigned int theOffset;

    theOffset = SCI_REPORT_HEADER_SIZE;
    theOffset += thePlayerIndex * SCI_ROSTER_ROW_SIZE;
    theOffset += SCI_ROSTER_TEAM_OFFSET;
    sciSerializeInt32(theReport->mBuffer.mData + theOffset, thePlayerTeamIndex);
    return SCResult_NO_ERROR;
}

/* sciReportSetPlayerGameResult: writes the player's result word in the results section. */
int sciReportSetPlayerGameResult(SCIReport *theReport, int thePlayerIndex, int thePlayerResult)
{
    SCIReportHeader *theHeader = (SCIReportHeader *)theReport->mBuffer.mData;
    int theOffset = theHeader->mRosterSectionLength + SCI_REPORT_HEADER_SIZE + theHeader->mAuthSectionLength
                  + thePlayerIndex * 4;

    sciSerializeInt32((unsigned char *)theHeader + theOffset, thePlayerResult);
    return SCResult_NO_ERROR;
}

/*
 * sciReportReturnZero (name guessed): called by scReportSetPlayerData after the
 * roster entries with the certificate and the auth hash; the shipped code does
 * nothing with them.
 */
int sciReportReturnZero(SCIReport *theReport, unsigned int thePlayerIndex, void *theCertificate,
                  unsigned char *theAuthHash)
{
    return SCResult_NO_ERROR;
}

/*
 * sciReportBeginNewPlayer: starts a player or team entry at the end of the
 * buffer with a two byte key count (zero for now).
 */
int sciReportBeginNewPlayer(SCIReport *theReport)
{
    unsigned int theStartPos = theReport->mBuffer.mLength;
    unsigned char *theBuffer = theReport->mBuffer.mData;

    theReport->mCurEntityKeyCount = 0;
    theReport->mCurEntityStartPos = theStartPos;
    theReport->mBuffer.mLength = theStartPos + 2;
    sciSerializeInt16(theBuffer + theStartPos, 0);
    ((SCIReportHeader *)theBuffer)->mPlayerSectionLength += 2;
    return SCResult_NO_ERROR;
}

/*
 * sciReportBeginGlobalData: switches to the game section, which starts after
 * the header, the roster, the auth and the results sections.
 */
int sciReportBeginGlobalData(SCIReport *theReport)
{
    SCIReportHeader *theHeader = (SCIReportHeader *)theReport->mBuffer.mData;

    theReport->mReportState = SCIReportState_GLOBAL_DATA;
    theReport->mBuffer.mLength = theHeader->mRosterSectionLength + SCI_REPORT_HEADER_SIZE
                               + theHeader->mAuthSectionLength + theHeader->mResultsSectionLength;
    return SCResult_NO_ERROR;
}

/* sciReportBeginPlayerData: switches to the player section. */
int sciReportBeginPlayerData(SCIReport *theReport)
{
    theReport->mReportState = SCIReportState_PLAYER_DATA;
    return SCResult_NO_ERROR;
}

/* sciReportBeginTeamData: switches to the team section. */
int sciReportBeginTeamData(SCIReport *theReport)
{
    theReport->mReportState = SCIReportState_TEAM_DATA;
    return SCResult_NO_ERROR;
}

/* sciReportReturnZeroWithArg (name guessed): empty hook called by sciReportEnd. */
int sciReportReturnZeroWithArg(SCIReport *theReport) { return SCResult_NO_ERROR; }

/* sciReportEnd: sets the status and flags and converts every header field to network byte order. */
int sciReportEnd(SCIReport *theReport, int isAuthoritative, unsigned int theGameStatus)
{
    SCIReportHeader *theHeader = (SCIReportHeader *)theReport->mBuffer.mData;

    sciReportReturnZeroWithArg(theReport);
    if (isAuthoritative != 0)
        theHeader->mFlags |= 1;
    theHeader->mGameStatus = BS32(theGameStatus);
    theHeader->mFlags = BS32(theHeader->mFlags);
    theHeader->mPlayerCount = BS16(theHeader->mPlayerCount);
    theHeader->mTeamCount = BS16(theHeader->mTeamCount);
    theHeader->mReserved = 0;
    theHeader->mGameKeyCount = BS16(theHeader->mGameKeyCount);
    theHeader->mPlayerKeyCount = BS16(theHeader->mPlayerKeyCount);
    theHeader->mTeamKeyCount = BS16(theHeader->mTeamKeyCount);
    theHeader->mRosterSectionLength = BS32(theHeader->mRosterSectionLength);
    theHeader->mAuthSectionLength = BS32(theHeader->mAuthSectionLength);
    theHeader->mResultsSectionLength = BS32(theHeader->mResultsSectionLength);
    theHeader->mGameSectionLength = BS32(theHeader->mGameSectionLength);
    theHeader->mPlayerSectionLength = BS32(theHeader->mPlayerSectionLength);
    theHeader->mTeamSectionLength = BS32(theHeader->mTeamSectionLength);
    return SCResult_NO_ERROR;
}

/*
 * sciReportAddIntValue: appends a key, the type tag and a 32 bit value to the
 * current section and updates the key counts and section lengths in the header.
 */
int sciReportAddIntValue(SCIReport *theReport, int theKey, int theValue)
{
    int theState = theReport->mReportState;
    SCIReportHeader *theHeader = (SCIReportHeader *)theReport->mBuffer.mData;

    if (theState == SCIReportState_GLOBAL_DATA) {
        theHeader->mGameKeyCount++;
        theHeader->mGameSectionLength += 8;
    } else if (theState == SCIReportState_PLAYER_DATA) {
        theHeader->mPlayerKeyCount++;
        theHeader->mPlayerSectionLength += 8;
        theReport->mCurEntityKeyCount++;
        sciSerializeInt16(theReport->mBuffer.mData + theReport->mCurEntityStartPos,
                      (short)theReport->mCurEntityKeyCount);
    } else if (theState == SCIReportState_TEAM_DATA) {
        theHeader->mTeamKeyCount++;
        theHeader->mTeamSectionLength += 8;
        theReport->mCurEntityKeyCount++;
        sciSerializeInt16(theReport->mBuffer.mData + theReport->mCurEntityStartPos,
                      (short)theReport->mCurEntityKeyCount);
    }
    sciSerializeInt16(theReport->mBuffer.mData + theReport->mBuffer.mLength, (short)theKey);
    theReport->mBuffer.mLength += 2;
    sciSerializeInt16(theReport->mBuffer.mData + theReport->mBuffer.mLength, (short)SCIValueType_INT);
    theReport->mBuffer.mLength += 2;
    sciSerializeInt32(theReport->mBuffer.mData + theReport->mBuffer.mLength, (int)theValue);
    theReport->mBuffer.mLength += 4;
    return SCResult_NO_ERROR;
}

/* sciReportAddByteValue: as sciReportAddIntValue for a one byte value (5 bytes per key). */
int sciReportAddByteValue(SCIReport *theReport, int theKey, int theValue)
{
    SCIReportHeader *theHeader = (SCIReportHeader *)theReport->mBuffer.mData;
    int theState = theReport->mReportState;

    if (theState == SCIReportState_GLOBAL_DATA) {
        theHeader->mGameKeyCount += 1;
        theHeader->mGameSectionLength += 5;
    } else if (theState == SCIReportState_PLAYER_DATA) {
        theHeader->mPlayerKeyCount += 1;
        theHeader->mPlayerSectionLength += 5;
        theReport->mCurEntityKeyCount += 1;
        sciSerializeInt16(theReport->mBuffer.mData + theReport->mCurEntityStartPos,
                      (short)theReport->mCurEntityKeyCount);
    } else if (theState == SCIReportState_TEAM_DATA) {
        theHeader->mTeamKeyCount += 1;
        theHeader->mTeamSectionLength += 5;
        theReport->mCurEntityKeyCount += 1;
        sciSerializeInt16(theReport->mBuffer.mData + theReport->mCurEntityStartPos,
                      (short)theReport->mCurEntityKeyCount);
    }
    sciSerializeInt16(theReport->mBuffer.mData + theReport->mBuffer.mLength, (short)theKey);
    theReport->mBuffer.mLength += 2;
    sciSerializeInt16(theReport->mBuffer.mData + theReport->mBuffer.mLength, SCIValueType_BYTE);
    theReport->mBuffer.mLength += 2;
    sciSerializeInt8((char *)theReport->mBuffer.mData + theReport->mBuffer.mLength, theValue);
    theReport->mBuffer.mLength += 1;
    return SCResult_NO_ERROR;
}
