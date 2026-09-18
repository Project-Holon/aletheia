/*
 * function: func_02020234
 * address:  0x02020234
 * packet:   pkt_02020234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020234.c \
 *       --func func_02020234 --addr 0x02020234 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};

extern u32  func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0202055C(void *p, u32 a, u32 b, u32 c, u32 d);
extern void func_020206C0(void *p);

void func_02020234(u8 *p)
{
    func_02043B5C(func_02045770(*(u32 *)(p + 0xc)),
                  ((struct Ctl *)p)->lo4);
    func_0202055C(p, *(u16 *)(p + 0x40), 0, *(u16 *)(p + 0x12), 1);
    func_020206C0(p);
}
