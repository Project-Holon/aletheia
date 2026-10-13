/*
 * function: BTLV_CORE_StartRotation
 * address:  0x021EA904
 * packet:   pkt_ov093_021EA904
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   BTLV_CORE_ProcRotation  0x021EA990  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern int BTLV_CORE_ProcRotation(int *st, u8 *b);

void BTLV_CORE_StartRotation(u32 *p, u32 a, u32 b, u32 c, u8 d, u8 e)
{
    u8 *t;

    t = BTLV_CORE_GetTaskWork((u8 *)p, 7);
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[3] = d;
    t[4] = e;
    t[5] = BTL_MAIN_GetClientTrainerIndex((u8 *)p[0], a, d);
    t[6] = BTL_MAIN_GetClientTrainerIndex((u8 *)p[0], a, e);
    p[7] = 0;
    p[8] = (u32)BTLV_CORE_ProcRotation;
    p[9] = (u32)p;
    p[10] = 0;
}
