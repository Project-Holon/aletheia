/*
 * function: BTLV_EFFVM_ResolveParticleKey
 * address:  0x021FE38C
 * packet:   pkt_ov094_021FE38C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Levers: v and k unsigned (bhi/bhs/blo compares); the middle arm is
 * `mode != 8` and the mode==8 arm last, which puts its block after the
 * cross-jumped BTLV_MCSS_GetSpriteColorCode call.
 *
 * symbols:
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_GetSpriteColorCode  0x022003C4  thumb  ov094
 *   PALANM_GetPairedCodeForFirst  0x0202142C  thumb
 */
#include "../include/Obj00325.h"
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_MCSS_GetSpriteColorCode(char *p, int key);
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);

unsigned int BTLV_EFFVM_ResolveParticleKey(char *p, unsigned int k)
{
    int mode = ((struct Obj00325 *)p)->f25C;
    unsigned int v;

    if (mode == 9)
        v = BTLV_MCSS_GetSpriteColorCode((char *)BTLV_EFFECT_GetMcss(), ((struct Obj00325 *)p)->fDC);
    else if (mode != 8)
        v = BTLV_MCSS_GetSpriteColorCode((char *)BTLV_EFFECT_GetMcss(), mode);
    else
        v = PALANM_GetPairedCodeForFirst(((struct Obj00325 *)p)->f254);
    if (v == 0 || v > 0x19)
        v = 4;
    v--;
    switch (k) {
    case 3:
        k += v;
        break;
    case 0x1d:
        if (v + 1 == 0x19)
            v = 0x10;
        else if (v + 1 >= 0x10)
            v = 3;
        k += v;
        break;
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
        k += v << 2;
        break;
    }
    return k;
}
