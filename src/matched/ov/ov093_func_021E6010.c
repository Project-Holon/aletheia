/*
 * function: func_021E6010
 * address:  0x021E6010
 * packet:   pkt_ov093_021E6010
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021E60A8  0x021E60A8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern u8 *func_021E60A8(void *a, u32 b, u8 c);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E6010(u8 *p, void *a, int b, int *c)
{
    int n;
    u32 i;
    if (b != BTL_EVENT_GetVar(3))
        return;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (func_021E60A8(a, b, i) != 0)
            n++;
    }
    if (n == 0)
        n = 1;
    BTL_EVENT_OverwriteVar(0x2a, n);
    *c = 0;
}
