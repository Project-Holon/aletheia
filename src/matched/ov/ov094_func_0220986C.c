/*
 * function: BTLV_BG_StartScrollJob
 * address: 0x0220986C
 * packet: pkt_ov094_0220986C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: matched twin 02201E04 with its unused idx slot removed; this
 *   caller registers fixed callback 02209A40, not a ninth parameter.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0207C768 0x0207C768 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   BTLV_BG_OnScrollJobEnd 0x02209A40 thumb ov094
 *   sBtlvBgSiteName 0x0220AEF0 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj13628.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { void *owner; Vec start; int mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;
extern char sBtlvBgSiteName[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_0207C768(u32, u32);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F918C(const Vec *, const Vec *, Vec *, int);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern void BTLV_BG_OnScrollJobEnd(void *);
static inline int Round(int x)
{
    if (x > 0) return _ffix(_fadd(0.5f, _fflt(x << 12)));
    else return _ffix(_fsub(_fflt(x << 12), 0.5f));
}
void BTLV_BG_StartScrollJob(char *o, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                   void (*f1)(void *, void *))
{
    Job *p;
    p = func_02030734(((struct Obj13628 *)o)->f8, 0x4c, 0, sBtlvBgSiteName, 0xb8);
    p->owner = o;
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
    func_021F896C(func_02030DA8(((struct Obj13628 *)o)->f0, f1, p, 0), BTLV_BG_OnScrollJobEnd, 0);
}
