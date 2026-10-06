/*
 * function: func_0203BDEC
 * address:  0x0203BDEC
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
 *   python tools/match.py one --src src/matched/func_0203BDEC.c \
 *       --func func_0203BDEC --addr 0x0203BDEC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

struct NetState;
extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern int func_0203CEAC(int a0);

void func_0203BDEC(void)
{
    u8 *p = func_0203D798();
    u8 *s = func_0203D788();

    if ((u8)(p[0x65] + 0xFD) <= 1) {
        if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0xAC))() != 0)
            return;
        func_0203CEAC(0);
    } else {
        u8 *s2 = func_0203D788();

        if (((*(u32 (**)(void))(*(u32 *)(s2 + 0x340) + 0x7C))() & 0xFFFE) != 0)
            return;
        func_0203CEAC(0);
    }
}
