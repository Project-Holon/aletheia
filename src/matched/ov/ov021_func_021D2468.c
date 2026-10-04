/*
 * function: func_021D2468
 * address:  0x021D2468
 * packet:   pkt_ov021_021D2468
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_02008B94  0x02008B94  thumb
 *   func_02008B98  0x02008B98  thumb
 *   func_020056EC  0x020056EC  thumb
 *   d_021DD6D0     0x021DD6D0  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h[31];
} Tbl;

extern Tbl d_021DD6D0;

extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012EBC(u32 a);
extern u32 func_02008B08(u32 a);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u32 func_02008B94(u32 a);
extern u32 func_02008B98(u32 a);
extern u32 func_020056EC(u32 a);

int func_021D2468(u32 a, u32 b)
{
    u32 x, y, z, v, w, k;
    u16 *p6, *p4, *p5;
    Tbl t;

    x = (u32)func_0215A5E4((void *)b); /* int-typed on purpose: pointer local changes codegen */
    y = func_02159B10((void *)a, (void *)b);
    p6 = func_02159AE8((void *)a, (void *)b);
    p4 = func_02159AE8((void *)a, (void *)b);
    p5 = func_02159AE8((void *)a, (void *)b);
    t = d_021DD6D0;
    z = func_02008B08(func_02012EBC(x));
    v = func_021690D0(x);
    w = func_021690E0(x);
    k = func_02008B94(z);
    if (w == func_02008B98(z) && v == k) {
        *p6 = 0x34;
        *p4 = 0x53;
        *p5 = t.h[30];
    } else {
        u32 i = func_020056EC(y ? 0x1E : 0x16);
        *p6 = i + 0x16;
        *p4 = i + 0x35;
        *p5 = t.h[i];
    }
    return 0;
}
