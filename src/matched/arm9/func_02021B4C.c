/*
 * function: PALANM_StepObjFades
 * address:  0x02021B4C
 * packet:   pkt_02021944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_StepFadeWait  0x02021B6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void PALANM_StepFadeWait(u8 *p, u32 idx, u32 arg);

void PALANM_StepObjFades(u8 *p)
{
    u8 i;

    for (i = 4; i < 0xE; i++) {
        PALANM_StepFadeWait(p, i, 0x100);
    }
}
