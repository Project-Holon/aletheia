/*
 * function: func_021AA944
 * address:  0x021AA944
 * packet:   pkt_ov021_021AA944
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   func_021AB070  0x021AB070  thumb  ov021
 *   func_021AB0AC  0x021AB0AC  thumb  ov021
 *   func_021AB018  0x021AB018  thumb  ov021
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_021AAFA0  0x021AAFA0  thumb  ov021
 *   func_021AAB1C  0x021AAB1C  thumb  ov021
 *   func_021A3624  0x021A3624  thumb  ov021
 *   func_021A3644  0x021A3644  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

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
    unsigned char mid : 2;
    unsigned char top : 2;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0C[4];
    void *f10;
} Self;

extern char *func_02012A38(void *p);
extern void *func_02188CB4(void *p);
extern void *func_021A3074(void *p);
extern void func_0216D828(void *p, Vec3s *out);
extern u32 func_02005728(u32 v);
extern u16 func_021AB070(void);
extern int func_021AB0AC(Self *self, u16 v);
extern u16 func_021AB018(void);
extern int func_021A9F40(Self *self, u32 v);
extern void func_021AAFA0(Self *self, void *p);
extern void func_021AAB1C(Self *self, int v);
extern int func_021A3624(void *p);
extern void func_021A3644(void *p);

static inline int same_pos(Ent *e, Vec3s *v)
{
    if (e->x != v->x || e->z != v->z || e->y != v->y)
        return 0;
    return 1;
}

int func_021AA944(Self *self)
{
    void *arg = self->f10;
    char *base = func_02012A38(self->obj);
    Ent *e = (Ent *)(base + 0x10);
    int flag = 0;
    Vec3s v;
    u16 r;
    int x;
    void *o;

    if (((Ent *)(base + 0x10))->flags == 0)
        return flag;
    func_0216D828(func_021A3074(func_02188CB4(self->ctx)), &v);
    if (!same_pos(e, &v))
        return 0;
    r = func_02005728(1000);
    if (e->b == 7) {
        if (r < 200) {
            x = func_021A9F40(self, 1);
        } else {
            x = func_021AB0AC(self, func_021AB070());
            flag = 1;
        }
    } else if (e->b == 4) {
        if (r < 400) {
            x = func_021A9F40(self, 1);
        } else {
            x = func_021AB0AC(self, func_021AB018());
            flag = 1;
        }
    } else {
        x = func_021A9F40(self, 1);
    }
    if (x == 0) {
        func_021AAFA0(self, arg);
        return 0;
    }
    if (flag) {
        func_021AAFA0(self, arg);
    } else {
        if (e->b == 5 || e->b == 6)
            func_021AAB1C(self, 1);
        e->top = 1;
        o = func_02188CB4(self->ctx);
        if (func_021A3624(o))
            func_021A3644(o);
    }
    return x;
}
