/*
 * function: func_021D846C
 * address:  0x021D846C
 * packet:   pkt_021D846C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202DC08  0x0202DC08  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0202DC08(void *);

void func_021D846C(u8 *p)
{
    if (*(void **)(p + 0xcc)) {
        func_0202DC08(*(void **)(p + 0xcc));
        *(u32 *)(p + 0xcc) = 0;
    }
}
