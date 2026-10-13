/*
 * function: FIELD_PLACE_NAME_Main
 * address:  0x021BC484
 * packet:   pkt_ov021_021BC484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_IncrementFrame  0x021BD0B0  thumb  ov021
 *   FIELD_PLACE_NAME_GetState  0x021BD0A4  thumb  ov021
 *   FIELD_PLACE_NAME_StateIdle  0x021BCC3C  thumb  ov021
 *   FIELD_PLACE_NAME_StatePrepare  0x021BCC80  thumb  ov021
 *   FIELD_PLACE_NAME_StateFadeIn  0x021BCD34  thumb  ov021
 *   FIELD_PLACE_NAME_StateFadeInWait  0x021BCD70  thumb  ov021
 *   FIELD_PLACE_NAME_StateLettersLaunch  0x021BCD84  thumb  ov021
 *   FIELD_PLACE_NAME_StateLettersLand  0x021BCDD8  thumb  ov021
 *   FIELD_PLACE_NAME_StateFadeOut  0x021BCE88  thumb  ov021
 *   FIELD_PLACE_NAME_UpdateLetters  0x021BC970  thumb  ov021
 */

extern void FIELD_PLACE_NAME_IncrementFrame(int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELD_PLACE_NAME_GetState(u8 *p);
extern void FIELD_PLACE_NAME_StateIdle(void *p);
extern void FIELD_PLACE_NAME_StatePrepare(char *p);
extern void FIELD_PLACE_NAME_StateFadeIn(int a);
extern void FIELD_PLACE_NAME_StateFadeInWait(int a);
extern void FIELD_PLACE_NAME_StateLettersLaunch(char *p);
extern void FIELD_PLACE_NAME_StateLettersLand(char *p);
extern void FIELD_PLACE_NAME_StateFadeOut(char *p);
extern void FIELD_PLACE_NAME_UpdateLetters(int a);

void FIELD_PLACE_NAME_Main(u32 a)
{
    FIELD_PLACE_NAME_IncrementFrame(a);
    switch (FIELD_PLACE_NAME_GetState((u8 *)a)) {
    case 0:
        FIELD_PLACE_NAME_StateIdle((void *)a);
        break;
    case 1:
        FIELD_PLACE_NAME_StatePrepare((char *)a);
        break;
    case 2:
        FIELD_PLACE_NAME_StateFadeIn(a);
        break;
    case 3:
        FIELD_PLACE_NAME_StateFadeInWait(a);
        break;
    case 4:
        FIELD_PLACE_NAME_StateLettersLaunch((char *)a);
        break;
    case 5:
        FIELD_PLACE_NAME_StateLettersLand((char *)a);
        break;
    case 6:
        FIELD_PLACE_NAME_StateFadeOut((char *)a);
        break;
    }
    FIELD_PLACE_NAME_UpdateLetters(a);
}
