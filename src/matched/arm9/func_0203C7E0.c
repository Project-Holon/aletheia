/*
 * function: func_0203C7E0
 * address:  0x0203C7E0
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
 *   python tools/match.py one --src src/matched/func_0203C7E0.c \
 *       --func func_0203C7E0 --addr 0x0203C7E0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern u8 *func_0203D788(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern void func_0203C0DC(u8 *p, u32 v);

void func_0203C7E0(u8 *p)
{
    u8 *s = func_0203D788();
    int r = (*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);

    if (r < 0) {
        func_0203C0DC(p, (u32)r);
        func_0203AD80((u32)g_021469DC, 0x0203C05C, 0, 0x72E);
    } else if (r > 0) {
        func_0203AD80((u32)g_021469DC, 0x0203C464, 0, 0x737);
    }
}
