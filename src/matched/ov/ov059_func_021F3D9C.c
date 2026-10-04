/*
 * function: func_021F3D9C
 * address:  0x021F3D9C
 * packet:   pkt_ov059_021F3D9C
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the task callback func_021F3CFC installs; the function is 180
 *           bytes, the rest of the handed 772 is data.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162744  0x02162744  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEE4  0x0216CEE4  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x24];
    u16 *p24;
} W;

struct BigObj;
struct Ctx;
struct Obj;
struct Rec44;
struct SaveBlock;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern W *func_021897BC(void *p, int i);
extern int func_021BE6E8(int a, int b, int c, int d);
extern void *func_02188C7C(u8 *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216CF2C(void *o);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u16 func_02162744(u8 *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_02162740(u8 *p);
extern void *func_0216CEE4(void *a, void *e, u32 b, int n, u32 c, u32 id);
extern void func_0216DAF8(void *obj);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *p);

int func_021F3D9C(void *a)
{
    void *o;
    void *t;
    void *s;
    W *w;
    u16 x;
    u16 y;
    void *map;
    void *v;
    void *m;
    u16 k;
    u32 b;
    u32 c;
    void *e;
    int r;

    o = func_020124E4(a);
    t = func_0201210C(o);
    s = (void *)func_02188D2C(t);
    w = func_021897BC(t, 1);
    if (func_021BE6E8((int)s, 0, 2, 0) == 0xF000) {
        x = w->p24[0];
        y = w->p24[1];
        map = func_02188C7C(t);
        func_0216CF2C(func_0216DE94(map, x));
        v = func_020120F4(o);
        m = (void *)func_02012844(v);
        k = func_02162744(m);
        b = func_02012AC8(func_020127A4(v));
        if (k != 0) {
            c = func_0201296C(v);
            e = func_0216CEE4(map, (void *)func_02162740(m), b, k, c, y);
            if (e != 0)
                func_0216DAF8(e);
        }
    }
    r = 0;
    if (func_021BE6BC(func_021BE674(s, 0, 2, 0)) != 0)
        r = 1;
    return r;
}
