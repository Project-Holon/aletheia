/*
 * function: func_0203B950
 * address:  0x0203B950
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
 *   python tools/match.py one --src src/matched/func_0203B950.c \
 *       --func func_0203B950 --addr 0x0203B950 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02039338(void);
extern void func_0203BCE0(u8 *p);

void func_0203B950(u8 *p)
{
    if (func_02039338() != 0) {
        func_0203AD80((u32)g_021469DC, 0x0203B758, 0, 0x383);
        return;
    }

    if (p[0x56] == 2)
        return;

    if (*(u16 *)(p + 0x46) != 0) {
        (*(u16 *)(p + 0x46))--;
        return;
    }

    func_0203AD80((u32)g_021469DC, 0x0203BCE0, 0, 0x390);
    func_0203BCE0(p);
}
