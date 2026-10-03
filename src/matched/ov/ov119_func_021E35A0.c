/*
 * function: func_021E35A0
 * address: 0x021E35A0
 * packet: pkt_ov119_021E35A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0215642C 0x0215642C thumb ov009
 *   func_02017270 0x02017270 thumb
 *   func_020173B4 0x020173B4 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015FF0 0x02015FF0 thumb
 *   func_021E33FC 0x021E33FC thumb ov119
 *   data_021E7B00 0x021E7B00 data a4
 *   data_021E7B0C 0x021E7B0C data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[4]; } Table;
typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad5f6[0x840 - 0x5f6];
    void *res;
    void *obj[4];
    char pad854[0x118c - 0x854];
    int mode;
} Work;
extern const Vec data_021E7B00;
extern const Table data_021E7B0C;
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void *func_0201ADE4(u16 a, u16 b, u16 heap);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *h);
extern void func_0215642C(int);
extern void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_020173B4(void *o);
extern void func_02015CAC(void *o, Vec *v);
extern void func_02015FF0(char *p, int v);
extern void func_021E33FC(void *o, Vec *v, int side, void *mon);
void func_021E35A0(Work *p, int idx, int side, void *mon, int flag)
{
    Vec v = data_021E7B00;
    Table t = data_021E7B0C;
    if (flag) {
        u16 species = func_02017E1C(mon, 5, 0);
        u16 form = func_02017E1C(mon, 0x6f, 0);
        void *h = func_0201ADE4(species, form, p->heap);
        u32 r = func_0201AE1C(h, 0x22);
        func_0201AE14(h);
        if (r == 0)
            v.x = -v.x;
    }
    if (p->mode == 2)
        func_0215642C(1);
    if (side)
        p->obj[idx] = func_02017270(p->res, mon, 0, t.v[idx], -0x1C000, 0);
    else
        p->obj[idx] = func_02017270(p->res, mon, 1, t.v[idx], -0x1C000, 0);
    if (p->mode == 2)
        func_0215642C(0);
    func_020173B4(p->obj[idx]);
    func_02015CAC(p->obj[idx], &v);
    func_02015FF0(p->obj[idx], 1);
    func_021E33FC(p->obj[idx], &v, side, mon);
}
