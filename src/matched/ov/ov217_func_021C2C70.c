/*
 * function: PALETTE_ANIME_StepBlink30
 * address: 0x021C2C70
 * packet: pkt_ov217_021C2C70
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C2CAE..021C2CB0 is two zero alignment bytes.
 * Callee 02021F64's legacy Rgb555 aggregate input reads only its low
 * stack halfword; scalar u16 preserves the original caller's str word.
 * symbols:
 *   PALANM_BlendColors 0x02021F64 thumb
 *   PALETTE_ANIME_StopImpl 0x021C2A28 thumb ov217
 *   PALETTE_ANIME_RestoreImpl 0x021C2D88 thumb ov217
 */
#include "../include/Obj00115.h"
struct Rgb555 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};
extern void PALANM_BlendColors(unsigned short *, unsigned short *, unsigned int, int, unsigned short);
extern void PALETTE_ANIME_StopImpl(void *);
extern int PALETTE_ANIME_RestoreImpl(char *);
void PALETTE_ANIME_StepBlink30(char *p)
{
    int weight = ((((struct Obj00115 *)p)->f1C >> 2) & 1) == 0 ? 0 : 6;
    PALANM_BlendColors(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 30) {
        PALETTE_ANIME_StopImpl(p);
        PALETTE_ANIME_RestoreImpl(p);
    }
}
