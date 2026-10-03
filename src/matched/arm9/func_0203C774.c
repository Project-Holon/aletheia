/*
 * function: func_0203C774
 * address:  0x0203C774
 * packet:   pkt_0203C65C
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
 *   python tools/match.py one --src src/matched/func_0203C774.c \
 *       --func func_0203C774 --addr 0x0203C774 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern void *func_0203D788(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern int func_020351A0(u32 v);

void func_0203C774(u32 v)
{
    u8 *s;

    if (g_021469DC == 0)
        return;

    s = func_0203D788();
    func_020351A0(1);
    *(u32 *)(g_021469DC + 0x28) = v;
    (*(void (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(1, 0);

    func_0203AD80((u32)g_021469DC, 0x0203C710, 5, 0x719);
}
