/*
 * function: func_02039050
 * address:  0x02039050
 * packet:   pkt_02038D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   g_021469D0     0x021469D0  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039050.c \
 *       --func func_02039050 --addr 0x02039050 --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469D0;
extern void func_0203666C(u32 a);
extern u32 func_020365E8(u32 a);
extern u32 func_02037258(void);
extern void func_02038DF0(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_02039050(void)
{
    int i;
    u8 *p;

    if (g_021469D0 == 0)
        return;

    func_0203666C((u32)(g_021469D0 + 0x2C));

    for (i = 0; i < 4; i++) {
        if ((int)func_020365E8((u32)(g_021469D0 + 0x2C)) <= 0)
            return;

        p = g_021469D0;
        func_02038DF0((u32)(p + 0x2C), 0xFF, *(u32 *)(p + 0x18),
                      (u32)(p + 0x19C), func_02037258());
    }
}
