/*
 * unit:     yes
 * function: func_021D9ADC, func_021D9B34
 * address:  0x021D9ADC
 * packet:   pkt_ov093_021D9ADC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0878     0x021F0878  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021D775C(int);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F0878[];

void func_021D9ADC(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(2)) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            if (func_021D85C0((int)b, 0x21)) {
                p = func_021C88A4(b, 0xb, c);
                *(u32 *)p |= 0x800000;
                *(u32 *)p |= 0x2000000;
                *(int *)(p + 4) = 0x24;
                p[8] = c;
                p[0x14] = 1;
                func_021C88C8(b, p);
            }
        }
    }
}

int *func_021D9B34(int *p)
{
    *p = 1;
    return d_021F0878;
}
