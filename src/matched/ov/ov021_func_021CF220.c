/*
 * unit:     yes
 * function: func_021CF220
 * function: func_021CF27C
 * address:  0x021CF220
 * packet:   pkt_ov021_021CF220
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021CF27C (unlabelled) is a tail-call stub into func_021CF110.
 *
 * symbols:
 *   func_0203996C  0x0203996C  arm
 *   func_02008468  0x02008468  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CF110  0x021CF110  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0203996C(u32);
extern int func_02008468(void);
extern u32 func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021CF110(u32, u32, u32);

void func_021CF220(u32 a, u32 flag, u32 c)
{
    u32 h;

    if (flag == 1) {
        h = func_0203996C(0xff);
        func_0203D3F8(h, a, 0x2701, func_02008468(), c, 0, 0, 0);
    } else {
        h = func_020399A8();
        func_0203D3F8(h, a, 0x2701, func_02008468(), c, 0, 0, 0);
    }
}

void func_021CF27C(u32 a, u32 b, u32 c, u32 d)
{
    func_021CF110(d, 2, c);
}
