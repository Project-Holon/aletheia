/*
 * function: func_0203BCE0
 * address:  0x0203BCE0
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BCE0.c \
 *       --func func_0203BCE0 --addr 0x0203BCE0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern u8 *func_0203D788(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);

void func_0203BCE0(void)
{
    u8 *s = func_0203D788();

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) == 0)
        return;

    func_0203AD80((u32)g_021469DC, 0x0203B90C, 0, 0x411);
}
