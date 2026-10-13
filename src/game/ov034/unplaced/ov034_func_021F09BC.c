/*
 * function: REPORT_UpdateSaveAnim
 * address:  0x021F09BC
 * packet:   pkt_ov034_021F09BC
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  label (arm9 leaf). Every byte agrees; the one wildcard is the
 *   bl to SAVE_CONTROL_GetWrittenSize, an unlabelled arm9 Thumb tail-call stub
 *   (ldr r0,[r0,#0x10]; ldr r3,[pc]; bx r3; .word 0x02031E69) with no
 *   witness outside this range. It is the integrator's. Verified leaf C
 *   (match.py one --thumb, no --region: MATCH, byte-correct, its own
 *   pool word to BACKUP_SYSTEM_GetWrittenSize unwitnessed):
 *     extern u32 BACKUP_SYSTEM_GetWrittenSize(void *p);
 *     u32 SAVE_CONTROL_GetWrittenSize(char *p) { return BACKUP_SYSTEM_GetWrittenSize(*(void **)(p + 0x10)); }
 *
 * note 2026-10-05: the blocker leaf is now filed as src/matched/arm9/SAVE_CONTROL_GetWrittenSize.c
 * (EXACT, verified with match.py one; its pool word to BACKUP_SYSTEM_GetWrittenSize needs the arm symbols line). This
 * file stays MATCH until the integrator regenerates the manifest so the witness resolves;
 * then it is EXACT with no change to the C.
 *
 * symbols:
 *   REPORT_UpdateSaveAnim 0x021F09BC thumb
 *   SAVE_CONTROL_GetWrittenSize 0x020071C0 thumb
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 */

#include "../report_types.h"

struct Task;
struct ClactActor;

extern u32 SAVE_CONTROL_GetWrittenSize(void *saveControl);
extern void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 value);
extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value);
extern void func_0204B92C(struct ClactActor *actor, u32 v);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);

void REPORT_UpdateSaveAnim(struct Task *task, ReportWork *work)
{
    u32 writtenSize;

    if (work->saveAnimRunning != 0) {
        writtenSize = SAVE_CONTROL_GetWrittenSize(work->saveControl) << 8;
        if (work->pieceFrameDelay != 8)
            work->pieceFrameDelay++;
        if (writtenSize >= work->progressTarget && work->pieceFrameDelay == 8
            && work->barPiecesLit < REPORT_BAR_PIECE_COUNT) {
            work->progressTarget += work->progressStep;
            work->pieceFrameDelay = 0;
            CLACT_SetActorAnimFrame(work->actors[work->barPiecesLit + 6], 0);
            CLACT_SetActorAnimSeq(work->actors[work->barPiecesLit + 6], 1);
            func_0204B92C(work->actors[work->barPiecesLit + 6], 1);
            work->barPiecesLit++;
        }
        CLACT_DrawSystem();
        CLACT_VBlankSystem();
    }
}
