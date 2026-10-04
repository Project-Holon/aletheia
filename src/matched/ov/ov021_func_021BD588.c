/*
 * function: func_021BD588
 * address:  0x021BD588
 * packet:   pkt_ov021_021BD588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BD2C8  0x021BD2C8  thumb  ov021
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern u16 func_021BD2C8(void *p);
extern u16 func_02045A98(void);
struct Obj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *a, const u16 *b, u32 c);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_020257D0(struct Obj *o);
extern void func_02045808(struct U16Vec *vec);

void func_021BD588(u32 *p)
{
    u16 buf[2];
    u32 h;

    buf[0] = func_021BD2C8(p);
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, *(u16 *)p);
    func_02045994((struct Strbuf *)h, buf, 2);
    func_0201C7D0((void *)p[2], 0, 0, (void *)h, (void *)p[1], 0x440);
    func_020257D0((struct Obj *)p[3]);
    func_02045808((struct U16Vec *)h);
}
