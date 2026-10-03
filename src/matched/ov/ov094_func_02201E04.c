/*
 * function: func_02201E04
 * address: 0x02201E04
 * packet: pkt_ov094_02201E04
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0207C768 0x0207C768 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   d_0220AE88 0x0220AE88 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { void *owner; Vec start; int idx, mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;
extern char d_0220AE88[];
extern void *func_02030734(u16, u32, int, const char *, u16);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F918C(const Vec *, const Vec *, Vec *, int);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
static inline int Round(int x)
{
    if (x > 0) return _ffix(_fadd(0.5f, _fflt(x << 12)));
    else return _ffix(_fsub(_fflt(x << 12), 0.5f));
}
void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                   void (*f1)(void *, void *), void (*f2)(void *))
{
    Job *p;
    p = func_02030734((*(u16 *)(o + 0x80) & 0x7fff) | 0x8000, 0x50, 0, d_0220AE88, 0x197);
    p->owner = o;
    p->idx = idx;
    p->start.x = v->x;
    p->start.y = v->y;
    p->start.z = v->z;
    p->mode = mode;
    p->n1 = s1;
    p->n2 = s1;
    p->zero = 0;
    p->s2 = s2;
    p->s3 = s3 * 2;
    p->a.x = v->x;
    p->a.y = v->y;
    p->a.z = v->z;
    p->b.x = w->x;
    p->b.y = w->y;
    p->b.z = w->z;
    switch (mode) {
    case 1:
        func_021F918C(&p->a, w, &p->delta, Round(s1));
        break;
    case 3:
        p->n2 *= 2;
        p->s3 *= 2;
    case 2:
        p->delta.x = func_0207C768(w->x, Round(s1));
        p->delta.y = func_0207C768(w->y, Round(s1));
        p->delta.z = func_0207C768(w->z, Round(s1));
        break;
    case 0:
    default:
        break;
    }
    func_021F896C(func_02030DA8(*(void **)o, f1, p, 0), f2, 0);
}
