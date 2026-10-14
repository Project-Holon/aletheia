/*
 * function: BTLV_EFFVM_CmdSetPokeShadowVanish
 * address:  0x021FB1C4
 * packet:   pkt_ov094_021FB1C4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_SetShadowVanish  0x021FF470  thumb  ov094
 */
#include "../include/Obj00177.h"
typedef unsigned char u8;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveBattlerList(int b, int t, int *out);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_SetShadowVanish(void *p, int key, u8 v);

int BTLV_EFFVM_CmdSetPokeShadowVanish(struct Cursor *a, char *b)
{
    int buf[8];
    int n;
    int i;
    int v;

    n = BTLV_EFFVM_ResolveBattlerList((int)b, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            BTLV_MCSS_SetShadowVanish((void *)BTLV_EFFECT_GetMcss(), buf[i], v);
    }
    return ((struct Obj00177 *)b)->f23C;
}
