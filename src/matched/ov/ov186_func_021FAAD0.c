/*
 * function: BR_BTN_UpdateSlide
 * address: 0x021FAAD0
 * packet: pkt_ov186_021FAAD0
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_BTN_GetRowField 0x021FAF24 thumb
 *   BR_BTN_SetAnimMode 0x021FAD18 thumb
 *   BR_BTN_StepAnim 0x021FAD74 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_SetupInput 0x021FA274 thumb
 */
#include "../include/Obj05499.h"
extern int BR_BTN_GetRowField(char *ctx, int kind);
extern void BR_BTN_SetAnimMode(char *ctx, int mode, const int *target);
extern int BR_BTN_StepAnim(char *ctx);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_SetupInput(void *p);
void BR_BTN_UpdateSlide(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            values[0] = BR_BTN_GetRowField(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44, 8);
            values[1] = BR_BTN_GetRowField(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44, 9);
            BR_BTN_SetAnimMode(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= BR_BTN_StepAnim(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: BR_UTIL_SetTaskStep(p, (int)BR_BTN_SetupInput); break;
    }
}
