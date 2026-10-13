/*
 * function: FIELD_PLACE_NAME_BlitNextLetter
 * address:  0x021BC9CC
 * packet:   pkt_ov021_021BC9CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetBmp  0x021BD1DC  thumb  ov021
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PLACE_NAME_LETTER_GetX  0x021BD1FC  thumb  ov021
 *   PLACE_NAME_LETTER_GetY  0x021BD204  thumb  ov021
 *   PLACE_NAME_LETTER_GetWidth  0x021BD1EC  thumb  ov021
 *   PLACE_NAME_LETTER_GetHeight  0x021BD1F4  thumb  ov021
 *   BMP_Blit  0x020439A0  arm
 */
#include "../include/Obj01123.h"

typedef unsigned short u16;
typedef unsigned char u8;

extern int PLACE_NAME_LETTER_GetBmp(u8 *a0);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern int PLACE_NAME_LETTER_GetX(int a);
extern int PLACE_NAME_LETTER_GetY(int a);
extern int PLACE_NAME_LETTER_GetWidth(u8 *a0);
extern int PLACE_NAME_LETTER_GetHeight(u8 *a0);
typedef unsigned int   u32;
struct Bmp;
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

void FIELD_PLACE_NAME_BlitNextLetter(char *p)
{
    int r4;
    int a, b;
    u16 c, d, e, f;

    r4 = *(int *)(p + 0xc8 + 4 * ((struct Obj01123 *)p)->f14A);
    if (r4 != 0) {
        a = PLACE_NAME_LETTER_GetBmp((u8 *)r4);
        b = (int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj01123 *)p)->f24);
        c = PLACE_NAME_LETTER_GetX(r4);
        d = PLACE_NAME_LETTER_GetY(r4) - 8;
        e = PLACE_NAME_LETTER_GetWidth((u8 *)r4);
        f = PLACE_NAME_LETTER_GetHeight((u8 *)r4);
        BMP_Blit((struct Bmp *)a, (struct Bmp *)b, 0, 0, c, d, e, f, 0);
    }
    (((struct Obj01123 *)p)->f14A)++;
}
