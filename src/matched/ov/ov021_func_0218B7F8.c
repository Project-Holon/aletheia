/*
 * function: func_0218B7F8
 * address:  0x0218B7F8
 * packet:   pkt_ov021_0218B7F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C860  0x0218C860  thumb
 *   func_0218BE84  0x0218BE84  thumb
 *   func_0218BD94  0x0218BD94  thumb
 *   func_0218BB64  0x0218BB64  thumb
 *   func_0218BC6C  0x0218BC6C  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

extern void func_0218C860(void *p);
typedef unsigned char  u8;
extern void func_0218BE84(u8 *s, u8 *e);
extern void func_0218BD94(u8 *s);
extern int func_0218BB64(char *a);
extern void func_0218BC6C(unsigned char *p);
extern void func_020307B0(void *p);

void func_0218B7F8(char *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (*(void **)(p + 0x1DC + i * 4) != 0)
            func_0218C860(*(void **)(p + 0x1DC + i * 4));
    }
    func_0218BE84((u8 *)p, (u8 *)(p + 0x1B0));
    func_0218BD94((u8 *)p);
    func_0218BB64(p);
    func_0218BC6C((unsigned char *)p);
    func_020307B0(p);
}
