/*
 * function: BR_DOWNLOAD_StepFadeIn
 * address:  0x021F85DC
 * packet:   pkt_021F85DC
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: every concrete byte reproduces; the call to 0x021FE7B0 is left
 *   wildcarded because that address lies outside ov184's own 0x5A0-byte
 *   region and no listing labels it -- the only branch image-wide is the
 *   one inside this range.
 *
 * symbols:
 *   BR_DOWNLOAD_HandleTouch   0x021F8670  thumb
 *   BR_FADE_Start   0x021FE784  thumb
 *   BR_FADE_GetResult   0x021FE7B0  thumb
 *   BR_UTIL_SetTaskStep   0x021FD73C  thumb
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   finish through 0x21FD73C on 2.
 */
#include "../include/Obj14447.h"


extern void BR_DOWNLOAD_HandleTouch(int a, int b, char *p);
extern int BR_FADE_Start(int, int, int, int);
extern int BR_FADE_GetResult(int);
extern void BR_UTIL_SetTaskStep(int, void *);

void BR_DOWNLOAD_StepFadeIn(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start(*(int *)(((struct Obj14447 *)p)->f30), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(*(int *)(((struct Obj14447 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(a, BR_DOWNLOAD_HandleTouch);
        break;
    }
}
