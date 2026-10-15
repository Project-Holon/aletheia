/*
 * function: INTRO_CMD_CmdSaveResume
 * address:  0x021BE6E8
 * packet:   pkt_021BE6E8
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SAVE_CONTROL_INTR_Resume 0x021BD374 thumb ov088
 *
 * UNBLOCKED: 0x021BD374 is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl gIntroSite resolves as matched and the verdict promoted to EXACT.
 */
#include "../include/Obj25361.h"

extern void SAVE_CONTROL_INTR_Resume(unsigned char *p);

int INTRO_CMD_CmdSaveResume(char *a)
{
    SAVE_CONTROL_INTR_Resume((unsigned char *)(((struct Obj25361 *)a)->fA4));
    return 1;
}
