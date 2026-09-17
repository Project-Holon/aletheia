/*
 * function: func_020109E0
 * address:  0x020109E0
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020109E0.c \
 *       --func func_020109E0 --addr 0x020109E0 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_020399A8(void);
extern u32  func_02039CB4(u32 h, u32 a, u32 b);
extern void func_02010888(u8 *p, u32 v);
extern void func_02010A04(u8 *p);

void func_020109E0(u8 *p)
{
    if (func_02039CB4(func_020399A8(), 0x73, 8) != 0) {
        func_02010888(p, (u32)func_02010A04);
    }
}
