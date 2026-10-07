/*
 * file:     unit_021B7560_p10.c
 * unit:     yes
 * function: func_021B8D20, func_021B8DA4
 * address:  0x021B8D20
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   func_0204B6F4 0x0204B6F4 arm
 */
#include "../../matched/include/Obj02453.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {int x,y,z;} Vec;

typedef struct { int x, y; } Point;

typedef struct {
    void *object;
    u32 index, active;
    int sx, sy, sz, ex, ey, ez;
    u32 counter, lifetime;
} Particle;

extern void func_0207CA00(Vec *,Vec *,Vec *);
extern int func_0207CBD0(Vec *);
extern void func_0207CCA4(Vec *,Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float), _fsub(float, float);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021B8D20(u8 *p);
void func_021B8DA4(Particle *p, const Point *a, const Point *b, int color, u32 lifetime);

/*
 * extent: Two zero alignment bytes at 021B8DA2 before 021B8DA4.
 * lever: Declare delta before pos; multiply length by counter in that order.
 */
void func_021B8D20(u8 *p) {
 u16 xy[2]; Vec delta; Vec pos; int length;
 if(((struct Obj02453 *)p)->f8) {
  func_0207CA00((Vec *)(p+0x18),(Vec *)(p+0xc),&delta);
  length=func_0207CBD0(&delta); func_0207CCA4(&delta,&delta);
  func_0207CEE4((u32)(length * ((struct Obj02453 *)p)->f24)/ ((struct Obj02453 *)p)->f28,&delta,(Vec *)(p+0xc),&pos);
  xy[0]=pos.x>>12; xy[1]=pos.y>>12;
  if((((struct Obj02453 *)p)->f24)++ > ((struct Obj02453 *)p)->f28) {
   xy[0]=((struct Obj02453 *)p)->f18; xy[1]=((struct Obj02453 *)p)->f1C;
   func_0204B3DC(((struct Obj02453 *)p)->f0,0); ((struct Obj02453 *)p)->f8=0;
  }
  func_0204B404(((struct Obj02453 *)p)->f0,(const struct Vec2 *)xy,(u16)(((struct Obj02453 *)p)->f4));
 }
}

static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}

/*
 * Evidence: 44-byte particle layout from ov104_func_021B8D20; float
 * runtime identities from matched func_0204CC6C; object callees from
 * their own matched units. Unsigned shifts preserve 32-bit wrapping;
 * explicit runtime conversion retains all signed input values.
 */
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
