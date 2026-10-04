/*
 * function: func_021EEE80
 * address:  0x021EEE80
 * packet:   pkt_ov093_021EEE80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 *   func_021EEEC8  0x021EEEC8  thumb  ov093
 *   d_021F39A0     0x021F39A0  data  a2
 *   d_021F6398     0x021F6398  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8BD0(unsigned char *p, unsigned char k);
extern void func_021EEEC8(u32 a, u32 b, u32 c);
extern const u16 d_021F39A0[];
extern void *d_021F6398;

void func_021EEE80(u32 a, u16 k, u32 *p)
{
    u32 i;

    for (i = 0; i < 27; i++) {
        if (k == d_021F39A0[i]) {
            if (func_021B8BD0(d_021F6398, (u8)*p) == 0)
                k = k + 1;
            break;
        }
    }
    func_021EEEC8(a, k, (u32)p);
}
