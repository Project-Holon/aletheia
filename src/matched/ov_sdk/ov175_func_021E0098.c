/*
 * function: func_021E0098
 * address:  0x021E0098
 * packet:   pkt_ov175_021E0098
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0090  0x021E0090  arm  ov175
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021E0090(void *a0);

#define BS32(x) ((u32)((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                       (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000)))
#define BS16(x) ((u16)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))

int func_021E0098(u8 *p, int f, u32 v)
{
    u8 *q = *(u8 **)(p + 0x124);

    func_021E0090(p);
    if (f != 0)
        *(u32 *)(q + 0x1c) |= 1;
    *(u32 *)(q + 0x18) = BS32(v);
    *(u32 *)(q + 0x1c) = BS32(*(u32 *)(q + 0x1c));
    *(u16 *)(q + 0x20) = BS16(*(u16 *)(q + 0x20));
    *(u16 *)(q + 0x22) = BS16(*(u16 *)(q + 0x22));
    *(u16 *)(q + 0x2a) = 0;
    *(u16 *)(q + 0x24) = BS16(*(u16 *)(q + 0x24));
    *(u16 *)(q + 0x26) = BS16(*(u16 *)(q + 0x26));
    *(u16 *)(q + 0x28) = BS16(*(u16 *)(q + 0x28));
    *(u32 *)(q + 0x2c) = BS32(*(u32 *)(q + 0x2c));
    *(u32 *)(q + 0x30) = BS32(*(u32 *)(q + 0x30));
    *(u32 *)(q + 0x34) = BS32(*(u32 *)(q + 0x34));
    *(u32 *)(q + 0x38) = BS32(*(u32 *)(q + 0x38));
    *(u32 *)(q + 0x3c) = BS32(*(u32 *)(q + 0x3c));
    *(u32 *)(q + 0x40) = BS32(*(u32 *)(q + 0x40));
    return 0;
}
