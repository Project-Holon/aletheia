/*
 * function: BR_CODEIN_RecordStepCreateProfile
 * address:  0x021DBC68
 * packet:   pkt_021DBC68
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_CODEIN_RecordStepFadeInA   0x021DBCA8  thumb
 *   BR_CODEIN_RecordSetupButtons   0x021DCEE4  thumb
 *   BR_CODEIN_RecordCreateProfileScreen   0x021DCDD8  thumb
 *   BR_CODEIN_RecordSetupProfile   0x021DC8EC  thumb
 *   BR_UTIL_SetTaskStep   0x021FD73C  thumb
 *
 * Flush the object, dispatch on the p+0xB0 flag, then chain to 0x21FD73C.
 */
#include "../include/Obj00730.h"


extern void BR_CODEIN_RecordStepFadeInA(int *task, int *state, char *p);
extern void BR_CODEIN_RecordSetupButtons(char *p, char *q);
extern void BR_CODEIN_RecordCreateProfileScreen(char *p, char *q);
extern void BR_CODEIN_RecordSetupProfile(char *p, char *q);
extern void BR_UTIL_SetTaskStep(int, void *);

void BR_CODEIN_RecordStepCreateProfile(int a, int b, char *p)
{
    BR_CODEIN_RecordSetupButtons(p, (char *)(((struct Obj00730 *)p)->fD0));
    if (((struct Obj00730 *)p)->fB0 != 0)
        BR_CODEIN_RecordCreateProfileScreen(p, (char *)(((struct Obj00730 *)p)->fD0));
    else
        BR_CODEIN_RecordSetupProfile(p, (char *)(((struct Obj00730 *)p)->fD0));
    BR_UTIL_SetTaskStep(a, BR_CODEIN_RecordStepFadeInA);
}
