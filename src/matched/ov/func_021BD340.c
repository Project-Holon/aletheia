/*
 * function: PLACE_NAME_LETTER_IsFinished
 * address:  0x021BD340
 * packet:   pkt_021BD340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetActive  0x021BD2D8  thumb  ov021
 *   PLACE_NAME_LETTER_IsXDone  0x021BD36C  thumb  ov021
 *   PLACE_NAME_LETTER_IsYDone  0x021BD394  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 PLACE_NAME_LETTER_GetActive(u8 *p);
extern int PLACE_NAME_LETTER_IsXDone(void *p);
extern int PLACE_NAME_LETTER_IsYDone(void *p);

int PLACE_NAME_LETTER_IsFinished(void *a)
{
if (PLACE_NAME_LETTER_GetActive((u8 *)a) == 0) {
    return 1;
}
if (PLACE_NAME_LETTER_IsXDone((void *)a) != 0) {
    if (PLACE_NAME_LETTER_IsYDone((void *)a) != 0) {
        return 1;
    }
}
return 0;
}

