/*
 * function: func_021F4040
 * address:  0x021F4040
 * packet:   pkt_ov056_021F4040
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x1C-byte record from heap e, fills word 0 from
 * func_02011510(e, b, c, d) and copies 0x12 bytes of a into it at +8.
 * The u16 heap e is re-read with ldrh from its stack slot before each call,
 * so both callees take it as u16 (see
 * a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md);
 * with u32 callee parameters e stayed in r5 and c/d spilled.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02011510  0x02011510  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F4400  0x021F4400  data  ov056  a1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02011510(u16 heap, u32 b, u32 c, u32 d);
extern void func_02082D44(void *dst, void *src, int n);
extern char d_021F4400[];

u32 *func_021F4040(void *a, u32 b, u32 c, u32 d, u16 e)
{
    u32 *r;

    r = func_02030734(e, 0x1c, 1, d_021F4400, 0x4d);
    r[1] = 0;
    r[0] = func_02011510(e, b, c, d);
    func_02082D44(a, r + 2, 0x12);
    return r;
}
