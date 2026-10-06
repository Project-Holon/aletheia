/*
 * function: func_0203B90C
 * address:  0x0203B90C
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
 *   python tools/match.py one --src src/matched/func_0203B90C.c \
 *       --func func_0203B90C --addr 0x0203B90C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern u8 *func_0203D788(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);

void func_0203B90C(void)
{
    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0x78))() == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B6EC, 0, 0x371);
}
