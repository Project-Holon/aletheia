/*
 * function: func_0202B3EC
 * address:  0x0202B3EC
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs the destructor chain: func_0202B42C, then releases the +0x14
 * sub-object and the object itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B3EC.c \
 *       --func func_0202B3EC --addr 0x0202B3EC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202B42C(u8 *p);
extern void func_0202B360(u8 *p);
extern void func_020307B0(void *p);

void func_0202B3EC(u8 *p)
{
    func_0202B42C(p);
    func_0202B360(*(u8 **)(p + 0x14));
    func_020307B0(p);
}
