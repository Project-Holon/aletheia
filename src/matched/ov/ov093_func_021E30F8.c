/*
 * function: func_021E30F8
 * address:  0x021E30F8
 * packet:   pkt_ov093_021E30F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C8288(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E30F8(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (func_021C8288(a) == 3)
            BTL_EVENT_OverwriteVar(0x51, 1);
    }
}
