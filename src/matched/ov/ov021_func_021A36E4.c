/*
 * function: func_021A36E4
 * address:  0x021A36E4
 * packet:   pkt_ov021_021A36E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02012B34  0x02012B34  thumb
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_021A3998  0x021A3998  thumb  ov021
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   d_021DDEB8     0x021DDEB8  data  a1
 *   d_021D89A0     0x021D89A0  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A36E4;

typedef struct {
    s16 x;
    s16 z;
    int y;
} Pos021A36E4;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x18];
    Pos021A36E4 pos;
} Tmpl021A36E4;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u8 pad10[8];
    u32 f18;
    void *f1c;
    u16 f20;
    u16 f22;
} Obj021A36E4;

extern const char d_021DDEB8[];
extern Tmpl021A36E4 d_021D89A0;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_02188C80(u32 a);
extern u32 func_02188C7C(u32 a);
extern void *func_0216DE94(u32 a, u32 b);
extern int func_02012B34(u32 a);
extern int func_021A3974(Obj021A36E4 *o);
extern int func_021A31A4(u32 x, int a);
extern void *func_0216CE60(u32 a, Tmpl021A36E4 *b, int c);
extern void func_0216D844(void *h, s16 v);
extern void func_0216D85C(void *h, s16 v);
extern void func_0216D874(void *h, s16 v);
extern void func_0216D89C(void *h, const Vec021A36E4 *v);
extern void func_021A3998(Obj021A36E4 *o);
extern void func_0216DB80(void *o, int v);

Obj021A36E4 *func_021A36E4(u32 a, u32 b, const Vec021A36E4 *pos, u32 d, u16 heap)
{
    Obj021A36E4 *o;
    u32 m;
    int k;
    void *h;

    o = func_02030734(heap, 0x34, 1, d_021DDEB8, 0x97);
    o->fc = a;
    o->f8 = b;
    o->f4 = func_02188C80(b);
    o->f20 = 9;
    o->f22 = 9;
    m = func_02188C7C(b);
    o->f1c = func_0216DE94(m, 0xff);
    o->f18 = d;
    k = func_02012B34(o->fc);
    h = o->f1c;
    if (h == 0) {
        Tmpl021A36E4 t = d_021D89A0;
        Pos021A36E4 *ps = &t.pos;
        ps->x = (pos->x >> 4) / 4096;
        ps->z = (pos->z >> 4) / 4096;
        ps->y = pos->y;
        if (k == 0xFFFF)
            t.f2 = func_021A31A4(d, func_021A3974(o));
        else
            t.f2 = k;
        o->f1c = func_0216CE60(m, &t, 0);
    } else {
        int y;
        int z;
        y = (pos->y >> 4) / 4096;
        z = (pos->z >> 4) / 4096;
        func_0216D844(h, (pos->x >> 4) / 4096);
        func_0216D85C(h, y);
        func_0216D874(h, z);
        func_0216D89C(h, pos);
        if (k == 0xFFFF)
            func_021A3998(o);
    }
    func_0216DB80(o->f1c, 1);
    return o;
}
