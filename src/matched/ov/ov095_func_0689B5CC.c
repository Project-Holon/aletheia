/*
 * function: func_0689B5CC
 * address:  0x0689B5CC
 * packet:   pkt_ov095_0689B5CC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689B63C  0x0689B63C  thumb  ov095
 *   func_0689B64C  0x0689B64C  thumb  ov095
 *   func_0689B65C  0x0689B65C  thumb  ov095
 *   d_0689D88C     0x0689D88C  data   ov095
 *   d_0689DC48     0x0689DC48  data   ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0689B63C(u32 h, void *a, void *b);
extern void func_0689B64C(u32 h, int a, int b);
extern int func_0689B65C(u32 h);
extern char d_0689D88C[];
extern char d_0689DC48[];

int func_0689B5CC(u8 *s, u32 *out)
{
    int i;

    switch (s[0x93]) {
    case 0:
        i = func_0689B63C(*(u32 *)(s + 0xb0), d_0689D88C, d_0689DC48);
        if (i == -1)
            break;
        *(int *)(s + 0x94) = i;
        func_0689B64C(*(u32 *)(s + 0xb0), 0, 0);
        s[0x93] = s[0x93] + 1;
        break;
    case 1:
        if (func_0689B65C(*(u32 *)(s + 0xb0)) == 0) {
            *out = *(u32 *)(s + 0x94);
            return 1;
        }
        break;
    }
    return 0;
}
