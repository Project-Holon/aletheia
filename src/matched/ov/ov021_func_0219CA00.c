/*
 * function: func_0219CA00
 * address:  0x0219CA00
 * packet:   pkt_ov021_0219CA00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDD70  0x021DDD70  data ov021 a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern unsigned char d_021DDD70[];

void func_0219CA00(u32 *s, u32 n, u32 heap)
{
    u16 *p = (u16 *)func_02030734(heap, n * 8, 1, (const char *)d_021DDD70, 0x484);
    s[0] = n;
    s[1] = (u32)p;
    do {
        p[0] = 0xFFFF;
        p[1] = 0xFFFF;
        p += 4;
    } while (--n);
}
