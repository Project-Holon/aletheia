/*
 * function: func_021C1450
 * address:  0x021C1450
 * packet:   pkt_ov208_021C1450
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   func_021C0CCC 0x021C0CCC thumb ov208
 *   func_021C0D5C 0x021C0D5C thumb ov208
 *   func_021C1068 0x021C1068 thumb ov208
 *   func_021C1D30 0x021C1D30 thumb ov208
 *   func_021C2238 0x021C2238 thumb ov208
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_020520A4 0x020520A4 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Vec { int x, y, z; };
struct PtS { s16 x, y; };

extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
struct Actor;
struct Obj;
struct Vec2;
struct Vec3;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u16 func_021BBB3C(char *, int, int);
extern void func_021C0CCC(u16 *heap, u8 *p, int key);
extern u8 func_021C0D5C(void *unused, char *p, int unused2, u8 x, u8 y);
extern u8 func_021C1068(void *heap, char *p, int key, u8 x, u8 y);
extern void func_021C1D30(u16 *heap, u8 *p, int key);
extern void func_021C2238(u16 *heap, u8 *p, int key);
extern void func_0207CA00(struct Vec *a, struct Vec *b, struct Vec *out);
extern int func_0207CBD0(struct Vec *v);
extern void func_0207CCA4(struct Vec *src, struct Vec *dst);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void func_020061E4(u32 se);

#define W(o) (*(u32 *)(p + (o)))
#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))

static inline void set3(struct Vec *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_021C1450(u16 *heap, u8 *p, int key)
{
    u32 tx, ty;
    struct { struct PtS t, c; } pt;
    u8 idx;
    u8 old;
    int found, near;
    int moved;
    unsigned int keys;
    int dx, dy;

    if (W(0x90) == 0)
        return;
    if (func_020355C4() == 0) {
        if (func_02035D20(&tx, &ty)) {
            func_020355D8(1);
            func_0204B3DC((struct Obj *)W(0xcc), 0);
        }
    } else if (func_020362DC()) {
        func_020355D8(0);
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
        func_021C2238(heap, p, key);
        return;
    }
    if (func_020355C4() == 0) {
        old = p[0x79];
        moved = 0;
        found = 0;
        near = 0;
        {
        struct Vec v = {0, 0, 0};
        struct Vec d = {0, 0, 0};
        struct Vec a;
        struct Vec b;
        func_0204B454((struct Actor *)W(0xcc), &pt.c, 0);
        keys = func_0203630C();
        if ((keys & 0x10) || (keys & 0x20) || (keys & 0x40) || (keys & 0x80)) {
            moved = 1;
            if (keys & 0x10)
                v.x += 0x1000;
            if (keys & 0x20)
                v.x -= 0x1000;
            if (keys & 0x40)
                v.y -= 0x1000;
            if (keys & 0x80)
                v.y += 0x1000;
        }
        idx = func_021C1068(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (idx != 0xff) {
            found = 1;
            pt.t.x = func_021BBB3C(*(char **)(p + 0x3c8), idx, 4);
            pt.t.y = func_021BBB3C(*(char **)(p + 0x3c8), idx, 5);
            a.x = FX(pt.t.x);
            a.y = FX(pt.t.y);
            a.z = 0;
            b.x = FX(pt.c.x);
            b.y = FX(pt.c.y);
            b.z = 0;
            func_0207CA00(&a, &b, &d);
            if (func_0207CBD0(&d) < 0x1BB6)
                near = 1;
            if (func_0207CBD0(&d) > 0x1000) {
                func_0207CCA4(&d, &d);
                func_020520A4((const struct Vec3 *)(&d), 0x1000, (struct Vec3 *)(&d));
            }
        }
        if (moved == 0 && found == 0)
            return;
        if (moved == 0 && found != 0 && near != 0) {
            pt.c = pt.t;
        } else {
            func_0207CCA4(&v, &v);
            dx = d.x + v.x * 3;
            dy = d.y + v.y * 3;
            if (dx > 0 && dx < 0x1000)
                dx = 0x1000;
            else if (dx > -0x1000 && dx < 0)
                dx = -0x1000;
            if (dy > 0 && dy < 0x1000)
                dy = 0x1000;
            else if (dy > -0x1000 && dy < 0)
                dy = -0x1000;
            pt.c.x = pt.c.x + (s16)(dx >> 12);
            pt.c.y = pt.c.y + (s16)(dy >> 12);
        }
        pt.c.x = pt.c.x > 0xf8 ? 0xf8 : (pt.c.x < 0 ? 0 : pt.c.x);
        pt.c.y = pt.c.y > 0xa8 ? 0xa8 : (pt.c.y < 8 ? 8 : pt.c.y);
        func_0204B404((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt.c), 0);
        p[0x79] = func_021C0D5C(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (p[0x79] != old) {
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
            if (p[0x79] != 0xff)
                func_020061E4(0x548);
        }
        }
    } else if (func_02035D20(&tx, &ty)) {
        p[0x79] = func_021C0D5C(heap, (char *)p, key, (u8)tx, (u8)ty);
        func_021C1D30(heap, p, key);
        func_021C2238(heap, p, key);
        if (p[0x79] != 0xff)
            func_020061E4(0x54C);
    }
}
