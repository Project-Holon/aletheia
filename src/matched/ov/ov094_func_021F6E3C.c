/*
 * function: func_021F6E3C
 * address:  0x021F6E3C
 * packet:   pkt_ov094_021F6E3C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_021F73A4  0x021F73A4  thumb  ov094
 *   func_021F7208  0x021F7208  thumb  ov094
 *   d_0220AC60     0x0220AC60  data   ov094  a1
 *   d_02209CF4     0x02209CF4  data   ov094
 *   d_02209D00     0x02209D00  data   ov094
 *   d_02209CE8     0x02209CE8  data   ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} VecFx32;

typedef struct {
    int f0;
    int h4;
    char pad08[0x10];
    VecFx32 v18;        /* 0x18 */
    VecFx32 v24;        /* 0x24 */
    char pad30[0xb4 - 0x30];
    u16 hb4;            /* 0xb4 */
} Obj;

extern const char d_0220AC60[];
extern char d_02209CF4[];
extern char d_02209D00[];
extern char d_02209CE8[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_021F73A4(Obj *o);
extern void func_021F7208(VecFx32 *a, VecFx32 *b);

Obj *func_021F6E3C(int a, u16 b)
{
    Obj *o = sub_02030734(b, 0xb8, 1, d_0220AC60, 0x56);

    o->hb4 = b;
    o->f0 = a;
    o->h4 = func_02048A24(0, 0x399, 0xf97, 0x159a, 0, 0x1000, 0x200000, 0,
                          d_02209CF4, d_02209D00, d_02209CE8, b);
    func_021F73A4(o);
    func_02048AD0((struct Light *)o->h4);
    func_021F7208(&o->v18, &o->v24);
    return o;
}
