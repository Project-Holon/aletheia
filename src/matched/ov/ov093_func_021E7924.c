/*
 * function: func_021E7924
 * address:  0x021E7924
 * packet:   pkt_ov093_021E7924
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E7924(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x3c) == 0xb)
        BTL_EVENT_OverwriteVar(0x3d, BTL_EVENT_GetVar(0x3d) + 1);
}
