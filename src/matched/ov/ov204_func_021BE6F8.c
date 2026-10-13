/*
 * function: func_021BE6F8
 * address:  0x021BE6F8
 * packet:   pkt_021BE6F8
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SAVE_CONTROL_INTR_NoOp 0x021BD39C thumb ov088
 *
 * UNBLOCKED: 0x021BD39C is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl site resolves as matched and the verdict promoted to EXACT.
 */
#include "../include/Obj25362.h"

extern void SAVE_CONTROL_INTR_NoOp(int);

int func_021BE6F8(char *a)
{
    SAVE_CONTROL_INTR_NoOp(((struct Obj25362 *)a)->fA4);
    return 1;
}
