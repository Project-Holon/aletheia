/*
 * file:     btl_server_p121.c
 * unit:     yes
 * function: func_021CFD50, func_021CFDCC, func_021CFE08, func_021CFE98
 * address:  0x021CFD50
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
 *   func_021B8D38  0x021B8D38  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8AFC 0x021E8AFC thumb ov093
 *   func_021D631C 0x021D631C thumb ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D0644  0x021D0644  thumb  ov093
 *   func_021D055C  0x021D055C  thumb  ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_021D799C 0x021D799C thumb ov093
 */
struct Unk021D62A8;
struct QG;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

struct G_021CFD50 {
    void *p0;
    void *p1;
    u8 pad0[0xec];
    u64 seed;
    u64 mul;
    u64 add;
};

union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};

struct G_021CFE08 {
    void *p0;
    u8 pad0[0xf0];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021CFE98 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

extern u8 func_021B8D38(void *p, int a, int k, u8 *out);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Slot func_021D6314(void *, int);
extern u8 func_021E8AFC(union Slot);
extern u8 func_021D631C(u8 *p, int i);
extern u32 func_021B8588(void **p);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D0644(void *g, void *m, void *a, int b);
extern int func_021D055C(u8 *g, void *a, int b);
extern u16 func_021D57FC(void *);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_0201C314(void *p);
extern u8 func_0201C1C8(void *p);
extern int func_021D799C(int, int);
u8 *func_021CFD50(struct G_021CFD50 *g, int k);
int func_021CFDCC(void *p, void *q);
int func_021CFE08(struct G_021CFE08 *g, void *a, void *b);
int func_021CFE98(struct G_021CFE98 *g, void *a, void *b);


u8 *func_021CFD50(struct G_021CFD50 *g, int k)
{
    u8 buf[4];
    u8 n;
    u32 v;

    n = func_021B8D38(g->p0, (int)g->p1, (u16)(k | 0x100), buf);
    if (n) {
        g->seed = g->mul * g->seed + g->add;
        if (n == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)n) >> 32);
        }
        return func_021B9934(g->p1, buf[(u8)v]);
    }
    return 0;
}

/*
 * lever: explicit aggregate return local reserves the original eight-byte frame;
 *   named incremented accessor result gives cmp r0,r4.
 */
int func_021CFDCC(void *p, void *q)
{
    u32 n;
    u32 id = 20;
    u32 m;
    union Slot t;
    if (func_021D62C4(q, id)) {
        t = func_021D6314(q, id);
        n = func_021E8AFC(t);
        m = func_021D631C(q, id) + 1;
        if (m == n) return 1;
    }
    return 0;
}


int func_021CFE08(struct G_021CFE08 *g, void *a, void *b)
{
    if (func_021B8588(g->p0) != 0)
        return 0;
    if (func_021D59B4(b, 0x11) == 0x19) {
        if (func_021D0644(g, a, b, 4) == 0 && func_021D055C((u8 *)g, b, 4) != 0) {
            g->seed = g->mul * g->seed + g->add;
            if ((u32)(((g->seed >> 32) * 3) >> 32) < 2)
                return 1;
        }
    }
    return 0;
}

/*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled func_021CFFAC.
 */
int func_021CFE98(struct G_021CFE98 *g, void *a, void *b)
{
    u8 n;
    int k;
    u32 c;
    u32 i;
    u32 v;
    k = func_021D57FC(b);
    n = func_021D5448(a);
    c = 0;
    for (i = 0; i < n; i++) {
        v = (u32)func_021D54C0(a, (u8)i);
        if (func_0201C314((void *)v)) {
            if (func_021D799C(func_0201C1C8((void *)v), k))
                return 0;
            c++;
        }
    }
    if (c >= 2) {
        if (func_021D055C((u8 *)g, b, 4)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
        }
        if (func_021D055C((u8 *)g, b, 3)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}
