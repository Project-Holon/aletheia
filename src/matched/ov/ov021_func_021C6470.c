/*
 * function: func_021C6470
 * address:  0x021C6470
 * packet:   pkt_ov021_021C6470
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C6854  0x021C6854  thumb  ov021
 *   func_021C69B4  0x021C69B4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
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

extern void func_021C6854(u8 *s);
extern void func_021C69B4(Elem *e, u8 *s, int a, int b, int c, int d, int f);

void func_021C6470(Mgr *m)
{
    int i;
    int j;
    Elem *e;
    u8 *s;

    if (m->f2 == 1) {
        e = m->fC;
        s = m->f8;
        for (i = 0; i < m->f4; i++) {
            if (s[0x29] == 2)
                func_021C6854(s);
            s += 0x2c;
        }
        s = m->f8;
        for (j = 0; j < m->f6; j++) {
            if (e->kind == 2)
                func_021C69B4(e, s + e->f4 * 0x2c, e->f4, e->f6, m->f0, 0, 0);
            e++;
        }
    }
}
