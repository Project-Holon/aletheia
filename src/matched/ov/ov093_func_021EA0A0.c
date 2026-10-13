/*
 * function: BTLV_CORE_StartSceneEffect
 * address:  0x021EA0A0
 * packet:   pkt_ov093_021EA0A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTLV_SCU_StartWazaEffect  0x021ED118  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void BTLV_SCU_StartWazaEffect(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f);

void BTLV_CORE_StartSceneEffect(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7)
{
    u32 r7;
    u32 r2;

    r7 = BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], a1);
    if (a2 != 6) {
        r2 = BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], a2);
    } else {
        r2 = 0xff;
    }
    BTLV_SCU_StartWazaEffect((u8 *)p[0x5f], r7, r2, a3, s5, s6, s7);
}
