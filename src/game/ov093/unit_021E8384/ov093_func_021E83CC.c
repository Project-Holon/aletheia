/*
 * function: func_021E83CC
 * address:  0x021E83CC
 * packet:   pkt_ov093_021E83CC
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
 *   func_021D6E50  0x021D6E50  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E8384  0x021E8384  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6E50(u8 *p, u8 *id, u16 *value);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021E8384(u32 x, u32 y);
extern int func_021D76BC(int key, u32 val);

void func_021E83CC(void *a, void *b, int c, int *d)
{
    u16 y;
    u8 x;
    int r;
    u8 k;

    if (c == func_021D775C(3)) {
        if (func_021D6E50(func_021C7CF4(b, c), &x, &y) != 0) {
            r = func_021E8384(func_021D70A8(a), y);
            k = func_021D775C(0x16);
            if (r != 0) {
                d[1] = r;
                d[0] = 1;
                d[2] = x;
                switch (r) {
                case 1:
                    k = 10;
                    break;
                case 2:
                    k = 9;
                    break;
                case 3:
                    k = 11;
                    break;
                }
                func_021D76BC(0x16, k);
            }
        }
    }
}
