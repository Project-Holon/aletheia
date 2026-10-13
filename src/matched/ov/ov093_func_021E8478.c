/*
 * function: func_021E8478
 * address:  0x021E8478
 * packet:   pkt_ov093_021E8478
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

void func_021E8478(int a, int b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(2) && *d != 0)
        BTL_EVENT_OverwriteVar(0x51, 1);
}
