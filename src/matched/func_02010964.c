/*
 * function: func_02010964
 * address:  0x02010964
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010964.c \
 *       --func func_02010964 --addr 0x02010964 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_020399A8(void);
extern void func_02039C68(u32 h, u32 a, u32 b);
extern u32  func_02012DD0(u32 v);
extern u32  func_020056EC(u32 v);
extern void func_02010888(u8 *p, u32 v);
extern void func_02010994(u8 *p);

void func_02010964(u8 *p)
{
    if (func_02012DD0(*(u32 *)(p + 0xc)) == 1) {
        func_02039C68(func_020399A8(), 0x72, 8);
        *(u32 *)(p + 0x10) = func_020056EC(0x3c);
        func_02010888(p, (u32)func_02010994);
    }
}
