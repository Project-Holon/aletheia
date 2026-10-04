/*
 * function: func_021CE7AC
 * address:  0x021CE7AC
 * packet:   pkt_ov021_021CE7AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   data_021DB498  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Fx;
extern u32 func_02188C54(u8 *p);
extern void *func_02190708(struct Fx *p, u32 a, u32 b, u32 c, u16 d, u16 e);
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern u8 data_021DB498[];

void func_021CE7AC(u32 *p)
{
    u32 h;
    int k;

    h = func_02188C54((u8 *)p[0]);
    k = 0x10;
    if (*(u8 *)((u8 *)p + 0x51f)) {
        k = 0xe;
    }
    p[3] = (u32)func_02190708((struct Fx *)h, p[2], 2, 6, 0x12, k - 6);
    p[4] = (u32)func_02190708((struct Fx *)h, p[2], 2, 1, 0x1c, 2);
    func_02190740(p[4], 0, 0, *(u16 *)(data_021DB498 + *(u8 *)((u8 *)p + 0x520) * 12));
}
