/*
 * function: PLACE_NAME_LETTER_UpdateActive
 * address:  0x021BD3BC
 * packet:   pkt_ov021_021BD3BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetActive  0x021BD2D8  thumb  ov021
 *   PLACE_NAME_LETTER_StepX  0x021BD3EC  thumb  ov021
 *   PLACE_NAME_LETTER_StepY  0x021BD430  thumb  ov021
 *   PLACE_NAME_LETTER_UpdateOamPos  0x021BD5D4  thumb  ov021
 *   PLACE_NAME_LETTER_IsFinished  0x021BD340  thumb  ov021
 *   PLACE_NAME_LETTER_Deactivate  0x021BD47C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 PLACE_NAME_LETTER_GetActive(u8 *p);
extern void PLACE_NAME_LETTER_StepX(void *p);
extern void PLACE_NAME_LETTER_StepY(void *p);
extern void PLACE_NAME_LETTER_UpdateOamPos(void *p);
extern int PLACE_NAME_LETTER_IsFinished(void *p);
extern void PLACE_NAME_LETTER_Deactivate(u8 *p);

void PLACE_NAME_LETTER_UpdateActive(void *p)
{
    if (PLACE_NAME_LETTER_GetActive(p)) {
        PLACE_NAME_LETTER_StepX(p);
        PLACE_NAME_LETTER_StepY(p);
        PLACE_NAME_LETTER_UpdateOamPos(p);
        if (PLACE_NAME_LETTER_IsFinished(p) == 1) {
            PLACE_NAME_LETTER_Deactivate(p);
        }
    }
}
