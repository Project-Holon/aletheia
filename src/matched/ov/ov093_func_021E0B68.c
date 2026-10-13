/*
 * function: func_021E0B68
 * address:  0x021E0B68
 * packet:   pkt_ov093_021E0B68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C815C  0x021C815C  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int func_021C815C(int *p);
extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E0B68(int a, void *b, int c)
{
    int n = 34;

    if (func_021C815C(b) == 0 || func_021C815C(b) == 3) {
        if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(n) == 0)
            BTL_EVENT_OverwriteVar(n, 26);
    }
}
