/*
 * function: BR_CODEIN_ProfileDeleteActor
 * address: 0x021E08E4
 * packet: pkt_ov183_021E08E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0952 alignment padding.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BR_CODEIN_ProfileDeleteOam 0x021E10BC thumb ov183
 */
#include "../include/Obj08317.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void BR_CODEIN_ProfileDeleteOam(char *);
void BR_CODEIN_ProfileDeleteActor(char *p)
{
    int i;
    for (i = 0; i < ((struct Obj08317 *)p)->f23C; i++) CLACT_DeleteActor(*(void **)(p + i * 28 + 12));
    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor(*(void **)(p + i * 28 + 0x15c));
        CLACT_DeleteActor(*(void **)(p + i * 28 + 0x1e8));
    }
    for (i = 0; i < 3; i++) CLACT_DeleteActor(*(void **)(p + i * 28 + 0x194));
    BR_CODEIN_ProfileDeleteOam(p);
}
