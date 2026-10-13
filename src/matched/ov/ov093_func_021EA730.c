/*
 * function: BTLV_CORE_StartPrintMessage
 * address:  0x021EA730
 * packet:   pkt_ov093_021EA730
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartMessage  0x021ECEB8  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMessage(u8 *a, u32 b, u16 s, u32 c);

void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c)
{
    if (BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj01899 *)p)->f4) == 0) {
        BTLV_SCU_StartMessage(*(u8 * *)&((struct Obj01899 *)p)->f17C, a, b, c);
    }
}
