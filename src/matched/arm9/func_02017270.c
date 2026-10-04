/*
 * function: func_02017270
 * address:  0x02017270
 * packet:   pkt_02017270
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017270.c \
 *       --func func_02017270 --addr 0x02017270 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32  func_02017E1C(void *p, u32 a, u32 b);
extern void func_020172AC(int a0, int a1);
extern void func_02017100(void *p, void *buf, u32 a);
extern void *func_020159C8(void *a0, u32 a1, u32 a2, u32 a3, void *buf);

void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 buf[0x24];

    func_020172AC((int)a0, func_02017E1C(a1, 0, 0));
    func_02017100(a1, buf, a2);
    return func_020159C8(a0, a3, a4, a5, buf);
}
