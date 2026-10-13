/*
 * function: BTL_CLIENT_StepPlayViewSequence
 * address: 0x021D299C
 * packet: pkt_ov093_021D299C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_CORE_StartMonSpriteUnload 0x021EA8E4 thumb ov093
 *   BTLV_CORE_WaitMonSpriteUnload 0x021EA8F4 thumb ov093
 */
#include "../include/Obj13398.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BTLV_CORE_StartMonSpriteUnload(u32 *p);
extern int BTLV_CORE_WaitMonSpriteUnload(u32 *p);
int BTL_CLIENT_StepPlayViewSequence(char *p, int *state)
{
    switch (*state) {
    case 0:
        BTLV_CORE_StartMonSpriteUnload(((struct Obj13398 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUnload(((struct Obj13398 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}
