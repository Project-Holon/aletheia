/*
 * function: func_021DFD24
 * address:  0x021DFD24
 * packet:   pkt_ov175_021DFD24
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss, 216 B compiled against 216 B in the object; 7 concrete
 *                 bytes differ in two instructions, 4/4 relocations resolved)
 *
 * sdk:      scReportSetPlayerData (libdwcgssc.TWL.HYB.a(scimain.o))
 *
 * symbols:
 *   func_021DFF78  0x021DFF78  arm  ov175
 *   func_021DFFA0  0x021DFFA0  arm  ov175
 *   func_021DFFC8  0x021DFFC8  arm  ov175
 *   func_021DFFF8  0x021DFFF8  arm  ov175
 *
 * Static: walks the report's team-id array for thePlayerTeamId, and on a miss
 * appends it (bailing out with 5 past 64 entries).  It then runs the three
 * player-data setters -- connection id, team index, game result -- each guarded
 * on the previous one's result, and only calls the auth-info setter when all
 * three succeeded, returning the first non-zero result otherwise.
 *
 * The object is 216 bytes, all four PC24 sites resolve, and the code here is
 * byte-identical to it except for two instructions at +0x50.  DIFF not MATCH:
 *
 *   +0x50  the object reloads the count and bumps it in place
 *          (ldr r1,[r6,#0x10] ; add r1,r1,#1) while this build folds the loop's
 *          cached copy in lr into the increment (add r1,lr,#1).  The instruction
 *          the object spends there, this build spends at +0x54, materialising
 *          aResult a second time (mov r0,#0).
 *
 * Signature note: the DWARF prototype names only 7 parameters, but the object
 * loads theResult from sp+0x10, theCertificate from sp+0x18 and theAuthHash from
 * sp+0x1c, never touching sp+0x14.  That skipped word is a real 6th stack
 * argument the function never reads, so the `unused` int in the signature below
 * is load-bearing, not a leftover: delete it and both pointer loads slide down a
 * word, breaking all three call sites.
 *
 * Both are 9 instructions in the new-team arm, so the totals agree at 216 and
 * everything from +0x58 on is identical.  The coupling is what makes this hard:
 * the object only needs the +0x54 `mov r0,#0` because aResult is zeroed once at
 * +0x0C and never written again, so the compare at +0x74 is dead and 4.0.0.1025
 * still emitted it.  Every front end available here folds that dead test, so to
 * keep it the accumulator has to be re-zeroed in the arm -- which costs exactly
 * the 4 bytes the object spends on the reload, and hands the increment a spare
 * slot that it then fills from lr.  Re-zeroing aResult in the arm with the
 * increment written as `aReport->mNumTeamsReported++` gives 220 bytes (both the
 * reload and the second mov), and the count-local spellings that reload give
 * 212 (the accumulator folds out instead).  Spelling the scan `while`, seeding
 * i from aResult, and the pointer/inc/copy variants all land on the same 52 of
 * 54 words.  Recorded rather than guessed at: the residue is one allocator
 * choice, not a missing statement.
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
    unsigned int n;

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
        n = aReport->mNumTeamsReported + 1;
        aReport->mNumTeamsReported = n;
        aResult = 0;
        if (n > 64)
            return 5;
        aReport->mTeamIds[n - 1] = thePlayerTeamId;
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
