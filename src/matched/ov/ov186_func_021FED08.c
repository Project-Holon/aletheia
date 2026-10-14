/*
 * function: BR_FADE_GetStepFunc
 * address: 0x021FED08
 * packet: pkt_ov186_021FED08
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_StepFadeBgA 0x021FE90C thumb ov186
 *   BR_FADE_StepFadeBgB 0x021FE970 thumb ov186
 *   BR_FADE_StepBlend 0x021FE9D4 thumb ov186
 *   BR_FADE_StepPalette 0x021FEB1C thumb ov186
 *   BR_FADE_StepSubPlane3 0x021FEC14 thumb ov186
 */
typedef unsigned int   u32;
extern int BR_FADE_StepFadeBgA(u32 *p, u32 *state);
extern int BR_FADE_StepFadeBgB(u32 *p, u32 *state);
extern int BR_FADE_StepBlend(char *p, int *state);
extern int BR_FADE_StepPalette(char *p, int *state);
extern int BR_FADE_StepSubPlane3(char *p, int *state);
void *BR_FADE_GetStepFunc(unsigned index)
{
    switch (index) {
    case 0: return (void *)BR_FADE_StepFadeBgA;
    case 1: return (void *)BR_FADE_StepFadeBgB;
    case 2: return (void *)BR_FADE_StepBlend;
    case 3: return (void *)BR_FADE_StepPalette;
    case 4: return (void *)BR_FADE_StepSubPlane3;
    }
    return 0;
}
