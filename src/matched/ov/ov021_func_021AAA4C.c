/*
 * function: func_021AAA4C
 * address:  0x021AAA4C
 * packet:   pkt_ov021_021AAA4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D828  0x0216D828  thumb  ov010
 */

typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
} Self;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216D828(void *p, Vec3s *out);

int func_021AAA4C(Self *self, short *out)
{
    Ent *e = (Ent *)(func_02012A38(self->obj) + 0x10);
    Vec3s v;
    int a, b;

    if (e->flags == 0) {
        *out = 0;
        return 0;
    }
    func_0216D828(func_021A3074(func_02188CB4(self->ctx)), &v);
    a = (short)(e->x - v.x);
    if (a < 0)
        a = a * 0xffffffff;
    b = (short)(e->z - v.z);
    if (b < 0)
        b = b * 0xffffffff;
    if (a > b)
        *out = a;
    else
        *out = b;
    return 1;
}
