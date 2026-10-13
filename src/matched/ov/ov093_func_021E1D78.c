/*
 * function: func_021E1D78
 * address:  0x021E1D78
 * packet:   pkt_ov093_021E1D78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C830C  0x021C830C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern unsigned int func_021C830C(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E1D78(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && func_021C830C(b))
        BTL_EVENT_OverwriteVar(81, 1);
}
