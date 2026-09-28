/*
 * function: func_0215AE34
 * address:  0x0215AE34
 * packet:   pkt_ov010_0215AE34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159F28  0x02159F28  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02012974  0x02012974  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013B44  0x02013B44  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_0215A5E4();
extern int func_0215A5CC();
extern int func_02159B10();
extern int func_02159F28();
extern int func_02159B94();
extern int func_02159CC4();
extern int func_02012974();
extern int func_020127A4();
extern int func_02012AC8();
extern int func_02013B44();

int func_0215AE34(int a0, int a1)
{
    int v0 = func_0215A5DC(a1);
    int p = func_0215A5E4(a1);
    int x = func_02159B10(a0, a1);
    int y = func_02159B10(a0, a1);
    int flag = func_02159B10(a0, a1);
    int q, r, s, t;
    func_02159F28(p, x, y);
    if (flag != 0) {
        q = func_02012974(p);
        func_020127A4(p);
        r = func_02012AC8();
        s = func_02013B44();
        t = func_0215A5CC(a1);
        func_02159B94(q, s, r, t);
        func_02159CC4(q, v0, t);
    }
    return 0;
}
