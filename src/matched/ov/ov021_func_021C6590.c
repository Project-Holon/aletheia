/*
 * function: FIELD_G3DOBJ_AddObject
 * address:  0x021C6590
 * packet:   pkt_ov021_021C6590
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3DOBJ_CreateObject  0x021C69B4  thumb  ov021
 *   MTX_Identity33_  0x0207ADC4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 rest : 29;
    u16 f4;
    u16 f6;
    Vec f8;
    int f14;
    int f18;
    int f1C;
    u8 f20[0x24];
    void *f44;
    u8 pad48[0x20];
} Elem;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem *fC;
} Mgr;

extern void FIELD_G3DOBJ_CreateObject(Elem *e, u8 *s, int a, int b, int c, void *d, int f);
extern void MTX_Identity33_(void *p);

u16 FIELD_G3DOBJ_AddObject(Mgr *m, u16 idx, u16 a, Vec *src)
{
    u16 i;
    Elem *e;
    u8 *s;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 0 && e->f44 == 0) {
            s = m->f8 + idx * 0x2c;
            if (s[0x29] == 2) {
                e->f4 = idx;
                e->f6 = a;
                e->kind = 2;
                e->b2 = 1;
                e->f14 = 0x1000;
                e->f18 = 0x1000;
                e->f1C = 0x1000;
                if (src != 0)
                    e->f8 = *src;
                MTX_Identity33_(e->f20);
            } else {
                FIELD_G3DOBJ_CreateObject(e, s, idx, a, m->f0, src, 1);
            }
            return i;
        }
        e++;
    }
    return 0;
}
