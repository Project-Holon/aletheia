/*
 * function: func_021DFD24
 * address:  0x021DFD24
 * packet:   pkt_ov175_021DFD24
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      scReportSetPlayerData (libdwcgssc.TWL.HYB.a(scimain.o))
 *
 * NEAR MISS (204 vs 216 B): the object keeps aResult (r0 = 0) live across the loop and tests it before the first call (cmp r0,#0); the compiler here folds that test away.
 *
 * symbols:
 *   func_021DFF78  0x021DFF78  arm  ov175
 *   func_021DFFA0  0x021DFFA0  arm  ov175
 *   func_021DFFC8  0x021DFFC8  arm  ov175
 *   func_021DFFF8  0x021DFFF8  arm  ov175
 */

struct SCIReport {
    int mReportState;
    int mCurEntityStartPos;
    unsigned short mCurEntityKeyCount;
    unsigned int mNumResultsReported;
    unsigned int mNumTeamsReported;
    unsigned int mTeamIds[64];
};

extern int func_021DFF78(struct SCIReport *report, unsigned int index, unsigned char *connectionId);
extern int func_021DFFA0(struct SCIReport *report, unsigned int index, unsigned int teamIndex);
extern int func_021DFFC8(struct SCIReport *report, unsigned int index, int gameResult);
extern void func_021DFFF8();

int func_021DFD24(void *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId,
                  unsigned int thePlayerTeamId, int theResult, int unused, void *theCertificate,
                  unsigned char *theAuthHash)
{
    struct SCIReport *aReport;
    int aResult;
    unsigned int i;
    int isNewTeam;

    aReport = theReport;
    aResult = 0;
    isNewTeam = 1;
    for (i = 0; i < aReport->mNumTeamsReported; i++) {
        if (thePlayerTeamId == aReport->mTeamIds[i]) {
            isNewTeam = 0;
            break;
        }
    }
    if (isNewTeam) {
        aReport->mNumTeamsReported++;
        if (aReport->mNumTeamsReported > 64)
            return 5;
        aReport->mTeamIds[aReport->mNumTeamsReported - 1] = thePlayerTeamId;
    }
    if (aResult == 0)
        aResult = func_021DFF78(aReport, thePlayerIndex, thePlayerConnectionId);
    if (aResult == 0)
        aResult = func_021DFFA0(aReport, thePlayerIndex, thePlayerTeamId);
    if (aResult == 0)
        aResult = func_021DFFC8(aReport, thePlayerIndex, theResult);
    if (aResult != 0)
        return aResult;
    func_021DFFF8(aReport, thePlayerIndex, theCertificate, theAuthHash);
}
