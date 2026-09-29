/*
 * function: func_021D66D8
 * address:  0x021D66D8
 * packet:   pkt_ov093_021D66D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017D30  0x02017D30  thumb
 *   func_02017988  0x02017988  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_021D52B4  0x021D52B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct {
    void *w;
    u8 pad4[8];
    u16 fC;
    u8 pad0E[13];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;
extern u32 func_02017D30(void *h);
extern void func_02017988(void *h, u32 v);
extern u32 func_02017E1C(void *h, u32 k, u32 z);
extern void func_02017D70(void *h, u32 v);
extern void func_021D52B4(void *p, void *w, u32 k);

void func_021D66D8(Obj *p, u32 v)
{
    u32 t;
    ((u8 *)p)[0x141] = v;
    t = func_02017D30(p->w);
    func_02017988(p->w, v);
    func_021D52B4(p, p->w, 1);
    if (p->fC == 0x1ec && v == 0) {
        p->f1b_lo = 0;
        *(u16 *)((u8 *)p + 0x13c) = func_02017E1C(p->w, 10, 0);
    }
    func_02017D70(p->w, t);
}
