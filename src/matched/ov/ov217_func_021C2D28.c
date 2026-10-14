/*
 * function: PALETTE_ANIME_StepFadeOut
 * address: 0x021C2D28
 * packet: pkt_ov217_021C2D28
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Original truncates weight to u8 before calling 02021F64; its legacy
 * Rgb555 stack input reads only the low halfword, so scalar u16 keeps
 * the original caller's full-word str without aggregate partial stores.
 * symbols:
 *   PALANM_BlendColors 0x02021F64 thumb
 *   PALETTE_ANIME_StopImpl 0x021C2A28 thumb ov217
 *   PALETTE_ANIME_RestoreImpl 0x021C2D88 thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00115.h"
struct Rgb555 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};
extern void PALANM_BlendColors(unsigned short *, unsigned short *, unsigned int, unsigned char, unsigned short);
extern void PALETTE_ANIME_StopImpl(void *);
extern int PALETTE_ANIME_RestoreImpl(char *);
void PALETTE_ANIME_StepFadeOut(char *p)
{
    unsigned int weight = 7 - ((struct Obj00115 *)p)->f1C * 7 / 30;
    PALANM_BlendColors(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 30) {
        PALETTE_ANIME_StopImpl(p);
        PALETTE_ANIME_RestoreImpl(p);
    }
}
