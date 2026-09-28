/*
 * function: func_0203C238
 * address:  0x0203C238
 * packet:   pkt_0203C0F4
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
 *   python tools/match.py one --src src/matched/func_0203C238.c \
 *       --func func_0203C238 --addr 0x0203C238 --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;
extern u8 *func_0203D788(void);
extern u8 *func_0203D798(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern void func_02037D78(void);
extern void func_020398B4(u32 a);
extern void func_02039834(u32 a);

void func_0203C238(s8 *p)
{
    u8 *s = func_0203D788();
    u8 *q = func_0203D798();

    if ((*(u32 (**)(int, u32, u32))(*(u32 *)(s + 0x340) + 0x50))(p[0x48], q[0x60], 0) != 0)
        return;

    func_02037D78();
    func_020398B4((u32)s);
    func_02039834((u32)s);
    func_0203AD80((u32)g_021469DC, 0x0203C0F4, 0, 0x5AC);
}
