/*
 * function: func_0218B930
 * address:  0x0218B930
 * packet:   pkt_ov021_0218B930
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218B910  0x0218B910  thumb  ov021
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 */

typedef struct {
    int f0;
    unsigned short id;
    short x;
    short y;
    short z;
} Ent;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef unsigned int   u32;
int func_0218B910(u32 a, u32 b);
int func_0218BBD0(void *p, unsigned int i);

static inline void Vec_Set(Vec *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

int func_0218B930(void *p, int a, Vec *pos, int *k)
{
    Ent *e = (Ent *)func_0218B910((u32)p, a);
    if (e->id == 0xFFFF)
        return 0;
    *k = func_0218BBD0(p, e->id);
    Vec_Set(pos, e->x << 12, e->y << 12, e->z << 12);
    return 1;
}
