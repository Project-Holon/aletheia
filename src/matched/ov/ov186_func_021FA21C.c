/*
 * unit: yes
 * function: BR_BTN_SetTailSelection,BR_BTN_SetupInput
 * address: 0x021FA21C
 * packet: pkt_ov186_021FA21C
 * region: ov186
 * status: EXACT
 * symbols:
 *   BR_BTN_SetSelected 0x021FAFC0 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb
 *   BR_BTN_HandleInput 0x021FA284 thumb
 */
#include "../include/Obj06627.h"
extern void BR_BTN_SetSelected(char *p, unsigned value);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_HandleInput(void *p, int *state, unsigned char *ctx);
void BR_BTN_SetTailSelection(unsigned char *ctx, int mode)
{
    int i, selected;
    for (i = 0; i < ctx[0x3b]; i++) {
        switch (mode) {
        case 0: selected = (i == ctx[0x3b] - 1); break;
        case 1: selected = (i >= ctx[0x3b] - 2); break;
        }
        if (selected)
            BR_BTN_SetSelected(*(char * *)&((struct Obj06627 *)ctx)->f3C + i * 0x44, 0);
        else
            BR_BTN_SetSelected(*(char * *)&((struct Obj06627 *)ctx)->f3C + i * 0x44, 1);
    }
}
void BR_BTN_SetupInput(void *p)
{
    BR_UTIL_SetTaskStep(p, (int)BR_BTN_HandleInput);
}
