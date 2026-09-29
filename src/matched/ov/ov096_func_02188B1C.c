/*
 * function: func_02188B1C
 * address:  0x02188B1C
 * packet:   pkt_ov096_02188B1C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C(int);
extern void func_020113B0(int, int);

int func_02188B1C(int a, int b)
{
    u16 *p;
    int m;
    int i;
    int v;

    p = (u16 *)(*(int *)(a + 0x14) + func_0201134C(a));
    m = func_0201134C(a);
    i = 0;
    do {
        v = p[i] | (p[i + 1] << 16);
        if (*(int *)(b + 0x38) == v) {
            func_020113B0(a, *(int *)(a + 0x14) + m);
            break;
        }
        i += 2;
    } while (v != -1);
    return *(int *)(b + 0xc4);
}
