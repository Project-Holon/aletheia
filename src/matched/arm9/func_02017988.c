/*
 * function: func_02017988
 * address:  0x02017988
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017988.c \
 *       --func func_02017988 --addr 0x02017988 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32  func_02017D30(void *p);
extern u32  func_020179B8(void *p, u32 a);
extern void func_020185C4(void *p);
extern void func_02017D70(void *p, u32 v);

u32 func_02017988(void *p, u32 a)
{
    u8 v = (u8)func_02017D30(p);
    u32 r = func_020179B8(p, a);

    if (r == 1) {
        func_020185C4(p);
    }
    func_02017D70(p, v);
    return r;
}
