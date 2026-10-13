/*
 * function: FIELD_PLACE_NAME_SetState
 * address:  0x021BCB9C
 * packet:   pkt_ov021_021BCB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_SetStateRaw  0x021BD0A0  thumb  ov021
 *   FIELD_PLACE_NAME_ResetFrame  0x021BD0A8  thumb  ov021
 *   FIELD_PLACE_NAME_ResetStep  0x021BD0C8  thumb  ov021
 *   func_02040588  0x02040588  arm
 *   FIELD_PLACE_NAME_HideLetters  0x021BC92C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

void FIELD_PLACE_NAME_SetStateRaw(void *p, int v);
void FIELD_PLACE_NAME_ResetFrame(char *p);
void FIELD_PLACE_NAME_ResetStep(char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
void FIELD_PLACE_NAME_HideLetters(void *p);

void FIELD_PLACE_NAME_SetState(void *p, int keep)
{
    FIELD_PLACE_NAME_SetStateRaw(p, keep);
    FIELD_PLACE_NAME_ResetFrame(p);
    FIELD_PLACE_NAME_ResetStep(p);
    if (keep == 0) {
        func_02040588(3, 0);
        FIELD_PLACE_NAME_HideLetters(p);
    }
}
