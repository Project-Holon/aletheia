/*
 * function: func_021AAB74
 * address:  0x021AAB74
 * packet:   pkt_ov021_021AAB74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021AAFC0  0x021AAFC0  thumb
 *   func_02082BCC  0x02082BCC  arm
 */

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
    unsigned char f4 : 2;
    unsigned char f6 : 2;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
} Self;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);
extern u16 func_02188C9C(u8 *p);
extern void func_021AAFC0(Self *self, int a, Ent *e);
extern void func_02082BCC(void *p, int v, unsigned long n);

void func_021AAB74(Self *self, int a)
{
    Ent *e = (Ent *)(func_02012A38(self->obj) + 0x10);
    unsigned short id;

    if (e->flags == 0 || e->f4 == 0)
        return;
    e->f4 = 0;
    id = func_02188C9C(self->ctx);
    if (id != e->id || e->f6 != 0)
        func_02082BCC(e, 0, 0x10);
    else
        func_021AAFC0(self, a, e);
}
