/*
 * function: func_0203D7C8
 * address:  0x0203D7C8
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Allocates size rounded up to 0x20 plus 0x20, rounds the result up to a
 * 0x20 boundary and stores the raw pointer in the word just before the
 * aligned block, which func_0203D7FC releases it by.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D7C8.c \
 *       --func func_0203D7C8 --addr 0x0203D7C8 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *func_02030734(u32 a, u32 b, int clear, const char *site, u16 tag);

void *func_0203D7C8(u32 a, u32 size, const char *c, u16 d)
{
    u8 *p = (u8 *)func_02030734(a, ((size + 0x24) & ~0x1fu) + 0x20, 1, c, d);
    u8 *q = (u8 *)(((u32)p + 0x20) & ~0x1fu);

    *(void **)(q - 4) = p;
    return q;
}
