/*
 * unit:     yes
 * function: func_02158378, func_0215839C
 * address:  0x02158378
 * packet:   pkt_ov010_02158378
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158344  0x02158344  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 */

typedef unsigned char u8;

typedef struct { u8 a : 4; u8 f : 2; u8 b : 2; } Fl;

struct BigObj;
extern int func_02158344(int a0);
typedef unsigned int   u32;
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);

int func_02158378(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0) {
        return func_02012B58((const struct BigObj *)func_02026478(p));
    }
    return q[0x911];
}

int func_0215839C(u8 *p, int m, int a2)
{
    Fl *s = (Fl *)(p + 0x93F);
    u8 t = s->f;
    if (m & t) {
        s->f ^= 1;
        return 1;
    }
    return 0;
}
