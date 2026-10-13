/*
 * function: BTLV_SCU_PhaseTrainerIntro
 * address:  0x021EBF80
 * packet:   pkt_ov093_021EBF80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetOwnOpponentClient  0x021B904C  thumb  ov093
 *   BTLV_SCU_RunTrainerIntroOne  0x021EBFDC  thumb  ov093
 */
#include "../include/Obj00027.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);
extern int BTLV_SCU_RunTrainerIntroOne(u8 *, int *, u16);
int BTLV_SCU_PhaseTrainerIntro(u8 *p, int *state)
{
    return BTLV_SCU_RunTrainerIntroOne(p, state, BTL_MAIN_GetOwnOpponentClient(((struct Obj00027 *)p)->f134, 0));
}
