/*
 * function: func_021E8070
 * address:  0x021E8070
 * packet:   pkt_ov093_021E8070
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8494  0x021C8494  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern int func_021C7D00(u8 *p, int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C8494(u8 *p, int i);

void func_021E8070(int a, void *b, int c)
{
    u8 v, t;
    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_POKEPARAM_GetCounter(func_021C7CF4(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t == 0x1f || func_021C7D00(b, t) == 6)
            BTL_EVENT_OverwriteVar(0x41, 1);
        func_021C8494(b, c);
    }
}
