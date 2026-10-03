/*
 * function: func_02167B44
 * address:  0x02167B44
 * packet:   pkt_ov010_02167B44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012944  0x02012944  thumb
 *   func_021CA210  0x021CA210  thumb  ov021
 *   func_02008550  0x02008550  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021CA234  0x021CA234  thumb  ov021
 *   func_021CA2CC  0x021CA2CC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x1E];
    u8 b1e[2];
    u8 pad20[0x668 - 0x20];
    u16 h668;
    u16 h66a[2];
    u16 h66e;
} Obj;

struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *func_021CA210(Obj *o);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u16 func_021CA234(u8 *p);
extern u16 func_021CA2CC(u16 v);

void func_02167B44(Obj *o, void *a1)
{
    void *t;
    void *list;
    int i;

    t = func_02012944(a1);
    list = func_021CA210(o);
    o->h668 = func_02008550(t);
    for (i = 0; i < 2; i++)
        o->h66a[i] = func_02017E1C(func_0201AB28(list, o->b1e[i]), 5, 0);
    o->h66e = func_021CA2CC(func_021CA234((u8 *)o));
}
