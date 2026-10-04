/*
 * function: func_02010A04
 * address:  0x02010A04
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010A04.c \
 *       --func func_02010A04 --addr 0x02010A04 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern int  func_02012DD0(u8 *p);
extern void func_02010888(u8 *p, u32 v);
extern void func_02010A3C(u8 *p);

void func_02010A04(u8 *p)
{
    if (*(u32 *)p != 0) {
        ((void (*)(u32)) * (u32 *)p)(*(u32 *)(p + 4));
    }
    if (func_02012DD0(*(u8 **)(p + 0xc)) == 2) {
        *(u32 *)(p + 0xc) = 0;
        func_02039C68((struct Link *)func_020399A8(), 0x74, 8);
        func_02010888(p, (u32)func_02010A3C);
    }
}
