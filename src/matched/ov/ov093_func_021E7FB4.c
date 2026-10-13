/*
 * function: func_021E7FB4
 * address:  0x021E7FB4
 * packet:   pkt_ov093_021E7FB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

void func_021E7FB4(int a, int b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        if (k != 0x1f && func_021B9A24(c, k) != 0)
            BTL_EVENT_OverwriteVar(0x41, 1);
    }
}
