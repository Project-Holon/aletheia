/*
 * function: func_021A0D44
 * address:  0x021A0D44
 * packet:   pkt_ov021_021A0D44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
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

extern u32 func_020307B0(void *p);

u8 func_021A0D44(u32 *p)
{
    u32 id = p[0];
    d_021D8738[id].fn(p);
    func_020307B0(p);
    return id;
}
