/*
 * function: func_021E0284
 * address:  0x021E0284
 * packet:   pkt_ov093_021E0284
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int m);
typedef unsigned int   u32;
extern u32 func_021C7EC4(u8 *p);

void func_021E0284(int a, void *b, int c, int *d, u8 e)
{
    if (c == BTL_EVENT_GetVar(3) && e == BTL_EVENT_GetVar(22)) {
        if (*d == 1 || func_021C7EC4(b))
            BTL_EVENT_MultiplyVar(49, 6 << 10);
    }
}
