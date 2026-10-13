/*
 * function: func_021E5800
 * address:  0x021E5800
 * packet:   pkt_ov093_021E5800
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021E5784  0x021E5784  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void func_021E5784(void *a, void *b, int c, int d);

void func_021E5800(void *a, void *b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(0xd);
        func_021E5784(a, b, c, k);
    }
}
