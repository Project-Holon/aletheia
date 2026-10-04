/*
 * function: func_021FE410
 * address:  0x021FE410
 * packet:   pkt_ov094_021FE410
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets/clears the 0x200/0x400 flag bits of *o, allocates a 0x10-byte record
 * (heap from the u16 at +0x238), converts n to fx32 (n<<12, +-0.5 rounding)
 * and registers func_021FE768 as a task callback through func_02030DA8.
 *
 * symbols:
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F9154  0x021F9154  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021FE768  0x021FE768  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094
 */
#include "../include/Obj13601.h"
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned int f0 : 9;
    unsigned int f9 : 1;
    unsigned int f10 : 1;
} Flags;

typedef struct {
    Flags *fl;
    int a;
    int b;
    int v[3];
} Rec;

typedef struct {
    Flags fl;
    char pad04[4];
    int h;
    char pad0c[0xd0];
    unsigned int heap : 32;
} Obj;

extern char d_0220AE68[];
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030DA8(int owner, void *fn, void *arg, int n);
extern void func_021F9154(int a, int b, int *out, int c);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE768(void *h, int *s);

void func_021FE410(Obj *o, int a, int b, int n)
{
    Rec *r;
    int fx;

    if (a > b) {
        if (o->fl.f9) {
            o->fl.f10 = 1;
            return;
        }
        o->fl.f9 = 1;
    } else {
        o->fl.f9 = 0;
    }
    r = func_02030734((u16)(((u16)((struct Obj13601 *)o)->f238 & 0x7fff) | 0x8000), 0x10, 0, d_0220AE68, 0x1d78);
    r->a = a;
    r->b = b;
    r->fl = (Flags *)o;
    if (n > 0)
        fx = _ffix(_fadd(0.5f, _fflt(n << 12)));
    else
        fx = _ffix(_fsub(_fflt(n << 12), 0.5f));
    func_021F9154(r->a, r->b, r->v, fx);
    func_021F896C((void *)func_02030DA8(((struct Obj13601 *)o)->f8, (void *)func_021FE768, r, 0), 0, 1);
}
