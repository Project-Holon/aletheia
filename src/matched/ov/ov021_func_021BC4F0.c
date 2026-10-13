/*
 * function: FIELD_PLACE_NAME_Draw
 * address:  0x021BC4F0
 * packet:   pkt_ov021_021BC4F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetState  0x021BD0A4  thumb  ov021
 *   FIELD_PLACE_NAME_DrawIdle  0x021BCEAC  thumb  ov021
 *   FIELD_PLACE_NAME_DrawPrepare  0x021BCEB0  thumb  ov021
 *   FIELD_PLACE_NAME_DrawFadeIn  0x021BCEB4  thumb  ov021
 *   FIELD_PLACE_NAME_DrawFadeInWait  0x021BCF18  thumb  ov021
 *   FIELD_PLACE_NAME_DrawLettersLaunch  0x021BCF1C  thumb  ov021
 *   FIELD_PLACE_NAME_DrawLettersLand  0x021BCF20  thumb  ov021
 *   FIELD_PLACE_NAME_DrawFadeOut  0x021BCF24  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELD_PLACE_NAME_GetState(u8 *p);
extern void FIELD_PLACE_NAME_DrawIdle(int a);
extern void FIELD_PLACE_NAME_DrawPrepare(int a);
extern void FIELD_PLACE_NAME_DrawFadeIn(char *p);
extern void FIELD_PLACE_NAME_DrawFadeInWait(int a);
extern void FIELD_PLACE_NAME_DrawLettersLaunch(int a);
extern void FIELD_PLACE_NAME_DrawLettersLand(int a);
extern void FIELD_PLACE_NAME_DrawFadeOut(char *p);

void FIELD_PLACE_NAME_Draw(int a)
{
    switch (FIELD_PLACE_NAME_GetState((u8 *)a)) {
    case 0:
        FIELD_PLACE_NAME_DrawIdle(a);
        break;
    case 1:
        FIELD_PLACE_NAME_DrawPrepare(a);
        break;
    case 2:
        FIELD_PLACE_NAME_DrawFadeIn((char *)a);
        break;
    case 3:
        FIELD_PLACE_NAME_DrawFadeInWait(a);
        break;
    case 4:
        FIELD_PLACE_NAME_DrawLettersLaunch(a);
        break;
    case 5:
        FIELD_PLACE_NAME_DrawLettersLand(a);
        break;
    case 6:
        FIELD_PLACE_NAME_DrawFadeOut((char *)a);
        break;
    }
}
