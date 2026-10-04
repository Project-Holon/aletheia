/*
 * function: func_02028454
 * address:  0x02028454
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028454.c \\
 *       --func func_02028454 --addr 0x02028454 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 v);

void func_02028454(u8 *p)
{
    func_02045374((struct Cfg *)(*(u32 *)p));
    func_02041B6C((u8)*(u16 *)(*(u32 *)(p + 0x18)));
}
