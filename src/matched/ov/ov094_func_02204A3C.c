/*
 * function: BTLV_INPUT_WaitFadeTaskMain
 * address:  0x02204A3C
 * packet:   pkt_ov094_02204A3C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_INPUT_ReleaseScreenResources  0x022023D0  thumb  ov094
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 *   FADE_IsActive  0x0204E804  arm  arm9
 */
#include "../include/Obj21770.h"
typedef struct Bits { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits;
typedef unsigned int   u32;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int FADE_IsActive(void);
extern void BTLV_INPUT_ReleaseScreenResources(char *p);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_WaitFadeTaskMain(void *a, char **s)
{
    if (PALANM_GetFadeRequestBits(((struct Obj21770 *)(*s))->f64) != 0)
        return;
    if (FADE_IsActive() != 0)
        return;
    if (((Bits *)(*s + 0x68))->mode == 1)
        BTLV_INPUT_ReleaseScreenResources(*s);
    BTLV_INPUT_DeleteTask(*s, a);
}
