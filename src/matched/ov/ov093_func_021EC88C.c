/*
 * function: BTLV_SCU_PhaseOwnSendOutDouble
 * address:  0x021EC88C
 * packet:   pkt_ov093_021EC88C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_GetOwnPartnerClient  0x021B9000  thumb  ov093
 *   BTLV_SCU_RunOwnSendOutDoubleSolo  0x021EC8C4  thumb  ov093
 *   BTLV_SCU_RunOwnSendOutDoublePartner  0x021ECA60  thumb  ov093
 */
#include "../include/Obj00027.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern u8 BTL_MAIN_GetOwnPartnerClient(u8 *);
extern int BTLV_SCU_RunOwnSendOutDoubleSolo(u8 *, int *, u8);
extern int BTLV_SCU_RunOwnSendOutDoublePartner(u8 *, int *, u32, u8);
int BTLV_SCU_PhaseOwnSendOutDouble(u8 *p, int *state)
{
    u8 a = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00027 *)p)->f134);
    u8 b = BTL_MAIN_GetOwnPartnerClient(*(u8 * *)&((struct Obj00027 *)p)->f134);
    if (b == 4)
        return BTLV_SCU_RunOwnSendOutDoubleSolo(p, state, a);
    return BTLV_SCU_RunOwnSendOutDoublePartner(p, state, a, b);
}
