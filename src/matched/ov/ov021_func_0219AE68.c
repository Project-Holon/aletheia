/*
 * function: func_0219AE68
 * address:  0x0219AE68
 * packet:   pkt_ov021_0219AE68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   d_021D4F90     0x021D4F90  data    a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

extern int func_02197EDC(int a);
extern u16 func_0216D5A0(int a);
extern int func_0216E0E8(int a0, int a1);
extern void func_0216DA50(int a);
extern u16 d_021D4F90[];

int func_0219AE68(int a, s8 *b)
{
    u16 *p;
    u32 id;
    u32 r4;
    u32 v;
    int t;

    if (func_02197EDC(a) == 1) {
        r4 = 0xff;
        v = func_0216D5A0(a);
        p = d_021D4F90;
        id = 0x25;
        do {
            if (id == v) {
                r4 = p[1];
            } else if (p[1] == v) {
                r4 = id;
            }
            if (r4 != 0xff) {
                t = 4 - (b[1] + 1);
                func_0216E0E8(a, r4);
                b[1] = t;
                break;
            }
            p += 2;
            id = p[0];
        } while (id != 0xff);
        func_0216DA50(a);
        b[0] = 2;
    }
    return 0;
}
