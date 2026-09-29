/*
 * function: func_021BC958
 * address:  0x021BC958
 * packet:   pkt_ov099_021BC958
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020200CC  0x020200CC  thumb
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *
 * Twins: func_021BCA14 (+0x22 byte, +0x134e halfword) and func_021BCAD0
 * (stores 1 - r at +0x20).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int func_02045770(int);
extern int func_0201C6C4(int a, int b);
extern void func_02045334(int);
extern int func_020200CC(int);
extern void func_021BA8EC(char *p);
extern void *func_021BA8BC(void *p);
extern void func_0202020C(int a, int b, void *c);
extern void func_0201F868(int);

int func_021BC958(char *p, int v)
{
    int r;
    int q;

    q = *(int *)(p + 0x1B8);
    if (*(u8 *)(p + 0x1B0) != 0) {
        if (func_0201C6C4(q, func_02045770(*(int *)(p + 0x1AC))) == 0) {
            func_02045334(*(int *)(p + 0x1AC));
            *(u8 *)(p + 0x1B0) = 0;
        }
    }
    r = func_020200CC(*(int *)(p + 0xbc));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        *(u16 *)(p + 0x134c) = r;
        *(u8 *)(*(char **)(p + 0x248) + 0x21) = r;
    }
    *(u32 *)(p + 0x1CC) = 0x4e;
    func_021BA8EC(p);
    *(void **)(p + 0x1A4) = func_021BA8BC(*(void **)(p + 0x1A4));
    func_0202020C(*(int *)(p + 0xbc), 0, p + 0x236);
    func_0201F868(*(int *)(p + 0xb8));
    return v;
}
