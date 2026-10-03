/*
 * function: func_02173C64
 * address:  0x02173C64
 * packet:   pkt_ov012_02173C64
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02034714  0x02034714  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02034714(const char *expr, u32 line, const char *file);

void func_02173C64(int a, int b, u32 *value, u8 *p)
{
    u8 *q;
    q = *(u8 **)(p + 0x355C);
    if (q == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    q[0xDE] = *value;
}
