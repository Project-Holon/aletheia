/*
 * function: func_021C0398
 * address:  0x021C0398
 * packet:   pkt_ov021_021C0398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C77D8  0x021C77D8  thumb  ov021
 *   func_021C7814  0x021C7814  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { u32 w[8]; } Blk32;

extern u32 func_02188CB4(u32 a);
extern u32 func_02188C58(u32 a);
extern u32 func_02188D38(u32 a);
extern u32 func_021C7260(u32 a, u32 b, u32 c);
extern u32 func_021C71D4(u32 a, u32 b, u32 c);
extern u32 func_021C77D8(u32 a, u32 b);
extern u32 func_021C7814(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021C6DE0(u32 a, u32 b, u32 c);
extern void func_020061E4(u32 a);
extern u32 func_0218FE80(u32 a);
extern void func_0218FEA0(u32 a, u8 *b);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, u8 *b);
extern void func_0218FEC0(u32 a);
extern void func_0218FF00(u32 a);
extern int func_021C6E48(u32 a);
extern void func_0218FF20(u32 a);
extern void func_0218FE98(u32 a);

int func_021C0398(u32 task, int *st, u8 *p)
{
    u32 obj;
    u32 h;
    u32 d;
    u32 a;
    u32 b;
    u32 c;
    u32 e;

    obj = *(u32 *)(p + 4);
    func_02188CB4(obj);
    h = func_02188C58(*(u32 *)(p + 4));
    d = func_02188D38(obj);

    switch (*st) {
    case 0:
        a = func_021C7260(obj, 0x14, 3);
        b = func_021C71D4(obj, 0x14, 5);
        c = func_021C77D8(obj, 0x1e);
        e = func_021C7814(obj, 3, 0, 0x10, 1);
        func_021C6DE0(d, a, 0);
        func_021C6DE0(d, b, a);
        func_021C6DE0(d, c, 0);
        func_021C6DE0(d, e, c);
        if (*(u32 *)(p + 0x10) != 0)
            func_020061E4(0x6E7);
        else
            func_020061E4(0x676);
        b = func_0218FE80(obj);
        *(u32 *)(p + 0x24) = 0x3c;
        *(u32 *)(p + 0x68) = 1;
        *(u32 *)(p + 0x6c) = 1;
        *(u32 *)(p + 0x70) = b;
        func_0218FEA0(b, p + 0x24);
        func_0218FEA4(*(u32 *)(p + 0x70));
        func_0218FE78(h, p + 0x28);
        *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
        *(u32 *)(p + 0x4c) -= 0x64000;
        func_0218FEC0(*(u32 *)(p + 0x70));
        func_0218FF00(*(u32 *)(p + 0x70));
        *st = *st + 1;
        break;
    case 1:
        if (func_021C6E48(d))
            *st = *st + 1;
        break;
    case 2:
        func_0218FF20(*(u32 *)(p + 0x70));
        func_0218FE98(*(u32 *)(p + 0x70));
        return 1;
    }
    return 0;
}
