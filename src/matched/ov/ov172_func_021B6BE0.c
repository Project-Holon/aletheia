/*
 * function: func_021B6BE0
 * address: 0x021B6BE0
 * packet: pkt_ov172_021B6BE0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   d_021C71D0 0x021C71D0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;
typedef struct { u8 kind, pad; u16 count, x, y, a, b, c, d; void *data; } Object;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *GFL_NET_AllocAligned(u32, u32, const char *, u16);
extern const char d_021C71D0[];
Object *func_021B6BE0(Params *p)
{
    Object *q;
    q = func_02030734(p->heap, 20, 1, d_021C71D0, 64);
    q->data = GFL_NET_AllocAligned(p->heap, p->count * 8, d_021C71D0, 65);
    q->kind = p->kind;
    q->count = p->count;
    q->a = p->a;
    q->b = p->b;
    q->c = p->c;
    q->d = p->d;
    q->x = 0;
    q->y = 0;
    return q;
}
