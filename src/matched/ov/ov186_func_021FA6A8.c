/*
 * function: BR_BTN_UpdateRestore
 * address: 0x021FA6A8
 * packet: pkt_ov186_021FA6A8
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_BTN_SetAnimMode 0x021FAD18 thumb
 *   BR_BTN_StepAnim 0x021FAD74 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_UpdateBack 0x021FAA34 thumb
 *   BR_BTN_UpdateExpand 0x021FA7FC thumb
 */
#include "../include/Obj06628.h"
extern void BR_BTN_SetAnimMode(char *ctx, int mode, const int *target);
extern int BR_BTN_StepAnim(char *ctx);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_UpdateBack(void *p, int *state, int *ctx);
extern void BR_BTN_UpdateExpand(void *p, int *state, unsigned char *ctx);
void BR_BTN_UpdateRestore(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++)
            BR_BTN_SetAnimMode(*(char * *)&((struct Obj06628 *)ctx)->f40 + i * 0x44, 1, 0);
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= BR_BTN_StepAnim(*(char * *)&((struct Obj06628 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2:
        switch (((struct Obj06628 *)ctx)->f1C) {
        case 0: case 1: BR_UTIL_SetTaskStep(p, (int)BR_BTN_UpdateBack); break;
        case 4: BR_UTIL_SetTaskStep(p, (int)BR_BTN_UpdateExpand); break;
        default: BR_UTIL_SetTaskStep(p, (int)BR_BTN_UpdateBack); break;
        }
        break;
    }
}
