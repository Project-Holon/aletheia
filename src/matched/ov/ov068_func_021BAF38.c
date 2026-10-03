/*
 * function: func_021BAF38
 * address: 0x021BAF38
 * packet: pkt_ov068_021BAF38
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021BAF46 writes hardware register 04000050.
 * symbols:
 *   func_021BA31C 0x021BA31C thumb ov068
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
extern int func_021BA31C(u8 *);
typedef unsigned int   u32;
extern void func_02040588(u32 which, u32 enable);
int func_021BAF38(u8 *p)
{
    if (func_021BA31C(p)) {
        *(volatile unsigned short *)0x04000050 = 0;
        func_02040588(3, 0);
        return 1;
    }
    return 0;
}
