/*
 * function: func_020109B8
 * address:  0x020109B8
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020109B8.c \
 *       --func func_020109B8 --addr 0x020109B8 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_02010888(u8 *p, u32 v);
extern void func_020109E0(u8 *p);

void func_020109B8(u8 *p)
{
    s32 v = (s32)*(u32 *)(p + 0x10) - 1;

    *(u32 *)(p + 0x10) = (u32)v;
    if (v < 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x73, 8);
        func_02010888(p, (u32)func_020109E0);
    }
}
