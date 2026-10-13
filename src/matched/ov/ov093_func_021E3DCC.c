/*
 * function: func_021E3DCC
 * address:  0x021E3DCC
 * packet:   pkt_ov093_021E3DCC
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
 *   func_021E3E84  0x021E3E84  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021E3E84(int u, void *a, int c, int *w);

void func_021E3DCC(int u, void *a, int b, int *p)
{
    int t;

    if (b == BTL_EVENT_GetVar(3)) {
        if (*p >= 2) {
            t = func_021E3E84(u, a, b, p);
            p[2] = t;
            BTL_EVENT_OverwriteVar(4, t);
        }
    }
}
