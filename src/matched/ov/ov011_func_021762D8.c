/*
 * function: func_021762D8
 * address:  0x021762D8
 * packet:   pkt_ov011_021762D8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021762C0  0x021762C0  thumb  ov011
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201F184  0x0201F184  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u32 f0_0 : 15;
    u32 f0_15 : 7;
    u32 f0_22 : 10;
    u32 kind : 4;
    u32 f4_4 : 28;
    u32 pad8[3];
    Pos pos;
} Obj;

extern void func_021762C0(void *a, int b, void *c, void *d);
extern void func_0201EFA4(void *a, int b, int c, int d, int e, int f);
extern void func_0201EF40(void *a, int b, int c);
extern void func_0201F184(void *a, int b, int c);

void func_021762D8(const Obj *obj, void *a1, void *a2, void *a3)
{
    int v;

    switch (obj->kind) {
    case 0:
        func_021762C0(a2, 0, a1, a3);
        func_0201EFA4(a2, 1, obj->pos.x, 3, 0, 1);
        break;
    case 1:
        func_021762C0(a2, 0, a1, a3);
        func_0201F184(a2, 1, obj->pos.x);
        break;
    case 2:
        func_021762C0(a2, 0, a1, a3);
        func_0201F184(a2, 1, obj->pos.x);
        break;
    case 3: {
        const Pos *pos = &obj->pos;
        func_021762C0(a2, 0, a1, a3);
        func_0201EF40(a2, 1, pos->x);
        func_0201EFA4(a2, 2, pos->y, 5, 0, 1);
        break;
    }
    case 4:
        func_0201EF40(a2, 0, obj->pos.y);
        func_021762C0(a2, 1, a1, a3);
        break;
    case 5:
        func_021762C0(a2, 0, a1, a3);
        break;
    }
    func_0201EFA4(a2, 2, obj->f0_22, 4, 0, 1);
    v = obj->f0_15;
    if (v > 20) {
        v = 1;
    }
    func_0201EFA4(a2, 3, v, 4, 0, 1);
}
