/*
 * function: BR_BTN_UpdateHide2
 * address: 0x021FAB7C
 * packet: pkt_ov186_021FAB7C
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_BTN_GetPos 0x021FAEE4 thumb
 *   BR_BTN_SetAnimMode 0x021FAD18 thumb
 *   BR_BTN_StepAnim 0x021FAD74 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_UpdateBack 0x021FAA34 thumb
 */
#include "../include/Obj06630.h"
extern void BR_BTN_GetPos(char *p, int *out);
extern void BR_BTN_SetAnimMode(char *ctx, int mode, const int *target);
extern int BR_BTN_StepAnim(char *ctx);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_UpdateBack(void *p, int *state, int *ctx);
void BR_BTN_UpdateHide2(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            BR_BTN_GetPos(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44, values);
            values[1] = 0xe0;
            BR_BTN_SetAnimMode(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= BR_BTN_StepAnim(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: BR_UTIL_SetTaskStep(p, (int)BR_BTN_UpdateBack); break;
    }
}
