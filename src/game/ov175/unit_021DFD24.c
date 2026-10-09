/*
 * file:     unit_021DFD24.c
 * function: func_021DFD24
 * address:  0x021DFD24
 * packet:   pkt_ov175_021DFD24
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 * THE NEW-TEAM ARM IS NINE INSTRUCTIONS AND BOTH OF ITS TWO NON-TRIVIAL
 * INSTRUCTIONS ARE EARNED, NOT SPENT.  The earlier lane's record held the arm
 * full: +0x50 is a fresh `ldr r1,[r6,#0x10]` where a spelled-out
 * `n = aReport->mNumTeamsReported + 1` gives the loop's cached copy in lr, and
 * +0x74 keeps a `cmp r0,#0` that is dead because aResult was zeroed at +0x0C
 * and never written again (4.0.0.1025 emitted it, 1.1p1 folds it).  Both are
 * reproduced here at zero cost, and neither needs the other:
 *
 *   - the reload is the compound-assignment read.  `n = ++aReport->mNumTeams
 *     Reported;` is `+= 1` on the field, which mwccarm treats as a read of the
 *     lvalue in its own right and does not let common subexpression
 *     elimination supply from the loop's `ldr lr,[r6,#0x10]`, while the
 *     spelled-out `n = aReport->mNumTeamsReported + 1; aReport->mNumTeams
 *     Reported = n;` folds into lr.  The store still sinks below the
 *     `cmp r1,#0x40` (it is an ordinary store, only the load is pinned), which
 *     is what puts +0x5C after +0x58 as the object has it.  Measured: the
 *     spelled-out form is 212 bytes with `add r1, lr, #1` at +0x50, 111
 *     concrete out.  See
 *     docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md.
 *   - the dead compare is kept by the TYPE of the accumulator, not by a store.
 *     aResult is a `TResult`; under `-enum int` mwccarm does not propagate an
 *     enum-typed value, so `cmp r0,#0 / bne` survives with no `mov r0,#0`
 *     anywhere in the arm.  It is the type and not the guard constant: with
 *     `TResult` and a bare `== 0` this is still EXACT, and with `int` compared
 *     against the enumerator `RESULT_OK` it is not.  An `int` aResult folds the
 *     whole four-guard chain (the value is constant-propagated through the
 *     calls' results too) and the function collapses to 204 bytes, 174
 *     concrete out.  See
 *     docs/idioms/an-enum-guard-keeps-a-dead-compare-an-int-guard-folds-it.md.
 *
 * So the re-zero that cost the reload is not needed at all, and the
 * "9 instructions with no mov r0,#0, so both cannot fit" reading of the arm
 * does not hold: the arm holds the reload because nothing had to be re-zeroed,
 * and the compare survives on the accumulator's type.  The earlier record's
 * "enum-typed aResult is codegen-neutral" was measured against a build that
 * already had the re-zero in the arm, where the compare is unfolded either way
 * and the enum therefore cannot show.  Typing aResult as an enum is what the
 * vendor DWARF says it is anyway (`enum @enum aResult`).
 *
 * Signature note: the DWARF prototype names only 7 parameters, but the object
 * loads theResult from sp+0x10, theCertificate from sp+0x18 and theAuthHash from
 * sp+0x1c, never touching sp+0x14.  That skipped word is a real 6th stack
 * argument the function never reads, so the `unused` int in the signature below
 * is load-bearing, not a leftover: delete it and both pointer loads slide down a
 * word, breaking all three call sites.
 *
 * The third argument of the first setter needs no register set-up: the
 * connection id arrives in r2 and nothing between the prologue and the call at
 * +0x84 writes r2, so the object has no `mov r2` there and neither does this.
 */

struct SCIReport {
    int mReportState;
    int mCurEntityStartPos;
    unsigned short mCurEntityKeyCount;
    unsigned int mNumResultsReported;
    unsigned int mNumTeamsReported;
    unsigned int mTeamIds[64];
};

typedef enum {
    RESULT_OK = 0,
    RESULT_BAD = 1
} TResult;

extern int func_021DFF78(struct SCIReport *report, unsigned int index, unsigned char *connectionId);
extern int func_021DFFA0(struct SCIReport *report, unsigned int index, unsigned int teamIndex);
extern int func_021DFFC8(char *obj, int i, int v);
extern void func_021DFFF8();

int func_021DFD24(void *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId,
                  unsigned int thePlayerTeamId, int theResult, int unused, void *theCertificate,
                  unsigned char *theAuthHash)
{
    struct SCIReport *aReport;
    TResult aResult;
    unsigned int i;
    int isNewTeam;
    unsigned int n;

    aReport = theReport;
    aResult = RESULT_OK;
    isNewTeam = 1;
    for (i = 0; i < aReport->mNumTeamsReported; i++) {
        if (thePlayerTeamId == aReport->mTeamIds[i]) {
            isNewTeam = 0;
            break;
        }
    }
    if (isNewTeam) {
        n = ++aReport->mNumTeamsReported;
        if (n > 64)
            return 5;
        aReport->mTeamIds[n - 1] = thePlayerTeamId;
    }
    if (aResult == RESULT_OK)
        aResult = func_021DFF78(aReport, thePlayerIndex, thePlayerConnectionId);
    if (aResult == RESULT_OK)
        aResult = func_021DFFA0(aReport, thePlayerIndex, thePlayerTeamId);
    if (aResult == RESULT_OK)
        aResult = func_021DFFC8((char *)aReport, thePlayerIndex, theResult);
    if (aResult != RESULT_OK)
        return aResult;
    func_021DFFF8(aReport, thePlayerIndex, theCertificate, theAuthHash);
}
