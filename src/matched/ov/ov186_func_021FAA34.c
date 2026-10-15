/*
 * function: BR_BTN_UpdateBack
 * address: 0x021FAA34
 * packet: pkt_ov186_021FAA34
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_HandleInput 0x021FA284 thumb
 */
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_HandleInput(void *p, int *state, unsigned char *ctx);
void BR_BTN_UpdateBack(void *p, int *state, int *ctx)
{
    if (*state == 0) {
        if (ctx[8]) {
            switch (ctx[7]) {
            case 0: case 1: case 2: break;
            case 3: ctx[6] = 2; break;
            case 4: ctx[6] = 1; break;
            }
        }
        BR_UTIL_SetTaskStep(p, (int)BR_BTN_HandleInput);
    }
}
