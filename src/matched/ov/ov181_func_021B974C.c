/*
 * function: STAFF_ROLL_StateWaitIntro
 * address: 0x021B974C
 * packet: pkt_ov181_021B974C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B97BA, then the next function.
 * symbols:
 *   STAFF_ROLL_StepWindowSlide 0x021BA83C thumb ov181
 */
#include "../include/Obj00682.h"
extern int STAFF_ROLL_StepWindowSlide(char *);
#define STATE(p) (*(int *)((p) + 0x2EC))
#define COUNT(p) (*(unsigned *)((p) + 0x2E4))
int STAFF_ROLL_StateWaitIntro(char *p)
{
    switch (STATE(p)) {
    case 0:
        if (COUNT(p) >= 41) {
            COUNT(p) = 0;
            STATE(p)++;
        } else if (((struct Obj00682 *)p)->f2D2 == 1) {
            COUNT(p) += 4;
        } else {
            COUNT(p)++;
        }
        break;
    case 1:
        if (STAFF_ROLL_StepWindowSlide(p) == 0)
            STATE(p)++;
        break;
    case 2:
        COUNT(p) = 0;
        STATE(p) = 0;
        return 4;
    }
    return 3;
}
