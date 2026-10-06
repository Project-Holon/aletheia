/*
 * function: func_0201281C
 * address:  0x0201281C
 * packet:   pkt_02012800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02161D64  0x02161D64  thumb  ov010
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201281C.c \
 *       --func func_0201281C --addr 0x0201281C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_02082BCC(void *dst, int c, u32 n);
extern int func_02161D64(int a0);

void func_0201281C(u8 *obj)
{
    func_02082BCC(obj + 0x214, 0, 0x1e8);
    func_02161D64((int)(obj + 0x3fc));
}
