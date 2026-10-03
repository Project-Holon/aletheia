/*
 * function: func_021EA878
 * address:  0x021EA878
 * packet:   pkt_ov170_021EA878
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202614C 0x0202614C thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EB988 0x021EB988 thumb
 *   d_021EF8FC 0x021EF8FC data a1
 *   d_021EF8F4 0x021EF8F4 data a1
 */

typedef struct {
    unsigned char pad0[0x16];
    unsigned char b16;
    unsigned char pad17[0x2C - 0x17];
    char *work;
} Obj;

typedef unsigned int   u32;
struct Sound;
extern void func_0202614C(struct Sound *obj, u32 idx);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern const unsigned char d_021EF8FC[];
extern const unsigned char d_021EF8F4[];

#define OBJ(p) (*(void **)((p)->work + 0x70))

void func_021EA878(Obj *p, int v)
{
    if (v != 0) {
        if (p->b16 < 0x1E)
            func_0202614C(OBJ(p), 0x24);
        else
            func_0202614C(OBJ(p), 9);
        func_021EB988(p, d_021EF8FC, 3);
    } else {
        if (p->b16 < 0x1E)
            func_02026124(OBJ(p), 0x24);
        else
            func_02026124(OBJ(p), 9);
        func_021EB988(p, d_021EF8F4, 2);
    }
}
