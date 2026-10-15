/*
 * function: BR_BTN_UpdateSpread
 * address: 0x021FA444
 * packet: pkt_ov186_021FA444
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_BTN_GetPos 0x021FAEE4 thumb
 *   BR_BTN_SetAnimMode 0x021FAD18 thumb
 *   BR_BTN_StepAnim 0x021FAD74 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_UpdatePress 0x021FA500 thumb
 */
#include "../include/Obj03890.h"
typedef unsigned char  u8;
extern void BR_BTN_GetPos(char *p, int *out);
extern void BR_BTN_SetAnimMode(char *ctx, int mode, const int *target);
extern int BR_BTN_StepAnim(char *ctx);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_UpdatePress(void *p, int *state, u8 *ctx);
void BR_BTN_UpdateSpread(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            if (((struct Obj03890 *)ctx)->f2C != i) {
                BR_BTN_GetPos(*(char * *)&((struct Obj03890 *)ctx)->f40 + ((struct Obj03890 *)ctx)->f2C * 0x44, values);
                BR_BTN_SetAnimMode(*(char * *)&((struct Obj03890 *)ctx)->f40 + i * 0x44, 0, values);
            }
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= BR_BTN_StepAnim(*(char * *)&((struct Obj03890 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2:
        if (((struct Obj03890 *)ctx)->f1C == 4) {
            BR_UTIL_SetTaskStep(p, (int)BR_BTN_UpdatePress);
            return;
        } else {
            BR_UTIL_SetTaskStep(p, (int)BR_BTN_UpdatePress);
        }
        break;
    }
}
