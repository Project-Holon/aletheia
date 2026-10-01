/*
 * function: func_021A0EB0
 * address:  0x021A0EB0
 * packet:   pkt_ov021_021A0EB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D8738     0x021D8738  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    int (*init)(void *, u32);
    void (*fn)(void *);
    u8 rest[0x14];
} Entry;

extern Entry d_021D8738[];

int func_021A0EB0(u32 *p, u32 a)
{
    if (p[2] == 0 && d_021D8738[p[0]].init != 0)
        return d_021D8738[p[0]].init(p, a);
    return 0;
}
