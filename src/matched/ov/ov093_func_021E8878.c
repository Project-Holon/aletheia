/*
 * function: BTLV_CORE_EventSetFlagIfAttacker
 * address:  0x021E8878
 * packet:   pkt_ov093_021E8878
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void BTLV_CORE_EventSetFlagIfAttacker(int a, int b, int c)
{
    if (func_021B9A24((u8)BTL_EVENT_GetVar(2), c) != 0)
        BTL_EVENT_OverwriteVar(0x51, 1);
}
