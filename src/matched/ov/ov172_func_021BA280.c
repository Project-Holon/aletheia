/*
 * function: func_021BA280
 * address:  0x021BA280
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0x98-byte record and seeds its counters.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);

void func_021BA280(void *a, void *b)
{
    char *v = func_02030734((u32)b, 0x98, 1, (void *)0x021C7228, 0xcf);

    v[0x36] = 0;
    v[0x37] = 3;
    *(u32 *)(v + 0x28) = 0;
    *(u32 *)(v + 0x24) = 0;
    *(u16 *)(v + 0x34) = 0x8000;
}
