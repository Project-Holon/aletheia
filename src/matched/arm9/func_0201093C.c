/*
 * function: func_0201093C
 * address:  0x0201093C
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201093C.c \
 *       --func func_0201093C --addr 0x0201093C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_020399A8(void);
extern u32  func_02039CB4(u32 h, u32 a, u32 b);
extern int func_02012DAC(int a0);
extern void func_02010888(u8 *p, u32 v);
extern void func_02010964(u8 *p);

void func_0201093C(u8 *p)
{
    if (func_02039CB4(func_020399A8(), 0x71, 8) != 0) {
        func_02012DAC(*(u32 *)(p + 0xc));
        func_02010888(p, (u32)func_02010964);
    }
}
