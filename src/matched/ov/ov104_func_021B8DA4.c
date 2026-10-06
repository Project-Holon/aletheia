/*
 * function: func_021B8DA4
 * address: 0x021B8DA4
 * packet: pkt_ov104_021B8DA4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Evidence: 44-byte particle layout from ov104_func_021B8D20; float
 * runtime identities from matched func_0204CC6C; object callees from
 * their own matched units. Unsigned shifts preserve 32-bit wrapping;
 * explicit runtime conversion retains all signed input values.
 *
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int x, y; } Point;
typedef struct {
    void *object;
    u32 index, active;
    int sx, sy, sz, ex, ey, ez;
    u32 counter, lifetime;
} Particle;
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float), _fsub(float, float);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}
void func_021B8DA4(Particle *p, const Point *a, const Point *b, int color, u32 lifetime)
{
    int sy, ey;
    p->active = 1;
    sy = convert(a->y);
    p->sx = convert(a->x);
    p->sz = 0;
    p->sy = sy;
    ey = convert(b->y);
    p->ex = convert(b->x);
    p->ez = 0;
    p->counter = 0;
    p->lifetime = lifetime;
    p->ey = ey;
    func_0204B3DC(p->object, 1);
    func_0204B6F4(p->object, (u8)color, 1);
}
