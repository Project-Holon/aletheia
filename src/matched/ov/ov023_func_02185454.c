/*
 * function: func_02185454
 * address:  0x02185454
 * packet:   pkt_ov023_02185454
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020278F4  0x020278F4  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_021864A8  0x021864A8  thumb  ov023
 *   func_02186660  0x02186660  thumb  ov023
 *   func_02184560  0x02184560  thumb  ov023
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Bits;

typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern u32  func_02045730(u32 a);
extern void func_020409B4(u32 a);
extern void func_020278F4(u8 *p);
extern void func_020061E4(u32 a);
extern void func_0201F7A8(u32 a, int b);
extern void func_021852F4(u32 a, int b);
extern void func_02185354(char *p);
extern void func_021861C4(char *p, int a, int b);
extern void func_02186444(char *p, u32 v);
extern int  func_021864A8(char *p);
extern int  func_02186660(char *p);
extern void func_02184560(char *p, int a);

int func_02185454(char *p, int x)
{
    u32 w;

    ((Bits *)(p + 0x4210))->mid = 0;
    if (*(u8 *)(p + 0x4217) == 2 && func_02039338() != 0) {
        func_02185354(p);
        func_020278F4(*(void **)(p + 0x178));
        if (func_021864A8(p))
            func_020061E4(0x54b);
        return x;
    }
    if (func_02039338() == 0 && *(int *)(p + 0x9280) != 0) {
        func_02185354(p);
        func_020278F4(*(void **)(p + 0x178));
        return x;
    }
    switch (func_02186660(p)) {
    case 0:
        if (func_02039338() == 0) {
            func_02186444(p, 0xf);
            func_021861C4(p, 4, 1);
        } else {
            func_02186444(p, 8);
            func_0201F7A8(*(u32 *)(p + 0x11c), 2);
        }
        w = *(u32 *)(p + 0x118);
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4(*(u32 *)(p + 0x100), 0);
        func_0201F7A8(*(u32 *)(p + 0x11c), 2);
        w = *(u32 *)(p + 0x118);
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            *(int *)(p + 0x9e6c) = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}
