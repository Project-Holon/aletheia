/*
 * file:     unit_068998A4.c
 * function: func_068998A4
 * address: 0x068998A4
 * packet: pkt_ov095_068998A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Calls Thumb bx-pc veneers: 068998C4 -> 021D775C,
 * 068998D4 -> 021B9A40, 068998E4 -> 021D76BC.
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern int func_021B9A40(u8);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
void func_068998A4(int a, int b, int c)
{
    if (c == func_021B9A40((u8)BTL_EVENT_GetVar(3))) {
        BTL_EVENT_OverwriteVar(0x45, 1);
    }
}
