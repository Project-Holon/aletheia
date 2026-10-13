/*
 * function: func_021E8270
 * address:  0x021E8270
 * packet:   pkt_ov093_021E8270
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
 *   func_021C8288  0x021C8288  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C8288(u8 *p);

void func_021E8270(int a, void *b, int c)
{
    int v;

    if (c == BTL_EVENT_GetVar(3) && func_021C8288(b) == 1) {
        v = BTL_EVENT_GetVar(0x20);
        if (v == 1)
            v++;
        BTL_EVENT_OverwriteVar(0x20, v);
    }
}
