/*
 * function: func_021DD158
 * address:  0x021DD158
 * packet:   pkt_ov093_021DD158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D778C  0x021D778C  thumb  ov093
 *   func_021DD1D8  0x021DD1D8  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D778C(int key, int *out);
extern int func_021DD1D8(u8 *b, int c, int d);
extern void func_021DD044(void *a, void *b, int c);

void func_021DD158(u8 *a, u8 *b, int c, int d)
{
    int loc;
    if (c == func_021D775C(2)) {
        if (func_021D778C(0x2e, &loc) == 0 || loc == 3 || loc == 0) {
            if (func_021DD1D8(b, c, d) != 0)
                func_021DD044(a, b, c);
        }
    }
}
