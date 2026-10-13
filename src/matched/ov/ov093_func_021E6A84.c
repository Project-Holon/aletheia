/*
 * function: func_021E6A84
 * address:  0x021E6A84
 * packet:   pkt_ov093_021E6A84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021E6AC8  0x021E6AC8  thumb  ov093
 *   BTL_CALC_PickRandomMoveExcluding  0x021D7E44  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021E6AC8(u32 *out);
extern u16 BTL_CALC_PickRandomMoveExcluding(int a, int b);
extern int func_021C8030(int a, int b, int c);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E6A84(int x, int a, int c)
{
    u32 v;
    int id;
    int r;

    if (c == BTL_EVENT_GetVar(2)) {
        id = BTL_CALC_PickRandomMoveExcluding(func_021E6AC8(&v), (u16)v);
        r = func_021C8030(a, c, id);
        BTL_EVENT_OverwriteVar(0x12, id);
        BTL_EVENT_OverwriteVar(0xd, r);
    }
}
