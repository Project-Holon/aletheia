/*
 * function: func_021F7F58
 * address:  0x021F7F58
 * packet:   pkt_ov094_021F7F58
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   d_02209D0C     0x02209D0C  data   ov094  a1
 *   func_021F88F4  0x021F88F4  thumb  ov094
 *   func_021FF088  0x021FF088  thumb  ov094
 *   func_021FF144  0x021FF144  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern char *d_0220AF20;
extern u8 d_02209D0C[];
extern int func_021F88F4(void);
extern void func_021FF088(u32 obj, int a, u32 b);
extern void func_021FF144(u32 obj, u32 b, u32 c, u32 d, u32 e);

void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e)
{
    if (!(b & 1)) {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 4;
            break;
        case 0x3D:
            a = 2;
            break;
        case 0x25:
            a = 3;
            break;
        default:
            if (d_02209D0C[a] == 0)
                a = 0;
            else
                a = 1;
            break;
        }
    } else {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 0x67;
            break;
        }
    }
    func_021FF088(*(u32 *)(d_0220AF20 + 0x190), a, b);
    if (c != 0 || d != 0 || e != 0)
        func_021FF144(*(u32 *)(d_0220AF20 + 0x190), b, c, d, e);
    *(u32 *)(d_0220AF20 + (b - 8) * 4 + 0x1F8) = b;
}
