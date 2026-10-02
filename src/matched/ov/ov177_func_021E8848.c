/*
 * function: func_021E8848
 * address:  0x021E8848
 * packet:   pkt_ov177_021E8848
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    char pad0[0x10];
    int  f10;
    int  f14;
    char pad1[0x18];
    int  f30;
} S;

extern void func_0202F038(int);
extern void func_02045374(int);
extern int  func_02045730(int);
extern void func_020409B4(int);

void func_021E8848(S *p)
{
    p->f30 = 1;
    if (p->f10 != 0) {
        func_0202F038(p->f10);
        p->f10 = 0;
        func_02045374(p->f14);
        func_020409B4(func_02045730(p->f14));
    }
}
