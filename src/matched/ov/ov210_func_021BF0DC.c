/*
 * function: func_021BF0DC
 * address:  0x021BF0DC
 * packet:   pkt_ov210_021BF0DC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_0204B688 0x0204B688 arm
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021C940C 0x021C940C thumb ov212
 *   func_021BEDB8 0x021BEDB8 thumb ov210
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE14 0x021BEE14 thumb ov210
 *   data_021C09AC 0x021C09AC data
 *   data_021C0978 0x021C0978 data
 *   data_021C0960 0x021C0960 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Tpl021BF0DC {
    int f0;
    u16 id;
    u16 f6;
    int a;
    int b;
    int c;
    u16 f14;
    u16 f16;
};

struct Obj021BF0DC {
    void **sys;
    u8 pad04[0x20];
    void *set;
    void *objs[57];
    int a[6];
    int b[6];
    int c[4];
};

struct Actor;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B688(struct Actor *actor, u32 value);
extern int func_02012BF8(int a0, int a1);
struct Obj;
extern struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
extern void func_021BEDB8(int p, int i, int v);
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE14(char *p, int idx, int flag);
extern const struct Tpl021BF0DC data_021C09AC[15];
extern const struct Tpl021BF0DC data_021C0978;
extern const struct Tpl021BF0DC data_021C0960;

void func_021BF0DC(struct Obj021BF0DC *p)
{
    u32 i;
    struct Tpl021BF0DC t0;
    struct Tpl021BF0DC t;
    struct Tpl021BF0DC ta;
    struct Tpl021BF0DC tb;

    p->set = func_0204B100(0x39, 0, 0x7B);
    for (i = 0; i < 0x39; i++)
        p->objs[i] = 0;

    for (i = 0; i <= 14; i++) {
        t0 = data_021C09AC[i];
        t0.a = p->a[t0.a];
        t0.b = p->b[t0.b];
        t0.c = p->c[t0.c];
        p->objs[i] = func_021C940C((u32)p->set, (const u8 *)(&t0), 0x7B);
    }

    if (func_02012BF8((int)(*p->sys), 0x10) == 1)
        func_021BEDB8((int)p, 4, 7);
    func_021BEDF0((int)p, 5, 0);
    func_021BEDF0((int)p, 6, 0);
    func_021BEDF0((int)p, 0, 0);
    func_021BEDF0((int)p, 1, 0);
    func_021BEDF0((int)p, 7, 0);
    func_021BEDF0((int)p, 8, 0);
    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 10, 0);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 12, 0);
    func_021BEDF0((int)p, 13, 0);
    func_021BEDF0((int)p, 14, 0);
    func_0204B688(p->objs[13], 2);
    func_0204B688(p->objs[14], 2);
    func_021BEE14((char *)p, 11, 1);
    func_021BEE14((char *)p, 12, 1);

    ta = data_021C0978;
    tb = data_021C0960;
    for (i = 0; i < 14; i++) {
        t = ta;
        t.a = p->a[t.a];
        t.b = p->b[t.b];
        t.c = p->c[t.c];
        t.id = i;
        p->objs[15 + i] = func_021C940C((u32)p->set, (const u8 *)(&t), 0x7B);
        func_021BEDF0((int)p, i + 15, 0);

        t = tb;
        t.a = p->a[t.a];
        t.b = p->b[t.b];
        t.c = p->c[t.c];
        t.id = i;
        p->objs[29 + i] = func_021C940C((u32)p->set, (const u8 *)(&t), 0x7B);
        func_021BEDF0((int)p, i + 29, 0);
        func_021BEE14((char *)p, (int)i + 29, 1);
        p->objs[43 + i] = func_021C940C((u32)p->set, (const u8 *)(&t), 0x7B);
        func_021BEDF0((int)p, i + 43, 0);
        func_0204B688(p->objs[43 + i], 2);
    }
}
