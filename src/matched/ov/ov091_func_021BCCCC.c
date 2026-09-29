/*
 * function: func_021BCCCC
 * address:  0x021BCCCC
 * packet:   pkt_ov091_021BCCCC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BCE84  0x021BCE84  thumb  ov091
 *   func_021BCEAC  0x021BCEAC  thumb  ov091
 *   func_021BD05C  0x021BD05C  thumb  ov091
 *   func_021BD59C  0x021BD59C  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021BCE84(int);
extern void func_021BCEAC(int);
extern int func_021BD05C(int, int, int, int, int);
extern void func_021BD59C(int);

void func_021BCCCC(int p)
{
    int r;
    func_021BCE84(p);
    func_021BCEAC(p);
    r = *(int *)(p + 0x280);
    if (*(int *)(r + 0x8c) == 1) {
        switch (*(int *)(r + 0x64)) {
        case 1:
            *(int *)(p + 0x1f4) = func_021BD05C(p, r + 0x74, 10, 0, 2);
            break;
        case 2:
            *(int *)(p + 0x1f0) = func_021BD05C(p, r + 0x68, 0, 0, 0);
            *(int *)(p + 0x1f4) = func_021BD05C(p, *(int *)(p + 0x280) + 0x74, 0xb, 0, 0);
            *(int *)(p + 0x1f8) = func_021BD05C(p, *(int *)(p + 0x280) + 0x80, 0x16, 0, 0);
            break;
        }
    }
    r = *(int *)(p + 0x280);
    *(u8 *)(p + 0x20c) = *(u8 *)(r + 0x94);
    *(u8 *)(p + 0x20d) = 0;
    if (*(int *)(r + 0x90) == 1) {
        func_021BD59C(p);
    }
    *(u16 *)(p + 0x24e) = 0;
}
