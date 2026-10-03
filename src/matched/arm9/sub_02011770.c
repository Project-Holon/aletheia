/*
 * function: sub_02011770
 * address:  0x02011770
 * packet:   pkt_020116E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g020A7270      0x020A7270  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u8    g020A7270[];

void sub_02011770(u8 *p, int n)
{
    *(u32 *)(p + 0x18) = (u32)n;
    if (*(u32 *)(p + 0x28) != 0) {
        *(u32 *)(p + 0x1c) = (u32)func_02030734((u32)*(u16 *)p, n * 0xc,
                                                  0, (const char *)g020A7270, 0x25c);
    }
    if (*(u32 *)(p + 0x2c) != 0) {
        *(u32 *)(p + 0x20) = (u32)func_02030734((u32)*(u16 *)p, n * 0xc,
                                                  0, (const char *)g020A7270, 0x260);
    }
    if (*(u32 *)(p + 0x30) != 0) {
        *(u32 *)(p + 0x24) = (u32)func_02030734((u32)*(u16 *)p, n * 0xc,
                                                  0, (const char *)g020A7270, 0x264);
    }
    *(u32 *)(p + 0x34) = 1;
}
