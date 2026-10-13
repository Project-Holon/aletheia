/*
 * function: func_021D8D40
 * address:  0x021D8D40
 * packet:   pkt_ov093_021D8D40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D8D9C  0x021D8D9C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D8D9C(void *a, int k, u8 *buf, int v);
extern int WAZA_TOOL_GetDamageType(int a);
extern void func_021D7704(int a, int b);

void func_021D8D40(int u, int a, int b, int c)
{
    if (b == func_021D775C(3)) {
        if (func_021D8D9C((void *)a, b, (u8 *)c, 0x39) != 0 || func_021D8D9C((void *)a, b, (u8 *)c, 0x3a) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)func_021D775C(0x12)) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}
