/*
 * function: func_021E70E4
 * address:  0x021E70E4
 * packet:   pkt_ov093_021E70E4
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
 *   func_021C83A0  0x021C83A0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021C83A0(u8 *p, int i);
extern u8 func_021D5440(u8 *p);
extern int func_021D76BC(int key, u32 val);

void func_021E70E4(int x, int a, int c)
{
    void *m;
    int p;
    int q;
    int r;
    int v;

    if (c == func_021D775C(3)) {
        func_021C7CF4((int *)a, c);
        m = func_021C7CF4((int *)a, (u8)func_021D775C(4));
        p = func_021C83A0((u8 *)a, c);
        q = func_021C83A0((u8 *)a, func_021D5440(m));
        r = p / q;
        if (r >= 5) {
            v = 0x78;
        } else if (r == 4) {
            v = 0x64;
        } else if (r == 3) {
            v = 0x50;
        } else {
            v = 0x3c;
            if (r != 2) {
                v = 0x28;
            }
        }
        func_021D76BC(0x30, v);
    }
}
