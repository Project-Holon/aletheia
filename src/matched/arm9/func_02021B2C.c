/*
 * function: PALANM_StepBgFades
 * address:  0x02021B2C
 * packet:   pkt_02021944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_StepFadeWait  0x02021B6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void PALANM_StepFadeWait(u8 *p, u32 idx, u32 arg);

void PALANM_StepBgFades(u8 *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        PALANM_StepFadeWait(p, i, 0x10);
    }
}
