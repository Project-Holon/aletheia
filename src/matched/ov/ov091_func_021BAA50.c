/*
 * function: func_021BAA50
 * address:  0x021BAA50
 * packet:   pkt_ov091_021BAA50
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0201BBE8  0x0201BBE8  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201AB28(int base, int idx);
extern int func_020185F4(int x);
extern int func_0201BA68(int x);
extern int func_0204A6C8(u32 a, int b, int c, int d, u16 e);
extern void func_02049238(u32 a);
extern int func_0201BBE8(int x);
extern int func_0204B294(int a, int b, int c, int d, R *r, int f, u16 g);
extern void func_0204B6F4(int a, int b, int c);
extern void func_0204B92C(int a, int b);

void func_021BAA50(u8 *a, u8 *s)
{
    void *h;
    int t;
    int r;
    R rc;

    h = func_020490F4(7, *(u16 *)a);
    t = func_020185F4(func_0201AB28(**(int **)(a + 0x280), s[4]));
    *(int *)(s + 0x2c) = func_0204A6C8(h, func_0201BA68(t), 0, 0, *(u16 *)a);
    func_02049238(h);
    r = func_0201BBE8(t);
    rc.a = 0x18;
    rc.b = 0x10;
    rc.c = 1;
    rc.d = 0;
    rc.e = 2;
    {
        int x = func_0204B294(*(int *)(s + 0x28), *(int *)(s + 0x2c), *(int *)(a + 0x190),
                              *(int *)(a + 0x1d0), &rc, 0, *(u16 *)a);
        *(int *)(s + 0x30) = x;
        func_0204B6F4(x, r, 1);
    }
    func_0204B92C(*(int *)(s + 0x30), 1);
}
