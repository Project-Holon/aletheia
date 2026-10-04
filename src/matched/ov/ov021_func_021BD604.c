/*
 * function: func_021BD604
 * address:  0x021BD604
 * packet:   pkt_ov021_021BD604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern u16 func_02045A98(void);
struct StrObj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *a, const u16 *b, u32 c);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_02045808(struct U16Vec *vec);

void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e)
{
    u16 buf[2];
    u32 h;

    buf[0] = b;
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, c);
    func_02045994((struct Strbuf *)h, buf, 2);
    *d = func_0201D304((struct StrObj *)h, a, 0);
    *e = func_0201D42C((struct StrObj *)h, (void *)a);
    func_02045808((struct U16Vec *)h);
}
