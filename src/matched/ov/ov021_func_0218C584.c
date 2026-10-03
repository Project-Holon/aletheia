/*
 * function: func_0218C584
 * address:  0x0218C584
 * packet:   pkt_ov021_0218C584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Collects the active 16-byte entries whose position lies inside a rect.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02169510  0x02169510  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218C674  0x0218C674  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data   a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Rect;

typedef struct {
    int obj;
    int pad[2];
    u8 *ref;
} Ent;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02169510(int o, Vec *v);
extern void func_0207C9D0(Vec *a, Vec *b, Vec *c);
extern int func_0218C674(u8 *s, Ent *e);
extern char d_021DD9CC[];

static inline int InRect(Rect *r, int x, int z)
{
    if (r->c <= x && r->d >= x && r->a <= z && r->b >= z)
        return 1;
    return 0;
}

Ent **func_0218C584(u8 *s, Rect *r, int kind, int *count)
{
    Ent **list;
    Ent *e;
    Vec v;
    int n = 0;
    u32 i;

    list = func_02030734(*(u16 *)s, 0x80, 1, d_021DD9CC, 0x749);
    for (i = 0; i < 0x120; i++) {
        e = (Ent *)(s + 0x1F8) + i;
        if (e->obj == 0)
            continue;
        if (kind != 0 && kind != func_0218C674(s, e))
            continue;
        func_02169510(e->obj, &v);
        func_0207C9D0((Vec *)(e->ref + 4), &v, &v);
        if (InRect(r, v.x, v.z) == 1) {
            list[n] = e;
            n++;
        }
    }
    *count = n;
    return list;
}
