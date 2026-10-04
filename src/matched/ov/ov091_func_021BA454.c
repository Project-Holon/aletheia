/*
 * function: func_021BA454
 * address:  0x021BA454
 * packet:   pkt_ov091_021BA454
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_021BA65C  0x021BA65C  thumb  ov091
 *   func_021BA688  0x021BA688  thumb  ov091
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021BB2C0  0x021BB2C0  thumb  ov091
 *   func_021B7B98  0x021B7B98  thumb  ov091
 *   func_021B9E20  0x021B9E20  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021BB7A4(void *p, u32 *s);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_021BA65C(u8 *p, u16 id);
extern u32 func_021BA688(u8 *p, u16 id);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_021B7B98(u8 *a);
extern void func_021B9E20(u8 *p);

void func_021BA454(u8 *a, int k)
{
    func_021BB7A4(a, (u32 *)(*(int *)(a + 0x150)));
    if (k == 0xe) {
        int v = func_02017E1C((void *)*(int *)(a + 0x38), 6, 0);

        if (func_021BA65C(a, v) == 0x3e7) {
            func_021B9788(a, 0x3f, 1, (int)func_021B9E20);
            return;
        }
        func_021BA688(a, v);
        func_02017E40((void *)(*(int *)(a + 0x38)), 6, 0);
        func_021BB2C0(a, (u8 *)(*(int *)(a + *(int *)(a + 0x2c) * 4 + 0x160)));
        func_021B9788(a, 0x1f, 1, (int)func_021B9E20);
    } else {
        func_021BB7A4(a, (u32 *)(*(int *)(a + 0x150)));
        a[0xc] = 2;
        func_021B7B98(a);
    }
}
