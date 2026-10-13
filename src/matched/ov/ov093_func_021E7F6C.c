/*
 * function: func_021E7F6C
 * address:  0x021E7F6C
 * packet:   pkt_ov093_021E7F6C
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
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct S;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *p, u32 val);

void func_021E7F6C(int a, int b, int c)
{
    void *m;
    if (c == BTL_EVENT_GetVar(3)) {
        m = (void *)BTL_EVENT_GetVar(0x3f);
        BTL_EVENT_OverwriteVar(0x1d, 0x20);
        func_021C8838(m, 2, 1140);
        func_021C8860(m, BTL_EVENT_GetVar(4));
    }
}
