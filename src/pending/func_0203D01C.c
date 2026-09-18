/*
 * function: func_0203D01C
 * address:  0x0203D01C
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * PARKED AT MATCH.  The six-case switch, its PC-relative table and both
 * shared arms reproduce exactly; the open sites are the two calls,
 * 0x0203C3B4 and 0x0203B2D0, and this function is the only caller of each
 * anywhere in the image.  0x0203C3B4 sits between this window's packets and
 * 0x0203B2D0 below its first one, so neither can be matched from here.
 *   blocker: single-caller callees 0x0203C3B4 and 0x0203B2D0
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D01C.c \
 *       --func func_0203D01C --addr 0x0203D01C --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *func_0203D788(void);
extern void func_0203C3B4(void);
extern void func_0203B2D0(u32 a);

void func_0203D01C(void)
{
    u8 *s = func_0203D788();

    switch (s[0x65]) {
    case 1:
    case 2:
        func_0203C3B4();
        return;
    case 0:
    case 5:
        func_0203B2D0(*(u16 *)(s + 0x56));
        return;
    default:
        return;
    }
}
