/*
 * function: func_0219EF14
 * address:  0x0219EF14
 * packet:   pkt_ov021_0219EF14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   d_021DDDB8     0x021DDDB8  data
 *   d_021DDDA0     0x021DDDA0  data
 *   d_021DDDAC     0x021DDDAC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern char d_021DDDB8[];
extern char d_021DDDA0[];
extern char d_021DDDAC[];
extern void func_02082BCC(void *, int, int);

void func_0219EF14(u8 *p)
{
    func_02082BCC(p, 0, 0x30);
    *(u16 *)(p + 8) = 0x14;
    *(u16 *)(p + 0xa) = 3;
    *(u16 *)(p + 0xc) = 3;
    *(void **)(p + 0x20) = d_021DDDB8;
    *(void **)(p + 0x24) = d_021DDDA0;
    *(void **)(p + 0x28) = d_021DDDAC;
}
