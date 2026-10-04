/*
 * function: func_021CE81C
 * address:  0x021CE81C
 * packet:   pkt_ov021_021CE81C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190490  0x02190490  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02188C54(u8 *p);
extern int func_02190728(u32 a);
extern void func_02190490(u8 *p);

void func_021CE81C(u32 *p)
{
    u32 h = func_02188C54((u8 *)p[0]);

    if (p[4] != 0) {
        func_02190728(p[4]);
        p[4] = 0;
    }
    if (p[3] != 0) {
        func_02190728(p[3]);
        p[3] = 0;
    }
    func_02190490((u8 *)h);
}
