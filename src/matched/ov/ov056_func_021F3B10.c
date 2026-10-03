/*
 * function: func_021F3B10
 * address:  0x021F3B10
 * packet:   pkt_ov056_021F3B10
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the image loads the stack parameter idx into r4 before the first
 *           call and keeps it there to the arms' idx * 6.  An unassigned stack
 *           parameter is re-read from its slot at each use (228 bytes); any
 *           assignment to it makes it a register variable loaded at entry.
 *           `idx = (u32)idx;` does that and emits no code (`idx = idx;`,
 *           `idx += 0;` and `idx = idx * 1;` fold away first; `idx *= 6` in the
 *           arms promotes it but multiplies in place, 220 bytes).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02008550  0x02008550  thumb
 *   func_02046E24  0x02046E24  arm
 *   func_02047180  0x02047180  arm
 *   func_02049238  0x02049238  arm
 *   d_021F4308     0x021F4308  data  a4
 *   d_021F4264     0x021F4264  data  a2
 *   d_021F426C     0x021F426C  data  ov056  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct Obj {
    void *res0;
    void *res1;
    void *res2;
    int f0c;
    u8 pad10[0x10];
    Vec pos;
    Vec scale;
    Mtx33 rot;
    int f5c;
    int f60;
    void *f64;
    void *f68;
    Vec f6c;
    u16 f78;
    u16 pad7a;
    int f7c;
} Obj;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_021A3074(unsigned char *p);
extern void func_0207ADC4(Mtx33 *m);
extern u32 func_02008550(int a);
extern void *func_02046E24(void *a0, u32 a1);
extern int func_02047180(u32 *p);
extern void func_02049238(void *);

extern const Vec d_021F4308[];
extern const u16 d_021F4264[];
extern const Vec d_021F426C;

void func_021F3B10(Obj *o, void *a1, int a2, int a3, int idx)
{
    void *h;
    int k;

    idx = (u32)idx;
    h = func_020490F4(0x96, (a3 & 0x7fff) | 0x8000);
    o->f7c = 0;
    o->f5c = 0;
    o->f6c = d_021F4308[idx];
    o->f60 = a2;
    o->f78 = d_021F4264[idx];
    o->f64 = a1;
    o->f68 = func_021A3074(a1);
    o->pos = d_021F426C;
    o->scale.x = 0x1000;
    o->scale.y = 0x1000;
    o->scale.z = 0x1000;
    func_0207ADC4(&o->rot);
    if (func_02008550(a2) == 0) {
        k = idx * 6;
        o->res0 = func_02046E24(h, k + 3);
        o->res2 = func_02046E24(h, k + 4);
    } else {
        k = idx * 6;
        o->res0 = func_02046E24(h, k + 1);
        o->res2 = func_02046E24(h, k + 2);
    }
    o->res1 = func_02046E24(h, k + 5);
    func_02047180(o->res0);
    o->f0c = 1;
    func_02049238(h);
}
