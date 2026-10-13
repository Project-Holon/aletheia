/*
 * function: PLACE_NAME_LETTER_IsYDone
 * address:  0x021BD394
 * packet:   pkt_ov021_021BD394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetMotion  0x021BD304  thumb  ov021
 *   PLACE_NAME_LETTER_GetActive  0x021BD2D8  thumb  ov021
 */

typedef struct {
    char pad[0x2C];
    int f;
} Inner;

extern unsigned char *PLACE_NAME_LETTER_GetMotion(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 PLACE_NAME_LETTER_GetActive(u8 *p);

int PLACE_NAME_LETTER_IsYDone(void *p)
{
    Inner *q = (Inner *)PLACE_NAME_LETTER_GetMotion(p);

    if (PLACE_NAME_LETTER_GetActive(p) == 0) {
        return 1;
    }
    if (q->f <= 0) {
        return 1;
    }
    return 0;
}
