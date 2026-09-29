/*
 * function: func_021B5DD0
 * address:  0x021B5DD0
 * packet:   pkt_ov021_021B5DD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves no lr), called by func_021B5DF8.
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a; u16 b; } Ent;

u32 func_021B5DD0(Ent *t, int k)
{
    int i;
    u32 th;

    for (i = 0; ; i++) {
        th = t[i].a;
        if (th == 0)
            return t[i].b;
        if (k <= (int)th)
            return t[i].b;
    }
}
