/*
 * function: func_021E8744
 * address:  0x021E8744
 * packet:   pkt_ov093_021E8744
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8434  0x021C8434  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021B9A24(u32 a, u32 b);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int func_021D76BC(int key, u32 val);
extern void func_021C8434(u8 *p, int a, int b);

void func_021E8744(int u, void *a, int b, int d)
{
    u8 k;
    u16 m;

    k = func_021D775C(2);
    if (func_021B9A24(k, b) == 0) {
        m = func_021D775C(0x12);
        if (WAZA_TOOL_GetCategory(m) == 0xb) {
            if (WAZA_TOOL_GetFlag(m, 4) != 0) {
                if (func_021D76BC(0x22, 0x19) != 0)
                    func_021C8434(a, b, k);
            }
        }
    }
}
