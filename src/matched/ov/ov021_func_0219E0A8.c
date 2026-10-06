/*
 * function: func_0219E0A8
 * address:  0x0219E0A8
 * packet:   pkt_ov021_0219E0A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E354  0x0219E354  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0219E370  0x0219E370  thumb  ov021
 *   func_0219E6C8  0x0219E6C8  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   d_021DDD94     0x021DDD94  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    s32 x, y, z;
} V3;

typedef struct {
    s32 speed;
    s32 acc;
    u16 step;
    u16 pos;
    s8 id;
    s8 count;
    s8 f0e;
    s8 table;
} E;

extern void *func_0216D6D4(void *p);
extern void *func_0219E348(void *a);
extern void func_0219E354(u32);
extern void func_021B8028(u32, void *);
extern void func_0216D89C(u32, void *);
extern void func_0219E370(u32 a, u32 b, u32 c);
extern void func_0219E6C8(u32 o, u16 id);
extern void func_0216D568(void *p, u32 v);
extern void func_0216D8C0(u32, V3 *);
extern u8 func_021B8040(u8 *p);
extern void func_02163F10(u32);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *p);
extern void func_020061E4(u32);

extern s32 *d_021DDD94[];

int func_0219E0A8(u32 o)
{
    E *e;
    u32 a;
    s32 t;
    s32 k;
    u8 buf[12];
    V3 v;
    s32 z[3];

    e = func_0216D6D4((void *)o);
    e->count--;
    if (e->speed != 0) {
        a = (u32)func_0219E348((void *)o);
        func_0219E354(o);
        func_021B8028(a, buf);
        func_0216D89C(o, buf);
        if (e->acc >= 0x10000 && e->count > 0) {
            e->acc = 0;
            func_0219E370(o, e->id, 8);
            func_0219E6C8(o, e->id);
            func_0216D568((void *)o, 0x20);
        }
        t = e->speed;
        if (t < 0) {
            t = -t;
        }
        e->acc += t;
    }
    e->pos += e->step;
    if (e->pos > 0xF00) {
        e->pos = 0xF00;
    }
    t = (u16)(e->pos / 256);
    k = e->table;
    v.x = 0;
    v.y = d_021DDD94[k][t];
    v.z = 0;
    func_0216D8C0(o, &v);
    if (e->count > 0 || func_021B8040((u8 *)a)) {
        return 0;
    }
    {
        V3 *pv = (V3 *)z;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        func_0216D8C0(o, pv);
    }
    func_0216D568((void *)o, 0x540);
    func_02163F10(o);
    func_0216D674((void *)o, 0);
    func_0216D7CC((u8 *)o);
    func_020061E4(0x67B);
    return 1;
}
