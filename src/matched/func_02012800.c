/*
 * function: func_02012800
 * address:  0x02012800
 * packet:   pkt_02012800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02161D64  0x02161D64  thumb  ov010
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012800.c \
 *       --func func_02012800 --addr 0x02012800 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_02082D44(void *dst, const void *src, u32 n);
extern void func_02161D64(u8 *p);

void func_02012800(u8 *obj, void *dst)
{
    func_02082D44(dst, obj + 0x214, 0x1e8);
    func_02161D64(obj + 0x214);
}
