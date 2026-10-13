/*
 * function: PRINTSYS_PrintQueColor
 * address:  0x0201C724
 * packet:   pkt_0201C6FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _PrintJobWork     0x0214655C  data
 *   PRINTSYS_SetupJob   0x0201C808  thumb
 *   PRINTSYS_SetJobColor   0x0201C8A4  thumb
 *   PRINTSYS_SubmitJob   0x0201C758  thumb
 *
 * Seven-argument front door of the move-data layer (worklist guesses
 * waza_tool.c for this packet): fill the shared scratch object at
 * 0x0214655C from the caller's four middle arguments, stamp the u16 from
 * the last argument on it, then hand it plus the owner to PRINTSYS_SubmitJob.
 *
 * 0x0214655C is passed by address, not dereferenced, so it is the object
 * itself and not a pointer to one.  It is live across all three calls,
 * which is what buys it r7.
 *
 * The last argument is read as `add r1, sp, #0x18` then `ldrh r1, [r1, #8]`
 * rather than a single sp-relative load: Thumb `ldrh` cannot use sp as a
 * base at all, so reaching an incoming halfword argument always costs the
 * extra `add` (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  The
 * `push {r3, ...}` reserves the one outgoing stack word that PRINTSYS_SetupJob's
 * fifth argument needs; the `str r3, [sp]` that fills it is the original r3
 * being forwarded, not a spill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_PrintQueColor.c \
 *       --func PRINTSYS_PrintQueColor --addr 0x0201C724 --cc 1.1p1 --thumb
 */

#include "../include/G_Scratch.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Scratch _PrintJobWork;

extern void PRINTSYS_SetupJob(struct Scratch *s, u32 e, u32 a, u32 b, u32 c);
struct Rec2;
extern void PRINTSYS_SetJobColor(struct Rec2 *p, u16 v);
struct PrintCtx;
struct PrintSys;
extern void PRINTSYS_SubmitJob(struct PrintSys *p, struct PrintCtx *c, void *s);

void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    PRINTSYS_SetupJob(&_PrintJobWork, e, a, b, c);
    PRINTSYS_SetJobColor((struct Rec2 *)(&_PrintJobWork), f);
    PRINTSYS_SubmitJob(owner, (struct PrintCtx *)(&_PrintJobWork), (void *)d);
}
