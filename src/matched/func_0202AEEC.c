/*
 * function: func_0202AEEC
 * address:  0x0202AEEC
 * packet:   pkt_0202AEEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x28-byte node with func_02030734, wraps it with func_02048F88,
 * runs func_0202AF3C over the pair and releases the wrapper.  The pair is
 * passed as (wrapper, node): r0 is left holding the wrapper from the second
 * allocation when func_0202AF3C is reached, with the node moved into r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AEEC.c \
 *       --func func_0202AEEC --addr 0x0202AEEC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_02030734(u32 heapId, u32 size, u32 zero,
                           const void *file, u32 line);
extern void *func_02048F88(u32 heapId, u32 a, u32 b, u32 c, u32 d);
extern void  func_0202AF3C(u8 *wrapper, u8 *node);
extern void  func_020307B0(void *p);

u8 *func_0202AEEC(u32 a, u32 b)
{
    u8 *node = (u8 *)func_02030734(a, 0x28, 0, (const void *)0x020A76F8, 0x6c);
    u8 *wrap = (u8 *)func_02048F88(0x84, b, a, 0, 0x28);

    func_0202AF3C(wrap, node);
    func_020307B0(wrap);
    return node;
}
