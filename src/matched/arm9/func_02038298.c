/*
 * function: func_02038298
 * address:  0x02038298
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_02038AE0  0x02038AE0  arm
 *
 * Third entry of this packet's chain, and the one that shows why the object
 * word has to be re-read rather than cached: 0x021469D0 is a pointer word and
 * every use of the object it points at goes back through the pool address, so
 * the C indexes g_021469D0 directly each time.
 *
 * The state machine is three bytes of the object (0x1E7 = "armed", 0x1ED =
 * "in flight", 0x1D5 = a mode byte feeding 0x02038AE0): returning early
 * unless armed, arming the in-flight flag once 0x02038AE0 agrees, and only
 * then running the object's +0x64 entry, which clears the flag when it
 * returns non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038298.c \
 *       --func func_02038298 --addr 0x02038298 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_021469D0;
extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern u32 func_0203D6BC(void);
extern u32 func_02038AE0(u32 a, u8 *b, u32 c, u32 d);

void func_02038298(void)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();
    v = func_0203D6BC();

    if (*(u8 *)(g_021469D0 + 0x1E7) == 0)
        return;
    if (*(u8 *)(g_021469D0 + 0x1ED) == 0) {
        if (func_02038AE0(*(u32 *)g_021469D0, g_021469D0 + 0xCC,
                          func_0203D6BC(),
                          *(u8 *)(g_021469D0 + 0x1D5)) != 0)
            *(u8 *)(g_021469D0 + 0x1ED) = 1;
    }

    if (*(u8 *)(g_021469D0 + 0x1ED) != 1)
        return;
    if (((u32 (*)(u32, u32, u32, u32))
             * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(*(u32 *)g_021469D0, v,
                                                    0, 0) == 0)
        return;
    *(u8 *)(g_021469D0 + 0x1ED) = 0;
}
