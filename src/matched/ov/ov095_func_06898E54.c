/*
 * function: func_06898E54
 * address:  0x06898E54
 * packet:   pkt_ov095_06898E54
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06898EA4  0x06898EA4  thumb  ov095
 *   func_06898EB4  0x06898EB4  thumb  ov095
 *   func_06898EC4  0x06898EC4  thumb  ov095
 *   func_06898ED4  0x06898ED4  thumb  ov095
 *   func_06898EE4  0x06898EE4  thumb  ov095
 *   func_06898EF4  0x06898EF4  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_06898EA4(int k);
extern int func_06898EB4(int k);
extern int func_06898EC4(int k);
extern int func_06898ED4(int k);
extern int func_06898EE4(int a);
extern void func_06898EF4(int k, int v);

void func_06898E54(int a, int b, int c)
{
    u8 t = func_06898EA4(4);

    if (b == func_06898EB4(t) && c == func_06898EC4(0x1a) && func_06898ED4(0x45) == 0) {
        int r = func_06898EE4(a);

        func_06898EF4(0x35, (r == 0 || r == 3) ? 0x800 : 0xa8f);
    }
}
