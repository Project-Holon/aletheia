/*
 * function: func_021E34B4
 * address:  0x021E34B4
 * packet:   pkt_ov093_021E34B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021E8744  0x021E8744  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021E8624(void *p, int key);
extern void func_021D76BC(int key, int v);
extern int func_021B9A24(int a, int b);
extern void func_021E8744(int a, void *b, int c, int d);

void func_021E34B4(int u, void *p, int key, int o)
{
    u8 v = func_021D775C(2);
    if (v == key) {
        if (func_021E8624(p, key) != 0) {
            func_021D76BC(0x22, 0x1a);
            return;
        }
    } else if (func_021B9A24(key, v) == 0) {
        func_021E8744(u, p, key, o);
    }
}
