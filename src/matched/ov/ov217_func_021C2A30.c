/*
 * function: PALETTE_ANIME_UpdateImpl
 * address:  0x021C2A30
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatch: after two non-null guards, one of ten handlers is called on the
 * record, chosen by the word at offset 0x18.
 *
 * symbols:
 *   PALETTE_ANIME_StepSinePulse60  0x021C2AA0  thumb  ov217
 *   PALETTE_ANIME_StepSinePulse30  0x021C2B10  thumb  ov217
 *   PALETTE_ANIME_StepSinePulse90  0x021C2B80  thumb  ov217
 *   PALETTE_ANIME_StepBlink20  0x021C2BF0  thumb  ov217
 *   PALETTE_ANIME_StepBlink10  0x021C2C30  thumb  ov217
 *   PALETTE_ANIME_StepBlink30  0x021C2C70  thumb  ov217
 *   PALETTE_ANIME_StepBlinkStrong20  0x021C2CB0  thumb  ov217
 *   PALETTE_ANIME_StepFadeIn  0x021C2CF0  thumb  ov217
 *   PALETTE_ANIME_StepFadeOut  0x021C2D28  thumb  ov217
 *   PALETTE_ANIME_StepHold  0x021C2D68  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    u32 kind;
} Rec;

extern void PALETTE_ANIME_StepSinePulse60(u8 *p);
extern void PALETTE_ANIME_StepSinePulse30(u8 *p);
extern void PALETTE_ANIME_StepSinePulse90(u8 *p);
extern void PALETTE_ANIME_StepBlink20(u8 *p);
extern void PALETTE_ANIME_StepBlink10(u8 *p);
extern void PALETTE_ANIME_StepBlink30(char *p);
extern void PALETTE_ANIME_StepBlinkStrong20(char *p);
extern void PALETTE_ANIME_StepFadeIn(void *p);
extern void PALETTE_ANIME_StepFadeOut(char *p);
extern void PALETTE_ANIME_StepHold(void *p);

void PALETTE_ANIME_UpdateImpl(Rec *p)
{
    if (p->w4 == 0)
        return;
    if (p->w14 == 0)
        return;
    switch (p->kind) {
    case 0:
        PALETTE_ANIME_StepSinePulse60((u8 *)p);
        break;
    case 1:
        PALETTE_ANIME_StepSinePulse30((u8 *)p);
        break;
    case 2:
        PALETTE_ANIME_StepSinePulse90((u8 *)p);
        break;
    case 3:
        PALETTE_ANIME_StepBlink20((u8 *)p);
        break;
    case 4:
        PALETTE_ANIME_StepBlink10((u8 *)p);
        break;
    case 5:
        PALETTE_ANIME_StepBlink30((char *)p);
        break;
    case 6:
        PALETTE_ANIME_StepBlinkStrong20((char *)p);
        break;
    case 7:
        PALETTE_ANIME_StepFadeIn(p);
        break;
    case 8:
        PALETTE_ANIME_StepFadeOut((char *)p);
        break;
    case 9:
        PALETTE_ANIME_StepHold(p);
        break;
    }
}
