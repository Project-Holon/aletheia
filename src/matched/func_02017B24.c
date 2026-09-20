/*
 * function: func_02017B24
 * address:  0x02017B24
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02017B24.c \
 *       --func func_02017B24 --addr 0x02017B24 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32  func_02017D30(void *p);
extern void func_02017B4C(void *p, u32 a, u32 b, u32 c);
extern void func_02017D70(void *p, u32 v);

void func_02017B24(void *p, u32 a, u32 b, u32 c)
{
    u8 v = (u8)func_02017D30(p);

    func_02017B4C(p, a, b, c);
    func_02017D70(p, v);
}
