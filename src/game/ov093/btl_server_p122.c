/*
 * file:     btl_server_p122.c
 * unit:     yes
 * function: func_021CFFAC, func_021D0100, func_021D0248, func_021D0304
 * address:  0x021CFFAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021D799C 0x021D799C thumb ov093
 *   func_021D055C 0x021D055C thumb ov093
 *   _ull_mul 0x0209C054 arm
 *   func_021D0644 0x021D0644 thumb ov093
 *   func_021D6940 0x021D6940 thumb ov093
 *   func_021D04E4 0x021D04E4 thumb ov093
 *   d_021EFFC2 0x021EFFC2 data ov093 a2
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D05C4  0x021D05C4  thumb  ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021D7F2C 0x021D7F2C thumb ov093
 *   func_021CFBBC 0x021CFBBC thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 */
struct Unk021D62A8;
struct Rat;
struct Q1;
struct S2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

struct G_021CFFAC { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

typedef union { u32 v; } Word;

struct G_021D0100 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct Row { u8 kind; u8 pad; u16 ids[4]; };

struct G_021D0248 {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021D0304 { void *p0; u8 pad[0xf0]; u64 seed; u64 mul; u64 add; u8 pad2[0xc]; void *list; u8 start; };

typedef signed char    s8;

extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *, int);
extern u16 func_021E8B80(Word);
extern u32 func_0201C314(void *p);
extern u8 func_0201C1C8(void *p);
extern u16 func_021D57FC(void *);
extern int func_021D799C(int, int);
extern int func_021D055C(u8 *g, void *a, int b);
extern int func_021D0644(void *, void *, void *, int);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021D04E4(void *, int, u8 *);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D5C44(struct Rat *p);
extern int func_021D05C4(u8 *g, u8 a, int b, u8 *out);
extern u8 func_021B9B94(struct Q1 *p);
extern u32 func_021B8588(void **p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern int func_021CFBBC(s8 *p, int v);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
int func_021CFFAC(struct G_021CFFAC *g, void *mon, void *target);
int func_021D0100(struct G_021D0100 *g, void *mon, void *target, u8 *out);
int func_021D0248(struct G_021D0248 *g, void *m, u8 *out);
int func_021D0304(struct G_021D0304 *g, void *mon, void *target, u8 *out);
extern const struct Row d_021EFFC2[4];

int func_021CFFAC(struct G_021CFFAC *g, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    Word slot;
    if (func_021D62C4(mon, 0x1b)) {
        slot = func_021D6314(mon, 0x1b);
        id = func_021E8B80(slot);
        if (id) {
            valid = func_0201C314((void *)id);
            kind = func_0201C1C8((void *)id);
            if (func_021D799C(kind, func_021D57FC(target)) == 0 && valid) {
                if (func_021D055C((u8 *)g, target, 4)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
                }
                if (func_021D055C((u8 *)g, target, 3)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                g->seed = g->mul * g->seed + g->add;
                return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}

int func_021D0100(struct G_021D0100 *g, void *mon, void *target, u8 *out)
{
    u16 hist[5];
    u32 i;
    u8 pos;
    u32 j;
    const struct Row *row;
    pos = 0;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) return 0;
    }
    while (func_021D6940(mon, 1, pos++, hist + 1)) {
        for (i = 0; i < 4; i++) {
            row = &d_021EFFC2[i];
            if (((u8 *)hist)[6] == row->kind) {
                for (j = 0; j < 4; j++) {
                    if (!row->ids[j]) break;
                    if (func_021D04E4(g, row->ids[j], (u8 *)hist)) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = ((u8 *)hist)[0];
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


int func_021D0248(struct G_021D0248 *g, void *m, u8 *out)
{
    u16 t[4];
    u8 idx;

    if (func_021D59B4(m, 0x11) == 0x1e) {
        if (func_021D62C4(m, 2) || func_021D62C4(m, 3)) {
            if (func_021D5C44(m) >= 0x32000) {
                if (func_021D6940(m, 1, 0, t)) {
                    if (func_021D05C4((u8 *)g, ((u8 *)t)[4], 2, &idx)) {
                        *out = idx;
                        return 1;
                    }
                } else {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) ? 0 : 1;
                }
            }
        }
    }
    return 0;
}

int func_021D0304(struct G_021D0304 *g, void *mon, void *target, u8 *out)
{
    u16 hist[4];
    u32 sum;
    u32 i;
    u32 n;
    u8 *other;
    int affinity;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 10) >> 32) != 0) return 0;
    }
    sum = 0;
    for (i = 1; i <= 7; i++) sum += func_021D59B4(mon, i);
    if (sum >= 4) return 0;
    if (func_021D6940(mon, 1, 0, hist)) {
        n = func_021B9B94(g->list);
        i = func_021D7F2C(func_021B8588(g->p0), g->start);
        for (; i < n; i++) {
            if (!func_021CFBBC((s8 *)g, (u8)i)) {
                other = func_021B9C00(g->list, (u8)i);
                if (func_021D0644(g, other, target, 4)) {
                    affinity = func_021D799C(((u8 *)hist)[4], func_021D57FC(other));
                    if (affinity == 0) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    } else if (affinity < 3) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
