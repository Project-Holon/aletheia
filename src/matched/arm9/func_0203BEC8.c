/*
 * function: func_0203BEC8
 * address:  0x0203BEC8
 * packet:   pkt_0203BEC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_0203AEEC   0x0203AEEC  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEC8.c \
 *       --func func_0203BEC8 --addr 0x0203BEC8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern void func_0203AEEC(u8 *p);

void func_0203BEC8(u8 *p)
{
    u8 *s;

    func_0203D798();
    s = func_0203D788();

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x78))() != 0) {
        if ((*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0) == 0)
            return;
        func_0203AEEC(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x6C))() != 0)
        return;
    if ((*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0) == 0)
        return;
    func_0203AEEC(p);
}
