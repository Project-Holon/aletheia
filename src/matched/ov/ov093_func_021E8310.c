/*
 * function: func_021E8310
 * address:  0x021E8310
 * packet:   pkt_ov093_021E8310
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C812C  0x021C812C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   func_021E8374  0x021E8374  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern u8 *func_021C812C(u8 *p);
struct Q7;
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern int func_021E8374(int a, int b);
extern void func_021D7704(int a, int b);
extern void func_021C83DC(char *p, int x);

void func_021E8310(void *a, void *b, int c)
{
    int m;
    int t;

    if (c == func_021D775C(3)) {
        m = (int)func_021C812C(b);
        switch (func_021D70A8(a)) {
        case 0x22e:
            t = 0x22f;
            break;
        case 0x22f:
            t = 0x22e;
            break;
        default:
            t = 0;
            break;
        }
        if (t != 0 && t == func_021E8374(m, func_021C8138(b))) {
            func_021D7704(0x31, 0x2000);
            func_021C83DC(b, 1);
        }
    }
}
