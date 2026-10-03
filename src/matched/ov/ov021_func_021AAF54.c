/*
 * function: func_021AAF54
 * address:  0x021AAF54
 * packet:   pkt_ov021_021AAF54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_021AAEC0  0x021AAEC0  thumb
 *   func_021AAFA0  0x021AAFA0  thumb
 */

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0c[4];
    void *f10;
} Self;

typedef unsigned int   u32;
struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);
extern int func_021AAEC0(Self *self, int x, short y, int z, int skip);
extern void func_021AAFA0(Self *self, void *p);

int func_021AAF54(Self *self)
{
    Ent *e = (Ent *)(func_02012A38(self->obj) + 0x10);

    if (e->flags == 0)
        return 0;
    if (func_021AAEC0(self, e->x, e->y, e->z, 1)) {
        func_021AAFA0(self, self->f10);
        return 1;
    }
    return 0;
}
