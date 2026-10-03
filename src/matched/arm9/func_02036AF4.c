/*
 * function: func_02036AF4
 * address:  0x02036AF4
 * packet:   pkt_020369F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   str_020A79C4  0x020A79C4  data
 *   func_02082BCC 0x02082BCC  arm
 *   func_02030734 0x02030734  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

extern u8 str_020A79C4[];
extern void func_02082BCC(void *dst, u32 val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void func_02036AF4(u8 *p, u32 n, u32 a, u32 b)
{
    func_02082BCC(p, 0, 0x28);
    *(u32 *)(p + 0x18) = (u32)func_02030734(b, n * 0x14, 1, (const char *)str_020A79C4, 0x173);
    *(u32 *)(p + 0x1c) = n;
    *(u32 *)(p + 0x14) = a;
}
