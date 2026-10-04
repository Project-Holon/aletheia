/*
 * function: func_02174F54
 * address:  0x02174F54
 * packet:   pkt_ov011_02174F54
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   func_020264B4  0x020264B4  thumb
 *   func_02039338  0x02039338  arm
 *   func_021751D4  0x021751D4  thumb ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u32 f0;
    u8 pad4[0x10];
    u16 f14;
    u16 a : 3;
    u16 rest : 13;
    u8 pad18[3];
    u8 lo : 6;
    u8 mid : 1;
    u8 hi : 1;
} Ent;

typedef struct Cp {
    int w[5];
} Cp;

void func_02082D44(const Ent *a, Ent *b, int c);
void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag);
u16 func_02039338(void);
void func_021751D4(u8 *p, u16 a, int b, struct Ent *c);

void func_02174F54(u8 *p, int idx, const Ent *src, int arg)
{
    Ent *e;
    u32 saved;

    e = (Ent *)(p + 0x8C) + idx;
    saved = e->f0;
    func_02082D44(src, e, 0x1C);
    e->f0 = saved;
    e->hi = (u8)src->f0;
    if (src->f0 == 1) {
        e->f0 = 1;
    }
    func_020264B4((void *)(*(int *)(p + 4)), idx, e->f14, (u8)e->a, e->lo, arg);
    if (idx != func_02039338()) {
        *((Cp *)(p + 0xE0) + idx) = *(Cp *)e;
        func_021751D4(p, *(u16 *)(p + 0x84), *(int *)(p + 0x74), e);
    }
    p[0x927] |= (u8)(1 << idx);
}
