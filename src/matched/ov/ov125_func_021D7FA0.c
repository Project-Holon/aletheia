/*
 * function: func_021D7FA0
 * address: 0x021D7FA0
 * packet: pkt_ov125_021D7FA0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: port byte swap keeps both explicit masks; timeout casts after unsigned 64-bit subtraction, preserving the original subs before the signed comparison.
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021DA040 0x021DA040 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F480 0x0215F480 arm ov009
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u8 size, family; u16 port; u32 address; } Address;
extern u32 d_021D9E40[];
extern u8 d_021DA040[];
extern u64 OS_GetTick(void);
extern int func_0215F480(int, const Address *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
int func_021D7FA0(void)
{
    Address address;
    int start, result;
    address.size = 8;
    address.family = 2;
    address.port = ((*(u16 *)(d_021DA040 + 0x40) >> 8) & 0xff) | ((*(u16 *)(d_021DA040 + 0x40) << 8) & 0xff00);
    address.address = d_021D9E40[0x264/4];
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        result = func_0215F480(d_021D9E40[0x26c/4], &address);
        if (result >= 0) break;
        if (result == -26) {
            if (d_021D9E40[0x244/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)d_021D9E40[0x244/4]) {
                d_021D9E40[0x250/4] = 10;
                return 0;
            }
        } else {
            if (result == -30) break;
            d_021D9E40[0x250/4] = 7;
            return 0;
        }
        func_021D7CAC();
        if (d_021D9E40[0x268/4] == 1) {
            d_021D9E40[0x250/4] = 13;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
    return 1;
}
