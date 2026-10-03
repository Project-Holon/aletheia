/*
 * function: func_021BCFB4
 * address:  0x021BCFB4
 * packet:   pkt_ov099_021BCFB4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void func_0201DD68(void);
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern void func_021BAAB8(char *p, int a, int b);

int func_021BCFB4(char *p, int v)
{
    int r;

    func_0201DD68();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        *(u32 *)(p + 0x1CC) = 0x62;
        func_021BA8EC(p);
    } else {
        if ((unsigned)(*(int *)(p + 0x135C) - 1) <= 1) {
            *(u8 *)(p + 0x1353) = 0x4A;
            func_021BAAB8(p, 0x4A, 0);
        } else {
            *(u8 *)(p + 0x1353) = 0x90;
        }
        *(u32 *)(p + 0x1CC) = 0x8A;
    }
    return v;
}
