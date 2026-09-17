/*
 * function: func_02010994
 * address:  0x02010994
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010994.c \
 *       --func func_02010994 --addr 0x02010994 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_020399A8(void);
extern u32  func_02039CB4(u32 h, u32 a, u32 b);
extern void func_02010888(u8 *p, u32 v);
extern void func_020109B8(u8 *p);

void func_02010994(u8 *p)
{
    if (func_02039CB4(func_020399A8(), 0x72, 8) != 0) {
        func_02010888(p, (u32)func_020109B8);
    }
}
