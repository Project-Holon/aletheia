/*
 * function: func_021E612C
 * address:  0x021E612C
 * packet:   pkt_ov093_021E612C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021D76BC(int key, u32 val);

void func_021E612C(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021D5BDC(func_021C7CF4(b, c), 0) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}
