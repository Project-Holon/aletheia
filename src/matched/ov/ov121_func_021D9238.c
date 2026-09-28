/*
 * function: func_021D9238
 * address:  0x021D9238
 * packet:   pkt_021D9238
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_021D9238(char *p)
{
    if (*(u32 *)(p + 4) != 0 && *(u32 *)p != 0) {
        void (*fp)(char *) = *(void (**)(char *))(p + 0x11c);
        if (fp != 0)
            fp(p);
    }
}
