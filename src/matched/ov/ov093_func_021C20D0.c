/*
 * function: func_021C20D0
 * address:  0x021C20D0
 * packet:   pkt_ov093_021C20D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021C5B74(u8 *p, u8 *a, int c, int k);
extern void func_021D5FC0(u8 *a, int k);
extern void func_021C99A0(u8 *p, u8 *l);
extern void func_021C8810(u8 *l);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern int func_021C4F64(u8 *p, u8 *a);
extern int func_021BC2B0(u8 *p);

int func_021C20D0(u8 *p, u8 *a, int c, u8 *l)
{
    int r;
    c = -c;
    if (c != 0) {
        func_021C5B74(p, a, c, 1);
        func_021D5FC0(a, 2);
        if (l != 0) {
            func_021C99A0(p, l);
            func_021C8810(l);
        }
        r = 1;
        func_021C195C(p, a, 1);
        if (func_021C4F64(p, a) != 0) {
            func_021BC2B0(p);
            return r;
        }
        return r;
    }
    return 0;
}
