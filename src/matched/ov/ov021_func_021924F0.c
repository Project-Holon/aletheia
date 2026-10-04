/*
 * function: func_021924F0
 * address:  0x021924F0
 * packet:   pkt_ov021_021924F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201DC80  0x0201DC80  thumb
 *   func_020458F8  0x020458F8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Font;
struct StrObj;
struct U16Vec;
extern u32 func_0201DC80(struct Font *p);
extern u16 func_020458F8(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);

void func_021924F0(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f)
{
    int i;
    u32 h;
    int t;

    t = func_0201DC80((struct Font *)d) + 2;
    h = (u32)func_020457B0(func_020458F8((struct U16Vec *)e) + 1, f);
    for (i = 0; func_0201D37C((struct StrObj *)e, (struct StrObj *)h, i) == 1; i++) {
        func_0201C7A4((void *)c, (s16)a, (s16)b, (void *)h, (void *)d);
        b += (u16)t;
    }
    func_02045808((struct U16Vec *)h);
}
