/*
 * function: func_021CC098
 * address:  0x021CC098
 * packet:   pkt_ov021_021CC098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a mon from a spec record: create with a fresh personality, then
 * copy the spec's fields in, pick one of three abilities by spec +0x28,
 * set the two nickname strings and the trainer info, recalc.
 *
 * symbols:
 *   func_0201862C  0x0201862C  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_021CC23C  0x021CC23C  thumb  ov021
 *   func_021CC070  0x021CC070  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_020185C4  0x020185C4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef struct {
    u32 f00;
    u32 species;    /* 0x04 */
    u32 level;      /* 0x08 */
    u32 f0C;
    u32 f10[6];     /* 0x10..0x24: fields 0x46..0x4b */
    u32 sel;        /* 0x28 */
    u32 f2C;
    u32 f30;
    u32 id;         /* 0x34 */
    u32 f38[5];     /* 0x38..0x48: fields 0x13..0x17 */
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
} Spec;

extern u32 func_0201862C(u32 id, u16 species, u16 level, u8 a3, u8 a4, int a5);
struct Mon;
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *mon, u32 field, u32 v);
extern void func_021CC23C(void *mon);
extern u32 func_021CC070(u16 a, u32 b);
extern void func_02045808(u32 p);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(u32 x, u32 field);
extern void func_0201AE14(u32 x);
extern u32 func_02012944(void *sys);
extern void func_0202F190(void *mon, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020185C4(void *mon);

void func_021CC098(void *sys, u16 b, void *mon, Spec *d)
{
    u32 pid;
    u32 s;
    u32 x;
    u32 v[3];

    pid = func_0201862C(d->id, d->species, d->level, d->f30, 0, 0);
    func_02017588(mon, d->species, d->f0C, d->id, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, d->level);
    func_021CC23C(mon);
    s = func_021CC070(b, d->f64);
    func_02017E40(mon, 0x73, s);
    func_02045808(s);
    func_02017E40(mon, 0x46, d->f10[0]);
    func_02017E40(mon, 0x47, d->f10[1]);
    func_02017E40(mon, 0x48, d->f10[2]);
    func_02017E40(mon, 0x49, d->f10[3]);
    func_02017E40(mon, 0x4A, d->f10[4]);
    func_02017E40(mon, 0x4B, d->f10[5]);
    x = (u32)func_0201ADE4((u16)d->species, (u16)d->level, b);
    v[0] = func_0201AE1C(x, 0x1A);
    v[1] = func_0201AE1C(x, 0x1B);
    v[2] = func_0201AE1C(x, 0x1C);
    func_0201AE14(x);
    switch (d->sel) {
    case 0:
        break;
    case 1:
        v[0] = v[1];
        break;
    case 2:
        v[0] = v[2];
        break;
    }
    func_02017E40(mon, 0xA, v[0]);
    func_02017E40(mon, 0x70, d->f2C);
    func_02017E40(mon, 0x13, d->f38[0]);
    func_02017E40(mon, 0x14, d->f38[1]);
    func_02017E40(mon, 0x15, d->f38[2]);
    func_02017E40(mon, 0x16, d->f38[3]);
    func_02017E40(mon, 0x17, d->f38[4]);
    func_02017E40(mon, 0x6, d->f4C);
    s = func_021CC070(b, d->f68);
    func_02017E40(mon, 0x8D, s);
    func_02045808(s);
    func_02017E40(mon, 0x9A, d->f50);
    func_02017E40(mon, 0xC, d->f58);
    func_0202F190(mon, 1, func_02012944(sys), 0x7532, b);
    func_021CC23C(mon);
    func_020185C4(mon);
}
