/*
 * function: func_021DE3FC
 * address:  0x021DE3FC
 * packet:   pkt_ov093_021DE3FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021DCFD0  0x021DCFD0  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021DCFF8(int a, int b);
extern int func_021DCFD0(int *a, unsigned int b);
extern int func_021D76BC(int key, u32 val);
extern void func_021DD044(void *a, void *b, int c);

void func_021DE3FC(int a, void *b, int c)
{
    u8 j;

    if (c == func_021D775C(2)) {
        j = func_021DCFF8(a, 2);
        if (func_021DCFD0(b, j) != 0 && func_021D76BC(0x11, 2) != 0)
            func_021DD044((void *)a, b, c);
    }
}
