/*
 * function: func_021DDCD8
 * address:  0x021DDCD8
 * packet:   pkt_ov093_021DDCD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern u8 *func_021C7CF4(void *a, int b);
extern int func_021D6D7C(u8 *p);
extern void func_021D7704(int a, int b);
extern int func_021C7EC4(void *a);

int func_021DDCD8(int a, u8 *b, int c, int *d, u8 e, int f)
{
    if (c == func_021D775C(4) && e == func_021D775C(0x16)
        && (f != 0 || func_021D775C(0x38) > 3)
        && func_021D6D7C(func_021C7CF4(b, c)) == 0) {
        func_021D7704(0x35, 0x800);
        if (func_021C7EC4(b) == 0)
            *d = 1;
        return 1;
    }
    return 0;
}
