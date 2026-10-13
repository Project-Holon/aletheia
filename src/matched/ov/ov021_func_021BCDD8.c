/*
 * function: FIELD_PLACE_NAME_StateLettersLand
 * address:  0x021BCDD8
 * packet:   pkt_ov021_021BCDD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELD_PLACE_NAME_GetStep  0x021BD0C0  thumb  ov021
 *   PLACE_NAME_LETTER_IsActive  0x021BD20C  thumb  ov021
 *   FIELD_PLACE_NAME_ResetBlitCount  0x021BC9C0  thumb  ov021
 *   FIELD_PLACE_NAME_IncrementStep  0x021BD0D0  thumb  ov021
 *   FIELD_PLACE_NAME_BlitNextLetter  0x021BC9CC  thumb  ov021
 *   FIELD_PLACE_NAME_IsAllBlitted  0x021BCA48  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FIELD_PLACE_NAME_HideLetters  0x021BC92C  thumb  ov021
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 */
#include "../include/Obj01123.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 FIELD_PLACE_NAME_GetStep(u8 *p);
extern unsigned int PLACE_NAME_LETTER_IsActive(char *p);
extern void FIELD_PLACE_NAME_ResetBlitCount(char *p);
extern void FIELD_PLACE_NAME_IncrementStep(char *p);
extern void FIELD_PLACE_NAME_BlitNextLetter(char *p);
extern int FIELD_PLACE_NAME_IsAllBlitted(char *p);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void FIELD_PLACE_NAME_HideLetters(char *p);
extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

void FIELD_PLACE_NAME_StateLettersLand(char *p)
{
    int r6 = 1;
    int i;

    switch (FIELD_PLACE_NAME_GetStep((u8 *)p)) {
    case 0:
        for (i = 0; i < ((struct Obj01123 *)p)->f20; i++) {
            u32 v = *(u32 *)(p + 0xc8 + i * 4);
            if (v != 0 && PLACE_NAME_LETTER_IsActive((char *)v) != 0) {
                r6 = 0;
                break;
            }
        }
        if (r6 != 0) {
            FIELD_PLACE_NAME_ResetBlitCount(p);
            FIELD_PLACE_NAME_IncrementStep(p);
        }
        break;
    case 1:
        FIELD_PLACE_NAME_BlitNextLetter(p);
        if (FIELD_PLACE_NAME_IsAllBlitted(p) != 0) {
            FIELD_PLACE_NAME_IncrementStep(p);
        }
        break;
    case 2:
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01123 *)p)->f24);
        FIELD_PLACE_NAME_IncrementStep(p);
        break;
    case 3:
        FIELD_PLACE_NAME_HideLetters(p);
        FIELD_PLACE_NAME_IncrementStep(p);
        break;
    case 4:
        if (((struct Obj01123 *)p)->f42 > 0x1e) {
            FIELD_PLACE_NAME_SetState(p, 6);
        }
        break;
    }
}
