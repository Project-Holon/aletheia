/*
 * function: func_0215F714
 * address:  0x0215F714
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
* Build a packet header at `dst`: tag bytes 8, 2, then the byte-swapped
 * halfword at p+0xb0 and the byte-swapped word returned by func_0215EF48.
 * A null p returns -0x27.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0215EF48(void);

int func_0215F714(u8 *p, u8 *dst)
{
    u32 r;
    u16 t;

    if (p == 0)
        return -0x27;

    r = func_0215EF48();
    t = p ? *(u16 *)(p + 0xb0) : 0;
    t = r ? t : 0;

    dst[0] = 8;
    dst[1] = 2;
    *(u16 *)(dst + 2) = (u16)(((t >> 8) & 0xff) | ((t << 8) & 0xff00));
    *(u32 *)(dst + 4) = ((r >> 24) & 0xff) | ((r >> 8) & 0xff00)
                      | ((r << 8) & 0xff0000) | ((r << 24) & 0xff000000);
    return 0;
}
