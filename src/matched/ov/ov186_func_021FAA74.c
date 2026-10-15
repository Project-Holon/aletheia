/*
 * function: BR_BTN_UpdateTextInput
 * address: 0x021FAA74
 * packet: pkt_ov186_021FAA74
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_BTN_GetRowField 0x021FAF24 thumb
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb
 *   BR_UTIL_SetWindowText 0x021FD170 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_HandleInput 0x021FA284 thumb
 */
#include "../include/Obj03340.h"
extern int BR_BTN_GetRowField(char *ctx, int kind);
typedef unsigned short u16;
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_HandleInput(void *p, int *state, unsigned char *ctx);
void BR_BTN_UpdateTextInput(void *p, int *state, unsigned *ctx)
{
    int value;
    switch (*state) {
    case 0:
        value = BR_BTN_GetRowField((char *)ctx[16] + ctx[11] * 0x44, 6);
        if (ctx[20] == 0)
            ctx[20] = (unsigned)BR_UTIL_CreateTextWin((int)((void *)ctx[1]), (void *)ctx[19], ((struct Obj03340 *)ctx)->f0);
        BR_UTIL_SetWindowText((void *)ctx[20], (void *)ctx[1], (void *)value);
        *state = 1;
        break;
    case 1: *state = 2; break;
    case 2: BR_UTIL_SetTaskStep(p, (int)BR_BTN_HandleInput); break;
    }
}
